#include <iostream>
using namespace std;

const int SIZE = 100;

class Stack {
private:
    string arr[SIZE];
    int top;
public:
    Stack() {
        top = -1;
    }
    bool isEmpty() {
        return top == -1;
    }
    bool isFull() {
        return top == SIZE - 1;
    }
    void push(string data) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }
        top++;
        arr[top] = data;
    }
    string pop() {
        if (isEmpty()) {
            return "";
        }
        string temp = arr[top];
        top--;
        return temp;
    }
    string peek() {
        if (isEmpty()) {
            return "";
        }
        return arr[top];
    }
};

class TextEditor {
private:
    string text;
    Stack undoStack;
    Stack redoStack;
public:
    void type(string newText) {
        undoStack.push(text);
        text += newText;
        while (!redoStack.isEmpty()) {
            redoStack.pop();
        }
        cout << "Typed.\n";
    }

    void deleteChars(int count) {
        if (count > text.length()) {
            count = text.length();
        }
        undoStack.push(text);
        text = text.substr(0, text.length() - count);
        while (!redoStack.isEmpty()) {
            redoStack.pop();
        }
        cout << "Deleted.\n";
    }

    void undo() {
        if (undoStack.isEmpty()) {
            cout << "Nothing to undo.\n";
            return;
        }
        redoStack.push(text);
        text = undoStack.pop();
        cout << "Undo done.\n";
    }

    void redo() {
        if (redoStack.isEmpty()) {
            cout << "Nothing to redo.\n";
            return;
        }
        undoStack.push(text);
        text = redoStack.pop();
        cout << "Redo done.\n";
    }

    void show() {
        cout << "Current Text: " << text << endl;
    }
};

int main() {
    TextEditor t;
    int ch;
    string input;
    int delCount;

    do {
        cout << "\n--- Text Editor ---\n";
        cout << "1. Type Text\n";
        cout << "2. Delete Characters\n";
        cout << "3. Undo\n";
        cout << "4. Redo\n";
        cout << "5. Show Current Text\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;
        cin.ignore();

        switch (ch) {
        case 1:
            cout << "Enter text to type: ";
            getline(cin, input);
            t.type(input);
            break;
        case 2:
            cout << "How many characters to delete? ";
            cin >> delCount;
            t.deleteChars(delCount);
            break;
        case 3:
            t.undo();
            break;
        case 4:
            t.redo();
            break;
        case 5:
            t.show();
            break;
        case 6:
            cout << "Exiting editor.\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }

    } while (ch != 6);

    return 0;
}
