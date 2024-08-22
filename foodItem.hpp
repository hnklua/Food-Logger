#pragma once 
#include <string>
#include <exception>
using namespace std; 

class FoodItem {
private: 
    // Attributes
    string foodName; 
    string measure; 
    int grams; 
    int calories; 
    int protein; 
    int fat; 
    int saturatedFat; 
    int fiber; 
    int carbs; 
    string category; 
public: 
    // Constructor 
    FoodItem();
    FoodItem(const string& FoodName, const string& Measure, int Grams, int Calories, int Protein, int Fat, int SaturatedFat, 
         int Fiber, int Carbs, const string& Category);
    
    // Getters 
    int getCalories() const { return calories; } 
    int getProtien() const { return protein; }
    int getFat() const { return fat; }
    int getSaturatedFat() const { return saturatedFat; }
    int getFiber() const { return fiber; }
    int getCarbs() const { return carbs; }
    
}; 
    // Default Constructor 
    FoodItem::FoodItem() : grams(0), calories(0), protein(0), fat(0), saturatedFat(0), fiber(0), carbs(0) {}

    // Initialized Constructor
    FoodItem::FoodItem(const string& FoodName, const string& Measure, int Grams, int Calories, int Protein, int Fat, int SaturatedFat, 
        int Fiber, int Carbs, const string& Category) : foodName(FoodName), measure(Measure), grams(Grams), calories(Calories), 
        protein(Protein), fat(Fat), saturatedFat(SaturatedFat), fiber(Fiber), carbs(Carbs), category(Category) {}
 
// End of foodItem header file


