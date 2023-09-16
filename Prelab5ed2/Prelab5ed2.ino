//Luis Pedro  Gonzalez 21513

//Prelab 5


//variables 
int start_sem = 0; //variable para inciar el semaforo


//--------------SETUP GENERAL -----------------

void setup(){

  //establecer entradas y salidas
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  //establecer los pullups
  pinMode(PUSH1, INPUT_PULLUP); // estableces el sw1 de tiva con entrada

  //asignar las interrupciones para cada boton
  attachInterrupt(digitalPinToInterrupt(PUSH1), button1, LOW); //asignar interrupción a botón de start del semafor 

 
}


//-------------Loop principal----------------------
void loop(){


//inicicion de secuancia de semaforo
  if (start_sem == 1){
    semaforo(); //iniciar la secuancia del semaforo
  }

  
  }

//---------RUTINA PARA EL BOTON DE INCIO DE SEMAFORO---------
void button1(){
  start_sem = 1;
}

//-----Rutina para el semaforo----------------------------

void semaforo(){

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


  start_sem = 0;// finalizar el conteo de semaforo


}
