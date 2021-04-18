#include<iostream>
using namespace std;

template <typename Object>
struct BinaryNode
{
    Object element;
    BinaryNode* left;
    BinaryNode* right;

    BinaryNode(const Object& theElement, BinaryNode* lt = nullptr, BinaryNode* rt = nullptr)
        : element{ theElement }, left{ lt }, right{ rt } { }

};

template <typename Object>
void ArrayToTree(BinaryNode<Object>*& tree, Object arr[], int size, int startIndex) {
    if (size == 0) return;
    if (startIndex == 0) { tree = new BinaryNode<Object>(arr[0]); }
    if (startIndex * 2 + 1 < size) {
        tree->left = new BinaryNode<Object>( arr[startIndex * 2 + 1]);
        ArrayToTree(tree->left, arr, size, startIndex * 2 + 1);
            if (startIndex * 2 + 2 < size) {
                tree->right = new BinaryNode<Object>(arr[startIndex * 2 + 2]);
                ArrayToTree(tree->right, arr, size, startIndex * 2 + 2);
            }
    }
}

template <typename Object>
void treeToArray(BinaryNode<Object>* tree, Object values[], int index=0) {

    if (tree == nullptr) return;
    values[index] = tree->element;
    if (tree->left != nullptr) {
        values[2 * index + 1] = tree->left->element;
        treeToArray(tree->left, values, 2 * index + 1);
    }
    if (tree->right != nullptr) {
        values[2 * index + 2] = tree->right->element;
        treeToArray(tree->right, values, 2 * index + 2);
    }
}

template <typename Object>
void printTree(BinaryNode<Object>* node)
{
    cout << node->element << " ";
    if (node->left != nullptr) {
        printTree(node->left);
    }
    
    if (node->right != nullptr) {
        printTree(node->right);
    }

}

int main(){
   
    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
    BinaryNode<int>* tree;
    ArrayToTree(tree, arr, 10, 0);
    printTree(tree);
    cout << endl;
    int newarr[10];
    treeToArray(tree,newarr);
    for (int x : newarr) {
        cout << x << " ";
    }

    return 0;
}