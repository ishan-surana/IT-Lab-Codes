#include <stdio.h>

void addMatrices(int A[][100], int B[][100], int result[][100], int row, int col, int i, int j) {
    if (i == row)
        return;

    if (j == col) {
        j = 0;
        i++;
        addMatrices(A, B, result, row, col, i, j);
    }

    result[i][j] = A[i][j] + B[i][j];
    j++;
    addMatrices(A, B, result, row, col, i, j);
}

void displayMatrix(int matrix[][100], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int A[100][100], B[100][100], result[100][100];
    int row, col;

    printf("Enter the number of rows and columns for matrices A and B: ");
    scanf("%d %d", &row, &col);

    printf("Enter elements for matrix A:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements for matrix B:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    addMatrices(A, B, result, row, col, 0, 0);

    printf("Result of matrix addition (A + B):\n");
    displayMatrix(result, row, col);

    return 0;
}
