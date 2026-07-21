#include <iostream>

using namespace std;

int() main {

    int choice;

    do {
        
        cout << "1. Add items to cart" << endl;
        cout << "2. Remove items from cart" << endl;
        cout << "3. Get total" << endl;
        cout << "4. Exit" << endl; 
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        if (choice == 1) {
            addItems();
        } else if (choice == 2) {
            removeItems();
        } else if (choice == 3) {
            getTotal();
        } else if (choice != 4) {
            cout << "Invalid choice. Try again." << endl;
        }
        cout << endl;

    } while (choice != 4);

}

void addItems(){
    String itemName;
    int itemNum;
    double itemPrice;

    cout << "Item Name: ";
    cin >> itemName;

    cout << "Item Price: ";
    cin >> itemPrice;

    cout << "Number of Items: ";
    cin >> itemNum;



}

void removeItems(){
    String itemName;
    int itemNum;
    double itemPrice;

    cout << "Item Name: ";
    cin >> itemName;

    cout << "Item Price: ";
    cin >> itemPrice;

    cout << "Number of Items: ";
    cin >> itemNum;



}