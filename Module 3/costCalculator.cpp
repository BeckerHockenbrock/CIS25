#include <iostream>

using namespace std;

int main() {

    string itemName;
    double cost;
    int numItems;

    
    cout << "Total Cost Calculator\n\n";
    cout << "Enter Item Name: ";
    cin >> itemName;
    cout << "Enter Price: ";
    cin >> cost;
    cout << "Enter Numer of items: "; 
    cin >> numItems;

    cout << "Total Cost: " << (numItems * cost) << endl;

    return 0;
}