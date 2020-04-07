#ifndef GRAPH_H
#define GRAPH_H

#include <vector>


template <typename T>
class Graph
{

public:
    Graph();
    
    int AddNode(T node);
    T GetNode(int node_id);
    void AddEdge(int node1_id, int node2_id);
    std::vector<int> GetNeighborIndices(int node_id);
    std::vector<T> GetNeighbors(int node_id);



private:
    std::vector<std::vector<int>> adj_list_;
    std::vector<T> nodes_;


};




#endif

// Templated function definitions
#include "graph.hpp"
