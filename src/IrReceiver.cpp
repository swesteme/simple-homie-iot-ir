
#include "IrReceiver.h"

IrReceiver::IrReceiver(uint16_t recvpin, const char* name)
    : Receiver("infrared", name), receiver(recvpin) {}

void IrReceiver::setup() {
  HomieNode::setup();
  // Start the receiver
  receiver.enableIRIn();
}

unsigned long IrReceiver::fillReceivedCode() {
  decode_results results;
  if (receiver.decode(&results)) {
    unsigned long retVal = results.value;

    receiver.resume();  // Receive the next value

    // do not notify of buttons held for a longer period of time
    if (retVal != 4294967295) {
      return retVal;
    }
  }

  return 0;
}
