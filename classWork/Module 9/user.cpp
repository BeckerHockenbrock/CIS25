#include <iostream>
#include <string>

using namespace std;

class User{
    protected: string username;

    public:


    virtual void accessLevel(){
        cout << "Public Access";
    }

    void sayHi(){
        cout << "Hello" << endl;
    }

    void setUsername(string s){
        username = s;
    }

    string getUsername(){
        return username;
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

class BigBoss : public User{
public:

    void accessLevel(){
        cout << "Total access" << endl;
    }

};

int main(){

    Employee emp;
    emp.sayHi();
    emp.accessLevel();
    emp.setUsername("Bob");
    cout << emp.getUsername() << endl;


}

