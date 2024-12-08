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


    private:
        vector<CustomerOrder*> orders;
        vector<MenuItem> menu;

        string title;
        string author;
        string copyrightDate;
};
#endif
