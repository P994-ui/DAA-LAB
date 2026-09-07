#include <stdio.h>
#include <time.h>

int isPossible(int pages[], int n, int students, int maxPages)
{
    int i;
    int studentCount = 1;
    int currentPages = 0;

    for(i = 0; i < n; i++)
    {
        if(pages[i] > maxPages)
            return 0;

        if(currentPages + pages[i] > maxPages)
        {
            studentCount++;
            currentPages = pages[i];

            if(studentCount > students)
                return 0;
        }
        else
        {
            currentPages += pages[i];
        }
    }

    return 1;
}

int main()
{
    int pages[100], n, students;
    int low = 0, high = 0, mid, answer = 0;
    int i;
    clock_t start, end;
    double time;

    printf("Enter number of books: ");
    scanf("%d", &n);

    printf("Enter pages of books: ");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &pages[i]);

        if(pages[i] > low)
            low = pages[i];

        high += pages[i];
    }

    printf("Enter number of students: ");
    scanf("%d", &students);

    start = clock();

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(isPossible(pages, n, students, mid))
        {
            answer = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    end = clock();

    printf("Minimum maximum pages: %d", answer);

    time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nExecution time: %f seconds", time);

    return 0;
}