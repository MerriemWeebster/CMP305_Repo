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
int height(TreeNode<Object> *node, int d=0)
{
  if(node->firstChild != nullptr)
  {
    if(node->nextSibling == nullptr)
      return height(node->firstChild, d + 1);
    else
    {
      int hSibling = height(node->nextSibling, d), hChild = height( node->firstChild, d + 1);
      return (hSibling > hChild) ? hSibling : hChild;
    }
  }
  else
  {
    if(node->nextSibling == nullptr)
      return d;
    else
      return height(node->nextSibling, d);
  }
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
    TreeNode<char> *o = new TreeNode<char>('N', nullptr, nullptr);
    TreeNode<char> *p = new TreeNode<char>('N', nullptr, nullptr);
    TreeNode<char> *q = new TreeNode<char>('N', nullptr, nullptr);
    
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
    
  //Continue creating TreeNodes

}


