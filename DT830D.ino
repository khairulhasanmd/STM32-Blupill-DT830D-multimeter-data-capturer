int num=0;
void setup()                                                      
{
  Serial.begin(115200);             
  pinMode(PA15, INPUT);                       
  pinMode(PB11, INPUT);                       
  pinMode(PB10, INPUT);                       
  pinMode(PB1, INPUT);                       
  pinMode(PB0, INPUT);                       
  pinMode(PA7, INPUT);                       
  pinMode(PA5, INPUT);                       
  pinMode(PA4, INPUT);                       
  pinMode(PA3, INPUT);                       
  pinMode(PA2, INPUT);                       
  pinMode(PA1, INPUT);                       
  pinMode(PC15, INPUT);                       
  pinMode(PC13, INPUT);                       
  pinMode(PB12, INPUT);                       
  pinMode(PB13, INPUT);                       
  pinMode(PB14, INPUT);                       
  pinMode(PB15, INPUT);                       
  pinMode(PA8, INPUT);                       
  pinMode(PA15, INPUT);                       
  pinMode(PB3, INPUT);                       
  pinMode(PB4, INPUT);                       
  pinMode(PB5, INPUT);                       
  pinMode(PB6, INPUT);                       
  pinMode(PB7, INPUT);                       
  pinMode(PB8, INPUT);                       
  pinMode(PB9, INPUT);                       
  int i = 0;                                  
  attachInterrupt(PA15, isr, FALLING);
}

void loop()                                 
{  
  //Serial.print(num);
  //Serial.println(num);
  delay(50);
}

void isr()                        
{
  delay(1);
  Serial.print(digitalRead(PA15));
  Serial.print(digitalRead(PB11));
  Serial.print(digitalRead(PB10));
  Serial.print(digitalRead(PB1));
  Serial.print(digitalRead(PB0));
  Serial.print(digitalRead(PA7));
  Serial.println(digitalRead(PA5));
}
