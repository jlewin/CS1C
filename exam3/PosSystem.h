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
        CustomerOrder& createOrder(const string&);

        // LibraryShelf& operator[](int index) const;
        // LibraryShelf& operator[](int index);

        friend ostream& operator<<(ostream&, const PosSystem&);

        void listOrders() const;
        void listMenuItems() const;

        void addMenuItem(const string& name, double cost, double salePrice);
        CustomerOrder* addOrder(const string& customerName);
        void addOrderItem(CustomerOrder* order, const string& name, int quantity);
        const MenuItem* getMenuItem(const string& name) const;

    private:
        vector<CustomerOrder*> orders;
        vector<MenuItem> menu;

        string title;
        string author;
        string copyrightDate;
};
#endif
