#include "Node.h"
class BST {
public:
	Node* create(int* array, int start, int end);
	Node* newnode(int element);
	BST();
	void print();

private:
	Node* root;
	void recursivePrint(std::vector<Node*> nodes);
	std::vector<Node*> BFS(std::vector<Node*> nodes, int data);

};

