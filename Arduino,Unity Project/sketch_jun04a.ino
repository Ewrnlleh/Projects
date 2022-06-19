// MPU 6050   --->   Arduino 
//
//  VCC   ----->   3.3v
//  GND   ----->   GND
//  SCL   ----->   A5 pin
//  SDA   ----->   A4 pin
#include <Wire.h> //mpu6050 için 

long accelX, accelY, accelZ;
float gForceX, gForceY, gForceZ;

long gyroX, gyroY, gyroZ;
float rotX, rotY, rotZ;

volatile boolean TurnDetected;  
volatile boolean up;

const int PinCLK=2;
const int PinDT=3;
const int PinSW=4;

boolean saatyonu;
int cevirme;

// L298N bağlantıları ve motor yönleri
#define MOTOR1_ILERI 11 // Pin D11 --> ilk motor ileri
#define MOTOR1_GERI 10 // Pin D10 --> ilk motor geri

#define MOTOR2_ILERI 9 // Pin D9 --> ikinci motor ileri
#define MOTOR2_GERI 8 // Pin D8 --> ikinci motor geri

// encoderın hangi yöne dönduğunu belirleyen fonksıyon
void isr ()  {
 //delay(4);  
 if (digitalRead(PinCLK)) // eğer clk değeri 1 gelirse
   up = !digitalRead(PinDT); // saat yönunun tersinde 
 else
   up = digitalRead(PinDT); // saat yönünde dönüyor
 TurnDetected = true;
}

void setup ()  {
 pinMode(PinCLK,INPUT);
 pinMode(PinDT,INPUT);  
 pinMode(PinSW,INPUT);
 
 digitalWrite(PinSW, HIGH); // pinsw değerini açıyor ( 1 olarak atıyor )
 attachInterrupt (0,isr,FALLING); 
 Serial.begin (9600); 
 //Serial.println("Start");

  Wire.begin();
  setupMPU();

 //motorlara çıkış atıyoruz 
 pinMode( MOTOR1_ILERI, OUTPUT ); 
 pinMode( MOTOR1_GERI, OUTPUT );
 pinMode( MOTOR2_ILERI, OUTPUT );
 pinMode(  MOTOR2_GERI, OUTPUT );
 
 digitalWrite(MOTOR1_ILERI, 0 ); // motor kapalı konumda 
 digitalWrite(MOTOR1_GERI,0 );
 digitalWrite(MOTOR2_ILERI, 0 ); //  motor kapalı konumda 
 digitalWrite(MOTOR2_GERI,0 );
}

void loop ()  {
 static long RotaryPosition=0;    // STATIC to count correctly


  recordAccelRegisters();
  recordGyroRegisters();
  printData();
  cevirme = 0;
  //delay(25);

 if (!(digitalRead(PinSW))) {   // butona basılıp basılmadıgını kontrol etme
   if (RotaryPosition == 0) {  // eğer basıldıysa
   } else {
       RotaryPosition=0; // eğer basılmadıysa sıfırlıyor
       digitalWrite(MOTOR1_ILERI, 0 ); // motorlar kapatılıyor
       digitalWrite(MOTOR1_GERI, 0 ); 
       digitalWrite(MOTOR2_ILERI, 0 ); // motorlar kapatılıyor
       digitalWrite( MOTOR2_GERI, 0 ); 
       
       //Serial.print ("Reset = ");
       //Serial.println (RotaryPosition);
   }
 }

 // eğer dönme tespit  edildiyse,
 if (TurnDetected)  {
   if (up) {
     if (RotaryPosition >= 50) { // saat yönunde 50  kere dönerse
       RotaryPosition = 50;
        
     }else {
         RotaryPosition=RotaryPosition+1;
         // eğer saat yönunde dönerse
          saatyonu = true;
          cevirme = 1; // unity e veri göndermek için atanan değişken 
          
          digitalWrite(MOTOR1_ILERI, 1 ); // yön  = ileri
          digitalWrite( MOTOR1_GERI,0 );
          digitalWrite(MOTOR2_ILERI, 1 ); // yön  = ileri
          digitalWrite(MOTOR2_GERI,0 );
      }
   }else {
     if (RotaryPosition <= -50) { // saat yönunün tersinde  50  kere dönerse
       RotaryPosition = -50;
      
      }
       else {
          RotaryPosition=RotaryPosition-1;
          // eğer saat yönunun tersinde dönerse
          saatyonu = false;
          cevirme = 2;
          
          digitalWrite(MOTOR1_ILERI, 0 );
          digitalWrite(MOTOR1_GERI, 1 ); // yön  = geri
          digitalWrite( MOTOR2_ILERI, 0 );
          digitalWrite(MOTOR2_GERI, 1 ); // yön  = geri
     
      }}
      delay(150);
      digitalWrite( MOTOR1_GERI,0 );
      digitalWrite( MOTOR1_ILERI, 0 );
      digitalWrite(MOTOR2_GERI,0 );
      digitalWrite( MOTOR2_ILERI, 0 );
      TurnDetected = false;  // eğer dönme tespit edilmesse yada tespit edilene kadar motorlar sıfırlanır

      /*Serial.print ("Hareket : ");
      if (saatyonu){
       Serial.println ("Saat Yonu");
      }else{
       Serial.println("Saat Yonunun Tersi");
      }
      Serial.print("Enkoder pozisyonu : ");
      Serial.println(RotaryPosition);*/
   
  }
 }

void setupMPU(){ // mpu6050 kurulumu 
  Wire.beginTransmission(0b1101000); //This is the I2C address of the MPU (b1101000/b1101001 for AC0 low/high datasheet sec. 9.2)
  Wire.write(0x6B); //Accessing the register 6B - Power Management (Sec. 4.28)
  Wire.write(0b00000000); //Setting SLEEP register to 0. (Required; see Note on p. 9)
  Wire.endTransmission();  
  Wire.beginTransmission(0b1101000); //I2C address of the MPU
  Wire.write(0x1B); //Accessing the register 1B - Gyroscope Configuration (Sec. 4.4) 
  Wire.write(0x00000000); //Setting the gyro to full scale +/- 250deg./s 
  Wire.endTransmission(); 
  Wire.beginTransmission(0b1101000); //I2C address of the MPU
  Wire.write(0x1C); //Accessing the register 1C - Acccelerometer Configuration (Sec. 4.5) 
  Wire.write(0b00000000); //Setting the accel to +/- 2g
  Wire.endTransmission(); 
}

 void recordAccelRegisters() { // 3 boyutta  açısal ivme değerlerini alıyor 
  Wire.beginTransmission(0b1101000); //I2C address of the MPU
  Wire.write(0x3B); //Starting register for Accel Readings
  Wire.endTransmission();
  Wire.requestFrom(0b1101000,6); //Request Accel Registers (3B - 40)
  while(Wire.available() < 6);
  accelX = Wire.read()<<8|Wire.read(); //Store first two bytes into accelX
  accelY = Wire.read()<<8|Wire.read(); //Store middle two bytes into accelY
  accelZ = Wire.read()<<8|Wire.read(); //Store last two bytes into accelZ
  processAccelData();
}

void processAccelData(){ // mpu6050 den gelen açısal ivme değerlerini anlamlandırcak değerlere dönüştürme
  gForceX = accelX / 16384.0;
  gForceY = accelY / 16384.0; 
  gForceZ = accelZ / 16384.0;
}

void recordGyroRegisters() { // 3 boyutta jiroskop değerlerini alıyor 
  Wire.beginTransmission(0b1101000); //I2C address of the MPU
  Wire.write(0x43); //Starting register for Gyro Readings
  Wire.endTransmission();
  Wire.requestFrom(0b1101000,6); //Request Gyro Registers (43 - 48)
  while(Wire.available() < 6);
  gyroX = Wire.read()<<8|Wire.read(); //Store first two bytes into accelX
  gyroY = Wire.read()<<8|Wire.read(); //Store middle two bytes into accelY
  gyroZ = Wire.read()<<8|Wire.read(); //Store last two bytes into accelZ
  processGyroData();
}

void processGyroData() { // mpu6050 den gelen jiroskop değerlerini anlamlandırcak değerlere dönüştürme
  rotX = gyroX / 131.0;
  rotY = gyroY / 131.0; 
  rotZ = gyroZ / 131.0;
}

void printData() { // Verileri yazdırıyoruz
 
  //Serial.print(" Accel (g)");
  //Serial.print(" X=");

  Serial.print(cevirme);
  Serial.print(";");
  
  Serial.print(accelX);
  Serial.print(";");
  
  //Serial.print(" Y=");
  
  Serial.print(accelY);
  Serial.print(";");
  
  //Serial.print(" Z=");
  
  Serial.print(accelZ);
  Serial.print(";");
  
  //Serial.print("Gyro (deg)");
  //Serial.print(" X=");
  
  Serial.print(gyroX);
  Serial.print(";");
   
  //Serial.print(" Y=");
  
  Serial.print(gyroY);
  Serial.print(";");
   
  //Serial.print(" Z=");
  
  Serial.print(gyroZ);
  Serial.println("");
  Serial.flush();
}
