#include <iostream>

using namespace std;

int main() {
    char choice;

    do {
        double a, b, result;
        char operation;

        cout << "Welcome to digital Calculator using C++ " << endl;
        cout << "Enter the first number: ";
        cin >> a;

        cout << "Enter the operation (+, -, *, /): ";
        cin >> operation;

        cout << "Enter the second number: ";
        cin >> b;

        switch (operation) {
            case '+':
                result = a + b;
                cout << "Result: " << result << endl;
                break;
            case '-':
                result = a - b;
                cout << "Result: " << result << endl;
                break;
            case '*':
                result = a * b;
                cout << "Result: " << result << endl;
                break;
            case '/':
                if (b != 0) {
                    result = a / b;
                    cout << "Result: " << result << endl;
                } else {
                    cout << " Error: Division by zero is not possible ." << endl;
                }
                break;
            default:
                cout << " Error: Invalid operation" << endl;
        }

        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Digital Calculator using C++!" << endl;

    return 0;
}
