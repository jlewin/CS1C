#include <iostream>
#include <fstream>
#include <iomanip>
#include "MenuItem.h" 
#include "Screen.h"
#include "constants.h"
#include "PosSystem.h"
#include "MockState.h"

// #include "json.hpp"
// using json = nlohmann::json;
//void loadJsonInventory(InventoryManager&);

/*

    Store
        Orders [
        {
            items: [
                    {'MenuItem, quantity}, ...
            ]
        Menu [MenuItems],
        reports...

*/

using namespace std;

int main()
{
    // TODO: Implement the authentication system
    string activeUser = "jlewin";

    auto& options = FormattingOptions::getInstance();

    bool choiceValid = true;
    char choice = ' ';
    string notifyMessage = "";

    PosSystem posSystem;

    MockState mockState;
    mockState.initAppState(posSystem);
    
    // Disable so that the json dependency is not required (and thus 3rd party libraries)
    //loadJsonInventory(libraryInventory);

    do
    {
        initMenu("Restaurant Point of Sale System");
        cout << " 1. Report - Menu Items" << endl;
        cout << " 2. List Daily Orders" << endl;
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
                
        // Collect user input and update exit condition variable
        switch (choice = getMenuChoice())
        {
        case '1':
        {   
            posSystem.listMenuItems();
            pauseForEnter();           
            break;
        }
        case '2':
            posSystem.listOrders();
            pauseForEnter();
            break;
        case '3':
        {
            
        }
            break;

        case '4':
        case '5':
        {
        }
            break;
        case '6':
        {
        }
            break;
        case '7':
        {
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
