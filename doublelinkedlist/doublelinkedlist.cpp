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
	if (START == NULL || nim <= START->noMhs) { //check if data null
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

	/*Inserting a node Between two Nodes in the list*/
	Node* current = START;
	Node* previous = NULL;
	while (current->next != NULL && current->next->noMhs < nim) 
	{
		previous = current; //1.d
		current = current->next; //1.e
	}

	if (current->next !=NULL && nim == current->next->noMhs) {
		cout << "\nDuplicate roll numbers not allowed" << endl;
		return;
	}

	newNode->next = current->next; //step 4
	newNode->prev = current; //step 5
	if (current->next != NULL)
		current->next->prev = newNode; //step 6
	current->next = newNode; //step 7
}

bool DoubleLinkedList::search(int rollNo, Node** previous, Node** current) {
	*previous = NULL;
	*current = START;
	while (*current != NULL && (*current)->noMhs !=rollNo) {
		*previous = *current;
		*current = (*current)->next;
	}
	return;
}
