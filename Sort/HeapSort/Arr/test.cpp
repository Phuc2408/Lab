#include <iostream>
using namespace std;
void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l<n && arr[l]>arr[largest]) {
        largest = l;
    }
    if (r<n && arr[r]>arr[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(int a[], int n) {
    for (int i = n / 2 - 1;i >= 0;i--) {
        heapify(a, n, i);
    }
    for (int i = n - 1;i >= 0;i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}
int main() {
    int a[] = { 12, 11, 13, 5, 6, 7 };
    heapSort(a, 6);
    for (int i = 0;i < 6;i++) {
        cout << a[i] << " ";
    }
    system("pause");
    return 0;
}