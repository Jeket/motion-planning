#ifndef ASTAR_H
#define ASTAR_H

#include <random>
#include <iostream>

#include "scene.h"
#include "graph.h"

class AStar {

public:
    AStar(int node_count, int k);
    void NavigateScene(Scene scene);


private:
    void PopulateGraph(Scene scene);


    int node_count_;
    int k_;
    Graph<Scene::Point> graph_;
    int start_node_id_, end_node_id_;

    // Seed random number generation
    std::random_device rd_;
    std::mt19937 mt_;

};

#endif
