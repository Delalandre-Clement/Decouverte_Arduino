/* Initialisation des varirables globales */
int nbAlea = 0;
int boutonLanceDe = 7;
int positionLed[5] = {2,3,4,5,6};
int delaiAttente = 100;
bool boutonPoussoir = 0;

void setup() {
  /* Initialisation des nombres aléatoires */
  randomSeed(analogRead(0));//initialise la séquence aléatoire
  
  /* Pin en mode entrée PULL-UP */
  pinMode(boutonLanceDe,INPUT_PULLUP);
  
  /*Pin en mode Sortie courant */
  for(int nombreTour = 0; nombreTour <= 6; nombreTour++){
    pinMode(positionLed[nombreTour],OUTPUT);
  }

  /* Mise en place de la communication série */
  Serial.begin(9600);
  Serial.println("Communication initialisée");
}

void loop() {
  boutonPoussoir=digitalRead(boutonLanceDe);
  if(boutonPoussoir == 1 )
  { 
    /* Simulation du lancé du Dé (roulement) */
    LanceDe();

    /* Dernier nombre à afficher -> Résultat */
    nbAlea = random (4);
    AfficheResultat(nbAlea+1);
   }
   delay(100);
}

/* Simule le lancé du dé (génération de plusieurs nombres succésifs */
void LanceDe()
{
  int i = 0;
  int chiffre;
  for(i=0;i<8;i++){
    chiffre = random(4);
    AfficheResultat(chiffre+1);
    delay(200);
    RemiseZero();
    delay(100);
  }
}

/* Mise à Zéro des LEDS's */
void RemiseZero()
{
  digitalWrite(30,LOW);
  digitalWrite(31,LOW);
  digitalWrite(32,LOW);
  digitalWrite(33,LOW);
  digitalWrite(34,LOW);
}

/* Affiche le résultat du nombre aléatoire */
void AfficheResultat(int chiffre)
{
  switch (chiffre){
    case 1:
      digitalWrite(30,LOW);
      digitalWrite(31,LOW);
      digitalWrite(32,HIGH);
      digitalWrite(33,LOW);
      digitalWrite(34,LOW);
      break;
    case 2:
      digitalWrite(30,HIGH);
      digitalWrite(31,LOW);
      digitalWrite(32,LOW);
      digitalWrite(33,HIGH);
      digitalWrite(34,LOW);
      break;
    case 3:
      digitalWrite(30,HIGH);
      digitalWrite(31,LOW);
      digitalWrite(32,HIGH);
      digitalWrite(33,HIGH);
      digitalWrite(34,LOW);
      break;
    case 4:
      digitalWrite(30,HIGH);
      digitalWrite(31,HIGH);
      digitalWrite(32,LOW);
      digitalWrite(33,HIGH);
      digitalWrite(34,HIGH);
      break;
    case 5:
      digitalWrite(30,HIGH);
      digitalWrite(31,HIGH);
      digitalWrite(32,HIGH);
      digitalWrite(33,HIGH);
      digitalWrite(34,HIGH);
      break;
  }
}
