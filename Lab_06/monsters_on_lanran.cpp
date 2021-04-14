#include <iostream>
#include <climits>

using namespace std;
int main() {
    int n = 0;
    cin >> n;
    long long tmp;
    bool all_neg = true;
    bool all_pos = true;
    long long min_val = LONG_LONG_MAX;
    long long sum = 0;

    if (n == 1) {
        cin >> tmp;
        cout << tmp;
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        if (tmp < 0) {
            all_pos = false;
        } else if (tmp > 0){
            all_neg = false;
        }
        sum += abs(tmp);
        min_val = min(min_val, abs(tmp));
    }

    if (all_neg || all_pos) {
        sum -= 2 * min_val;
    }

    cout << sum;
    return 0;
}