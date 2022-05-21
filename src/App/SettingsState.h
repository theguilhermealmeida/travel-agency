#ifndef SETTINGSSTATE_H
#define SETTINGSSTATE_H

#include <iostream>

#include "State.h"
#include "InitialState.h"

class SettingsState : public State {
   void step(App* app) override;
};

#endif
