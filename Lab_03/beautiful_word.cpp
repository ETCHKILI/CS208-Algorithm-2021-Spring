#include <iostream>
#include <string>

#define GET_CHART(a, b) chart[(a) * count + (b)]

using namespace std;

inline bool IsConsonants(char a) {
    return (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u');
}

int Dfs(int index, bool *check, int *chart, int count, int res) {
    int tmp_res = res;
    auto tmp_check = new bool[count];

    for (int i = 0; i < count; ++i) {
        tmp_check[i] = check[i];
    }
    tmp_check[index]= true;

    for (int i = 0; i < count; ++i) {
        if (i != index) {
            tmp_res += GET_CHART(index, i);
        }
    }
    for (int i = 0; i < index; ++i) {
        if (check[i]) {
            tmp_res -= 2 * (GET_CHART(index, i));
        }
    }

    if (index == count-1) {
        return max(tmp_res, res);
    }

    ++index;
    int ans1 = Dfs(index, tmp_check, chart, count, tmp_res);
    int ans2 = Dfs(index, check, chart, count, res);

    delete [] tmp_check;
    return max(ans1, ans2);
}

int main() {
    int t;
    cin >> t;
    cin.ignore();

    string line;
    while (t--) {
        getline(cin, line);
        if (line.size() == 1){
            cout << "0\n";
            continue;
        }

        int my_map[26];
        for (int i = 0; i < 26; ++i) {
            my_map[i] = -1;
        }

        int count = 0;

        for (int i = 0; i < line.size(); ++i) {
            if (IsConsonants(line[i])) {
                continue;
            }
            if (my_map[line[i]-'a'] == -1){
                my_map[line[i]-'a'] = count;
                count++;
            }
        }

        if (count == 0 || count == 1){
            cout << "0\n";
            continue;
        }

        auto check = new bool[count];
        for (int i = 0; i < count; ++i) {
            check[i] = false;
        }

        auto chart = new int[count * count]{0};
        int n, m;
        for (int i = 0; i < line.size() - 1; ++i) {
            if (IsConsonants(line[i]) || IsConsonants(line[i+1])) {
                continue;
            }

            n = my_map[line[i]-'a'];
            m = my_map[line[i+1]-'a'];
            GET_CHART(n, m) += 1;
            GET_CHART(m, n) += 1;
        }

        int res = Dfs(0, check, chart, count, 0);
        cout << res << '\n';

        delete [] check;
        delete [] chart;
    }
}