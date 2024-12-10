#include <iostream>
using namespace std;
int patition(int a[], int l, int r) {
    int pivot = (l + r) / 2;
    int i = l;
    int j = r;
    while (i <= j) {
        while (a[i] < a[pivot]) i++;
        while (a[j] > a[pivot]) j--;
        if (i <= j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    return i;
}
void quickSort(int a[], int l, int r) {
    int i = patition(a, l, r);
    if (l < i - 1) {
        quickSort(a, l, i - 1);
    }
    if (i < r) {
        quickSort(a, i, r);
    }
}
int main() {
    int a[] = { 3, 1, 6, 5, 2, 4 };
    quickSort(a, 0, 6);
    for (int i = 0; i < 6; i++) {
        cout << a[i] << " ";
    }
    system("pause");
    return 0;
}