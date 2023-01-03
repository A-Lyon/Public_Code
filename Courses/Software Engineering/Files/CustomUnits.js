import {useState} from "react";
import React from 'react';
import { Button, Modal, ModalHeader, ModalFooter, ModalBody, Col, Input} from "reactstrap";

export function CustomUnits(props) {
    const [placeholderName, setPlaceholderName] = useState('miles');
    const [placeholderRadius, setPlaceholderRadius] = useState(3959);
    return (
        <Modal isOpen={props.isOpen} toggle={props.toggleCustomUnit}>
            <CustomUnitHeader toggleCustomUnit={props.toggleCustomUnit}/>
            <CustomUnitBody setPlaceholderName={setPlaceholderName} setPlaceholderRadius={setPlaceholderRadius}/>
            <CustomUnitFooter 
                setDistanceUnits={props.setDistanceUnits} setEarthRadius={props.setEarthRadius} 
                distanceActions={props.distanceActions} toggleCustomUnit={props.toggleCustomUnit}
                placeholderName={placeholderName} placeholderRadius={placeholderRadius}>

            </CustomUnitFooter>
        </Modal>
    );
}

function CustomUnitHeader(props){
    return(
        <ModalHeader toggle={props.toggleCustomUnit}>
                    Choose Unit
        </ModalHeader>
    )
}

function CustomUnitBody(props){
    return(
        <ModalBody>
                <Col>
                    <Input
                        onChange={(input) => props.setPlaceholderName(input.target.value)}
                        placeholder='Enter Unit Name' data-testid='unit-input'
                    />
                </Col>
                <br/>
                <Col>
                    <Input
                        placeholder='Enter Earth Radius' data-testid='radius-input'
                        onChange={(input) => props.setPlaceholderRadius(input.target.value)}
                    />
                </Col>
            </ModalBody>
    )
}

function CustomUnitFooter(props){
    return(
        <ModalFooter>
                    <Button
                        color='primary'
                        onClick={() => {
                            props.setDistanceUnits(props.placeholderName);
                            props.setEarthRadius(parseFloat(props.placeholderRadius));
                            props.distanceActions.setDistances([]);
                            props.toggleCustomUnit();
                        }}
                        data-testid='add-unit-button'>
                        Enter Unit
                    </Button>
                    <Button color="secondary" onClick={() => {props.toggleCustomUnit();}}>
                    Cancel
                    </Button>

        </ModalFooter>
    );
}