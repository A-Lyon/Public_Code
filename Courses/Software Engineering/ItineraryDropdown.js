import React from 'react';
import { DEFAULT_STARTING_POSITION } from '../../../utils/constants';
import { Button, ButtonGroup, DropdownItem, Dropdown, DropdownMenu, DropdownToggle, UncontrolledDropdown } from 'reactstrap';
import { FaFolderOpen, FaHome, FaPlus, FaSave, FaCog, FaEdit, FaTrashAlt, FaFlag, FaSearchLocation, FaArrowUp, FaArrowDown} from 'react-icons/fa';
import { MdSwapHoriz } from 'react-icons/md'
import { BsSortUpAlt } from 'react-icons/bs';
import { doesServerSupport } from '../../Margins/Interopability';
import { useToggle } from '../../../hooks/useToggle';
import AddPlace from './AddPlace';
import { ShorterTrip } from './ShorterTrip';
import ChangeTripName from './ChangeTripName';
import LoadFile from './LoadFile';
import SaveTrip from './SaveTrip';
import { reverseTrip, rotateTrip, swapUp } from '../../../utils/tripUtils';
import FilterTrip from "./FilterTrip";
import MapOptions from '../Map/MapOptions';

export function ItineraryActionsDropdown(props) {
    const [showAddPlace, toggleAddPlace] = useToggle(false);
    const [showOpt, toggleOpt] = useToggle(false);
    let dropdown = 'Place Options';
    return (
        <ActionsDropdown  Name={dropdown}>
            <DropdownItem onClick={() => props.placeActions.append(DEFAULT_STARTING_POSITION)} data-testid='home-button'>
                <FaHome />
            </DropdownItem>
            <DropdownItem onClick={() => toggleAddPlace()} data-testid='add-place-button'>
                <FaPlus />
                <AddPlace isOpen={showAddPlace} toggleAddPlace={toggleAddPlace} append={props.placeActions.append}/>
            </DropdownItem >
            {doesServerSupport(props.serverFeatures, "tour")?<DropdownItem disabled={props.disableRemoveAll} onClick={() => toggleOpt()} data-testid={`opt-button`}>
                <BsSortUpAlt/>
                <ShorterTrip isOpen={showOpt} toggleShorterTrip={toggleOpt} earthRadius={props.earthRadius} loadDistanceActions={props.distanceActions}
                    loadPlaces={props.places} loadPlaceActions={props.placeActions} loadDistances={props.distances} MapLayer={props.MapLayer} MapAttribution={props.MapAttribution} LineColor={props.LineColor}/>
            </DropdownItem>:null}
            <DropdownItem disabled={props.disableRemoveAll} onClick={() =>{ reverseTrip(props.places, props.placeActions, props.distanceActions)}} data-testid='reverse-button'>
                <MdSwapHoriz />
            </DropdownItem>
            <DropdownItem disabled={props.disableRemoveAll} onClick={() =>{ props.placeActions.removeAll(); props.distanceActions.setDistances([]);}} data-testid='delete-all-button'>
                <FaTrashAlt />
            </DropdownItem></ActionsDropdown>
    );
}

export function TripActionsDropdown(props) {
    const [showLoadFile, toggleLoadFile] = useToggle(false);
    const [showSaveTrip, toggleSaveTrip] = useToggle(false);
    const [showChangeTripName, toggleChangeTripName] = useToggle(false);
    const [showFilterTrip, toggleShowFilterTrip] = useToggle(false);
    const [showMapOptions, toggleShowMapOptions] = useToggle(false);

    return (
        <ActionsDropdown Name={props.TripName}>
            <LoadSaveDropdown showChangeTripName={showChangeTripName} toggleChangeTripName={toggleChangeTripName} 
                        toggleLoadFile={toggleLoadFile} showLoadFile={showLoadFile} showSaveTrip={showSaveTrip} 
                        toggleSaveTrip={toggleSaveTrip} MapMarker={props.MapMarker} {...props}/>
            <DropdownItem onClick={() => toggleShowMapOptions()}>
                <FaCog />
                <MapOptions isOpen={showMapOptions} toggleShowMapOptions={toggleShowMapOptions} showMessage={props.showMessage}
                        setMapLayer={props.setMapLayer} setMapAttribution={props.setMapAttribution} 
                        setLineColor={props.setLineColor} LineColor={props.LineColor} 
                        LineType={props.LineType} setLineType={props.setLineType} 
                        setIconURL={props.setIconURL}/>
            </DropdownItem>       
            <DropdownItem  onClick={() => toggleShowFilterTrip()} data-testid='filter-button'>
                <FilterTrip isOpen={showFilterTrip} toggleShowFilterTrip={toggleShowFilterTrip}
                            places={props.places} placeActions={props.placeActions}/>
                <FaSearchLocation/>
            </DropdownItem>
        </ActionsDropdown>
    );
}

function LoadSaveDropdown(props){
    return(
        <React.Fragment>
            <DropdownItem onClick={() => props.toggleChangeTripName()} data-testid='trip-button'>
                <FaEdit/>
                <ChangeTripName  setTripName={props.setTripName} isOpen={props.showChangeTripName} toggleChangeTripName={props.toggleChangeTripName}
                                     showMessage={props.showMessage} TripName={props.TripName}/>
            </DropdownItem>
            <DropdownItem onClick={() => props.toggleLoadFile()} data-testid='file-button'>
                <FaFolderOpen/>
                <LoadFile places={props.places} placeActions={props.placeActions} earthRadius={props.earthRadius} serverFeatures={props.serverFeatures}
                            showMessage={props.showMessage} toggleLoadFile={props.toggleLoadFile} isOpen={props.showLoadFile} distanceActions={props.distanceActions}
                            MapLayer={props.MapLayer} MapAttribution={props.MapAttribution} LineColor={props.LineColor} LineType={props.LineType}/>
            </DropdownItem>
            <DropdownItem data-testid='save-button' onClick={() => props.toggleSaveTrip()} >
                <SaveTrip isOpen={props.showSaveTrip} places={props.places} toggleSaveTrip={props.toggleSaveTrip}
                            showMessage={props.showMessage}  TripName={props.TripName}/>
                <FaSave/>
            </DropdownItem>
        </React.Fragment>
    );
}

export function PlaceActionsDropdown(props) {
    return (
        <PlaceRowDropdown {...props}>
            <DropdownItem onClick={()=> swapUp(props, props.index)} disabled={props.index === 0} data-testid='move-up-button'>
                <FaArrowUp/>
            </DropdownItem>
            <DropdownItem onClick={()=> swapUp(props, props.index + 1)} disabled={props.index === props.lastPlace} data-testid='move-down-button'>
                <FaArrowDown/>
            </DropdownItem>
            <DropdownItem onClick={()=> rotateTrip(props)}data-testid='new-start-button'>
                <FaFlag/>
            </DropdownItem>
            <DropdownItem onClick={() => props.placeActions.removeAtIndex(props.index)} data-testid={`delete-button-${props.index}`}>
                <FaTrashAlt/>
            </DropdownItem>
        </PlaceRowDropdown>
    );
}

function PlaceRowDropdown(props) {

    return (
        <UncontrolledDropdown>
            <DropdownToggle align='middle' caret={true} color="primary" outline='true' block='true' tag="div" data-testid={`row-toggle-${props.index}`}>
                {doesServerSupport(props.serverFeatures, "distances")? props.distance + " " + props.distanceUnits:null}
            </DropdownToggle>
            <DropdownMenu>
                <ButtonGroup>
                    {props.children}
                </ButtonGroup>
            </DropdownMenu>
        </UncontrolledDropdown>
    );
}

export function ActionsDropdown(props) {
    return (
        <UncontrolledDropdown>
            <DropdownToggle caret={true} color='primary' outline={true} block={true} size="sm">
                {props.Name}
            </DropdownToggle>
            <DropdownMenu>
                <ButtonGroup >
                    {props.children}
                </ButtonGroup>
            </DropdownMenu>
        </UncontrolledDropdown>
    );
}
