#include<vector>
#include<iostream>
class Node {
public:
	Node* parent;
	int data;
	Node* children[2];
	Node(Node* parent, int data) {
		this->parent = parent;
		this->data = data;
	}
	Node() {
		this->parent = NULL;
		this->data = NULL;
	}

};