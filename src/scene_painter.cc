#include "scene_painter.h"

#include "scene.h"
#include "simplegl.h"

ScenePainter::ScenePainter()
{
}

void ScenePainter::PaintScene(SimpleGL graphics, Scene scene)
{

    for (Scene::Rect rect : scene.GetRectangles())
    {
        graphics.DrawRect(rect.x, rect.y, rect.width, rect.height, SimpleGL::Color(0.2275, 0.1255, 0.6314, 1));
    }

    for (Scene::Point point : scene.GetGraph().GetAllNodes())
    {
        graphics.DrawPoint(SimpleGL::Point(point.x, point.y), 5, SimpleGL::Color(0, 0, 0, 1));
    }

    graphics.DrawPoint(SimpleGL::Point(scene.GetStart().x, scene.GetStart().y), 8, SimpleGL::Color(0.0706, 0.098, 0.6, 1));
    graphics.DrawPoint(SimpleGL::Point(scene.GetEnd().x, scene.GetEnd().y), 8, SimpleGL::Color(0.6, 0.0706, 0.1176, 1));

    // TODO: Draw Edges


    graphics.Update();
}
