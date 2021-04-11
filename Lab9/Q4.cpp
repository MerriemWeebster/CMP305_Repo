#include<iostream>
#include<vector>
using namespace std;

//Q4)a)
double calculate(vector<double>::iterator it1, vector<double>::iterator it2, double sum = 0) {
	if (it1 >= --it2) return (sum);
	sum += (*it1) + (*it2);
	return calculate(++it1, it2, sum);
}


//Q4)b)
template< typename Iter, typename Value >
Value Sum(Iter it1, Iter it2, Value sum) {
	if (it1 >= --it2) return (sum);
	sum += (*it1) + (*it2);
	return calculate(++it1, it2, sum);
}

int main() {
	vector<double> arr = { 1,2,3,4,5,6,7,8,9,10 };
	cout << Sum(arr.begin(), arr.end()) << endl;
	return 0;
}