#pragma once 
#include <iostream> 
#include <exception>
#include <cassert>
#include "foodItem.hpp"
using namespace std; 

class userData {
private:
    // Attributes
    int Height; 
    int Weight; 
    int totalCalories; 
    int totalProtein; 
    int totalFat; 
    int totalSaturatedFat; 
    int totalFiber; 
    int totalCarbs; 

public:
    // User Data Constructor
    userData(int h = 0, int w = 0) 
        : Height(h), Weight(w), totalCalories(0), totalProtein(0), totalFat(0), totalSaturatedFat(0), totalFiber(0), totalCarbs(0) {}

    // Getters 
    int getHeight() const { return Height; }
    int getWeight() const { return Weight; }
    int getTotalCalories() { return totalCalories; }
    int getTotalProtein() { return totalProtein; }
    int getTotalFat() { return totalFat; }
    int getTotalSaturatedFat() { return totalSaturatedFat; }
    int getTotalFiber() { return totalFiber; }
    int getTotalCarbs() { return totalCarbs; }
    
    // Setters 
    void setHeight() {
        cout << "Enter height (in CM): ";
        cin >> Height; 
    }
    void setWeight() {
        cout << "Enter Weight (in Pounds): "; 
        cin >> Weight; 
    }
    void setNutritionalIntake(const FoodItem& item) {
        totalCalories += item.getCalories(); 
        totalProtein += item.getProtien(); 
        totalFat += item.getFat(); 
        totalSaturatedFat += item.getSaturatedFat(); 
        totalFiber += item.getFiber(); 
        totalCarbs += item.getCarbs(); 
    }
}; 

// End of userData header file