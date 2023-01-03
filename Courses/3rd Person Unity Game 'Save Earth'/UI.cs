using UnityEngine;

public class UI : MonoBehaviour
{

    public GameObject pauseMenu;

    public static UI instance;

    private void Awake()
    {
        if(instance == null){
            instance = this;
        }
    }

    private void Start()
    {
        pauseMenu.SetActive(false);
    }

    

}
