using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
public class GameControl : MonoBehaviour
{

    public void restart(){
        SceneManager.LoadScene("SaveEarth", 0);
    }

    public void quit(){
        //Debug.Log("Quit Success.");
        Application.Quit();
    }

    public void startGame(){
        SceneManager.LoadScene("SaveEarth", 0);
    }

    public void instructions(){
        SceneManager.LoadScene("Instructions", 0);
    }
    
    public void mainMenu(){
        SceneManager.LoadScene("EntryScreen", 0);
    }
}
