#include <iostream>
#include <string>
using namespace std;

class Node {
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
	return (*current !=NULL);
}

bool DoubleLinkedList::deleteNode(int rollNo) {
	Node* previous, * current;
	previous = current = NULL;
	if (search(rollNo, &previous, &current) == false)
		return false;
	if (current->next != NULL)
		current->next->prev = previous;
	if (previous != NULL)
		previous->next = current->next;
	else
		START = current->next;

	delete current;
	return true;
}

bool DoubleLinkedList::listEmpty() {
	return (START == NULL);
}

void DoubleLinkedList::traverse() {
	if (listEmpty())
		cout << "\nlist is empty" << endl;
	else {
		cout << "\nRecord in acsending order of roll number are: " << endl;
		Node* currentNode = START;
		while (currentNode != NULL) {
			cout << currentNode->noMhs << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
	}
}

void DoubleLinkedList::hapus() {
	if (listEmpty()) {
		cout << "\nlist is empty" << endl;

	}
	cout << "\nEnter the roll number of the student whose record is to be deleted: ";
	int rollNo;
	cin >> rollNo;
	cout << endl;
	if (DoubleLinkedList::deleteNode(rollNo) == false)
		cout << "Record not found" << endl;
	else
		cout << "Record with roll number" << rollNo << "deleteted" << endl;
}
void DoubleLinkedList::searchData() {
	if (listEmpty() == true) {
		cout << "\nnList is empty" << endl;
	}
	Node* prev, * curr;
	prev = curr = NULL;
	cout << "\nEnter the roll number of the statemnent whose record to search: ";
	int num;
	cin >> num;
	if (DoubleLinkedList::search(num, &prev, &curr) == false)
		cout << "\nRecord not found" << endl;
	else {
		cout << "\nRecord found" << endl;
		cout << "\nRoll number" << endl;
		cout << "\nName" << curr->name << endl;
	}
}

int main() {
	DoubleLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all records in the ascending order of roll numbers" << endl;
			cout << "4. View all records in the descending order of roll number" << endl;
			cout << "5. Search for a record in the list" << endl;
			cout << "6. Exit" << endl;
			cout << "\nEnter your choice (1-6): ";
			char ch;
			cin >> ch;

			switch (ch) {
			case '1':
				obj.addNode();
				break;
			case '2':
				obj.hapus();
				break;
			case '3':
				obj.traverse();
				break;
			case '4':
				obj.revtraverse();
				break;
			case '5':
				obj.searchData();
				break;
			case '6':
				return 0;
			default:
				cout << "\nInvalid option" << endl;
				break;
			}
		}
		catch (exception& e) {
			cout << "Check for the values entered." << endl;
		}
	}
}
