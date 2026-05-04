#include <iostream>
using namespace std;

// Medical History Node (Linked List)
struct MedicalRecord {
    string disease;
    string diagnosis;
    string treatment;
    string date;
    MedicalRecord* next;
};

// Patient Structure
struct Patient {
    int id;
    string name;
    int age;
    string gender;
    MedicalRecord* history;  // linked list
    Patient* next;
};

Patient* head = NULL;

// Add Patient
void addPatient() {
    Patient* newPatient = new Patient();

    cout << "Enter Patient ID: ";
    cin >> newPatient->id;
    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, newPatient->name);

    cout << "Enter Age: ";
    cin >> newPatient->age;
    cin.ignore();

    cout << "Enter Gender: ";
    getline(cin, newPatient->gender);

    newPatient->history = NULL;
    newPatient->next = NULL;

    if (head == NULL) {
        head = newPatient;
    } else {
        Patient* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newPatient;
    }

    cout << "✅ Patient added successfully!\n";
}

// Find Patient
Patient* findPatient(int id) {
    Patient* temp = head;
    while (temp != NULL) {
        if (temp->id == id)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

// Add Medical History
void addMedicalHistory() {
    int id;
    cout << "Enter Patient ID: ";
    cin >> id;
    cin.ignore();

    Patient* patient = findPatient(id);

    if (patient == NULL) {
        cout << "❌ Patient not found!\n";
        return;
    }

    MedicalRecord* newRecord = new MedicalRecord();

    cout << "Disease: ";
    getline(cin, newRecord->disease);

    cout << "Diagnosis: ";
    getline(cin, newRecord->diagnosis);

    cout << "Treatment: ";
    getline(cin, newRecord->treatment);

    cout << "Date: ";
    getline(cin, newRecord->date);

    newRecord->next = NULL;

    if (patient->history == NULL) {
        patient->history = newRecord;
    } else {
        MedicalRecord* temp = patient->history;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newRecord;
    }

    cout << "✅ Medical history added!\n";
}

// View All Patients
void viewPatients() {
    Patient* temp = head;

    if (temp == NULL) {
        cout << "No patients found.\n";
        return;
    }

    while (temp != NULL) {
        cout << "\nID: " << temp->id;
        cout << "\nName: " << temp->name;
        cout << "\nAge: " << temp->age;
        cout << "\nGender: " << temp->gender << endl;

        temp = temp->next;
    }
}

// View Medical History
void viewMedicalHistory() {
    int id;
    cout << "Enter Patient ID: ";
    cin >> id;

    Patient* patient = findPatient(id);

    if (patient == NULL) {
        cout << "❌ Patient not found!\n";
        return;
    }

    MedicalRecord* temp = patient->history;

    if (temp == NULL) {
        cout << "No medical history available.\n";
        return;
    }

    cout << "\n--- Medical History ---\n";

    while (temp != NULL) {
        cout << "\nDisease: " << temp->disease;
        cout << "\nDiagnosis: " << temp->diagnosis;
        cout << "\nTreatment: " << temp->treatment;
        cout << "\nDate: " << temp->date << endl;

        temp = temp->next;
    }
}

// Main Menu
int main() {
    int choice;

    do {
        cout << "\n\n===== Patient Medical History Tracker =====\n";
        cout << "1. Add Patient\n";
        cout << "2. Add Medical History\n";
        cout << "3. View Patients\n";
        cout << "4. View Medical History\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                addMedicalHistory();
                break;
            case 3:
                viewPatients();
                break;
            case 4:
                viewMedicalHistory();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}