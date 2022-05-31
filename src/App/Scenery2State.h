#ifndef SCENERY2STATE_H
#define SCENERY2STATE_H

#include "App.h"
#include "State.h"
#include "ChooseSceneryState.h"

class Scenery2State : public State {
   void step(App *app) override;

   void display21(App *app);
   void display23(App *app);
};


#endif
