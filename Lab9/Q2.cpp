#include <iostream>
#include <string>
using namespace std;

//defining single node
template <typename Object>
struct SingleNode {
    Object  data;
    SingleNode* next;

    SingleNode(const Object& d = Object{}, SingleNode* n = nullptr) //constructor initializing data to empty object and
        : data{ d }, next{ n } { } //next pointer to null
};

//function to create Singly Linked List with an array of values
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
SingleNode<Object>* alternateMix(SingleNode<Object>* headList1, SingleNode<Object>* headList2) {
	if (headList1 == nullptr && headList2 == nullptr) return nullptr;
	if (headList1 != nullptr && headList2 == nullptr) return headList1;
	if (headList1 == nullptr && headList2 != nullptr) return headList2;
	//None of the above, hence normal case where we add alternate node:
	headList1->next= alternateMix(headList2, headList1->next);
	return headList1;
}

int main() {
    int arr1[] = { 1,2,3,4,5,6 }, size = 6;
    int arr2[] = { 7,8,9,10,11,12 };
    SingleNode<int>* head1 = createSLL<int>(arr1, size);
    SingleNode<int>* head2 = createSLL<int>(arr2, size);
    cout << "Printing List1: \n";
    printSLL(head1);
    cout << endl;
    cout << "Printing List2: \n";
    printSLL(head2);
    cout << endl;
    SingleNode<int>* newhead = alternateMix(head1, head2);
    cout << "Printing alternate list:\n";
    printSLL(newhead);
    cout << endl;


	return 0;
}