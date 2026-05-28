#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50000

int arr[MAX];

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);

    return i + 1;
}

void quicksort(int low, int high)
{
    if (low < high)
    {
        int pi = partition(low, high);

        quicksort(low, pi - 1);
        quicksort(pi + 1, high);
    }
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    clock_t start = clock();

    quicksort(0, n - 1);

    clock_t end = clock();

    printf("Sorted array:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nExecution time: %f seconds\n", time_taken);

    return 0;
}

