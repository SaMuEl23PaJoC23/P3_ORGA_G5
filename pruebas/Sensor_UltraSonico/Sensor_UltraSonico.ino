int trig = 10;
int eco = 9;
int led = 3;
int duracion;
int distancia;

void setup(){
	pinMode(trig, OUTPUT);
  	pinMode(eco, INPUT);
  	pinMode(led, OUTPUT);
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
  
  if(distancia >=10 && distancia <=300){
  	digitalWrite(led, HIGH);
    delay(distancia*10);
    digitalWrite(led, LOW);
  }
}