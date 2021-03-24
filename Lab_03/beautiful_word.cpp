#include <iostream>
#include <string>

#define GET_ARR(a, b) arr[(a) * N + (b)] 

using namespace std;

inline bool IsConsonants(char a) {
    return (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u');
}

class TARR {
    public:
    TARR(int row, int col):row_(row), col_(col) {
        arr_ = new int [row * col]();
    }
    int *operator[](int a) {
        return arr_ + a * row_;
    }
    
    int *arr_;
    int row_;
    int col_;
};


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
        for (int i = 0; i < line.size() - 1; ++i) {
            for (int j = 1; j < line.size(); ++j) {
                
            }
        }
        
    }


}