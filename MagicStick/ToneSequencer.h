#ifndef TONE_SEQUENCER_H
#define TONE_SEQUENCER_H

#define _TASK_OO_CALLBACKS
#include <TaskSchedulerDeclarations.h>

class ToneSequencer : public Task {

    public:
    
        ToneSequencer(Scheduler* scheduler, void (*onFinish)() = NULL);
        ~ToneSequencer() {};

        void start();
        void stop();

  
    private:
    
        void (*onFinish)();

        bool Callback();
        bool OnEnable();
        void OnDisable();

        static const int notes[][2];
        int noteIndex;
        int notePhase;

        void playTone();
        void pauseTone();
  
};

#endif
