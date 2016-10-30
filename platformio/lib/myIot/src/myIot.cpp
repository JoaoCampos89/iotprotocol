#include "MyIot.h"


MyIot::MyIot(){
  _id = 0;

}

MyIot::MyIot(int id): _id(id){

}
//adapted from MySensorsMyProtocol.cpp
bool MyIot::protocolParse(MyMessage &message, char *inputString) {
	char *str, *p, *value=NULL;
	uint8_t bvalue[150];
	uint8_t blen = 0;
	int i = 0;
	uint8_t command = 0;
	uint8_t ack = 0;

	// Extract command data coming on serial line
	for (str = strtok_r(inputString, ";", &p); // split using semicolon
		str && i < 6; // loop while str is not null an max 5 times
		str = strtok_r(NULL, ";", &p) // get subsequent tokens
			) {
		switch (i) {
			case 0: // Radioid (destination)
				message.setDestination(atoi(str));
				break;
			case 1: // Childid
				message.setSensor(atoi(str));
				break;
			case 2: // Message type
				command = atoi(str);
				message.setCommand(command);
				break;
			case 3: // Should we request ack from destination?
				ack = atoi(str);
				break;
			case 4: // Data type
				message.setType(atoi(str));
				break;
			case 5: // Variable value
				if (command == C_STREAM) {
          // command C_STREAM not implemented
					/*blen = 0;
					uint8_t val;
					while (*str) {
						val = protocolH2i(*str++) << 4;
						val += protocolH2i(*str++);
						bvalue[blen] = val;
						blen++;
					}*/
				} else {
          Serial.println(value);
          message.setPayload(str);
					//value = str;
					// Remove trailing carriage return and newline character (if it exists)
				/*	uint8_t lastCharacter = strlen(value)-1;
					if (value[lastCharacter] == '\r')
						value[lastCharacter] = 0;
					if (value[lastCharacter] == '\n')
						value[lastCharacter] = 0;*/
				}
				break;
		}
		i++;
	}
  //debug(PSTR("Received %d"), i);
	// Check for invalid input
	if (i < 5)
		return false;

	//message.sender = GATEWAY_ADDRESS;
	//message.last = GATEWAY_ADDRESS;
  //  mSetRequestAck(message, ack?1:0);
  //  mSetAck(message, false);
/*	if (command == C_STREAM)
		message.set(bvalue, blen);
	else
		message.set(value);*/
	return true;
}

void MyIot::present(MyMessage & message, int sensor, int id){
  message.setDestination(_id);
  message.setSensor(sensor);
  message.setCommand(C_PRESENTATION);
  message.setType(I_PRESENTATION);
  //String msg(id);
  char buffer[100];
  itoa(id,buffer,10);
  message.setPayload(buffer);

}

void MyIot::sendSketchName(MyMessage & message, char * payload){
  message.setDestination(_id);
  message.setSensor(255);
  message.setCommand(C_INTERNAL);
  message.setType(I_SKETCH_NAME);
  message.setPayload(payload);

}

void MyIot::sendSketchVersion(MyMessage & message, char * payload){
    message.setDestination(_id);
    message.setSensor(255);
    message.setCommand(C_INTERNAL);
    message.setType(I_VERSION);
    message.setPayload(payload);
}
/**
 * [MyIot::composeSensorDataMessage sets message with parameters to for message to build]
 * @param message [description]
 * @param buffer  [description]
 */
void MyIot::composeSensorDataMessage(MyMessage & message, char * payload){
    message.setDestination(_id);
    message.setCommand(C_SET);
    message.setPayload(payload);
}

/**
 * [MyIot::buildSensorDataMessage sets message with parameters and build message ]
 * @param  message [MyMessage constructor]
 * @param  payload [description]
 * @return         [char * of message to send via Serial or Socket]
 */
char * MyIot::buildSensorDataMessage(MyMessage & message, char * payload){
    message.setDestination(_id);
    message.setCommand(C_SET);
    message.setPayload(payload);
    return message.buildMessage();
}
