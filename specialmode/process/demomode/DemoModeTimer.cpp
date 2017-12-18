/**
* \file    DemoModeTimer.cpp
* \brief     Declaration of DemoModeTimer
*
* \details
*    This software is copyright protected and proprietary to
*    LG electronics. LGE grants to you only those rights as
*    set out in the license conditions. All other rights remain
*    with LG electronics.
* \author       junghun77.kim
* \date    2016.12.13
* \attention Copyright (c) 2015 by LG electronics co, Ltd. All rights reserved.
*/

#define LOG_TAG "DemoModeTimer"

#include "DemoModeTimer.h"


DemoModeTimerSet::DemoModeTimerSet()
    : m_InitFlag(false),mp_DemoModeTimerSet{0}{
    LOGI("## DemoModeTimerSet created!");
}


DemoModeTimerSet::~DemoModeTimerSet(){
    LOGI("## DemoModeTimerSet closed!");
}


void DemoModeTimerSet::initialize(TimerTimeoutHandler* pTimerHandler){
    if(pTimerHandler == NULL) {
        return;
    }
    LOGI("##DemoModeTimerSet DemoModeTimerSet initialize()");
    mp_DemoModeTimerSet[0] = new Timer(pTimerHandler, TIMER_DEMOMODE_ACTIVE);
    mp_DemoModeTimerSet[1] = new Timer(pTimerHandler, TIMER_SVT_ANSWER);

    m_InitFlag  = true;
}


void DemoModeTimerSet::release(){
    if(m_InitFlag == false) {
        return;
    }
    LOGI("##DemoModeTimerSet DemoModeTimerSet release()");
    if(m_InitFlag == false) {
        return;
    }
    delete mp_DemoModeTimerSet[0];
    delete mp_DemoModeTimerSet[1];
}


bool DemoModeTimerSet::startTimer(uint32_t index, uint32_t startTimeout, uint32_t cyclicTimeout){
    LOGI("DemoModeTimerSet startTimer(), index[%d], timeout[%d sec] ====================", index, startTimeout);

    mp_DemoModeTimerSet[index]->setDuration(startTimeout, cyclicTimeout);
    mp_DemoModeTimerSet[index]->start();

    return true;
}

bool DemoModeTimerSet::stopTimer(uint32_t index){
    LOGI("DemoModeTimerSet %s(), index[%d] ", __func__, index);

    mp_DemoModeTimerSet[index]->stop();

    return true;
}

void DemoModeTimer::handlerFunction(int timerId){
    LOGI("##DemoModeTimer %s(), timerId[%d]", __func__, timerId);
    mr_Process.handleTimerEvent(timerId);
}