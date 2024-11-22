#include <iostream>
#include <iomanip>
#include "MagazineItem.h"

using namespace std;

int MagazineItem::instanceCount = 0;

MagazineItem::MagazineItem() {
    instanceCount++;
}

MagazineItem::MagazineItem(const string& id, const string& desc, const string& title, const string& edition) {
    // Base members
    setNormailzedName(title);
    this->id = id;
    this->description = desc;

    this->title = title;
    this->edition  = edition;
    instanceCount++;
}

void MagazineItem::print(ostream& os) const {
    InventoryItem::print(os);
    
    os << indent() << Screen::heading("Magazine Details ------------------------------") << endl;
    os << indent() << setw(titleWidth) << "Title" << title << endl;
    os << indent() << setw(titleWidth) << "Edition" << edition << endl;
}

int MagazineItem::getInstanceCount() {
    return instanceCount;
}