#include <stdio.h>
#include <time.h>

#define MAX 16

void conventional(int A[MAX][MAX], int B[MAX][MAX],
                  int C[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }
}

void add(int A[MAX][MAX], int B[MAX][MAX],
         int C[MAX][MAX], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void subtract(int A[MAX][MAX], int B[MAX][MAX],
              int C[MAX][MAX], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void strassen(int A[MAX][MAX], int B[MAX][MAX],
              int C[MAX][MAX], int n) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int m = n / 2;
    int A11[MAX][MAX], A12[MAX][MAX];
    int A21[MAX][MAX], A22[MAX][MAX];
    int B11[MAX][MAX], B12[MAX][MAX];
    int B21[MAX][MAX], B22[MAX][MAX];

    int M1[MAX][MAX], M2[MAX][MAX];
    int M3[MAX][MAX], M4[MAX][MAX];
    int M5[MAX][MAX], M6[MAX][MAX], M7[MAX][MAX];

    int X[MAX][MAX], Y[MAX][MAX];
    int C11[MAX][MAX], C12[MAX][MAX];
    int C21[MAX][MAX], C22[MAX][MAX];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + m];
            A21[i][j] = A[i + m][j];
            A22[i][j] = A[i + m][j + m];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + m];
            B21[i][j] = B[i + m][j];
            B22[i][j] = B[i + m][j + m];
        }
    }

    add(A11, A22, X, m);
    add(B11, B22, Y, m);
    strassen(X, Y, M1, m);

    add(A21, A22, X, m);
    strassen(X, B11, M2, m);

    subtract(B12, B22, Y, m);
    strassen(A11, Y, M3, m);

    subtract(B21, B11, Y, m);
    strassen(A22, Y, M4, m);

    add(A11, A12, X, m);
    strassen(X, B22, M5, m);

    subtract(A21, A11, X, m);
    add(B11, B12, Y, m);
    strassen(X, Y, M6, m);

    subtract(A12, A22, X, m);
    add(B21, B22, Y, m);
    strassen(X, Y, M7, m);

    add(M1, M4, X, m);
    subtract(X, M5, Y, m);
    add(Y, M7, C11, m);

    add(M3, M5, C12, m);
    add(M2, M4, C21, m);

    subtract(M1, M2, X, m);
    add(X, M3, Y, m);
    add(Y, M6, C22, m);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            C[i][j] = C11[i][j];
            C[i][j + m] = C12[i][j];
            C[i + m][j] = C21[i][j];
            C[i + m][j + m] = C22[i][j];
        }
    }
}

int main() {
    int n, A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

    printf("Enter matrix order (power of 2, max 16): ");
    scanf("%d", &n);

    if (n < 1 || n > MAX || (n & (n - 1)) != 0) {
        printf("Invalid matrix order.\n");
        return 0;
    }

    printf("Enter first matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter second matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);

    clock_t start = clock();
    conventional(A, B, C, n);
    clock_t end = clock();

    printf("\nConventional multiplication:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    printf("Conventional time: %.6f seconds\n",
           (double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    strassen(A, B, C, n);
    end = clock();

    printf("\nStrassen multiplication:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    printf("Strassen time: %.6f seconds\n",
           (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
