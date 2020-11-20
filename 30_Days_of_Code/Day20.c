#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, count;
    scanf("%d", &n);
    int *a = malloc(sizeof(int) * n);

    for (int a_i = 0; a_i < n; a_i++)
        scanf("%d", &a[a_i]);
    count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] <= a[j])
                continue ;
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            count++;
        }
    }
    printf("Array is sorted in %d swaps.\nFirst Element: %d\nLast Element: %d\n", count, a[0], a[n - 1]);
    return 0;
}