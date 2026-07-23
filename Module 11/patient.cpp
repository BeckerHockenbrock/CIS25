#include <iostream>
#include <string>

using namespace std;

struct Patient{

    int id;
    string name;
    int age;

};

int main(){

    //normal
    Patient p1;
    p1.id = 107;
    p1.name = "John";
    p1.age = 35;

    Patient* p2 = &p1;

    cout << "ID: " << p2->id << endl;
    cout << "ID: " << p1.id << endl;

    cout << "Mem: " << p2 << endl;

}