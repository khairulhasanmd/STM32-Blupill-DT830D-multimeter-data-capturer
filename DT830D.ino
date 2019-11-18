int i, d1=0, d2=0, d3=0, d4=0, dot1=0, dot2=0;
float num=0;
int segment_decimal_equivalent[10] = {95,  6, 109, 47,  54,  59,  123, 14,  127, 63};//0123456789 according to excel sheet
void setup()                   
{
  Serial.begin(115200); // blobpin  usage        
  pinMode(PB11, INPUT);     //  1   d1
  pinMode(PB10, INPUT);     //  2   c1
  pinMode(PB1, INPUT);      //  3   b1
  pinMode(PB0, INPUT);      //  4   a1
  pinMode(PA7, INPUT);      //  5   f1
  pinMode(PA6, INPUT);      //  6   e1
  pinMode(PA5, INPUT);      //  7   g1

  pinMode(PA4, INPUT);      //  8   d2
  pinMode(PA3, INPUT);      //  9   c2
  pinMode(PA2, INPUT);      //  10  b2
  pinMode(PA1, INPUT);      //  11  a2
  pinMode(PA0, INPUT);      //  12  f2
  pinMode(PC15, INPUT);     //  13  g2

  pinMode(PC14, INPUT);     //  14  d3
  pinMode(PB12, INPUT);     //  15  b3
  pinMode(PB13, INPUT);     //  16  f3
  pinMode(PB14, INPUT);     //  17  g3

  pinMode(PB15, INPUT);     //  18  a4+b4  last 1

  pinMode(PA8, INPUT);      //  19  -
  pinMode(PA15, INPUT);     //  20  COM

  pinMode(PB3, INPUT);      //  21  e3
  pinMode(PB4, INPUT);      //  22  a3
  pinMode(PB5, INPUT);      //  23  c3
  pinMode(PB6, INPUT);      //  24  e2

  pinMode(PB7, INPUT);      //  25  battery low
  pinMode(PB8, INPUT);      //  26  HV

  pinMode(PB9, INPUT);      //  27  10.00
  pinMode(PC13, INPUT);     //  28 maybe 100.0


  int i = 0;
  attachInterrupt(PA15, isr, FALLING);
}

void loop()          {  
  //Serial.print(num);
  //Serial.println(num);
  delay(50);
}

void isr() {
  delay(1);
   d1 = segment_to_number(digitalRead(PB11) | 
     (digitalRead(PB10) << 1) |
     (digitalRead(PB1) << 2) |
     (digitalRead(PB0) << 3) |
     (digitalRead(PA7) << 4) |
     (digitalRead(PA6) << 5) |
     (digitalRead(PA5) << 6));
   d2 = segment_to_number(digitalRead(PA4) | 
     (digitalRead(PA3) << 1) |
     (digitalRead(PA2) << 2) |
     (digitalRead(PA1) << 3) |
     (digitalRead(PA0) << 4) |
     (digitalRead(PB6) << 5) |
     (digitalRead(PC15) << 6));
  d3 = segment_to_number(digitalRead(PC14) | 
    (digitalRead(PB5) << 1) |
    (digitalRead(PB12) << 2) |
    (digitalRead(PB4) << 3) |
    (digitalRead(PB13) << 4) |
    (digitalRead(PB3) << 5) |
    (digitalRead(PB14) << 6));
  d4 = digitalRead(PB15);
  dot1 = digitalRead(PB9);
  dot2 = digitalRead(PC13);
  num = d4*1000+d3*100+d2*10+d1;
  if(dot1){
    num = num/10;
  } else if(dot2){
    num = num/100;
  }
  Serial.println(num);
  // Serial.print(digitalRead(PC14));
  // Serial.print(digitalRead(PB5));
  // Serial.print(digitalRead(PB12));
  // Serial.print(digitalRead(PB4));
  // Serial.print(digitalRead(PB13));
  // Serial.print(digitalRead(PB14));
  // Serial.println(digitalRead(PB3));
}

int segment_to_number(int number)
{
  for (i = 0; i < 10; i++)
  {
    if(number == segment_decimal_equivalent[i]){
      return i;
    }
  }
  return 0;
}
