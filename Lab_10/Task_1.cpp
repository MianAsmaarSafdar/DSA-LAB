#include <iostream>
using namespace std;
int sum(int* arr, int size) {
	if (size == 0) {
		return 0;
	}
	else {
		return(arr[size - 1] + sum(arr, size - 1));
	}
}
int main()
{
	int arr[5] = { 5,10,15,20,25 };
	cout << sum(arr, 5) << endl;
	return 0;
}