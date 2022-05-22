#ifndef IR_RECEIVER_TASK_H
#define IR_RECEIVER_TASK_H

#define _TASK_OO_CALLBACKS
#include <TaskSchedulerDeclarations.h>


class IrReceiverTask : public Task {

    public:

        IrReceiverTask(Scheduler* scheduler, void (*onReceive)(unsigned int) = NULL, void (*onFinish)() = NULL);
        ~IrReceiverTask() {};

        void start();
        void stop();


    private:

        void (*onReceive)(unsigned int);
        void (*onFinish)();

        bool Callback();
        bool OnEnable();
        void OnDisable();
        
};

#endif
