import React, {useEffect, useState} from 'react';
import {
    Button,
    Col,
    Modal,
    ModalBody,
    ModalHeader,
    Input,
    Collapse,
    ModalFooter,
} from 'reactstrap';
import Coordinates from 'coordinate-parser';
import {reverseGeocode} from '../../../utils/reverseGeocode'

export default function AddPlace(props) {
    const [foundPlace, setFoundPlace] = useState();
    const [coordString, setCoordString] = useState('');
    return (
        <Modal isOpen={props.isOpen} toggle={props.toggleAddPlace}>
            <AddPlaceHeader toggleAddPlace={props.toggleAddPlace}/>
            <PlaceSearch
                foundPlace={foundPlace}
                setFoundPlace={setFoundPlace}
                coordString={coordString}
                setCoordString={setCoordString}
            />
            <AddPlaceFooter
                append={props.append}
                foundPlace={foundPlace}
                setCoordString={setCoordString}
            />
        </Modal>
    );
}

function AddPlaceHeader(props) {
    return (
        <ModalHeader className='ml-2' toggle={props.toggleAddPlace}>
            Add a Place
        </ModalHeader>
    );
}

function PlaceSearch(props) {
    useEffect(() => {
        verifyCoordinates(props.coordString, props.setFoundPlace);
    }, [props.coordString]);

    return (
        <ModalBody>
            <Col>
                <Input
                    onChange={(input) => props.setCoordString(input.target.value)}
                    placeholder='Enter Place Coordinates'
                    data-testid='coord-input'
                    value={props.coordString}
                />
                <PlaceInfo foundPlace={props.foundPlace}/>
            </Col>
        </ModalBody>
    );
}

function PlaceInfo(props) {
    return (
        <Collapse isOpen={!!props.foundPlace}>
            <br/>
            {props.foundPlace?.formatPlace()}
        </Collapse>
    );
}

function AddPlaceFooter(props) {
    return (
        <ModalFooter>
            <Button
                color='primary'
                onClick={() => {
                    props.append(props.foundPlace);
                    props.setCoordString('');
                }}
                data-testid='add-place-button'
                disabled={!props.foundPlace}
            >
                Add Place
            </Button>
        </ModalFooter>
    );
}

async function verifyCoordinates(coordString, setFoundPlace) {
    try {
        const latLngPlace = new Coordinates(coordString);
        const lat = latLngPlace.getLatitude();
        const lng = latLngPlace.getLongitude();
        if (lat !== undefined && lng !== undefined) {
            const fullPlace = await reverseGeocode({lat, lng});
            setFoundPlace(fullPlace);
        }
    } catch (error) {
        setFoundPlace(undefined);
    }
}
