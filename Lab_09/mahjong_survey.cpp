//
// Created by GuoYubin on 2021/5/1.
//
#include <iostream>
#include <vector>

struct p {
    int u;
    int v;
    int h;

    bool operator < (p oth) const {
        return ((this->u <= oth.u) && (this->v <= oth.v));
    }
};

using namespace std;
int main() {
    int n;
    cin >> n;

    p ps[n];
    auto res = new int[n]{0};
    for (int i = 0; i < n; ++i) {
        cin >> ps[i].u >> ps[i].v;
        ps[i].h = i;
    }

    for (int i = 1; i < n; ++i) {
        int tmp = i - 1;
        while (tmp >= 0) {
//            && !(ps[tmp] < ps[i])
            if ( !(ps[tmp--] < ps[i])) {
                --ps[i].h;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        res[ps[i].h] += 1;
    }

    for (int i = 0; i < n; ++i) {
        cout << res[i] << '\n';
    }
}