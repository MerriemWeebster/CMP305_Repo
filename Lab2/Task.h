#pragma once
#pragma once
#include <string>
#include<iostream>
using namespace std;
class Task {
public:


	Task(int id, string tName, int tDuration) :taskID(id), taskName(tName), taskDuration(tDuration) {};

	int gettaskID() const
	{
		return taskID;
	}
	string getTasktName()const
	{
		return taskName;
	}
	int getTaskDuration()const
	{
		return taskDuration;
	}
	
	friend	ostream& operator<<(ostream& outs, const Task& rhs)
	{
		outs << rhs.taskID << "\t" << rhs.taskName << "\t" << rhs.taskDuration << endl;
		return outs;
	}
private:
	int taskID,taskDuration;
	string taskName;
};

