import React  from 'react';
import {useToggle} from '../../../hooks/useToggle';
import {Table, Collapse} from 'reactstrap';
import {ItineraryActionsDropdown, PlaceActionsDropdown,TripActionsDropdown} from './ItineraryDropdown.js';
import {latLngToText, placeToLatLng} from '../../../utils/transformers';
import ShowUnits from "./Units/ShowUnits";
import {CustomUnits} from './Units/CustomUnits';
import {useState, useRef, useEffect} from "react";
import { sum as distanceSum} from '../../../hooks/useDistances';
import { doesServerSupport } from '../../Margins/Interopability';


const LOCAL_STORAGE_KEY = 'Itinerary.distanceUnits';
const LOCAL_STORAGE_NAME = 'Itinerary.TripName';

export default function Itinerary(props) {
    const [distanceUnits, setDistanceUnits] = useState('Miles');
    const [TripName, setTripName] = useState('My Trip');

    useEffect(getObj(LOCAL_STORAGE_KEY,setDistanceUnits),[]);
    useEffect(saveString(LOCAL_STORAGE_KEY,distanceUnits),[distanceUnits]);

    useEffect(getObj(LOCAL_STORAGE_NAME,setTripName),[]);
    useEffect(saveString(LOCAL_STORAGE_NAME,TripName),[TripName]);

    function tripIsEmpty() {
        return !props.places || props.places.length === 0;
    }

    return (
        <Table style={{"overflowX": "visible"}}>
            <TripHeader {...props} disableRemoveAll={tripIsEmpty()} setDistanceUnits={setDistanceUnits} 
                        distanceUnits={distanceUnits} TripName={TripName} setTripName={setTripName} 
                        MapLayer={props.MapLayer} setMapLayer={props.setMapLayer} 
                        MapAttribution={props.MapAttribution} setMapAttribution={props.setMapAttribution}
                        setLineColor={props.setLineColor} LineColor={props.LineColor} 
                        LineType={props.LineType} setLineType={props.setLineType}  setIconURL={props.setIconURL}
                        />

            <PlaceList places={props.places} placeActions={props.placeActions} selectedIndex={props.selectedIndex} distanceActions={props.distanceActions} 
                       distanceUnits={distanceUnits} distances={props.distances} serverFeatures={props.serverFeatures}/>
        </Table>
    );
}

export function getObj(StorageKey, setter){
    return () => {
        const obj = JSON.parse(localStorage.getItem(StorageKey))
        if (obj) setter(obj)
    }
}

export function saveString(StorageKey, str){
    return () => {
        localStorage.setItem(StorageKey, JSON.stringify((str)))
    }
}

function TripHeader(props) {
    
    return (
        <React.Fragment><thead><tr>
                <td><TripActionsDropdown 
                        TripName={props.TripName} setTripName={props.setTripName} places={props.places}
                        placeActions={props.placeActions} showMessage={props.showMessage} earthRadius={props.earthRadius}
                        distanceActions={props.distanceActions} serverFeatures={props.serverFeatures}
                        MapLayer={props.MapLayer} MapAttribution={props.MapAttribution}
                        setMapLayer={props.setMapLayer} setMapAttribution={props.setMapAttribution}
                        setLineColor={props.setLineColor} LineColor={props.LineColor} 
                        LineType={props.LineType} setLineType={props.setLineType} 
                        setIconURL={props.setIconURL}
                        /></td>
                <td><ItineraryActionsDropdown placeActions={props.placeActions} disableRemoveAll={props.disableRemoveAll} 
                        append={props.placeActions.append} serverFeatures={props.serverFeatures} places={props.places} distances={props.distances}
                        distanceActions={props.distanceActions} earthRadius={props.earthRadius} LineColor={props.LineColor} LineType={props.LineType}
                        MapLayer={props.MapLayer} MapAttribution={props.MapAttribution} /></td>
                {doesServerSupport(props.serverFeatures, "distances")?<DistanceHeader distances = {props.distances} setDistanceUnits={props.setDistanceUnits} 
                        setEarthRadius={props.setEarthRadius} distanceUnits={props.distanceUnits} distanceActions={props.distanceActions}/>:null}
            </tr></thead></React.Fragment>
    );
}

function DistanceHeader(props) {
    const [showCustomUnit, toggleCustomUnit] = useToggle(false);
    return (
        <React.Fragment>
            <td align='right'>
            <ShowUnits distanceSum={distanceSum(props.distances)} setDistanceUnits={props.setDistanceUnits}
                       setEarthRadius={props.setEarthRadius} toggleCustomUnit={toggleCustomUnit}
                       distanceUnits={props.distanceUnits} distanceActions={props.distanceActions}/>
            </td>
            <CustomUnits isOpen={showCustomUnit} toggleCustomUnit={toggleCustomUnit}
                         setDistanceUnits={props.setDistanceUnits} setEarthRadius={props.setEarthRadius}
                         distanceActions={props.distanceActions}/>
        </React.Fragment>
    );
}

function PlaceList(props) {
    const [lastPlace, setLastPlace] = useState(-1);
    useEffect( () =>{
        setLastPlace(props.places.length-1)
    },[props.places])

    return (
        <tbody>
        {props.places.map((place, index) => (
            <PlaceRow
                key={`table-${JSON.stringify(place)}-${index}`}
                lastPlace={lastPlace}
                place={place}
                index={index}
                places={props.places}
                placeActions={props.placeActions}
                distanceActions={props.distanceActions}
                {...props}
            />
        ))}
        </tbody>
    );
}

function PlaceRow(props) {
    const [showFullName, toggleShowFullName] = useToggle(false);
    const name = props.place.defaultDisplayName;
    const location = latLngToText(placeToLatLng(props.place));
    let distance = 0;
    if (props.distances != null) {
        distance = props.distances[props.index];
    }

    return (
        <tr className={props.selectedIndex === props.index ? 'selected-row' : ''}>
            <td data-testid={`place-row-${props.index}`}
                onClick={() => placeRowClicked(toggleShowFullName, props.placeActions.selectIndex, props.index)}>
                {!showFullName ? name : props.place.formatPlace()}
                <AdditionalPlaceInfo showFullName={showFullName} location={location}/></td>
            <td/>
            <td>
                <PlaceActionsDropdown
                    distance={distance} distanceActions={props.distanceActions} distanceUnits={props.distanceUnits} 
                    placeActions={props.placeActions} places={props.places} lastPlace={props.lastPlace}
                    index={props.index} serverFeatures={props.serverFeatures}/>
            </td>
        </tr>
    );
}

function AdditionalPlaceInfo(props) {
    return (
        <Collapse isOpen={props.showFullName}>
            {props.location}
        </Collapse>
    );
}

function placeRowClicked(toggleShowFullName, selectIndex, placeIndex) {
    toggleShowFullName();
    selectIndex(placeIndex);
}

