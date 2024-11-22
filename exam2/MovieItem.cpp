#include <iostream>
#include <iomanip>
#include "MovieItem.h"

using namespace std;

int MovieItem::instanceCount = 0;

MovieItem::MovieItem() {
    instanceCount++;
}

MovieItem::MovieItem(const string& id, const string& desc, const string& title, const string& director, const vector<string> mainActors) {
    // Base members
    setNormailzedName(title);
    this->id = id;
    this->description = desc;

    this->title = title;
    this->director  = director;
    this->mainActors = mainActors;

    instanceCount++;
}

void MovieItem::print(ostream& os) const {
    InventoryItem::print(os);
    
    os << indent() << headingText("Movie Details ------------------------------") << endl;
    os << indent() << setw(titleWidth) << "Title" << title << endl;
    os << indent() << setw(titleWidth) << "Director" << director << endl;
    os << indent() << setw(titleWidth) << "Main Actors";
    for (size_t i = 0; i < mainActors.size(); i++) {
        os << mainActors[i] << (i < mainActors.size() - 1 ? ", " : "");
    }
    os << endl;
}


int MovieItem::getInstanceCount() {
    return instanceCount;
}