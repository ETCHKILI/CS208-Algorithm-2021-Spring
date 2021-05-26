//
// Created by GuoYubin on 2021/4/27.
//
#include <iostream>

using namespace std;

void ToBinary(int src, short *dst) {
    int one = 1;
    for (int i = 0; i < 31; ++i) {
        dst[i] = src & one;
        src >>= 1;
    }
}

int ToDecimal(const short *src) {
    int dst = 0;
    for (int i = 0; i < 31; ++i) {
        dst += src[i] << i;
    }

    return dst;
}

int Calculate(const string& s,int k1, int k2) {
    if (s == "AND") {
        return k1 & k2;
    } else if (s == "OR") {
        return k1 | k2;
    } else {
        return k1 ^ k2;
    }
}

void Check(short m_bin, short r_zero, short r_one, bool &flag, short &ans) {
    if (flag) {
        ans = max(r_zero, r_one);
    } else if (m_bin == 0) {
        ans = r_zero;
    } else if (m_bin == 1) {
        ans = max(r_zero, r_one);
        flag = (ans == 0);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    short m_bin[31];
    string ops[n];
    short nums[n][31];

    auto result = new short *[2];
    result[0] = new short [31] {0};
    result[1] = new short [31] {1};

    short ans[32];

    ToBinary(m, m_bin);
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> ops[i];
        cin >> tmp;
        ToBinary(tmp, nums[i]);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 31; ++j) {
            result[0][j] = Calculate(ops[i], result[0][j], nums[i][j]);
            result[1][j] = Calculate(ops[i], result[1][j], nums[i][j]);
        }
    }

    bool flag = false;
    for (int i = 30; i >= 0; --i) {
        Check(m_bin[i], result[0][i], result[1][i], flag, ans[i]);
    }

    int final = ToDecimal(ans);
    cout << final;
}

