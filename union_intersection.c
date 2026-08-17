#include <stdio.h>
#include <time.h>

int main()
{
    int a[100], b[100];
    int n, m, i, j;
    clock_t start, end;
    double time_taken;

    printf("Enter size of first array: ");
    scanf("%d", &n);

    printf("Enter first sorted array: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter size of second array: ");
    scanf("%d", &m);

    printf("Enter second sorted array: ");
    for(i = 0; i < m; i++)
        scanf("%d", &b[i]);

    start = clock();

    /* Union */

    i = 0;
    j = 0;

    printf("\nUnion: ");

    while(i < n && j < m)
    {
        if(a[i] < b[j])
        {
            printf("%d ", a[i]);
            i++;
        }
        else if(b[j] < a[i])
        {
            printf("%d ", b[j]);
            j++;
        }
        else
        {
            printf("%d ", a[i]);
            i++;
            j++;
        }
    }

    while(i < n)
    {
        printf("%d ", a[i]);
        i++;
    }

    while(j < m)
    {
        printf("%d ", b[j]);
        j++;
    }

    /* Intersection */

    i = 0;
    j = 0;

    printf("\nIntersection: ");

    while(i < n && j < m)
    {
        if(a[i] < b[j])
            i++;
        else if(b[j] < a[i])
            j++;
        else
        {
            printf("%d ", a[i]);
            i++;
            j++;
        }
    }

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nExecution Time: %f seconds", time_taken);

    return 0;
}