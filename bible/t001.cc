
//g++ t001.cc -lGL -lglut -lGLEW -o t001

#include <stdio.h>
#include <GL/glew.h>
#include <GL/freeglut.h>

static void GLRender()
{
    static const GLfloat red [] = {1.0f,0.0f,0.0f,1.0f};
    glClearBufferfv(GL_COLOR, 0, red);

}

static void Render()
{
    GLRender();
    glutSwapBuffers();
}

static void InitializeGlutCallbacks()
{
    glutDisplayFunc(Render);
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowSize(1024,768);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("sample t001");
    InitializeGlutCallbacks();
    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
      fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
    }
    glutMainLoop();
    return 0;

}
