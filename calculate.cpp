#include <iostream>

using namespace std;

int main() {
    // Declare variables to store user input and result
    double num1, num2, result;
    char operation;
for(int i=0;i<=3;++i){
    // Get input from the user
    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    // Get the operation from the user
    cout << "Choose an operation (+, -, *, /): ";
    cin >> operation;

    // Perform the calculation based on the chosen operation
    switch (operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            // Check if the denominator is not zero before performing division
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                cout << "Error: Division by zero is not allowed." << endl;
                return 1; // Exit with an error code
            }
            break;
        default:
            cout << "Error: Invalid operation. Please choose +, -, *, or /." << endl;
            return 1; // Exit with an error code
    }

    // Display the result
    cout << "Result: " << result << endl;
}

    return 0; // Exit successfully
}

