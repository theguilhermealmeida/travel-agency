#include "Scenery1State.h"

void Scenery1State::step(App *app) {
    printBreak();

    std::cout << "\tScenario 1\n\n";

    std::cout << "2) 1.2 - Maximize group dimension and minimize transhipments\n";
    std::cout << "1) 1.1 - Maximize group dimension\n\n";
    std::cout << "9) Go back\n";
    std::cout << "0) Exit.\n";

    while (true)
    {
        int option = readOption(app);

        switch (option) {
            case 9:
                app->setState(new ChooseSceneryState());
                return;
            case 1:
                display11(app);
                return;
            case 2:
                display12(app);
                return;
            case 0:
                app->setState(nullptr);
                return;
            default:
                printInvalidOption();
        }
    }
}

void Scenery1State::display11(App *app) {
    printBreak();

    int src, dest;
    chooseSrcDest(app, src, dest);
    printBreak();


    Path path = app->getAgency()->scenario11(src, dest);

    auto info = [](Path path) {
        std::cout << "Scenery 1.1 - Maximize group dimension\n\n";
        path.printInfo();
        cout << "\n2) Display trips.\n";
        cout << "\n9) Go back.\n";
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

void Scenery1State::display12(App *app) {
    printBreak();

    int src, dest;
    chooseSrcDest(app, src, dest);
    printBreak();

    pair<Path, Path> paths = app->getAgency()->scenario12(src, dest);

    auto info = [](pair<Path, Path> paths) {
        std::cout << "Scenery 1.2 - Maximize group dimension and minimize transhipments.\n\n";
        cout << "      Max dimension info\n";
        paths.first.printInfo();
        cout << "\n      Min transhipments info\n";
        paths.second.printInfo();
        cout << "\n2) Display max dimension trips.\n";
        cout << "1) Display min transhipments trips.\n";
        cout << "\n9) Go back.\n";
        cout << "0) Exit.\n";
    };

    info(paths);

    while (true)
    {
        int option = readOption(app);

        switch (option) {
            case 9:
                return;
            case 2:
                displayTrips(app, paths.second);
                printBreak();
                info(paths);
                break;
            case 1:
                displayTrips(app, paths.first);
                printBreak();
                info(paths);
                break;
            case 0:
                app->setState(nullptr);
                return;
            default:
                printInvalidOption();
        }
    }

}

