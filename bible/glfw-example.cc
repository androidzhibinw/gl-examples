
//g++ t001.cc -lGL -lglut -lGLEW -o t001

#include <stdio.h>
#include <unistd.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
int i=0;
static void GLRender()
{
    i++;
     GLfloat red [] = {1.0,0.0f,0.0f,1.0f};
     GLfloat yellow [] = {1.0,1.0f,0.0f,1.0f};
    sleep(1);
    if(i%2){
      glClearBufferfv(GL_COLOR, 0, red);
     } else {
      glClearBufferfv(GL_COLOR, 0, yellow);
     }
}

int main(int argc, char** argv)
{
    /* Initialize the library */
    if (!glfwInit())
        return -1;
    /* Create a windowed mode window and its OpenGL context */
    GLFWwindow* window;
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
      fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
    }

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        GLRender();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;

}
