// Name: Jenna
// Date: October 16, 2026
// Description: Declares the class that tracks grocery item counts.

#pragma once

#include <map>
#include <string>

class GroceryTracker {
public:
    bool LoadItems(const std::string& inputFile);
    bool SaveFrequencyData(const std::string& outputFile) const;
    int GetFrequency(const std::string& itemName) const;
    void PrintFrequencies() const;
    void PrintHistogram() const;

private:
    std::map<std::string, int> itemFrequencies;
};