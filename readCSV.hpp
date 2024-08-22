#pragma once
#include "foodHash.hpp"
#include <string> 
#include <fstream>
#include <sstream> 
#include <vector>
#include <stdexcept>
#include <iostream>
#include <cctype>
#include <algorithm>
using namespace std; 

// Utility function to convert a string to an interger with error checking 
// Int function 
// Parameters: const string& str 
int safeStoi(const string& str) {
    if (str == "t") return 0; 
    try {
        return stoi(str); 
    } catch (const invalid_argument& e) {
        return 0; 
    }
}

// Trim function to remove leading and trailing spaces
string trim(const string& str) {
    size_t first = str.find_first_not_of(' ');
    if (first == string::npos)
        return "";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, last - first + 1);
}

// Function to convert a string to lowercase
string toLowerCase(const string& str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), [](unsigned char c){ return tolower(c); });
    return lowerStr;
}

// Function that reads from the csv file, and parses contents into hashtable 
// Void function
// Parameters: const string of the filename, and a hashmap from the foodHash object
void readCSV(const string& filename, foodHash& hashtable) {
    ifstream file(filename); 
    if (!file.is_open()) {
        throw runtime_error("Unable to open file: " + filename); 
    }

    string line; 
    while(getline(file, line)) {
        stringstream ss(line); 
        string token;
        vector<string> tokens; 
        bool insideQuote = false; 
        string currentToken; 
        // Debugging 
        //int lineCount = 0; 

        for (char c : line) {
            if (c == '"') {
                insideQuote = !insideQuote; 
            } else if (c == ',' && !insideQuote) {
                tokens.push_back(trim(currentToken)); 
                currentToken.clear(); 
            } else { 
                currentToken += c; 
            }
        }
        tokens.push_back(trim(currentToken));; // Add last token 

        if (tokens.size() != 10) {
            throw runtime_error("Invaid CSV file format: " + filename); 
        }

        // Extrat data from food log csv file 
        string foodName = tokens[0]; 
        string measure = tokens[1]; 
        int grams = safeStoi(tokens[2]);
        int calories = safeStoi(tokens[3]);
        int protein = safeStoi(tokens[4]);
        int fat = safeStoi(tokens[5]);
        int saturatedFat = safeStoi(tokens[6]);
        int fiber = safeStoi(tokens[7]);
        int carbs = safeStoi(tokens[8]);
        string category = tokens[9];

        // Istantiate food item object and insert into unordered map 
        FoodItem items(foodName, measure, grams, calories, protein, fat, saturatedFat, fiber, carbs, category);
        hashtable.insert(foodName, items); 

        // Debugging Purposes 
        /*if (lineCount < 5 || lineCount % 100 == 0) {
            cout << "Inserted food item: " << foodName << endl;
        }
        lineCount++;*/
    }
} 

// End of readCSV header file