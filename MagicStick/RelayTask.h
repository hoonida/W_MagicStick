#ifndef RELAY_TASK_H
#define RELAY_TASK_H

#define _TASK_OO_CALLBACKS
#include <TaskSchedulerDeclarations.h>


class RelayTask : public Task {

    public:

        RelayTask(Scheduler* scheduler, void (*onFinish)() = NULL);
        ~RelayTask() {};

        void start();
        void stop();


    private:

        void (*onFinish)();

        bool Callback();
        bool OnEnable();
        void OnDisable();
        
};

#endif
