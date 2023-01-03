import React from "react";
import { useState } from "react";
import { Button, Input, Modal, ModalHeader, ModalFooter, ModalBody, Col } from "reactstrap";

  export default function ChangeTripName(props){

    const [tempName, setTempName] = useState('My Trip');  

    return(
        <Modal isOpen={props.isOpen} toggle={props.toggleChangeTripName}>
            
            <ChangeTripNameHeader toggleChangeTripName={props.toggleChangeTripName}>
            </ChangeTripNameHeader>

            <PickTripName
                setTempName={setTempName}>
            </PickTripName>
            
            <ChangeTripNameFooter
                showMessage={props.showMessage}
                toggleChangeTripName={props.toggleChangeTripName}
                tempName={tempName}
                setTripName={props.setTripName}>
            </ChangeTripNameFooter>
    
        </Modal>
    );
    
  }

  function ChangeTripNameHeader(props) {
    return (
      <ModalHeader toggle={props.toggleChangeTripName}>
        Name your trip
      </ModalHeader>
    );
  }

  function PickTripName(props){
      return(
          <ModalBody>
            <Col>
              <Input 
                onChange={(input) => props.setTempName(input.target.value)}
                data-testid="change-trip-name"
                />
            </Col>
          </ModalBody>
      );
  }

  function ChangeTripNameFooter(props) {
    return (
      <ModalFooter>
  
        <Button color="primary"
          onClick={() => {
            props.setTripName(props.tempName);
            props.toggleChangeTripName();
            }} 
            data-testid='change-trip-button'>
            Set new name 
        </Button>
  
        <Button color="secondary" onClick={() => {props.toggleChangeTripName();}} data-testid='change-trip-decline'>
            Cancel
        </Button>
        
      </ModalFooter>
    );
  }