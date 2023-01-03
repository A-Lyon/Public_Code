using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class UpdateAircraft : MonoBehaviour
{

    [SerializeField] GameObject aircraftRequest;
    ADSBRequest script;

    // Start is called before the first frame update
    void Start(){
        script = aircraftRequest.GetComponent<ADSBRequest>();
        script.enabled = false;
    }

    public void startFlying(){
        script.enabled = true;
        Debug.Log("ADSB update starting.");
    }

    public void stopFlying(){
        script.enabled = false;
        Debug.Log("ADSB update stopped.");
    }

}
