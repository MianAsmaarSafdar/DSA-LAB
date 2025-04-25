#include <iostream>
#include <string>
using namespace std;
const int size=8;
class Stack
{
private:
	string arr[size];
	int top;
public:
	Stack()
	{
		top=-1;
	}
	bool isEmpty()
	{
		return top==-1;
	}
	bool isFull()
	{
		return top==size-1;
	}
	void push(string carN)
	{
		if(isFull())
		{
			cout<<"Parking Lot is Full !"<<endl;
			return;
		}
		else
		{
			top++;
			arr[top]=carN;
		}
	}
	void pop(string carN)
	{
		if(isEmpty())
		{
			cout<<"Parking Lot is Empty !"<<endl;
			return;
		}
		int tempTop=-1;
		string tempArr[size];
		bool found=false;
		while(top!=-1)
		{
			if(arr[top]==carN)
			{
				top--;
				found=true;
				break;
			}
			else
			{
				tempTop++;
				tempArr[tempTop]=arr[top];
				top--;

			}
		}

		while(tempTop!=-1)
		{
			top++;
			arr[top]=tempArr[tempTop];
			tempTop--;
		}
		if (found)
		{
			cout << "Car " << carN << " removed successfully"<<endl;
		}
		else
		{
			cout << "Car " << carN << " not found in the Parking Lot"<<endl;
		}
	}
	void display()
	{
		if(isEmpty())
		{
			cout<<"Parking Lot is Empty !"<<endl;
			return;
		}
		cout << "Cars currently parked (Top to Bottom):"<<endl;
		for (int i = top; i >= 0; i--) {
			cout << arr[i] << endl;
		}
	}
	void totalCars()
	{
	    cout<<"Total Cars in Parking Lot are :"<<top+1<<endl;
	}
	void search(string carN)
	{
	    for(int i=0;i<=top;i++)
	    {
	        if(arr[i]==carN)
	        {
	            cout<<"Car "<<carN<<" is Present in Parking Lot"<<endl;
	            return;
	        }
	    }
	    cout<<"Car "<<carN<<" Not Found in Parking Lot"<<endl;
	}
};
int main()
{
    Stack s1;
    string CarNum;
    int choice;
    do
    {
        cout << "\n=== Parking Lot Menu ===\n";
        cout << "1. Park a new car\n";
        cout << "2. Remove a car by number\n";
        cout << "3. View all cars\n";
        cout << "4. Total cars parked\n";
        cout << "5. Search for a car\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice)
        {
            case 1:
            {
                cout<<"Enter Car Number to Add :";
                getline(cin,CarNum);
                s1.push(CarNum);
                break;
                
            }
            case 2:
            {
                cout<<"Enter Car Number to Remove :";
                getline(cin,CarNum);
                s1.pop(CarNum);
                break;
            }
            case 3:
            {
                s1.display();
                break;
            }
            case 4:
            {
                s1.totalCars();
                break;
            }
            case 5:
            {
                cout<<"Enter Car Number to Search :";
                getline(cin,CarNum);
                s1.search(CarNum);
                break;
            }
            case 6:
            {
                cout<<"Existing Program"<<endl;
                break;
            }
            default:
            {
                cout<<"Invalid choice. Please select a valid option."<<endl;
                break;
            }
        }
    }
	while(choice != 6);
	return 0;
}
