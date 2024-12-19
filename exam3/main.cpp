#include <iostream>
#include <iomanip>
#include "MenuItem.h"
#include "Screen.h"
#include "PosSystem.h"
#include "constants.h"

using namespace std;

string getDateString();

int main()
{
    // Shared local state for reports
    int indentWidth = 4; // indentText.length(); <-- Unicode character are not accounted for in .length()
    int rightColumnWidth = 7;
    int colWidths[] = {79-indentWidth-rightColumnWidth, rightColumnWidth}; // Set the column widths (79 accounts for extra $)
    bool showTotals = true; // Loop back and add a toggle for this
    string date = getDateString(); // Add realistic date to reports

    PosSystem posSystem;

    // Init menu items
    posSystem.addMenuItem("Hamburger", 2.50, 5.99);
    posSystem.addMenuItem("Cheeseburger", 3.00, 6.99);
    posSystem.addMenuItem("Fries", 1.50, 1.99);
    posSystem.addMenuItem("Soda", 0.75, 1.49);
    posSystem.addMenuItem("Milkshake", 2.00, 7.99);

    // Init orders
    auto order = posSystem.addOrder("Joe Smith");
    posSystem.addOrderItem(order, "Hamburger", 2);
    posSystem.addOrderItem(order, "Cheeseburger", 1);
    posSystem.addOrderItem(order, "Milkshake", 1);

    order = posSystem.addOrder("Emma Wilson");
    posSystem.addOrderItem(order, "Cheeseburger", 1);
    posSystem.addOrderItem(order, "Fries", 2);
    posSystem.addOrderItem(order, "Soda", 1);

    // List all menu items in the system
    posSystem.listMenuItems();
    cout << endl;

    // List all orders in the system
    showHeading("All Orders for " + date, "────");
    posSystem.listOrders();
    cout << endl;

    // Show 'Costs Report' Output report heading {{ ---------------------
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
    // }} ---------------------------------------------------------------

    // Show 'Revenue Report' Output report heading {{ ---------------------
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
    // }} ---------------------------------------------------------------


    // Show 'Profit Report' Output report heading {{ ---------------------
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
    // }} ---------------------------------------------------------------

    // Show 'Item Profit Report' Output report heading {{ ---------------------
    showHeading("Per Item Profit Report for " + date, "──┬─");

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
    cout << endl;
    // }} ---------------------------------------------------------------

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
