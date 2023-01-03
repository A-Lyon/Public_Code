
import React from "react";
import { Button, Modal, ModalHeader, ModalFooter, ModalBody, Dropdown, ButtonGroup } from "reactstrap";
import { useState } from "react";

const MIME_TYPE = {
    JSON: "application/json",
    CSV: "text/csv",
    SVG: "image/svg+xml",
    KML: "application/vnd.google-earth.kml+xml"
};

export default function SaveTrip(props) {

    const [mimeType, setMimeType] = useState(MIME_TYPE.CSV);

    return (

    <Modal isOpen={props.isOpen} toggle={props.toggleSaveTrip}>

      <SaveTripHeader 
        toggleSaveTrip={props.toggleSaveTrip} 
        />

      <SaveTripBody
        mimeType = {mimeType} setMimeType={setMimeType}
        />

      <SaveTripFooter
        showMessage={props.showMessage}
        toggleSaveTrip={props.toggleSaveTrip}
        fileNameWithExtension={props.tripName}
        mimeType = {mimeType}
        fileText={JSON.stringify({"places": props.places})}
      ></SaveTripFooter>

    </Modal>

    );
}

function onSave(fileNameWithExtension, mimeType, fileText){
    const file = new Blob([fileText], { type: mimeType });
    const link = document.createElement("a");
    const url = URL.createObjectURL(file);
    link.href = url;
    link.download = fileNameWithExtension;
    document.body.appendChild(link);
    link.click();
    
    setTimeout(function() {
        document.body.removeChild(link);
        window.URL.revokeObjectURL(url);
    }, 0);
}

function SaveTripHeader(props) {
  return (
    <ModalHeader className="ml-2" toggle={props.toggleSaveTrip}>
      Save your itinerary.
    </ModalHeader>
  );
}

function SaveTripBody(props){
  return(
    <ModalBody>
      <tr>
      Pick file format:
      </tr>
      
      <MimeTypeButton mimeType={MIME_TYPE.JSON} mimeName={'JSON'} setMimeType={props.setMimeType}/>
      <MimeTypeButton setMimeType={props.setMimeType} mimeType={MIME_TYPE.CSV} mimeName={'CSV'}/>
      <MimeTypeButton mimeType={MIME_TYPE.SVG} setMimeType={props.setMimeType}  mimeName={'SVG'}/>
      <MimeTypeButton setMimeType={props.setMimeType} mimeName={'KML'} mimeType={MIME_TYPE.KML}/>
    
    </ModalBody>
  );
}

function MimeTypeButton(props){
  return(
    <Button size='sm' color='primary' active 
      onClick={() => {props.setMimeType(props.mimeType)}} data-testid={`${props.mimeName}-Mime`}>
        .{props.mimeName}
    </Button>
  )
}

function SaveTripFooter(props) {
  return (
    <ModalFooter>
      <Button color="primary"
        onClick={() => {
          onSave(props.fileNameWithExtension, props.mimeType, props.fileText);
          props.toggleSaveTrip();
        }} data-testid='save--button'> Save </Button>
      <Button color="secondary" onClick={props.toggleSaveTrip}>Cancel </Button>
    </ModalFooter>
  );
}