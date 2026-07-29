#include <iostream>
#include "operations.h"

using namespace std;

int main() {

    int choice;

    do {
        
        cout << "1. Do multiplication" << endl;
        cout << "2. Do addition" << endl;
        cout << "3. Do subtraction" << endl;
        cout << "4. Do division" << endl;
        cout << "5. Exit" << endl; 
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        if (choice == 1) {
            doMultiplication();
        } else if (choice == 2) {
            doAddition();
        } else if (choice == 3) {
            doSubtraction();
        } else if (choice == 4) {
            doDivision();
        } else if (choice != 5) {
            cout << "Invalid choice. Try again." << endl;
        }
        cout << endl;

    } while (choice != 5);

    return 0;
}