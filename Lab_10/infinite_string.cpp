//
// Created by GuoYubin on 2021/5/7.
//
#include <iostream>

using namespace std;

long long bina[62];

void Bina() {
    bina[0] = 1;
    for (int i = 1; i < 62; ++i) {
        bina[i] = bina[i - 1] << 1;
    }
}

pair<bool, long long> check(long long i) {
    int l = 0, m, r = 61;
    while (l <= r) {
        m = (l + r) / 2;
        if (bina[m] == i) {
            return {true, bina[m]};
        }
        if (bina[m] < i) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    return {false, (bina[l] < i ? bina[l] : bina[l - 1])};
}

long long search(long long i, long long j) {
    if (i != 1) {
        return search(1, j) - search(1, i - 1);
    }

    if (j == 0) {
        return 0;
    }

    pair<bool, long long> tmp;

    tmp = check(j + 1);
    if (tmp.first) {
        return tmp.second / 2;
    } else if (j == tmp.second) {
        return tmp.second / 2 + 1;
    }

    return tmp.second / 2 + 1 + (j - tmp.second) - search(2 * tmp.second - j, tmp.second - 1);
}

int main() {
    Bina();
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        long long x, y;
        cin >> x >> y;
        cout << search(x, y) << '\n';
    }


    return 0;
}
