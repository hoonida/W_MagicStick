#ifndef LED_BLINKER_H
#define LED_BLINKER_H

#define _TASK_OO_CALLBACKS
#include <TaskSchedulerDeclarations.h>

class LedBlinker : public Task {

    public:

        LedBlinker(Scheduler* scheduler, void (*onFinish)() = NULL);
        ~LedBlinker() {};

        void start(int durationMilliSeconds = 1000000);
        void stop();


    private:
    
        void (*onFinish)();

        int counter;
        int timer;
        
        bool Callback();
        bool OnEnable();
        void OnDisable();
        
};

#endif
