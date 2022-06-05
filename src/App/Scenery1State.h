#ifndef SCENERY1STATE_H
#define SCENERY1STATE_H

#include <iostream>

#include "State.h"
#include "InitialState.h"


class Scenery1State : public State {
    void step(App *app) override;

    /**
     * Scenario 1.1 - Maximize group dimension.
     * @param app Pointer to the main application.
     */
    void display11(App *app);

    /**
     * Scenario 1.2 - Maximize group dimension and minimize transhipments.
     * @param app Pointer to the main application.
     */
    void display12(App *app);
};

#endif
