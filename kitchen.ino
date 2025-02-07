



int gas_sensor_pin = A0; // Gas sensor connected to analog pin A
int sensorThres = 900; // Threshold value of gas sensor
int flame_sensor_pin = 11; // Flame sensor connected to digital pin 11
int Flame = HIGH; // Value of the flame sensor
int red_led_pin = 7; // Red led connected to pin 7 of arduino
int sprinkler_motor_relay1_pin = 8; // Relay_1 connected to pin 8 of arduino to control sprinkler
int buzzer_pin = 10;// Buzzer connected into pin 10 of arduino

//int trig_pin = 8; //ultrasonic sensor trigpin connected to pin 8
//int echo_pin = 9; //ultrasonic sensor echopin connected to pin 9
//long duration;
//int distance_cm;


void setup() {

  Serial.begin(9600); // Initiates Serial communication: Serial monitor       

  Serial.println("Initializing...");
  delay(1000);                                     

  pinMode(A0, INPUT); // Set Gas Sensor as input
  pinMode(11, INPUT); // Set Flame sensor as input
  pinMode(7, OUTPUT); // Set Red led as output
  pinMode(8, OUTPUT); // Set relay as output
  pinMode(10, OUTPUT); // Set buzzer as output 
  
}

void loop() {
   // put your main code here, to run repeatedly:
  CheckGas(); // Run Chech Gas loop to detect any gas leakage
  CheckFlame(); // Run Check Flame loop to detect presence of fire 
}
void CheckGas() {
  int analogSensor = analogRead(A0);
  Serial.print("Gas Sensor:");
  delay(1000);
  Serial.println(analogSensor);
  delay(1000);

  if (analogSensor > sensorThres) {
    Serial.println("GAS LEAKAGE DETECTED");
    //SendMessageGas();
    digitalWrite(8, HIGH); // Turn relay on
    digitalWrite(7, HIGH); // Turn red led on
    digitalWrite(10, HIGH); // Turn buzzer on
  }else{
    Serial.println("NO GAS ALERT");
    digitalWrite(8, LOW); // Turn relay off
    digitalWrite(7, LOW); // Turn red led off
    digitalWrite(10, LOW); // Turn buzzer off
  }
  delay(1000);
}


void CheckFlame() {
  Flame = digitalRead(11);
  Serial.print("Flame Sensor:");
  delay(1000);
  Serial.println(Flame);
  delay(1000);

  if(Flame == LOW) { 
   Serial.println("FLAME DETECTED");
   //SendMessage();
   digitalWrite(8, HIGH); // Turn relay on.
   digitalWrite(7, HIGH); // Turn red led on
   digitalWrite(10, HIGH); // Turn buzzer on
}else{
  Serial.println("NO FLAME ALERT ");
  digitalWrite(8, LOW); // Turn relay off
  digitalWrite(7, LOW); // Turn red led on
  digitalWrite(10, LOW); // Turn buzzer off
  }
  delay(1000);
  
}

 
