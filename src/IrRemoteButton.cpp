#include "IrRemoteButton.h"
#include "IrReceiver.h"

IrRemoteButton::IrRemoteButton(IrReceiver* receiverNode, const char* id,
                               const char* name, unsigned long code)
    : RemoteButton(receiverNode, id, name, code) {}

ResultState IrRemoteButton::checkCode(unsigned long cmpCode) const {
  // check, whether the code matches
  if (getCode() == cmpCode) {
    return STATE_ON;
  }

  return STATE_NO_MATCH;
}
