#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct item
{
    double val;
    double weight;
};

void sort(struct item a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            double x = a[j].val / a[j].weight;
            double y = a[j + 1].val / a[j + 1].weight;
            if (y > x)
            {
                int temp = a[j].val;
                a[j].val = a[j + 1].val;
                a[j + 1].val = temp;

                temp = a[j].weight;
                a[j].weight = a[j + 1].weight;
                a[j + 1].weight = temp;
            }
        }
    }
}

double maximise(struct item a[], int n, int w)
{
    sort(a, n);

    int u = w;
    double res = 0.0;
    int i;
    for (i = 0; i < n; i++)
    {
        if (a[i].weight <= u)
        {
            u = u - a[i].weight;
            res += a[i].val;
        }
        else
            break;
    }
    if (i < n)
    {
        res += ((u / a[i].weight) * a[i].val);
    }
    return res;
}

int main()
{
    int n;
    cout << "ENTER NUMBER OF ITEMS: ";
    cin >> n;
    int capacity;
    item arr[n];
    cout << "Enter the value and weight of the each item"
         << "\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].val;
        cin >> arr[i].weight;
    }
    cout << "Enter the capacity of the bag"
         << "\n";
    cin >> capacity;
    cout << "MAXIMUM VALUE IS: " << maximise(arr, n, capacity);
    return 0;
}