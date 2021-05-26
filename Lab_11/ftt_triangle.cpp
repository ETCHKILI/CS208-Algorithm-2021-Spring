//
// Created by GuoYubin on 2021/5/19.
//

#include <iostream>
#include <algorithm>
#include <cmath>

#define PI acos(-1.0)

using namespace std;

struct complex {
    double r,i;
    explicit complex(double r = 0,double i = 0) : r(r), i(i) {
    }
    complex operator +(const complex &b) const {
        return complex(r+b.r,i+b.i);
    }
    complex operator -(const complex &b) const {
        return complex(r-b.r,i-b.i);
    }
    complex operator *(const complex &b) const {
        return complex(r*b.r-i*b.i,r*b.i+i*b.r);
    }
};

void InitComplex(complex *pComplex, int size) {
    int i,j,k;
    for (i = 1, j = size / 2; i < size - 1; i++) {
        if(i < j) {
            swap(pComplex[i], pComplex[j]);
        }
        k = size / 2;
        while( j >= k) {
            j -= k;
            k /= 2;
        }
        if(j < k) {
            j += k;
        }
    }
}
void FFT(complex *y, int size, int flag) {
    InitComplex(y, size);
    for(int i = 2; i <= size; i <<= 1) {
        complex c0(cos(-flag * 2 * PI / i), sin(-flag * 2 * PI / i));
        for(int j = 0; j < size; j += i) {
            complex c1(1, 0);
            for(int k = j; k < j + i / 2; k++) {
                complex c2 = y[k];
                complex c3 = y[k + i / 2] * c1;

                c2 = c2 + c3;
                c3 = c2 - c3 - c3;

                y[k] = c2;
                y[k + i / 2] = c3;
                c1 = c1 * c0;
            }
        }
    }

    int i = 0;
    while (flag == -1) {
        if (i < size) {
            y[i].r /= size;
            ++i;
        } else {
            flag = 0;
        }
    }
}

const int kArrSize = 400000;
complex x[kArrSize];
int l[kArrSize / 4];
long long num[kArrSize];
long long pre_sum[kArrSize];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < kArrSize; ++i) {
        num[i] = 0;
        pre_sum[i] = 0;
    }
    for(int i = 0;i < n;i++) {
        cin >> l[i];
        ++num[l[i]];
    }


    sort(l, l + n, less<>());
    int len1 = l[n - 1] + 1;
    int len2 = 1;
    while(len2 < 2 * len1 ) {
        len2 <<= 1;
    }
    for(int i = 0;i < len1;i++) {
        x[i] = complex(num[i], 0);
    }


    for(int i = len1; i < len2; i++) {
        x[i] = complex(0, 0);
    }
    FFT(x, len2, 1);
    for(int i = 0; i < len2; i++) {
        x[i] = x[i] * x[i];
    }
    FFT(x, len2, -1);


    for(int i = 0; i < len2; i++) {
        num[i] = floor(x[i].r + 0.5);
    }
    len2 = 2 * l[n - 1];


    for(int i = 0;i < n;i++) {
        num[l[i] * 2]--;
    }


    for(int i = 1; i <= len2; i++) {
        num[i] = num[i] / 2;
    }


    for(int i = 1; i <= len2; i++) {
        pre_sum[i] = pre_sum[i - 1] + num[i];
    }
    long long res = 0;

    for(int i = 0;i < n;i++) {
        res += pre_sum[len2] - pre_sum[l[i]];
        res -= (long long)(n - 1 - i) * i;
        res -= (n - 1);
        res -= (long long)(n - 1 - i) * (n - i - 2) / 2;
    }

    cout << res;

    return 0;
}