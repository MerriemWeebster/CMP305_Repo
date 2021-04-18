#include<iostream>
using namespace std;

template <typename Object>
struct TreeNode
{
    Object element;
    TreeNode *firstChild;
    TreeNode *nextSibling;
    TreeNode(const Object & e = Object{ }, TreeNode * first = nullptr, TreeNode * next = nullptr)
        : element{ e }, firstChild{ first }, nextSibling{next}{ }

};

template <typename Object>
int depth(TreeNode<Object>* root, TreeNode<Object>* node, int dep = 0) {
    if (root == node) return dep;
    if (root == nullptr) return 0;
    int dep1 = 0, dep2 = 0;
    if (root->nextSibling != nullptr) {
        dep1 = depth(root->nextSibling, node, dep);
    }
    if (root->firstChild != nullptr) {
        dep2 = depth(root->firstChild, node, dep + 1);
    }
    if (dep1 > dep2) return dep1;
    else return dep2;
}


template <typename Object>
int height(TreeNode<Object> *node, int d=0)
{
  int hSibling = -1, hChild = -1;

  if(node->nextSibling != nullptr)
    hSibling = height(node->nextSibling, d);

  if(node->firstChild != nullptr)
    hChild = height( node->firstChild, d + 1);

  int hMax = (hSibling > hChild) ? hSibling : hChild;

  return (hMax > d) ? hMax : d;
}

int main()
{
    TreeNode<char> *root = new TreeNode<char>('A', nullptr,nullptr);
    TreeNode<char> *b = new TreeNode<char>('B', nullptr, nullptr);
    TreeNode<char> *c = new TreeNode<char>('C', nullptr, nullptr);
    TreeNode<char> *d = new TreeNode<char>('D', nullptr, nullptr);
    TreeNode<char> *e = new TreeNode<char>('E', nullptr, nullptr);
    TreeNode<char> *f = new TreeNode<char>('F', nullptr, nullptr);
    TreeNode<char> *g = new TreeNode<char>('G', nullptr, nullptr);
    TreeNode<char> *h = new TreeNode<char>('H', nullptr, nullptr);
    TreeNode<char> *i = new TreeNode<char>('I', nullptr, nullptr);
    TreeNode<char> *j = new TreeNode<char>('J', nullptr, nullptr);
    TreeNode<char> *k = new TreeNode<char>('K', nullptr, nullptr);
    TreeNode<char> *l = new TreeNode<char>('L', nullptr, nullptr);
    TreeNode<char> *m = new TreeNode<char>('M', nullptr, nullptr);
    TreeNode<char> *n = new TreeNode<char>('N', nullptr, nullptr);
    TreeNode<char> *o = new TreeNode<char>('O', nullptr, nullptr);
    TreeNode<char> *p = new TreeNode<char>('P', nullptr, nullptr);
    TreeNode<char> *q = new TreeNode<char>('Q', nullptr, nullptr);
    
    root->firstChild = b;
    b->nextSibling = c;
    c->nextSibling = d;
    d->firstChild = h;
    d->nextSibling = e;
    e->firstChild = i;
    e->nextSibling = f;
    f->firstChild = k;
    f->nextSibling = g;
    g->nextSibling = n;
    n->firstChild = o;
    o->nextSibling = p;
    o->firstChild = q;

    cout << "The height of the tree is: " << height(root) << endl;
    cout << "The depth of node Q is: " << depth(root, q) << endl;
    cout << "The depth of node O is: " << depth(root, o) << endl;
    cout << "The depth of node D is: " << depth(root, d) << endl;
    cout << "The depth of node A is: " << depth(root, root) << endl;
}