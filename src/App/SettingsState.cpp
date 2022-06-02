#include "SettingsState.h"

void SettingsState::step(App* app) {
    printBreak();

    std::cout << "\tSettings\n\n";

    std::cout << "Test file: " << app->getSettings().file_path << "\n\n";

    std::cout << "2) See example files.\n";
    std::cout << "1) Change input file.\n";

    std::cout << "\n9) Go back\n";
    std::cout << "0) Exit\n";

    while (true)
    {
        int option = readOption(app);

        switch (option) {
            case 9:
                app->setState(new InitialState());
                return;
            case 2:
                displayFiles(app);
                app->setState(new SettingsState());
                return;
            case 1:
                changeFile(app);
                app->setState(new SettingsState());
                return;
            case 0:
                app->setState(nullptr);
                return;
            default:
                printInvalidOption();
        }

    }
}

void SettingsState::changeFile(App *app) {
    string path;
    ifstream f;
    do {
        cout << "Choose a valid path for the input file:\n";
        cin >> path;
        f = ifstream (path);
    } while (!f.good());
    app->changeFile(path);
}

void SettingsState::displayFiles(App *app) const {
    printBreak();
    cout << "Smaller graph (good for visualization): \n";
    cout << "\t../data/test.txt\n\n";
    cout << "Different test sets with varying dimension:\n";
    cout << "\t../data/inN.txt\n\n";
    cout << "Where N is a number between 01 and 10\n\n";

    cout << "9) Go back\n\n";

    while (true)
    {
        int option = readOption(app);

        switch (option) {
            case 9:
                return;
            default:
                printInvalidOption();
        }
    }
}
