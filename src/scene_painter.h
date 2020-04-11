#ifndef SCENE_PAINTER_H
#define SCENE_PAINTER_H

#include "scene.h"
#include "simplegl.h"

class ScenePainter {

public:
    ScenePainter();

    void PaintScene(SimpleGL graphics, Scene scene);
};

#endif
