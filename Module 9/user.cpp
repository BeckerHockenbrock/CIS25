#include <iostream>

using namespace std;

class User{
public:

    virtual void accessLevel(){
        cout << "Public Access";
    }

    void sayHi(){
        cout << "Hello" << endl;
    }

};

class Employee : public User{
public: 

    void accessLevel(){
        cout << "Employee Access" << endl;
    }

};

class InventoryManger : public User{
public: 

    void accessLevel(){
        cout << "Full inventory access" << endl;
    }

};

int main(){


    Employee emp;
    emp.sayHi();
    emp.accessLevel();

}

