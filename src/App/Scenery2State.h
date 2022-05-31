#ifndef SCENERY2STATE_H
#define SCENERY2STATE_H

#include "App.h"
#include "State.h"
#include "ChooseSceneryState.h"

class Scenery2State : public State {
   void step(App *app) override;

   /**
    * Scenario 2.1 - Get the path with maximum flow for a given group dimension.
    * The group splits up.
    * @param app Pointer to main application.
    */
   void display21(App *app);

   /**
    * Scenario 2.3 - Get the maximum path through the network when the group spits up.
    * @param app Pointer to main application.
    */
   void display23(App *app);
};


#endif
