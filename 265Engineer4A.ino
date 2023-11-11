#include <IRremote.h>
int Lights =6;
IRrecv IR (4);
void setup(){
  Serial.begin(9600);
  IR.enableIRIn();
  
  pinMode(Lights , OUTPUT);
}

void loop(){

  if (IR.decode()){
    if(IR.decodedIRData.decodedRawData == 0xFF089F20)
    {
       do
       {
            digitalWrite(Lights , HIGH);
       }while (IR.decodedIRData.decodedRawData ==0xF4079F20);
    }


    
    else if (IR.decodedIRData.decodedRawData ==0xF4079F20)
    {
      do 
      {
            digitalWrite(Lights , LOW);
      }while (IR.decodedIRData.decodedRawData ==0xFF089F20);
    }
    
   IR.resume();


  }
  }
