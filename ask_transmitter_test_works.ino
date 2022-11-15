
#include <RH_ASK.h>
#ifdef RH_HAVE_HARDWARE_SPI
#include <SPI.h> // Not actually used but needed to compile
#endif
int number;
String Val;


RH_ASK driver(2000, 3, 3, 5); 

void setup()
{
#ifdef RH_HAVE_SERIAL
    Serial.begin(9600);	  // Debugging only
#endif
    if (!driver.init())
#ifdef RH_HAVE_SERIAL
         Serial.println("init failed");
#else
	;
#endif
}

void loop()
{
  
  Val = String (number);
    char * buf = Val.c_str();

    driver.send((uint8_t *)buf, strlen(buf));
    driver.waitPacketSent();
    delay(200);
}
