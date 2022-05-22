#include <Arduino.h>
#include "RelayTask.h"

#define RELAY_PIN           16
#define POTENTIOMETER_PIN   A0

RelayTask::RelayTask(Scheduler* scheduler, void (*onFinish)()) : Task(0, TASK_ONCE, scheduler, false) {

    pinMode(RELAY_PIN, OUTPUT);

    this->onFinish = onFinish;
}

void RelayTask::start() {
  
    digitalWrite(RELAY_PIN, HIGH);

    unsigned int adCount = analogRead(POTENTIOMETER_PIN);

    //Serial.print("adCount :");
    //Serial.println(adCount * 60 / 1000);

    setInterval(adCount * 60);
    restartDelayed();
}

void RelayTask::stop() {
    disable();
}


bool RelayTask::Callback() {
    
}

bool RelayTask::OnEnable() {

    return true;
}

void RelayTask::OnDisable() {

    digitalWrite(RELAY_PIN, LOW);
  
    if(onFinish != NULL) {
        onFinish();
    }   
}
