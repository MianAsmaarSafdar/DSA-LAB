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
	ll.insert_at_tail(5);
	ll.insert_at_tail(10);
	ll.insert_at_tail(15);
	ll.insert_at_tail(20);
	ll.display();
	return 0;
}