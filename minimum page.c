#include <stdio.h>
#include <time.h>

int countStudents(int pages[], int n, long long limit) {
    int students = 1;
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        if (pages[i] > limit)
            return n + 1;

        if (sum + pages[i] > limit) {
            students++;
            sum = pages[i];
        } else {
            sum += pages[i];
        }
    }

    return students;
}

long long allocatePages(int pages[], int n, int m) {
    if (m > n)
        return -1;

    long long low = 0, high = 0;

    for (int i = 0; i < n; i++) {
        if (pages[i] > low)
            low = pages[i];

        high += pages[i];
    }

    long long answer = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (countStudents(pages, n, mid) <= m) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return answer;
}

int main() {
    int n, m, pages[100];

    printf("Enter number of books: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("Invalid number of books.\n");
        return 0;
    }

    printf("Enter pages in each book:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of students: ");
    scanf("%d", &m);

    if (m <= 0) {
        printf("Invalid number of students.\n");
        return 0;
    }

    clock_t start = clock();
    long long result = allocatePages(pages, n, m);
    clock_t end = clock();

    if (result == -1)
        printf("Allocation is not possible.\n");
    else
        printf("Minimum maximum pages: %lld\n", result);

    printf("Execution time: %.6f seconds\n",
           (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
