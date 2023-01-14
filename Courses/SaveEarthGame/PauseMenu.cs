using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using StarterAssets;

public class PauseMenu : MonoBehaviour
{
    public bool gamePaused;
    private StarterAssetsInputs starterAssetsInputs;
    [SerializeField] GameObject PauseUI;
    [SerializeField] GameObject ScreenUI;

    void Start(){
        gamePaused = false;
        starterAssetsInputs = GetComponent<StarterAssetsInputs>();
    }

    void Update()
    {
        if(starterAssetsInputs.escape){
            if(gamePaused){
                Resume();
            }
            else{
                Pause();
            }
            starterAssetsInputs.escape = false;
        }
    }

    public void Pause(){
        PauseUI.SetActive(true);
        ScreenUI.SetActive(false);
        Time.timeScale = 0f;
        gamePaused = true;
    }

    public void Resume(){
        PauseUI.SetActive(false);
        ScreenUI.SetActive(true);
        Time.timeScale = 1f;
        gamePaused = false;
    }
}
