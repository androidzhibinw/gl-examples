
//g++ 2.4.cc -lGL -lglut -lGLEW -o 2.4

#include <stdio.h>
#include <GL/glew.h>
#include <GL/freeglut.h>

GLuint rendering_program;
GLuint vertex_array_object;
GLenum err;

void check_glError(void)
{
    while((err = glGetError()) != GL_NO_ERROR)
    {
        printf("GL error is %d",err);
    }
}
void checkShaderStatus(GLuint shader,const char* msg)
{
    GLint val = GL_FALSE;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &val);
    if( val != GL_TRUE)
    {
        printf("shader status wrong in %s",msg);
    }
}

void checkShaderLog(GLuint shader) 
{
    GLint maxLen=0;
    glGetShaderiv(shader,GL_INFO_LOG_LENGTH, &maxLen);
    if ( maxLen != 0) 
    {
        GLchar* errLog = (GLchar*)malloc(sizeof(GLchar) * maxLen);
        glGetShaderInfoLog(shader,maxLen,&maxLen,&errLog[0]);
        printf("error log is  %s",errLog);
    }
}

GLuint compile_shaders(void)
{
    GLuint vertex_shader;
    GLuint fragment_shader;
    GLuint program;
    //source for vetex shader
    static const GLchar * vertex_shader_source []= 
    {
        "#version 130                            \n"
        "void main()                             \n"
        "{                                           \n"
        "    const vec4 vertices[3] = vec4[3](vec4(0.25, -0.25, 0.5,1.0),vec4(-0.25,-0.25,0.5,1.0),vec4(0.25,0.25,0.5,1.0)); \n"
        "    gl_Position = vertices[gl_VertexID]; \n"
        "}                                           \n"
    };
    // source for fragement shader
    static const GLchar * fragment_shader_source []= 
    {
        "                                            \n" 
        "void main(void)                             \n"
        "{                                           \n"
        "   gl_FragColor = vec4(1.0, 0.8, 0.0, 1.0);        \n"
        "}                                           \n"
    };
    vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, vertex_shader_source, NULL);
    glCompileShader(vertex_shader);
    checkShaderStatus(vertex_shader,"vertex compiling\n");
    checkShaderLog(vertex_shader);
    // Create and compile fragment shader
    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, fragment_shader_source, NULL);
    glCompileShader(fragment_shader);
    checkShaderStatus(fragment_shader,"fragement compiling\n");
    // Create program, attach shaders to it, and link it
    program = glCreateProgram();
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);
    // Delete the shaders as the program has them now
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);
    return program;
}

static void GLRender()
{
    static const GLfloat red [] = {0.0f,0.2f,0.0f,1.0f};
    glClearBufferfv(GL_COLOR, 0, red);
    glUseProgram(rendering_program);
    glPointSize(40.0f);
    //glDrawArrays(GL_POINTS, 0, 1);
    glDrawArrays(GL_TRIANGLES, 0, 3);

}
void startUp()
{
    rendering_program = compile_shaders();
    glGenVertexArrays(1, &vertex_array_object);
    glBindVertexArray(vertex_array_object);
}

void shutDown()
{
    glDeleteVertexArrays(1, &vertex_array_object);
    glDeleteProgram(rendering_program);
    glDeleteVertexArrays(1, &vertex_array_object);
}


static void Render()
{
    GLRender();
    glFlush();
    glutSwapBuffers();
    //glutPostRedisplay();
}


static void InitializeGlutCallbacks()
{
    glutDisplayFunc(Render);
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
    glutInitContextVersion(3,0);
    glutInitWindowSize(1024,768);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("sample t001");
    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
      fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
    }
    startUp();
    InitializeGlutCallbacks();
    glutMainLoop();
    shutDown();
    return 0;

}
