#include <iostream>

using namespace std;

int half = 0;

int Cor(int *cont) {
    int hal = half;
    int num = 0;

    for (int i = 0; i < 3; ++i) {
        if (cont[i] == hal){
            num++;
        }
    }

    if (num == 2) {
        return 1;
    } else {
        return 0;
    }
}

void Pour(int *capacity, int *content, int a, int b) {
    int left = content[a];
    int space = capacity[b] - content[b];
    if (left > space) {
        content[b] = capacity[b];
        content[a] -= space;
    } else {
        content[a] = 0;
        content[b] += left;
    }
}

int Rec(int *capacity, int *content) {
    if (Cor(content)){
        return 0;
    }
    if (content[1] == 0 && content[2] == capacity[2]) {
        return -1;
    }
    if (content[1] == 0) {
        Pour(capacity, content, 0, 1);
    } else if (content[2] == capacity[2]) {
        Pour(capacity, content, 2, 0);
    } else {
        Pour(capacity, content, 1, 2);
    }

    int sub = Rec(capacity, content);
    if (sub == -1){
        return -1;
    } else {
        return sub + 1;
    }
}

void Swap(int *arr, int a, int b) {
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

int main() {
    int t = 0;
    cin >> t;

    int cap[3];
    int cont[3];
    int res_a = 0, res_b = 0, res = 0;
    while(t--) {
        cin >> cap[0] >> cap[1] >> cap[2];

        if (cap[0] % 2){
            cout << "impossible" << '\n';
            continue;
        }

        half = cap[0] / 2;

        cont[0] = cap[0];
        cont[1] = cont[2] = 0;
    
        res_a = Rec(cap, cont);
        Swap(cap, 1, 2);
        cont[0] = cap[0];
        cont[1] = cont[2] = 0;
        res_b = Rec(cap, cont);

        if (res_a < 0) {
            res_a = 0x7fffffff;
        }
        if (res_b < 0) {
            res_b = 0x7fffffff;
        }

        res = min(res_a, res_b);
        if (res == 0x7fffffff) {
            cout << "impossible" << '\n';
        } else {
            cout << res << '\n';
        }

    }

    return 0;
}

