#pragma once

#include <RemoteButton.h>

class IrReceiver;

class IrRemoteButton : public RemoteButton {
  public:
    // constructor
    IrRemoteButton(IrReceiver *receiverNode, const char* id, const char* name, unsigned long code);

  protected:
    virtual ResultState checkCode(unsigned long cmpCode) const;
};

