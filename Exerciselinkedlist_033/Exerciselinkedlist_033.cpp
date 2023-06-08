#include <iostream>
#include <string>
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
	void addNode(Node** Praja, Node** Defarrel);
	bool search(int rollno, Node** Praja, Node** Defarrel);
	bool listEmpty();
	bool delNode();
	void traverse();
};
void CircularLinkedList::addNode(Node** Praja, Node** Defarrel) {
	Node* newNode = new Node(); //mengalokasikan memory untuk node baru
	LAST =newNode;				//menetapkan nilai ke node baru
	newNode->next = LAST;		//membuat field berikutnya dari titik baru ke last
	LAST -> next = newNode;
	LAST = NULL;
	while ((*Defarrel) != LAST) {// membuat loop 
		*Praja = *Defarrel;
		*Defarrel = (*Defarrel)->next;
	}
	Node* temp = new Node();//membuat memory untuk node baru
	temp->next = newNode;
	newNode->next = LAST;
	LAST = newNode;
	
}
bool CircularLinkedList::search(int rollno, Node** Praja, Node** Defarrel) {
	*Praja = LAST->next;
	*Defarrel = LAST->next;
	while (*Defarrel != LAST) {
		if (rollno == (*Defarrel)->rollNumber) {
			return true;
		}
		*Praja = *Defarrel;
		*Defarrel = (*Defarrel)->next;
	}
	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}
bool CircularLinkedList::listEmpty() {
	return LAST == NULL;
}
bool CircularLinkedList::delNode() { 
	Node* curr = LAST; //membuat memory untuk node baru
	Node* prev = NULL;
	if (curr == LAST && curr->next == LAST) { // membuat if else 
		LAST = NULL;
	}
	else if (curr == LAST) {  
		Node* temp = LAST;
		while (temp->next != LAST) {
			temp = temp->next;
		}
		LAST = LAST->next;
		temp->next = LAST;
	}
	else {  
		prev->next = curr->next;
	}

	delete curr;
	return true;

}
void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* currentNode = LAST->next;
		while (currentNode != LAST) {
			cout << currentNode->rollNumber << " " << currentNode->name << endl;
			currentNode = currentNode->next;
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
			}
			case '2': {
			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
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