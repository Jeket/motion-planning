#include <vector>

#include "scene.h"

Scene::Scene(int startX, int startY, int endX, int endY, int width, int height) :
    start_(startX, startY), end_(endX, endY), width_(width), height_(height)
{
}

void Scene::AddRectObstacle(Scene::Rect rect)
{
    rectangles_.push_back(rect);
}

std::vector<Scene::Rect> Scene::GetRectangles()
{
    return rectangles_;
}

Scene::Point Scene::GetStart()
{
    return start_;
}

Scene::Point Scene::GetEnd()
{
    return end_;
}

int Scene::GetWidth()
{
    return width_;
}

int Scene::GetHeight()
{
    return height_;
}
