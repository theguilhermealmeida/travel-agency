#include "App.h"

App::App()
{
    settings.file_path = "../../data/in01.txt";
    agency = new Agency(settings.file_path);
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