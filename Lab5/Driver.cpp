#include<iostream>
#include"SortedList.h"
using namespace std;

int main() {

	SortedClass<int> arr;
	for (int i = 1; i <= 5; i++) {
		arr.insert(i);
	}
	for (auto i = arr.begin(); i != arr.end(); i++) {
		cout << *i << " ";
	}
	return 0;
}