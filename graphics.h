/* Graphics library header file 
This file is beta and it may contain bugs
This lib use openGL for rendering
*/
// It will make GL easier to use
#pragma once
#include <GL/glut.h>
namespace graphics {
    void create_window(int* argc, char** argv, double w, double h, const char* title);
    void start_loop();
}