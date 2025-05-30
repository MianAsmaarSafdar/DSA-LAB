#include <iostream>
using namespace std;

int nmax(int* arr, int size)
{
	if (size == 1)
	{
		return arr[0];
	}
	int max_of_rest = nmax(arr, size - 1);

	if (arr[size - 1] > max_of_rest)
		return arr[size - 1];
	else
		return max_of_rest;
}

int main() {
	int arr[5] = { 40, 20, 52, 17, 19 };
	cout << nmax(arr, 5) << endl;
	system("pause");
	return 0;
}