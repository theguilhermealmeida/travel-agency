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
    * Scenario 2.2 - Get the path with maximum flow for a given group dimension.
    * The group splits up.
    * @param app Pointer to main application.
    * @param src Source node.
    * @param dest Destination node.
    * @param flow Flow of path.
    * @param dimension Dimension of path.
    */
   void display22(App *app, const int& src, const int& dest, const int& flow, int dimension);

   /**
    * Scenario 2.3 - Get the maximum path through the network when the group spits up.
    * @param app Pointer to main application.
    */
   void display23(App *app);

   /**
    * Scenario 2.4 - Find how long the group will take to reunite at the destination.
    * @param app Pointer to main application.
    */
   void display24(App *app);

   /**
    * Scenario 2.5 - Find the maximum waiting time in path and the nodes that wait that time.
    * @param app Pointer to the main application.
    */
    void display25(App *app);

   vector<vector<int> > residual;
};


#endif
