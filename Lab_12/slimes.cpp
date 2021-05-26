//
// Created by GuoYubin on 2021/5/26.
//

#include <iostream>

#define Get(x, y) dp[(x) * n + (y)]

using namespace std;

#define ll long long

int main() {
    int n;
    cin >> n;
    auto w = new ll [n];
    auto sum = new ll [n];
    auto dp = new ll [n * n];

    for (int i = 0; i < n; ++i) {
        cin >> w[i];
        sum[i] = (i == 0? w[i] : (sum[i - 1] + w[i]));
    }

    for (int i = 0; i < n; ++i) {
        Get(i, i) = 0;
        if (i < n - 1) {
            Get(i, i + 1) = w[i] + w[i + 1];
        }
    }


    for (int g = 2; g < n; ++g) {
        for (int i = 0; i < n - g; ++i) {
            ll min_val = 0x7fffffffffffffffLL;
            for (int j = i; j < i + g ; ++j) {
                min_val = min(min_val, (Get(i, j) + Get(j + 1, i + g) + (i == 0? sum[i + g] : (sum[i + g] - sum[i - 1]))));
            }
            Get(i, i + g) = min_val;
        }
    }

    cout << Get(0, n - 1);

}

