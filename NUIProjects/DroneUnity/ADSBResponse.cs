using System.Collections;
using System.Collections.Generic;
using UnityEngine;


//This class handles the model for our response from ADSBexchange

// Root myDeserializedClass = JsonConvert.DeserializeObject<Root>(myJsonResponse);
    public class Aircraft
    {
        public string hex { get; set; }
        public string type { get; set; }
        public string flight { get; set; }                 // flight number for display
        public string r { get; set; }                      // registration
        public string t { get; set; }
        public int alt_baro { get; set; }                  // altitude measurement  // likely an int, grag "ground" and use separately.
        public int alt_geom { get; set; }                  // great if the transmitter uses this
        public double gs { get; set; }
        public int ias { get; set; }
        public int tas { get; set; }
        public double mach { get; set; }
        public int wd { get; set; }
        public int ws { get; set; }
        public int oat { get; set; }
        public int tat { get; set; }
        public int track { get; set; }
        public double track_rate { get; set; }
        public double roll { get; set; }
        public double mag_heading { get; set; }
        public double true_heading { get; set; }
        public int baro_rate { get; set; }
        public int geom_rate { get; set; }
        public string squawk { get; set; }
        public string emergency { get; set; }
        public string category { get; set; }
        public double nav_qnh { get; set; }
        public int nav_altitude_mcp { get; set; }
        public int nav_heading { get; set; }
        public double lat { get; set; }                      // we need this 
        public double lon { get; set; }                      // we need this 
        public int nic { get; set; }
        public int rc { get; set; }
        public double seen_pos { get; set; }
        public int version { get; set; }
        public int nic_baro { get; set; }
        public int nac_p { get; set; }
        public int nac_v { get; set; }
        public int sil { get; set; }
        public string sil_type { get; set; }
        public int gva { get; set; }
        public int sda { get; set; }
        public int alert { get; set; }
        public int spi { get; set; }
        public List<object> mlat { get; set; }
        public List<object> tisb { get; set; }
        public int messages { get; set; }
        public int seen { get; set; }
        public double rssi { get; set; }
    }

    public class ADSBResponse
    {
        public List<Aircraft> aircraft { get; set; }
        public int total { get; set; }
        public long ctime { get; set; }
        public long now { get; set; }
        public int ptime { get; set; }
    }




