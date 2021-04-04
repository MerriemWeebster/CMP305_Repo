#include <iostream>
using namespace std;

template <typename Object>
struct SingleNode {
    Object  data;
    SingleNode* next;

    SingleNode(const Object& d = Object{}, SingleNode* n = nullptr) //constructor initializing data to empty object and
        : data{ d }, next{ n } { } //next pointer to null
};

template <typename Object>
SingleNode<Object>* createSLL(Object ary[], int size) //arguments are array of Object and size of array
{
    SingleNode<Object>* first = new SingleNode<Object>(ary[0]); //create structure instance and point to first element of array
    SingleNode<Object>* temp = first; //create temp instance and point to first element of array
    for (int i = 1; i < size; i++)
    {
        SingleNode<Object>* node = new SingleNode<Object>(ary[i]); //create instances called nodes and point to array elements
        temp->next = node; //next pointer of first element points to node
        temp = node; //with each iteration, the previous node's next pointer will point to current node
    }
    return first; //return pointer to first element of array

}

template <typename Object>
void printSLL(SingleNode<Object>* head)
{
    while (head != nullptr)
    {
        cout << head->data << "\t";
        head = head->next;
    }
    cout << endl;
}

template <typename Object>
bool isEqual(SingleNode<Object>* l1, SingleNode<Object>* l2) {
    if (l1 == nullptr && l2 == nullptr) return true;
    if (l1 == nullptr || l2 == nullptr) return false;
    isEqual(l1->next, l2->next);
}
/*
int main() {
    int arr[5] = { 1,2,3,4,5 };
    int arr2[5] = { 1,2,3,4,5 };
    int arr3[6] = { 1,2,3,4,5,6 };
    SingleNode<int>* l1 = createSLL(arr,5);
    SingleNode<int>* l2 = createSLL(arr2, 5);
    SingleNode<int>* l3 = createSLL(arr3, 6);

    cout << "l1 and l2:" << endl;
    if(isEqual(l1, l2)) cout << "THEY ARE EQUAL!" << endl;
    else cout << "THEY ARE NOT EQUAL!" << endl;

    cout << "l1 and l3:" << endl;
    if (isEqual(l1, l3)) cout << "THEY ARE EQUAL!" << endl;
    else cout << "THEY ARE NOT EQUAL!" << endl;
    return 0;
}*/