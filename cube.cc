// Programmer: Mihalis Tsoukalos
// Date: Wednesday 04 June 2014
//
// A simple OpenGL program that draws a colorful cube
// that rotates as you move the arrow keys!
//
// g++ cube.cc -lm -lglut -lGL -lGLU -o cube

#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>

// Rotate X
double rX=0;
// Rotate Y
double rY=0;

// The coordinates for the vertices of the cube
double x = 0.6;
double y = 0.6;
double z = 0.6;

void drawCube()
{
        // Set Background Color
    glClearColor(0.4, 0.4, 0.4, 1.0);
        // Clear screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Reset transformations
    glLoadIdentity();

    // Rotate when user changes rX and rY
    glRotatef( rX, 1.0, 0.0, 0.0 );
    glRotatef( rY, 0.0, 1.0, 0.0 );

    // BACK
        glBegin(GL_TRIANGLES);
            glColor3f(0.4, 0.3, 0.5);
                glVertex3f(x, y, z);
                glVertex3f(x, -y, z);
                glVertex3f(-x, y, z);
        glEnd();

        glBegin(GL_TRIANGLES);
            glColor3f(0.5, 0.3, 0.2);
                glVertex3f(-x, -y, z);
                glVertex3f(x, -y, z);
                glVertex3f(-x, y, z);
        glEnd();

        // FRONT
        // Using 4 trianges!
        glBegin(GL_TRIANGLES);
            glColor3f(0.1, 0.5, 0.3);
                glVertex3f(-x, y, -z);
                glVertex3f(0, 0, -z);
                glVertex3f(-x, -y, -z);
        glEnd();

        glBegin(GL_TRIANGLES);
                glColor3f(0.0, 0.5, 0.0);
                glVertex3f(-x, -y, -z);
                glVertex3f(0, 0, -z);
                glVertex3f(x, -y, -z);
        glEnd();

        glBegin(GL_TRIANGLES);
            glColor3f(0.1, 0.3, 0.3);
                glVertex3f(-x, y, -z);
                glVertex3f(x, y, -z);
                glVertex3f(0, 0, -z);
        glEnd();

        glBegin(GL_TRIANGLES);
                glColor3f(0.2, 0.2, 0.2);
                glVertex3f(0, 0, -z);
                glVertex3f(x, y, -z);
                glVertex3f(x, -y, -z);
        glEnd();

        // LEFT
        glBegin(GL_TRIANGLES);
        glColor3f(0.3, 0.5, 0.6);
                glVertex3f(-x, -y, -z);
                glVertex3f(-x, -y, z);
                glVertex3f(-x, y, -z);
        glEnd();

        glBegin(GL_TRIANGLES);
                glColor3f(0.5, 0.5, 0.5);
                glVertex3f(-x, y, z);
                glVertex3f(-x, -y, z);
                glVertex3f(-x, y, -z);
        glEnd();

        // RIGHT
        glBegin(GL_TRIANGLES);
        glColor3f(0.2, 0.2, 0.2);
                glVertex3f(x, y, z);
                glVertex3f(x, y, -z);
                glVertex3f(x, -y, z);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3f(0.0, 0.0, 0.0);
                glVertex3f(x, -y, -z);
                glVertex3f(x, y, -z);
                glVertex3f(x, -y, z);
        glEnd();

        // TOP
        glBegin(GL_TRIANGLES);
        glColor3f(0.6, 0.0, 0.0);
                glVertex3f(x, y, z);
                glVertex3f(x, y, -z);
                glVertex3f(-x, y, -z);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3f(0.6, 0.1, 0.2);
                glVertex3f(-x, y, z);
                glVertex3f(x, y, z);
                glVertex3f(-x, y, -z);
        glEnd();

        // BOTTOM
        glBegin(GL_TRIANGLES);
        glColor3f(0.4, 0.0, 0.4);
                glVertex3f(-x, -y, -z);
                glVertex3f(-x, -y, z);
                glVertex3f(x, -y, z);
        glEnd();

        glBegin(GL_TRIANGLES);
                glColor3f(0.3, 0.0, 0.3);
                glVertex3f(x, -y, -z);
                glVertex3f(-x, -y, -z);
                glVertex3f(x, -y, z);
        glEnd();

    glFlush();
    glutSwapBuffers();
}

void keyboard(int key, int x, int y)
{
    if (key == GLUT_KEY_RIGHT)
        {
                rY += 15;
        }
    else if (key == GLUT_KEY_LEFT)
        {
                rY -= 15;
        }
    else if (key == GLUT_KEY_DOWN)
        {
                rX -= 15;
        }
    else if (key == GLUT_KEY_UP)
        {
                rX += 15;
        }

    // Request display update
    glutPostRedisplay();
}


int main(int argc, char **argv)
{
        // Initialize GLUT and process user parameters
        glutInit(&argc, argv);

        // Request double buffered true color window with Z-buffer
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

        glutInitWindowSize(700,700);
        glutInitWindowPosition(100, 100);

        // Create window
        glutCreateWindow("Linux Journal OpenGL Cube");

        // Enable Z-buffer depth test
        glEnable(GL_DEPTH_TEST);

        // Callback functions
        glutDisplayFunc(drawCube);
        glutSpecialFunc(keyboard);

        // Pass control to GLUT for events
        glutMainLoop();

        return 0;
}
