#ifndef MovieItem_H
#define MovieItem_H

#include <iostream>
#include <vector>
#include "InventoryItem.h"

using namespace std;

class MovieItem : public InventoryItem
{
    public:
        MovieItem();
        friend ostream& operator<<(ostream&, const MovieItem*);
        int static getInstanceCount();

    private:
        static int instanceCount;
        string title;
        string directory;
        vector<string> mainActors;
};

#endif
