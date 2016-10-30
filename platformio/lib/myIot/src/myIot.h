#ifndef MyIot_h
#define MyIot_h
#include <stdlib.h>
#include <Arduino.h>
#include "MyMessage.h";

class MyIot
{
private:
	char* getCustomString(char *buffer) const;
	int _id;
	char * _buffer;
public:
	// Constructors
	 MyIot();
	 MyIot(int id);
	 void present(MyMessage &, int, int);
 	// char * sendSketchInfo(char *, char *);
	 void sendSketchName(MyMessage &, char *);
	 void sendSketchVersion(MyMessage &, char *);
	 bool protocolParse(MyMessage &, char *);
	 char * buildSensorDataMessage(MyMessage &, char *);
	 void composeSensorDataMessage(MyMessage &, char *);
};




#endif
