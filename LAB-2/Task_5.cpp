#include <iostream>
using namespace std;
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void mostFrequentElement(int arr[], int size, int &resultElement, int &maxFreq) {
    if (size == 0) {
        resultElement = -1; 
        maxFreq = 0;
        return;
    }

    bubbleSort(arr, size);

    maxFreq = 1;
    int currentFreq = 1;
    resultElement = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] == arr[i - 1]) {
            currentFreq++;
        } else {
            if (currentFreq > maxFreq) {
                maxFreq = currentFreq;
                resultElement = arr[i - 1];
            }
            currentFreq = 1;
        }
    }
    if (currentFreq > maxFreq) {
        maxFreq = currentFreq;
        resultElement = arr[size - 1];
    }
}

int main() {
    int size;

    cout << "Enter the size of the array: ";
    cin >> size;

    int* arr = new int[size];

    cout << "Enter array elements: ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    int resultElement, maxFreq;
    mostFrequentElement(arr, size, resultElement, maxFreq);

    cout << "Element: " << resultElement << ", Frequency: " << maxFreq << endl;

    delete[] arr;

    return 0;
}
