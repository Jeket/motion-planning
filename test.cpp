
// This must be before OpenGL and SDL2 includes
#define GLEW_STATIC
#include <GL/glew.h>

#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello." << endl;
    // Initialize SDL2
    SDL_Init(SDL_INIT_VIDEO);

    // Initialize attributes for OpenGL
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

    // Create the window and OpenGL context
    SDL_Window *window = SDL_CreateWindow("OpenGL Test", 100, 100, 640, 480, SDL_WINDOW_OPENGL);
    SDL_GLContext context = SDL_GL_CreateContext(window);

    // Initialize GLEW
    glewExperimental = GL_TRUE;
    glewInit();

    GLuint vertex_buffer;
    glGenBuffers(1, &vertex_buffer);

    cout << vertex_buffer << endl;
    
    // Event Loop
    SDL_Event windowEvent;
    while (true)
    {
        if (SDL_PollEvent(&windowEvent))
        {
            if (windowEvent.type == SDL_QUIT)
            {
                break;
            }
        }

        SDL_GL_SwapWindow(window);
    }

    // Delete the OpenGL context, destroy the window, and quit
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;

}
