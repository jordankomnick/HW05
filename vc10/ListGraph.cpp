
#include "ListGraph.h"


ListGraph::ListGraph(int numNodes){

}

ListGraph::~ListGraph(){

}

void ListGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){

}

EdgeWeight ListGraph::weight(NodeID u, NodeID v) const
{
	//iterator code from what we did in class
	edgeList[u];
	EList::const_iterator it;
	for(it=edgeList[u].begin(); it != edgeList[u].end(); it++){
		NWPair theEdge = *it; //operator overloading to make iterator behave like a pointer
		if(theEdge.first == v){
			return theEdge.second;
		}
	}

	return 0.0;
}

std::list<NWPair> ListGraph::getAdj(NodeID u) const
{
	return edgeList[NULL];

}

unsigned ListGraph::degree(NodeID u) const
{
	return 0.0;

}

unsigned ListGraph::size() const
{
	return 0.0;

}

unsigned ListGraph::numEdges() const
{
	return 0.0;

}