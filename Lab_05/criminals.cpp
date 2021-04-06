#include <iostream>
#include <algorithm>


using namespace std;

int main() {
    int n, m, k, t;
    cin >> n >> m >> k >> t;

    int c_p[n]; //criminals_position
    int h_p[m]; //houses_position
    int h_c[m]; //home_capacity
    for (int i = 0; i < n; ++i) {
        cin >> c_p[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> h_p[i];
        h_c[i] = 0;
    }

    sort(c_p, c_p + n);
    sort(h_p, h_p + m);

    int i = 0;
    int j = 0;
    int result = 0;
    while(i < n, j < m) {
        if (abs(c_p[i] - h_p[j]) <= t) {
            if (h_c[j] < k) {
                ++result;
                ++i;
                ++h_c[j];
            } else {
                ++j;
            }
        } else {
            if (c_p[i] < h_p[j]) {
                ++i;
            } else {
                ++j;
            }
        }
    }

    cout << result << '\n';
}