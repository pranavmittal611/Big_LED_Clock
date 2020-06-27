#include <Wire.h>
#include <FastLED.h>

byte decToBcd(byte val)
{
  return( (val/10*16) + (val%10) );
}
// Convert binary coded decimal to normal decimal numbers
byte bcdToDec(byte val)
{
  return( (val/16*10) + (val%16) );
}

#define LED_PIN     6
#define NUM_LEDS    58
#define DS3231_I2C_ADDRESS 0x68
int analog = A0;
int whiteled;
int power =13;
int power2 =12;
int prevtime, newtime;
int light = A1;
int color, bb;
float lightVal, temp;
float val,VAL;
int but = 8;
int redVal;
int grnVal;
int bluVal; 
int Hour, Minute, Second,MiN,HouR;
int input = 3;
int num1, num2, num3, num4;
int seg1, seg2, seg3, seg4, seg5, seg6, seg7, seg8, seg9, seg10, seg11, seg12, seg13, seg14, seg16, seg17, seg18, seg19, seg20, seg21, seg22, seg23, seg24, seg25, seg26, seg27, seg28, seg29;
int dots, state;
CRGB leds[NUM_LEDS];


void displayTime(){
  byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;
  // retrieve data from DS3231
  readDS3231time(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month, &year);
  Hour=hour;
  Minute=minute;
  Second=second;
  // send it to the serial monitor
  Serial.print(hour, DEC);
  // convert the byte variable to a decimal number when displayed
  Serial.print(":");
  if (minute<10)
  {
    Serial.print("0");
  }
  Serial.print(minute, DEC);
  Serial.print(":");
  if (second<10)
  {
    Serial.print("0");
  }
  Serial.print(second, DEC);
  Serial.print(" ");
  Serial.print(dayOfMonth, DEC);
  Serial.print("/");
  Serial.print(month, DEC);
  Serial.print("/");
  Serial.print(year, DEC);
  Serial.print(" Day of week: ");
  switch(dayOfWeek){
  case 1:
    Serial.println("Sunday");
    break;
  case 2:
    Serial.println("Monday");
    break;
  case 3:
    Serial.println("Tuesday");
    break;
  case 4:
    Serial.println("Wednesday");
    break;
  case 5:
    Serial.println("Thursday");
    break;
  case 6:
    Serial.println("Friday");
    break;
  case 7:
    Serial.println("Saturday");
    break;
  }
}




void readDS3231time(
byte *second,
byte *minute,
byte *hour,
byte *dayOfWeek,
byte *dayOfMonth,
byte *month,
byte *year)
{Wire.beginTransmission(DS3231_I2C_ADDRESS);
  Wire.write(0); // set DS3231 register pointer to 00h
  Wire.endTransmission();

  Wire.requestFrom(DS3231_I2C_ADDRESS, 7);
  
// request seven bytes of data from DS3231 starting from register 00h
  *second = bcdToDec(Wire.read() & 0x7f);
  *minute = bcdToDec(Wire.read());
  *hour = bcdToDec(Wire.read() & 0x3f);
  *dayOfWeek = bcdToDec(Wire.read());
  *dayOfMonth = bcdToDec(Wire.read());
  *month = bcdToDec(Wire.read());
  *year = bcdToDec(Wire.read());
}




void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  pinMode(input, INPUT);
  pinMode (power, OUTPUT);
  pinMode (power2,OUTPUT);
  pinMode(but, INPUT);
  Serial.begin(9600);      
  Wire.begin();    
color=0;
digitalWrite(power, HIGH);
digitalWrite(power2, HIGH);

leds[0] = CRGB(210,40,0);
leds[1] = CRGB(210,40,0);
leds[2] = CRGB(210,40,0);
leds[3] = CRGB(210,40,0);
FastLED.show();
delay(200);
leds[10] = CRGB(210,40,0);
leds[11] = CRGB(210,40,0);
leds[8] = CRGB(210,40,0);
leds[9] = CRGB(210,40,0);
leds[4] = CRGB(210,40,0);
leds[5] = CRGB(210,40,0);
FastLED.show();
delay(200);
leds[12] = CRGB(210,40,0);
leds[13] = CRGB(210,40,0);
leds[6] = CRGB(210,40,0);
leds[7] = CRGB(210,40,0);
FastLED.show();
delay(200);
leds[14] = CRGB(210,40,0);
leds[15] = CRGB(210,40,0);
leds[22] = CRGB(210,40,0);
leds[23] = CRGB(210,40,0);
FastLED.show();
delay(200);
leds[16] = CRGB(210,40,0);
leds[17] = CRGB(210,40,0);
leds[20] = CRGB(210,40,0);
leds[21] = CRGB(210,40,0);
leds[24] = CRGB(210,40,0);
leds[25] = CRGB(210,40,0);
FastLED.show();
delay(200);
leds[18] = CRGB(210,40,0);
leds[19] = CRGB(210,40,0);
leds[26] = CRGB(210,40,0);
leds[27] = CRGB(210,40,0);
FastLED.show();
delay(200);
leds[28] = CRGB(210,40,0);
leds[29] = CRGB(210,40,0);
FastLED.show();
delay(200);
leds[38] = CRGB(210,40,0);
leds[39] = CRGB(210,40,0);
leds[30] = CRGB(210,40,0);
leds[31] = CRGB(210,40,0);
FastLED.show();
delay(200);
leds[40] = CRGB(210,40,0);
leds[41] = CRGB(210,40,0);
leds[36] = CRGB(210,40,0);
leds[37] = CRGB(210,40,0);
leds[32] = CRGB(210,40,0);
leds[33] = CRGB(210,40,0);
FastLED.show();
delay(200);
leds[42] = CRGB(210,40,0);
leds[43] = CRGB(210,40,0);
leds[34] = CRGB(210,40,0);
leds[35] = CRGB(210,40,0);
FastLED.show();
delay(200);
leds[44] = CRGB(210,40,0);
leds[45] = CRGB(210,40,0);
leds[52] = CRGB(210,40,0);
leds[53] = CRGB(210,40,0);
FastLED.show();
delay(200);
leds[46] = CRGB(210,40,0);
leds[47] = CRGB(210,40,0);
leds[50] = CRGB(210,40,0);
leds[51] = CRGB(210,40,0);
leds[54] = CRGB(210,40,0);
leds[55] = CRGB(210,40,0);
FastLED.show();
delay(200);
leds[48] = CRGB(210,40,0);
leds[49] = CRGB(210,40,0);
leds[56] = CRGB(210,40,0);
leds[57] = CRGB(210,40,0);
FastLED.show();
delay(200);







}











void loop() {
 
  displayTime();

  dots=digitalRead(input);
  state= digitalRead(but);
  lightVal= analogRead(light);
  lightVal=lightVal * -1;
  lightVal=lightVal + 1000;
  lightVal=lightVal / 500;
  if (lightVal>=1){
    lightVal=1;
  }
   temp=lightVal;


  
  
  
 
  


 if (state == 1){
  VAL = analogRead(analog);  
  
   
 }
 val=VAL;
Wire.requestFrom(DS3231_I2C_ADDRESS, 7);

 

 /*if (lightVal<=0.15){


put the code for really low light here
  }
*/ 

  
if (true){  //use this line if not using dark mode
//if (lightVal>0.15){  //use this line is using dark mode

  val=val/100;
  bb=bb+val;
  if (bb>767 ){
       bb=0;
       }
  
       color=bb;


   
      if (color <= 255 )
        {                  
        

          redVal = 255- color;  // Red from full to off
         grnVal = color;        // Green from off to full
          bluVal = 0 ;           // Blue off
          goto mark;
       }
       else if (color <= 511)
       {
          color = color-256;

          redVal = 0 ;          // Red off
         grnVal = 255- color; // Green from full to off
          bluVal = color;       // Blue from off to full
          goto mark;
        }

  
       else 
       {
       
          color = color-512;

         redVal = color;       // Red from off to full
         grnVal = 0   ;        // Green off
          bluVal = 255- color; // Blue from full to off
          goto mark;
         }

        }

 
  mark:
  


if (temp<0.15){
  temp= 0.15;
}
  redVal=redVal * temp;
  grnVal=grnVal * temp;
  bluVal=bluVal * temp;
MiN=Minute;




if (Minute>=10){
  Minute=Minute-10;
}
if (Minute>=10){
  Minute=Minute-10;
}
if (Minute>=10){
  Minute=Minute-10;
}
if (Minute>=10){
  Minute=Minute-10;
}
if (Minute>=10){
  Minute=Minute-10;
}
if (Minute>=10){
  Minute=Minute-10;
}

MiN=MiN-Minute;
MiN=MiN/10;




if (Hour>12){
  Hour=Hour-12;
}
HouR=Hour;
if (Hour>9){
  Hour=Hour-10;
}

HouR=HouR-Hour;
HouR=HouR/10;

if (HouR<1){
  HouR=99;
}

num1=HouR;
num2=Hour;
num3=MiN;
num4=Minute;



if (num1==99){
  seg1=0;
  seg2=0;
  seg3=0;
  seg4=0;
  seg5=0;
  seg6=0;
  seg7=0;
}
if (num1==0){
  seg1=1;
  seg2=1;
  seg3=1;
  seg4=1;
  seg5=1;
  seg6=1;
  seg7=0;
}
if (num1==1){
  seg1=0;
  seg2=1;
  seg3=1;
  seg4=0;
  seg5=0;
  seg6=0;
  seg7=0;
}
if (num1==2){
  seg1=1;
  seg2=1;
  seg3=0;
  seg4=1;
  seg5=1;
  seg6=0;
  seg7=1;
}
if (num1==3){
  seg1=1;
  seg2=1;
  seg3=1;
  seg4=1;
  seg5=0;
  seg6=0;
  seg7=1;
}
if (num1==4){
  seg1=0;
  seg2=1;
  seg3=1;
  seg4=0;
  seg5=0;
  seg6=1;
  seg7=1;
}
if (num1==5){
  seg1=1;
  seg2=0;
  seg3=1;
  seg4=1;
  seg5=0;
  seg6=1;
  seg7=1;
}
if (num1==6){
  seg1=1;
  seg2=0;
  seg3=1;
  seg4=1;
  seg5=1;
  seg6=1;
  seg7=1;
}
if (num1==7){
  seg1=1;
  seg2=1;
  seg3=1;
  seg4=0;
  seg5=0;
  seg6=0;
  seg7=0;
}
if (num1==8){
  seg1=1;
  seg2=1;
  seg3=1;
  seg4=1;
  seg5=1;
  seg6=1;
  seg7=1;
}
if (num1==9){
  seg1=1;
  seg2=1;
  seg3=1;
  seg4=1;
  seg5=0;
  seg6=1;
  seg7=1;
}
if (num2==99){
  seg8=0;
  seg9=0;
  seg10=0;
  seg11=0;
  seg12=0;
  seg13=0;
  seg14=0;
}
if (num2==0){
  seg8=1;
  seg9=1;
  seg10=1;
  seg11=1;
  seg12=1;
  seg13=1;
  seg14=0;
}
if (num2==1){
  seg8=0;
  seg9=1;
  seg10=1;
  seg11=0;
  seg12=0;
  seg13=0;
  seg14=0;
}
if (num2==2){
  seg8=1;
  seg9=1;
  seg10=0;
  seg11=1;
  seg12=1;
  seg13=0;
  seg14=1;
}
if (num2==3){
  seg8=1;
  seg9=1;
  seg10=1;
  seg11=1;
  seg12=0;
  seg13=0;
  seg14=1;
}
if (num2==4){
  seg8=0;
  seg9=1;
  seg10=1;
  seg11=0;
  seg12=0;
  seg13=1;
  seg14=1;
}
if (num2==5){
  seg8=1;
  seg9=0;
  seg10=1;
  seg11=1;
  seg12=0;
  seg13=1;
  seg14=1;
}
if (num2==6){
  seg8=1;
  seg9=0;
  seg10=1;
  seg11=1;
  seg12=1;
  seg13=1;
  seg14=1;
}
if (num2==7){
  seg8=1;
  seg9=1;
  seg10=1;
  seg11=0;
  seg12=0;
  seg13=0;
  seg14=0;
}
if (num2==8){
  seg8=1;
  seg9=1;
  seg10=1;
  seg11=1;
  seg12=1;
  seg13=1;
  seg14=1;
}
if (num2==9){
  seg8=1;
  seg9=1;
  seg10=1;
  seg11=1;
  seg12=0;
  seg13=1;
  seg14=1;
}
if (num3==99){
  seg16=0;
  seg17=0;
  seg18=0;
  seg19=0;
  seg20=0;
  seg21=0;
  seg22=0;
}
if (num3==0){
  seg16=1;
  seg17=1;
  seg18=1;
  seg19=1;
  seg20=1;
  seg21=1;
  seg22=0;
}
if (num3==1){
  seg16=0;
  seg17=1;
  seg18=1;
  seg19=0;
  seg20=0;
  seg21=0;
  seg22=0;
}
if (num3==2){
  seg16=1;
  seg17=1;
  seg18=0;
  seg19=1;
  seg20=1;
  seg21=0;
  seg22=1;
}
if (num3==3){
  seg16=1;
  seg17=1;
  seg18=1;
  seg19=1;
  seg20=0;
  seg21=0;
  seg22=1;
}
if (num3==4){
  seg16=0;
  seg17=1;
  seg18=1;
  seg19=0;
  seg20=0;
  seg21=1;
  seg22=1;
}
if (num3==5){
  seg16=1;
  seg17=0;
  seg18=1;
  seg19=1;
  seg20=0;
  seg21=1;
  seg22=1;
}
if (num3==6){
  seg16=1;
  seg17=0;
  seg18=1;
  seg19=1;
  seg20=1;
  seg21=1;
  seg22=1;
}
if (num3==7){
  seg16=1;
  seg17=1;
  seg18=1;
  seg19=0;
  seg20=0;
  seg21=0;
  seg22=0;
}
if (num3==8){
  seg16=1;
  seg17=1;
  seg18=1;
  seg19=1;
  seg20=1;
  seg21=1;
  seg22=1;
}
if (num3==9){
  seg16=1;
  seg17=1;
  seg18=1;
  seg19=1;
  seg20=0;
  seg21=1;
  seg22=1;
}
if (num4==99){
  seg23=0;
  seg24=0;
  seg25=0;
  seg26=0;
  seg27=0;
  seg28=0;
  seg29=0;
}
if (num4==0){
  seg23=1;
  seg24=1;
  seg25=1;
  seg26=1;
  seg27=1;
  seg28=1;
  seg29=0;
}
if (num4==1){
  seg23=0;
  seg24=1;
  seg25=1;
  seg26=0;
  seg27=0;
  seg28=0;
  seg29=0;
}
if (num4==2){
  seg23=1;
  seg24=1;
  seg25=0;
  seg26=1;
  seg27=1;
  seg28=0;
  seg29=1;
}
if (num4==3){
  seg23=1;
  seg24=1;
  seg25=1;
  seg26=1;
  seg27=0;
  seg28=0;
  seg29=1;
}
if (num4==4){
  seg23=0;
  seg24=1;
  seg25=1;
  seg26=0;
  seg27=0;
  seg28=1;
  seg29=1;
}
if (num4==5){
  seg23=1;
  seg24=0;
  seg25=1;
  seg26=1;
  seg27=0;
  seg28=1;
  seg29=1;
}
if (num4==6){
  seg23=1;
  seg24=0;
  seg25=1;
  seg26=1;
  seg27=1;
  seg28=1;
  seg29=1;
}
if (num4==7){
  seg23=1;
  seg24=1;
  seg25=1;
  seg26=0;
  seg27=0;
  seg28=0;
  seg29=0;
}
if (num4==8){
  seg23=1;
  seg24=1;
  seg25=1;
  seg26=1;
  seg27=1;
  seg28=1;
  seg29=1;
}
if (num4==9){
  seg23=1;
  seg24=1;
  seg25=1;
  seg26=1;
  seg27=0;
  seg28=1;
  seg29=1;
}





Serial.print("\n");
Serial.print("lightVal:");
   Serial.print(lightVal);
    Serial.print("\n");
Serial.print("red:");
   Serial.print(redVal);
    Serial.print("\n");
Serial.print("green:");
   Serial.print(grnVal);
    Serial.print("\n");
Serial.print("blue:");
   Serial.print(bluVal);
    Serial.print("\n");

if(dots==1){
  if (seg6 == 1){
  leds[0] = CRGB(redVal, grnVal, bluVal);
  leds[1] = CRGB(redVal, grnVal, bluVal);
  }
  else {
  leds[0] = CRGB(0,0,0);
  leds[1] = CRGB(0,0,0);
  }

  if (seg5 == 1){
  leds[2] = CRGB(redVal, grnVal, bluVal);
  leds[3] = CRGB(redVal, grnVal, bluVal);
  }
  else {
  leds[2] = CRGB(0,0,0);
  leds[3] = CRGB(0,0,0);
  }
  
  if (seg4 == 1){
  leds[4] = CRGB(redVal, grnVal, bluVal);
  leds[5] = CRGB(redVal, grnVal, bluVal);
  }
  else {
  leds[4] = CRGB(0,0,0);
  leds[5] = CRGB(0,0,0);
  }
  
 if (seg3 == 1){
  leds[6] = CRGB(redVal, grnVal, bluVal);
  leds[7] = CRGB(redVal, grnVal, bluVal);
  }
  else {
  leds[6] = CRGB(0,0,0);
  leds[7] = CRGB(0,0,0);
  }
  
  if (seg7 == 1){
  leds[8] = CRGB(redVal, grnVal, bluVal);
  leds[9] = CRGB(redVal, grnVal, bluVal);
  }
  else {
  leds[8] = CRGB(0,0,0);
  leds[9] = CRGB(0,0,0);
  }

  if (seg1 == 1){
  leds[10] = CRGB(redVal, grnVal, bluVal);
  leds[11] = CRGB(redVal, grnVal, bluVal);
  }
  else {
  leds[10] = CRGB(0,0,0);
  leds[11] = CRGB(0,0,0);
  }

  
  if (seg2 == 1){
  leds[12] = CRGB(redVal, grnVal, bluVal);
  leds[13] = CRGB(redVal, grnVal, bluVal);
  }
  else {
  leds[12] = CRGB(0,0,0);
  leds[13] = CRGB(0,0,0);
  }
  
  if (seg13 == 1){
  leds[14] = CRGB(redVal, grnVal, bluVal);
  leds[15] = CRGB(redVal, grnVal, bluVal);
  }
  else {
  leds[14] = CRGB(0,0,0);
  leds[15] = CRGB(0,0,0);
  }
  
  if (seg8 == 1){
  leds[16] = CRGB(redVal, grnVal, bluVal);
  leds[17] = CRGB(redVal, grnVal, bluVal);
  }
  else {
  leds[16] = CRGB(0,0,0);
  leds[17] = CRGB(0,0,0);
  }
  
  if (seg9 == 1){
  leds[18] = CRGB(redVal, grnVal, bluVal);
  leds[19] = CRGB(redVal, grnVal, bluVal);
  }
  else {
  leds[18] = CRGB(0,0,0);
  leds[19] = CRGB(0,0,0);
  }
  
  if (seg14 == 1){
  leds[20] = CRGB(redVal, grnVal, bluVal);
  leds[21] = CRGB(redVal, grnVal, bluVal);

  }
  else {
  leds[20] = CRGB(0,0,0);
  leds[21] = CRGB(0,0,0);
  }
  
  if (seg12 == 1){
  leds[22] = CRGB(redVal, grnVal, bluVal);
  leds[23] = CRGB(redVal, grnVal, bluVal);
  }
  else {
  leds[22] = CRGB(0,0,0);
  leds[23] = CRGB(0,0,0);
  }
  
  if (seg11 == 1){
  leds[24] = CRGB(redVal, grnVal, bluVal);
  leds[25] = CRGB(redVal, grnVal, bluVal);
  }
  else {
  leds[24] = CRGB(0,0,0);
  leds[25] = CRGB(0,0,0);
  }
  
  if (seg10 == 1){
  leds[26] = CRGB(redVal, grnVal, bluVal);
  leds[27] = CRGB(redVal, grnVal, bluVal);
  }
  else {
  leds[26] = CRGB(0,0,0);
  leds[27] = CRGB(0,0,0);
  }

  if (true){ 
  leds[28] = CRGB(redVal, grnVal, bluVal);
  leds[29] = CRGB(redVal, grnVal, bluVal);
  }
   else {
  leds[28] = CRGB(0,0,0);
  leds[29] = CRGB(0,0,0);
  }
  
  if (seg20 == 1){
  leds[30] = CRGB(redVal, grnVal, bluVal);
  leds[31] = CRGB(redVal, grnVal, bluVal);
  }
  else {
  leds[30] = CRGB(0,0,0);
  leds[31] = CRGB(0,0,0);
  }
  
  if (seg19 == 1){
  leds[32] = CRGB(redVal, grnVal, bluVal);
  leds[33] = CRGB(redVal, grnVal, bluVal);
  }
  else {
  leds[32] = CRGB(0,0,0);
  leds[33] = CRGB(0,0,0);
  }
  
  if (seg18 == 1){
  leds[34] = CRGB(redVal, grnVal, bluVal);
  leds[35] = CRGB(redVal, grnVal, bluVal);
  }
  else {
  leds[34] = CRGB(0,0,0);
  leds[35] = CRGB(0,0,0);
  }
  
  if (seg22 == 1){
    
  leds[36] = CRGB(redVal, grnVal, bluVal);
  leds[37] = CRGB(redVal, grnVal, bluVal);
  }
  else {
  leds[36] = CRGB(0,0,0);
  leds[37] = CRGB(0,0,0);
  }
  
  if (seg21 == 1){
  leds[38] = CRGB(redVal, grnVal, bluVal);
  leds[39] = CRGB(redVal, grnVal, bluVal);
  }
  else {
  leds[38] = CRGB(0,0,0);
  leds[39] = CRGB(0,0,0);
  }
  
  if (seg16 == 1){
  leds[40] = CRGB(redVal, grnVal, bluVal);
  leds[41] = CRGB(redVal, grnVal, bluVal);
  }
  else {
  leds[40] = CRGB(0,0,0);
  leds[41] = CRGB(0,0,0);
  }
  
  if (seg17 == 1){
  leds[42] = CRGB(redVal, grnVal, bluVal);
  leds[43] = CRGB(redVal, grnVal, bluVal);
  }
  else {
  leds[42] = CRGB(0,0,0);
  leds[43] = CRGB(0,0,0);
  }
  
  if (seg28 == 1){
  leds[44] = CRGB(redVal, grnVal, bluVal);
  leds[45] = CRGB(redVal, grnVal, bluVal);
  }
  else {
  leds[44] = CRGB(0,0,0);
  leds[45] = CRGB(0,0,0);
  }
  
  if (seg23 == 1){
  leds[46] = CRGB(redVal, grnVal, bluVal);
  leds[47] = CRGB(redVal, grnVal, bluVal);
  }
  else {
  leds[46] = CRGB(0,0,0);
  leds[47] = CRGB(0,0,0);
  }
  
  if (seg24 == 1){
  leds[48] = CRGB(redVal, grnVal, bluVal);
  leds[49] = CRGB(redVal, grnVal, bluVal);
  }
  else {
  leds[48] = CRGB(0,0,0);
  leds[49] = CRGB(0,0,0);
  }
  
  if (seg29 == 1){
  leds[50] = CRGB(redVal, grnVal, bluVal);
  leds[51] = CRGB(redVal, grnVal, bluVal);
  }
  else {
  leds[50] = CRGB(0,0,0);
  leds[51] = CRGB(0,0,0);
  }
  
  if (seg27 == 1){
  leds[52] = CRGB(redVal, grnVal, bluVal);
  leds[53] = CRGB(redVal, grnVal, bluVal);
  }
  else {
  leds[52] = CRGB(0,0,0);
  leds[53] = CRGB(0,0,0);
  }
  
  if (seg26 == 1){
  leds[54] = CRGB(redVal, grnVal, bluVal);
  leds[55] = CRGB(redVal, grnVal, bluVal);
  }
  else {
  leds[54] = CRGB(0,0,0);
  leds[55] = CRGB(0,0,0);
  }
  
  if (seg25 == 1){
  leds[56] = CRGB(redVal, grnVal, bluVal);
  leds[57] = CRGB(redVal, grnVal, bluVal);
  }
  else {
  leds[56] = CRGB(0,0,0);
  leds[57] = CRGB(0,0,0);
  }
}
if(dots==0){
leds[0] = CRGB(255,0,0);
leds[1] = CRGB(255,0,0);
leds[2] = CRGB(255,0,0);
leds[3] = CRGB(255,0,0);

leds[10] = CRGB(220,45,0);
leds[11] = CRGB(165,90,0);
leds[8] = CRGB(165,45,0);
leds[9] = CRGB(220,90,0);
leds[4] = CRGB(220,45,0);
leds[5] = CRGB(165,90,0);

leds[12] = CRGB(120,135,0);
leds[13] = CRGB(120,135,0);
leds[6] = CRGB(120,135,0);
leds[7] = CRGB(120,135,0);

leds[14] = CRGB(75, 180,0);
leds[15] = CRGB(75, 180,0);
leds[22] = CRGB(75, 180,0);
leds[23] = CRGB(75, 180,0);

leds[16] = CRGB(30,225,0);
leds[17] = CRGB(0,240,16);
leds[20] = CRGB(0,240,16);
leds[21] = CRGB(30,225,0);
leds[24] = CRGB(30,225,0);
leds[25] = CRGB(0,240,16);

leds[18] = CRGB(0,196,60);
leds[19] = CRGB(0,196,60);
leds[26] = CRGB(0,196,60);
leds[27] = CRGB(0,196,60);

leds[28] = CRGB(0,150,106);
leds[29] = CRGB(0,150,106);

leds[38] = CRGB(0,105,151);
leds[39] = CRGB(0,105,151);
leds[30] = CRGB(0,105,151);
leds[31] = CRGB(0,105,151);

leds[40] = CRGB(0, 60,196);
leds[41] = CRGB(0,15,241);
leds[36] = CRGB(0,15,241);
leds[37] = CRGB(0, 60,196);
leds[32] = CRGB(0, 60,196);
leds[33] = CRGB(0,15,241);

leds[42] = CRGB(30,0,227);
leds[43] = CRGB(30,0,227);
leds[34] = CRGB(30,0,227);
leds[35] = CRGB(30,0,227);

leds[44] = CRGB(75,0,182);
leds[45] = CRGB(75,0,182);
leds[52] = CRGB(75,0,182);
leds[53] = CRGB(75,0,182);

leds[46] = CRGB(127,0,136);
leds[47] = CRGB(166,0,91);
leds[50] = CRGB(166,0,91);
leds[51] = CRGB(127,0,136);
leds[54] = CRGB(127,0,136);
leds[55] = CRGB(166,0,91);

leds[48] = CRGB(211,0,46);
leds[49] = CRGB(211,0,46);
leds[56] = CRGB(211,0,46);
leds[57] = CRGB(211,0,46);



  
}

  FastLED.show();
   

}
