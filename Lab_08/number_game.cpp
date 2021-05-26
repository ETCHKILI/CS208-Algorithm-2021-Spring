//
// Created by GuoYubin on 2021/4/27.
//
#include <iostream>

using namespace std;

int Calculate(const string& s,int k1, int k2) {
    if (s == "AND") {
        return k1 & k2;
    } else if (s == "OR") {
        return k1 | k2;
    } else {
        return k1 ^ k2;
    }
}

int main() {
    int n, m;

    cin >> n >> m;

    int r1 = m, r2 = m - 1, r3 = m -2;
    string tmp_s;
    int tmp_k;
    for (int i = 0; i < n; ++i) {
        cin >> tmp_s >> tmp_k;
        r1 = Calculate(tmp_s, r1, tmp_k);
        r2 = Calculate(tmp_s, r2, tmp_k);
        r3 = Calculate(tmp_s, r3, tmp_k);
    }

    cout << max(r1, max(r2, r3));

}