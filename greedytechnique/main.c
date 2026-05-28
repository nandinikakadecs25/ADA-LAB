
#include <stdio.h>

struct Item {
    int value, weight;
};

void sort(struct Item a[], int n) {

    int i, j;

    for (i = 0; i < n - 1; i++) {

        for (j = i + 1; j < n; j++) {

            float r1 = (float)a[i].value / a[i].weight;
            float r2 = (float)a[j].value / a[j].weight;

            if (r1 < r2) {

                struct Item temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main() {

    int n, w, i;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item a[n];

    printf("Enter value and weight:\n");

    for (i = 0; i < n; i++) {
        scanf("%d %d", &a[i].value, &a[i].weight);
    }

    printf("Enter capacity: ");
    scanf("%d", &w);

    sort(a, n);

    float totalProfit = 0.0;

    for (i = 0; i < n; i++) {

        if (w >= a[i].weight) {

            w -= a[i].weight;
            totalProfit += a[i].value;
        }
        else {

            totalProfit += ((float)a[i].value / a[i].weight) * w;
            break;
        }
    }

    printf("Maximum profit = %.2f\n", totalProfit);

    return 0;
}
