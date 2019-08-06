Tutorial 1 - Project Template
=============================

# Tutorial 1 Result
![Tutorial 1](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial1/Tutorial1/result.jpg)

# Solution Introduction
This tutorial solution is used to build up an template for using OpenGL with Qt, and display a simple cube with texture;

# Solution Environment:
* Windows 10
* Visual Studio 2019
* Qt 5.12.3

# Solution Hierarchy:
> Form Files
>> [Tutorial1.ui](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial1/Tutorial1/Tutorial1.ui): Qt UI file, where QOpenGLWidget is promoted to Widget defined in Widget.h;
>
> Header Files
>> [Tutorial1.h](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial1/Tutorial1/Tutorial1.h): Qt framework;
>>
>> [Widget.h](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial1/Tutorial1/Widget.h): Derived from QOpenGLWidget, used to implement OpenGL pipeline;
>>
>>> void initializeGL(): This function is used to initialize OpenGL state machine, and initialize shaders ,objects and etc.;
>>> 
>>> void resizeGL(int width, int height): This function is used to deal with resive event;
>>>
>>> void paintGL(): This function is used to set parameters for the vertex shader, fragment shader and etc. and draw other objects;
>>>
>>> void initShaders(): This function is used to initialize shaders and objects;
>>>
>>> void initCube(float width): This function is used to load graphics data for a cube, including vertex data and index data;
>>
>
> Source Files
>> [main.cpp](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial1/Tutorial1/main.cpp)
>>
>> [Tutorial1.cpp](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial1/Tutorial1/Tutorial1.cpp): implements Tutorial1.h;
>>
>> [Widget.cpp](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial1/Tutorial1/Widget.cpp): implements Widget.h;
>
> Shader Files
>> [FragmentShader.fsh](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial1/Tutorial1/FragmentShader.fsh): The fragment shader adds ambient light;
>>
>> [VertexShader.vsh](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial1/Tutorial1/VertexShader.vsh): The vertex shader projects vertices;
>
