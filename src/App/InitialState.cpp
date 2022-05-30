#include "InitialState.h"

void InitialState::step(App* app) {
   printBreak();

   std::cout << "\tHello World!\n\n";
   std::cout << "2) Start\n";
   std::cout << "1) Settings\n";
   std::cout << "0) Exit\n";

   while (true)
   {
       int option = readOption(app);

       switch (option) {
           case 2:
               app->setState(new ChooseSceneryState());
               return;
           case 1:
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