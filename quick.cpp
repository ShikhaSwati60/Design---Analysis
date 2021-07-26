#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int partition(int a[], int low, int high)
{
    int pi = a[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (a[i] <= pi)
            i++;
        while (a[j] > pi)
            j--;
        if (i < j)
            swap(a[i], a[j]);
    }
    swap(a[low], a[j]);
    return j;
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int n;
    cout << "enter size of array: ";
    cin >> n;
    int arr[n];
    cout << "enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "array after sorting is : ";
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)

        cout << arr[i] << " ";

    return 0;
}