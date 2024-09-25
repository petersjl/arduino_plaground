int potpin=0;// initialize analog pin 0
int ledpin=11;//initialize digital pin 11（PWM output）
int val=0;// Temporarily store variables' value from the sensor
int history[10];
int history_size = sizeof(history) / sizeof(history[0]);
int index = 0;
int duty = 0;
void setup()
{
  pinMode(ledpin,OUTPUT);// define digital pin 11 as “output”
  Serial.begin(9600);// set baud rate at 9600
// attention: for analog ports, they are automatically set up as “input”
}
void loop()
{
  val=analogRead(potpin);// read the analog value from the sensor and assign it to val
  //Serial.println(val);// display value of val
  history[index++ % history_size] = val;
  duty = 1023;
  for (int i = 0; i < history_size; i++){
    duty = min(history[i], duty);
  }
  Serial.println(duty);
  analogWrite(ledpin,duty/4);// turn on LED and set up brightness（maximum output of PWM is 255）
  delay(10);// wait for 0.01 second
}