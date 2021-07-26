#include <stdio.h>
#include <limits.h>
int A[50], max, min;

void xyz(int i, int j)
{
    int mid, max1, min1;
    if (i == j)
        max = min = A[i];
    else if (i == j - 1)
    {
        if (A[i] < A[j])
        {
            max = A[j];
            min = A[i];
        }
        else
        {
            max = A[i];
            min = A[j];
        }
    }
    else
    {
        mid = (i + j) / 2;
        xyz(i, mid);
        max1 = max;
        min1 = min;
        xyz(mid + 1, j);
        if (max < max1)
            max = max1;
        if (min > min1)
            min = min1;
    }
}
int main()
{
    int n, i;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("\nEnter the array elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);
    printf("\nArray is :");
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    max = min = A[0];
    xyz(1, n - 1);
    printf("\nMinimum Element of Array is: %d", min);
    printf("\nMaximum Element of Array is: %d\n", max);
    return 0;
}
