#include <iostream>
#include <string>

using namespace std;

class Product{
private:

    int id;
    string name;
    double price;

public:

    Product(int i, string n, double p){

        id = i;
        name = n;
        price = p;

        cout << "Made the " << name << " object." << endl;

    }

    ~Product(){
        cout << name << " was descontructed." << endl;
    }

    void printDetails(){

        cout << "Id: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Price: " << price << endl;

    }



};

int main(){

    Product p = Product(100, "basketball", 10.50);
    p.printDetails();
    return 0;


}