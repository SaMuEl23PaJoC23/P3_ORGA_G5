int password;
int contError = 1;
int i, Crojo = 0;
String articulo, color; 

//Variables Sensor Ultrasonico - VERDE
int trig = 10;
int eco = 9;
int led = 3;
int cantVerde = 0;
int duracion;
int distancia;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(eco, INPUT);
  Serial.begin(9600);
}

void loop() {

  Serial.println("Ingrese contrasena: ");
  while(Serial.available() == 0){} 
  password=Serial.parseInt(); 
  
  if(password==123 || password == 9){ //9, representa el boton de emergencia
      contError=1; //Se desactiva ALARMA
      
    Serial.println("CORRECTO"); //Pausa de 5s para iniciar
    for(i=5; i>0; i--){
      Serial.println(i);
      delay(500); 
    }

    Serial.println("ACTIVO: Banda 1");  //Se encienden SENSORES y se reinician CONTADORES
    delay(1000);                        //Los motores iran controlados desde otro ARDUINO
    Serial.println("ACTIVO: Sensor Color");
    delay(1000);
    Serial.println("ACTIVO: Semaforo");
    delay(1000);
    Serial.println("ACTIVO: Banda 2");
    delay(1000);
    Serial.println("ACTIVO: Sensor Ultrasonico 1 y 2");
    delay(1000);
    Serial.println("ACTIVO: Contadores");
    delay(1000);

    while(true){
      Serial.println("SEMAFORO-VERDE");
      for(i=20; i>0; i--){  //20s de funcionamiento
        Serial.print("Tiempo: ");
        Serial.println(i);


        //Acá va codigo del sensor COLOR
        //Indica si banda 1 va hacia --> (delante) o hacia <- (atras)
        //indica si banda 2 va hacia --> (Derecha, rojo) o hacia <- (izquierda, verde)


        if(color=="verde"){
          delay(3000);  //Tiempo de espera para que se acerque el objeto
          while(true){
            digitalWrite(trig, HIGH); //Dispara onda
            delay(1);
            digitalWrite(trig, LOW);
            duracion = pulseIn(eco, HIGH);
            distancia = duracion/58.2;
            Serial.println(distancia);
            delay(200);

            if(distancia >=3 && distancia <=10){
              cantVerde++;
              if (cantVerde > 15){cantVerde=1;}
              digitalWrite(led, HIGH);
              Serial.print("Cant Detectados: ");
              Serial.println(cantVerde);
              delay(3000);
              digitalWrite(led, LOW);  
              break;
            }
          }
        }   //Se realiza lo mismo, pero ahora para el color rojo

        
        else if(articulo=="azul"){
          Serial.println("Cambio giro BANDA 1 <--");
          delay(5000);
          Serial.println("Cambio giro BANDA 1 -->");
        }


        delay(20000); //Sinta 1 gira por 20s
      }

      Serial.println("SEMAFORO-ROJO");  //Sinta 1 y 2 DETENIDAS por 10s
      for(i=10; i>0; i--){
        Serial.print("Tiempo: ");
        Serial.println(i);
        delay(500); 
      }
    }
  }

  else{
    Serial.println("Incorrecto");
    Serial.print("Numero de error: ");
    Serial.println(contError);
    contError+=1;

    if(contError==5){
      Serial.println("ALARMA ACTIVA");  //Se enciende ALARMA
      delay(5000);
      contError=1;
    }
    else{
      for(i=10; i>0;i--){   //Se desactiva TECLADO por 10s
        Serial.println(i);
        delay(500);
      }
    }
  }


  while(Serial.available()) { //Se utiliza para limpiar la entrada del serial ya que despues de presionar ENTER
    Serial.read();            //Aun detecta que hay un caracter de salto de linea y no funcionaria correctamente
  }
  delay(500);
}