#ifndef InventoryItem_H
#define InventoryItem_H

#include <iostream>

using namespace std;

class InventoryItem
{
    public:
        InventoryItem();
        InventoryItem(const string&, const string&, const string&);
    
        friend ostream& operator<<(ostream&, const InventoryItem*);

        int static getInstanceCount();

        bool getCheckedOut() const;
        void setCheckedOut(bool);
    
    protected:
        string name;
        string description;
        string id;
        
    private:
        bool checkedOut;
        static int instanceCount;
};

#endif
