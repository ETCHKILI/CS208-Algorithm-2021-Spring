//
// Created by GuoYubin on 2021/4/28.
//
using namespace std;

#include <iostream>
#include "number_game_no_trick.cpp"

int main() {
    short src[31] {0};
    src[0] = 1;
    src[3] = 1;
    int i = ToDecimal(src);

    cout << i;
}