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

class DoubleLinkedList {
private: 
	Node* START;
public: 
	DoubleLinkedList() {
		START = NULL;
	}

	void addNode() {
		int nim;
		string nm;
		cout << "\nEnter the roll number of the student : ";
		cin >> nim;
		cout << "\nEnter the name of the student : ";
		cin.ignore();
		getline(cin, nm);
		Node* newNode = new Node(); //step 1
		newNode->noMhs = nim; //step 2
		newNode->name = nm;// step 2

		/*insert a node in the begining of a doubly - linked list*/
		if (START == NULL || nim <= START->noMhs) {
			if (START != NULL && nim == START->noMhs) {
				cout << "\nDuplicated number of allowed" << endl;
				return;
			}
			newNode->next = START; //step 3
			if (START != NULL)
				START->prev = newNode;//Step 4
			newNode->prev = NULL; //Step 5
			START = newNode; //Step 6
			return;
		}
		/*inserting a Node Between Two Nodes in the List*/
		Node* current = START; //step1 a.
		while (current->next != NULL && current->next->noMhs < nim) //step1.c
		{
			current = current->next; //1.e
		}

		if (current->next != NULL && nim == current->next->noMhs) {
			cout << "\nDuplicate roll Numbers not allowed" << endl;
			return;
		}
		newNode->next = current->next; //step 4
		newNode->prev = current; //step 5
		if (current->next != NULL)
			current->next->prev = newNode; //step 6
		current->next = newNode;//step 7
	}
	bool search(int rollNo, Node** previous, Node** current) {
		*previous = START; //stepp 1.a
		*current = START; // step 1.b
		while (*current != NULL && rollNo != (*current)->noMhs) {//Step 1.c
			*previous = *current; //step 1.d
			*current = (*current)->next; //step1.e
		}
		return (*current != NULL);
	}
	bool deleteNode(int rollNo) {
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
	bool ListEmpty() {
		return (START == NULL);
	}
	void ascending() {
		if (ListEmpty())
			cout << "\nlist empty" << endl;
		else {
			cout << "\nRecords in ascending order of roll number are : " << endl;
			Node* currentNode = START;
			while (currentNode != NULL) {
				cout << currentNode->noMhs << " " << currentNode-> name << endl;
				currentNode = currentNode->next;
			}
		}
	}
	void descending() {
		if (ListEmpty())
			cout << "\nListEmpty" << endl;
		else {
			cout << "\nRecords in descending order of roll numebr are : " << endl;
			Node* currentNode = START;
			while (currentNode != NULL) 
				currentNode = currentNode->next;
			while (currentNode) {
				cout << currentNode->noMhs << " " << currentNode->name << endl;
				currentNode = currentNode->prev;
			}			
		}
	}
};

int main() {
	DoubleLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all records in the ascending order of roll numbers" << endl;
			cout << "4. View all records in the descending order of roll numbers" << endl;
			cout << "5. Search for a record in the list" << endl;
			cout << "6. Exit" << endl;
			cout << "\nEnter your choice (1-6): ";
			char ch;
			cin >> ch;

			switch (ch) {
			case '1' :
				obj.addNode();
				break;
			case '2' :
				if (obj.ListEmpty()) {
					cout << "\nList Empty" << endl;
					break;
				}
				cout << "\nEnter the roll number of the student whose record is to be deleted: ";
				int rollNo;
				cin >> rollNo;
				cout << endl;
				if (obj.deleteNode(rollNo) == false)
					cout << "Record not found" << endl;
				else
					cout << "Record with roll number " << rollNo << " deleted" << endl;
				break;
			case '3' :
				obj.ascending();
				break;
			case '4': 
				obj.descending();
				break;
			case '5' :
				if (obj.ListEmpty() == true) {
					cout << "\nList is Empty" << endl;
					break;
				}
				Node* prev, * curr;
				prev = curr = NULL;
				cout << "\nENeter the roll number of the student whose record you want to search: ";
				int num;
				cin >> num;
				if (obj.search(num, &prev, &curr) == false)
					cout << "\nrecord not found" << endl;
				else {
					cout << "\nRecord found" << endl;
					cout << "\nRecord number: " << curr->noMhs << endl;
					cout << "\nName: " << curr->name << endl;
				}
				break;
			case '6' :
				return 0;
			default :
				cout << "\nInvalid option" << endl;
				break;
			}
		}
		catch (exception& e) {
			cout << "Check for the values entered." << endl;
		}
	}
}






