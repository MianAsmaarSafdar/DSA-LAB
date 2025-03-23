#include <iostream>
using namespace std;

void rotateArray(int* arr, int size, int k) {
    k = k % size;

    if (k == 0) return;

    int* start = arr;
    int* end = arr + size - 1;
    while (start < end) {
        swap(*start, *end);
        start++;
        end--;
    }

    start = arr;
    end = arr + k - 1;
    while (start < end) {
        swap(*start, *end);
        start++;
        end--;
    }

    start = arr + k;
    end = arr + size - 1;
    while (start < end) {
        swap(*start, *end);
        start++;
        end--;
    }
}

int main() {
    int size, k;

    cout << "Enter size of the array: ";
    cin >> size;
    int* arr = new int[size];

    cout << "Enter array elements: ";
    for (int i = 0; i < size; ++i) {
        cin >> *(arr + i);
    }

    cout << "Enter the number of positions to rotate (K): ";
    cin >> k;

    rotateArray(arr, size, k);

    cout << "Rotated array: ";
    for (int i = 0; i < size; ++i) {
        cout << *(arr + i) << " ";
    }
    cout << endl;

    delete[] arr;

    return 0;
}
