#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

String prev = "";
String x = "";
bool newLine = false;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  SerialBT.begin("ESP32test");
  Serial.println("Ready to Pair");//fixed the capital E
}

void loop() {
  if(SerialBT.available()){
    
    x = String(SerialBT.read()-48);
//    Serial.print(x);
//    Serial.println("HAAAA");
//    Serial.write(x);
    if(x.toInt() == -35){
      Serial.print("n0.val=" + prev);
      Serial.write(0xff);
      Serial.write(0xff);
      Serial.write(0xff);
      Serial.print("z0.val=" + prev);
      Serial.write(0xff);
      Serial.write(0xff);
      Serial.write(0xff);
      x = "";
      prev = "";
      newLine = true;
    }else if(newLine){
      newLine = false;
    }else{
      prev += x;
    }
  }
  
  if(Serial.available()){
    SerialBT.write(Serial.read());
  }
  delay(200);
}
