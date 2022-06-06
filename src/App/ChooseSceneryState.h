#ifndef DELIVERY_SCHEDULER_CHOOSESCENERYSTATE_H
#define DELIVERY_SCHEDULER_CHOOSESCENERYSTATE_H

#include <iostream>

#include "State.h"
#include "Scenery2State.h"
#include "Scenery1State.h"

class ChooseSceneryState : public State {
    /**
    * Handle the specific events in the choose scenario state.
    * @param app Pointer to the main application.
    */
    void step(App* app) override;
};


#endif //DELIVERY_SCHEDULER_CHOOSESCENERYSTATE_H
