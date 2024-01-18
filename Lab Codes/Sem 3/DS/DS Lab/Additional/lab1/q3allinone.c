#include <stdio.h>

// Function to multiply two matrices A and B
void multiplyMatrices(int A[][100], int B[][100], int C[][100], int rowsA, int colsA, int rowsB, int colsB) {
    if (colsA != rowsB) {
        printf("Matrix multiplication is not possible.\n");
        return;
    }

    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            C[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Function to add two matrices A and B
void addMatrices(int A[][100], int B[][100], int C[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to check if a square matrix is a magic square
int isMagicSquare(int matrix[][100], int n) {
    int sumRow = 0, sumCol = 0, sumDiagonal1 = 0, sumDiagonal2 = 0;

    // Calculate the sum of the first row for reference
    for (int i = 0; i < n; i++) {
        sumRow += matrix[0][i];
    }

    // Check the sum of rows, columns, and diagonals
    for (int i = 0; i < n; i++) {
        sumCol = 0;
        for (int j = 0; j < n; j++) {
            sumCol += matrix[j][i];
        }

        sumDiagonal1 += matrix[i][i];
        sumDiagonal2 += matrix[i][n - i - 1];

        if (sumRow != sumCol || sumRow != sumDiagonal1 || sumRow != sumDiagonal2) {
            return 0; // Not a magic square
        }
    }

    return 1; // It's a magic square
}

int main() {
    int A[100][100], B[100][100], C[100][100];
    int rowsA, colsA, rowsB, colsB;
    int rows, cols;

    // Input the number of rows and columns for matrix A
    printf("Enter the number of rows for matrix A: ");
    scanf("%d", &rowsA);
    printf("Enter the number of columns for matrix A: ");
    scanf("%d", &colsA);

    // Input matrix A
    printf("Enter elements for matrix A:\n");
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Input the number of rows and columns for matrix B
    printf("Enter the number of rows for matrix B: ");
    scanf("%d", &rowsB);
    printf("Enter the number of columns for matrix B: ");
    scanf("%d", &colsB);

    // Input matrix B
    printf("Enter elements for matrix B:\n");
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Multiply matrices A and B if possible
    if (colsA == rowsB) {
        multiplyMatrices(A, B, C, rowsA, colsA, rowsB, colsB);
        printf("Matrix C (A * B):\n");
        for (int i = 0; i < rowsA; i++) {
            for (int j = 0; j < colsB; j++) {
                printf("%d\t", C[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Matrix multiplication is not possible.\n");
    }

    // Add matrices A and B if they have the same dimensions
    if (rowsA == rowsB && colsA == colsB) {
        addMatrices(A, B, C, rowsA, colsA);
        printf("Matrix C (A + B):\n");
        for (int i = 0; i < rowsA; i++) {
            for (int j = 0; j < colsA; j++) {
                printf("%d\t", C[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Matrix addition is not possible.\n");
    }

    // Check if a square matrix is a magic square
    if (rowsA == colsA) {
        if (isMagicSquare(A, rowsA)) {
            printf("Matrix A is a magic square.\n");
        } else {
            printf("Matrix A is not a magic square.\n");
        }
    } else {
        printf("Matrix A is not a square matrix, so it cannot be a magic square.\n");
    }

    return 0;
}
