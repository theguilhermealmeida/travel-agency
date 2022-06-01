#include "Scenery2State.h"

void Scenery2State::step(App *app) {
    printBreak();

    std::cout << "\tScenario 2\n\n";

    std::cout << "3) 2.3 - Maximum group dimension\n";
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

    int src, dest;
    chooseSrcDest(app, src, dest);
    printBreak();

    cout << "Scenery 2.1 - Allocate a group of given dimension\n\n";
    cout << "What is the dimension of the group?\n";
    int dimension = readOption(app);

    Path path = app->getAgency()->scenario21(src, dest, dimension, residual);
    cout << "Path found with a flow of " << path.getFlow() << ".\n\n";
    cout << "3) Display trips.\n";
    cout << "2) Add more people to the group (Scenario 2.2).\n";
    cout << "1) Go back.\n";
    cout << "0) Exit.\n";

    while (true)
    {
        int option = readOption(app);

        switch (option) {
            case 3:
                displayTrips(app, path);
                return;
            case 2:
                display22(app, src, dest, path.getFlow(), dimension);
                return;
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

void Scenery2State::display22(App *app, const int& src, const int& dest, const int& flow, int dimension) {
    printBreak();

    cout << "Scenery 2.2 - Correct a path for a different group dimension\n\n";
    cout << "How many people are joining the group?\n";
    dimension += readOption(app);

    Path path = app->getAgency()->scenario22(src, dest, dimension, residual, flow);
    cout << "Path found with a flow of " << path.getFlow() << ".\n\n";
    cout << "3) Display trips.\n";
    cout << "2) Add even more people to the group.\n";
    cout << "1) Go back.\n";
    cout << "0) Exit.\n";

    while (true)
    {
        int option = readOption(app);

        switch (option) {
            case 3:
                displayTrips(app, path);
                return;
            case 2:
                display22(app, src, dest, path.getFlow(), dimension);
                return;
            case 1:
                app->setState(new Scenery2State());
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

    int src, dest;
    chooseSrcDest(app, src, dest);
    printBreak();


    Path path = app->getAgency()->scenario23(src, dest);

    cout << "Scenery 2.3 - Maximum group dimension\n\n";
    cout << "The maximum flow is " << path.getFlow() << ".\n\n";
    cout << "2) Display trips.\n";
    cout << "1) Go back.\n";
    cout << "0) Exit.\n";

    while (true)
    {
        int option = readOption(app);

        switch (option) {
            case 2:
                displayTrips(app, path);
                return;
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
