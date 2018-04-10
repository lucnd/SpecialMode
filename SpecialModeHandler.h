#ifndef SPECIALMODEHANDLER_H
#define SPECIALMODEHANDLER_H

#include "SpecialModeDataType.h"
#include "ISpecialModeApplication.h"

enum SpecialModeHandlerMessageID{
    RECV_MSG_FROM_DIAGNOSTICS_DATA      = 3,
    RECV_MSG_FROM_SLDD                  = 4,
    RECV_MSG_FROM_WIFI_ON               = 13,
    RECV_MSG_FROM_WIFI_OFF              = 14,
    RECV_MSG_FROM_CONFIG                = 15,
    RECV_MSG_DEMOMODE_START             = 100,
    RECV_MSG_DEMOMODE_STOP              = 101
};

class SpecialModeHandler : public sl::Handler
{
private:
    ISpecialModeApplication& mr_Application;

public:
    SpecialModeHandler(sp<sl::SLLooper>& looper, ISpecialModeApplication& service) : Handler(looper),mr_Application(service){}
    virtual void handleMessage(const sp<sl::Message>& message);
    virtual ~SpecialModeHandler();
};

#endif // SPECIALMODEHANDLER_H
