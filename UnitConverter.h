// ==================== UnitConverter.h ====================
#ifndef UNITCONVERTER_H
#define UNITCONVERTER_H

#include <string>
#include <map>

using namespace std;

class UnitConverter {
private:
    map<string, double> lengthUnits;
    map<string, double> weightUnits;
    
public:
    // Constructor
    UnitConverter();
    
    // Menu and display functions
    void displayMenu();
    void displayLengthUnits();
    void displayWeightUnits();
    
    // Conversion functions
    double lengthConversion(double value, string from, string to);
    double weightConversion(double value, string from, string to);
    double tempConversion(double value, string from, string to);
    
    // User interface functions
    void convertLength();
    void convertWeight();
    void convertTemperature();
    
    // Helper function (this was missing from the header!)
    string pluralize(string unit, double value);
};

#endif