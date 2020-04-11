#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "graph.h"

/**
 * A scene object that has a start point, end point, and obstacles
 *
 * Rectangle coordinates are given in numbers between 0 and 1, where (0, 0) is
 * the top left-hand corner and x goes to the right and y goes down
 */
class Scene {

public:

    struct Rect {
        int x; // x of top left corner
        int y; // y of top left corner
        int width;
        int height;

        Rect (int x, int y, int width, int height) :
            x(x), y(y), width(width), height(height)
        {
        }
    };

    struct Point {
        int x;
        int y;

        Point (int x, int y) : x(x), y(y)
        {
        }
    };

    /**
     * Create a scene object
     *
     * @param startX, startY The coordinates of the starting position
     * @param endX, endY The coordinates of the ending position
     */
    Scene(int startX, int startY, int endX, int endY, int width, int height);

    /**
     * Add a rectangular obstacle to the scene
     * 
     * @param x, y The location of the top left coordinate of the rectangle
     * @param width The width of the rectangle
     * @param height The height of the rectangle
     */
    void AddRectObstacle(Scene::Rect rect);

    /**
     * Get the rectangles in the scene
     *
     * @returns The rectangles in the scene
     */
    std::vector<Scene::Rect> GetRectangles();

    Scene::Point GetStart();

    Scene::Point GetEnd();

    int GetWidth();

    int GetHeight();

    bool PointCollides(Scene::Point point);

    Graph<Scene::Point> GetGraph();

    std::vector<int> GetUsedEdges();

    void SetPrm(Graph<Scene::Point> graph, std::vector<int> used_edges);

private:

    std::vector<Rect> rectangles_;
    Scene::Point start_, end_;
    int width_, height_;

    Graph<Scene::Point> graph_;
    std::vector<int> used_edge_indices_;


};

#endif
