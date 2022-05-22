#include <Arduino.h>
#include "IrReceiverTask.h"

#define DECODE_NEC
#define USE_IRREMOTE_HPP_AS_PLAIN_INCLUDE
#include <IRremote.hpp>

#define IR_RECEIVE_PIN  2


IrReceiverTask::IrReceiverTask(Scheduler* scheduler, void (*onReceive)(unsigned int), void (*onFinish)()) : Task(100, TASK_FOREVER, scheduler, false) {

    this->onReceive = onReceive;
    this->onFinish = onFinish;
}

void IrReceiverTask::start() {
  
    IrReceiver.begin(IR_RECEIVE_PIN);
    restartDelayed();
}

void IrReceiverTask::stop() {
    disable();
}


bool IrReceiverTask::Callback() {

    if (IrReceiver.decode()) {

        IrReceiver.printIRResultShort(&Serial);//IrReceiver.printIRResultShort(&Serial);

        if (IrReceiver.decodedIRData.protocol == NEC && IrReceiver.decodedIRData.address == 0x0102) {

            
            onReceive(IrReceiver.decodedIRData.command);
            
            disable();
        }
        else {
            IrReceiver.resume();
        }

    }

}

bool IrReceiverTask::OnEnable() {

    return true;
}

void IrReceiverTask::OnDisable() {
    if(onFinish != NULL) {
        onFinish();
    }  
}
