#ifndef PRM_H
#define PRM_H

#include <random>
#include <iostream>
#include <vector>

#include "scene.h"
#include "graph.h"

class Prm {

public:
    Prm(int node_count, int k);
    void NavigateScene(Scene& scene);


private:
    void PopulateGraph(Scene scene);


    int node_count_;
    int k_;
    Graph<Scene::Point> graph_;
    std::vector<int> used_edges_;
    int start_node_id_, end_node_id_;

    // Seed random number generation
    std::random_device rd_;
    std::mt19937 mt_;

};

#endif
