
#include <iostream>
using namespace std;
void change(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
void swap(int a[], int n) {
    int minindex = 0;
    int maxindex = 0;
    int minvalue = a[0];
    int maxvalue = 0;
    for (int i = 0;i < n;i++) {
        if (minvalue > a[i]) {
            minvalue = a[i];
            minindex = i;
        }
        if (maxvalue < a[i]) {
            maxvalue = a[i];
            maxindex = i;
        }
    }
    change(a[minindex], a[maxindex]);
    for (int i = 0;i < n;i++) {
        cout << a[i] << " ";
    }
}
int main() {
    int a[1000];
    int n;
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> a[i];
    }
    swap(a, n);
    system("pause");
    return 0;
}