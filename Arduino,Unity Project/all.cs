using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;
using System.IO.Ports;

public class all : MonoBehaviour
{

    SerialPort stream;

    public GameObject cylinder;
    //public GameObject cylinder2;

    float acc_normalizer_factor = 0.00025f;
    float gyro_normalizer_factor = 1.0f / 32768.0f;   // 32768 is max value captured during test on imu

    float curr_angle_x = 90;
    float curr_angle_y = 90;
    float curr_angle_z = 0;

    //float curr_angle_x1 = 180;
    //float curr_angle_y1 = 90;
    //float curr_angle_z1 = 0;

    float curr_offset_x = 5.71f;
    float curr_offset_y = 37.28f;
    float curr_offset_z = -2.54f;


    //float curr_offset_x1 = -0.35f;
    //float curr_offset_y1 = 34.98f;
    //float curr_offset_z1 = -9;

    // Increase the speed/influence rotation
    public float factor = 7; //  silindirin dönm hızı


    public bool enableRotation;
    public bool enableTranslation;

    //port ve freaknsı ayarlıyoruz
    string port = "COM3";
    int baudrate = 9600;
 
    // Start, ilk olarak  updateden önce çağrılır
    void Start()
    {
        stream = new SerialPort(port, baudrate); // arduino bağlantısı

        stream.Open(); 
    }

    // her frame için çalışıyor
    void Update()
    {
        string dataString = "null received"; // bir string tanımlanıyor

            if (stream.IsOpen)
            {
            try
            {
                dataString = stream.ReadLine();
                Debug.Log("RCV_ : " + dataString); // gelen verileri yazdırıoruz

            }
            catch (System.IO.IOException ioe)
            {
                Debug.Log("IOException: " + ioe.Message); // hata olursa hata mesajını donduruyoruz
            }

        }
        else
            dataString = "NOT OPEN";
        Debug.Log("RCV_ : " + dataString); // eğer stream gelmediyse yayın açılmadı yazıyoruz

        if (!dataString.Equals("NOT OPEN"))  // Yayın başarılı bir şekilde geliyorsa
        {
            // gelen değerler bu tarz  "cevirmedegeri;accx;accy;accz;gyrox;gyroy;gyroz"
            char splitChar = ';';
            string[] dataRaw = dataString.Split(splitChar); // gelen değerleri ";" ile ayırıp dataRaw dizisine atıyoruz


            

            int cevirme = Int32.Parse(dataRaw[0]);

            // ayırmış oldugumuz accumulator değerlerini normalize ediyoruz
            float ax = Int32.Parse(dataRaw[1]) * acc_normalizer_factor;
            float ay = Int32.Parse(dataRaw[2]) * acc_normalizer_factor;
            float az = Int32.Parse(dataRaw[3]) * acc_normalizer_factor;

            // ayırmış oldugumuz gyro değerlerini  normalize ediyoruz
            float gx = Int32.Parse(dataRaw[4]) * gyro_normalizer_factor;
            float gy = Int32.Parse(dataRaw[5]) * gyro_normalizer_factor;
            float gz = Int32.Parse(dataRaw[6]) * gyro_normalizer_factor;

            // engel olmak 
            if (Mathf.Abs(ax) - 1 < 0) ax = 0;
            if (Mathf.Abs(ay) - 1 < 0) ay = 0;
            if (Mathf.Abs(az) - 1 < 0) az = 0;


            curr_offset_x += ax;
            //curr_offset_x1 += ax;
            curr_offset_y += ay;
            //curr_offset_y1 += ay;
            curr_offset_z += az;
            //curr_offset_z1 += 0;// The IMU module have value of z axis of 16600 caused by gravity


            // gelen ufak yani gürültü değerlerini engelliyoruz
            if (Mathf.Abs(gx) < 0.025f) gx = 0f;
            if (Mathf.Abs(gy) < 0.025f) gy = 0f;
            if (Mathf.Abs(gz) < 0.025f) gz = 0f;

            curr_angle_x += gx;
            //curr_angle_x1 += gx;
            curr_angle_y += gy;
            //curr_angle_y1 += gy;
            curr_angle_z += gz;
            //curr_angle_z1 += gz;

            if (cevirme == 1)
                {
                    //cylinder.transform.localScale -= new Vector3(0, 0.1f, 0);
                    cylinder.transform.position += new Vector3(0.1f, 0, 0);

                    //cylinder2.transform.localScale += new Vector3(0, 0.1f, 0);
                    //cylinder2.transform.position -= new Vector3(0, 0.1f, 0);
                    
                }
            
            if (cevirme == 2)
                {
                    //cylinder.transform.localScale += new Vector3(0, 0.1f, 0);
                    cylinder.transform.position -= new Vector3(0.1f, 0, 0);

                    //cylinder2.transform.localScale -= new Vector3(0, 0.1f, 0);
                    //cylinder2.transform.position += new Vector3(0, 0.1f, 0);
                    

                }

            if (enableTranslation) cylinder.transform.position = new Vector3(curr_offset_x, curr_offset_y, curr_offset_z);
            if (enableRotation) cylinder.transform.rotation = Quaternion.Euler(curr_angle_x * factor, curr_angle_y * factor, curr_angle_z * factor);

            //if (enableTranslation) cylinder2.transform.position = new Vector3(curr_offset_x1, curr_offset_y1, curr_offset_z1);
            //if (enableRotation) cylinder2.transform.rotation = Quaternion.Euler(curr_angle_x1 * factor, curr_angle_y1 * factor, -curr_angle_z1 * factor);
        }
    }
}
