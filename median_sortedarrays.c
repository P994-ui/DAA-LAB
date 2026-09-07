#include <stdio.h>
#include <limits.h>
#include <time.h>

double findMedian(int A[], int n, int B[], int m)
{
    int low = 0, high = n;
    int i, j;
    int leftA, rightA, leftB, rightB;

    /* Binary search on smaller array */
    if(n > m)
        return findMedian(B, m, A, n);

    while(low <= high)
    {
        i = (low + high) / 2;
        j = (n + m + 1) / 2 - i;

        if(i == 0)
            leftA = INT_MIN;
        else
            leftA = A[i - 1];

        if(i == n)
            rightA = INT_MAX;
        else
            rightA = A[i];

        if(j == 0)
            leftB = INT_MIN;
        else
            leftB = B[j - 1];

        if(j == m)
            rightB = INT_MAX;
        else
            rightB = B[j];

        if(leftA <= rightB && leftB <= rightA)
        {
            if((n + m) % 2 == 0)
            {
                int leftMax, rightMin;

                leftMax = (leftA > leftB) ? leftA : leftB;
                rightMin = (rightA < rightB) ? rightA : rightB;

                return (leftMax + rightMin) / 2.0;
            }
            else
            {
                return (leftA > leftB) ? leftA : leftB;
            }
        }
        else if(leftA > rightB)
        {
            high = i - 1;
        }
        else
        {
            low = i + 1;
        }
    }

    return 0;
}

int main()
{
    int A[100], B[100];
    int n, m, i;
    double median;
    clock_t start, end;
    double time;

    printf("Enter size of first array: ");
    scanf("%d", &n);

    printf("Enter first sorted array: ");
    for(i = 0; i < n; i++)
        scanf("%d", &A[i]);

    printf("Enter size of second array: ");
    scanf("%d", &m);

    printf("Enter second sorted array: ");
    for(i = 0; i < m; i++)
        scanf("%d", &B[i]);

    start = clock();

    median = findMedian(A, n, B, m);

    end = clock();

    printf("Median: %.2f", median);

    time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nExecution time: %f seconds", time);

    return 0;
}