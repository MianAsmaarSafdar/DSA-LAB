# include<iostream>
using namespace std;
class node
{
public:
	node* next;
	node* prev;
	int data;
	node(int d)
	{
		data = d;
		next = NULL;
		prev = NULL;
	}
};
class ll
{
private:
	node* head;
public:
	ll()
	{
		head = NULL;
	}
	void create_at_end(int data)
	{
		node* newnode = new node(data);

		if (head == NULL)
		{
			head = newnode;
			newnode->prev = NULL;
			newnode->next = NULL;
		}
		else
		{
			node* temp = head;

			while (temp->next != NULL)
			{
				temp = temp->next;
			}

			temp->next = newnode;
			newnode->prev = temp;
			newnode->next = NULL;
		}
	}
	void insert_at_specific_position(int data,int pos)
	{
		if (head == NULL)
		{
			cout << "Linked list is empty." << endl;
			return;
		}
		node* newnode = new node(data);
		node* temp = head;
		for (int i = 1; i < pos; i++)
		{
			temp = temp->next;
		}
		newnode->next = temp->next;
		newnode->prev = temp;
		temp->next->prev = newnode;
		temp->next = newnode;
	}
	
	void delete_from_position(int pos)
	{
		if (head == NULL) return;

		node* temp = head;
		int count = 1;

		while (temp != NULL)
		{
			if (count == pos) 
			{
				if (temp->prev != NULL) 
				{
					temp->prev->next = temp->next;
				}
				else
				{
					head = temp->next;
				}

				if (temp->next != NULL) 
				{
					temp->next->prev = temp->prev;
				}
				delete temp;
				return;
			}
			temp = temp->next;
			count++;
		}
		cout << "Position out of range!" << endl;
	}
	void search(int v)
	{
		node* temp = head;
		while (temp != NULL)
		{
			if (v == temp->data)
			{
				cout << "Element is present in list." << endl;
				return;
			}
			temp = temp->next;
		}
		cout << "Element not present in list" << endl;
	}
	void count()
	{
		node* temp = head;
		int count = 0;
		while (temp != NULL)
		{
			count++;
			temp = temp->next;
		}
		cout << "Total number of elements in list is: " << count << endl;
	}
	void display()
	{
		node* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};
int main()
{
	ll obj;
	obj.create_at_end(11);
	obj.create_at_end(13);
	obj.create_at_end(14);
	obj.create_at_end(15);
	obj.create_at_end(16);
	int num;
	cout << "Press 1 for insert at specific position." << endl;
	cout << "Press 2 for delete from specific position." << endl;
	cout << "Press 3 for search element in list." << endl;
	cout << "Press 4 for find total number of elements in list." << endl;
	cout << "Press 5 to display." << endl;
	cout << "Press 0 to exit." << endl;
	
	cout << "--------------------------------------------------" << endl;
	cout << "Enter value:" << endl;
	cin >> num;
	while (num != 0)
	{
		if (num == 1)
		{
			int a, p;
			cout << "Enter a value and position:";
			cin >> a;
			cin >> p;
			obj.insert_at_specific_position(a, p);
		}
		else if (num == 2)
		{
			int p;
			cout << "Enter a value and position:";
			cin >> p;
			obj.delete_from_position(p);
		}
		else if (num == 3)
		{
			int n;
			cout << "Enter a number which you want find in list:";
			cin >> n;
			obj.search(n);
		}
		else if (num == 4)
		{
			obj.count();
		}
		else if (num == 5)
		{
			obj.display();
		}
		else 
		{
			cout << "Invalid input.Enter a new number." << endl;
			cin >> num;
		}
		cout << "Enter a number:" << endl;
		cin >> num;
	}
	return 0;
}