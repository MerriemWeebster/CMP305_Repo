#include <iostream>
#include<cmath>
using namespace std;
bool isPrime(int n, int x = 2) {
    if (n % x == 0) return false;
    if (x > sqrt(n)) return true;
    return isPrime(n, x + 1);
}

int main() {
    int n = 1223;
    if (isPrime(n)) cout << n << " is prime!!!" << endl;
    else cout << n << " is NOT prime!" << endl;
    return 0;
}