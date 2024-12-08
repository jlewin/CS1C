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
        MovieItem(const string& id, const string& desc, const string& title, const string& director, const vector<string> mainActors);
        void print(std::ostream& os) const override;
        int static getInstanceCount();

    private:
        static int instanceCount;
        string title;
        string director;
        vector<string> mainActors;
};

#endif
