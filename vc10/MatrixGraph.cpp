
#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(unsigned num_nodes){

}

MatrixGraph::~MatrixGraph(){ //may not need destructors, because you should only delete things YOU made using new

}

void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){

}

EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const{
	return NULL;
}

std::list<NWPair> MatrixGraph::getAdj(NodeID u) const{

}

unsigned MatrixGraph::degree(NodeID u) const{
	return 0;
}

unsigned MatrixGraph::size() const{
	return 0;
}

unsigned MatrixGraph::numEdges() const{
	return 0;
}


