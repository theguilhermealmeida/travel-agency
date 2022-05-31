#include "State.h"

void State::run(App *app)
{
    step(app);
}

int State::readOption(App* app) const
{
    int option;

    while (!(std::cin >> option))
    {
        if (std::cin.eof()) app->setState(nullptr);
        else
        {
            std::cin.clear();
            std::cin.ignore(1000000, '\n');
            printInvalidOption();
        }
    }
    return option;
}

void State::printBreak() const
{
    for (int i = 0; i < 40; i++) std::cout << std::endl;
}

void State::printInvalidOption() const
{
    std::cout << "Invalid option. Try again.\n";
}

std::vector<int> State::findLength(const std::vector<std::vector<std::string>> &table) const
{
    std::vector<int> res(table[0].size(), 2);
    for (int i = 0; i < table.size(); i++)
    {
        for (int j = 0; j < table[0].size(); j++)
        {
            if (res[j] < table[i][j].size()) res[j] = table[i][j].size();
        }
    }
    return res;
}

void State::displayTable(std::vector<std::vector<std::string> >& table, int page) const
{
    std::vector<int> length = findLength(table);
    std::vector<std::string> header = table[0];
    table.erase(table.begin());
    int n_pages = (table.size() + ITEMS_PER_PAGE - 1) / ITEMS_PER_PAGE - 1;
    page = std::min(n_pages, page - 1);
    page = std::max(0, page);
    std::string barrier = "+";
    for (int & i: length) barrier += std::string(i + 2, '-') + '+';
    std::cout << barrier << "\n|";
    for (int i = 0; i < header.size(); i++) std::cout << " " << std::left
        << std::setw(length[i]) << header[i]<< " |";
    std::cout << std::endl << barrier << std::endl;
    for (int i = page * ITEMS_PER_PAGE; i < table.size() && i < (page + 1) * ITEMS_PER_PAGE; i++)
    {
        std::cout << "|";
        for (int j = 0; j < table[0].size(); j++)
        {
            std::cout << " " << std::left << std::setw(length[j]) << table[i][j] << " |";
        }
        std::cout << std::endl;
    }
    std::cout << barrier << std::endl;
    std::string index = "Page " + std::to_string(page + 1) + "/" + std::to_string(n_pages + 1);
    std::cout << std::right << std::setw(barrier.size()) << index << std::endl;
}

void State::getNextPage(App* app, int& page, const int& max_page) const {
    std::cout << std::endl;
    if (page < max_page) std::cout << "3) Next page\n";
    if (1 < page) std::cout << "2) Previous page\n";
    std::cout << "\n1) Go back\n0) Exit\n";

    int option = readOption(app);
    switch (option) {
        case 3:
            if (page < max_page) page++;
            return;
        case 2:
            if (1 < page) page--;
            return;
        case 1:
            page = -1;
            return;
        case 0:
            page = -1;
            app->setState(nullptr);
            return;
    }
}

void State::displayTrips(App* app, const Path &path) {
    printBreak();
    path.printTrips();

    cout << endl;
    cout << "1) Go back\n";
    cout << "0) Exit\n";

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

void State::chooseSrcDest(App *app, int &src, int &dest) {
    string node = "source";
    while (true) {
        cout << "Graph size: " << app->getAgency()->getGraphSize() << "\nChoose " << node << " node: ";
        int option = readOption(app);
        cout << "\n";

        checkNode(app, option, node);

        if (node == "source") src = option;
        else dest = option;

        while (src == dest) {
            cout << "Source and destination node must be different.\nChoose destination node: ";
            option = readOption(app);
            cout << "\n";

            checkNode(app, option, node);

            dest = option;
        }

        if (node == "destination") break;
        node = "destination";
    }
}

void State::checkNode(App *app, int &node, string src_dest) {
    while (node < 1 || node > app->getAgency()->getGraphSize()) {
        cout << "Node must be between 1 and " << app->getAgency()->getGraphSize()
             << ".\nChoose " << src_dest << " node: ";

        node = readOption(app);
        cout << "\n";
    }
}