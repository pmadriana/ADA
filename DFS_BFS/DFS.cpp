//// DFS NORMAL
#include <iostream>
#include <memory>
#include <vector>

using namespace std;
class Node;
typedef std::shared_ptr <Node> pNode;

class Node {
public:
	Node() : value(0), adjacent() {}
	Node(int value) : value(value), adjacent() {}
	Node(int value, std::vector<pNode> adj) : value(value), adjacent(adj) {}
	~Node() {}

	int getValue() const { return value; }
	int getNumAdjacencies() const { return adjacent.size(); }
	void setAdj(std::vector<pNode> newAdj) { adjacent = newAdj; }
	std::vector<pNode> getAdj() const { return adjacent; }
	pNode getAdj(int index) { return adjacent.at(index); }
	bool setValue(int newValue) { value = newValue; return true; }

private:
	int value;
	std::vector<pNode> adjacent;
};

class Graph
{
public:
	Graph() : root(nullptr) {}
	Graph(pNode node) : root(node) {}
	~Graph() {}

	pNode getNode(int value);
	pNode root;
	pNode DFS(int value, pNode node);
};
pNode Graph::getNode(int value)
{
	if (root == nullptr)
	{
		std::cout << "VACIO" << std::endl;
		return nullptr;
	}
	return DFS(value, root);
}

pNode Graph::DFS(int value, pNode node)
{
	std::cout << node->getValue() << " ";
	if (node->getValue() == value)
	{
		return node;
	}
	if (node->getNumAdjacencies() > 0)
	{
		std::vector<pNode> adj = node->getAdj();
		std::vector<pNode>::iterator it = adj.begin();
		for (; it != adj.end(); ++it)
		{
			//STACK
			pNode foundNode = DFS(value, *it);
			if (foundNode != nullptr) return foundNode;
		}
	}

	return nullptr;
}


int main()
{
	//1 - 2,3,4
	//2 - 5,6
	//4 - 8
	//8 - 7
	cout << "DFS" << endl;
	pNode n1(new Node(1));
	pNode n2(new Node(2));
	pNode n3(new Node(3));
	pNode n4(new Node(4));
	pNode n5(new Node(5));
	pNode n6(new Node(6));
	pNode n7(new Node(7));
	pNode n8(new Node(8));

	vector<pNode> adj1;
	adj1.insert(adj1.begin(), n2);
	adj1.insert(adj1.begin(), n3);
	adj1.insert(adj1.begin(), n4);
	n1->setAdj(adj1);


	vector<pNode> adj2;
	adj2.insert(adj2.begin(), n5);
	adj2.insert(adj2.begin(), n6);
	n2->setAdj(adj2);


	vector<pNode> adj3;
	adj3.insert(adj3.begin(), n8);
	n4->setAdj(adj3);


	vector<pNode> adj4;
	adj4.insert(adj4.begin(), n7);
	n8->setAdj(adj4);

	Graph graph(n1);
	//graph.DFS(2, n2);
	graph.getNode(2);
	cout << std::endl;

	std::cin.get();
	return 0;
}
