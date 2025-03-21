#include <iostream>
# include<string>
using namespace std;

template<typename T>
int Search(T arr[], int size, T key)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == key)
		{
			return i;
		}
	}

}
template<typename T>
void printSearchResult(T arr[], int index, T Key)
{
	cout << "Value at index " << index << " is " << arr[index] << endl;
}


int main()
{
	// Test with an integer array of size 5
	int intArray[5] = { 64, 25, 12, 22, 11 };
	int intKey = 12;
	int intIndex = Search(intArray, 5, intKey);
	printSearchResult(intArray, intIndex, intKey);

	// Test with a float array of size 4
	float floatArray[4] = { 3.14, 2.71, 1.62, 0.57 };
	float floatKey = 1.62;
	int floatIndex = Search(floatArray, 4, floatKey);
	printSearchResult(floatArray, floatIndex, floatKey);

	// Test with a string array of size 4
	string stringArray[4] = { "apple", "orange", "banana", "grape" };
	string stringKey = "banana";
	int stringIndex = Search(stringArray, 4, stringKey);
	printSearchResult(stringArray, stringIndex, stringKey);

	return 0;
}