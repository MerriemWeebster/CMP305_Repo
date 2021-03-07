#include<iostream>
#include"SortedList.h"
using namespace std;

int main() {

	SortedClass<int> arr;
	for (int i = 1; i <= 5; i++) {
		arr.insert(i);
	}
	arr.insert(7);
	arr.insert(6);// Insert in the middle
	arr.insert(0);// Insert at the start
	for (auto i = arr.begin(); i != arr.end(); i++) {
		cout << *i << " ";
	}
	cout << endl;
	arr.erase(4);
	for (auto i = arr.begin(); i != arr.end(); i++) {	cout << *i << " "; }

	return 0;
}