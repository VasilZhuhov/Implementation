#include "BST.h"
BST::BST() {

}
Node* BST::newnode(int element) {
	Node* temp = new Node();
	temp->data = element;
	temp->children[0] = temp->children[1] = NULL;
	return temp;
}

/* Function to convert the Sorted array to BST */

Node* BST::create(int* arr, int start, int end) {
	if (start > end) {
		return NULL;
	}

	int mid = (start + end) / 2;
	Node* root = newnode(arr[mid]);
	root->children[0] = create(arr, mid + 1, end);
	root->children[1] = create(arr, start, mid - 1);

	return root;
}

void BST::recursivePrint(std::vector<Node*> nodes) {
	std::vector<Node*> allChildren;
	if (nodes.size() == 0) {
		return;
	}
	for (unsigned int i = 0; i < nodes.size(); i++) {
		for (unsigned int j = 0; j < sizeof(nodes[i]->children[0])/sizeof(*nodes[i]->children[0]); j++) {
			allChildren.push_back(nodes[i]->children[j]);
		}
	}

	recursivePrint(allChildren);
	for (unsigned int i = 0; i < nodes.size(); i++) {
		std::cout << nodes[i]->data << '-';
	}
	std::cout << std::endl;
}

std::vector<Node*> BST::BFS(std::vector<Node*> nodes, int data) {
	std::vector<Node*> results;
	std::vector<Node*> allChildren;
	if (nodes.size() == 0) {
		return results;
	}

	for (unsigned int i = 0; i < nodes.size(); i++) {
		if (nodes[i]->data == data) {
			results.push_back(nodes[i]);
		}
		for (unsigned int j = 0; j < sizeof(nodes[i]->children[0]) / sizeof(*nodes[i]->children[0]); j++) {
			allChildren.push_back(nodes[i]->children[j]);
		}
	}
	std::vector<Node*> nextResults = BFS(allChildren, data);
	for (unsigned int i = 0; i < nextResults.size(); i++) {
		results.push_back(nextResults[i]);
	}
	return results;
}

void BST::print() {
	std::vector<Node*> rootVector;
	rootVector.push_back(root);
	recursivePrint(rootVector);
}


