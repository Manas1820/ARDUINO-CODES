

int a;
int n;
int i;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(4,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(12,OUTPUT);
    }

void loop() {
  // put your main code here, to run repeatedly:
  waveLED();
 //  brightness();
if(Serial.available())
   {
     n= Serial.parseInt();
     Serial.print(n);
     if(n>=32 || n<=0){while(n>30){ flickerLED(); n--;} Serial.print("INVALID INPUT");  }
     else
     {
     int n1=n;
  Serial.print("\n");
  convertDecimalToBinary(n);

  Serial.print("\nCOMPLETED\n");
  Serial.print(n1,BIN);
  delay(10000);
  }
  } 
}
void convertDecimalToBinary(int n)
{
  for(i=12 ;i>=4 ;i=i-2)
  {
     a=n%2;   
     n=n/2; 
     
    if(a){ Serial.print("HIGH\t");        digitalWrite(i,HIGH);}
    else { Serial.print("LOW\t");       digitalWrite(i,LOW);}
  }
  
}

//  /*
 void waveLED()
{
 // Serial.print("WAVE START");
  for(i=2;i<=12;i=i+2)
  {
    digitalWrite(i,HIGH);//Serial.print("\n");Serial.print("PIN:");Serial.print(i);Serial.print("IS WORKING !");
    delay(75);
    digitalWrite(i,LOW); 
  }
   for(i=10;i>=2;i=i=i-2)
  {
    digitalWrite(i,HIGH);//Serial.print("\n");Serial.print("PIN:");Serial.print(i);Serial.print("IS WORKING !");
    delay(75);
    digitalWrite(i,LOW); 
  }  
  //Serial.print("\nWAVE END\n");
}
//*/
void flickerLED()
{
 // Serial.print("WAVE START");
  for(i=2;i<=12;i=i+2)
  {
    digitalWrite(i,HIGH);//Serial.print("\n");Serial.print("PIN:");Serial.print(i);Serial.print("IS WORKING !");
    delay(10);
    digitalWrite(i,LOW); 
  }
   for(i=10;i>=2;i=i=i-2)
  {
    digitalWrite(i,HIGH);//Serial.print("\n");Serial.print("PIN:");Serial.print(i);Serial.print("IS WORKING !");
    delay(10);
    digitalWrite(i,LOW); 
  }
}
/*void brightness()
{
  for(int i=0;i<=255;i++)
  {
    analogWrite(10,i);
    analogWrite(6,i);
    delay(1000);
  }
  for(int i=255;i>=0;i--)
  {
    analogWrite(10,i);
    analogWrite(6,i);
    delay(1000);
  }
  
}
*/
