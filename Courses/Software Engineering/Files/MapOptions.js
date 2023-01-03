import React from 'react';
import { Button, ButtonGroup, Modal, ModalBody, ModalFooter, ModalHeader } from 'reactstrap';
import {  CirclePicker } from 'react-color';
import icon from 'leaflet/dist/images/marker-icon.png';
import mug from './MarkerIcons/BeerMug.png';
import bottle from './MarkerIcons/Bottle.png';
import star from './MarkerIcons/star.png';
import Mblack from './MarkerIcons/marker-icon-black.png';
import Mgreen from './MarkerIcons/marker-icon-green.png';
import Mpurple from './MarkerIcons/marker-icon-violet.png';
import dots from './Lines/dots.png'
import solid from './Lines/Solid.png'
import dotslash from './Lines/dotslash.png'
import topo from './Layers/Topo.png'
import satellite from './Layers/Satellite.png'
import bike from './Layers/Bike.png'
import standard from './Layers/Standard.png'

export default function MapOptions(props){

    const MAP_SATELLITE = ["https://api.maptiler.com/maps/hybrid/{z}/{x}/{y}.jpg?key=a8n4fop4OkskMooIjcHF" , '<a href="https://www.maptiler.com/copyright/" target="_blank">&copy; MapTiler</a> <a href="https://www.openstreetmap.org/copyright" target="_blank">&copy; OpenStreetMap contributors</a>'];
    const MAP_TOPOGRAPHICAL = ['https://api.maptiler.com/maps/topo/{z}/{x}/{y}.png?key=a8n4fop4OkskMooIjcHF', '<a href="https://www.maptiler.com/copyright/" target="_blank">&copy; MapTiler</a> <a href="https://www.openstreetmap.org/copyright" target="_blank">&copy; OpenStreetMap contributors</a>' ];
    const MAP_PARKS = ['https://api.maptiler.com/maps/outdoor/{z}/{x}/{y}.png?key=a8n4fop4OkskMooIjcHF' , '<a href="https://www.maptiler.com/copyright/" target="_blank">&copy; MapTiler</a> <a href="https://www.openstreetmap.org/copyright" target="_blank">&copy; OpenStreetMap contributors</a>'];
    const MAP_STANDARD = ['https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png', '&copy; <a href=&quot;http://osm.org/copyright&quot;>OpenStreetMap</a> contributors'];
    

    return (
        <Modal isOpen={props.isOpen} toggle={props.toggleShowMapOptions}>
            <MapOptionsHeader/>

            <MapOptionsBody
                setMapLayer={props.setMapLayer} setMapAttribution = {props.setMapAttribution}
                MAP_PARKS={MAP_PARKS} MAP_SATELLITE={MAP_SATELLITE} MAP_STANDARD={MAP_STANDARD} MAP_TOPOGRAPHICAL={MAP_TOPOGRAPHICAL}>
            </MapOptionsBody>

            <MapLineBody setLineColor={props.setLineColor} setLineType={props.setLineType}/>

            <MapMarkerBody setIconURL={props.setIconURL}/>

            <MapOptionsFooter toggleShowMapOptions={props.toggleShowMapOptions}/>

        </Modal>
    );
}

function MapOptionsHeader(props){
    return(
        <ModalHeader className="font-weight-bold">
            Customize your map!
        </ModalHeader>

    );
}

function MapOptionsBody(props){
    return (

        <ModalBody>
            <tr className="font-weight-bold">
            Select map type:    
            </tr>
            <ButtonGroup>
                <MapChangeButton setMapLayer={props.setMapLayer} map={props.MAP_STANDARD} setMapAttribution={props.setMapAttribution} buttonName={'Standard'} image={standard}/>{' '}
                <MapChangeButton map={props.MAP_TOPOGRAPHICAL} setMapAttribution={props.setMapAttribution} setMapLayer={props.setMapLayer}  buttonName={'Topograph'} image={topo}/>{' '} 
                <MapChangeButton buttonName={'Satellite'} setMapLayer={props.setMapLayer} setMapAttribution={props.setMapAttribution} map={props.MAP_SATELLITE} image={satellite}/>{' '}
                <MapChangeButton image={bike} setMapLayer={props.setMapLayer} setMapAttribution={props.setMapAttribution} map={props.MAP_PARKS} buttonName={'Parks/Paths'}/>{' '}
            </ButtonGroup>
        </ModalBody>
    );
}

function MapChangeButton(props){
    return(
        <Button size='sm' color='outline-primary' 
            onClick={() => {props.setMapLayer(props.map[0]); 
            props.setMapAttribution(props.map[1]);}}>
                   <img src={props.image}/>
                   {props.buttonName}
            </Button>
        )
}

function MapLineBody(props){
    return(
        <ModalBody>
            <tr className="font-weight-bold">
            Select your maps line color:    
            </tr>
            <CirclePicker 
                onChange={(newColor) => {props.setLineColor(newColor)}}> 
            </CirclePicker>
            <tr>.</tr>
            <tr className="font-weight-bold">
            Select your maps line type:
            </tr>
            <ButtonGroup>
                <MapLineButton setLineType={props.setLineType} lineImage={solid} line={"0"}/>
                <MapLineButton setLineType={props.setLineType} lineImage={dots} line={"4 20"}/>
                <MapLineButton setLineType={props.setLineType} lineImage={dotslash} line={"4 5 1 5"} />
            </ButtonGroup>
        </ModalBody>
    )
}

function MapLineButton(props){
    return(
        <Button color='light' onClick={()=>{props.setLineType(props.line)}}><img src={props.lineImage}/>
        </Button>
    )
}

function MapMarkerBody(props){
    return(
        <ModalBody>
            <tr className="font-weight-bold">
            Select your maps markers:
            </tr>
            <MapMarkerButton icon={icon} setIconURL={props.setIconURL}/>
            <MapMarkerButton icon={Mblack} setIconURL={props.setIconURL}/>
            <MapMarkerButton icon={Mgreen} setIconURL={props.setIconURL}/>
            <MapMarkerButton icon={Mpurple} setIconURL={props.setIconURL}/>
            <tr></tr>
            <MapMarkerButton icon={mug} setIconURL={props.setIconURL}/>
            <MapMarkerButton icon={bottle} setIconURL={props.setIconURL}/>
            <MapMarkerButton icon={star} setIconURL={props.setIconURL}/>
        </ModalBody>
    )
}

function MapMarkerButton(props){
    return(
        <Button color='light' 
        onClick={()=>{props.setIconURL(props.icon)}}>
            <img src={props.icon} />
        </Button>
    )
}


function MapOptionsFooter(props){
    return(

        <ModalFooter>
            <Button color="secondary" onClick={props.toggleShowMapOptions}>
                Finished</Button>
        </ModalFooter>
    );
}
