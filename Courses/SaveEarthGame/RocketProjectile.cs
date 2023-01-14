using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RocketProjectile : MonoBehaviour
{
    [SerializeField] private Transform rocketHit;
    [SerializeField] private AudioClip rocketExplosion;
    [SerializeField] private LayerMask WhatToDestroy;
    [SerializeField] private Transform bloodyMess;


    private void Awake(){
    }


    private void OnCollisionEnter(Collision other){
        Instantiate(rocketHit, transform.position, Quaternion.identity);
        AudioSource.PlayClipAtPoint(rocketExplosion, transform.position);

        findSplashTargets();

        Destroy(this.gameObject);

    }

    private void findSplashTargets(){
        Collider[] colliders = Physics.OverlapSphere(transform.position, 10f, WhatToDestroy);
        foreach(Collider collider in colliders){
            if(collider.GetComponent<Destroyable>()){
                Destroy(collider.gameObject);
                //Instantiate(bloodyMess, collider.transform.position , Quaternion.identity);
            }
        }
    }
}

