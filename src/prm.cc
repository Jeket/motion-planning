#include <random>
#include <iostream>

#include "prm.h"
#include "scene.h"

using std::cout, std::endl;

Prm::Prm(int node_count, int k) : node_count_(node_count), k_(k), mt_(rd_())
{
}

void Prm::NavigateScene(Scene scene)
{
    Prm::PopulateGraph(scene);

}


void Prm::PopulateGraph(Scene scene)
{
    start_node_id_ = graph_.AddNode(scene.GetStart());
    end_node_id_ = graph_.AddNode(scene.GetEnd());

    std::uniform_int_distribution x_dist(0, scene.GetWidth());
    std::uniform_int_distribution y_dist(0, scene.GetHeight());

    int nodes_added = 0;
    while (nodes_added < node_count_)
    {
        int x = x_dist(mt_);
        int y = y_dist(mt_);
        cout << x << endl;
        cout << y << endl;
        nodes_added++;
    }
}
