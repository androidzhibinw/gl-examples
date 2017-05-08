
//g++ 2.2.cc -lGL -lglut -lGLEW -o 2.2

#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <GL/glew.h>
#include <GL/freeglut.h>

int i=0;
static void GLRender()
{
    i++; 
    float g=i/10.0f;
    GLfloat red [] = {sin(g),cos(g),0.0f,1.0f};
    glClearBufferfv(GL_COLOR, 0, red);
}

static void Render()
{
    GLRender();
    glFlush();
    glutSwapBuffers();
    glutPostRedisplay();
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
    glutCreateWindow("list 2.2");
    InitializeGlutCallbacks();
    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
      fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
    }
    glutMainLoop();
    return 0;

}
