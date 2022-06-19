using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;
using System.IO.Ports;

public class encoder : MonoBehaviour
{
    // Start is called before the first frame update
    public GameObject cylinder;
    public GameObject cylinder2;


    SerialPort sp;
    string port = "COM3";
    int baudrate = 9600;
 
 
 
 void Start()
    {
         sp = new SerialPort(port, baudrate);

        sp.Open();

    }

void Update()
    {
        if (sp.IsOpen)
        {
            try
            {
                if (sp.ReadByte() == 1)
                {
                    cylinder.transform.localScale -= new Vector3(0, 0.1f, 0);
                    cylinder.transform.position -= new Vector3(0.1f, 0, 0);

                    cylinder2.transform.localScale += new Vector3(0, 0.1f, 0);
                    cylinder2.transform.position -= new Vector3(0, 0.1f, 0);

                    
                }
            
                if (sp.ReadByte() == 2)
                {
                    cylinder.transform.localScale += new Vector3(0, 0.1f, 0);
                    cylinder.transform.position += new Vector3(0.1f, 0, 0);

                    cylinder2.transform.localScale -= new Vector3(0, 0.1f, 0);
                    cylinder2.transform.position += new Vector3(0, 0.1f, 0);
                    

                }
            }
            catch (System.Exception)
            {

                throw;
            }
        }
    }

    
}
