#ifndef APIS_INC_DHT11_H_
#define APIS_INC_DHT11_H_

#include "../../_Drivers_/Inc/gpio.h"
#include "../../_Drivers_/Inc/timer.h"

void dht11_setup();
void dht11_send_start_signal();
uint8_t validate_sensor();
uint8_t dht11_read();


#endif /* APIS_INC_DHT11_H_ */
