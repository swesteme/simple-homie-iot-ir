#pragma once

#include <Receiver.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>

class IrReceiver : public Receiver {
  public:
    // constructor
    IrReceiver(uint16_t recvpin, const char* name);

  protected:
    virtual void setup();

    virtual unsigned long fillReceivedCode();

   private:
    // IR receiver
    IRrecv receiver;
};

