#ifndef PosSystem_H
#define PosSystem_H

#include <iostream>
#include "MenuItem.h"
#include "CustomerOrder.h"

using namespace std;

class PosSystem
{
    public:
        PosSystem();
        ~PosSystem();

        // Reporting functions - assume primary out is console (consider passing ostream for more control)
        void listOrders() const;
        void listMenuItems() const;
        double getDailySalesCosts() const;
        double getDailySalesRevenue() const;
        double getDailySalesProfit() const;
        vector<double> getDailyItemProfits() const;

        // Default behavior of cout on PosSystem
        friend ostream& operator<<(ostream&, const PosSystem&);

        // Order functions
        CustomerOrder* addOrder(const string& customerName);
        void addOrderItem(CustomerOrder* order, const string& name, int quantity);

        // MenuItem functions
        void addMenuItem(const string& name, double cost, double salePrice);

        // Get menu item by name
        const MenuItem* getMenuItem(const string& name) const;

        // Get menu item by index
        const MenuItem* getMenuItem(const int) const;

        // Get menu item index by name
        int getMenuItemIndex(const std::string& name) const;

    private:
        vector<CustomerOrder*> orders;
        vector<MenuItem*> menu;
};
#endif
