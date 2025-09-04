#include<iostream>
using namespace std;

template<typename T>
class AbstractStack
{
public:
	virtual void push(T value) = 0;
	virtual T pop() = 0;
	virtual T topIndex() const = 0;
	virtual bool isEmpty() const = 0;
	virtual bool isFull() const = 0;
	virtual ~AbstractStack() {}
};

template<typename T>
class myStack : public AbstractStack<T>
{
private:
	T* arr;
	int size;
	int top;
	T minElement;

public:
	myStack(int s)
	{
		size = s;
		arr = new T[size];
		top = -1;
	}

	bool isEmpty() const
	{
		return top == -1;
	}

	bool isFull() const
	{
		return top == size - 1;
	}

	void push(T value)
	{
		if (isFull())
		{
			cout << "Stack is Full ! cannot Push Item" << endl;
			return;
		}

		if (isEmpty())
		{
			minElement = value;
			arr[++top] = value;
		}
		else if (value >= minElement)
		{
			arr[++top] = value;
		}
		else
		{
			arr[++top] = 2 * value - minElement;
			minElement = value;
		}
	}

	T pop()
	{
		if (isEmpty())
		{
			cout << "Stack is Empty ! cannot Pop Item" << endl;
			return T();
		}

		T poppedVal;

		if (arr[top] >= minElement)
		{
			poppedVal = arr[top--];
		}
		else
		{
			// decode previous minimum
			poppedVal = minElement;
			minElement = 2 * minElement - arr[top--];
		}

		cout << "Popped item :" << poppedVal << endl;
		return poppedVal;
	}

	T topIndex() const
	{
		if (isEmpty())
		{
			cout << "Stack is Empty ! cannot pop top item" << endl;
			return T();
		}

		if (arr[top] >= minElement)
		{
			cout << "Stack Top value are :" << arr[top] << endl;
			return arr[top];
		}
		else
		{
			cout << "Stack Top value are :" << minElement << endl;
			return minElement;
		}
	}

	T getMin() const
	{
		if (isEmpty())
		{
			cout << "Stack is Empty ! No minimum value" << endl;
			return T();
		}
		cout << "Minimum Element in Stack is: " << minElement << endl;
		return minElement;
	}

	void display()
	{
		if (isEmpty())
		{
			cout << "Stack is Empty!" << endl;
			return;
		}
		cout << "Stack Items from Top to Bottom are :";
		for (int i = top; i >= 0; i--)
		{
			if (arr[i] >= minElement)
				cout << arr[i] << " ";
			else
				cout << minElement << " "; 
		}
		cout << endl;
	}

	~myStack()
	{
		delete[] arr;
	}
};

int main()
{
	int size;
	cout << "Enter Size :";
	cin >> size;
	myStack<int> s1(size);

	int choice;
	do {
		cout << "\n--- Stack Menu ---\n";
		cout << "1. Push\n";
		cout << "2. Pop\n";
		cout << "3. Top\n";
		cout << "4. Display\n";
		cout << "5. Is Empty\n";
		cout << "6. Is Full\n";
		cout << "7. Show minimum element\n";
		cout << "8. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
		{
			int val;
			cout << "Enter Value :";
			cin >> val;
			s1.push(val);
			break;
		}
		case 2:
		{
			s1.pop();
			break;
		}
		case 3:
		{
			s1.topIndex();
			break;
		}
		case 4:
		{
			s1.display();
			break;
		}
		case 5:
		{
			if (s1.isEmpty())
				cout << "Stack is Empty!" << endl;
			else
				cout << "Stack is not Empty!" << endl;
			break;
		}
		case 6:
		{
			if (s1.isFull())
				cout << "Stack is Full!" << endl;
			else
				cout << "Stack is not Full!" << endl;
			break;
		}
		case 7:
		{
			s1.getMin();
			break;
		}
		case 8:
		{
			cout << "Exiting..." << endl;
			break;
		}
		default:
			cout << "Invalid Choice!" << endl;
		}
	} while (choice != 8);

	return 0;
}
