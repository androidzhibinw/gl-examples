
//g++ t001.cc -lGL -lglut -o t001


#include <GL/freeglut.h>

static void RenderSceneCB()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

static void InitializeGlutCallbacks()
{
    glutDisplayFunc(RenderSceneCB);
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowSize(1024,768);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("sample t001");
    InitializeGlutCallbacks();

    glClearColor(1.0f,0.0f,0.0f,0.0f);

    glutMainLoop();
    return 0;

}
