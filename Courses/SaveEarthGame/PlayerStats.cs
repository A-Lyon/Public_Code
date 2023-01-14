using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class PlayerStats : MonoBehaviour
{
    
    [SerializeField] ThirdPersonShooterController thirdPersonShooterController;
    [SerializeField] Image healthBar;
    [SerializeField] Image batteryBar;
    [SerializeField] Image rocketBar;

    private float health = 100f;
    private float battery = 60f;
    private float rockets = 4f;


    // Update is called once per frame
    void Update()
    {
        if(thirdPersonShooterController)
        {
        healthBar.fillAmount = thirdPersonShooterController.getHealth() / health;
        batteryBar.fillAmount = thirdPersonShooterController.getLaserAmmo() / battery;
        rocketBar.fillAmount = thirdPersonShooterController.getRocketAmmo() / rockets;
        }
    }
}
