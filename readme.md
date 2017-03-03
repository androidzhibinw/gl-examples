
#Start Progamming OpenGL in Ubuntu:

#### using freeglut and glew
from: http://www.linuxjournal.com/content/introduction-opengl-programming 

install dependency on ubuntu: 

sudo apt-get install freeglut3 freeglut3-dev libglew-dev glew-utils


### glew-utils

glew-utils provide one tool glewinfo, using this command can see how many gl features were supported.


glew usage: http://glew.sourceforge.net/basic.html



#### using glfw and glew 

glfw: need install from http://www.glfw.org refer http://www.glfw.org/docs/latest/compile_guide.html 

after installation, it will install to /usr/local/lib/, add this path to LD_LIBRARY_PATH using: 

export LD_LIBRARY_PATH=/usr/local/lib:${LD_LIBRARY_PATH}
