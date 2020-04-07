#include<iostream>

#include "scene.h"
#include "astar.h"
#include "graph.h"

using std::cout, std::endl;

int main() {

    Scene scene(1, 2, 3, 4, 20, 30);
    scene.AddRectObstacle(Scene::Rect(22, 33, 44, 55));
    scene.AddRectObstacle(Scene::Rect(22, 33, 44, 55));

    AStar a(5, 2);
    a.NavigateScene(scene);

    return 0;
}
