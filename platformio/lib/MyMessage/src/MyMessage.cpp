#include "MyMessage.h"

MyMessage::MyMessage(){

}



MyMessage::MyMessage(int destination, int  sensor, int command, int ack, char * payload ):_destination(destination),_sensor(sensor),_command(command), _ack(ack),_payload(payload){

}


void MyMessage::setType(int type) {
	_type = type;
}

void MyMessage::setSensor(int sensor) {
	_sensor = sensor;
}

void MyMessage::setDestination(int destination) {
	_destination = destination;
}
void MyMessage::setPayload(char * payload) {
	_payload = payload;
}
void MyMessage::setCommand(int command) {
	_command = command;
}
void MyMessage::setAck(int ack) {
	_ack = ack;
}

/**
 *
 *
 * @return [pointer to the build message]
 */
char * MyMessage::buildMessage() {

	sprintf(_buffer,"%d;%d;%d;%d;%d;%s\n", _destination, _sensor, _command , _ack, _type, _payload);
	return _buffer;
}
