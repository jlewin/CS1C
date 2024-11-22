#include <iostream>
#include <fstream>
#include <iomanip>
#include "InventoryManager.h"
#include "BookItem.h" 
#include "MagazineItem.h" 
#include "MovieItem.h" 

#include "json.hpp"

using json = nlohmann::json;
using namespace std;

void loadInventory(InventoryManager& libraryInventory) {
    std::ifstream f("data.json");
    json data = json::parse(f);

    int i = 0;
    for (auto& book : data["books"]) {
        libraryInventory[0].addItem(
            new BookItem(
                book["isbn"],        // The isbn is a decent item identifier
                book["description"], 
                book["title"],
                book["author"],
                book["published"]),  // Imagine the published date is the copyright date
            i++);
    }

    i = 0;
    for (auto& magazine : data["magazines"]) {
        libraryInventory[1].addItem(
            new MagazineItem(
                magazine["issn"],        // The issn is a decent item identifier
                magazine["description"], 
                magazine["title"],
                magazine["issue"]),
            i++);
    }

    i = 0;
    for (auto& movie : data["movies"]) {

        auto actors = movie["main_actors"];
        auto gah = actors.get<vector<string>>();

        libraryInventory[2].addItem(
            new MovieItem(
                movie["id"],
                movie["description"], 
                movie["title"],
                movie["director"],
                gah),
            i++);
    }
}


int main() {
    InventoryManager libraryInventory;
    loadInventory(libraryInventory);

    cout << "Library Inventory instance count: " << InventoryManager::getInstanceCount() << endl;
    cout << libraryInventory << endl;

    return 0;
}
