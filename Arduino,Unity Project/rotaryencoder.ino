 int pinA = 4;  // DT Pini D4 pinine bağlı
 int pinB = 3;  // CLK Pini D3 pinine bağlı
 int enkodersayim = 0; //
 int pinASon;  
 int aDeger;
 boolean saatyonu;

 void setup() { 
   pinMode (pinA,INPUT);
   pinMode (pinB,INPUT);
   pinASon = digitalRead(pinA);   
   Serial.begin (9600);
 } 

 void loop() { 
   aDeger = digitalRead(pinA);
   if (aDeger != pinASon){ 
     if (digitalRead(pinB) != aDeger) {  
       Serial.write(1);
       enkodersayim ++;
       saatyonu = true;
     } else {
       saatyonu = false;
       Serial.write(2);
       enkodersayim--;
     }
     Serial.print ("Hareket : ");
     if (saatyonu){
       Serial.println ("Saat Yonu");
     }else{
       Serial.println("Saat Yonunun Tersi");
     }
     Serial.print("Enkoder pozisyonu : ");
     Serial.println(enkodersayim);
     
   } 
   pinASon = aDeger;
 } 
