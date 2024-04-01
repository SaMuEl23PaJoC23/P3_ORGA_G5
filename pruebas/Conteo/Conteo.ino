int trig = 10;
int eco = 9;
int led = 3;
int cantVerde = 0;
int duracion;
int distancia;

void setup(){
	pinMode(trig, OUTPUT);
  	pinMode(eco, INPUT);
  	Serial.begin(9600);
}

void loop(){
  digitalWrite(trig, HIGH);
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
    delay(4000);
    digitalWrite(led, LOW);  
  }
}