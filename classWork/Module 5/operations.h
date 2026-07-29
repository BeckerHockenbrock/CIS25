#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <iostream>

using namespace std;

inline void doMultiplication() {
    int n1, n2;
    cout << "Enter two numbers: ";
    cin >> n1 >> n2;
    cout << "Result: " << n1 * n2 << endl;
}

inline void doAddition() {
    int n1, n2;
    cout << "Enter two numbers: ";
    cin >> n1 >> n2;
    cout << "Result: " << n1 + n2 << endl;
}

inline void doSubtraction() {
    int n1, n2;
    cout << "Enter two numbers: ";
    cin >> n1 >> n2;
    cout << "Result: " << n1 - n2 << endl;
}

inline void doDivision() {
    double n1, n2;
    cout << "Enter two numbers: ";
    cin >> n1 >> n2;
    if (n2 != 0) {
        cout << "Result: " << n1 / n2 << endl;
    } else {
        cout << "Error: Division by zero!" << endl;
    }
}

#endif // OPERATIONS_H
