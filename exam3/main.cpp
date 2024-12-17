#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include "MenuItem.h"
#include "Screen.h"
#include "constants.h"
#include "PosSystem.h"
#include "MockState.h"

using namespace std;

string getDateString();

int main()
{
    // TODO: Implement the authentication system
    string activeUser = "jlewin";

    string date = getDateString();

    bool choiceValid = true;
    char choice = ' ';
    string notifyMessage = "";

    // Shared local state for reports
    int indentWidth = 4; // indentText.length(); <-- Unicode character are not accounted for in .length()
    int rightColumnWidth = 7;
    int colWidths[] = {79-indentWidth-rightColumnWidth, rightColumnWidth}; // Set the column widths (79 accounts for extra $)
    bool showTotals = true; // Loop back and add a toggle for this

    PosSystem posSystem;

    MockState mockState;
    mockState.initAppState(posSystem);

    // Disable so that the json dependency is not required (and thus 3rd party libraries)
    //loadJsonInventory(libraryInventory);

    do
    {
        showHeading("Restaurant Point of Sale System");
        cout << " 1. List Menu Items" << endl;
        cout << " 2. List Daily Orders" << endl;
        cout << " 3. Add Order" << endl;
        cout << " 4. Daily Costs Report" << endl;
        cout << " 5. Daily Revenue Report" << endl;
        cout << " 6. Daily Profit Report (store)" << endl;
        cout << " 7. Daily Profit Report (per item)" << endl;
        cout << " 8. Exit\n" << endl;

        // Report on invalid choice
        if (!choiceValid)
        {
            reportChoiceError(choice);
        }

        if (notifyMessage.length() > 0)
        {
            cout << notifyMessage << endl;
            notifyMessage = "";
        }

        // Initialize the error condition
        choiceValid = true;

        // Collect user input and update exit condition variable
        switch (choice = getMenuChoice())
        {
        case '1':
        {
            posSystem.listMenuItems();
            pauseForEnter();
            break;
        }
        case '2':
            posSystem.listOrders();
            pauseForEnter();
            break;
        case '3':
        {
            clearScreen();
            string customerName;
            showHeading("Add Order");
            cout << "Enter customer name: ";
            cin >> customerName;

            posSystem.printMenu();
            pauseForEnter();
            break;
        }

        case '4':
        {
            // Output report heading
            showHeading("Costs Report for " + date, "──┬─");

            // Output table header, init left aligned, 2 decimal places
            cout << left << setprecision(2) << fixed
                 << indentText << setw(colWidths[0]) << "Report" << setw(colWidths[1]) << "Totals" << endl;

            cout << indentText << left
                    << setfill('.') << setw(colWidths[0]) << "Total Costs of Goods Sold"
                    << "$"
                    << setfill(' ') << setw(colWidths[1]) << right << posSystem.getDailySalesCosts() << endl;

            printSeparator("  └─");

            cout << endl;
            pauseForEnter();
            break;
        }
        case '5':
            // Output report heading
            showHeading("Revenue Report for " + date, "──┬─");

            // Output table header, init left aligned, 2 decimal places
            cout << left << setprecision(2) << fixed
                 << indentText << setw(colWidths[0]) << "Report" << setw(colWidths[1]) << "Totals" << endl;

            cout << indentText << left
                    << setfill('.') << setw(colWidths[0]) << "Total Revenue on Goods Sold"
                    << "$"
                    << setfill(' ') << setw(colWidths[1]) << right << posSystem.getDailySalesRevenue() << endl;

            printSeparator("  └─");

            cout << endl;
            pauseForEnter();
            break;

        case '6':
            // Output report heading
            showHeading("Profit Report for " + date, "──┬─");

            // Output table header, init left aligned, 2 decimal places
            cout << left << setprecision(2) << fixed
                 << indentText << setw(colWidths[0]) << "Report" << setw(colWidths[1]) << "Totals" << endl;

            cout << indentText << left
                    << setfill('.') << setw(colWidths[0]) << "Total Profit on Goods Sold"
                    << "$"
                    << setfill(' ') << setw(colWidths[1]) << right << posSystem.getDailySalesProfit() << endl;

            printSeparator("  └─");

            cout << endl;
            pauseForEnter();
            break;
        case '7':
        {

            // Output report heading
            showHeading("Profit Report for " + date, "──┬─");

            // Output table header, init left aligned, 2 decimal places
            cout << left << setprecision(2) << fixed
                 << indentText << setw(colWidths[0]) << "Item" << setw(colWidths[1]) << "Profit" << endl;

            // Get profit results, loop over menu items and output aggregate profit
            auto menuItemProfits = posSystem.getDailyItemProfits();
            for (size_t i = 0; i < menuItemProfits.size(); i++)
            {
                cout << indentText << left
                     << setfill('.') << setw(colWidths[0]) << posSystem.getMenuItem(i)->getName()
                     << "$"
                     << setfill(' ') << setw(colWidths[1]) << right << menuItemProfits[i] << endl;
            }

            printSeparator("  └─");

            if (showTotals)
            {
                cout << string(indentWidth, ' ') << left
                     << setfill('.') << setw(colWidths[0]) << "Total"
                     << "$"
                     << setfill(' ') << setw(colWidths[1]) << right << posSystem.getDailySalesProfit() << endl;
            }

            // Reset back to the default fill character and push an empty line for improved formatting
            cout << setfill(' ') << endl;
            pauseForEnter();
            break;
        }
        case '8':
            return 0;
        default:
            choiceValid = false;
            break;
        }
    // Main Menu - loop until exit is called
    } while (true);

    return 0;
}

// Build a date string in the format MM/DD/YYYY using the strftime function
string getDateString() {
    char date[15];

    time_t timestamp = time(NULL);
    struct tm datetime = *localtime(&timestamp);
    strftime(date, 15, "%m/%d/%Y", &datetime);

    return date;
}
