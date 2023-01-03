using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using Newtonsoft.Json;
using UnityEngine.Networking;

public class ADSBRequest : MonoBehaviour
{

//might need to pay to get the official request URL and key. Currently produces invalid key from RapidAPI
    private string ADSBexchangeURL = "https://adsbexchange-com1.p.rapidapi.com/v2/lat/39.6519/lon/-104.78197/dist/10/@APPID=";

    private string fortOpenSkyURL = "https://opensky-network.org/api/states/all?lamin=40.3804&lomin=-105.0934&lamax=40.6240&lomax=-105.1005";
            // upper bound for FoCo: 40.6240105262557, -105.10059208302569 
            // lower bound for loveland: 40.38040677184718, -105.09349054495046
            // fort collins openSky: "https://opensky-network.org/api/states/all?lamin=40.3804&lomin=-105.0934&lamax=40.6240&lomax=-105.1005";

    private string denverOpenSkyURL = "https://opensky-network.org/api/states/all?lamin=39.6519&lomin=-104.7819&lamax=40.0724&lomax=-104.4645";
            //upper for denver: 40.07241951800824, -104.46451835033419
            // lower for denver: 39.65196362343024, -104.78197801381714
            // denver opensky: "https://opensky-network.org/api/states/all?lamin=39.6519&lomin=-104.7819&lamax=40.0724&lomax=-104.4645";

    private double userLatitude;
    private double userLongitude;      
    [SerializeField] GameObject latInput;
    [SerializeField] GameObject lonInput;

    //time between API calls
    [SerializeField] float updateTime;
    private UserLocation location;
    private bool requestHold;  
    private string url;
 


    void Start(){
        requestHold = false;
        location = GetComponent<UserLocation>();

    }

    void Update(){
        makeRequestWithWait();
    }

    IEnumerator makeADSBRequest(){

        UnityWebRequest request = UnityWebRequest.Get(denverOpenSkyURL);
        yield return request.SendWebRequest();

        if(request.result != UnityWebRequest.Result.Success){
            Debug.Log("Request to API has failed. Check coordinates or try again later.");
        }
        else{
            var ADSBJson = JsonConvert.DeserializeObject<Aircraft>(request.downloadHandler.text);
            Debug.Log(ADSBJson.ToString()); 
        }

    }

    void makeRequestWithWait(){
        if(!requestHold){
            StartCoroutine(makeADSBRequest());
            requestHold = true;
            Invoke(nameof(waitReset), updateTime);
        }
    }

    void waitReset(){
        requestHold = false;
    }

    public void getUserLocation(){

        if(location.getLocationStatus()){
            userLatitude = location.getUserLatitude();
            userLongitude = location.getUserLongitude();
            Debug.Log("Latitude: " + userLatitude);
            Debug.Log("Longitude: " + userLongitude);
            
            latInput.SetActive(false);
            lonInput.SetActive(false);
        }
        else if(!location.getLocationStatus() && !location.getManualEntry()){
            Debug.Log("Location Services not working. Please enter location manually.");
            location.setManualEntry(true);
            
            //display UI for locations
            latInput.SetActive(true);
            lonInput.SetActive(true);
        }
        else if(location.getManualEntry()){
            location.setManualEntry(false);

            //remove UI for manual entry
            latInput.SetActive(false);
            lonInput.SetActive(false);
        }

    }


}
