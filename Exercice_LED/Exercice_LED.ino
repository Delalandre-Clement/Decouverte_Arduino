int pinLedVerte=22; 
int pinLedJaune=23; 
int pinLedRouge=24; 

void setup()
{
    //Pin en mode Sortie courant
    pinMode(pinLedVerte,OUTPUT);
    pinMode(pinLedJaune,OUTPUT); 
    pinMode(pinLedRouge,OUTPUT); 
}
void loop()
{
    //Activation des sorties
    digitalWrite(pinLedVerte,HIGH);
    delay(500);
    digitalWrite(pinLedJaune,HIGH);
    delay(500);
    digitalWrite(pinLedRouge,HIGH);
    delay(500);
    digitalWrite(pinLedVerte,LOW);
    digitalWrite(pinLedJaune,LOW);
    digitalWrite(pinLedRouge,LOW);
    delay(500);
}
