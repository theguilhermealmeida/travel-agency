#include "SettingsState.h"

void SettingsState::step(App* app) {
    printBreak();

    std::cout << "\tSettings\n\n";

    std::cout << "Test file: " << app->getSettings().file_path << "\n\n";

    std::cout << "9) Go back\n";
    std::cout << "0) Exit\n";

    while (true)
    {
        int option = readOption(app);

        switch (option) {
            case 9:
                app->setState(new InitialState());
                return;
            case 0:
                app->setState(nullptr);
                return;
            default:
                printInvalidOption();
        }

    }
}
