#include <iostream>
using namespace std;

void IntegerPalindrome(int value) {
    cout << value;
    if (value == 9) return;
    IntegerPalindrome(value + 1);
    cout << value;
}
/*
int main() {
    IntegerPalindrome(5);
    return 0;
}*/