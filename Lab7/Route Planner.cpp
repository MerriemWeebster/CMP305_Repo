#include<iostream>
#include<fstream>
using namespace std;

int menu() {
	cout << "Menu:" << endl;
	cout << "1.Load Map" << endl;
	cout << "2.Display Map" << endl;
	cout << "3.Set Start" << endl;
	cout << "4.Set Goal" << endl;
	cout << "5.Find Path DFS" << endl;
	cout << "6.Find Path BFS" << endl;
	cout << "7.Find Path DA" << endl;
	cout << "8.Quit" << endl;
	int choice;
	cout << "Enter your choice: ";
	cin >> choice;
	return choice;
}

int main() {

	return 0;
}