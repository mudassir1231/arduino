// C++ code
//

int i,e1=6,i1=1,i2=2,s=3;

void setup()
{
  pinMode(e1, OUTPUT);
  pinMode(i1, OUTPUT);
  pinMode(i2, OUTPUT);
  pinMode(s, INPUT);
  Serial.begin(9600);
}

void loop()
{
  
  i=analogRead(A0);
  int d= map(i,0,1023,0,255);
  int dir = digitalRead(s);
  
  analogWrite(e1,d);
  
  Serial.println(dir);
  if(dir==1){
  digitalWrite(i1, LOW);
  digitalWrite(i2, HIGH);
  }
  else{
  digitalWrite(i1,HIGH);
  digitalWrite(i2,LOW);
  }
  
  
  
}
