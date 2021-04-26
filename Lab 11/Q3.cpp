#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

int main() {

	BinarySearchTree<int> bst{};
	bst.insert(5);
	bst.insert(4);
	bst.insert(3);
	bst.insert(1);
	bst.insert(8);
	bst.insert(6);
	bst.insert(9);
	
	cout << "The number of nodes where the difference between children is more than 2 is: " << bst.childrenDiff(2) << endl;
	
	if (bst.isSumOfPath(19)) cout << "There is a path with values that add to 19" << endl;
	else cout << "There is no path with value that add to 19" << endl;
    
	return 0;
}