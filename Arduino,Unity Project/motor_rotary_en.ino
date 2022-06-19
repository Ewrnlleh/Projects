volatile boolean TurnDetected;  // need volatile for Interrupts
volatile boolean up;

const int PinCLK=2;
const int PinDT=3;
const int PinSW=4;

// L9110 connections
#define L9110_B_IA 11 // Pin D10 --> Motor B Input A
#define L9110_B_IB 10 // Pin D11 --> Motor B Input B

#define MOTOR2_ILERI 9 // Pin D8 --> Motor 2 Input A
#define MOTOR2_GERI 8 // Pin D9 --> Motor 2 Input B

 
// Motor Speed & Direction
#define MOTOR_B_DIRFOR L9110_B_IA // Motor Direction fORWARD
#define MOTOR_B_DIRBACK L9110_B_IB // Motor Direction bACKWARD

// Interrupt routine runs if CLK goes from HIGH to LOW
void isr ()  {
 delay(4);  // delay for Debouncing
 if (digitalRead(PinCLK))
   up = digitalRead(PinDT);
 else
   up = !digitalRead(PinDT);
 TurnDetected = true;
}

void setup ()  {
 pinMode(PinCLK,INPUT);
 pinMode(PinDT,INPUT);  
 pinMode(PinSW,INPUT);
 digitalWrite(PinSW, HIGH); // Pull-Up resistor for switch
 
 attachInterrupt (0,isr,FALLING); // interrupt 0 always connected to pin 2 on Arduino UNO
 Serial.begin (9600);
 Serial.println("Start");
 pinMode( MOTOR_B_DIRFOR, OUTPUT );
 pinMode( MOTOR_B_DIRBACK, OUTPUT );
  pinMode( MOTOR2_ILERI, OUTPUT );
 pinMode(  MOTOR2_GERI, OUTPUT );
 digitalWrite(MOTOR_B_DIRFOR, 0 ); // Set motor to off
 digitalWrite(MOTOR_B_DIRBACK,0 );
  digitalWrite(MOTOR2_ILERI, 0 ); // Set motor to off
 digitalWrite(MOTOR2_GERI,0 );
}

void loop ()  {
 static long RotaryPosition=0;    // STATIC to count correctly

 if (!(digitalRead(PinSW))) {   // check if button is pressed
   if (RotaryPosition == 0) {  // check if button was already pressed
   } else {
       RotaryPosition=0; // if YES, then reset position to ZERO
       digitalWrite(MOTOR_B_DIRFOR, 0 ); // turn motor off
       digitalWrite(MOTOR_B_DIRBACK, 0 ); 
        digitalWrite(MOTOR2_ILERI, 0 ); // turn motor off
       digitalWrite( MOTOR2_GERI, 0 ); 
       Serial.print ("Reset = ");
       Serial.println (RotaryPosition);
   }
 }
 
 // Runs if rotation was detected
 if (TurnDetected)  {
   if (up) {
     if (RotaryPosition >= 100) { // Max value set to 100
       RotaryPosition = 100;
        
     }else {
         RotaryPosition=RotaryPosition+2;
         // if Rotation is Clockwise
          digitalWrite(MOTOR_B_DIRFOR, 1 ); // direction = forward
          digitalWrite( MOTOR_B_DIRBACK,0 );
            digitalWrite(MOTOR2_ILERI, 1 ); // direction = forward
          digitalWrite(MOTOR2_GERI,0 );
      }
   }else {
     if (RotaryPosition <= -100) { // Max value set to -100
       RotaryPosition = -100;
      
      }
       else {
         RotaryPosition=RotaryPosition-2;
          // if Rotation is Counter-Clockwise 
          digitalWrite( MOTOR_B_DIRFOR, 0 );
          digitalWrite(MOTOR_B_DIRBACK, 1 ); // direction = reverse
            digitalWrite( MOTOR2_ILERI, 0 );
          digitalWrite(MOTOR2_GERI, 1 ); // direction = reverse
     
      }}
      delay(200);
      digitalWrite( MOTOR_B_DIRBACK,0 );
      digitalWrite( MOTOR_B_DIRFOR, 0 );
       digitalWrite(MOTOR2_GERI,0 );
      digitalWrite( MOTOR2_ILERI, 0 );
   TurnDetected = false;  // do NOT repeat IF loop until new rotation detected
   Serial.print ("Speed = ");  
   Serial.println (RotaryPosition);
   
  }
 }
