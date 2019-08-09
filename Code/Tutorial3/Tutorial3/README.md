Tutorial 3 - Object Groupings (1/3)
=============================

# Tutorial 3 Result
![Tutorial 3](https://github.com/jingyangcarl/Resources/blob/master/QtOpenGLTutorials/Tutorial3/result.jpg)

# Solution Introduction
This tutorial solution introduces how to add other objects and translate it to a given position;

# Solution Environment:
* Windows 10
* Visual Studio 2019
* Qt 5.12.3

# Solution Documentation:
> Form Files
>> [Tutorial3.ui](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial3/Tutorial3/Tutorial3.ui): Qt UI file, where QOpenGLWidget is promoted to Widget defined in Widget.h;
>
> Header Files
>> [SimpleObject3D.h](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial3/Tutorial3/SimpleObject3D.h): Used to define a 3D object;
>>
>>> void init(const QVector<Vertex>& vertices, const QVector<GLuint>& indices, const QImage& image): This function is used to initialize an object with its vertices reference, indices reference, and texture image reference;
>>>
>>> void draw(QOpenGLShaderProgram *shaderProgram, QOpenGLFunctions *functions): This function is used to set parameters for the vertex shader, fragment shader and etc. and draw the object;
>>>
>>> void translate(const QVector3D &translateVector): This function is used to translate the object;
>>
>> [Tutorial3.h](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial3/Tutorial3/Tutorial3.h): Qt framework;
>>
>> [Widget.h](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial3/Tutorial3/Widget.h): Derived from QOpenGLWidget, used to implement OpenGL pipeline;
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
>> [main.cpp](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial3/Tutorial3/main.cpp)
>>
>> [SimpleObject3D.cpp](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial3/Tutorial3/SimpleObject3D.cpp): implements SimpleObject3D.h;
>>
>> [Tutorial3.cpp](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial3/Tutorial3/Tutorial3.cpp): implements Tutorial3.h;
>>
>> [Widget.cpp](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial3/Tutorial3/Widget.cpp): implements Widget.h;
>
> Shader Files
>> [FragmentShader.fsh](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial3/Tutorial3/FragmentShader.fsh): The fragment shader implements phong shading including diffuse light, ambient light, as well as specular light;
>>
>> [VertexShader.vsh](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial3/Tutorial3/VertexShader.vsh): The vertex shader projects vertices;
>

# Solution Hierarchy:
./Tutorial3
│   README.md
│   Tutorial3.sln
│
└───Tutorial3
    │   cube.jpg
    │   FragmentShader.fsh
    │   main.cpp
    │   README.md
    │   SimpleObject3D.cpp
    │   SimpleObject3D.h
    │   Tutorial3.cpp
    │   Tutorial3.h
    │   Tutorial3.qrc
    │   Tutorial3.ui
    │   Tutorial3.vcxproj
    │   Tutorial3.vcxproj.filters
    │   Tutorial3.vcxproj.user
    │   VertexShader.vsh
    │   Widget.cpp
    │   Widget.h
    │
    └───GeneratedFiles
        │   qrc_Tutorial3.cpp
        │   ui_Tutorial3.h
        │
        ├───Debug
        │       moc_Tutorial3.cpp
        │
        └───Release
                moc_Tutorial3.cpp
