#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <iomanip>
#include <set>
#include <vector>

#include "App.h"

#define ITEMS_PER_PAGE 7

class App;

class State {
public:
   /**
    * State's main method. Calls display and step.
    * @param app Pointer to the main application.
    */
   void run(App* app);

protected:
   /**
    * Reads an integer until valid input.
    * @param app Pointer to the main application.
    * @return - Returns an integer from user input.
    */
   int readOption(App* app) const;

   /**
    * Print a page break;
    */
   void printBreak() const;

   /**
   * Outputs the invalid option message to the console.
   */
   void printInvalidOption() const;

   /**
    * Handle the specific events in each state.
    * @param app Pointer to the main application.
    */
   virtual void step(App* app) {}

   /**
    * Find the maximum length per column for a column row.
    * @param table 2D vector to be displayed as a table.
    * @return Vector with maximum dimension per row.
    */
   std::vector<int> findLength(const std::vector<std::vector<std::string> > &table) const;

   /**
    * Displays a table from a 2D vector.
    * @param table 2D vector to be displayed as a table.
    * @param page The current page being displayed (to limit the amount of content)
    */
   void displayTable(std::vector<std::vector<std::string> >& table, int page) const;

   /**
    * Go to a separate page that displays all the trips from the same path.
    * @param app Pointer to main application.
    * @param path Path object to be displayed.
    */
   void displayTrips(App* app, const Path& path);

    void chooseSrcDest(App *app, int &src, int &dest);
private:

   /**
    * Get the next page for a table display.
    * @param app Pointer to the main application.
    * @param page Current displayed page.
    * @param max_page Maximum number of pages.
    */
   void getNextPage(App* app, int& page, const int& max_page) const;

    void checkNode(App *app, int &node, string src_dest);
};


#endif