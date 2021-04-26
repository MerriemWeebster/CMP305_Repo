#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

int childrenDiff(int threshold, BinaryNode* node)
{
    int count = 0;

    if(node != nullptr)
    {
        if(node->left != nullptr)
            count += childrenDiff(threshold, node->left);

        if(node->right != nullptr)
            count += childrenDiff(threshold, node->right);

        if(node->left != nullptr && node->right != nullptr)
        {
            if(node->left->element - node->right->element > threshold || node->right->element - node->left->element > threshold)
                count++;
        }
    }

    return count;
}

bool isSumOfPath(int sum, BinaryNode* node, int value = 0)
{
    if(node != nullptr)
    {
        value += node->element;
        return (isSumOfPath(sum, node->left, value) || isSumOfPath(sum, node->right, value));
    }
    else
    {
        return value == sum;
    }
}

int main() {

	BinarySearchTree<int> bst{};
	bst.insert(5);
	bst.insert(2);
	bst.insert(3);
	bst.insert(1);
	bst.insert(8);
	bst.insert(6);
	bst.insert(9);
	
    


	return 0;
}