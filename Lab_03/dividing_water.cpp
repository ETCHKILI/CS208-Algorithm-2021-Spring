#include <iostream>

using namespace std;


int Solution(int a, int b) {
    for (int i = min(a, b); i > 1; --i) {
        if (!(a % i) && !(b % i)) {
            a /= i;
            b /= i;
            break;
        }
    }

    if ((a + b) & 1) {
        return -1;
    } else {
        return a + b - 1;
    }

}

int main() {
    int t = 0;
    cin >> t;
    int s = 0, n = 0, m = 0, ans = 0;
    while (t--) {
        cin >> s >> n >> m;
        ans = Solution(n, m);
        if (ans == -1) {
            cout << "impossible\n";
        } else {
            cout << ans << '\n';
        }




    }
}