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

    patient.id = pCount;

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
        cout << patients[i].name << endl;
    }
}

Patient searchForPatient() {
    int searchID;

    cout << "Enter Patient ID to search: ";
    cin >> searchID;

    int left = 0;
    int right = pCount - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (patients[mid].id == searchID) {
            return patients[mid];
        }

        if (patients[mid].id < searchID) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << "Patient not found." << endl;
    return Patient();
}

void updatePatient(){
    Patient temp = searchForPatient();
    cout << "Enter name: ";
    cin >> temp.name;

    cout << "Enter age: ";
    cin >> temp.age;

    cout << "Enter gender: ";
    cin >> temp.gender;

    cout << "Enter diagnosis: ";
    cin >> temp.diagnosis;

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
        }else {
            cout << "Invalid choice. Try again." << endl;
        }
        cout << endl;
    
    } while (choice != 6);

    delete[] patients;
    
}