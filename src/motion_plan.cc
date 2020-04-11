#include<iostream>
#include <chrono>
#include <thread>

#include "scene.h"
#include "prm.h"
#include "graph.h"
#include "scene_painter.h"

using std::cout, std::endl;

int main() {

    int width = 640;
    int height = 480;

    Scene scene(35, height - 35, width - 35, 35, width, height);
    scene.AddRectObstacle(Scene::Rect(100, 100, 100, 200));
    scene.AddRectObstacle(Scene::Rect(400, 300, 70, 30));
    scene.AddRectObstacle(Scene::Rect(300, 200, 120, 120));

    Prm p(200, 2);
    p.NavigateScene(scene);

    SimpleGL graphics("PRM", 200, 200, width, height, SimpleGL::Color(0.1569, 0.6314, 0.5294, 0.5));
    graphics.Init();
    ScenePainter().PaintScene(graphics, scene);

    while (!graphics.HasQuit())
    {
        // Twiddle Thumbs
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    graphics.Destroy();
    return 0;
}
