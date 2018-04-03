#include<vector>

class Node {
public:
	Node* parent;
	int value;
	std::vector<Node*> rightChildren = std::vector<Node*>();
	std::vector<Node*> leftChildren = std::vector<Node*>();
	Node(Node* parent, int value) {
		this->parent = parent;
		this->value = value;
	}
private:
	Node* root;

};