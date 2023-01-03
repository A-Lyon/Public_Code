using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;

public class UserLocation : MonoBehaviour
{

    private double userLatitude;
    private double userLongitude;
    bool userFound, manualEntry, latitudeSet, longitudeSet = false;

    void Start(){
        tryLocationUpdate();
    }

    void tryLocationUpdate(){
        StartCoroutine(LocationCoroutine());
    }

    IEnumerator LocationCoroutine() {

        //Check which device is being used, and ask for location permissions.
        //Possibly wont need this if ONLY using the magicLeap
        // No permission handling needed in Editor
            #if UNITY_EDITOR
        
        //Will need to ask permission from user. 
            #elif UNITY_ANDROID
                if (!UnityEngine.Android.Permission.HasUserAuthorizedPermission(UnityEngine.Android.Permission.CoarseLocation)) {
                    UnityEngine.Android.Permission.RequestUserPermission(UnityEngine.Android.Permission.CoarseLocation);
                }

        // First, check if user has location service enabled
                if (!UnityEngine.Input.location.isEnabledByUser) {
                    // TODO Failure
                    Debug.LogFormat("Android and Location not enabled");
                    yield break;
                }

            #elif UNITY_IOS
                if (!UnityEngine.Input.location.isEnabledByUser) {
                    // TODO Failure
                    Debug.LogFormat("IOS and Location not enabled");
                    yield break;
                }
            #endif


        // Start service before querying location
        UnityEngine.Input.location.Start(500f, 500f);
                
        // Wait until service initializes
        int maxWait = 20;
        while (UnityEngine.Input.location.status == LocationServiceStatus.Initializing && maxWait > 0) {
            yield return new WaitForSecondsRealtime(1);
            maxWait--;
        }

        // Editor has a bug which doesn't set the service status to Initializing. So extra wait in Editor.
        #if UNITY_EDITOR
            int editorMaxWait = 15;
                while (UnityEngine.Input.location.status == LocationServiceStatus.Stopped && editorMaxWait > 0) {
                    yield return new WaitForSecondsRealtime(1);
                editorMaxWait--;
                }
        #endif

        // Service didn't initialize in 15 seconds
        if (maxWait < 1) {
            // TODO Failure
            Debug.LogFormat("Timed out");
            yield break;
        }

        // Connection has failed
        if (UnityEngine.Input.location.status != LocationServiceStatus.Running) {
            // TODO Failure
            userFound = false;
            Debug.LogFormat("Unable to determine device location. Failed with status {0}", UnityEngine.Input.location.status);
            yield break;
        } else {
            userFound = true;
            Debug.LogFormat("Location service live. status {0}", UnityEngine.Input.location.status);
            // Access granted and location value could be retrieved
            Debug.LogFormat("Location: " 
                + UnityEngine.Input.location.lastData.latitude + " " 
                + UnityEngine.Input.location.lastData.longitude + " " 
                + UnityEngine.Input.location.lastData.altitude + " " 
                );

            userLatitude = UnityEngine.Input.location.lastData.latitude;
            userLongitude = UnityEngine.Input.location.lastData.longitude;
            // TODO success do something with location
        }

        // Stop service if there is no need to query location updates continuously
        UnityEngine.Input.location.Stop();
    }

    public double getUserLatitude(){
            return userLatitude;
    }

    public bool getLatitudeSet(){
        return latitudeSet;
    }



    public double getUserLongitude(){
            return userLongitude;
    }

    public bool getLongitudeSet(){
        return longitudeSet;
    }

    public bool getLocationStatus(){
        return (userFound || (latitudeSet && longitudeSet));
    }

    public bool getManualEntry(){
        return manualEntry;
    }

    public void setManualEntry(bool newState){
        manualEntry = newState;
    }

    public void setLocationStatus(bool newState){
        userFound = true;
    }

    public void setLatitude(string lat){
        if(!Double.TryParse(lat, out userLatitude)){
            Debug.Log("Invalid coordinate format, please enter only numbers in the form ##.###");
            latitudeSet = false;
        }
        else{
            if(userLatitude > 90.0 || userLatitude < -90.0){
                Debug.Log("Invalid coordinate, latitude must be between -90.0 and 90.0.");
                latitudeSet = false;
            }
            else{
                latitudeSet = true;
            }
        }

    }

    public void setLongitude(string lon){
        if(!Double.TryParse(lon, out userLongitude)){
            Debug.Log("Invalid cordinate format, please enter only numbers in the form ###.###");
            longitudeSet = false;
        }
        else{
            if(userLongitude > 180.0 || userLongitude < -180.0){
                Debug.Log("Invalid coordinate, longitude must be between -180.0 and 180.0.");
                longitudeSet = false;
            }
            else{
                longitudeSet = true;
            }
        }
    }
}