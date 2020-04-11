#include <vector>
#include <iostream>

#include "scene.h"
#include "graph.h"

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

bool Scene::PointCollides(Scene::Point point)
{
    for (Rect rect : rectangles_)
    {
        if (point.x >= rect.x &&
            point.x <= rect.x + rect.width &&
            point.y >= rect.y &&
            point.y <= rect.y + rect.height)
        {
            return true;
        }
    }
    
    return false;
}

Graph<Scene::Point> Scene::GetGraph()
{
    return graph_;
}

std::vector<int> Scene::GetUsedEdges()
{
    return used_edge_indices_;
}

void Scene::SetPrm(Graph<Scene::Point> graph, std::vector<int> used_edges)
{
    graph_ = graph;
    used_edge_indices_ = used_edges;
}
