#include "graphics.h"

namespace graphics {
    void create_window(int* argc, char** argv, int width, int height, const char* title) {
    glutInit(argc, argv);
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
        glutInitWindowSize(width, height);
        glutCreateWindow(title);
        glEnable(GL_DEPTH_TEST);
    }
    void start_loop() {
        glutMainLoop();
    }
}  // namespace graphics