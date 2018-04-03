#include "Node.h"
class BinaryTree {
public:
	BinaryTree(int data);
	void createBinaryTree();
	void printRightBinaryTree();
	void printLeftBinaryTree();

	std::vector<Node*> search(int value);



private:
	Node* root;
	void recursiveRightPrint(std::vector<Node*> nodes);
	void recursiveLeftPrint(std::vector<Node*> nodes);
	std::vector<Node*> BFS(std::vector<Node*> nodes, int data);
};