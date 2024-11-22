#include <iostream>
#include <fstream>
#include <iomanip>
#include "InventoryManager.h"
#include "BookItem.h" 
#include "MagazineItem.h" 
#include "MovieItem.h" 
#include "Screen.h"
#include "constants.h"
#include "LibraryShelf.h"

#include "json.hpp"

using json = nlohmann::json;
using namespace std;

bool getCompartment(const string&, InventoryManager&, int&, int&);
void loadInventory(InventoryManager&);

int main()
{
    auto& options = FormattingOptions::getInstance();

    bool choiceValid = true;
    char choice = ' ';
    string notifyMessage = "";

    InventoryManager libraryInventory;
    loadInventory(libraryInventory);

    do
    {
        initMenu("Library Inventory Management System");
        cout << " 1. Add an item" << endl;
        cout << " 2. Checkout an item" << endl;
        cout << " 3. Checkin an item" << endl;
        cout << " 4. Print checked-in items (items in storage)" << endl;
        cout << " 5. Print checked-out items" << endl;
        cout << " 6. Swap items" << endl;
        cout << " 7. Print all items" << endl;
        cout << " 8. Exit\n" << endl;

        // Report on invalid choice
        if (!choiceValid)
        {
            reportChoiceError(choice);
        }

        if (notifyMessage.length() > 0)
        {
            cout << notifyMessage << endl;
            notifyMessage = "";
        }

        // Initialize the error condition
        choiceValid = true;
        int shelf = -1;
        int compartment = -1;
                
        // Collect user input and update exit condition variable
        switch (choice = getMenuChoice())
        {
        case '1':
            if (getCompartment("Add an item", libraryInventory, shelf, compartment)) {
                // Use the required indexing syntax
                if (libraryInventory[shelf][compartment] == nullptr) {
                    libraryInventory[shelf].addItem(new BookItem("Hello", "hello2", "hello3", "hellow4", "hello5"), compartment);
                } else {
                    notifyMessage = "\033[1;94mCompartment is already occupied. Please try again.\033[0m";
                }
            }
            break;
        case '2':
        case '3':
        {
            bool setCheckedOut = choice == '2';
            string title = setCheckedOut ? "Checkout an item" : "Checkin an item";
            if (getCompartment(title, libraryInventory, shelf, compartment)) {
                // Use the required indexing syntax
                if (libraryInventory[shelf][compartment] == nullptr) {
                    notifyMessage = "\033[1;94mCompartment is empty. Please try again.\033[0m";
                } else {
                    // Use the api/interface to change the checked out status
                    InventoryItem* item = libraryInventory[shelf][compartment];
                    item->setCheckedOut(setCheckedOut);
                }
            }
        }
            break;

        case '4':
        case '5':
        {
            options.showCheckedInOnly = choice == '4';
            options.showCheckedOutOnly = choice == '5';
            options.showEmptyCompartments = false;

            initMenu(options.showCheckedInOnly ? "Checked In Items" : "Checked Out Items");
            cout << libraryInventory << endl;
            pauseForEnter();
        }
            break;
        case '6':
        {
            bool setCheckedOut = choice == '2';
            int shelfIndex2 = -1;
            int compartmentIndex2 = -1;

            if (getCompartment("Swap Items - Select Item 1", libraryInventory, shelf, compartment) &&
                getCompartment("Swap Items - Select Item 2", libraryInventory, shelfIndex2, compartmentIndex2)) {
                // Use the required indexing syntax
                InventoryItem* c1 = libraryInventory[shelf][compartment];
                InventoryItem* c2 = libraryInventory[shelfIndex2][compartmentIndex2];

                if (c1 == nullptr || c2 == nullptr) {
                    notifyMessage = "\033[1;94mOne or more compartments are empty. Please try again.\033[0m";
                } else {
                    InventoryItem temp = *c1;

                    // Swap, wouldn't it be nice...
                    *c1 = *c2;
                    *c2 = temp;
                }
            }
        }
            break;
        case '7':
        {
            options.showAllItems = true;
            options.showEmptyCompartments = true;
            initMenu("All Inventory Items");
            cout << libraryInventory << endl;
            pauseForEnter();
        }
            break;
        case '8':
            return 0;
        default:
            choiceValid = false;
            break;
        }
    // Main Menu - loop until exit is called
    } while (true);

    return 0;
}

void loadInventory(InventoryManager& libraryInventory) {
    std::ifstream f("data.json");
    json data = json::parse(f);

    // Loop over books - `i` is the source index and compartment number
    for (size_t i = 0; i < data["books"].size(); i++) {
        auto book = data["books"][i];

        libraryInventory.addItem(0, i,
            new BookItem(
                book["isbn"],        // The isbn is a decent item identifier
                book["description"], 
                book["title"],
                book["author"],
                book["published"]));
    }

    // Loop over magazines - `i` is the source index and compartment number
    for (size_t i = 0; i < data["magazines"].size(); i++) {
        auto magazine = data["magazines"][i];
        libraryInventory.addItem(1, i,
            new MagazineItem(
                magazine["issn"],        // The issn is a decent item identifier
                magazine["description"], 
                magazine["title"],
                magazine["issue"]));
    }

    // Loop over movies - `i` is the source index and compartment number
    for (size_t i = 0; i < data["movies"].size(); i++) {
        auto movie = data["movies"][i];

        libraryInventory.addItem(2, i,
            new MovieItem(
                movie["id"],
                movie["description"], 
                movie["title"],
                movie["director"],
                movie["main_actors"].get<vector<string>>()));
    }
}

bool getCompartment(const string& actionTitle, InventoryManager& libraryInventory, int &shelfNumber, int &compartmentNumber) 
{
    shelfNumber = -1;
    compartmentNumber = -1;
    
    int tempNumber = 0;
    string notifyMessage = "";
    
    do
    {
        initMenu(actionTitle);

        if (notifyMessage.length() > 0)
        {
            cout << notifyMessage << endl;
            notifyMessage = "";
        }

        if (shelfNumber == -1) {
            cout << "Enter Shelf Number: ";
            cin >> tempNumber;
            tempNumber -= 1; // Adjust for 0-based index

            if (tempNumber < 0 || tempNumber >= libraryInventory.getShelfCount())
            {
                notifyMessage = "\033[1;94mInvalid shelf number. Please try again.\033[0m";
            }
            else
            {
                shelfNumber = tempNumber;
            }
        } else if (compartmentNumber == -1) {
            cout << "Enter Compartment Number: ";
            cin >> tempNumber;
            tempNumber -= 1; // Adjust for 0-based index

            if (tempNumber < 0 || tempNumber >= MAX_COMPARTMENTS)
            {
                notifyMessage = "\033[1;94mInvalid compartment number. Please try again.\033[0m";
            }
            else
            {
                compartmentNumber = tempNumber;
            }
        }

    // Menu - loop until exit is called
    } while (compartmentNumber == -1 || shelfNumber == -1);

    return true;
}
