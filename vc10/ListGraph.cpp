
#include "ListGraph.h"


ListGraph::ListGraph(int numNodes)
{
	edgeList = std::vector<EList>(numNodes);
	num_edges = 0;
	num_nodes = numNodes;
}

ListGraph::~ListGraph(){

}

void ListGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight)
{
	edgeList[u].push_back(NWPair(v, weight));
	edgeList[v].push_back(NWPair(u, weight));
	num_edges++;
}

EdgeWeight ListGraph::weight(NodeID u, NodeID v) const
{
	//iterator code from what we did in class
	edgeList[u];
	EList::const_iterator it;
	for(it = edgeList[u].begin(); it != edgeList[u].end(); it++)
	{
		NWPair theEdge = *it; //operator overloading to make iterator behave like a pointer
		if(theEdge.first == v){
			return theEdge.second;
		}
	}

	return 0.0;
}

std::list<NWPair> ListGraph::getAdj(NodeID u) const
{
	EList temp;
	EList::const_iterator it;
	for(it = edgeList[u].begin(); it != edgeList[u].end(); it++)
	{
		NWPair theEdge = *it;
		if(theEdge.first != NULL)
			temp.push_back(NWPair(theEdge.first, theEdge.second));
	}
	return temp;

}

unsigned ListGraph::degree(NodeID u) const
{
	int count = 0;
	EList::const_iterator it;
	for(it = edgeList[u].begin(); it != edgeList[u].end(); it++)
	{
		NWPair theEdge = *it;
		if(theEdge.first != NULL)
			count++;
	}
	return count;

}

unsigned ListGraph::size() const
{
	return num_nodes;

}

unsigned ListGraph::numEdges() const
{
	return num_edges;

}