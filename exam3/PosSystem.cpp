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
    // Output report heading
    showHeading("Menu Items", "──┬─");

    cout << indentText << setw(titleWidth) << "Name"
       << setw(titleWidth) << "Cost"
       << setw(titleWidth) << "Sale Price"
       << setw(titleWidth) << "Profit" << endl;

    for (size_t i = 0; i < menu.size(); i++) {
        cout << indentText << setw(titleWidth) << menu[i]->getName()
            << setw(titleWidth) << menu[i]->getCost()
            << setw(titleWidth) <<  menu[i]->getSalePrice()
            << setw(titleWidth) <<  menu[i]->getItemProfit() << endl;
    }

    printSeparator("  └─");

}

void PosSystem::listOrders() const {
    for (size_t i = 0; i < orders.size(); i++) {
        cout << orders[i];
        cout << "---------------------" << endl;
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
