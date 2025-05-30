#include <iostream>
using namespace std;
class node {
public:
	node* next;
	node* prev;
	int data;
	node(int d) {
		data = d;
		prev = NULL;
		next = NULL;
	}
};
class list {
private:
	node* head;
public:
	list() {
		head = NULL;
	}
	void insert_at_head(int val) {
		node* temp = new node(val);
		temp->next = head;
		temp->prev = NULL;
		if (head != NULL) {
			head->prev = temp;
		}
		head = temp;
	}
	void insert_at_tail(int val) {
		node* newNode = new node(val);
		if (head == NULL) {
			head = newNode;
			newNode->next = NULL;
			newNode->prev == NULL;
			return;
		}
		node* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->prev = temp;
		newNode->next = NULL;
	}
	void delete_by_value(int val) {
		if (head == NULL) {
			cout << "List is Empty...!" << endl;
		}
		node* temp = head;
		node* curr = NULL;
		if (head->data == val) {
			head = head->next;
			delete temp;
			return;
		}
		while (temp != NULL && temp->data != val) {
			curr = temp;
			temp = temp->next;
		}
		if (temp == NULL) {
			cout << "Value Not Found";
			return;
		}
		curr->next = temp->next;
		//temp->next->prev = temp->prev;
		delete temp;
	}
	void display() {
		node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};
int main()
{
	list ll;
	ll.insert_at_head(3);
	ll.insert_at_head(2);
	ll.insert_at_head(1);
	ll.insert_at_tail(4);
	ll.insert_at_tail(5);
	cout << "Linked List: ";
	ll.display();
	cout << "Linked List after Deleting Value: ";
	ll.delete_by_value(2);
	ll.delete_by_value(1);
	ll.display();
	return 0;
}