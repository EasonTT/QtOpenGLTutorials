Tutorial 1 - Project Template
=============================

# Tutorial 1 Result
![](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial1/Tutorial1/result.jpg)

# Solution Introduction
This tutorial solution is used to build up an template for using OpenGL with Qt

# Solution Environment:
* Windows 10
* Visual Studio 2019
* Qt 5.12.3

# Solution Hierarchy:
> Form Files
>> Tutorial1.ui: Qt UI file;
>
> Header Files
>> Tutoiral1.h: Qt framework;
>>
>> Widget.h: Derived from QOpenGLWidget, used to implement OpenGL pipeline;
>>
>>> void initializeGL(): This function is used to initialize OpenGL state machine;
>>> 
>>> void resizeGL(int width, int height): This function is used to deal with resive event;
>>>
>>> void paintGL(): This function is used to set parameters for the vertex shader, fragment shader and etc. and draw objects;
>>
>
> Source Files
>> main.cpp
>>
>> Tutorial1.cpp: implement Tutorial1.h;
>>
>> Widget.cpp: implement Widget.h;
>
> Shader Files
>> FragmentShader.fsh
>>
>> VertexShader.vsh
>
