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
    for(int nb_Cycle=0; nb_Cycle<5; nb_Cycle--){
        int temps_Allumage = 1000 - (nb_Cycle * 0,2);
        int nombre_Tour;
        for(nombre_Tour = nombre_Led-1; nombre_Tour >= 0; nombre_Tour--){
          digitalWrite(position_Depart-nombre_Tour,HIGH);
        }
    }
}
