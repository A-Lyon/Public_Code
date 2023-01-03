import React from 'react';
import { Marker as LeafletMarker, Popup } from 'react-leaflet';
import { Button, ButtonGroup, Modal, ModalBody, ModalFooter, ModalHeader } from 'reactstrap';
import { latLngToText, placeToLatLng } from '../../../utils/transformers';
import iconShadow from 'leaflet/dist/images/marker-shadow.png';

export default function Marker(props) {

    const MARKER_ICON = L.icon({ iconUrl: props.iconURL, shadowUrl: iconShadow, iconAnchor: [12, 40]});

    function showMarkerPopup(ref) {
        if (ref) {
            ref.leafletElement.openPopup();
        }
    }

    if (!props.place) {
        return null;
    }

    return (
        <LeafletMarker ref={(ref) => showMarkerPopup(ref)} position={placeToLatLng(props.place)} icon={MARKER_ICON}>
            <Popup offset={[0, -18]} className="font-weight-bold">
                {props.place.formatPlace()}
                <br/>
                <small className="text-muted">
                    {latLngToText(placeToLatLng(props.place), 6)}
                </small>
            </Popup>
        </LeafletMarker>
    );
}

