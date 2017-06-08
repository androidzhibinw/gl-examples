
# Start OpenGL ES 3 on  Android:

This repo is used for OpenGLES demos on  Android platform. Each folder is a standalone Android project. Each project will demostrade a OpenGL ES program. 

refered: https://learnopengl.com 

# Environment set up 
1. Android SDK (version >= 23  )
2. Android NDK (version >=r10) 
3. apache-ant (version >=1.9.9)

# How to Build ? 
1. enter project 
2. `ndk-build` (depend on Android NDK).
3. `ant debug` (depend on Android SDK and apache ant) 

# What each demo do ?

| Folder name     | Comment |
| ------------- | ------------- |
| old-linux|no use any more, for linux platform only. Because on linux the opengl version is too low(3.0) , some modern opengl api not supported so I give up the linux platform. Turn to Android with OpenGL ES|
| mygles3  | This is a simplest android opengl program, which only show a red screen|
|triangles| draw a simple triangle. |
|Rectangles| draw a rectangle|
|Shader01| draw color triangle with shader|
|Shader02|using uniform variable in glsl and change color each frame, draw triangle|
|Shader03|pass color variable from vertex shader to fragement shader|
|Textures01|texture example, draw a picture with texture|
|Textures02|mix two textures|
|glm-example| using glm implement transform/rotation|



