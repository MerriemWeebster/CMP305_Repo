#include <iostream>
using namespace std;

//Q1
/*
double Harmonic(int n) {
    if (n == 1) return 1;
    if (n % 2 == 0) return ((-1.0 / n) + Harmonic(n - 1));
    else return ((1.0 / n) + Harmonic(n - 1));
}
*/
double Harmonic(double n) {
    if (n == 1) return 1;
    return 1.0 / n + Harmonic(n - 1);
}
/*
int main(){
    cout << Harmonic(3);
    return 0;
}*/