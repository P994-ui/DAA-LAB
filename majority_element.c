#include <stdio.h>
#include <time.h>

int main()
{
    int a[100], n, i;
    int candidate = 0, count = 0;
    int frequency = 0;
    clock_t start, end;
    double time_taken;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    start = clock();

    /* Moore's Voting Algorithm */

    for(i = 0; i < n; i++)
    {
        if(count == 0)
        {
            candidate = a[i];
            count = 1;
        }
        else if(a[i] == candidate)
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    /* Verify candidate */

    for(i = 0; i < n; i++)
    {
        if(a[i] == candidate)
            frequency++;
    }

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    if(frequency > n / 2)
        printf("\nMajority Element = %d", candidate);
    else
        printf("\nNo Majority Element");

    printf("\nExecution Time: %.10f seconds", time_taken);

    return 0;
}