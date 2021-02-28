#include <iostream>
#include <string>
using namespace std;

//Doubly Linked List structure
template <typename Object>
struct DoubleNode
{
    Object  data;
    DoubleNode   *prev;
    DoubleNode   *next;

    DoubleNode(const Object & d = Object{}, DoubleNode * p = nullptr, DoubleNode * n = nullptr)
        : data{ d }, prev{ p }, next{ n } { }
};

//function to create Doubly Linked List with values
template <typename Object>
DoubleNode<Object>* createDLL(Object ary[], int size)
{
    DoubleNode<Object>* first = new DoubleNode<Object>(ary[0]);
    DoubleNode<Object>* temp = first;
    for (int i = 1; i < size; i++)
    {
        DoubleNode<Object>* node = new DoubleNode<Object>(ary[i]);
        temp->next = node;
        temp = node; //same as single linked list
    }

    temp = first; //make temp point back to first element
    DoubleNode<Object>* x = first; //create instance x and make it point to first element
    temp = temp->next; //shift temp to next node
    while (temp != NULL)
    {
        temp->prev = x; //prev points to x
        x = temp; //x points to temp
        temp = temp->next; //temp points one step ahead
    } //overall structure is therefore prev --> x --> temp(new position) and this loop stops when temp goes out of the array
    return first;
}


template <typename Object>
void printDLL(DoubleNode<Object>*  head)
{
    while (head != nullptr)
    {
        cout << head->data << "\t";
        head = head->next;
    }
    cout << endl;
}

template <typename Object>
bool findInDLL(DoubleNode<Object>*  head, Object value)
{
    
}


template <typename Object>
bool insertBeforeDLL(DoubleNode<Object>* & head, Object givenValue, Object newValue) {
    
   
  
}
template <typename Object>
bool eraseInDLL(DoubleNode<Object>*& head, Object givenValue) {
   
}

//Bonus
template <typename Object>
bool setInsert(DoubleNode<Object>* & head, Object newValue)
{
    
  
}

template <typename Object>
DoubleNode<Object>* setUnion(DoubleNode<Object>*  head1, DoubleNode<Object>*  head2)
{
    
}

template <typename Object>
DoubleNode<Object>* setIntersection(DoubleNode<Object>*  head1, DoubleNode<Object>*  head2)
{
   
}


int main()
{
    int ary[] = { 1,2,4,7,6,8 }, size = 6;
    DoubleNode<int>* head = createDLL<int>(ary, size);

    cout << "Printing Double linked list: \n";
    printDLL(head);
    cout << "\nFinding 7 in the List: \n";
       if (findInDLL(head, 7))
           cout << "7 exist in the list\n";

  
    //Testing insertBefore function
    cout << "\nInserting 3 before 4 :\n";
 bool   success = insertBeforeDLL(head, 4, 3);
    if (success)
        printDLL(head);
    else
        cout << "Value not Found! \n";

    cout << "\nInserting 0 before 1 (inserting at the start of the list):\n";
    success = insertBeforeDLL(head, 1, 0);
    if (success)
        printDLL(head);
    else
        cout << "Value not Found! \n";

    cout << "\nDeleting 3:\n ";
    success = eraseInDLL(head, 3);
    if (success)
        printDLL(head);
    else
        cout << "Value not Found! \n";

    cout << "\nDeleting 9 (deleting last element in the list):\n ";
    success = eraseInDLL(head, 9);
    if (success)
        printDLL(head);
    else
        cout << "Value not Found! \n";

    cout << "\nDeleting 0 (deleting first element in the list):\n ";
    success = eraseInDLL(head, 0);
    if (success)
        printDLL(head);
    else
        cout << "Value not Found! \n";

    cout << "\nDeleting -99 (trying to delete an element which is not present in the list):\n ";
    success = eraseInDLL(head, -99);
    if (success)
        printDLL(head);
    else
        cout << "Value not Found! \n";
   
   //Bonus
    cout<<"\n\n Testing Bonus \n";
    DoubleNode<int>* bonushead1=nullptr;
    setInsert(bonushead1,2);
    setInsert(bonushead1,3);
    setInsert(bonushead1,4);
    setInsert(bonushead1,4);
    setInsert(bonushead1,5);
    setInsert(bonushead1,3);
   // printDLL(bonushead1);
    DoubleNode<int>* bonushead2=nullptr;
    setInsert(bonushead2,2);
    setInsert(bonushead2,3);
    setInsert(bonushead2,6);
    setInsert(bonushead2,5);
    setInsert(bonushead2,7);
    setInsert(bonushead2,4);
    cout<<"Lists are : \n";
    printDLL(bonushead1);
    printDLL(bonushead2);
    cout<<"Testing Union: \n";
    DoubleNode<int>* bonusUnionhead = setUnion(bonushead1, bonushead2);
   printDLL(bonusUnionhead);
    cout<<"Testing Intersection: \n";
    DoubleNode<int>* bonusIntersection= setIntersection(bonushead1, bonushead2);
    printDLL(bonusIntersection);
    return 0;
}


