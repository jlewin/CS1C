#ifndef BookItem_H
#define BookItem_H

#include "InventoryItem.h"

using namespace std;

class BookItem : public InventoryItem
{
    public:
        BookItem();
        BookItem(const string& id, const string& desc, const string& title, const string& author, const string& copyrightDate);
        void print(std::ostream& os) const override;
        int static getInstanceCount();

    private:
        static int instanceCount;
        string title;
        string author;
        string copyrightDate;
};

#endif
