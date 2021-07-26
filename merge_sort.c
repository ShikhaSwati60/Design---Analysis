void Merge(int A[], int low, int mid, int high)
{
    int n1 = mid - low + 1; //size of first subarray
    int n2 = high - mid;    //size of second subarray
    int L[n1], R[n2];       //temp array

    for (int i = 0; i < n1; i++)
    {
        L[i] = A[low + i]; //first subarray starts with low
    }

    for (int i = 0; i < n1; i++)
    {
        R[i] = A[mid + 1 + i]; //second subarray starts with mid+1
    }

    int i = 0;   //start index of first subarray
    int j = 0;   //start index of second subarray
    int k = low; //start index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            A[k] = L[i++];
        else
            A[k] = R[j++];

        k++;
    }
    //copy remaining elements

    while (i < n1)
    {
        A[k++] = L[i++];
    }

    while (j < n1)
    {
        A[k++] = R[j++];
    }
}
void Mergesort(int A[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        Mergesort(A, low, mid);
        Mergesort(A, mid + 1, high);
        Merge(A, low, mid, high);
    }
}

int main()
{
    int n, i;
    int A[50];
    printf("Enter the size of array: ");
    scanf("%d", &n);
    printf("\nEnter the elements of array: ");
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);
    Mergesort(A, 0, n - 1);
    printf("\nSorted Array : ");
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
}