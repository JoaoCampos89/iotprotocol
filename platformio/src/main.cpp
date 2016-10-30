#include "MyIot.h";
// currently
MyIot Automation;
MyIot Sensor(1);
MyMessage message;
//char * msg;

void setup(){
  // present binaray node to system
  Serial.begin(115200);
  Automation.present(message, S_BINARY, 1);
  Serial.print(message.buildMessage());
  char string[] = "1;2;2;1;5;100;100";
  Automation.protocolParse(message,string);
  Serial.print(message.buildMessage());
  Sensor.present(message, S_LIGHT_LEVEL, 2);
  Serial.print(message.buildMessage());
}






void loop(){



}
