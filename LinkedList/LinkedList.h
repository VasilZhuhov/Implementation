#include "Node.h"


class LinkedList {
private:
	Node* head;
	Node* tail;
public:
	LinkedList();
	Node* get(int index);
	Node* search(int value);
	void pushBack(int value);
	void insertAt(int pos, int value);
	void deleteAt(int pos);
	void print();
};
