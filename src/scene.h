
/**
 * A scene object that has a start point, end point, and obstacles
 *
 * Rectangle coordinates are given in numbers between 0 and 1, where (0, 0) is
 * the top left-hand corner and x goes to the right and y goes down
 */
class Scene {

public:

    /**
     * Create a scene object
     *
     * @param startX, startY The coordinates of the starting position
     * @param endX, endY The coordinates of the ending position
     */
    Scene(int startX, int startY, int endX, int endY);

    /**
     * Add a rectangular obstacle to the scene
     * 
     * @param x, y The location of the top left coordinate of the rectangle
     * @param width The width of the rectangle
     * @param height The height of the rectangle
     */
    void addRectObstacle(int x, int y, int width, int height);

private:







};
