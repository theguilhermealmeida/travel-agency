#ifndef DELIVERY_SCHEDULER_SCENERY1STATE_H
#define DELIVERY_SCHEDULER_SCENERY1STATE_H

#include <iostream>

#include "State.h"
#include "InitialState.h"


class Scenery1State : public State {
    void step(App *app) override;

    void display11(App *app);
    void display12(App *app);
};

#endif //DELIVERY_SCHEDULER_SCENERY1STATE_H
