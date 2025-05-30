#include <iostream>
#include <string>
using namespace std;

class Patient
{
public:
    string name;
    Patient* next;

    Patient(string pname)
    {

        name = pname;
        next = nullptr;
    }
};


class PatientQueue
{
private:
    Patient* head;

public:
    PatientQueue() {
        head = nullptr;
    }


    void addPatient(string name)
    {
        Patient* newPatient = new Patient(name);
        if (head == nullptr)
        {
            head = newPatient;
        }
        else
        {
            Patient* temp = head;

            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newPatient;
        }
        cout << "Patient " << name << " added to the queue." << endl;
    }


    void removePatient(string name)
    {
        if (head == nullptr)
        {
            cout << "Queue is empty. Cannot remove " << name << "." << endl;
            return;
        }


        if (head->name == name)
        {
            Patient* temp = head;
            head = head->next;
            delete temp;
            cout << "Patient " << name << " removed from the queue." << endl;
            return;
        }

        Patient* prev = head;
        Patient* curr = head->next;

        while (curr != nullptr && curr->name != name)
        {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr)
        {
            cout << "Patient " << name << " not found in the queue." << endl;
        }
        else
        {
            prev->next = curr->next;
            delete curr;
            cout << "Patient " << name << " removed from the queue." << endl;
        }
    }


    void displayQueue()
    {
        if (head == nullptr)
        {
            cout << "The queue is empty." << endl;
            return;
        }

        Patient* temp = head;
        cout << "Current patient queue:" << endl;

        while (temp != nullptr)
        {
            cout << temp->name << endl;
            temp = temp->next;
        }
    }


    int countPatients()
    {
        int count = 0;
        Patient* temp = head;

        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }


    ~PatientQueue()
    {
        Patient* temp;
        while (head != nullptr)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};


int main()
{
    PatientQueue obj;

    obj.addPatient("Ali");
    obj.addPatient("Bilal");
    obj.addPatient("Waqas");

    obj.displayQueue();

    cout << "Total patients: " << obj.countPatients() << endl;

    obj.removePatient("bilal");
    obj.displayQueue();

    cout << "Total patients: " << obj.countPatients() << endl;

    obj.removePatient("Dawood");

    return 0;
}