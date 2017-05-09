
# Start OpenGL ES 3 on  Android:

This repo is used for opengles demo for Android platform. Each folder is a standalone Android project. Each project will demostrade a OpenGL ES program. 


# Environment set up 
1. Android SDK (version >= 23  )
2. Android NDK (version >=r10) 
3. apache-ant (version >=1.9.9)

# How to Build ? 
1. enter project 
2. `ndk-build` (depend on Android NDK).
3. `ant debug` (depend on Android SDK and apache ant) 

# What each demo do ?

1. old-linux : no use any more, for linux platform only. Because on linux the opengl version is too low(3.0) , some modern opengl api not supported so I give up the linux platform. Turn to Android with OpenGL ES. 

2. mygles3: This is a simplest android opengl program, which only show a red screen. 

3. triangles:  draw a simple triangle. 

4. Rectangles:  draw a rectangle.

5. Shader01:  draw color triangle.

6. Shader02: using uniform variable in glsl and change color each frame, draw triangle.

7. Shader03:　pass color variable from vertex shader to fragement shader. 

8. Textures01: texture example, draw a picture with texture.

9. Textures01: mix two textures.



