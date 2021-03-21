#include <iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<cctype>
using namespace std;

/*
Need class for:
Node -> x,y,name,isVisited,char,cost,left,right,up,down,prevx,prevx (could use list of neighbors instead),status(char . or o)
Map -> 2D array. start, goal
*/


void loadMap() {
	// Just copy pasted from lab script. Change to create nodes as needed.
    string filename;
    cout << "Enter the name of the file:" << endl;
    cin >> filename;
    ifstream in(filename);
    if (in.fail()) {
        cout << "Invalid file name!" << endl;
        return;
    }
    cout << "Loading map..." << endl;
    char str1[100], str2[100], str3[100];
    in.getline(str1, 100);
    in.getline(str2, 100);
    in.getline(str3, 100);
    int line = 1, cell = 1;

    while (!in.eof()) {
        int i = 0, j = 0, k = 1, cost = -1, cell = 0;
        char name = ' ';
        bool above, below, right, left;
        cout << "line " << line << endl;

        while (i < strlen(str1) - 1) {
            above = below = right = left = true;
            name = ' ';
            if (str1[i] == '+') i++; // new path
            if (str1[i] == '-') above = false;
            else if (str1[i] == ' ') above = true;
            // else error
            i = i + 3; // path left
            if (str2[j] == '|') left = false;
            else if (str2[j] == ' ') left = true;
            // else error
            j = j + 2; // cost
            if (str2[j] != ' ')
                if (isdigit(str2[j])) cost = (str2[j] - '0');
                else { cost = 0; name = str2[j]; }
            else cost = 0;
            j = j + 2; //path right
            if (str2[j] == '|') right = false;
            else if (str2[j] == ' ') right = true;
            // else error
            //path below
            if (str3[k] == ' ') below = true;
            else if (str3[k] == '-') below = false;
            // else error
            k = k + 4; // wall below
            cout << "cell = " << cell++ << endl;
            cout << "above: " << above << "\t";
            cout << "below: " << below << endl;
            cout << "right: " << right << "\t";
            cout << "left: " << left << endl;
            cout << "cost: " << cost << endl;
            cout << "name: " << name << endl;
            cout << endl << endl;
        }

        strcpy(str1, str3);
        cout << str1 << endl;
        in.getline(str2, 100);
        in.getline(str3, 100);
        cout << str2 << endl;
        cout << str3 << endl;
        line++;
    }
}


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