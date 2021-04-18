#include <iostream>
using namespace std;
template <typename Object>
struct BinaryNode
{
    Object element;
    BinaryNode *left;
    BinaryNode *right;

    BinaryNode(const Object & theElement, BinaryNode *lt = nullptr, BinaryNode *rt = nullptr)
        : element{ theElement }, left{ lt }, right{ rt } { }

};

template <typename Object>
void MakeTree(string expr, BinaryNode<Object> *node, int& pos);

template <typename Object>
void preFix(BinaryNode<Object>* node);

template <typename Object>
void postFix(BinaryNode<Object>* node);

template <typename Object>
void inFix(BinaryNode<Object>* node);


int main()
{
    string a = "(((a+b)*c)+(((d-e)*f)/g))";
    int index = 0;
    
    BinaryNode<char>* root = new BinaryNode<char>(' ');
    int pos = 0;


    MakeTree(a, root, index);

    cout << "Expression = " << a << "\n\n";

    cout << "InFix equivalent: ";
    inFix(root);
    

    cout << "\n\nPostFix equivalent: ";
    postFix(root);

    cout << "\n\nPreFix equivalent: ";
    preFix(root);
    cout << "\n\n";
    
    return 0;
    
}

//A recursive function that takes an expression and makes the tree
template <typename Object>
void MakeTree(string expr, BinaryNode<Object> *node, int& pos)
{
    if (expr[pos] == '(')
    {
        pos++;
        node->left = new BinaryNode<char>('0');
        node->left->left = NULL;
        node->left->right = NULL;
        MakeTree(expr, node->left, pos);
        MakeTree(expr, node, pos);
        return;
    }

    if (expr[pos] >= 'a' && expr[pos] <= 'z')
    {

        node->element = expr[pos];
        pos++;
        return;
    }

    if (expr[pos] == '+' || expr[pos] == '-' || expr[pos] == '*' || expr[pos] == '/')
    {

        node->element = expr[pos];
        pos++;
        node->right = new BinaryNode<char>('0');
        node->right->left = NULL;
        node->right->right = NULL;
        MakeTree(expr, node->right, pos);
    }

    if (expr[pos] == ')')
    {
        pos++;
        return;
    }
}

template <typename Object>
void preFix(BinaryNode<Object>* node)
{
    if(node->element=='*'|| node->element == '/'|| node->element == '+'|| node->element == '-')
        cout << "(";
    cout << node->element << " ";
    if (node->left != nullptr) {
        preFix(node->left);
    }

    if (node->right != nullptr) {
        preFix(node->right);
        cout << ")";
    }
}
template <typename Object>
void inFix(BinaryNode<Object>* node)
{
    if (node->left != nullptr) {
        cout << "(";
        inFix(node->left);
    }
    cout << node->element;
    if (node->right != nullptr) {
        inFix(node->right);
        cout << ")";
    }
    
}
template <typename Object>
void postFix(BinaryNode<Object>* node)
{
    if (node->left != nullptr) {
        postFix(node->left);
    }
    
    if (node->right != nullptr) {
        postFix(node->right);
    }
    cout << node->element<<" ";
}

