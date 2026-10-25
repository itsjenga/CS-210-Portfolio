// Name: Jenna
// Date: October 18, 2026
// Description: Reads grocery items and saves their frequencies.

#include "GroceryTracker.h"
#include <fstream>
#include <iostream>
#include <string>

// Reads grocery items from the input file and counts them.
bool GroceryTracker::LoadItems(const std::string& inputFile) {
    std::ifstream input(inputFile);

    if (!input.is_open()) {
        return false;
    }

    std::string itemName;

    while (std::getline(input, itemName)) {
        if (!itemName.empty()) {
            ++itemFrequencies[itemName];
        }
    }

    return !itemFrequencies.empty();
}

// Saves each item and its count to the backup file.
bool GroceryTracker::SaveFrequencyData(
    const std::string& outputFileName) const {
    std::ofstream outFile(outputFileName);

    if (!outFile) {
        return false;
    }

    for (const auto& item : itemFrequencies) {
        outFile << item.first << " " << item.second << '\n';
    }

    return static_cast<bool>(outFile);
}

// Add this function below SaveFrequencyData.
int GroceryTracker::GetFrequency(const std::string& itemName) const {
    const auto item = itemFrequencies.find(itemName);

    if (item != itemFrequencies.end()) {
        return item->second;
    }

    return 0;
}  // This closes GetFrequency.
// Prints each item and its frequency.
void GroceryTracker::PrintFrequencies() const {
    for (const auto& item : itemFrequencies) {
        std::cout << item.first << " " << item.second << '\n';
    }
}
// Prints a row of asterisks for each item's frequency.
void GroceryTracker::PrintHistogram() const {
    for (const auto& item : itemFrequencies) {
        std::cout << item.first << " ";

        for (int i = 0; i < item.second; ++i) {
            std::cout << '*';
        }

        std::cout << '\n';
    }
}