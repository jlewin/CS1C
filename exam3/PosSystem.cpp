#include <iostream>
#include <iomanip>
#include "PosSystem.h"
#include "constants.h"

using namespace std;

// Constructor
PosSystem::PosSystem() {
}

// Destructor
PosSystem::~PosSystem() {
    // Free memory for orders
    for (size_t i = 0; i < orders.size(); i++) {
        delete orders[i];
    }

    // Free memory for menuitems
    for(size_t i = 0; i < menu.size(); i++) {
        delete menu[i];
    }
}

// Order functions
CustomerOrder* PosSystem::addOrder(const string& customerName) {
    CustomerOrder* order = new CustomerOrder(customerName);
    orders.push_back(order);
    return order;
}

void PosSystem::addOrderItem(CustomerOrder* order, const string& name, int quantity) {
    const MenuItem* menuItem = getMenuItem(name);
    if (menuItem != nullptr) {
        order->addItem(menuItem, quantity);
    }
}

// Menu functions
void PosSystem::addMenuItem(const string& name, double cost, double salePrice) {
    menu.push_back(new MenuItem(name, cost, salePrice));
}

const MenuItem* PosSystem::getMenuItem(const int index) const {
    return menu[index];
}

const MenuItem* PosSystem::getMenuItem(const std::string& name) const {
    for (size_t i = 0; i < menu.size(); i++) {
        if (menu[i]->getName() == name) {
            return menu[i];
        }
    }

    // Handle non-matching case
    return nullptr;
}

int PosSystem::getMenuItemIndex(const std::string& name) const {
    for (size_t i = 0; i < menu.size(); i++) {
        if (menu[i]->getName() == name) {
            return i;
        }
    }

    // Handle non-matching case
    return -1;
}

// Insertion operator
ostream& operator<<(ostream& outstream, const PosSystem& posSystem) {
    for (size_t i = 0; i < posSystem.orders.size(); i++) {
        outstream << posSystem.orders[i];
    }

    return outstream;
}

// Reporting functions
void PosSystem::listMenuItems() const {

    // Output report heading
    showHeading("Menu Items", "──┬─");

    for (size_t i = 0; i < menu.size(); i++) {
        cout << *menu[i];
        printSeparator(i == menu.size() - 1 ? "  └─" : "  ├─");
    }
}

void PosSystem::printMenu() const {

    int indentWidth = 4; // indentText.length(); <-- Unicode character are not accounted for in .length()
    int rightColumnWidth = 7;
    int colWidths[] = {79-indentWidth-rightColumnWidth, rightColumnWidth};

    // Output report heading
    showHeading("\nMenu Items", "──┬─", false);

    cout << left << setprecision(2) << fixed
         << indentText << setw(colWidths[0]) << "Item" << setw(colWidths[1]) << "Price" << endl;

    for (size_t i = 0; i < menu.size(); i++) {
        cout << left << setfill('.') << indentText << setw(colWidths[0])
            << (to_string(i + 1) + ". " + menu[i]->getName())
            << "$" << right << setfill(' ') << setw(colWidths[1]) << menu[i]->getSalePrice() << endl;
    }

    printSeparator("  └─");

}

void PosSystem::listOrders() const {

    int indentWidth = 4; // indentText.length(); <-- Unicode character are not accounted for in .length()
    int rightColumnWidth = 7;
    int colWidths[] = {4, 75-indentWidth-rightColumnWidth, rightColumnWidth};

    // Loop over orders
    for (size_t i = 0; i < orders.size(); i++) {

        // Output report heading
        showHeading("\nOrder for " + orders[i]->getCustomerName() , "──┬─", false);
        auto items = orders[i]->getLineItems();

        for (size_t i = 0; i < items.size(); i++) {
            auto lineItem = items[i];

            cout << left << indentText << setfill(' ') << setw(colWidths[0]) << ("(" + to_string(lineItem->getQuantity()) + ")")
                << setfill('.') << setw(colWidths[1]) << lineItem->getName()
                << "$" << right << setfill(' ') << setw(colWidths[2]) << lineItem->getPrice() << endl;
        }

        printSeparator("  └─");

        cout << string(indentWidth, ' ') << left
            << setfill('.') << setw(colWidths[0] + colWidths[1]) << "Total"
            << "$"
            << setfill(' ') << setw(colWidths[2]) << right << orders[i]->getTotalRevenue() << endl;

    }
}

double PosSystem::getDailySalesCosts() const {
    double totalCost = 0.0;
    for (size_t i = 0; i < orders.size(); i++) {
        totalCost += orders[i]->getTotalCost();
    }

    return totalCost;
}

double PosSystem::getDailySalesRevenue() const {
    double totalRevenue = 0.0;
    for (size_t i = 0; i < orders.size(); i++) {
        totalRevenue += orders[i]->getTotalRevenue();
    }

    return totalRevenue;
}

double PosSystem::getDailySalesProfit() const {
    double totalProfit = 0.0;
    for (size_t i = 0; i < orders.size(); i++) {
        totalProfit += orders[i]->getTotalProfit();
    }

    return totalProfit;
}

vector<double> PosSystem::getDailyItemProfits() const {
    // Storage for item profits
    vector<double> itemProfits(menu.size(), 0.0);

    // Loop over orders
    for (size_t j = 0; j < orders.size(); j++) {
        // Order line item reference to improve readability
        auto items = orders[j]->getLineItems();

        /// Loop over line items in the order
        for (size_t k = 0; k < items.size(); k++) {
            // Reference for readability
            LineItem *lineItem = items[k];

            // Get the oridinal of the menu item in the menu list
            int menuItemIndex = getMenuItemIndex(lineItem->getName());

            // Store profit for the item using the menu item index
            itemProfits[menuItemIndex] += lineItem->getProfit();
        }
    }

    // Return item profits
    return itemProfits;
}
