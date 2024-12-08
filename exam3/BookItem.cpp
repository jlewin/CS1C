#include <iostream>
#include <string>
#include <iomanip>
#include "BookItem.h"

using namespace std;

int BookItem::instanceCount = 0;

BookItem::BookItem() {
    instanceCount++;
}

BookItem::BookItem(const string& id, const string& desc, const string& title, const string& author, const string& copyrightDate) {
    setNormailzedName(title);

    this->id = id;
    this->title = title;
    this->description = desc;
    this->author = author;
    this->copyrightDate = copyrightDate;
    instanceCount++;
}

void BookItem::print(ostream& os) const {
    InventoryItem::print(os);
    
    os << indent() << headingText("Book Details ------------------------------") << endl;
    os << indent() << setw(titleWidth) << "Title" << title << endl;
    os << indent() << setw(titleWidth) << "Author" << author << endl;
    os << indent() << setw(titleWidth) << "Copyright Date" << copyrightDate << endl;
}

int BookItem::getInstanceCount() {
    return instanceCount;
}