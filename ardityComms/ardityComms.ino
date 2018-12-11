unsigned long last_time = 0;

void setup()
{
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);
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
            digitalWrite(LED_BUILTIN,HIGH);
            Serial.println("That's the first letter of the abecedarium.");
            break;
        case 'Z':
            digitalWrite(LED_BUILTIN, LOW);
            Serial.println("That's the last letter of the abecedarium.");
            break;
    }
}
