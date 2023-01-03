import * as tripFileSchema from '../../schemas/TripFile.json';
import { isJsonResponseValid } from './restfulAPI';
import Papa from 'papaparse';
import { Place } from '../models/place.model';
import { doesServerSupport } from '../components/Margins/Interopability';

export async function LoadPlaces(props, foundTrip) {
    try {
        if (isValidJsonFile(foundTrip)) {
            LoadJsonFile(props, foundTrip);
        } else {
            LoadCsvFile(props, foundTrip);
        }
    } catch {
        TripLoadErrorMessage(props);
    }
}

function isValidJsonFile(tripString){
    try{
        const tripObject = JSON.parse(tripString);
        return isJsonResponseValid(tripObject, tripFileSchema);
    }catch{
        return false;
    }
}

function LoadJsonFile(props, tripString){
    const tripObject = JSON.parse(tripString);
    const places = makeJsonPlaces(tripObject);
    TripLoadComplete({places}, props);
}

function makeJsonPlaces(tripObject){
    var places = [];
    for(let index in tripObject.places){
        var place = tripObject.places[index];
        const placeObject = makePlace(place);
        places.push(new Place(placeObject));
    }

    return places;
}

function LoadCsvFile(props, tripString){
    try{
        var context = {
            places: []
        }
        Papa.parse(tripString, {
            header: true,
            step: (row) => CsvStep(row, context),
            error: () => TripLoadErrorMessage(props),
            complete: () => TripLoadComplete(context, props)
        });
    }catch{
        TripLoadErrorMessage(props);
    }

}

function CsvStep(row, {places}){
    const placeObject = makePlace(row.data);
    places.push(new Place(placeObject));  
}

export function makePlace(place){
    const placeObject = {};
    for(let key in place){
        const value = place[key];
        placeObject[key] = value;
    }
    return placeObject;
}

function TripLoadErrorMessage(props){
    props.setDisallowLoad(true);
    props.showMessage('Invalid File', 'error');
}

function TripLoadComplete({places}, props){
    if(isValidPlaces(places)){
        props.setLoadPlace(places);
        props.showMessage('Valid File');
        doesServerSupport(props.serverFeatures, "tour")?props.toggleShorterTrip():null;
        props.setDisallowLoad(false);
    }else{
        TripLoadErrorMessage(props);
    }
}

function isValidPlaces(places){
    const isArray = Array.isArray(places);
    const allElementsValid = (places.length == 0 || hasPlaces(places))
    return isArray && allElementsValid;
}

function hasPlaces(places){
    return places.every((e)=>{return e.latitude!=null && e.longitude!=null});
}