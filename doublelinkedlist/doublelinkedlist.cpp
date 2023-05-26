#include <iostream>
#include <string>
using namespace std;

class Node{
public:
	int noMhs;
	string name;
	Node* next;
	Node* prev;
};

class DoubleLinkedList{
private:
	Node* START = NULL;
public:

	void addNode();
	bool search(int rollNo, Node** previous, Node** current);
	bool deleteNode(int rollNo);
	bool listEmpty();
	void traverse();
	void revtraverse();
	void hapus();
	void searchData();
};

void DoubleLinkedList::addNode() {
	int nim;
	string nm;
	cout << "\nEnter the roll number of the student :";
	cin >> nim;
	cout << "\nEnter the name of student";
	cin >> nm;

	Node* newNode = new Node();		//step1
	newNode->noMhs = nim;	//step 2
	newNode->name = nm; //step3

	/*insert a node in the begining of a doubly - linked list*/
	if (start == NULL || nim <= START->noMhs) { //check if data null
		if (START != NULL && nim == START->noMhs) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		newNode->next = START; //step 3
		if (START != NULL)
			START->prev = newNode; //step 4
		newNode->prev = NULL;	//step 5
		START = newNode;		//step 6
		return;
	}

}