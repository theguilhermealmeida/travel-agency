#ifndef INITIALSTATE_H
#define INITIALSTATE_H

#include <iostream>

#include "State.h"

class InitialState : public State {
   void step(App* app) override;
};

#endif
