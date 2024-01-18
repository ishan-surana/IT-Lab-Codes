#include <stdio.h>

void multiplyMatrices(int A[][100], int B[][100], int result[][100], int rowA, int colA, int rowB, int colB, int i, int j, int k) {
    if (i >= rowA)
        return;

    if (j < colB) {
        if (k < colA) {
            result[i][j] += A[i][k] * B[k][j];
            k++;
            multiplyMatrices(A, B, result, rowA, colA, rowB, colB, i, j, k);
        }
        k = 0;
        j++;
        multiplyMatrices(A, B, result, rowA, colA, rowB, colB, i, j, k);
    }

    j = 0;
    i++;
    multiplyMatrices(A, B, result, rowA, colA, rowB, colB, i, j, k);
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
    int rowA, colA, rowB, colB;

    printf("Enter the number of rows and columns for matrix A: ");
    scanf("%d %d", &rowA, &colA);

    printf("Enter elements for matrix A:\n");
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colA; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter the number of rows and columns for matrix B: ");
    scanf("%d %d", &rowB, &colB);

    if (colA != rowB) {
        printf("Matrix multiplication is not possible.\n");
        return 1;
    }

    printf("Enter elements for matrix B:\n");
    for (int i = 0; i < rowB; i++) {
        for (int j = 0; j < colB; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Initialize the result matrix with zeros
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colB; j++) {
            result[i][j] = 0;
        }
    }

    multiplyMatrices(A, B, result, rowA, colA, rowB, colB, 0, 0, 0);

    printf("Result of matrix multiplication (A * B):\n");
    displayMatrix(result, rowA, colB);

    return 0;
}
