String articulo;
int conteo=0;
int i;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("Escribe articulo: ");
  while(Serial.available()){}

  articulo = Serial.readString();
  
  if(articulo=="rojo\n"){
    Serial.println("ROJO");
  }
  else if(articulo=="verde\n"){
    Serial.println("Verde");
  }

}
