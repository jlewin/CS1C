#include <iostream>
#include <iomanip>
#include "InventoryItem.h"

using namespace std;

int InventoryItem::instanceCount = 0;
string InventoryItem::indentText = "    │ ";
int InventoryItem::titleWidth = 16;

InventoryItem::InventoryItem() {
    instanceCount++;

}

InventoryItem::~InventoryItem() {
    instanceCount--;
}

string InventoryItem::indent() const {
    return indentText;
}

string limitWidth(string text, size_t width) {
    if (text.length() > width) {
        return text.substr(0, width - 3) + "...";
    }

    return text;
}

bool InventoryItem::getCheckedOut() const {
    return checkedOut;
}

void InventoryItem::setCheckedOut(bool isCheckedOut) {
    checkedOut = isCheckedOut;
}

void InventoryItem::print(std::ostream& os) const {
    os << left
       << indent() << setw(titleWidth) << "Status" << (checkedOut ? "Checked Out" : "Avaiable") << endl
       << indent() << setw(titleWidth) << "ID" << id << endl
       << indent() << setw(titleWidth) << "Name" << name << endl
       << indent() << setw(titleWidth) << "Description" << limitWidth(description, 85) << endl;
}

void InventoryItem::setIndentText(string text) {
    indentText = text;
}

// Copy the passed string and replace spaces with dashes
void InventoryItem::setNormailzedName(string title) {
    // Replace all spaces with dashes for the name property
    std::replace(title.begin(), title.end(), ' ', '-');

    this->name = title;
}

string InventoryItem::getID() const {
    return id;
}

ostream& operator<<(ostream& outstream, const InventoryItem &item) {
    item.print(outstream);

    return outstream;
}


int InventoryItem::getInstanceCount() {
    return instanceCount;
}