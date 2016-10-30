#ifndef MyMessage_h
#define MyMessageh
//#include <Arduino.h>


class MyMessage
{
private:

  int _destination;
  int _sensor;
  int _ack;
  int _type;
  String payload;

public:
	// Constructor
	 MyMessage(int, int, int, int, String);
   void setDestination(int);
   void setSensor(int);
   void setAck(int);
   void setType(int);
   void setPayload(String);
   bool send();
   bool sendSerial();



};




#endif
