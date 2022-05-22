#include <Arduino.h>

#include "IrReceiverTask.h"
#include "IrSenderTask.h"
#include "ToneSequencer.h"
#include "LedBlinker.h"
#include "RelayTask.h"

#define _TASK_OO_CALLBACKS
#include <TaskScheduler.h>

#define DECODE_NEC
#include <IRremote.hpp>

#define BUTTON_PIN          7



void onIrReceiveTaskReceive(unsigned int command);
void onIrReceiveTaskFinish();
void onIrSenderTaskFinish();
void onToneSequencerFinish();
void onLedBlinkerFinish();
void onRelayTaskFinish();

Scheduler scheduler;
IrReceiverTask  irReceiverTask  (&scheduler, onIrReceiveTaskReceive, onIrReceiveTaskFinish);
IrSenderTask    irSenderTask    (&scheduler, onIrSenderTaskFinish);
ToneSequencer   toneSequencer   (&scheduler, onToneSequencerFinish);
LedBlinker      ledBlinker      (&scheduler, onLedBlinkerFinish);
RelayTask       relayTask       (&scheduler, onRelayTaskFinish);

#define DEBUG


void setup() {
  
    #ifdef DEBUG
    Serial.begin(115200);
    //delay(2000);
    #endif
  
    irReceiverTask.start();

    pinMode(BUTTON_PIN, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), onPushButton, LOW);
    
}

void loop() {
    scheduler.execute();
}

void onPushButton() {

    detachInterrupt(digitalPinToInterrupt(BUTTON_PIN));

    #ifdef DEBUG
    Serial.println("onPushButton");
    #endif 
    
    irReceiverTask.disable();
    irSenderTask.start();
}

void onIrReceiveTaskReceive(unsigned int command) {
    #ifdef DEBUG
    Serial.println("onIrReceiveTaskReceive");
    Serial.println(command, HEX);
    #endif

    switch(command) {
    case 0x34:
        relayTask.start();
        break;
    case 0x35:
        ledBlinker.start(5000);
        break;
    }

}

void onIrReceiveTaskFinish() {
    #ifdef DEBUG
    Serial.println("onIrReceiveTaskFinish");
    #endif

}

void onIrSenderTaskFinish() {
    #ifdef DEBUG
    Serial.println("onIrSenderTaskFinish");
    #endif

    toneSequencer.start();
    ledBlinker.start();
}

void onToneSequencerFinish() {
    #ifdef DEBUG
    Serial.println("onToneSequencerFinish");
    #endif

    ledBlinker.stop();
    irReceiverTask.start();

    attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), onPushButton, LOW);
}

void onLedBlinkerFinish() {
    #ifdef DEBUG
    Serial.println("onLedBlinkerFinish");
    #endif

    irReceiverTask.start();
}

void onRelayTaskFinish() {
    #ifdef DEBUG
    Serial.println("onRelayTaskFinish");
    #endif
    
    irReceiverTask.start();
}
