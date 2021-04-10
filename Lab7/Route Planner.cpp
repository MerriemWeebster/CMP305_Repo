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
Node -> x,y,name,isVisited,char,cost,left,right,up,down,parentx,parenty
Map -> 2D array of nodes. start, goal
*/

//Node class for storing individual grid information of Maps
class Node {
private :
    int x, y, cost, parentx, parenty; //x and y coordinates of the node is stored here. Cost variable stores cost of node traversal for DA function (cost is taken from map file).
    //parent x and y used to store coordinates of parent nodes in search algorithms, used to backtrack paths.
    bool left, right, up, down, isStart, isGoal, isVisited; //Basic node components to indicate items around the Node and its properties, 
    //such as being the start or goal and whether it has already been visited in the search algoritm.
    char name = ' ';
    //Display name for Nodes on the map, mainly used for points (i.e A, B, C, etc.). Later used for '.' or 'o' during display
public:
    //Constructor to set all private members mentioned above with appropriate default values
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
    
    //Insertion operator for output of Node data, mainly used for debugging purposes.
    friend ostream& operator<< (ostream& outs, Node n) {
        outs << "(x,y) = (" << n.x << "," << n.y << "). Cost = " << n.cost << " left,right,up,down : "
            << n.left << n.right << n.up << n.down << " Name = " << n.name;
        return outs;
    }

    //Setters and Getters for private members mentioned above
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
};

//Map class that stores relevant information of the map. All nodes are stored in a 2D Vector of Node pointers in addition to a start and goal Node pointers.
class Map {
public: //Could be private, but not necessary in our case
    vector<vector<Node*>> map;
    Node* start;
    Node* goal;

    //Default constructor intializing the above mentioned members.
    Map() :start{}, goal{}, map{} {}

    //isEmpty function that checks whether the map has data or is empty, used when the map is being displayed.
    bool isEmpty() const {
        if (map.size() == 0) {
            return true;
        }
        if (map[0].size() == 0) {
            return true;
        }
        return false;
    }
    
    //setters for start and goal pointers
    void setStart(Node* s) { start = s; }
    void setGoal(Node* g) { goal = g; }
};

//Handling of reading map data from text files done by loadMap, a Map object is sent via reference as a parameter and is loaded with the appropriate data.
//Returns true if map loaded successfully, else returns false
bool loadMap(Map& maze) {
    //File reading
    string filename;
    cout << "Enter the name of the file:" << endl;
    cin >> filename;
    string location = "C:/Users/rohan/Desktop/AUS Year 2/Sem 4/Data Structures and Algorithms/Labs/CMP305_Repo/Lab7/";
    //Base location, not necessary if file is in the same folder.
    filename = location + filename;
    ifstream in(filename);
    if (in.fail()) { //Incase map file name supplied does not exist
        cout << "Invalid file name!" << endl;
        return false; //Could not load map, hence return false
    }
    cout << "Loading map..." << endl;
    //Insertion of map data into map object
    char str1[100], str2[100], str3[100];
    in.getline(str1, 100);
    in.getline(str2, 100);
    in.getline(str3, 100);
    int line = 1, cell = 1;

    while (!in.eof()) {
        int i = 0, j = 0, k = 1, cost = -1, cell = 0;
        char name = ' ';
        bool above, below, right, left;
        vector<Node*> row; // To store the nodes in this row.
        while (i < strlen(str1) - 1) {
            above = below = right = left = true;
            name = ' ';
            if (str1[i] == '+') i++; // new path
            if (str1[i] == '-') above = false;
            else if (str1[i] == ' ') above = true;
            i = i + 3; // path left
            if (str2[j] == '|') left = false;
            else if (str2[j] == ' ') left = true;
            j = j + 2; // cost
            if (str2[j] != ' ')
                if (isdigit(str2[j])) cost = (str2[j] - '0');
                else { cost = 0; name = str2[j]; }
            else cost = 0;
            j = j + 2; //path right
            if (str2[j] == '|') right = false;
            else if (str2[j] == ' ') right = true;
            //path below
            if (str3[k] == ' ') below = true;
            else if (str3[k] == '-') below = false;
            k = k + 4; // wall below
            cell++;

            //Create the Node and put it into the row vector
            row.push_back(new Node(line, cell, cost, left, right, above, below, name));
        }

        //maze.map is a 2D vector of Node* Hence, we push_back an entire vector.
        maze.map.push_back(row); 
        
        strcpy(str1, str3);
        in.getline(str2, 100);
        in.getline(str3, 100);
        line++;
    }
    cout << "Map loaded!" << endl << endl;
    return true;//Map sucessfully loaded
}

void displayMap(const Map& maze) {
    //Function to display map nicely (Similar to input file). Will automatically display the map when menu option "display path" has been called
    // since the names of the nodes are changed to '.' or 'o' as necessary. Hence this one function handles both cases.
    //Does not return anything, takes in maze by const reference so it does not copy the map (avoid loss of efficiency during copying incase
    // of large map. Const keyword because we dont want to change any contents.

    if (maze.isEmpty()) cout << "Error: no map available." << endl;//Error checking

    //Top row of the map
    cout << '+';
    for (int i = 0; i < maze.map[0].size(); i++)
        cout << "---+";
    cout << endl;
    //Middle rows and last row:
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

//Sets the start point of the map by matching the user's input to the names of each Node. Error displayed if Node does not exist.
//Returns true or false based on if a node was successfully set or not.
bool setStart(Map& maze){
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
                return true; //Successfully set start node
            }
        }
    }
    cout << start << " does not exist! Please try again!" << endl << endl;
    return false; //Unable to set start node
}

//Sets the goal point of the map by matching the user's input to the names of each Node. Error displayed if Node does not exist.
//Returns true or false based on if a node was successfully set or not.
bool setGoal(Map & maze){
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
                return true;//Successfully set goal node
            }
        }
    }
    cout << goal << " does not exist! Please try again!" << endl << endl;
    return false;//Unable to set goal node
}

//Calculates the path using the DFS algorithm
//Backtrack and prints path if found the goal using the parent nodes in each Node object.
//Does not return anything
void DFS(Map& maze){
    Node* startNode = maze.start;
    Node* goalNode = maze.goal;
    stack<Node*> frontier; // Our data structure to store all the nodes yet to be explored.
    Node* currentnode;
    frontier.push(startNode);//Start from the start node inside the frontier.
    bool ReachedGoal = false;
    while (!frontier.empty() || ReachedGoal == false) { //Loop until we're out of nodes to explore, or we found the goal
        currentnode = frontier.top(); //Pick top node
        frontier.pop(); //Remove from frontier as we are currently processing the top node.
        if (currentnode == goalNode) { //Found goal
            ReachedGoal = true;
            //Backtrack the solution and find path
            stack<Node*> path;
            path.push(currentnode);
            while (currentnode->hasParent()) { // Do the following while the node has a parent node
                currentnode = maze.map[currentnode->getParentX()][currentnode->getParentY()]; //Move currentnode to the parent node 
                if (currentnode != maze.start) currentnode->setName('o'); 
                //We keep the start node the same name. Else, we change all the names to 'o' to show the final path.
                path.push(currentnode); // Add it to our path!
            }
            
            while (!path.empty()) { //Print out the path nicely
                if (path.top()->getName() != 'o' && path.top()->getName() != '.' && path.top()->getName() != ' ')
                    cout << path.top()->getName();
                cout << '(' << path.top()->getX() << ',' << path.top()->getY() << ") ";
                path.pop();
            }
            cout << endl << endl;
            return; 

        }
        //IF NOT REACHED GOAL:
        currentnode->setVisited(true);
        if (currentnode != startNode) currentnode->setName('.'); //Dont change name of start node
        if (!ReachedGoal)//Find the node:
            for (int i = 0; i < maze.map.size(); i++) {
                for (int j = 0; j < maze.map[i].size(); j++) {
                    if (maze.map[i][j] == currentnode) {
                        // Check if the neighbors have been explored. If they havent, push into frontier
                        if(maze.map[i][j]->getRight())
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

    //Exited the while loop means we did not reach goal (So we did not return)
    //Hence, it must be that the frontier is empty (i.e. we explored all the nodes) and didnt find the goal.
    cout << "No possible path found!" << endl << endl;
}

//Calculates the path using the BFS algorithm
//Backtrack and prints path if found the goal using the parent nodes in each Node object.
//Does not return anything
void BFS(Map& maze){
    Node* startNode = maze.start;
    Node* goalNode = maze.goal;
    queue<Node*> frontier;// Our data structure to store all the nodes yet to be explored.
    Node* currentnode;
    frontier.push(startNode);//Start from the start node inside the frontier.
    bool ReachedGoal = false;
    while (!frontier.empty() || ReachedGoal == false) {//Loop until we're out of nodes to explore, or we found the goal
        currentnode = frontier.front();
        frontier.pop(); // Remove from frontier as we are currently processing the top node.
        if (currentnode == goalNode) {
            ReachedGoal = true;
            //Backtrack the solution and find path
            stack<Node*> path;
            path.push(currentnode);
            while (currentnode->hasParent()) {
                currentnode = maze.map[currentnode->getParentX()][currentnode->getParentY()];//Move currentnode to the parent node 
                if (currentnode != maze.start)
                    currentnode->setName('o');
                //We keep the start node the same name. Else, we change all the names to 'o' to show the final path.
                path.push(currentnode); //Add to path
            }
            cout << "Solution path: "; //print path nicely
            while (!path.empty()) {
                if (path.top()->getName() != 'o' && path.top()->getName() != '.' && path.top()->getName() != ' ')
                    cout << path.top()->getName();
                cout << '(' << path.top()->getX() << ',' << path.top()->getY() << ") ";
                path.pop();
            }
            cout << endl << endl;
            return;
        }
        
        currentnode->setVisited(true);
        if(currentnode!=maze.start)
            currentnode->setName('.');
        // IF NOT FOUND THE GOAL:
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

    //Exited the while loop means we did not reach goal (So we did not return)
    //Hence, it must be that the frontier is empty (i.e. we explored all the nodes) and didnt find the goal.
    cout << "No possible path found!" << endl << endl;
}

//Used for cost comparison in DA function
struct compareCosts { // defining the comparison operator
    bool operator() (Node* & s1, Node* & s2) {
        return s1->getCost() > s2->getCost();
    }
};

//Uses the DA to find a path based on costs
//Backtrack and prints path if found the goal using the parent nodes in each Node object.
//Does not return anything
void DA(Map& maze){
    Node* startNode = maze.start;
    Node* goalNode = maze.goal;

    priority_queue<Node*,vector<Node*>,compareCosts> frontier;// Our data structure to store all the nodes yet to be explored.
    Node* currentnode;
    frontier.push(startNode);//Start from the start node inside the frontier.
    bool ReachedGoal = false;
    while (!frontier.empty() || ReachedGoal == false) {//Loop until we're out of nodes to explore, or we found the goal
        currentnode = frontier.top();
        frontier.pop();// Remove from frontier as we are currently processing the top node.
        if (currentnode == goalNode) {
            ReachedGoal = true;
            //Backtrack the solution and find path
            stack<Node*> path;
            path.push(currentnode);
            while (currentnode->hasParent()) {
                currentnode = maze.map[currentnode->getParentX()][currentnode->getParentY()];//Move currentnode to the parent node 
                if (currentnode->getName() =='.') currentnode->setName((char)(currentnode->getCost()+48)); //+48 (ascii of 0) to display the costs
                path.push(currentnode);
            }
            cout << "Solution path: ";
            while (!path.empty()) { //Display path nicely
                if (!( (int)(path.top()->getName())>=int('0') && (int)(path.top()->getName()) <= int('9')) && path.top()->getName() != '.' && path.top()->getName() != ' ')
                    cout << path.top()->getName();
                cout << '(' << path.top()->getX() << ',' << path.top()->getY() << ") ";
                path.pop();
            }
            cout << endl << endl;
            return;
        }
        currentnode->setVisited(true);
        if (currentnode->getName() == ' ') currentnode->setName('.');
        //IF NOT FOUND GOAL:
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

    //Exited the while loop means we did not reach goal (So we did not return)
    //Hence, it must be that the frontier is empty (i.e. we explored all the nodes) and didnt find the goal.
    cout << "No possible path found!" << endl << endl;
}


//Options for user:
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
    bool mapLoaded = false;
    bool hasGoal = false;
    bool hasStart = false;
    
    //Loop while the user has entered a valid choice
	while (choice >= 1 && choice <= 9 && !quit) {
		switch (choice) {
		case 1:
            mapLoaded = loadMap(maze); break;
		case 2:
            //Output error if no map loaded
            if (!mapLoaded) { cout << "No map loaded! Please load map first!" << endl; break; }
			displayMap(maze); break;
		case 3:
            //Output error if no map loaded
            if (!mapLoaded) { cout << "No map loaded! Please load map first!" << endl; break; }
            hasStart = setStart(maze);  break;
		case 4:
            //Output error if no map loaded
            if (!mapLoaded) { cout << "No map loaded! Please load map first!" << endl; break; }
            hasGoal = setGoal(maze);break;
		case 5:
            //Output error if no map loaded
            if (!mapLoaded) { cout << "No map loaded! Please load map first!" << endl; break; }
            //Check if goal and start have been set:
            if (!hasGoal || !hasStart) { cout << "Cannot call function! Start and/or Goal node not set!" << endl; break; }
            //Call DFS with the newly loaded maze.
            DFS(maze); break;
		case 6:
            //Output error if no map loaded
            if (!mapLoaded) { cout << "No map loaded! Please load map first!" << endl; break; }
            //Check if goal and start have been set:
            if (!hasGoal || !hasStart) { cout << "Cannot call function! Start and/or Goal node not set!" << endl; break; }
            //Call BFS with the newly loaded maze.
            BFS(maze); break;
		case 7:
            //Output error if no map loaded
            if (!mapLoaded) { cout << "No map loaded! Please load map first!" << endl; break; }
            //Check if goal and start have been set:
            if (!hasGoal || !hasStart) { cout << "Cannot call function! Start and/or Goal node not set!" << endl; break; }
            //Call Dijkstras Algorithm with the newly loaded maze.
            DA(maze); break;
		case 8:
            //Output error if no map loaded
            if (!mapLoaded) { cout << "No map loaded! Please load map first!" << endl; break; }
			//Call displayMap again because the names of the nodes have been changed to reflect 'o' or '.' respectively.
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