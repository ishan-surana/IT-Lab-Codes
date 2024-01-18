#include <stdio.h>

int isMagicSquare(int matrix[][100], int n, int row, int col, int sum, int currentSum) {
    if (row == n) {
        return (currentSum == sum);
    }

    if (col == n) {
        return isMagicSquare(matrix, n, row + 1, 0, sum, currentSum);
    }

    return isMagicSquare(matrix, n, row, col + 1, sum, currentSum + matrix[row][col]);
}

int main() {
    int matrix[100][100];
    int n;

    printf("Enter the order of the square matrix: ");
    scanf("%d", &n);

    printf("Enter elements for the square matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += matrix[i][0]; // Calculate the sum of the first column
    }

    if (isMagicSquare(matrix, n, 0, 0, sum, 0)) {
        printf("The matrix is a magic square.\n");
    } else {
        printf("The matrix is not a magic square.\n");
    }

    return 0;
}
