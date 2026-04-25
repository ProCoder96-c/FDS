//Design a C++ program to demonstrate exception handling by simulating a division operation.
//Use the try, throw, and catch constructs to handle case of division by zero.
#include <iostream>
using namespace std;

int main() {
    double numerator, denominator, result;

    cout << "Enter numerator: ";
    cin >> numerator;

    cout << "Enter denominator: ";
    cin >> denominator;

    try {
        // Check for division by zero
        if (denominator == 0)
            throw "Error: Division by zero is not allowed!";

        // Perform division
        result = numerator / denominator;
        cout << "Result = " << result << endl;
    }
    catch (const char* msg) {
        // Handle the thrown exception
        cout << msg << endl;
    }

    cout << "Program executed successfully." << endl;
    return 0;
}
