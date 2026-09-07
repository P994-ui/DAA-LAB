#include <stdio.h>
#include <time.h>

void normalMultiply(int A[2][2], int B[2][2], int C[2][2])
{
    int i, j, k;

    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            C[i][j] = 0;

            for(k = 0; k < 2; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }
}

void strassen(int A[2][2], int B[2][2], int C[2][2])
{
    int M1, M2, M3, M4, M5, M6, M7;

    M1 = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
    M2 = (A[1][0] + A[1][1]) * B[0][0];
    M3 = A[0][0] * (B[0][1] - B[1][1]);
    M4 = A[1][1] * (B[1][0] - B[0][0]);
    M5 = (A[0][0] + A[0][1]) * B[1][1];
    M6 = (A[1][0] - A[0][0]) * (B[0][0] + B[0][1]);
    M7 = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);

    C[0][0] = M1 + M4 - M5 + M7;
    C[0][1] = M3 + M5;
    C[1][0] = M2 + M4;
    C[1][1] = M1 - M2 + M3 + M6;
}

int main()
{
    int A[2][2], B[2][2];
    int C1[2][2], C2[2][2];
    int i, j;
    clock_t start, end;
    double time;

    printf("Enter first 2x2 matrix:\n");

    for(i = 0; i < 2; i++)
        for(j = 0; j < 2; j++)
            scanf("%d", &A[i][j]);

    printf("Enter second 2x2 matrix:\n");

    for(i = 0; i < 2; i++)
        for(j = 0; j < 2; j++)
            scanf("%d", &B[i][j]);

    start = clock();

    normalMultiply(A, B, C1);

    printf("\nNormal Matrix Multiplication:\n");

    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
            printf("%d ", C1[i][j]);

        printf("\n");
    }

    strassen(A, B, C2);

    end = clock();

    printf("\nStrassen Matrix Multiplication:\n");

    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
            printf("%d ", C2[i][j]);

        printf("\n");
    }

    time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nExecution time: %f seconds", time);

    return 0;
}