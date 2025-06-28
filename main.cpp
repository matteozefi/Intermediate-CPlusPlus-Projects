// ==================== main.cpp ====================
#include <iostream>
#include "UnitConverter.h"

using namespace std;

int main() {
    UnitConverter converter;
    int choice;
    
    cout << "Welcome to the Unit Converter!" << endl;
    
    while (true) {
        converter.displayMenu();
        cin >> choice;
        
        switch (choice) {
            case 1:
                converter.convertLength();
                break;
            case 2:
                converter.convertWeight();
                break;
            case 3:
                converter.convertTemperature();
                break;
            case 4:
                cout << "Thank you for using the Unit Converter!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    
    return 0;
}