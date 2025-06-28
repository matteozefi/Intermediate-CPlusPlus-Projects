#include <iostream>
using namespace std;

//pass by reference so that the original variable values are altered within the function
void calculateResult(double& result, double& number, char& operation, char& continueorNot){

    do {
        bool validOperator = false;
        cout << "Current Result: " << result << endl;

        while (!validOperator) {
            cout << "Enter your desired operator (+, -, *, /): ";
            cin >> operation;

            if (operation == '+' || operation == '-' || operation == '*' || operation == '/') {
                validOperator = true;
            } else {
                cout << "Invalid operator! Try again" << endl;
            }
        }

        cout << "Enter number: ";
        cin >> number;

        switch(operation) {
            case '+':
                result = result + number;
                break;
            case '-':
                result = result - number;
                break;
            case '*':
                result = result * number;
                break;
            case '/':
                if (number != 0) {
                    result = result / number;
                } else {
                    cout << "Error: Division by zero! Result unchanged." << endl;
                    continue;
                }
                break;
            /*case '%':
                if (number != 0) {
                    result = (int)result / (int)number;
                } else {
                    cout << "Error: Division by zero!" << endl;
                    continue;
                } */
            default:
                cout << "Invalid operator!" << endl;
                continue; 
        }

        cout << "Result: " << result << endl;
        cout << "Continue? (y/n) ";
        cin >> continueorNot;

    } while (continueorNot == 'y' || continueorNot == 'Y');

}

int main() {
    double result;
    double number = 0;         //initialize variables for good practice
    char operation = '+';
    char continueorNot = 'n';

    cout << "Enter starting number: ";
    cin >> result;

    calculateResult(result, number, operation, continueorNot);
     
    return 0;
}