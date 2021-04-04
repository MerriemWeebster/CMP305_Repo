#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<cctype>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

/*
Classes for:
Node -> x,y,name,isVisited,char,cost,left,right,up,down,parentx,parenty,status(char . or o)
Map -> 2D array of nodes. start, goal
*/

class Node {
private :
    int x, y, cost, parentx, parenty;
    bool left, right, up, down, isStart, isGoal, isVisited;
    char status = ' ';
    char name = ' ';
public:
    Node(int nx = -1, int ny = -1, int ncost = -1, bool nleft = false , bool nright = false, bool nup = false, bool ndown = false, char nname=' ') {
        x = nx;
        y = ny;
        cost = ncost;
        left = nleft;
        right = nright;
        up = nup;
        down = ndown;
        name = nname;
        parentx = -1;
        parenty = -1;
        isStart = false;
        isGoal = false;
        isVisited = false;
    }
    friend ostream& operator<< (ostream& outs, Node n) {
        outs << "(x,y) = (" << n.x << "," << n.y << "). Cost = " << n.cost << " left,right,up,down : "
            << n.left << n.right << n.up << n.down << " Name = " << n.name;
        return outs;
    }
    char getName() { return name; }
    bool getRight() { return right; }
    bool getDown() { return down; }
    bool getStart() { return isStart; }
    bool getGoal() { return isGoal; }
    int getCost() { return cost; }
    bool Visited() { return isVisited; }
    int getX() { return x; }
    int getY() { return y; }
    bool getUp() { return up; }
    bool getLeft() { return left; }
    void setVisited(bool v) { isVisited = v; }
    void setStart(bool s) { isStart = s; }
    void setGoal(bool g) { isGoal = g; }
    void setParent(int x, int y) { parentx = x; parenty = y; }
    bool hasParent() { return !(parentx == -1 && parenty == -1); }
    void setName(char n) { name = n; }
    int getParentY() { return parenty; }
    int getParentX() { return parentx; }

    Node* operator=(const Node* rhs) {
        x = rhs->x;
        y = rhs->y;
        cost = rhs->cost;
        left = rhs->left;
        right = rhs->right;
        up = rhs->up;
        down = rhs->down;
        name = rhs->name;
        parentx = rhs->parentx;
        parenty = rhs->parenty;
        isStart = rhs->isStart;
        isGoal = rhs->isGoal;
        isVisited = rhs->isVisited;
        return this;
    }
};

class Map {
public:
    vector<vector<Node*>> map;
    Node* start;
    Node* goal;
    bool isEmpty() const {
        if (map.size() == 0) {
            return true;
        }
        if (map[0].size() == 0) {
            return true;
        }
        return false;
    }
    void setStart(Node* s) { start = s; }
    void setGoal(Node* g) { goal = g; }

    Map operator=(const Map& rhs) {
        for (int i = 0; i < this->map.size(); i++) {
            for (int j = 0; j < this->map[i].size(); j++) {
                delete (map[i][j]);
            }
        }
        map.erase(map.begin(), map.end());

        for (int i = 0; i < rhs.map.size(); i++) {
            vector<Node*> row;
            for (int j = 0; j < rhs.map[i].size(); j++) {
                Node* temp;
                temp = rhs.map[i][j]; //Calls the assignment operator for Node
                row.push_back(temp);
            }
            map.push_back(row);
        }
        return *this;
    }
};

void loadMap(Map& maze) {

    string filename;
    /*
    cout << "Enter the name of the file:" << endl;
    cin >> filename;
    */
    string location = "C:/Users/rohan/Desktop/AUS Year 2/Sem 4/Data Structures and Algorithms/Labs/CMP305_Repo/Lab7/";
    filename = location+ "map2.txt";
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
        //cout << "line " << line << endl;
        vector<Node*> row; // To store the nodes in this row.
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
            cell++;
            /*
            cout << "cell = " << cell++ << endl;
            cout << "above: " << above << "\t";
            cout << "below: " << below << endl;
            cout << "right: " << right << "\t";
            cout << "left: " << left << endl;
            cout << "cost: " << cost << endl;
            cout << "name: " << name << endl;
            cout << endl << endl;
            */
            //Create the Node and put it into the row vector
            row.push_back(new Node(line, cell, cost, left, right, above, below, name));
        }
        maze.map.push_back(row); 
        
        strcpy(str1, str3);
        //cout << str1 << endl;
        in.getline(str2, 100);
        in.getline(str3, 100);
        //cout << str2 << endl;
        //cout << str3 << endl;
        line++;
    }
    cout << "Map loaded!" << endl << endl;
    //return maze;
}

void displayMap(const Map& maze) {

    if (maze.isEmpty()) cout << "Error: no map available." << endl;

    //Top row of the map
    cout << '+';
    for (int i = 0; i < maze.map[0].size(); i++)
        cout << "---+";
    cout << endl;
    //Middle rows:
    for (int i = 0; i < maze.map.size(); i++) {
        cout << '|';
        for (int j = 0; j < maze.map[i].size(); j++) {
            
            if (maze.map[i][j]->getStart()) {
                cout << "(" << maze.map[i][j]->getName() << ")";
            }
            else if (maze.map[i][j]->getGoal()) {
                cout << "{" << maze.map[i][j]->getName() << "}";
            }
            else {
                cout << " " << maze.map[i][j]->getName() << " ";
            }

            if (!maze.map[i][j]->getRight()) {
                cout << '|';
            }
            else { cout << ' '; }
        }
        cout << endl;
        cout << '+';
        for (int j = 0; j < maze.map[i].size(); j++) {
            if (!maze.map[i][j]->getDown()) {
                cout << "---+";
            }
            else {
                cout << "   +";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void setStart(Map& maze){
    char start;
    cout << "Enter the start point: ";
    cin >> start;
    start = toupper(start);
    for (int i = 0; i < maze.map.size(); i++) {
        for (int j = 0; j < maze.map[i].size(); j++) {
            if (start == maze.map[i][j]->getName()) {
                maze.map[i][j]->setStart(true);
                maze.setStart(maze.map[i][j]);
                cout << "Start has been set to " << start << endl << endl;
                return;
            }
        }
    }
    cout << start << " does not exist! Please try again!" << endl << endl;
}

void setGoal(Map & maze){
    char goal;
    cout << "Enter the goal point: ";
    cin >> goal;
    goal = toupper(goal);
    for (int i = 0; i < maze.map.size(); i++) {
        for (int j = 0; j < maze.map[i].size(); j++) {
            if (goal == maze.map[i][j]->getName()) {
                maze.map[i][j]->setGoal(true);
                maze.setGoal(maze.map[i][j]);
                cout << "Goal has been set to " << goal << endl << endl;
                return;
            }
        }
    }
    cout << goal << " does not exist! Please try again!" << endl << endl;
}

stack<Node*> DFS(Map& maze){
    Node* startNode = maze.start;
    Node* goalNode = maze.goal;
    stack<Node*> frontier;
    Node* currentnode;
    frontier.push(startNode);
    bool ReachedGoal = false;
    while (!frontier.empty() || ReachedGoal == false) {
        currentnode = frontier.top();
        frontier.pop();
        if (currentnode == goalNode) {
            ReachedGoal = true;
            //Backtrack the solution and find path
            stack<Node*> path;
            path.push(currentnode);
            while (currentnode->hasParent()) {
                currentnode = maze.map[currentnode->getParentX()][currentnode->getParentY()];
                if (currentnode != maze.start) currentnode->setName('o');
                path.push(currentnode);
            }
            stack<Node*> copy = path;
            while (!copy.empty()) {
                if (copy.top()->getName() != 'o' && copy.top()->getName() != '.' && copy.top()->getName() != ' ')
                    cout << copy.top()->getName();
                cout << '(' << copy.top()->getX() << ',' << copy.top()->getY() << ") ";
                copy.pop();
            }
            return path;

        }
        currentnode->setVisited(true);
        if (currentnode != maze.start) currentnode->setName('.');
        if (!ReachedGoal)//Find the node:
            for (int i = 0; i < maze.map.size(); i++) {
                for (int j = 0; j < maze.map[i].size(); j++) {
                    if (maze.map[i][j] == currentnode) {
                        // Check if the neighbors have been explored. If they havent, push into frontier
                        if(maze.map[i][j]->getRight())
                            if (!maze.map[i][j + 1]->Visited()) { maze.map[i][j + 1]->setParent(i,j); frontier.push(maze.map[i][j + 1]); }
                        if (maze.map[i][j]->getLeft())
                            if (!maze.map[i][j - 1]->Visited()) { maze.map[i][j - 1]->setParent(i, j); frontier.push(maze.map[i][j - 1]); }
                        if (maze.map[i][j]->getDown())
                            if (!maze.map[i + 1][j]->Visited()) { maze.map[i + 1][j]->setParent(i, j); frontier.push(maze.map[i + 1][j]); }
                        if (maze.map[i][j]->getUp())
                            if (!maze.map[i - 1][j]->Visited()) { maze.map[i - 1][j]->setParent(i, j); frontier.push(maze.map[i - 1][j]); }
                    }
                }
            }

    }
}

stack<Node*> BFS(Map& maze){
    Node* startNode = maze.start;
    Node* goalNode = maze.goal;
    queue<Node*> frontier;
    Node* currentnode;
    frontier.push(startNode);
    bool ReachedGoal = false;
    while (!frontier.empty() || ReachedGoal == false) {
        currentnode = frontier.front();
        frontier.pop();
        if (currentnode == goalNode) {
            ReachedGoal = true;
            //Backtrack the solution and find path
            stack<Node*> path;
            path.push(currentnode);
            while (currentnode->hasParent()) {
                currentnode = maze.map[currentnode->getParentX()][currentnode->getParentY()];
                if (currentnode != maze.start)
                    currentnode->setName('o');
                path.push(currentnode);
            }

            stack<Node*> copy = path;
            cout << "Solution path: ";
            while (!copy.empty()) {
                if (copy.top()->getName() != 'o' && copy.top()->getName() != '.' && copy.top()->getName() != ' ')
                    cout << copy.top()->getName();
                cout << '(' << copy.top()->getX() << ',' << copy.top()->getY() << ") ";
                copy.pop();
            }
            cout << endl << endl;
            return path;
        }
        currentnode->setVisited(true);
        if(currentnode!=maze.start)
            currentnode->setName('.');
        if (!ReachedGoal)//Find the node:
            for (int i = 0; i < maze.map.size(); i++) {
                for (int j = 0; j < maze.map[i].size(); j++) {
                    if (maze.map[i][j] == currentnode) {
                        // Check if the neighbors have been explored. If they havent, push into frontier
                        if(maze.map[i][j]->getRight())
                            if (!maze.map[i][j + 1]->Visited()) { maze.map[i][j + 1]->setParent(i,j); frontier.push(maze.map[i][j + 1]); }
                        if (maze.map[i][j]->getLeft())
                            if (!maze.map[i][j - 1]->Visited()) { maze.map[i][j - 1]->setParent(i, j); frontier.push(maze.map[i][j - 1]); }
                        if (maze.map[i][j]->getDown())
                            if (!maze.map[i + 1][j]->Visited()) { maze.map[i + 1][j]->setParent(i, j); frontier.push(maze.map[i + 1][j]); }
                        if (maze.map[i][j]->getUp())
                            if (!maze.map[i - 1][j]->Visited()) { maze.map[i - 1][j]->setParent(i, j); frontier.push(maze.map[i - 1][j]); }
                    }
                }
            }
    }
}

struct compareCosts { // defining the comparison operator
    bool operator() (Node* & s1, Node* & s2) {
        return s1->getCost() > s2->getCost();
    }
};
// TBD
// Dijkstra
stack<Node*> DA(Map& maze){
    Node* startNode = maze.start;
    Node* goalNode = maze.goal;

    priority_queue<Node*,vector<Node*>,compareCosts> frontier;
    Node* currentnode;
    frontier.push(startNode);
    bool ReachedGoal = false;
    while (!frontier.empty() || ReachedGoal == false) {
        currentnode = frontier.top();
        frontier.pop();
        if (currentnode == goalNode) {
            ReachedGoal = true;
            //Backtrack the solution and find path
            stack<Node*> path;
            path.push(currentnode);
            while (currentnode->hasParent()) {
                currentnode = maze.map[currentnode->getParentX()][currentnode->getParentY()];
                if (currentnode->getName() =='.') currentnode->setName((char)(currentnode->getCost()+48));
                path.push(currentnode);
            }
            stack<Node*> copy = path;
            cout << "Solution path: ";
            while (!copy.empty()) {
                if (!( (int)(copy.top()->getName())>=int('0') && (int)(copy.top()->getName()) <= int('9')) && copy.top()->getName() != '.' && copy.top()->getName() != ' ')
                    cout << copy.top()->getName();
                cout << '(' << copy.top()->getX() << ',' << copy.top()->getY() << ") ";
                copy.pop();
            }
            cout << endl << endl;
            return path;
        }
        currentnode->setVisited(true);
        if (currentnode->getName() == ' ') currentnode->setName('.');

        if (!ReachedGoal)//Find the node:
            for (int i = 0; i < maze.map.size(); i++) {
                for (int j = 0; j < maze.map[i].size(); j++) {
                    if (maze.map[i][j] == currentnode) {
                        // Check if the neighbors have been explored. If they havent, push into frontier
                        if (maze.map[i][j]->getRight())
                            if (!maze.map[i][j + 1]->Visited()) { maze.map[i][j + 1]->setParent(i, j); frontier.push(maze.map[i][j + 1]); }
                        if (maze.map[i][j]->getLeft())
                            if (!maze.map[i][j - 1]->Visited()) { maze.map[i][j - 1]->setParent(i, j); frontier.push(maze.map[i][j - 1]); }
                        if (maze.map[i][j]->getDown())
                            if (!maze.map[i + 1][j]->Visited()) { maze.map[i + 1][j]->setParent(i, j); frontier.push(maze.map[i + 1][j]); }
                        if (maze.map[i][j]->getUp())
                            if (!maze.map[i - 1][j]->Visited()) { maze.map[i - 1][j]->setParent(i, j); frontier.push(maze.map[i - 1][j]); }
                    }
                }
            }
    }
}

// Do we even need this? Just call displayMap()
void displayPath(stack<Node*> path){
    
    while (!path.empty()) {
        cout << *(path.top()) << endl;
        path.pop();
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
	} while (!(choice >= 1 && choice <= 9));
	bool quit = false;
    Map maze;
    stack<Node*> path;
    Map cleanMaze;
	while (choice >= 1 && choice <= 9 && !quit) {
		switch (choice) {
		case 1:
            loadMap(maze); break;
		case 2:
			displayMap(maze); break;
		case 3:
            setStart(maze);  break; //cleanMaze = maze; cout << cleanMaze.map[0][0] << "    " << maze.map[0][0];
		case 4:
			setGoal(maze);break;
		case 5:
            path = DFS(maze); break;
		case 6:
            path = BFS(maze); break;
		case 7:
            path = DA(maze); break;
		case 8:
			//displayPath(path); break;
            displayMap(maze); break;
		case 9:
			cout << "Good bye!! :) " << endl;
			quit = true;
            break;
		}
        if(!quit)
            choice = menu();
	}
	return 0;
}