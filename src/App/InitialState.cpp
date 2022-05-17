#include "InitialState.h"

void InitialState::step(App* app) {
   printBreak();

   std::cout << "\tHello World!\n\n";
   std::cout << "0) Exit\n";

   while (true)
   {
       int option = readOption(app);

       switch (option) {
           case 0:
               app->setState(nullptr);
               return;
           default:
               printInvalidOption();
       }

   }
}