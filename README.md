# Initial spec of iot protocol

This protocol is intended to be used with a esp12E as intermedeary and with arduinos
as attached sensors, by spi or serial depending of the author, with this is really possible to create multiple gateways with different id
enabling the true iot devices, which is beatiful.


State of Art
Based on MySensors Protocol with modifications to attend


spec

Its equivalent to the MySensors spec




the first field must be the destination
the third field is the sensor type
the second field the type of operation - PRESENTATION, SET, REQ, INTERNAL,
the four field is the sensor field


The next fields will depend of the type of operation
