// Programmer: Mihalis Tsoukalos
// Date: Wednesday 04 June 2014
//
// A simple OpenGL program that draws a triangle
// and automatically rotates it.
//
// g++ rotateCube.cc -lm -lglut -lGL -lGLU -o rotateCube

#include <iostream>
#include <stdlib.h>

// the GLUT and OpenGL libraries have to be linked correctly
#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;

// The coordinates for the vertices of the cube
double x = 0.6;
double y = 0.6;
double z = 0.6;

float angle = 0.0;

void drawCube()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Reset transformations
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glTranslatef(0.0, 0.0, -5.0);

        // Add an ambient light
        GLfloat ambientColor[] = {0.2, 0.2, 0.2, 1.0};
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

        // Add a positioned light
        GLfloat lightColor0[] = {0.5, 0.5, 0.5, 1.0};
        GLfloat lightPos0[] = {4.0, 0.0, 8.0, 1.0};
        glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
        glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

        glTranslatef(0.5, 1.0, 0.0);
        glRotatef(angle, 1.0, 1.0, 1.0);

    glRotatef( angle, 1.0, 0.0, 1.0 );
    glRotatef( angle, 0.0, 1.0, 1.0 );
        glTranslatef(-0.5, -1.0, 0.0);

        // Create the 3D cube

    // BACK
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.3, 0.2);
    glVertex3f(x, -y, z);
    glVertex3f(x, y, z);
    glVertex3f(-x, y, z);
    glVertex3f(-x, -y, z);
    glEnd();

        // FRONT
        glBegin(GL_POLYGON);
        glColor3f(0.0, 0.5, 0.0);
        glVertex3f(-x, y, -z);
        glVertex3f(-x, -y, -z);
        glVertex3f(x, -y, -z);
        glVertex3f(x, y, -z);
        glEnd();

        // LEFT
        glBegin(GL_POLYGON);
        glColor3f(0.5, 0.5, 0.5);
        glVertex3f(-x, -y, -z);
        glVertex3f(-x, -y, z);
        glVertex3f(-x, y, z);
        glVertex3f(-x, y, -z);
        glEnd();


        // RIGHT
        glBegin(GL_POLYGON);
        glColor3f(0.0, 0.0, 0.0);
        glVertex3f(x, -y, -z);
        glVertex3f(x, -y, z);
        glVertex3f(x, y, z);
        glVertex3f(x, y, -z);
        glEnd();

        // TOP
        glBegin(GL_POLYGON);
        glColor3f(0.6, 0.0, 0.0);
        glVertex3f(x, y, z);
        glVertex3f(-x, y, z);
        glVertex3f(-x, y, -z);
        glVertex3f(x, y, -z);
        glEnd();


        // BOTTOM
        glBegin(GL_POLYGON);
        glColor3f(0.3, 0.0, 0.3);
        glVertex3f(-x, -y, -z);
        glVertex3f(-x, -y, z);
        glVertex3f(x, -y, z);
        glVertex3f(x, -y, -z);
        glEnd();

        glFlush();
    glutSwapBuffers();
}

// Function for increasing the angle variable smoothly, 
// keeps it <=360
// It can also be implemented using the modulo operator.
void update(int value)
{
        angle += 1.0f;
        if (angle > 360)
                {
                        angle -= 360;
        }

        glutPostRedisplay();
        glutTimerFunc(25, update, 0);
}

// Initializes 3D rendering
void initRendering()
{
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_COLOR_MATERIAL);

        // Set the color of the background
        glClearColor(0.7f, 0.8f, 1.0f, 1.0f);
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        glEnable(GL_NORMALIZE);
}


// Called when the window is resized
void handleResize(int w, int h)
{
        glViewport(0, 0, w, h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}


int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL - Rotating a Cube");
        initRendering();

    glutDisplayFunc(drawCube);
        glutReshapeFunc(handleResize);

        // Add a timer for the update(...) function
    glutTimerFunc(25, update, 0);

    glutMainLoop();
    return 0;
}
