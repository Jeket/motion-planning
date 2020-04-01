#include <iostream>
#include <chrono>
#include <thread>
#include "simplegl.h"

int main()
{
    std::cout << "Hi" << std::endl;
    int width = 640;
    int height = 480;
    SimpleGL::Color c(0.1569, 0.6314, 0.5294, 0.5);
    SimpleGL s("Test Window", 150, 150, width, height, c);
    s.Init();

    SimpleGL::Color c2(0.2, 0.2, 0.2, 0.5);
    int xnum = 10;
    int ynum = 10;
    for (int i = 0; i < xnum; ++i)
    {
        for (int j = 0; j < ynum; ++j)
        {
            int x = ((width / xnum) / 2) + i * (width / xnum);
            int y = ((height/ ynum) / 2) + j * (height / ynum);
            s.DrawPoint(SimpleGL::Point(x, y), 5, c2);
        }
    }

    s.Update();

    // Exit by keypress or close window button
    while (!s.HasQuit())
    {
        // Twiddle Thumbs
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    s.Destroy();
}
