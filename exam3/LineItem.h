#ifndef LineItem_H
#define LineItem_H

#include "MenuItem.h"

class LineItem
{
    public:
        LineItem(const MenuItem& menuItem, int quantity);
        friend ostream& operator<<(ostream&, const LineItem*);
        static int getInstanceCount();
        string indent() const;
        
    private:
        static int titleWidth;
        static string indentText;
        static int instanceCount;
        void print(ostream&) const;

    private:
        MenuItem menuItem;
        int quantity;
};

#endif
