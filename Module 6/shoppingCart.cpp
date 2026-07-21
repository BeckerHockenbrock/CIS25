#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

class Item{
public:
    string name;
    double price;
    int num;

    double getTotalPrice() {
        return price * num;
    }
    
};


void addItems(){
    Item item;
    
    cout << "Item Name: ";
    cin >> item.name;
    
    cout << "Item Price: ";
    cin >> item.price;
    
    cout << "Number of Items: ";
    cin >> item.num;
    
    ofstream cartFile("cart.txt", ios::app);
    
    if (!cartFile) {
        cout << "Could not open cart.txt" << endl;
    } else {
        cartFile << item.name << " " << item.price << " " << item.num << endl;
        cartFile.close();
        cout << "Item added to cart." << endl;
    }
    
}

void checkout(){

    ifstream cartFile("cart.txt");

    if (!cartFile) {
        cout << "Could not open cart.txt" << endl;
        return;
    }

    Item item;
    double grandTotal = 0;

    cout << fixed << setprecision(2);
    
    while (cartFile >> item.name >> item.price >> item.num) {
        double itemTotal = item.getTotalPrice();
        
        cout << item.name << " - $" << item.price
        << " x " << item.num
        << " = $" << itemTotal << endl;
        
        grandTotal = grandTotal + itemTotal;
    }
    
    cout << "Total: $" << grandTotal << endl;
    
}
    
int main() {
    
    int choice;
    
    do {
        
        cout << "1. Add items to cart" << endl;
        cout << "2. Remove items from cart" << endl;
        cout << "3. Checkout" << endl;
        cout << "4. Exit" << endl; 
        cout << "Enter your choice (1-4): ";
        cin >> choice;
    
        if (choice == 1) {
            addItems();
        } else if (choice == 2) {
            checkout();
        } else if (choice == 3) {
            cout << "Thank you for shopping!" << endl;
        } else {
            cout << "Invalid choice. Try again." << endl;
        }
        cout << endl;
    
    } while (choice != 3);
    
}