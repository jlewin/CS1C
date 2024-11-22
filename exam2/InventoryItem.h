#ifndef InventoryItem_H
#define InventoryItem_H

#include <iostream>
#include "Screen.h"

using namespace std;

class InventoryItem
{
    public:
        InventoryItem();

        // Virtual functions
        virtual ~InventoryItem();
        virtual void print(ostream& os) const;

        bool getCheckedOut() const;
        void setCheckedOut(bool);

        string getID() const;

        friend ostream& operator<<(ostream&, const InventoryItem&);

        static void setIndentText(string);
        static int getInstanceCount();

    protected:
        // Helper method to produce name slug from text
        void setNormailzedName(string name);
        string name;
        string description;
        string id;
        string indent() const;
        static int titleWidth;
        
    private:
        bool checkedOut;
        static string indentText;
        static int instanceCount;
};

#endif
