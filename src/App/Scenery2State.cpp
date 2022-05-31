#include "Scenery2State.h"

void Scenery2State::step(App *app) {
    printBreak();

    std::cout << "\tScenario 2\n\n";

    std::cout << "3) 2.3 - Maximum group dimension\n";
    std::cout << "2) 2.2 - \n";
    std::cout << "1) 2.1 - Group of given dimension\n\n";
    std::cout << "5) Go back\n";
    std::cout << "0) Exit.\n";

    while (true)
    {
        int option = readOption(app);

        switch (option) {
            case 1:
                display21(app);
                return;
            case 3:
                display23(app);
                return;
            case 5:
                app->setState(new ChooseSceneryState());
                return;
            default:
                printInvalidOption();
        }
    }
}

void Scenery2State::display21(App *app) {
    printBreak();

    cout << "Scenery 2.1 - Allocate a group of given dimension\n\n";
    cout << "What is the dimension of the group?\n";
    int dimension = readOption(app);

    int flow = app->getAgency()->scenario21(dimension);
    cout << "Path found with a flow of " << flow << ".\n\n";
    cout << "1) Go back.\n";
    cout << "0) Exit.\n";

    while (true)
    {
        int option = readOption(app);

        switch (option) {
            case 1:
                return;
            case 0:
                app->setState(nullptr);
                return;
            default:
                printInvalidOption();
        }
    }

}

void Scenery2State::display23(App *app) {
    printBreak();

    int flow = app->getAgency()->scenario23();

    cout << "Scenery 2.3 - Maximum group dimension\n\n";
    cout << "The maximum flow is " << flow << ".\n\n";
    cout << "1) Go back.\n";
    cout << "0) Exit.\n";

    while (true)
    {
        int option = readOption(app);

        switch (option) {
            case 1:
                return;
            case 0:
                app->setState(nullptr);
                return;
            default:
                printInvalidOption();
        }
    }

}
