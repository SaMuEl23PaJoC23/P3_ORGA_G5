int in1=2;
int in2=4;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}