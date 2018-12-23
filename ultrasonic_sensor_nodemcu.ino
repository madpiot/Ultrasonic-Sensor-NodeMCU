/***************************************************************
 * COMPONENT TEST PROGRAM   : ULTRASONIC SENSOR TEST
 * BOARD                    : NodeMCU 
 * INPUT                    : ULTRASONIC SENSOR
 * OUTPUT                   : SERIAL MONITOR
 * TEST ENGINEER            : RABBANI BASHA
 * HARDWARE ENGINEER        : VENKATESH R
 * PROGRAMMER               : MADHU PARVATHANENI
 * ORGANIZATION             : MADHU HARDWARE GROUP, Orange Research Labs Industries (ORL Industries)
 * DATE                     : 23rd DEC 2018
 ****************************************************************/
// Port Declaration
int trig=D2,echo=D3;

long ultrason() 
{
   long duration, distance;
   digitalWrite(trig,LOW);
   delayMicroseconds(2);
   digitalWrite(trig, HIGH);
   delayMicroseconds(10);
   digitalWrite(trig, LOW);
   duration = pulseIn(echo, HIGH);
   distance = duration * 340 / (2 * 10000);
   return distance;
}
void setup() 
{
 pinMode(trig,OUTPUT); // TRIG PIN OF ULTRASONIC SENSOR
 pinMode(echo,INPUT); // ECHO PIN OF ULTRASONIC SENSOR
 Serial.begin(9600);
 Serial.println("WELCOME TO ULTRASONIC SENSOR TEST");
}

void loop() 
{
 Serial.print("DISTANCE: ");
 Serial.print(ultrason());
 Serial.println(" CM");
 delay(1000);
}
