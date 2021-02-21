
#include <iostream>
#include <string>
using namespace std;

//defining single node
template <typename Object>
struct SingleNode
{
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
bool findInSLL(SingleNode<Object>* head, Object value)
{
    
}

template <typename Object>
bool insertAfterSLL(SingleNode<Object>*& head, Object givenValue, Object newValue) {
   
    SingleNode<Object>* newNode = new SingleNode<Object>(newValue);
    SingleNode<Object>* temp = head;
    //your code
    
    
    return false;
}

template <typename Object>
bool eraseSLL(SingleNode<Object>*& head, Object givenValue) {


}

//bonus
template <typename Object>
bool insertBeforeSLL(SingleNode<Object>*& head, Object givenValue, Object newValue)
{
    

}
template <typename Object>
bool removeDuplicates (SingleNode<Object>*& head, Object givenValue)
{
  
   
}

template <typename Object>
void removeAllDuplicates (SingleNode<Object>*& head)
{
  
   
}

int main()
{
    int ary[] = { 11,22,44,77,66,88 }, size = 6;
    SingleNode<int>* head = createSLL<int>(ary, size);

    cout << "Printing Singly linked list: \n";
    printSLL(head);

    //Testing insertAfter function
    cout << "\nInserting 55 after 44 :\n";
    bool success = insertAfterSLL(head, 44, 55);
    if (success)
        printSLL(head);
    else
        cout << "Value not Found! \n";

    cout << "\nInserting 99 after 88 (inserting at the end of the list):\n";
    success = insertAfterSLL(head, 88, 99);
    if (success)
        printSLL(head);
    else
        cout << "Value not Found! \n";

    cout << "\nDeleting 77:\n ";
    success = eraseSLL(head, 77);
    if (success)
        printSLL(head);
    else
        cout << "Value not Found! \n";

    cout << "\nDeleting 99 (deleting last element in the list):\n ";
    success = eraseSLL(head, 99);
    if (success)
        printSLL(head);
    else
        cout << "Value not Found! \n";

    cout << "\nDeleting 11 (deleting first element in the list):\n ";
    success = eraseSLL(head, 11);
    if (success)
        printSLL(head);
    else
        cout << "Value not Found! \n";

    cout << "\nDeleting -99 (trying to delete an element which is not present in the list):\n ";
    success = eraseSLL(head, -99);
    if (success)
        printSLL(head);
    else
        cout << "Value not Found! \n";

 //Bonus
    cout<<endl<<"Testing Bonus :\n";
    //Testing insertBefore function
    cout << "\nInserting 33 before 44 :\n";
    success = insertBeforeSLL(head, 44, 33);
    if (success)
        printSLL(head);
    else
        cout << "Value not Found! \n";

    cout << "\nInserting 0 before 22 (inserting at the start of the list):\n";
    success = insertBeforeSLL(head, 22, 0);
    if (success)
        printSLL(head);
    else
        cout << "Value not Found! \n";
   
 //Testing removeDuplictes function
    cout<<"Adding duplicates:\n";
  
 insertBeforeSLL(head, 44, 44);
 insertBeforeSLL(head, 44, 44);
 insertBeforeSLL(head, 77,44);
 insertBeforeSLL(head, 0, 44);
 insertAfterSLL(head, 99,44);
printSLL(head);
    
cout<<"Remove duplicates of 44:\n";
     success = removeDuplicates(head, 44);
    
    if (success)
        printSLL(head);
    else
        cout << "Value not Found! \n";
cout<<"Adding duplicates:\n";
    insertAfterSLL(head, 44, 11);
    insertAfterSLL(head, 66, 11);
    insertAfterSLL(head, 66, 88);
    insertAfterSLL(head, 0, 88);
     printSLL(head);

cout<<"Remove all duplicates:\n";
    removeAllDuplicates(head);
    printSLL(head);
    return 0;
}
