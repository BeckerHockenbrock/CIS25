#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Item {
public:
    string name;
    double price;
    int quantity;

    double getTotalPrice() {
        return price * quantity;
    }
};

void displayMenu() {
    cout << "\n===== SHOPPING CART MENU =====" << endl;
    cout << "1. Add item to cart" << endl;
    cout << "2. View checkout" << endl;
    cout << "3. Exit" << endl;
    cout << "Choose an option: ";
}

int main() {
    Item cart[100];
    int itemCount = 0;
    int choice = 0;
    
    do {
        displayMenu();
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (choice == 1) {
            if (itemCount < 100) {
                cout << "Enter item name: ";
                cin >> cart[itemCount].name;
                cout << "Enter item price: ";
                cin >> cart[itemCount].price;
                cout << "Enter item quantity: ";
                cin >> cart[itemCount].quantity;
                itemCount++;
                cout << "Item added to cart." << endl;
            } else {
                cout << "Cart is full!" << endl;
            }
        } 
        else if (choice == 2) {
            cout << "\n===== CHECKOUT =====" << endl;
            double grandTotal = 0.0;
            cout << fixed << setprecision(2);
            
            for (int i = 0; i < itemCount; i++) {
                double total = cart[i].getTotalPrice();
                grandTotal += total;
                cout << cart[i].name << " - $" << cart[i].price << " x " << cart[i].quantity << " = $" << total << endl;
            }
            
            cout << "----------------------" << endl;
            cout << "Total: $" << grandTotal << endl;
        } 
        else if (choice == 3) {
            cout << "Thank you for shopping!" << endl;
        } 
        else {
            cout << "Invalid option. Please try again." << endl;
        }

    } while (choice != 3);

    return 0;
}
