#include "Graph.h"

// test for header guards
#include "Graph.h"

int main() {
	
	// make a graph
	gdwg::Graph<unsigned int,int> g;
	
	// add a node
	g.addNode(1);
	
	// print out the singular node
	std::cout << "Graph g nodes:" << std::endl;
	g.printNodes();
	
	unsigned int i = 2;
	
	// test if things are nodes or not
	std::cout << std::boolalpha << g.isNode(i-1) << " " << g.isNode(2) << std::endl;
	
	// add a second node
 	g.addNode(i);
	
	// test if there is an edge
	std::cout << g.isConnected(1,2) << std::endl;
	
	// add an edge and repeat the test
	g.addEdge(i-1,i,i+1);
	std::cout << g.isConnected(1,2) << std::endl;
	
	// print the edges
	g.printEdges(1);
	g.printEdges(2);
	
	// print the graph
	g.printNodes();

	// add a second edge to prove that two edges with different weights
	// to the same nodes
	g.addEdge(i-1,i,i+2);
}
