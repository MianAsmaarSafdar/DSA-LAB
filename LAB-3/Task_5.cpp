#include <iostream>
using namespace std;
int main()
{
	int *arr;
	int size;
	cout << "Enter size of the array: ";
	cin >> size;
	arr = new int[size]; 
	cout << "Enter values for your array " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "Enter " << i + 1 << " Number : ";
		cin >> arr[i];
		while (arr[i] < arr[i - 1])
		{
			cout << "Number is larger than previous" << endl;;
			cout << "Enter " << i + 1 << " number Again : ";
			cin >> arr[i];
		}
	}
	int num;
	cout << "Enter a Number you want to look for: ";
	cin >> num;
	int first = 0;
	int last = size - 1;
	int middle;
	while (first <= last)
	{
		middle = (first + last) / 2;
		if (first > last)
		{
			cout << num << " not found in the array" << endl;
		}
		if (arr[middle] < num)
		{
			first = middle + 1;
		}
		else if (arr[middle] == num)
		{
			cout << num << " found" << endl;
				break;
		}
		else
		{
			last = middle - 1;
		}
	}
	
	//system("pause");
	return 0;
}
