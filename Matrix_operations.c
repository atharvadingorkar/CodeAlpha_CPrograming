Task 2 : Matrix Operations 

#include <stdio.h>

void readMatrix(int a[10][10], int r, int c) {
    int i, j;
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &a[i][j]);
}

void printMatrix(int a[10][10], int r, int c) {
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

void addMatrix(int a[10][10], int b[10][10], int r, int c) {
    int i, j, sum[10][10];
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            sum[i][j] = a[i][j] + b[i][j];

    printf("\nMatrix Addition:\n");
    printMatrix(sum, r, c);
}

void multiplyMatrix(int a[10][10], int b[10][10], int r1, int c1, int c2) {
    int i, j, k, mul[10][10] = {0};

    for (i = 0; i < r1; i++)
        for (j = 0; j < c2; j++)
            for (k = 0; k < c1; k++)
                mul[i][j] += a[i][k] * b[k][j];

    printf("\nMatrix Multiplication:\n");
    printMatrix(mul, r1, c2);
}

void transposeMatrix(int a[10][10], int r, int c) {
    int i, j, t[10][10];

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            t[j][i] = a[i][j];

    printf("\nTranspose of Matrix:\n");
    printMatrix(t, c, r);
}

int main() {
    int a[10][10], b[10][10];
    int r1, c1, r2, c2;

    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter elements of first matrix:\n");
    readMatrix(a, r1, c1);

    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &r2, &c2);
    printf("Enter elements of second matrix:\n");
    readMatrix(b, r2, c2);

    if (r1 == r2 && c1 == c2)
        addMatrix(a, b, r1, c1);
    else
        printf("\nAddition not possible");

    if (c1 == r2)
        multiplyMatrix(a, b, r1, c1, c2);
    else
        printf("\nMultiplication not possible");

    transposeMatrix(a, r1, c1);

    return 0;
}