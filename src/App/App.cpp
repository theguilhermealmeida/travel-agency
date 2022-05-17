#include "App.h"

App::App()
{
    agency = new Agency();
}

void App::run()
{
    while (state != nullptr)
    {
        state->run(this);
    }
}

Agency* App::getAgency() const
{
    return agency;
}


void App::setState(State* state)
{
    this->state = state;
}