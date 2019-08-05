Tutorial 2 - Shader Lighting
=============================

# Tutorial 2 Result
![Tutorial 2](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial2/Tutorial2/result.jpg)

# Solution Introduction
This tutorial solution adds mouse events for rotation and updates fragment shader with phong shading implementation;

# Solution Environment:
* Windows 10
* Visual Studio 2019
* Qt 5.12.3

# Solution Hierarchy:
> Form Files
>> [Tutorial2.ui](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial2/Tutorial2/Tutorial2.ui): Qt UI file, where QOpenGLWidget is promoted to Widget defined in Widget.h;
>
> Header Files
>> [Tutorial2.h](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial2/Tutorial2/Tutorial2.h): Qt framework;
>>
>> [Widget.h](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial2/Tutorial2/Widget.h): Derived from QOpenGLWidget, used to implement OpenGL pipeline;
>>
>>> void initializeGL(): This function is used to initialize OpenGL state machine, and initialize shaders, objects and etc.;
>>> 
>>> void resizeGL(int width, int height): This function is used to deal with resive event;
>>>
>>> void paintGL(): This function is used to set parameters for the vertex shader, fragment shader and etc. and draw other objects;
>>>
>>> void mousePressEvent(QMouseEvent* event): This function is used to process mouse events, which is a Qt event function;
>>>
>>> void mouseMoveEvent(QMouseEvent* event): This function is used to process mouse move events, which is a Qt event function;
>>>
>>> void initShaders(): This function is used to initialize shaders objects;
>>> 
>>> void initCube(float width): This function is used to load graphics data for a cube, including vertex data and index data;
>>
>
> Source Files
>> [main.cpp](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial2/Tutorial2/main.cpp)
>>
>> [Tutorial2.cpp](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial2/Tutorial2/Tutorial2.cpp): implement Tutorial2.h;
>>
>> [Widget.cpp](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial2/Tutorial2/Widget.cpp): implement Widget.h;
>
> Shader Files
>> [FragmentShader.fsh](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial2/Tutorial2/FragmentShader.fsh): The fragment shader implements phong shading including diffuse light, ambient light, as well as specular light;
>>
>> [VertexShader.vsh](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial2/Tutorial2/VertexShader.vsh): The vertex shader projects vertices;
>
