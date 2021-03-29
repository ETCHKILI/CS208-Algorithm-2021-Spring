#include<bits/stdc++.h>

using namespace std;
#define maxn 100010
#define ll long long
#define ms(a) memset(a,0,sizeof(a))
typedef pair<int, int> P;
typedef vector<int> ve;

template<typename tp>
inline void read(tp &dig) {
    char ch = getchar();
    int flag = 0;
    dig = 0;
    while (!isdigit(ch)) {
        if (ch == '-')flag = 1;
        ch = getchar();
    }
    while (isdigit(ch))dig = dig * 10 + ch - '0', ch = getchar();
    if (flag)dig = -dig;
}

int n, m, T,  Max;
char s[10005];
int datas[30][30];
int cnts[30];
int stk[30];
int stkIndex = 0;

void dfs(int now, int ans) {
    if (now == 26) {
        Max = max(Max, ans);
        return;

    }
    if (now == 0 || now == 4 || now == 8 || now == 14 || now == 20) {
        dfs(now + 1, ans);
        return;
    }
    dfs(now + 1, ans);

    ans += cnts[now];

    for (int i = 0; i <= stkIndex; i++) {
        ans -= 2*datas[stk[i]][now];
    }
    stkIndex++;
    stk[stkIndex] = now;

    dfs(now + 1, ans);
    stkIndex--;


}

int main() {
    scanf("%d", &T);
    while (T--) {

        ms(cnts);
        ms(stk);
        stkIndex = 0;
        Max = 0;

        scanf("%s", s);
        int len = strlen(s);

        for (int j = 0; j < 27; ++j) {
            for (int i = 0; i < 27; ++i) {

                datas[i][j] = 0;
            }
        }

        for (int i = 0; i < len - 1; i++) {
            int a = s[i] - 'a';
            int b = s[i + 1] - 'a';
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i + 1] == 'a' ||
                s[i + 1] == 'e' || s[i + 1] == 'i' || s[i + 1] == 'o' || s[i + 1] == 'u')
                continue;
            if (a != b) {
                datas[a][b]++;
                datas[b][a]++;
            }
        }
        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                cnts[k] += datas[k][i];
            }
        }


        dfs(1, 0);


        printf("%d\n", Max);
    }


}