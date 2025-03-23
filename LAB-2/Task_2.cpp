#include <iostream>
using namespace std;

int main() {
    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int** arr = new int*[rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }

    cout << "Enter the elements of the 2D array:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> arr[i][j];
        }
    }

    bool found = false;
    for (int i = 0; i < rows; i++) {
        int minInRow = arr[i][0];
        int minIndex = 0;
        for (int j = 1; j < cols; j++) {
            if (arr[i][j] < minInRow) {
                minInRow = arr[i][j];
                minIndex = j;
            }
        }

        bool isSaddlePoint = true;
        for (int k = 0; k < rows; k++) {
            if (arr[k][minIndex] > minInRow) {
                isSaddlePoint = false;
                break;
            }
        }

        if (isSaddlePoint) {
            cout << "Saddle point found: " << minInRow << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "No saddle point found\n";
    }

    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
