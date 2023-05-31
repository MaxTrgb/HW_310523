#include <iostream>

using namespace std;

void transposeMatrix(int matrix[][3], int transposed[][3], int rows, int columns);

int main() {

    // Example usage
    int matrix[3][3] = {

        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int transposedMatrix[3][3];

    transposeMatrix(matrix, transposedMatrix, 3, 3);

    // Display the transposed matrix
    for (int i = 0; i < 3; ++i) {

        for (int j = 0; j < 3; ++j) {

            cout << transposedMatrix[i][j] << " ";
        }
        cout << endl;
    }
}
// Function to transpose a matrix
void transposeMatrix(int matrix[][3], int transposed[][3], int rows, int columns) {

    // Perform the transpose operation
    for (int i = 0; i < rows; ++i) {

        for (int j = 0; j < columns; ++j) {

            // Assign the value from the original matrix to the transposed matrix
            transposed[j][i] = matrix[i][j];
        }
    }
}
