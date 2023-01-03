import React, {Component} from "react";
import {Dropdown, DropdownToggle, DropdownMenu, DropdownItem} from 'reactstrap';

class ShowUnits extends Component {

    constructor(props) {
        super(props);
        this.toggle = this.toggle.bind(this);
        this.state = {
            dropdownOpen: false
        };
    }

    toggle() {
        this.setState(prevState => ({
            dropdownOpen: !prevState.dropdownOpen
        }));
    }

    setUnit(name, radius) {
        this.props.setDistanceUnits(name);
        this.props.setEarthRadius(radius);
        this.props.distanceActions.setDistances([]);

    }

    setMiles(props) {
        this.setUnit('mi', 3959);
    }


    setKilometers(props) {
        this.setUnit('km', 6371);
    }

    setNauticalMiles(props) {
        this.setUnit('nmi', 3440);
    }

    customUnit(props) {
        props.toggleCustomUnit();
    }

    render() {
        return (
            <Dropdown isOpen={this.state.dropdownOpen} toggle={this.toggle}>
                <DropdownToggle caret={true} color="primary" outline={true} block={true} size='sm' direction='down'>
                    {"Total: " + this.props.distanceSum + " " + this.props.distanceUnits}
                </DropdownToggle>
                <DropdownMenu >
                    <DropdownItem data-testid='miles-button' onClick={() => this.setMiles(this.props)}>Miles</DropdownItem>
                    <DropdownItem data-testid='km-button' onClick={() => this.setKilometers(this.props)}>Kilometers</DropdownItem>
                    <DropdownItem data-testid='nmi-button' onClick={() => this.setNauticalMiles(this.props)}>Nautical Miles</DropdownItem>
                    <DropdownItem data-testid='custom-button' onClick={() => this.customUnit(this.props)}>Custom</DropdownItem>
                </DropdownMenu>
            </Dropdown>
        );
    }
}

export default ShowUnits;