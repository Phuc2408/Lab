#include <iostream>
using namespace std;

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void merge(int L[], int l, int R[], int r, int a[], int n)
{
    int i, j, k;
    i = j = k = 0;
    while (i < l && j < r)
    {
        if (L[i] > R[j])
        {
            a[k] = R[j];
            j++;
        }
        else
        {
            a[k] = L[i];
            i++;
        }
        k++;
    }
    while (i < l)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < r)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int n)
{
    if (n > 1)
    {
        int l, r;
        l = n / 2;
        r = n - l;
        int L[l], R[r];

        for (int i = 0; i < l; i++)
        {
            L[i] = a[i];
        }
        for (int i = 0; i < r; i++)
        {
            R[i] = a[i + l];
        }

        mergeSort(L, l);
        mergeSort(R, r);
        merge(L, l, R, r, a, n);
    }
}

int main()
{
    int a[1000];
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "Initial array: ";
    printArray(a, n);

    mergeSort(a, n);

    cout << "Sorted array: ";
    printArray(a, n);
    system("pause");
    return 0;
}