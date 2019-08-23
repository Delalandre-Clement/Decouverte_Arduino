int const nombre_Led = 3;
int const position_Depart = 22;
int temps_Allumage;

void setup()
{
    //Pin en mode Sortie courant
    for(int nombre_Tour = nombre_Led-1; nombre_Tour >= 0; nombre_Tour--){
      pinMode(position_Depart-nombre_Tour,OUTPUT);
    }
}
void loop()
{
}
