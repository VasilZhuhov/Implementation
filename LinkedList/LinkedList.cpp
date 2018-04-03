#include<iostream>
#include "LinkedList.h"


LinkedList::LinkedList() {
	head = NULL;
	tail = NULL;
}

Node* LinkedList::get(int index) {
	Node* node = head;
	for (int i = 0; i < index; i++) {
		if (node == NULL) {
			break;
		}
		node = node->next;
	}
	return node;
}

Node* LinkedList::search(int value) {
	Node* node = head;
	while (node != NULL) {
		if (node->data == value) {
			break;
		}
		node = node->next;
	}

	return node;
}

void LinkedList::print() {
	Node* temp;
	temp = head;
	while (temp != NULL) {
		std::cout << temp->data << "->";
		temp = temp->next;
	}
	std::cout << std::endl;
}

void LinkedList::pushBack(int value) {
	Node* node = new Node;
	node->data = value;
	node->next = NULL;
	if (head == NULL) {
		head = node;
		tail = node;
	}
	else {
		tail->next = node;
		tail = node;
	}
}

void LinkedList::insertAt(int position, int value) {
	Node* node = new Node;
	node->data = value;
	node->next = NULL;
	Node *prevNode, *nextNode;
	prevNode = get(position-1);
	nextNode = prevNode->next;
	prevNode->next = node;
	node->next = nextNode;
}

void LinkedList::deleteAt(int pos)
{
	Node *current = new Node;
	Node *previous = new Node;
	current = head;
	for (int i = 1; i<pos; i++)
	{
		previous = current;
		current = current->next;
	}
	previous->next = current->next;
}
