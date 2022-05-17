#include "App/App.h"
#include "App/InitialState.h"

int main()
{
    App app;
    app.setState(new InitialState());
    app.run();
    return 0;
}