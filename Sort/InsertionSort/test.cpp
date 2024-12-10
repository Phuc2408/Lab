#include<iostream>
using namespace std;
void insertionSort(int a[], int n) {
    for (int i = 0;i < n;i++) {
        int index = i;
        int value = a[i];
        while (index > 0 && a[index - 1] > value) {
            a[index] = a[index - 1];
            index--;
        }
        a[index] = value;
    }
}
int main() {
    int a[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    insertionSort(a, n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    system("pause");
    return 0;
}