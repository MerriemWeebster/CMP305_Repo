#include<iostream>
using namespace std;

double PIAcc(int n = 3, double acc = 3.0)
{
    if(n == 0) return acc;

    int den = 2 * n;
    double fraction = 4.0/((den) * (den+1) * (den+2));

    acc += (n % 2 == 0 ? -1 : 1) * fraction;

    return PIAcc(--n, acc);
}

double PI(int n = 3)
{
    if(n == 0) return 3.0;

    int den = 2 * n;
    double fraction = 4.0/((den) * (den+1) * (den+2));

    fraction *= (n % 2 == 0 ? -1 : 1);

    return fraction + PI(--n);
}

int main()
{
    int n;
    cout << "Enter how many terms of PI to calculate: ";
    cin >> n;

    cout << PI(n);

    return 0;
}