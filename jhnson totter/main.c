#include <stdio.h>
#include <stdlib.h>

void printPermutations(int perm[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", perm[i]);

    printf("\n");
}

int getmobile(int perm[], int dir[], int n)
{
    int mobile = 0;
    int mobile_index = -1;

    for (int i = 0; i < n; i++)
    {
        int next = i + dir[i];

        if (next >= 0 && next < n && perm[i] > perm[next])
        {
            if (perm[i] > mobile)
            {
                mobile = perm[i];
                mobile_index = i;
            }
        }
    }

    return mobile_index;
}

void johnsonTrotter(int n)
{
    int *perm = (int *)malloc(n * sizeof(int));
    int *dir = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        perm[i] = i + 1;
        dir[i] = -1;
    }

    printPermutations(perm, n);

    while (1)
    {
        int mobile_index = getmobile(perm, dir, n);

        if (mobile_index == -1)
            break;

        int swap_with = mobile_index + dir[mobile_index];

        int temp = perm[mobile_index];
        perm[mobile_index] = perm[swap_with];
        perm[swap_with] = temp;

        int tempdir = dir[mobile_index];
        dir[mobile_index] = dir[swap_with];
        dir[swap_with] = tempdir;

        mobile_index = swap_with;

        for (int i = 0; i < n; i++)
        {
            if (perm[i] > perm[mobile_index])
                dir[i] *= -1;
        }

        printPermutations(perm, n);
    }

    free(perm);
    free(dir);
}

int main()
{
    int n;

    printf("Enter value of n: ");
    scanf("%d", &n);

    johnsonTrotter(n);

    return 0;
}
