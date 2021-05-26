//
// Created by GuoYubin on 2021/5/26.
//

#define ll long long

#include <iostream>


using namespace std;


int main() {


    int n, m;
    cin >> n >> m;

    auto dp = new ll[m + 1]{0};
    auto w = new int[n];
    auto c = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = m; j >= c[i - 1]; --j) {
            dp[j] = max(dp[j], dp[j - c[i - 1]] + w[i - 1]);
        }
    }

    cout << dp[m];


    return 0;
}

