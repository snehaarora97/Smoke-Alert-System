int red_led_pin = 9;
int green_led_pin = 8;
int buzzer = 10;
int smoke_sensor_pin = A0;
int Fan = 13;


void setup()
{
  Serial.begin(9600);
  Serial1.begin(38400);
  pinMode(buzzer, OUTPUT);
  pinMode(red_led_pin, OUTPUT);
  pinMode(green_led_pin, OUTPUT);
  pinMode(smoke_sensor_pin, INPUT);
  pinMode(Fan, OUTPUT);
  digitalWrite(Fan, LOW);
}

void loop()
{
  int analogSensor = analogRead(smoke_sensor_pin);
  if (analogSensor > 400)
  {
    Serial.println("Smoke detected...! take action immediately."); //on serial monitor
    Serial1.println("Smoke detected...! take action immediately."); //on mobile phone
    digitalWrite(buzzer, HIGH);
    digitalWrite(Fan, HIGH);
    digitalWrite(green_led_pin, LOW);
    while(1)
    {
    digitalWrite(red_led_pin, HIGH);
    delay(200);
    digitalWrite(red_led_pin, LOW);
    delay(200);
    }
  }
  else
  {
    Serial.println("No flame detected. stay cool");
    Serial1.println("No flame detected. stay cool");
    digitalWrite(buzzer, LOW);
    digitalWrite(red_led_pin, LOW);
    digitalWrite(green_led_pin, HIGH);
  }
  delay(1000);
}














 


     

     

     

     

     
            