#include <iostream>
#include <hash_map>
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore(100,'\n');

    unordered_map<string, int> boy_map;
    unordered_map<string, int> girl_map;

    int boy_pref[n][n];
    int girl_pref[n][n];
    string boys[n];
    string girls[n];
    int girls_hus[n];
    int boys_run[n];

    for (int i = 0; i < n; ++i) {
        girls_hus[i] = n+1;
        boys_run[i]=0;
    }

    string temp;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        boy_map.emplace(temp,i);
        boys[i] = temp;
    }
    cin.ignore(100,'\n');
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        girl_map.emplace(temp,i);
        girls[i] = temp;
    }
    cin.ignore(100,'\n');

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> temp;
            boy_pref[i][j] = girl_map.find(temp)->second;
        }
        cin.ignore(100,'\n');
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> temp;
            girl_pref[i][boy_map.find(temp)->second] = j;
        }
        cin.ignore(100,'\n');
    }

    stack<int> order;
    for (int i = n-1; i >= 0; --i) {
        order.push(i);
    }

    int boy_id;
    int girl_id;
    while(!order.empty()){
        boy_id = order.top();
        for (int i = boys_run[boy_id]; i < n; ++i) {
            girl_id = boy_pref[boy_id][i];
            if (girls_hus[girl_id] >= n || girl_pref[girl_id][boy_id] < girl_pref[girl_id][girls_hus[girl_id]]){
                boys_run[boy_id] = i + 1;
                if (girls_hus[girl_id] >= n){
                    order.pop();
                    girls_hus[girl_id] = boy_id;
                    break;
                }else{
                    order.pop();
                    order.push(girls_hus[girl_id]);
                    girls_hus[girl_id] = boy_id;
                    break;
                }
            }
        }
    }

    string res[n][2];
    for (int i = 0; i < n; ++i) {
        boy_id = girls_hus[i];
        res[boy_id][0] = boys[boy_id];
        res[boy_id][1] = girls[i];
    }
    for (int i = 0; i < n; ++i) {
        cout << res[i][0] << " " << res[i][1] << "\n";
    }

}

