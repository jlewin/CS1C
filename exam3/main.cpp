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

// #include "json.hpp"
// using json = nlohmann::json;
//void loadJsonInventory(InventoryManager&);

using namespace std;

bool getCompartment(const string&, InventoryManager&, int&, int&);
void loadSimpleInventory(InventoryManager& libraryInventory);
string getDueDate(int days);

int main()
{
    // TODO: Implement the authentication system
    string activeUser = "jlewin";

    auto& options = FormattingOptions::getInstance();

    bool choiceValid = true;
    char choice = ' ';
    string notifyMessage = "";

    // Increment var
    int inc = 1;

    InventoryManager libraryInventory;
    loadSimpleInventory(libraryInventory);
    // Disable so that the json dependency is not required (and thus 3rd party libraries)
    //loadJsonInventory(libraryInventory);

    do
    {
        initMenu("Library Inventory Management System");
        cout << " 1. Add an item" << endl;
        cout << " 2. Checkout an item" << endl;
        cout << " 3. Checkin an item" << endl;
        cout << " 4. Print checked-in items (items in storage)" << endl;
        cout << " 5. Print checked-out items" << endl;
        cout << " 6. Swap items" << endl;
        cout << " 7. Print all storage" << endl;
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
                // Increment the item id
                string n = to_string(inc++);

                // Use the required indexing syntax
                if (libraryInventory[shelf][compartment] == nullptr) {
                    libraryInventory[shelf].addItem(new BookItem( "id-" + n, "description-" + n, "title-" + n, "author-" + n, "na"), compartment);
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
                    if (setCheckedOut) {
                        string dueDate = getDueDate(21);
                        item->checkoutItem(dueDate, activeUser);
                    } else {
                        item->checkinItem();
                    }
                }
            }
        }
            break;

        case '4':
        case '5':
        {
            // Too much visibility state, loop back and clean up...
            options.showAllItems = false;
            options.showEmptyCompartments = false;
            
            options.showCheckedInOnly = choice == '4';
            options.showCheckedOutOnly = choice == '5';

            initMenu(options.showCheckedInOnly ? "Checked In Items" : "Checked Out Items");
            cout << libraryInventory << endl;
            pauseForEnter();
        }
            break;
        case '6':
        {
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
                    libraryInventory.swapItems(shelf, compartment, shelfIndex2, compartmentIndex2);
                    InventoryItem* temp = c1;
                    c1 = c2;
                    c2 = temp;
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

string getDueDate(int days) {
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    tm.tm_mday += days;
    std::mktime(&tm); // Normalize the time structure
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d");

    string dueDate = oss.str();
    return dueDate;
}

void loadSimpleInventory(InventoryManager& libraryInventory) {

    libraryInventory.addItem(0, 0,
        new BookItem(
            "978-3-16-148410-0",        // Mock ISBN
            "An adventurous journey through programming concepts.", // Mock description
            "Adventures in C++",        // Mock title
            "John Doe",                 // Mock author
            "2024-01-01"));             // Mock published date

    libraryInventory.addItem(0, 1,
        new BookItem(
            "978-0-13-235088-4",        // Mock ISBN
            "A practical guide to clean code practices.",           // Mock description
            "Clean Code",               // Mock title
            "Robert C. Martin",         // Mock author
            "2008-08-01"));             // Mock published date

    libraryInventory.addItem(0, 2,
        new BookItem(
            "978-1-59327-584-6",        // Mock ISBN
            "An engaging introduction to algorithms.",              // Mock description
            "The Algorithm Design Manual", // Mock title
            "Steven S. Skiena",         // Mock author
            "2020-10-15"));             // Mock published date

    libraryInventory.addItem(1, 0,
        new MagazineItem(
            "1234-5678",        // Mock ISSN
            "Exploring the latest advancements in AI technology.", // Mock description
            "AI Monthly",       // Mock title
            "2024-11"));        // Mock issue

    libraryInventory.addItem(1, 1,
        new MagazineItem(
            "9876-5432",        // Mock ISSN
            "A deep dive into space exploration and astronomy.",  // Mock description
            "Cosmos Today",     // Mock title
            "2024-10"));        // Mock issue

    libraryInventory.addItem(1, 2,
        new MagazineItem(
            "1122-3344",        // Mock ISSN
            "All the trends and tips in modern software development.", // Mock description
            "Dev Weekly",       // Mock title
            "2024-09"));        // Mock issue

    libraryInventory.addItem(2, 0,
        new MovieItem(
            "MOV12345",           // Mock ID
            "A thrilling tale of survival on a distant planet.",  // Mock description
            "Lost in the Stars",  // Mock title
            "Jane Smith",         // Mock director
            {"Chris Pine", "Zoe Saldana", "Idris Elba"})); // Mock main actors

    libraryInventory.addItem(2, 1,
        new MovieItem(
            "MOV67890",           // Mock ID
            "An epic battle between humans and AI for the future of Earth.", // Mock description
            "Machine Wars",       // Mock title
            "John Carpenter",     // Mock director
            {"Keanu Reeves", "Scarlett Johansson", "Tom Hardy"})); // Mock main actors

    libraryInventory.addItem(2, 2,
        new MovieItem(
            "MOV54321",           // Mock ID
            "A heartwarming story of a robot learning what it means to be human.", // Mock description
            "Metal Heart",        // Mock title
            "Steven Spielberg",   // Mock director
            {"Hugh Jackman", "Emma Stone", "Morgan Freeman"})); // Mock main actors

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

/*
void loadJsonInventory(InventoryManager& libraryInventory) {
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
*/