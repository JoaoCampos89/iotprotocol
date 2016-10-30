#ifndef MyMessage_h
#define MyMessageh
#include <Arduino.h>
#include "protocol.h"

class MyMessage
{
private:

  int _destination;
  int _sensor;
  int _ack;
  int _type;
  int _command;
  int _last; // 8 bit - Id of last node this message passed
  int _sender;   // 8 bit - Id of sender node (origin)
  char _buffer[100];
  char * _payload;

public:
	// Constructor
	 MyMessage();
	 MyMessage(int, int, int, int, char *);
   void setDestination(int);
   void setSensor(int);
   void setAck(int);
   void setType(int);
   void setCommand(int);
   void setPayload(char *);
   char * buildMessage();
   bool send();
   bool sendSerial();



};




#endif
