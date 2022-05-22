#ifndef IR_SENDER_TASK_H
#define IR_SENDER_TASK_H

#define _TASK_OO_CALLBACKS
#include <TaskSchedulerDeclarations.h>


class IrSenderTask : public Task {

    public:

        IrSenderTask(Scheduler* scheduler, void (*onFinish)() = NULL);
        ~IrSenderTask() {};

        void start();
        void stop();


    private:

        void (*onFinish)();

        bool Callback();
        bool OnEnable();
        void OnDisable();
        
};

#endif
