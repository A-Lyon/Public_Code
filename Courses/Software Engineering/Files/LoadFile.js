import React, { useState } from "react";
import { Button, Modal, ModalHeader, ModalFooter, ModalBody } from "reactstrap";
import { LoadPlaces } from "../../../utils/loadTrip";
import { ShorterTrip } from "./ShorterTrip";
import { useDistances } from "../../../hooks/useDistances";
import {useToggle} from "../../../hooks/useToggle"
import {usePlaces} from "../../../hooks/usePlaces"

export default function LoadFile(props) {
    const {places: loadPlaces, selectedIndex: loadSelectedIndex, placeActions: loadPlaceActions} = usePlaces();
    const {distances: loadDistances, distanceActions: loadDistanceActions} = useDistances(props.earthRadius, loadPlaces);
    const [showShorterTrip, toggleShorterTrip] = useToggle(false);
    const [disallowLoad, setDisallowLoad] = useState(true);

    return (
            <Modal isOpen={props.isOpen} toggle={props.toggleLoadFile}>
                <LoadFileHeader toggleLoadFile={props.toggleLoadFile}/>
                <ChooseFile
                    setLoadPlace={loadPlaceActions.setPlaces} showMessage={props.showMessage} loadPlaces={loadPlaces}
                    toggleShorterTrip={toggleShorterTrip} places={props.places} setDisallowLoad={setDisallowLoad} serverFeatures={props.serverFeatures}/>
                <LoadFileFooter
                    toggleLoadFile={props.toggleLoadFile} placeActions={props.placeActions} loadPlaces={loadPlaces}
                    setLoadPlace={loadPlaceActions.setPlaces} disallowLoad={disallowLoad} setDisallowLoad={setDisallowLoad} distanceActions={props.distanceActions}/>
                <ShorterTrip
                    isOpen={showShorterTrip} toggleShorterTrip={toggleShorterTrip} loadPlaces={loadPlaces}
                    loadSelectedIndex={loadSelectedIndex}loadDistances={loadDistances} loadDistanceActions={loadDistanceActions}
                    earthRadius={props.earthRadius} loadPlaceActions={loadPlaceActions}
                    MapLayer={props.MapLayer} MapAttribution={props.MapAttribution} LineColor={props.LineColor}/>
            </Modal>
    );
}

function LoadFileHeader(props) {
  return (
      <ModalHeader className="ml-2" toggle={props.toggleLoadFile}>
        Load Trip
      </ModalHeader>
  );
}

function ChooseFile(props) {
  return (
      <ModalBody>
        <input type="file" onChange={(e) => onUpload(e, props)} data-testid="input-file-button"/>
      </ModalBody>
  );
}

function onUpload(e, props) {
  let reader = new FileReader();

  reader.onload = async function (e) {
    props.setDisallowLoad(true);
    const tripString = e.target.result
    await LoadPlaces(props, tripString)
  }
  reader.readAsText(e.target.files[0]);
}

function LoadFileFooter(props) {
  return (
    <ModalFooter>
      <Button color="primary"
        disabled={props.disallowLoad}
        onClick={() => {
          props.placeActions.setPlaces(props.loadPlaces);
          clear(props);
          props.setLoadPlace([]);
        }} data-testid='load-button'> Load Selected File </Button>

      <Button color="secondary" data-testid='close-load' onClick={() =>{
        props.setLoadPlace([]);
        clear(props);}}>Cancel </Button>
    </ModalFooter>
  );
}

function clear(props) {
  props.toggleLoadFile();
  props.setDisallowLoad(true);
  console.log(props.distanceActions);
  props.distanceActions.setDistances([]);
}

