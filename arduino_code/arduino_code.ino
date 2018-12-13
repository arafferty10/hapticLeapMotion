unsigned long last_time = 0;

const int motorPin1 = 4;
const int motorPin2 = 5;
const int motorPin3 = 6;
//const int motorPin4 = 4;
//const int motorPin5 = 5;

void setup()
{
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);
    pinMode(4,OUTPUT);
    pinMode(5,OUTPUT);
    pinMode(6,OUTPUT);
//    pinMode(9,OUTPUT);
//    pinMode(10,OUTPUT);
}

void loop()
{
    // Print a heartbeat
    if (millis() > last_time + 2000)
    {
        Serial.println("Arduino is alive!!");
        last_time = millis();
    }

    // Send some message when I receive an 'A' or a 'Z'.
    switch (Serial.read())
    {
        case 'A':
            digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
            digitalWrite(motorPin1, HIGH);
            digitalWrite(motorPin2, HIGH);
            digitalWrite(motorPin3, HIGH);
//            digitalWrite(9, HIGH);
//            digitalWrite(10, HIGH);
            break;
        case 'Z':
            digitalWrite(LED_BUILTIN, LOW);
            digitalWrite(motorPin1, LOW);
            digitalWrite(motorPin2, LOW);
            digitalWrite(motorPin3, LOW);
//            digitalWrite(9, LOW);
//            digitalWrite(10, LOW);
            break;
    }
}
