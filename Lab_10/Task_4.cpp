#include <iostream>
using namespace std;
class node{
public:
	node* next;
	int data;
};
class list {
	node* head;
public:
	list() {
		head = NULL;
	}
	void inset_at_head(int value)
	{
		node* temp = new node;
		temp->data = value;
		temp->next = head;
		head = temp;
	}
	node* gethead()
	{
		return head;
	}
};
void display(node* temp)
{
	if (temp == NULL)
		return;
	else
	{
		display(temp->next);
		cout << temp->data << " ";

	}
}
int main()
{
	list ll;
	ll.inset_at_head(1);
	ll.inset_at_head(2);
	ll.inset_at_head(3);
	ll.inset_at_head(4);
	ll.inset_at_head(5);
	display(ll.gethead());
	return 0;
}