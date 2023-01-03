import React from 'react';
import { useState, useEffect} from "react";
import { Map as LeafletMap, Polyline, TileLayer } from 'react-leaflet';
import Marker from './Marker';
import { placeToLatLng } from '../../../utils/transformers';
import { DEFAULT_STARTING_POSITION } from '../../../utils/constants';
import 'leaflet/dist/leaflet.css';

const MAP_BOUNDS = [[-90, -180], [90, 180]];
const MAP_MIN_ZOOM = 1;
const MAP_MAX_ZOOM = 19;

export default function Map(props) {

    function handleMapClick(mapClickInfo) {
        props.placeActions.append(mapClickInfo.latlng);
    }

    const [zoom, setZoom] = useState(15);

    return (
        <LeafletMap
            className="mapStyle"
            boxZoom={false}
            useFlyTo={true}
            zoom={zoom}
            minZoom={MAP_MIN_ZOOM}
            maxZoom={MAP_MAX_ZOOM}
            maxBounds={MAP_BOUNDS}
            center={DEFAULT_STARTING_POSITION}
            onClick={handleMapClick}
            data-testid="Map"
        >
            <TileLayer url={props.MapLayer} attribution={props.MapAttribution} />
            <TripLines LineColor={props.LineColor} places={props.places} LineType={props.LineType} />
            <PlaceMarker selectedIndex={props.selectedIndex} places={props.places} MapMarker={props.MapMarker} iconURL={props.iconURL}/>
        </LeafletMap>
    );
}

function TripLines(props) {
    const pathData = computePaths(props.places);
    return pathData.map((path, index) =>
        <Polyline
            dashArray={props.LineType}
            key={`${JSON.stringify(path)}-${index}`}
            color = {props.LineColor.hex}
            positions={path}
        />
    );
}

function computePaths(places) {
    if (places.length < 2) {
        return [];
    }

    const pathPointPairs = [];
    for (let i = 0; i < places.length; i++) {
        const fromPlace = places[i];
        const toPlace = places[(i+1) % places.length];
        pathPointPairs.push([placeToLatLng(fromPlace), placeToLatLng(toPlace)]);
    }
    return pathPointPairs;
}

function PlaceMarker(props){
    if (props.selectedIndex === -1) {
        return null;
    }
    return <Marker place={props.places[props.selectedIndex]} iconURL={props.iconURL}/>;
}

