
#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(unsigned num_nodes)
{
	M = std::vector<std::vector<EdgeWeight>>(num_nodes);
	for(int i = 0; i < num_nodes; i++)
	{
		M.push_back(std::vector<EdgeWeight>(num_nodes));
		for(int j = 0; j < num_nodes; j++)
		{
			M[i][j] = 0;
		}
	}
	num_edges = 0;
}

MatrixGraph::~MatrixGraph(){ //may not need destructors, because you should only delete things YOU made using new

}

void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight)
{
	M[u][v] = weight;
}

EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const
{
	if(M[u][v] > 0)
		return M[u][v];
	return 0;
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


