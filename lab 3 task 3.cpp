#include <iostream>
using namespace std;

int main() {

    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    // Allocate memory for rows
    int** matrix = new int*[rows];

    // Allocate memory for columns
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    // Input elements
    cout << "Enter matrix elements:"<<endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    // Display matrix
    cout << "Matrix is:"<<endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Free memory
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;
    matrix = nullptr;

    return 0;
}