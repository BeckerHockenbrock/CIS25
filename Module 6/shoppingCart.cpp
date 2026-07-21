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
        return price * quantity;
    }

    int addToFile(){

    }
    
}

int main() {

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
        cartFile << itemName << " " << itemPrice << " " << itemNum << endl;
        cartFile.close();
        cout << "Item added to cart." << endl;
    }
    
}



void removeItems(){

    Item item;

    cout << "Item Name: ";
    cin >> item.name;

    cout << "Item Price: ";
    cin >> item.price;

    cout << "Number of Items: ";
    cin >> item.num;

}