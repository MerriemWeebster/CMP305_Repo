#include<iostream>
#include"BinarySearchTree.h"
using namespace std;

int main() {

	BinarySearchTree<int> bst{};
	bst.insert(5);
	bst.insert(2);
	bst.insert(3);
	bst.insert(1);
	bst.insert(8);
	bst.insert(6);
	bst.insert(9);
	cout << "BST Before Mirror: " << endl;
	bst.printTree();

	cout << "BST After Mirror: " << endl;
	bst.mirror();
	bst.printTree();
	
	cout << endl << endl;
	if (bst.isFull()) cout << "The BST is Full!" << endl;
	else cout << "The BST is NOT Full!" << endl;

	return 0;
}