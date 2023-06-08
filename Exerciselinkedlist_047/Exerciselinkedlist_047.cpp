#include<iostream>
#include<string>
using namespace std;

class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};

class CircularLinkedList {
private:
	Node* LAST;

public:
	CircularLinkedList() {
		LAST = NULL;
	}

	void addNode();

	bool search(int rollno, Node** Usman, Node** Isro);

	bool listEmpty();

	bool delNode();

	void traverse();

};

void CircularLinkedList::addNode(){ //Write the Answer
	Node* newNode = new Node();
	cout << "\nEnter the rollNumber ";
	cin >> newNode->rollNumber;
	cout << "\nEnter Name ";
	cin >> newNode->name;

	if (listEmpty()) {
		newNode->next = newNode;
		LAST = newNode;
	}
	else {
		newNode->next = LAST->next;
		LAST->next = newNode;
		LAST = newNode;
	}

	cout << "Record added successfully\n";
}

bool CircularLinkedList::search(int rollNo, Node** Usman, Node** Isro) {
	*Usman = LAST->next;
	*Isro = LAST->next;

	while (*Isro != LAST) {
		if (rollNo == (*Isro)->rollNumber) {
			return true;
		}
		*Usman = *Isro;
		*Isro = (*Isro)->next;
	}

	if (rollNo == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}

bool CircularLinkedList::listEmpty() {
	return LAST == NULL;
}

bool CircularLinkedList::delNode() { //Write the Answer
	if (listEmpty()) {
		cout << "\nList is empty\n";
		return false;
	}

	int rollno;
	cout << "\nEnter roll number to delete: ";
	cin >> rollno;

	Node* Usman = NULL;
	Node* Isro = NULL;
	bool found = search(rollno, &Usman, &Isro);

	if (found) {
		if (Usman == Isro) { // Only one node in the list
			delete Isro;
			LAST = NULL;
		}
		else if (Isro == LAST) { // Deleting the last node
			LAST = Usman;
			Usman->next = Isro->next;
			delete Isro;
		}
		else {
			Usman->next = Isro->next;
			delete Isro;
		}
		cout << "Record deleted successfully\n";
		return true;
	}
	else {
		cout << "Record not found\n";
		return false;
	}
}

void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are: \n";
		Node* IsroNode = LAST->next;
		while (IsroNode != LAST) {
			cout << IsroNode->rollNumber << " " << IsroNode->name << endl;
			IsroNode = IsroNode->next;
		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}

int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";

			char ch;
			cin >> ch;
			switch (ch) {
			case '1': {
				obj.addNode();
				break;
			}
			case '2': {
				obj.delNode();
				break;
			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				obj.listEmpty();
				return 0;
			}
			default: {
				cout << "Invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}