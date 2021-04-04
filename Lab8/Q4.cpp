#include <iostream>
using namespace std;

void toBin(int dec) {
    if (dec == 0) return;
    toBin(dec / 2);
    cout << dec % 2;
}
/*
int main() {
    toBin(252);
    return 0;
}*/