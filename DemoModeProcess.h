#ifndef DEMOMODEPROCESS_H
#define DEMOMODEPROCESS_H

#include "SpecialModeDataType.h"
#include "SpecialModeBaseProcess.h"
#include "DemoModeTimer.h"

//#include "services/NGTPManagerService/INGTPManagerService.h"
//#include "services/NGTPManagerService/INGTPReceiver.h"
#include <utils/Message.h>
#include <utils/Handler.h>
#include <utils/atoi.h>
#include <time.h>

class DemoModeProcess : public SpecialModeBaseProcess
{
public:
    DemoModeProcess();
    virtual ~DemoModeProcess();    
    virtual void handleEvent(uint32_t ev);
    virtual void handleTimerEvent(int timerId);
    virtual void doSpecialModeHandler(int32_t what, const sp<sl::Message>& message);

    void doKeepPower();
    void doreleaseKeepPower();
    void demoModeStart();
    void demoModeStop();
    void sendResponse(int32_t what, const sp<sl::Message>& message);
    void activatePSIM();
    void onPSimStateChanged(int32_t simAct, int32_t event, int32_t slot);
    void onActiveSimStateChanged(int32_t activeSim);
    void onPsimLockStateChanged(bool locked);
    void checkEBcallStatus();
    void registerSVTpostReceiver();
    void demoModeClockReset();
//    void setDisableEbcallStatus();  branch to 2 function below
    void disableECall();
    void disableBCall();
    bool turnOnDemoMode(uint8_t timeUnit, int32_t timeValue);
    bool turnOffDemoMode();

    int byteToInt1(byte data[], int idx);
    uint8_t getSVTConfig(const char* name);

private:
    DemoModeTimerSet m_TimerSet;
    bool m_pSimCheck;
    bool m_CheckPower;
    bool m_SVTRegOnDemo;
    bool m_SVTAlertStatus;
    int32_t m_RunningTime;
    uint8_t m_TimeUnit;


protected:
    virtual void initializeProcess();

    void setDemoStatus(DemoModeStatus status);
    void setWifiStatus(WiFiStatus status);

    DemoModeStatus getDemoStatus();
    DemoModeStatus m_DemoModeStatus;

    WiFiStatus getWifiStatus();
    WiFiStatus m_WifiStatus;

};

#endif // DEMOMODEPROCESS_H
