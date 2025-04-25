#include <iostream>
#include <string>
using namespace std;

class Patient {
public:
    string name;
    Patient* next;

    Patient(string pname) {
        name = pname;
        next = nullptr;
    }
};

class PatientQueue {
private:
    Patient* head;

public:
    PatientQueue() {
        head = nullptr;
    }

    ~PatientQueue() {
        Patient* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addPatient(string name) {
        Patient* newPatient = new Patient(name);
        if (head == nullptr) {
            head = newPatient;
            return;
        }

        Patient* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newPatient;
    }

    void removePatient(string name) {
        if (head == nullptr) {
            cout << "Queue is empty.\n";
            return;
        }

        if (head->name == name) {
            Patient* temp = head;
            head = head->next;
            delete temp;
            cout << name << " has been removed from the queue.\n";
            return;
        }

        Patient* current = head;
        while (current->next != nullptr && current->next->name != name) {
            current = current->next;
        }

        if (current->next == nullptr) {
            cout << "Patient " << name << " not found in the queue.\n";
        } else {
            Patient* temp = current->next;
            current->next = temp->next;
            delete temp;
            cout << name << " has been removed from the queue.\n";
        }
    }

    void displayQueue() const {
        if (head == nullptr) {
            cout << "The queue is empty.\n";
            return;
        }

        Patient* temp = head;
        cout << "Current Patient Queue:\n";
        while (temp != nullptr) {
            cout << "- " << temp->name << "\n";
            temp = temp->next;
        }
    }

    int countPatients() const {
        int count = 0;
        Patient* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    PatientQueue queue;
    int choice;
    string name;

    do {
        cout << "\nHospital Queue Management System\n";
        cout << "1. Add patient to queue\n";
        cout << "2. Remove patient (cancel appointment)\n";
        cout << "3. Display patient queue\n";
        cout << "4. Count patients in queue\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter patient name: ";
                getline(cin, name);
                queue.addPatient(name);
                break;

            case 2:
                cout << "Enter patient name to remove: ";
                getline(cin, name);
                queue.removePatient(name);
                break;

            case 3:
                queue.displayQueue();
                break;

            case 4:
                cout << "Total patients in queue: " << queue.countPatients() << "\n";
                break;

            case 5:
                cout << "Exiting system...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
