#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"BinarySearchTree.h"
#include <fstream>
#include<string>
using namespace std;

class RecordLocation
{
private:
	int studentId;//student id
	int studentRecordNumber;// Student record number
public:

	RecordLocation(int sID = 0, int srn = 0) {
		studentId = sID; studentRecordNumber = srn;
	}

	void setStudentID(int s) { studentId = s; }
	void setStudentRecordNumber(int s) { studentRecordNumber = s; }
	int getStudentId() { return studentId; }
	int getStudentRecordNumber() {return studentRecordNumber;}

	bool operator<(const RecordLocation& rhs) const {
		return (studentId < rhs.studentId);
	}
	bool operator>(const RecordLocation& rhs) const {
		return (studentId > rhs.studentId);
	}
	bool operator==(const RecordLocation& rhs) const {
		return (studentId == rhs.studentId);
	}
	friend ostream& operator<<(ostream& os, const RecordLocation&rhs) {
		os << "Student ID: " << rhs.studentId << " Student Record Number: " << rhs.studentRecordNumber << endl;
		return os;
	}
};

/*
int main() {
	char buffer[25] = { '0' };
	ifstream input("data.txt", ios::binary);
	if (input.fail()) { cout << "Failed!"<<endl; }

	BinarySearchTree<RecordLocation> bst{};
	
	int i = 0;
	while (!input.eof()) {
		input.seekg(24 * i);
		input.read(buffer, 24);
		char id[3];
		strncpy(id, buffer, 3);
		int myid = stoi(id);
		if (input.eof()) break;// Ensure we dont add the last node twice
		RecordLocation temp(myid, i);
		bst.insert(temp);
		i++;
	}

	//bst.printTree();
	cout << "Tree created!" << endl << endl;
	cout << "Enter the userID to search for: " << endl;
	int target;
	cin >> target;
	if (bst.contains(target)) {
		RecordLocation ans = bst.contains2(target);
		int index = ans.getStudentRecordNumber();
		input.seekg(24 * index);
		input.read(buffer, 24);
		cout << "The record is: " << endl << buffer << endl;
	}
	
	input.close();

	return 0;
}*/