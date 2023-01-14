using UnityEngine;

public class LaserProjectile : MonoBehaviour
{

    //private Rigidbody laserRigidBody;
    [SerializeField] private Transform laserHit;
    [SerializeField] private Transform laserMiss;
    [SerializeField] private float speed;
    [SerializeField] private AudioClip laserHitSound;
    

    private void Awake(){
        //laserRigidBody = GetComponent<Rigidbody>();
    }

    private void Start(){
        //laserRigidBody.velocity = (transform.forward * speed);
    }



    private void OnCollisionEnter(Collision other){

        if(other.gameObject.tag.Equals("Enemy") || other.gameObject.tag.Equals("Consumer")){
            Instantiate(laserHit, transform.position, Quaternion.identity);
            Destroy(other.gameObject);
        }
        else{
            Instantiate(laserMiss, transform.position, Quaternion.identity);
        }

        AudioSource.PlayClipAtPoint(laserHitSound, transform.localPosition);
        Destroy(this.gameObject);
    }


}
