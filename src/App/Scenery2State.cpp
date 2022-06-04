#include "Scenery2State.h"

void Scenery2State::step(App *app) {
    printBreak();

    std::cout << "\tScenario 2\n\n";

    std::cout << "5) 2.5 - Maximum waiting time\n";
    std::cout << "4) 2.4 - Minimum time\n";
    std::cout << "3) 2.3 - Maximum group dimension\n";
    std::cout << "1) 2.1 - Group of given dimension\n";
    std::cout << "\n9) Go back\n";
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
            case 4:
                display24(app);
                return;
            case 5:
                display25(app);
                return;
            case 9:
                app->setState(new ChooseSceneryState());
                return;
            case 0:
                app->setState(nullptr);
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

    auto info = [](Path path) {
        cout << "Path found with a flow of " << path.getFlow() << ".\n\n";
        cout << "3) Display trips.\n";
        cout << "2) Add more people to the group (Scenario 2.2).\n";
        cout << "\n9) Go back.\n";
        cout << "0) Exit.\n";
    };

    info(path);

    while (true)
    {
        int option = readOption(app);

        switch (option) {
            case 3:
                displayTrips(app, path);
                printBreak();
                info(path);
                break;
            case 2:
                display22(app, src, dest, path.getFlow(), dimension);
                return;
            case 9:
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

    auto info = [](Path path){
        cout << "Path found with a flow of " << path.getFlow() << ".\n\n";
        cout << "3) Display trips.\n";
        cout << "2) Add even more people to the group.\n";
        cout << "\n9) Go back.\n";
        cout << "0) Exit.\n";
    };

    info(path);

    while (true)
    {
        int option = readOption(app);

        switch (option) {
            case 3:
                displayTrips(app, path);
                printBreak();
                info(path);
                break;
            case 2:
                display22(app, src, dest, path.getFlow(), dimension);
                return;
            case 9:
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

    auto info = [](Path path) {
        cout << "Scenery 2.3 - Maximum group dimension\n\n";
        cout << "The maximum flow is " << path.getFlow() << ".\n\n";
        cout << "2) Display trips.\n";
        cout << "9) Go back.\n";
        cout << "0) Exit.\n";
    };

    info(path);

    while (true)
    {
        int option = readOption(app);

        switch (option) {
            case 2:
                displayTrips(app, path);
                printBreak();
                info(path);
                break;
            case 9:
                return;
            case 0:
                app->setState(nullptr);
                return;
            default:
                printInvalidOption();
        }
    }

}

void Scenery2State::display24(App *app) {
    printBreak();

    int src, dest;
    chooseSrcDest(app, src, dest);
    printBreak();

    cout << "Scenery 2.4 - Find how long the group will take to reunite at the destination\n\n";

    Path path = app->getAgency()->scenario24(src, dest);

    auto info = [](Path path) {
        cout << "The group will reunite in " << path.getMinTime() << " minutes.\n\n";
        cout << "3) Display trips.\n";
        cout << "\n9) Go back.\n";
        cout << "0) Exit.\n";
    };

    info(path);

    while (true)
    {
        int option = readOption(app);

        switch (option) {
            case 3:
                displayTrips(app, path);
                printBreak();
                info(path);
                break;
            case 9:
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

void Scenery2State::display25(App *app) {
    printBreak();

    int src, dest;
    chooseSrcDest(app, src, dest);
    printBreak();

    cout << "Scenery 2.5 - Find the maximum waiting time in the path and the respective nodes\n\n";

    Path path = app->getAgency()->scenario25(src, dest);

    auto info = [](Path path) {
        cout << "Maximum waiting time: " << path.getWaitingTime() << "\n";
        cout << "Respective nodes: ";
        for (auto n: path.get_waiting_time_nodes()) {
            cout << n << " ";
        }
        cout << "\n";
        cout << "3) Display trips.\n";
        cout << "\n9) Go back.\n";
        cout << "0) Exit.\n";
    };

    info(path);

    while (true)
    {
        int option = readOption(app);

        switch (option) {
            case 3:
                displayTrips(app, path);
                printBreak();
                info(path);
                break;
            case 9:
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
