#ifndef GRAPH_HPP
#define GRAPH_HPP

// This file should only be included in one place ever: at the end of graph.h

template <typename T>
Graph<T>::Graph()
{
}


template <typename T>
int Graph<T>::AddNode(T node)
{
    nodes_.push_back(node);
    adj_list_.push_back(std::vector<int>());
    return nodes_.size() - 1;
}


template <typename T>
T Graph<T>::GetNode(int node_id)
{
    return nodes_.at(node_id);
}


template <typename T>
void Graph<T>::AddEdge(int node1_id, int node2_id)
{
    adj_list_.at(node1_id).push_back(node2_id);
    adj_list_.at(node2_id).push_back(node1_id);
}


template <typename T>
std::vector<int> Graph<T>::GetNeighborIndices(int node_id)
{
    return adj_list_.at(node_id);
}

template <typename T>
std::vector<T> Graph<T>::GetNeighbors(int node_id)
{
        std::vector<int> indices = Graph<T>::GetNeighborIndices(node_id);
        std::vector<T> neighbors;
        for (auto id : indices)
        {
            neighbors.push_back(nodes_.at(id));
        }

        return neighbors;
}

template <typename T>
std::vector<T> Graph<T>::GetAllNodes()
{
    return nodes_;
}


#endif
