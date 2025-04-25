#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

Node* head = nullptr;

void insertAtPosition(int value, int position) {
    Node* newNode = new Node(value);
    if (position <= 0) {
        cout << "Invalid position.\n";
        delete newNode;
        return;
    }

    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    for (int i = 1; temp != nullptr && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Position out of range.\n";
        delete newNode;
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteAtPosition(int position) {
    if (head == nullptr || position <= 0) {
        cout << "Invalid position or list is empty.\n";
        return;
    }

    if (position == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    for (int i = 1; temp != nullptr && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == nullptr || temp->next == nullptr) {
        cout << "Position out of range.\n";
    } else {
        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
    }
}

int search(int value) {
    Node* temp = head;
    int position = 1;
    while (temp != nullptr) {
        if (temp->data == value) {
            return position;
        }
        temp = temp->next;
        position++;
    }
    return -1;
}

int countNodes() {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

void displayList() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    cout << "List: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    int choice, value, position;

    while (true) {
        cout << "\nSingly Linked List Menu\n";
        cout << "1. Insert at position\n";
        cout << "2. Delete at position\n";
        cout << "3. Search for element\n";
        cout << "4. Count nodes\n";
        cout << "5. Display list\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> position;
                insertAtPosition(value, position);
                break;

            case 2:
                cout << "Enter position to delete: ";
                cin >> position;
                deleteAtPosition(position);
                break;

            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                position = search(value);
                if (position != -1)
                    cout << "Element found at position " << position << ".\n";
                else
                    cout << "Element not found.\n";
                break;

            case 4:
                cout << "Total nodes: " << countNodes() << "\n";
                break;

            case 5:
                displayList();
                break;

            case 6:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice.\n";
        }
    }

    return 0;
}
