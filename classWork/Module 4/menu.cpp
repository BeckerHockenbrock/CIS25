#include <iostream>

using namespace std;

int main() {
    int choice;

    do {
        cout << "1. Say Hello" << endl;
        cout << "2. Do some math" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice (1-3): ";
        
        cin >> choice;

        if (choice == 1) {
            cout << "Hello there! Welcome to C++." << endl;
        } else if (choice == 2) {
            cout << "2 + 2 = 4 (Quick math!)" << endl;
        } else if (choice == 3) {
            cout << "Exiting the program. Goodbye!" << endl;
        } else {
            cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
        }

    } while (choice != 3);

    return 0;
}
