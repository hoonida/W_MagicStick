#include <Arduino.h>
#include "IrSenderTask.h"

#define DECODE_NEC
#define USE_IRREMOTE_HPP_AS_PLAIN_INCLUDE
#include <IRremote.hpp>

#define IR_SEND_PIN   3


IrSenderTask::IrSenderTask(Scheduler* scheduler, void (*onFinish)()) : Task(50, TASK_ONCE, scheduler, false) {

    this->onFinish = onFinish;
}

void IrSenderTask::start() {

    IrSender.begin(IR_SEND_PIN);
    restartDelayed();
}

void IrSenderTask::stop() {
    disable();
}


bool IrSenderTask::Callback() {

    uint16_t sAddress = 0x0102;
    uint8_t sCommand = 0x34;
    uint8_t sRepeats = 0;

    noInterrupts();
    IrSender.sendNEC(sAddress, sCommand, sRepeats);
    interrupts();

}

bool IrSenderTask::OnEnable() {

    return true;
}

void IrSenderTask::OnDisable() {
    if(onFinish != NULL) {
        onFinish();
    }   
}
