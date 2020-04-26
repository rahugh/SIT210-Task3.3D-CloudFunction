int led = D2;

void setup()
{
    pinMode(led,OUTPUT);
    Particle.subscribe("Deakin_RIOT_SIT210_Photon_Buddy", myHandler, ALL_DEVICES);
}

void loop() {
}

void myHandler(const char *event, const char *data)
{
    if (strcmp(data, "wave") == 0)
    {
        digitalWrite(led,HIGH);
        delay(250);
        digitalWrite(led,LOW);
        delay(250);

        digitalWrite(led,HIGH);
        delay(250);
        digitalWrite(led,LOW);
        delay(250);

        digitalWrite(led,HIGH);
        delay(250);
        digitalWrite(led,LOW);
    }
    else if (strcmp(data, "pat") == 0)
    {
        int j = 0;
        while (j++ < 255) {
          analogWrite(led, j);
          delay(10);
        }

        while (j--) {
          analogWrite(led, j);
          delay(10);
        }

        digitalWrite(led,LOW);
    }
    else
    {
        digitalWrite(led,LOW);
    }
}
