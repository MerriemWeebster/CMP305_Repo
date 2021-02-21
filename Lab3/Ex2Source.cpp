#include <iostream>
#include <string>
using namespace std;

//defining single node
template <typename Object>
struct SingleNode
{
	Object  data;
	SingleNode   *next;

	SingleNode(const Object & d = Object{}, SingleNode * n = nullptr) //constructor initializing data to empty object and 
		: data{ d }, next{ n } { } //next pointer to null 
};

int main()
{
	SingleNode<string>* queueHead = nullptr;
	SingleNode<string>* queueTail = nullptr;
	cout << "1. Stand in the Queue \n2. Serve a Customer \n3. Print Customer names waiting \n4. Exit \nEnter your choice: ";
	int choice;
	string customerName, coursePreReq;
	cin >> choice;
	while (choice != 4)
	{
		if (choice == 1) //add
		{
			cout << "Enter Customer Name: ";
			cin >> customerName;
			//your code goes here
			
		}
			
		
		else if (choice == 2) //delete
		{
			cout << "Serving " << queueHead->data << endl;
			//your code goes here

		}
		else if (choice == 3) //print
		{
			//your code goes here
		}
		
		cout << "1. Stand in the Queue \n2. Serve a Customer \n3. Print Customer names waiting \n4. Exit \nEnter your choice: ";
		cin >> choice;
	}
	
	
	return 0;
}

