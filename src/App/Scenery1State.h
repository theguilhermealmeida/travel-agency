#ifndef SCENERY1STATE_H
#define SCENERY1STATE_H

#include <iostream>

#include "State.h"
#include "InitialState.h"


class Scenery1State : public State {
    void step(App *app) override;

    void display11(App *app);
    void display12(App *app);
};

#endif
