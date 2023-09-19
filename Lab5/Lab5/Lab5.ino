//Luis Pedro  Gonzalez 21513

//Lab 5


//leds para los jugadores 

#define LED1_J1 2
#define LED2_J1 3
#define LED3_J1 4
#define LED4_J1 5
#define LED5_J1 6
#define LED6_J1 7
#define LED7_J1 8
#define LED8_J1 9
#define LEDW_J1 38
#define win1 15 

#define LED1_J2 23
#define LED2_J2 24
#define LED3_J2 25
#define LED4_J2 26
#define LED5_J2 27
#define LED6_J2 28
#define LED7_J2 29
#define LED8_J2 10
#define LEDW_J2 37
#define win2 35

//variables 
int start_sem = 0; //variable para inciar el semaforo
int start_race = 0; //variable para el incio del juego 

int PLAY1 = PE_0 ; //pin para el boton del jugador 1
int PLAY2 = PB_3 ; //[in para el boton del jugador 2

int cont1 = 0; // contadores para los jugadores
int cont2 = 0;

//--------------SETUP GENERAL -----------------

void setup(){

  //establecer entradas y salidas

  //semaforo
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  

  //establecer los pullups
  pinMode(PUSH1, INPUT_PULLUP); // estableces el sw1 de tiva con entrada
    
  pinMode(PLAY1, INPUT_PULLUP);//botones de jugadores
  pinMode(PLAY2, INPUT_PULLUP);

  pinMode(LED1_J1, OUTPUT); //leds para los jugadores 
  pinMode(LED2_J1, OUTPUT);
  pinMode(LED3_J1, OUTPUT);
  pinMode(LED4_J1, OUTPUT);
  pinMode(LED5_J1, OUTPUT);
  pinMode(LED6_J1, OUTPUT);
  pinMode(LED7_J1, OUTPUT);
  pinMode(LED8_J1, OUTPUT);
  pinMode(win1, OUTPUT);


  pinMode(LED1_J2, OUTPUT);
  pinMode(LED2_J2, OUTPUT);
  pinMode(LED3_J2, OUTPUT);
  pinMode(LED4_J2, OUTPUT);
  pinMode(LED5_J2, OUTPUT);
  pinMode(LED6_J2, OUTPUT);
  pinMode(LED7_J2, OUTPUT);
  pinMode(LED8_J2, OUTPUT);
  pinMode(win2, OUTPUT);

  //asignar las interrupciones para cada boton
  attachInterrupt(digitalPinToInterrupt(PUSH1), button1, LOW); //asignar interrupción a botón de start del semafor 

  attachInterrupt(digitalPinToInterrupt(PLAY1), race1, LOW); //asignar interrupción a botón de P1 
  attachInterrupt(digitalPinToInterrupt(PLAY2), race2, LOW); //asignar interrupción a botón de P2 


 
}


//-------------Loop principal----------------------
void loop(){


//inicicion de secuancia de semaforo
  if (start_sem == 1){
    start_sem = 0;// reicicia el contador del semaforo
    semaforo(); //iniciar la secuancia del semaforo
  }

  if (start_race == 1){
    leds1();// rutina de contadores bonario s
    leds2();
    
  }

  
  }

//---------RUTINA PARA EL BOTON DE INCIO DE SEMAFORO---------
void button1(){
  start_sem = 1;
}

//----------------reinicio de todo el juego------------
// si se presiona el botn del semaforo otra vez, el juego se reinciara

void reinicio(){

  //reiniciar los contadores 
  cont1 = 0;
  cont2 = 0;

    //apagar todos los leds
  digitalWrite(LED1_J1, LOW);
  digitalWrite(LED2_J1, LOW);
  digitalWrite(LED3_J1, LOW);
  digitalWrite(LED4_J1, LOW);
  digitalWrite(LED5_J1, LOW);
  digitalWrite(LED6_J1, LOW);
  digitalWrite(LED7_J1, LOW);
  digitalWrite(LED8_J1, LOW);
  digitalWrite(win1, LOW);

  digitalWrite(LED1_J2, LOW);
  digitalWrite(LED2_J2, LOW);
  digitalWrite(LED3_J2, LOW);
  digitalWrite(LED4_J2, LOW);
  digitalWrite(LED5_J2, LOW);
  digitalWrite(LED6_J2, LOW);
  digitalWrite(LED7_J2, LOW);
  digitalWrite(LED8_J2, LOW);
  digitalWrite(win2, LOW);

  //reiciar el semaforo
  digitalWrite (RED_LED, LOW);
  digitalWrite (BLUE_LED, LOW);
  digitalWrite (GREEN_LED, LOW);
  delay(1000);

  
}


//-----Rutina para el semaforo----------------------------

void semaforo(){

  reinicio(); //todo se deberia de reiniciar 
  //ENCENDER PRIMERO SOLO LA LED ROJA
  digitalWrite (RED_LED, HIGH);
  digitalWrite (BLUE_LED, LOW);
  digitalWrite (GREEN_LED, LOW);

  delay(1000); // esperar un segundo

  //ENCENDER LED AZUL
  digitalWrite (RED_LED, LOW);
  digitalWrite (BLUE_LED, HIGH);
  digitalWrite (GREEN_LED, LOW);

  delay(1000); // esperar un segundo


  //ENCENDER  SOLO LA LED VERDE
  digitalWrite (RED_LED, LOW);
  digitalWrite (BLUE_LED, LOW);
  digitalWrite (GREEN_LED, HIGH);
  delay(1000); // esperar un segundo


  start_race = 1;//empezar la carrera
}



//--------------------interrupciones para los contadores de carrera-----------------
void race1(){
  if (start_race == 1){// revisar si ya se puede iniciar el juego 
  cont1 = cont1 + 1; //incremtar el contador en 1
  delay(500);

  }
}

void race2(){
  if (start_race == 1){ // revisar si ya se puede iniciar el juego 
  cont2 = cont2 + 1; //incremtar el contador en 1
  delay(500);

  }
}

//--------------Rutinas para el contador de bianrio de los jugares----------
void leds1(){// primera rutina 
  switch(cont1){
    case 1:
      digitalWrite(LED1_J1, HIGH);
      digitalWrite(LED2_J1, LOW);
      digitalWrite(LED3_J1, LOW);
      digitalWrite(LED4_J1, LOW);
      digitalWrite(LED5_J1, LOW);
      digitalWrite(LED6_J1, LOW);
      digitalWrite(LED7_J1, LOW);
      digitalWrite(LED8_J1, LOW);
      digitalWrite(win1, LOW);
      break;

    case 2:
      digitalWrite(LED1_J1, LOW);
      digitalWrite(LED2_J1, HIGH);
      digitalWrite(LED3_J1, LOW);
      digitalWrite(LED4_J1, LOW);
      digitalWrite(LED5_J1, LOW);
      digitalWrite(LED6_J1, LOW);
      digitalWrite(LED7_J1, LOW);
      digitalWrite(LED8_J1, LOW);
      digitalWrite(win1, LOW);
      break;

    case 3:
      digitalWrite(LED1_J1, LOW);
      digitalWrite(LED2_J1, LOW);
      digitalWrite(LED3_J1, HIGH);
      digitalWrite(LED4_J1, LOW);
      digitalWrite(LED5_J1, LOW);
      digitalWrite(LED6_J1, LOW);
      digitalWrite(LED7_J1, LOW);
      digitalWrite(LED8_J1, LOW);
      digitalWrite(win1, LOW);
      break;

    case 4:
      digitalWrite(LED1_J1, LOW);
      digitalWrite(LED2_J1, LOW);
      digitalWrite(LED3_J1, LOW);
      digitalWrite(LED4_J1, HIGH);
      digitalWrite(LED5_J1, LOW);
      digitalWrite(LED6_J1, LOW);
      digitalWrite(LED7_J1, LOW);
      digitalWrite(LED8_J1, LOW);
      digitalWrite(win1, LOW);
      break;

    case 5:
      digitalWrite(LED1_J1, LOW);
      digitalWrite(LED2_J1, LOW);
      digitalWrite(LED3_J1, LOW);
      digitalWrite(LED4_J1, LOW);
      digitalWrite(LED5_J1, HIGH);
      digitalWrite(LED6_J1, LOW);
      digitalWrite(LED7_J1, LOW);
      digitalWrite(LED8_J1, LOW);
      digitalWrite(win1, LOW);
      break;

    case 6:
      digitalWrite(LED1_J1, LOW);
      digitalWrite(LED2_J1, LOW);
      digitalWrite(LED3_J1, LOW);
      digitalWrite(LED4_J1, LOW);
      digitalWrite(LED5_J1, LOW);
      digitalWrite(LED6_J1, HIGH);
      digitalWrite(LED7_J1, LOW);
      digitalWrite(LED8_J1, LOW);
      digitalWrite(win1, LOW);
      break;


    case 7:
      digitalWrite(LED1_J1, LOW);
      digitalWrite(LED2_J1, LOW);
      digitalWrite(LED3_J1, LOW);
      digitalWrite(LED4_J1, LOW);
      digitalWrite(LED5_J1, LOW);
      digitalWrite(LED6_J1, LOW);
      digitalWrite(LED7_J1, HIGH);
      digitalWrite(LED8_J1, LOW);
      digitalWrite(win1, LOW);
      break;

    case 8:
      digitalWrite(LED1_J1, LOW);
      digitalWrite(LED2_J1, LOW);
      digitalWrite(LED3_J1, LOW);
      digitalWrite(LED4_J1, LOW);
      digitalWrite(LED5_J1, LOW);
      digitalWrite(LED6_J1, LOW);
      digitalWrite(LED7_J1, LOW);
      digitalWrite(LED8_J1, HIGH);
      digitalWrite(win1, LOW);
      break;

    case 9:
      digitalWrite(LED1_J1, LOW);
      digitalWrite(LED2_J1, LOW);
      digitalWrite(LED3_J1, LOW);
      digitalWrite(LED4_J1, LOW);
      digitalWrite(LED5_J1, LOW);
      digitalWrite(LED6_J1, LOW);
      digitalWrite(LED7_J1, LOW);
      digitalWrite(LED8_J1, LOW);
      digitalWrite(win1, HIGH);
      start_race = 0; //se reiciaia contador de arrera y se termina el juego

      break;
    
  }
}


void leds2(){//segunda rutina 
  switch(cont2){
    case 1:
      digitalWrite(LED1_J2, HIGH);
      digitalWrite(LED2_J2, LOW);
      digitalWrite(LED3_J2, LOW);
      digitalWrite(LED4_J2, LOW);
      digitalWrite(LED5_J2, LOW);
      digitalWrite(LED6_J2, LOW);
      digitalWrite(LED7_J2, LOW);
      digitalWrite(LED8_J2, LOW);
      digitalWrite(win2, LOW);
      break;

    case 2:
      digitalWrite(LED1_J2, LOW);
      digitalWrite(LED2_J2, HIGH);
      digitalWrite(LED3_J2, LOW);
      digitalWrite(LED4_J2, LOW);
      digitalWrite(LED5_J2, LOW);
      digitalWrite(LED6_J2, LOW);
      digitalWrite(LED7_J2, LOW);
      digitalWrite(LED8_J2, LOW);
      digitalWrite(win2, LOW);
      break;

    case 3:
      digitalWrite(LED1_J2, LOW);
      digitalWrite(LED2_J2, LOW);
      digitalWrite(LED3_J2, HIGH);
      digitalWrite(LED4_J2, LOW);
      digitalWrite(LED5_J2, LOW);
      digitalWrite(LED6_J2, LOW);
      digitalWrite(LED7_J2, LOW);
      digitalWrite(LED8_J2, LOW);
      digitalWrite(win2, LOW);
      break;

    case 4:
      digitalWrite(LED1_J2, LOW);
      digitalWrite(LED2_J2, LOW);
      digitalWrite(LED3_J2, LOW);
      digitalWrite(LED4_J2, HIGH);
      digitalWrite(LED5_J2, LOW);
      digitalWrite(LED6_J2, LOW);
      digitalWrite(LED7_J2, LOW);
      digitalWrite(LED8_J2, LOW);
      digitalWrite(win2, LOW);
      break;

    case 5:
      digitalWrite(LED1_J2, LOW);
      digitalWrite(LED2_J2, LOW);
      digitalWrite(LED3_J2, LOW);
      digitalWrite(LED4_J2, LOW);
      digitalWrite(LED5_J2, HIGH);
      digitalWrite(LED6_J2, LOW);
      digitalWrite(LED7_J2, LOW);
      digitalWrite(LED8_J2, LOW);
      digitalWrite(win2, LOW);
      break;

    case 6:
      digitalWrite(LED1_J2, LOW);
      digitalWrite(LED2_J2, LOW);
      digitalWrite(LED3_J2, LOW);
      digitalWrite(LED4_J2, LOW);
      digitalWrite(LED5_J2, LOW);
      digitalWrite(LED6_J2, HIGH);
      digitalWrite(LED7_J2, LOW);
      digitalWrite(LED8_J2, LOW);
      digitalWrite(win2, LOW);
      break;


    case 7:
      digitalWrite(LED1_J2, LOW);
      digitalWrite(LED2_J2, LOW);
      digitalWrite(LED3_J2, LOW);
      digitalWrite(LED4_J2, LOW);
      digitalWrite(LED5_J2, LOW);
      digitalWrite(LED6_J2, LOW);
      digitalWrite(LED7_J2, HIGH);
      digitalWrite(LED8_J2, LOW);
      digitalWrite(win2, LOW);
      break;

    case 8:
      digitalWrite(LED1_J2, LOW);
      digitalWrite(LED2_J2, LOW);
      digitalWrite(LED3_J2, LOW);
      digitalWrite(LED4_J2, LOW);
      digitalWrite(LED5_J2, LOW);
      digitalWrite(LED6_J2, LOW);
      digitalWrite(LED7_J2, LOW);
      digitalWrite(LED8_J2, HIGH);
      digitalWrite(win2, LOW);
      break;

    case 9:
      digitalWrite(LED1_J2, LOW);
      digitalWrite(LED2_J2, LOW);
      digitalWrite(LED3_J2, LOW);
      digitalWrite(LED4_J2, LOW);
      digitalWrite(LED5_J2, LOW);
      digitalWrite(LED6_J2, LOW);
      digitalWrite(LED7_J2, LOW);
      digitalWrite(LED8_J2, LOW);
      digitalWrite(win2, HIGH);
      start_race = 0; //se reiciaia contador de arrera y se termina el juego

      break;
    
  }
}
