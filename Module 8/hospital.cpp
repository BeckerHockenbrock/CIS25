#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;



class Patient{
public:

    int id;
    string name;
    int age;
    string gender;
    string diagnosis;

    void toString(){
        cout << id << endl;
        cout << name << endl;
        cout << age << endl;
        cout << gender << endl;
        cout << diagnosis << endl;
    }

};

const int MAX_PATIENTS = 100;
Patient* patients = new Patient[MAX_PATIENTS];
int pCount = 0;

void addPatient(){
    Patient patient;

    cout << "Enter ID of patient: ";
    cin >> patient.id;

    cout << "Enter name: ";
    cin >> patient.name;

    cout << "Enter age: ";
    cin >> patient.age;

    cout << "Enter gender: ";
    cin >> patient.gender;

    cout << "Enter diagnosis: ";
    cin >> patient.diagnosis;

    patients[pCount] = patient;
    pCount++;
}

void displayPatients() {
    for (int i = 0; i < pCount; i++) {
        cout << "ID: " << patients[i].id << endl;
        cout << "Name: " << patients[i].name << endl;
        cout << "Age: " << patients[i].age << endl;
        cout << "Gender: " << patients[i].gender << endl;
        cout << "Diagnosis: " << patients[i].diagnosis << "\n\n";

    }
}

int searchForPatient() {
    int searchID;

    cout << "Enter Patient ID to search: ";
    cin >> searchID;

    int left = 0;
    int right = pCount - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (patients[mid].id == searchID) {
            return mid;
        }

        if (patients[mid].id < searchID) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << "Patient not found." << endl;
    return -1;
}

void updatePatient(){
    int i = searchForPatient();
    Patient temp = patients[i];

    cout << "Enter name: ";
    cin >> temp.name;

    cout << "Enter age: ";
    cin >> temp.age;

    cout << "Enter gender: ";
    cin >> temp.gender;

    cout << "Enter diagnosis: ";
    cin >> temp.diagnosis;

    patients[i] = temp;

}

void savePatients(){

    ofstream file("patients.txt");

    if(!file){
        cout << "Could not open cart.txt" << endl;
        return;
    }

    for(int i = 0; i < pCount; i++){
        
        file << patients[i].id << ",";
        file << patients[i].name << ",";
        file << patients[i].age << ",";
        file << patients[i].gender << ",";
        file << patients[i].diagnosis << ",\n" ;

    }
}

void loadPatients(){
    pCount = 0;
    ifstream file("patients.txt");
    string line;



    while (getline(file, line)) {
        Patient p;
        string idS;
        string ageS;

        stringstream ss(line);

        getline(ss, idS, ',');
        getline(ss, p.name, ',');
        getline(ss, ageS, ',');
        getline(ss, p.gender, ',');   
        getline(ss, p.diagnosis, ',');

        p.age = stoi(ageS);
        p.id = stoi(idS);

        patients[pCount] = p;
        pCount++;
    }


}
int main(){
    loadPatients();
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
            searchForPatient();
        } else if (choice == 4) {
            updatePatient();
        }else if (choice == 5) {
            savePatients();
        } else if(choice == 6){
            cout << "Good Bye" << endl;
        }else {
            cout << "Invalid choice. Try again." << endl;
        }
        cout << endl;
    
    } while (choice != 6);

    delete[] patients;
    
}