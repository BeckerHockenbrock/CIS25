#include <string>

using namespace std;



class Patient{
public:

    int id;
    string name;
    int age;
    string gender;
    string diagnosis;

    string toString(){
        cout << id << endl;
        cout << name << endl;
        cout << age << endl;
        cout << gender << endl;
        cout << diagnosis << endl;
    }

};

const int MAX_PATIENTS = 100;

void addPatient(){

}

int main(){
    int choice;

    do {
        
        cout << "1. Add a patient" << endl;
        cout << "2. Display all patients" << endl;
        cout << "3. Search for a patient by ID" << endl; 
        cout << "4. Update patient information" << endl;
        cout << "5. Save patients to file" << endl;
        cout << "6. Exit program" << endl;
        cout << "Enter your choice (1-6): ";
        cin >> choice;
    
        if (choice == 1) {
            addPatient();
        } else if (choice == 2) {
            displayPatients();
        } else if (choice == 3) {
            searchForPateint();
        } else if (choice == 4) {
            updatePatient();
        }else if (choice == 5) {
            savePatients();
        }else {
            cout << "Invalid choice. Try again." << endl;
        }
        cout << endl;
    
    } while (choice != 6);
    
}