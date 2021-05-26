//
// Created by GuoYubin on 2021/4/28.
//
using namespace std;

#include <iostream>

long long res = 0;

void mg(int *arr, int l, int m, int r) {
    int i = l, j = m, tmp[r - l], tmp_i = 0, tmp_rev = 0;

    while(i < m && j < r) {
        tmp[tmp_i++] = min(arr[i], arr[j]);
        arr[i] <= arr[j] ?  (i++) : ((res += j - i - tmp_rev) && (j++) && (tmp_rev++));
    }

    for (int k = i; k < m; ++k) {
        tmp[tmp_i++] = arr[k];
    }
    for (int k = j; k < r; ++k) {
        tmp[tmp_i++] = arr[k];
    }
    for (int k = 0; k < r - l; ++k) {
        arr[l + k] = tmp[k];
    }
}

void ms(int *arr, int l, int r) {
    if (l == r - 1) {
        return;
    }

    int m = l + (r - l) / 2;
    ms(arr, l, m);
    ms(arr, m, r);
    mg(arr, l, m, r);
}



int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    ms(arr, 0, n);
    cout << res;
}