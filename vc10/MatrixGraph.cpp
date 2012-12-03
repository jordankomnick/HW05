//MatrixGraph.cpp
//All code written by Jordan Komnick for CSE274
//Represents a graph of nodes in a matrix format
//Method documentation is found in Graph.h

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
	num_nodes = num_nodes;
}

//destructor is unnecessary for my implementation
MatrixGraph::~MatrixGraph()
{

}

void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight)
{
	M[u][v] = weight;
	M[v][u] = weight;
	num_edges++;
}

EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const
{
	if(M[u][v] > 0)
		return M[u][v];
	return 0;
}

std::list<NWPair> MatrixGraph::getAdj(NodeID u) const
{
	EList temp;
	int i = 0;
	for(int i = 0; i < num_nodes; i++)
	{
		if(M[u][i] > 0)
			temp.push_back(NWPair(i, M[u][i]));
	}
	return temp;
}

unsigned MatrixGraph::degree(NodeID u) const
{
	int count = 0;
	for(int i = 0; i < num_nodes; i++)
	{
		if(M[u][i] > 0)
			count++;
	}
	return count;
}

unsigned MatrixGraph::size() const
{
	return num_nodes;
}

unsigned MatrixGraph::numEdges() const
{
	return num_edges;
}


