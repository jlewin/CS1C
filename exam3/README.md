CS1C - Final Project - Point of Sale System for a Restaurant

## Overall Approach
To implement the solution for the given problem, the requirements were analyzed, modeled and sketched out on paper, and iterated on until all points were addressed. A number of specialized types were determined to be needed to produce a viable solution, which are depicted in the uml diagram below, as well as other supporting helper classes outlined in the `Files Overview` section. During implementation numerous  revisions were needed to address missing or misunderstood requirements, or to implement improvements and enhancements, and the process of implementing, testing, debugging, and iterating occurred through the lifetime of the project. Although a simple main function is described which must only run a predfined set of operations, a full menu system with interactive reports, and order entry was created to both verify and build out the system, and to test and validate the design during development. In the final stages this more indepth solution was removed, to match the requirements explicity stated in the output section which disallow interactivity. Finally, instrumentation of classes with instanceCounts was performed to track intialization and find and resolve memory leaks where they cropped up, and verbose logging can be toggled on and off to track instant lifetimes.

## Point of Sale Sytem Model & API
   ![Image](../out/exam3/uml/types/PosSystem/PosSystem.png)

## Files Overview

1. **Main.cpp**:
   - Contains the main function, the main entrypoint for the application, which initializes the PosSystem, application state, and displays the requested reports and demonstrates application requirements.

1. **CustomerOrder.cpp**:
   - Implements the CustomerOrder class, which manages customer orders, including adding items, calculating total costs, revenues, and profits, and managing the lifecycle of LineItem objects.

1. **LineItem.cpp**:
   - Implements the LineItem class, which represents individual items in a customer order, including methods to get item details like name, quantity, cost, price, and profit.

1. **MenuItem.cpp**:
   - Implements the MenuItem class, which represents items on the menu, including methods to get and set item details like name, cost, sale price, and profit.

1. **PosSystem.cpp**:
   - Implements the PosSystem class, which manages the overall point-of-sale system, including adding orders and menu items, listing orders and menu items, and generating daily sales reports.

1. **Screen.cpp**:
   - Contains utility functions for displaying text on the screen, including functions for colorizing text, displaying headings, handling user input, and clearing the screen.

----

1. **MainMenu.cpp**:
   - Contains the main function, the main entrypoint for the application, which initializes the PosSystem and application state, displays the main menu, and handles user input to perform various actions like listing menu items, adding orders, and generating reports. This was the more involved solution as an interactive application, included for reference only.

1. **MockState.cpp**:
   - Implements the MockState class, which provides methods to initialize the application state with mock data, including loading menu items and customer orders into the PosSystem.
