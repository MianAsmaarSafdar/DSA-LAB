#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int priority;
    Student* next;
    Student* prev;
};

class ReservationList {
private:
    Student* head;

    void removeStudentNode(const string& name) {
        Student* current = head;
        while (current) {
            if (current->name == name) {
                if (current->prev)
                    current->prev->next = current->next;
                else
                    head = current->next;
                if (current->next)
                    current->next->prev = current->prev;
                delete current;
                return;
            }
            current = current->next;
        }
    }

public:
    ReservationList() : head(nullptr) {}

    void addStudent(const string& name, int priority = 1) {
        Student* newStudent = new Student{ name, priority, nullptr, nullptr };
        if (!head || priority > head->priority) {
            newStudent->next = head;
            if (head) head->prev = newStudent;
            head = newStudent;
            return;
        }
        Student* current = head;
        while (current->next && current->next->priority >= priority) {
            current = current->next;
        }
        newStudent->next = current->next;
        if (current->next) current->next->prev = newStudent;
        current->next = newStudent;
        newStudent->prev = current;
    }

    void cancelReservation(const string& name) {
        removeStudentNode(name);
    }

    void updatePriority(const string& name, int newPriority) {
        Student* current = head;
        while (current) {
            if (current->name == name) {
                removeStudentNode(name);
                addStudent(name, newPriority);
                return;
            }
            current = current->next;
        }
    }

    void displayList() const {
        Student* current = head;
        while (current) {
            cout << current->name << " (Priority: " << current->priority << ")\n";
            current = current->next;
        }
    }

    int countStudents() const {
        int count = 0;
        Student* current = head;
        while (current) {
            count++;
            current = current->next;
        }
        return count;
    }

    void removeFront() {
        if (head) {
            Student* temp = head;
            head = head->next;
            if (head) head->prev = nullptr;
            delete temp;
        }
    }

    ~ReservationList() {
        while (head) {
            Student* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    ReservationList book1Queue;
    ReservationList book2Queue;

    cout << "--- Book 1 Reservations ---\n";
    book1Queue.addStudent("Alice", 3);
    book1Queue.addStudent("Bob", 1);
    book1Queue.addStudent("Carol", 2);
    book1Queue.displayList();

    cout << "\nCarol cancels her reservation.\n";
    book1Queue.cancelReservation("Carol");
    book1Queue.displayList();

    cout << "\nBob updates priority to 4.\n";
    book1Queue.updatePriority("Bob", 4);
    book1Queue.displayList();

    cout << "\nNumber of students in Book 1 queue: " << book1Queue.countStudents() << "\n";

    cout << "\nBook 1 returned. Removing front student.\n";
    book1Queue.removeFront();
    book1Queue.displayList();

    cout << "\n--- Book 2 Reservations ---\n";
    book2Queue.addStudent("David", 2);
    book2Queue.addStudent("Eve", 5);
    book2Queue.addStudent("Frank", 1);
    book2Queue.displayList();

    cout << "\nNumber of students in Book 2 queue: " << book2Queue.countStudents() << "\n";

    return 0;
}