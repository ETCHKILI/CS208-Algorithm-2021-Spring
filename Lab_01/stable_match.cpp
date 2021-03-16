#include <iostream>
#include <hash_map>
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    unordered_map<string, int> boy_map;
    unordered_map<string, int> girl_map;

    int boy_pref[n][n];
    int girl_pref[n][n];
    string boys[n];
    string girls[n];
    int girls_hus[n];

    for (int i = 0; i < n; ++i) {
        girls_hus[i] = n+1;
    }

    string temp;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        boy_map[temp] = i;
        boys[i] = temp;
    }
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        girl_map[temp] = i;
        girls[i] = temp;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> temp;
            boy_pref[i][j] = boy_map[temp];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> temp;
            girl_pref[i][girl_map[temp]] = j;
        }
    }

    stack<int> order;
    for (int i = n-1; i >= 0; --i) {
        order.push(i);
    }

    while(!order.empty()){
        int tmp = order.top();

    }


}

