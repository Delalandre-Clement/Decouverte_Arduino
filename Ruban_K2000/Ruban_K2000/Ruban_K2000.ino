/* Initialisation des varirables globales */
int positionLed[7]={22,23,24,25,26,27,28};
int delaiAttente=100;

void setup() {
  /*Pin en mode Sortie courant */
  for(int nombreTour = 0; nombreTour <= 6; nombreTour++){
    pinMode(positionLed[nombreTour],OUTPUT);
  }
}

void loop() {
  /* Boucle d'allumage des LED dans le sens positif */
  for(int nombreTour = 0; nombreTour <= 6; nombreTour++){
    /* Allumage de la LED actuelle en fonction du nombre de tour dans la boucle */
    digitalWrite(positionLed[nombreTour],HIGH); 
    delay(delaiAttente);
    /*Extinction de la LED-1 sauf si on est à la première LED */
    if(nombreTour != 0){
      digitalWrite(positionLed[nombreTour-1],LOW);
    }
    /*Extinction de la LED actuelle */
    digitalWrite(positionLed[nombreTour],LOW);
  }

  /* Boucle d'allumage des LED dans le sens négatif */
  for(int nombreTour = 6; nombreTour > 0; nombreTour--){
    /* Allumage de la LED actuelle en fonction du nombre de tour dans la boucle */
    digitalWrite(positionLed[nombreTour],HIGH); 
    /*Extinction de la LED+1 sauf si on est à la dernière LED */
    if(nombreTour != 6){
      delay(delaiAttente);
      digitalWrite(positionLed[nombreTour+1],LOW);
    }
    /*Extinction de la LED actuelle */
    digitalWrite(positionLed[nombreTour],LOW);
  }
}
