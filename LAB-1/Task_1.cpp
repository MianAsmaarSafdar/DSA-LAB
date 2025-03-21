#include<iostream>
#include<string>
using namespace std;

template<typename t>
void sort(t arr[], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				t temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
template<typename t>
void print(t arr, int size)
{
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main()
{
	int arr[5] = { 1,4,5,7,2 };
	string stringarr[5] = { "apple","orange","banana","kiwi","pineapple" };
	cout << "Orignal Array :  ";
	print(arr, 5);
	cout << "Sorted Array  :  ";
	sort(arr, 5);
	print(arr, 5);
	cout << "Orignal Array :  ";
	print(stringarr, 5);
	cout << "Sorted Array  :  ";
	sort(stringarr, 5);
	print(stringarr, 5);
return 0;
}
