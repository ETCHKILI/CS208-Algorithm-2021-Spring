#include <iostream>
#include <algorithm>
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

int Rec(int * capacity, int *content) {
    if (Cor(content)){
        return 0;
    }
    if ()
}



int main() {
    int t = 0;
    cin >> t;

    int cap[3];
    int cont[3];
    while(t--) {
        cin >> cap[0] >> cap[1] >> cap[2];

        if (cap[0] % 2){
            cout << "impossible" << '\n';
            continue;
        }



        Rec(cap, cont);






    }
}

