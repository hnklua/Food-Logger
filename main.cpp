#include "userData.hpp"
#include "readCSV.hpp"
#include "foodHash.hpp"
#include <unordered_map>

int main(int, char**) {
    // Message for program 
    cout << "Welcome to the Nutritional Logger!" << endl; 
    // Load CSV file and initialize hashtable 
    foodHash myFoodHash; 
    readCSV("nutrients_csvfile.csv", myFoodHash); 

    // User Choice 
    int choice; 

    // Initiate User Data and collect user data
    userData myUserData; 
    string foodName; 
    auto it = myFoodHash.find(foodName); 

    // Main Loop
    while (true) {
        // Menu Options
        cout << "Select an option" << endl; 
        cout << "1. Enter user information" << endl; 
        cout << "2. Enter nutrional calculator" << endl; 
        cout << "3. Display User Information" << endl;
        cout << "4. Display Nutritional Intake" << endl; 
        cout << "5. Debugging Purposes: Search for key" << endl; 
        cout << "6. Exit Program" << endl; 
        cin >> choice; 
        cin.ignore(); 

        switch (choice)
        {
        case 1:
            myUserData.setHeight();
            myUserData.setWeight(); 
            break;
        case 2: 
            cout << "Enter the name of the food that you ate: "; 
            // cin >> foodName; 
            getline(cin, foodName); 
            foodName = trim(foodName); 
            //foodName = toLowerCase(foodName); 

            cout << "The food name entered was: " << foodName << endl; 
            
            if (it != myFoodHash.getTable().end()) {
                // Access food item
                const FoodItem& foodItem = it->second; 
                // Pass in nutrtional information 
                myUserData.setNutritionalIntake(foodItem); 
                cout << "Nutrional Information added!" << endl; 
            } else {
                cout << "Food item not found" << endl; 
                // Debugging
                cout << "Food name entered: " << foodName << endl; 
            }
            break; 
        case 3: 
            cout << "Height: " << myUserData.getHeight() << " cm" << endl; 
            cout << "Weight: " << myUserData.getWeight() << " lbs" << endl; 
            break; 
        case 4: 
            cout << "Total Calories: " << myUserData.getTotalCalories() << endl; 
            cout << "Total Protien: " << myUserData.getTotalProtein() << " g" << endl; 
            cout << "Total Fat: " << myUserData.getTotalFat() << " g" << endl; 
            cout << "Total Saturated Fat: " << myUserData.getTotalSaturatedFat() << " g" << endl;
            cout << "Total Fiber: " << myUserData.getTotalFiber() << " g" << endl; 
            cout << "Total Carbs: " << myUserData.getTotalCarbs() << " g" << endl; 
            break; 
        case 5: 
            cout << "Enter the key of the food to search: "; 
            getline(cin, foodName); 

            // Trim whitespace and convert to lowercase
            foodName = trim(foodName);
            foodName = toLowerCase(foodName);

            if (myFoodHash.searchFood(foodName)) {
                cout << "Food item found: " << foodName << endl;
            } else {
                cout << "Food item not found" << endl;
            }
            break;
        case 6: 
            return 0;
            break;
        default:
            cout << "Invalid Option" << endl; 
            break;
        }    
    }
}

// End of main