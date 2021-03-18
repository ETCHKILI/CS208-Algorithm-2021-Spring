#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        auto arr = new int[n];
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        sort(arr, arr+n, [](int a, int b){return a > b;});
        int res = unique(arr, arr+n) - arr;

        int maxv = arr[0];
        for (int i = 1; i < res; ++i) {
            if (arr[0] % arr[i]){
                maxv += arr[i];
                for (int j = i+1; j < res; ++j) {
                    if (arr[0] % arr[j] && arr[i] % arr[j]){
                        maxv += arr[j];
                        break;
                    }
                }
                break;
            }
        }

        int ots = 0;
        for (int i = 1; i < res; ++i) {
            if (arr[i] * 2 == arr[0] || arr[i] * 3 == arr[0] || arr[i] * 5 == arr[0]){
                ots += arr[i];
            }
        }

        cout << max(ots, maxv) << '\n';
        
    }
    
    

}