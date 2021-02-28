#include"Song.h"

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
DoubleNode<Object>* createDoublyLinkedList(Object ary[], int size)
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
bool eraseInDLL(DoubleNode<Object>*& head, Object givenValue) {
	//copy ex1 code of eraseInDLL function here 
}
//add a song at the end of the list  
template <typename Object>
void addSong(DoubleNode<Object>*& node, Object newEntry) {
	//your code goes here
}

void menu() {
	cout << "1. Add a Song\n"
		<<"2. Delete a Song\n"
		<<"3. Play a Song\n"
		<<"4. Forward\n"
		<<"5. Backward\n"
		<<"6. Show Playlist\n"
		<<"7.Exit\n"
		<<"Choose an option: ";
}

int main()
{
	string title;
	string singer;
	bool success;
	Song MusicList[10];
	Song a("Staying Alive", "Bee Gees");
	MusicList[0] = a;
	Song b("Hotel California", "The Eagles");
	MusicList[1] = b;
	Song c("Saturnalia", "Marilyn Manson");
	MusicList[2] = c;
	Song d("Potions", "Puscifer");
	MusicList[3] = d;
	DoubleNode<Song> *MusicPlayList = createDoublyLinkedList(MusicList, 4);
	
		DoubleNode<Song> *currentSong = MusicPlayList
	Song song;
	bool found = false;
	int option;
	do {
		menu();
		cin >> option;
		cout << endl;
		cin.ignore();
		cin.clear();
		switch (option) {

		case 1: // Add a Song

			cout << "Enter song title: ";
			getline(cin, title);
			cout << "Enter singer: ";
			getline(cin, singer);
			song.setTitle(title);
			song.setSinger(singer);
			//your code goes here

			cout << endl;
			break;
		case 2: // Delete a Song

			cout << "Enter the title of the song to delete: ";
			getline(cin, title);

			cout << "Enter singer: ";
			getline(cin, singer);
			song.setTitle(title);
			song.setSinger(singer);
			//your code goes here

			break;
		case 3: // Paly a Song
			cout << "Enter the title of the song to play: ";
			getline(cin, title);

			cout << "Enter singer: ";
			getline(cin, singer);
			song.setTitle(title);
			song.setSinger(singer);
						
			//your code goes here


			break;
		case 4: //forward
			//your code goes here

			break;
		case 5: //backward
			//your code goes here

			break;
		case 6: //Display Playlist

			printDLL(MusicPlayList);
			break;
		case 7: //exit
			cout << "Exiting playlist...\n\n";
			break;
		}


	} while (option != 7);


}
