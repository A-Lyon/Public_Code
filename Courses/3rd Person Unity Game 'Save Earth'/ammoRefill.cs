using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ammoRefill : MonoBehaviour
{
  
    private void onTriggerEnter(Collider other){
        if(other.gameObject.name == "LaserAmmo"){
            
        }
        if(other.gameObject.name == "RocketAmmo"){
            
        }
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
