#include <Arduino.h>
#include "LedBlinker.h"

#define LED0_PIN    14
#define LED1_PIN    15



LedBlinker::LedBlinker(Scheduler* scheduler, void (*onFinish)()) : Task(0, TASK_FOREVER, scheduler, false) {

    pinMode(LED0_PIN, OUTPUT);
    pinMode(LED1_PIN, OUTPUT);

    this->onFinish = onFinish;
    
}

void LedBlinker::start(int durationMilliSeconds) {

    counter = 0;
    timer = durationMilliSeconds;
    
    setInterval(0);
    restartDelayed();
}

void LedBlinker::stop() {
    disable();
}

bool LedBlinker::Callback() {

    if(timer <= 0) {
        disable();
        return;
    }
    else {

        int nextInterval = min(timer, 100 + random(0, 100));
        timer -= nextInterval;
    
        setInterval(nextInterval);
    }


    if(++counter % 2 == 0) {
        digitalWrite(LED0_PIN, HIGH);
        digitalWrite(LED1_PIN, LOW);
    }
    else {
        digitalWrite(LED0_PIN, LOW);
        digitalWrite(LED1_PIN, HIGH);
    }

}

bool LedBlinker::OnEnable() {

    return true;
}

void LedBlinker::OnDisable() {

    digitalWrite(LED0_PIN, LOW);
    digitalWrite(LED1_PIN, LOW);

    if(onFinish != NULL) {
        onFinish();
    }
}
