#include "Scenery1State.h"

void Scenery1State::step(App *app) {
    printBreak();

    std::cout << "\tScenario 1\n\n";

    std::cout << "2) 1.2 - Maximize group dimension and minimize transhipments\n";
    std::cout << "1) 1.1 - Maximize group dimension\n\n";
    std::cout << "3) Go back\n";
    std::cout << "0) Exit.\n";

    while (true)
    {
        int option = readOption(app);

        switch (option) {
            case 3:
                app->setState(new ChooseSceneryState());
                return;
            case 1:
                display11(app);
                return;
            case 2:
                //display12(app);
                return;
            default:
                printInvalidOption();
        }
    }
}

void Scenery1State::display11(App *app) {
    printBreak();

    Path path = app->getAgency()->scenario11();

    std::cout << "Scenery 1.1 - Maximize group dimension\n\n";
    path.printInfo();
    cout << "\n2) Display trips.\n";
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

/*void Scenery1State::display12(App *app) {
    printBreak();

    vector<vector<Trip>> paths = app->getAgency()->scenario12();

    std::cout << "Scenery 1.2 - Maximize group dimension and minimize transhipments.\n\n";

    int sol = 1;
    for (auto p: paths) {
        cout << "Solution " << sol << ": \n\n";
        for (auto t: p) {
            cout << t.src << " ------------> " << t.dest << "\n";
            cout << "   capacity: " << t.capacity << "\n";
            cout << "   duration: " << t.duration << "\n\n";
        }
        sol++;
    }

    cout << "\n1) Go back.\n";
    while (true) {
        int option = readOption(app);

        switch (option) {
            case 1:
                return;
            default:
                printInvalidOption();
        }
    }

}
 */

