#include <iostream>
#include <algorithm>
#include <>

using namespace std;

struct Task {
    int ddl;
    int penalty;
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
//        auto ddls = new int[n];
//        auto penalties = new int[n];
        auto tasks = new Task[n];
        for (int i = 0; i < n; ++i) {
            cin >> tasks[i].ddl;
        }
        for (int i = 0; i < n; ++i) {
            cin >> tasks[i].penalty;
        }
        sort(tasks, tasks + n, [](Task &a, Task &b) {return a.ddl < b.ddl;});


        for (int i = 0; i < n; ++i) {
            if ()
        }
    }
}