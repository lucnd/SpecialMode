#define LOG_TAG "SpecialModeApplication"
#include <sys/stat.h>
#include "SpecialModeBaseProcess.h"
#include "SpecialModeHandler.h"

SpecialModeBaseProcess::SpecialModeBaseProcess() : m_Handler(NULL),mp_Application(NULL),mp_DemoModeTimer(NULL){
    LOGV("## SpecialModeBaseProcess constructor called.");
}

SpecialModeBaseProcess::~SpecialModeBaseProcess(){
    if(mp_DemoModeTimer != NULL) {
        delete mp_DemoModeTimer;
    }
    LOGV("## ~SpceialModeBaseProcess()++");
}

void SpecialModeBaseProcess::initialize(sp<SpecialModeServicesManager> servicesMgr,ISpecialModeApplication* pApp){
    LOGV("## SpecialModeBaseProcess::initialize()");
    m_ServicesMgr   = servicesMgr;
    mp_Application  = pApp;
    initializeProcess();
}

std::string SpecialModeBaseProcess::getPropertyWrap(const char* name){

    return std::string("-1");
    // if(name != NULL) {
    //     LOGD("%s:  name[%s]", __func__, name);
    //     //return mp_Application->getPropertyWrap(name);
    // }
    // char *value = "435343";
    // return NULL;

//    if(name != NULL) {
//        LOGD("%s:  name[%s]", __func__, name);
//        return mp_Application->getPropertyWrap(name);
//    }
//    return NULL;
}

void SpecialModeBaseProcess::setPropertyChar(const char* name, const char* value) {
    if(name != NULL) {
        LOGD("%s:  name[%s], value[%s]", __func__, name, value);
        mp_Application->setPropertyChar(name, value);
    }
}

void SpecialModeBaseProcess::setPropertyInt(const char* name, const int32_t i_value) {
    if(name != NULL) {
        LOGD("%s:  name[%s], i_value[%d]", __func__, name, i_value);
        mp_Application->setPropertyInt(name, i_value);
    }
}
