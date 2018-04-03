#include "BinaryTree.h"
#include<iostream>

BinaryTree::BinaryTree(int value) {

	Node* root = new Node(NULL, value);
	this->root = root;

}
void BinaryTree::createBinaryTree() {
	Node* node1 = new Node(root, 2);
	Node* node2 = new Node(root, 3);
	root->rightChildren.push_back(node1);
	root->leftChildren.push_back(node2);

	Node* node3 = new Node(node1, 2);
	Node* node4 = new Node(node1, 2);
	node1->rightChildren.push_back(node3);
	node1->leftChildren.push_back(node4);

	Node* node5 = new Node(node2, 6);
	Node* node6 = new Node(node2, 7);
	node2->rightChildren.push_back(node5);
	node2->leftChildren.push_back(node6);
}
void BinaryTree::printRightBinaryTree() {
	std::vector<Node*> rootVector;
	rootVector.push_back(root);
	recursiveRightPrint(rootVector);
}

void BinaryTree::recursiveRightPrint(std::vector<Node*> nodes) {
	std::vector<Node*> allChildren;
	if (nodes.size() == 0) {
		return;
	}
	for (unsigned int i = 0; i < nodes.size(); i++) {
		for (unsigned int j = 0; j < nodes[i]->rightChildren.size(); j++) {
			allChildren.push_back(nodes[i]->rightChildren[j]);
		}
	}

	recursiveRightPrint(allChildren);
	for (unsigned int i = 0; i < nodes.size(); i++) {
		std::cout << nodes[i]->value << '-';
	}
	std::cout << std::endl;
}

void BinaryTree::recursiveLeftPrint(std::vector<Node*> nodes) {
	std::vector<Node*> allChildren;
	if (nodes.size() == 0) {
		return;
	}
	for (unsigned int i = 0; i < nodes.size(); i++) {
		for (unsigned int j = 0; j < nodes[i]->leftChildren.size(); j++) {
			allChildren.push_back(nodes[i]->leftChildren[j]);
		}
		for (unsigned int j = 0; j < nodes[i]->rightChildren.size(); j++) {
			allChildren.push_back(nodes[i]->rightChildren[j]);
		}
	}

	

	recursiveLeftPrint(allChildren);
	for (unsigned int i = 0; i < nodes.size(); i++) {
		std::cout << nodes[i]->value << '-';
	}
	std::cout << std::endl;
}

void BinaryTree::printLeftBinaryTree() {
	std::vector<Node*> rootVector;
	rootVector.push_back(root);
	recursiveLeftPrint(rootVector);
}

std::vector<Node*> BinaryTree::search(int data) {
	std::vector<Node*> rootVector;
	rootVector.push_back(root);
	std::vector<Node*> result;
	result = BFS(rootVector, data);
	return result;
}


std::vector<Node*> BinaryTree::BFS(std::vector<Node*> nodes, int data) {
	std::vector<Node*> results;
	std::vector<Node*> allChildren;
	if (nodes.size() == 0) {
		return results;
	}
	for (unsigned int i = 0; i < nodes.size(); i++) {
		if (nodes[i]->value == data) {
			results.push_back(nodes[i]);
		}
		for (unsigned int j = 0; j < nodes[i]->leftChildren.size(); j++) {
			allChildren.push_back(nodes[i]->leftChildren[j]);
		}
		for (unsigned int j = 0; j < nodes[i]->rightChildren.size(); j++) {
			allChildren.push_back(nodes[i]->rightChildren[j]);
		}
	}
	std::vector<Node*> nextResults = BFS(allChildren, data);
	for (unsigned int i = 0; i < nextResults.size(); i++) {
		results.push_back(nextResults[i]);
	}
	return results;
}


