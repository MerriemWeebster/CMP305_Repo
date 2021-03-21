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
	cout << "8.Display Path" << endl;
	cout << "9.Quit" << endl;
	int choice;
	cout << "Enter your choice: ";
	cin >> choice;
	return choice;
}

int main() {
	int choice;
	do{
		choice = menu();
	} while (!(choice >= 1 and choice <= 9));
	bool quit = false;
	while (choice >= 1 and choice <= 9 and not quit) {
		switch (choice) {
		case 1:
			loadMap(); break;
		case 2:
			displayMap(); break;
		case 3:
			setStart(); break;
		case 4:
			setGoal(); break;
		case 5:
			DFS(); break;
		case 6:
			BFS(); break;
		case 7:
			DA(); break;
		case 8:
			displayPath(); break;
		case 9:
			cout << "Good bye!! :) " << endl;
			quit = true;
		}
	}
	return 0;
}