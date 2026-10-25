#include "GroceryTracker.h"
#include <iostream>
#include <limits>
#include <string>

int main() {
    GroceryTracker tracker;

    // Load the purchase list and create the backup file before showing the menu.
    if (!tracker.LoadItems("storeinputfile.txt")) {
        std::cerr << "Could not load the input file. Check its name and location.\n";
        return 1;
    }

    if (!tracker.SaveFrequencyData("frequency.dat")) {
        std::cerr << "Could not create frequency.dat.\n";
        return 1;
    }

    int choice = 0;

    // Keep showing the menu until the user chooses option 4.
    while (true) {
        std::cout << "\nCorner Grocer Menu\n";
        std::cout << "1. Find an item's frequency\n";
        std::cout << "2. Print all item frequencies\n";
        std::cout << "3. Print a frequency histogram\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please enter a number from 1 to 4.\n";
            continue;
        }

        // Clear the rest of the menu-choice line.
        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
        case 1: {
            std::string itemName;
            std::cout << "Enter the item name: ";
            std::getline(std::cin, itemName);

            std::cout << itemName << " appears "
                << tracker.GetFrequency(itemName) << " time(s).\n";
            break;
        }
        case 2:
            tracker.PrintFrequencies();
            break;
        case 3:
            tracker.PrintHistogram();
            break;
        case 4:
            std::cout << "Goodbye!\n";
            return 0;
        default:
            std::cout << "Please choose an option from 1 to 4.\n";
        }
    }
}