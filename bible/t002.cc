
//g++ t002.cc -lGL -lglut -lGLEW -o t002

#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <GL/glew.h>
#include <GL/freeglut.h>

int i=0;
static void GLRender()
{
    i++; 
    if (i >100) i=0;
    float g=i/10.0f;
    GLfloat red [] = {sin(g),cos(g),0.0f,1.0f};
    glClearBufferfv(GL_COLOR, 0, red);
}

static void Render()
{
    GLRender();
    glFlush();
    glutSwapBuffers();
    sleep(1);
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
