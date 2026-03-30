int x,y = 0;
int readX() // returns x axis value
{
  int xr=0;
  pinMode(A0, INPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, INPUT);
  pinMode(A3, OUTPUT);
  digitalWrite(A1, LOW);
  digitalWrite(A3, HIGH);
  delay(5);
  xr=analogRead(0);       // x-axis value
  return xr;
}

int readY() // returns y axis value
{
  int yr=0;
  pinMode(A0, OUTPUT);
  pinMode(A1, INPUT); 
  pinMode(A2, OUTPUT);
  pinMode(A3, INPUT); 
  digitalWrite(14, LOW);
  digitalWrite(16, HIGH);
  delay(5);
  yr=analogRead(1);       // y axis value
  return yr; 
}
void setup()
{
  pinMode(2, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  Serial.print(" x = ");
  x=readX();
  Serial.print(x);
  y=readY();
  Serial.print(" y = ");
  Serial.println(y);
  for(int x=0; x<=255; x++);
  {
    analogWrite (3, (x-100)/4);
    delay(10);
  }
  delay (200);
}