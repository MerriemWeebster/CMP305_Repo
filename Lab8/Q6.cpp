#include <iostream>
#include<utility>
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
pair<Object, Object> findMinMax(SingleNode<Object>* lst, Object min, Object max) {
    if (lst == nullptr) return make_pair(min, max);
    if (lst->data >= max) max = lst->data;
    if (lst->data <= min) min = lst->data;
    
    return findMinMax(lst->next, min, max);
}

/*
int main() {
    int arr[5] = { 1,2,3,4,5 };
    SingleNode<int>* l1 = createSLL(arr, 5);
    
    pair<int, int> result = findMinMax(l1, l1->data, l1->data);
    cout << "The minimum is: " << result.first << endl;
    cout << "The maximum is: " << result.second << endl;

    return 0;
}*/