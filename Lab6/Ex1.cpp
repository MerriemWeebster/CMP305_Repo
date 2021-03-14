#include<iostream>
#include<fstream>
#include<stack>
#include<string>
using namespace std;
/*
int main() {
	stack<char> mystack;
	string path="C:/Users/rohan/Desktop/AUS Year 2/Sem 4/Data Structures and Algorithms/Labs/CMP305_Repo/Lab6/";
	string filename;
	cout << "Enter the file to check:" << endl;
	cin >> filename;
	ifstream input;
	input.open(path+filename);
	if (input.fail()) {
		cout << "Could not find file!" << endl;
		exit(1);
	}
	string line;
	int linenum = 1;
	while (!input.eof()) {
		getline(input,line);
		for (char ch : line) {
			if (ch == '(' || ch == '{' || ch == '[') {
				mystack.push(ch);
			}
			else if (ch == ')') {
				if (mystack.empty())
					cout << "Extra ) found at line " << linenum;
				if (mystack.top() == '(')
					mystack.pop();
				else
					cout << "Error at line " << linenum << ", incorrect ) found. " << endl;
			}
			else if (ch == '}') {
				if (mystack.empty())
					cout << "Extra } found at line " << linenum;
				if (mystack.top() == '{')
					mystack.pop();
				else
					cout << "Error at line " << linenum << ", incorrect } found. "<< endl;
			}
			else if (ch == ']') {
				if (mystack.empty())
					cout << "Extra ] found at line " << linenum;
				else if (mystack.top() == '[')
					mystack.pop();
				else
					cout << "Error at line " << linenum << ", incorrect ] found. "<< endl;
			}
		}
		linenum++;
	}
	if (!mystack.empty()) {
		cout << "Reached end of file. The " << mystack.top() << " was not closed" << endl;
	}
	else {
		cout << "All good !" << endl;
	}
	return 0;
}*/