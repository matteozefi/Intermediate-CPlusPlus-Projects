// ==================== UnitConverter.cpp ====================
#include "UnitConverter.h"
#include <iostream>

using namespace std;

UnitConverter::UnitConverter() {
    // Initialize length units (base unit: meter)
    lengthUnits["meter"] = 1.0;
    lengthUnits["kilometer"] = 1000.0;     //each pair corresponds to it's base unit equivalent
    lengthUnits["centimeter"] = 0.01;   
    lengthUnits["millimeter"] = 0.001;
    lengthUnits["inch"] = 0.0254;
    lengthUnits["foot"] = 0.3048;
    lengthUnits["yard"] = 0.9144;
    lengthUnits["mile"] = 1609.34;
    
    // Initialize weight units (base unit: kilogram)
    weightUnits["kilogram"] = 1.0;
    weightUnits["gram"] = 0.001;
    weightUnits["pound"] = 0.453592;
    weightUnits["ounce"] = 0.0283495;
    weightUnits["ton"] = 1000.0;
}

void UnitConverter::displayMenu() {
    cout << "\n=== Unit Converter ===" << endl;
    cout << "1. Length Conversion" << endl;
    cout << "2. Weight Conversion" << endl;
    cout << "3. Temperature Conversion" << endl;
    cout << "4. Exit" << endl;
    cout << "Choose an option: ";
}

void UnitConverter::displayLengthUnits() {
    cout << "Available length units: ";
    for (auto& unit : lengthUnits) {  //auto makes it so the compiler figures out the data type and the colon syntax makes it loop through each item in LengthUnits
        cout << unit.first << " ";  //.first is making it so the first string value of the map is looped aka the unit name
    }           //if we were to use .second we would get the value associated with the unit
    cout << endl;
}

void UnitConverter::displayWeightUnits() {
    cout << "Available weight units: ";
    for (auto& unit : weightUnits) {
        cout << unit.first << " ";
    }
    cout << endl;
}

double UnitConverter::lengthConversion(double value, string from, string to) { //from references the base unit and to is the desired unit
    if (lengthUnits.find(from) == lengthUnits.end() ||  //basic error checking
        lengthUnits.find(to) == lengthUnits.end()) {
        cout << "Invalid unit!" << endl;
        return -1;
    }
    
    // Convert to base unit (meters) first, then to target unit
    double baseValue = value * lengthUnits[from];     
    return baseValue / lengthUnits[to];    
}

double UnitConverter::weightConversion(double value, string from, string to) {
    if (weightUnits.find(from) == weightUnits.end() || 
        weightUnits.find(to) == weightUnits.end()) {
        cout << "Invalid unit!" << endl;
        return -1;
    }
    
    // Convert to base unit (kilograms) first, then to target unit
    double baseValue = value * weightUnits[from];
    return baseValue / weightUnits[to];
}

double UnitConverter::tempConversion(double value, string from, string to) {
    // Convert input to Celsius first
    double celsius;
    if (from == "celsius") {
        celsius = value;
    } else if (from == "fahrenheit") {
        celsius = (value - 32) * 5.0 / 9.0;
    } else if (from == "kelvin") {
        celsius = value - 273.15;
    } else {
        cout << "Invalid temperature unit!" << endl;
        return -1;
    }
    
    // Convert from Celsius to target unit
    if (to == "celsius") {
        return celsius;
    } else if (to == "fahrenheit") {
        return celsius * 9.0 / 5.0 + 32;
    } else if (to == "kelvin") {
        return celsius + 273.15;
    } else {
        cout << "Invalid temperature unit!" << endl;
        return -1;
    }
}

void UnitConverter::convertLength() {
    double value;
    string fromUnit, toUnit;
    
    displayLengthUnits();
    cout << "Enter value: ";
    cin >> value;
    cout << "From unit: ";
    cin >> fromUnit;
    cout << "To unit: ";
    cin >> toUnit;
    
    double result = lengthConversion(value, fromUnit, toUnit);
    if (result != -1) {
        cout << value << " " << pluralize(fromUnit, value) << " = " << result << " " << pluralize(toUnit, result) << endl;
    }
}

void UnitConverter::convertWeight() {
    double value;
    string fromUnit, toUnit;
    
    displayWeightUnits();
    cout << "Enter value: ";
    cin >> value;
    cout << "From unit: ";
    cin >> fromUnit;
    cout << "To unit: ";
    cin >> toUnit;
    
    double result = weightConversion(value, fromUnit, toUnit);
    if (result != -1) {
        cout << value << " " << pluralize(fromUnit, value) << " = " << result << " " << pluralize(toUnit, result) << endl;
    }
}

void UnitConverter::convertTemperature() {
    double value;
    string fromUnit, toUnit;
    
    cout << "Available temperature units: celsius fahrenheit kelvin" << endl;
    cout << "Enter value: ";
    cin >> value;
    cout << "From unit: ";
    cin >> fromUnit;
    cout << "To unit: ";
    cin >> toUnit;
    
    double result = tempConversion(value, fromUnit, toUnit);
    if (result != -1) {
        cout << value << " " << pluralize(fromUnit, value) << " = " << result << " " << pluralize(toUnit, result) << endl;
    }
}

string UnitConverter::pluralize(string unit, double value) {
    // If value is exactly 1, return singular form
    if (value == 1.0) {
        return unit;
    }
    
    // Handle special pluralization cases
    if (unit == "foot") {
        return "feet";
    } else if (unit == "inch") {
        return "inches";
    } else {
        // Regular pluralization - just add 's'
        return unit + "s";
    }
}