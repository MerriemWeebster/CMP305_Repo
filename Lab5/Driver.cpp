#include<iostream>
#include"SortedList.h"
using namespace std;

int main() {

	SortedClass<int> arr1; // 1,2,3,5,7,9
	SortedClass<int> arr2; // 1,2,3,4,6,8,10

	int arr1ele[6] = { 1,2,3,5,7,9 };
	int arr2ele[7] = { 1,2,3,4,6,8,10 };
	for (int x : arr1ele) {
		arr1.insert(x);
	}
	for (int x : arr2ele) {
		arr2.insert(x);
	}
	cout << "Array 1 contains:" << endl;
	for (auto i = arr1.begin(); i != arr1.end(); i++) { cout << *i << " "; }
	cout << endl << "Array 2 contains:" << endl;
	for (auto i = arr2.begin(); i != arr2.end(); i++) { cout << *i << " "; }
	

	SortedClass<int>* inter = intersection(arr1, arr2);
	cout << endl << "Intersection contains:" << endl;
	for (auto i = inter->begin(); i != inter->end(); i++) { cout << *i << " "; }

	SortedClass<int>* uni = Union(arr1, arr2);
	cout << endl << "Union contains:" << endl;
	for (auto i = uni->begin(); i != uni->end(); i++) { cout << *i << " "; }

	
	return 0;
}