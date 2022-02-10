int e1=3 , i1=4 , i2=2 , s ;
int e2=9 , i3=7 , i4 = 8 ;
  
 int trig= 5;
 int echo= A0;
 long duration; 
 int distance; 

  

void setup()
{

  pinMode(trig, OUTPUT); 
  pinMode(echo, INPUT);
  
  
  pinMode(e1, OUTPUT);  //m1
  pinMode(i1, OUTPUT);  //motor1
  pinMode(i2, OUTPUT);  //m1
  
  pinMode(e2, OUTPUT);  //m2
  pinMode(i3, OUTPUT);  //m2
  pinMode(i4, OUTPUT);  //motor2
  
  pinMode(13 , OUTPUT); //led
  Serial.begin(9600);

}





void loop()
{

  int s;
  s= sense();
  Serial.println(s);
  
  digitalWrite(e1,HIGH);
  digitalWrite(e2,HIGH);
  
  
  if(s==1){
  //if abstracle is decetted
  rotate();
  digitalWrite(13,HIGH);
  }
  
  else{
  //no abstracl dtcected
  moveon();
  digitalWrite(13,LOW);
  }
  
  
}







  
  int moveon(){
  digitalWrite(i1,HIGH);
  digitalWrite(i2,LOW);

  digitalWrite(i3,HIGH);
  digitalWrite(i4,LOW);
  }
  
  
  int rotate(){
  digitalWrite(i1,LOW);
  digitalWrite(i2,HIGH);
  }
  
  
  




  int sense(){
//int d= map(i,0,1023,0,255);
  
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
 
  duration = pulseIn(echo, HIGH);
  distance = duration * 0.034 / 2; 
  Serial.println(distance);
  if(distance<50){
  return(1);
  }
  else{return(0);}
 
}
