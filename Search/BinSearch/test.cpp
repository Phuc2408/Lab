#include<iostream>
using namespace std;
int BinSearch(int a[], int n, int x) {
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (a[mid] < x) {
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }
    if (a[l] == x) {
        return l;
    }
    return -1;
}
int main() {
    int a[1000];
    int n;
    cin >> n; //Nhap so luong phan tu
    for (int i = 0;i < n;i++) {
        cin >> a[i];
    }
    int x;
    cin >> x;
    cout << BinSearch(a, n, x);
    return 0;
}
// Với a = [1, 2, 3, 4] và x = 3 thì kết quả mong muốn là 2.
// Với a = [2, 2, 2, 2] và x = 2 thì kết quả mong muốn là 0.