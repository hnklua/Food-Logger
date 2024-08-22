#pragma once 
#include "foodItem.hpp"
#include <unordered_map>
#include <algorithm>

class foodHash {
private:
    // Hash table
    unordered_map<string, FoodItem> table; 
public: 
    // Insert food items into hashtable 
    void insert(const string& key, const FoodItem& item) {
        table[key] = item; 
    }
    // Lookup food items in hashtable
    auto find(const string& key) {
        return table.find(key); 
    }

    // Debugging: Search for key 
    bool searchFood(const std::string& foodName) {
    string lowerFoodName = foodName;
    transform(lowerFoodName.begin(), lowerFoodName.end(), lowerFoodName.begin(), ::tolower);
    return table.find(lowerFoodName) != table.end();
}   
    
    // Accessor function to get the table
    const unordered_map<string, FoodItem>& getTable() const {
        return table;
    }
}; 
// End of foodHash header file 