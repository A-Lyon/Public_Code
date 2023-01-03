using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Cinemachine;
using StarterAssets;
using UnityEngine.SceneManagement;


public class ThirdPersonShooterController : MonoBehaviour
{

    [SerializeField] private CinemachineVirtualCamera aimVirtualCamera;
    [SerializeField] private float normalSensitivity;
    [SerializeField] private float aimSensitivity;
    [SerializeField] private LayerMask aimColliderLayerMask = new LayerMask();
    [SerializeField] private Transform debugTransform;
    [SerializeField] private float playerForwardSnapSpeed;
    [SerializeField] private Transform laserProjectile;
    [SerializeField] private Transform laserMuzzleFlash;

    [SerializeField] private Transform spawnLaserPosition;
    [SerializeField] private AudioClip laserSound;
    [SerializeField] private AudioClip laserRefill;
    [SerializeField] private AudioClip rocketRefill;
    [SerializeField] private Transform rocketProjectile;
    [SerializeField] private Transform rocketMuzzleFlash;

    [SerializeField] private Transform spawnRocketPosition;
    [SerializeField] private AudioClip rocketSound;

    PauseMenu pauseMenu;

    //[SerializeField] private Transform ammoRefill;
    
    //ammo
    private int laserAmmo = 60;
    private int rocketAmmo = 4;

    private int health = 100;
    private bool winCheck = false;
    private int delay = 5;



    private StarterAssetsInputs starterAssetsInputs;
    private ThirdPersonController thirdPersonController;
    private Animator _animator;

    private void Awake(){
        starterAssetsInputs = GetComponent<StarterAssetsInputs>();
        thirdPersonController = GetComponent<ThirdPersonController>();
        _animator = GetComponent<Animator>();
        pauseMenu = GetComponent<PauseMenu>();
    }

    private void OnCollisionEnter(Collision other){
        if(other.gameObject.tag.Equals("EnemyBullet")){
            health -= 15;
            Debug.Log("youve been hit bitch");
        }
        if(other.gameObject.tag.Equals("LaserAmmo")){
            addLaserAmmo(60);
            addHealth(100);
            AudioSource.PlayClipAtPoint(laserRefill, transform.position);
        }
        if(other.gameObject.tag.Equals("RocketAmmo")){
            addRocketAmmo(60);
            AudioSource.PlayClipAtPoint(rocketRefill, transform.position);
        }
    }

    private void onTriggerEnter(Collision other){
        if(other.gameObject.tag.Equals("LaserAmmo")){
            this.laserAmmo += 200;
        }
        if(other.gameObject.tag.Equals("RocketAmmo")){
            this.rocketAmmo += 4;
        }
    }

    private void Update()
    {
        Vector3 mouseWorldPosition = Vector3.zero;
        Vector2 screenCenter = new Vector2(Screen.width / 2f, Screen.height / 2f);
        Ray ray = Camera.main.ScreenPointToRay(screenCenter);
        
        // Crosshair logic
        if(Physics.Raycast(ray,out RaycastHit raycastHit, 999f, aimColliderLayerMask)){
            //turn off debug to remove the green ball for testing.
            // debugTransform.position = raycastHit.point;
            mouseWorldPosition = raycastHit.point;
        }    
        
        //Aim and zoom in
        if(starterAssetsInputs.aim){
            aimVirtualCamera.gameObject.SetActive(true);
            thirdPersonController.SetSensitivity(aimSensitivity);
            //change players forwart vector using vector3 not quaternion
            //change speed of player forward snapping using the 
            thirdPersonController.setRotateOnMove(false);
            _animator.SetBool("Aim", true);            
            
            Vector3 worldAimTarget = mouseWorldPosition;
            worldAimTarget.y = transform.position.y;
            Vector3 aimDirection = (worldAimTarget - transform.position).normalized;

            transform.forward = Vector3.Lerp(transform.forward, aimDirection, Time.deltaTime * playerForwardSnapSpeed);
        }
        else{
            aimVirtualCamera.gameObject.SetActive(false);
            thirdPersonController.SetSensitivity(normalSensitivity);
            thirdPersonController.setRotateOnMove(true);
            _animator.SetBool("Aim", false);

        }


        //Shoot Laser
        if(starterAssetsInputs.laser && !pauseMenu.gamePaused){
            Vector3 aimDirection = (mouseWorldPosition - spawnLaserPosition.position).normalized;
            
            if(laserAmmo > 0){
                var laser = Instantiate(laserProjectile, spawnLaserPosition.position, Quaternion.LookRotation(aimDirection,Vector3.forward));
                laser.GetComponent<Rigidbody>().velocity = aimDirection * 100 ;
                AudioSource.PlayClipAtPoint(laserSound, transform.position);
                Instantiate(laserMuzzleFlash, spawnLaserPosition.position, Quaternion.LookRotation(aimDirection,Vector3.up));
                laserAmmo--;
            }
            starterAssetsInputs.laser = false; 
        }

        //Shoot Rocket
        if(starterAssetsInputs.rocket && !pauseMenu.gamePaused){
            Vector3 aimDirection = (mouseWorldPosition - spawnRocketPosition.position).normalized;
            
            if(rocketAmmo > 0){
                var rocket = Instantiate(rocketProjectile, spawnRocketPosition.position, Quaternion.LookRotation(aimDirection,Vector3.forward));
                rocket.GetComponent<Rigidbody>().velocity = aimDirection * 100 ;
                AudioSource.PlayClipAtPoint(rocketSound, transform.position);
                Instantiate(rocketMuzzleFlash, spawnRocketPosition.position, Quaternion.LookRotation(aimDirection,Vector3.up));
                rocketAmmo--;
                Debug.Log(rocketAmmo);
            }
            starterAssetsInputs.rocket = false; 
        }

        //Death Condition Check

        if(health <= 0){
            SceneManager.LoadScene("GameOver");
        }

        if(!winCheck){
            winCheck = true;
            Invoke(nameof(checkWin), delay);
        }
    }

    public int getLaserAmmo(){
        return laserAmmo;
    }

    public void addLaserAmmo(int ammo){
        laserAmmo += ammo;

        if(laserAmmo > 60){
            laserAmmo = 60;
        }

    }

    public int getRocketAmmo(){
        return rocketAmmo;
    }

    public void addRocketAmmo(int ammo){
        rocketAmmo += ammo;

        if(rocketAmmo > 4){
            rocketAmmo = 4;
        }
    }

    public int getHealth(){
        return health;
    }

    public void addHealth(int heal){
        health += heal;

        if(health > 100){
            health = 100;
        }
    }

        private void checkWin(){
            GameObject[] consumers = GameObject.FindGameObjectsWithTag("Consumer");

        Debug.Log("Consumers left: " + consumers.Length);

            if(consumers.Length <= 0){
                SceneManager.LoadScene("GameWin");
            }
        winCheck = false;
    }
}
