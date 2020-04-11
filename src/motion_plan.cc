#include<iostream>

#include "scene.h"
#include "prm.h"
#include "graph.h"

using std::cout, std::endl;

int main() {

    Scene scene(1, 2, 3, 4, 20, 30);
    scene.AddRectObstacle(Scene::Rect(22, 33, 44, 55));
    scene.AddRectObstacle(Scene::Rect(22, 33, 44, 55));

    Prm p(5, 2);
    p.NavigateScene(scene);

    return 0;
}
