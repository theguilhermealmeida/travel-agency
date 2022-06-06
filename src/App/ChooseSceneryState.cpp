#include "ChooseSceneryState.h"

void ChooseSceneryState::step(App *app) {
    printBreak();
    std::cout << "\tChoose the scenario\n\n";
    std::cout << "2) Group splits up.\n";
    std::cout << "1) Group stays together.\n\n";
    std::cout << "9) Go Back.\n";
    std::cout << "0) Exit.\n";

    while (true) {
        int option = readOption(app);

        switch (option) {
            case 2:
                app->setState(new Scenery2State());
                return;
            case 1:
                app->setState(new Scenery1State());
                return;
            case 9:
                app->setState(new InitialState());
                return;
            case 0:
                app->setState(nullptr);
                return;
            default:
                printInvalidOption();
                break;
        }
    }
}