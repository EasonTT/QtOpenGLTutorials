Tutorial 7 - Skybox Surroundings
=============================

# Tutorial 7 Result
![Tutorial 7](https://github.com/jingyangcarl/Resources/blob/master/QtOpenGLTutorials/Tutorial7/result.gif)

# Solution Introduction
This tutorial solution introduces a skybox and render skybox with other objects simultaneously;

# Solution Environment:
* Windows 10
* Visual Studio 2019
* Qt 5.12.3

# Solution Documentation:
> Form Files
>> [Tutorial7.ui](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial7/Tutorial7/Tutorial7.ui): Qt UI file, where QOpenGLWidget is promoted to Widget defined in Widget.h;
>
> Header Files
>> [Camera3D.h](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial7/Tutorial7/Camera3D.h): Derived from Transformational class, used to define the camera (view matrix);
>>
>>> void rotate(const QQuaternion& r): This function is used to rotate the camera;
>>> 
>>> void translate(const QVector3D& t): This function is used to translate the camera;
>>> 
>>> void scale(const float& s): This function is used to scale the camera;
>>> 
>>> void setGlobalTransform(const QMatrix4x4& g): This function is used to set the global transform for the camera;
>>> 
>>> void draw(QOpenGLShaderProgram* shaderProgram, QOpenGLFunctions* functions): This function is used to set parameters for the vertex shader, fragment shader and etc.;
>>
>> [Group3D.h](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial7/Tutorial7/Group3D.h): Derived from Transformational class, used to define a group of objects (model matrix);
>>
>>> void rotate(const QQuaternion& r): This function is used to rotate all the objects in a group, which calls Object3D::rotate(const QQuaternion&) for object rotation;
>>>
>>> void translate(const QVector3D& t): This function is used to translate all the objects in a group, which calls Object3D::translate(const QVector3D&) for object translation;
>>>
>>> void scale(const float& s): This function is used to scale all the objects in a group, which calls Object3D::scale(const float&) for object scaling;
>>>
>>> void setGlobalTransform(const QMatrix4x4& g): This function is used to set the global transform for all the objects in a group, which calls Object3D::setGlobalTransform(const QMatrix4x4&) for setting global transform;
>>>
>>> void draw(QOpenGLShaderProgram* shaderProgram, QOpenGLFunctions* functions): This function is used to draw all the objects in a group, which calls Object3D::draw(QOpenGLShaderProgram*, QOpenGLFunctions*);
>>>
>>> void addObject(Transformational* object): This function is used to add object into the group list. An initialization of its position is necessary;
>>>
>>> void delObject(Transformational* object): This function is used to delete an object by its reference;
>>>
>>> void delObject(const int& index): This function is used to delete an object by its index;
>>
>> [SimpleObject3D.h](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial7/Tutorial7/SimpleObject3D.h): Derived from Transformational class, used to define a 3D object;
>>
>>> void init(const QVector<Vertex>& vertices, const QVector<GLuint>& indices, const QImage& image): This function is used to initialize an object with its vertices reference, indices reference, and texture image reference;
>>>
>>> void rotate(const QQuaternion& r): This function is used to rotate the object;
>>> 
>>> void translate(const QVector3D& t): This function is used to translate the object;
>>> 
>>> void scale(const float& s): This function is used to scale the object;
>>>
>>> void setGlobalTransform(const QMatrix4x4& g): This function is used to set the global transform for the object;
>>>
>>> void draw(QOpenGLShaderProgram *shaderProgram, QOpenGLFunctions *functions): This function is used to set parameters for the vertex shader, fragment shader and etc. and draw the object;
>>
>> [Skybox.h](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial7/Tutorial7/Skybox.h): Derived from Transformational.h, used to define a skybox;
>>
>>> void rotate(const QQuaternion& r): This function is used to rotate the skybox, which calls Object3D::rotate(const QQuaternion&) for object rotation;
>>> 
>>> void translate(const QVector3D& t): This function is used to translate the skybox, which calls Object3D::translate(const QVector3D&) for object translation;
>>> 
>>> void scale(const float& s): This function is used to scale the skybox, which calls Object3D::scale(const float&) for object scaling;
>>> 
>>> void setGlobalTransform(const QMatrix4x4& g): This function is used to set the global transform for the skybox, which calls Object3D::setGlobalTransform(const QMatrix4x4&) for setting global transform;
>>> 
>>> void draw(QOpenGLShaderProgram* shaderProgram, QOpenGLFunctions* functions): This function is used to draw the skybox, which calls Object3D::draw(QOpenGLShaderProgram*, QOpenGLFunctions*);
>>
>> [Transformational.h](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial7/Tutorial7/Transformational.h): An abstract class used as a blueprint;
>>
>>> virtual void rotate(const QQuaternion& r) = 0;
>>>
>>> virtual void translate(const QVector3D& t) = 0;
>>>
>>> virtual void scale(const float& s) = 0;
>>>
>>> virtual void setGlobalTransform(const QMatrix4x4& g) = 0;
>>>
>>> virtual void draw(QOpenGLShaderProgram* shaderProgram, QOpenGLFunctions* functions) = 0;
>>
>> [Tutorial7.h](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial7/Tutorial7/Tutorial7.h): Qt framework;
>>
>> [Widget.h](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial7/Tutorial7/Widget.h): Derived from QOpenGLWidget, used to implement OpenGL pipeline;
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
>>> void wheelEvent(QWheelEvent* event): This function is used to process wheel events, which is a Qt event function;
>>>
>>> void timerEvent(QTimerEvent* event): This function is used to process timer events, which is a Qt event function;
>>>
>>> void keyPressEvent(QKeyEvent* event): This function is used to process key events, which is a Qt event function;
>>>
>>> void initShaders(): This function is used to initialize shaders objects;
>>> 
>>> void initCube(float width): This function is used to load graphics data for a cube, including vertex data and index data;
>>
>
> Source Files
>> [Camera3D.cpp](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial7/Tutorial7/Camera3D.cpp): implements Camera3D.h;
>>
>> [Group3D.cpp](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial7/Tutorial7/Group3D.cpp): implements Group3D.h;
>>
>> [main.cpp](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial7/Tutorial7/main.cpp);
>>
>> [SimpleObject3D.cpp](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial7/Tutorial7/SimpleObject3D.cpp): implements SimpleObject3D.h;
>>
>> [Skybox.cpp](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial7/Tutorial7/Skybox.cpp): implements Skybox.h;
>>
>> [Tutorial7.cpp](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial7/Tutorial7/Tutorial7.cpp): implements Tutorial7.h;
>>
>> [Widget.cpp](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial7/Tutorial7/Widget.cpp): implements Widget.h;
>
> Shader Files
>> [Object.fsh](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial7/Tutorial7/Object.fsh): The fragment shader implements phong shading for objects including diffuse light, ambient light, as well as specular light;
>>
>> [Object.vsh](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial7/Tutorial7/Object.vsh): The vertex shader projects object vertices;
>>
>> [Skybox.fsh](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial7/Tutorial7/Skybox.vsh): The fragment shader implements only texture color for skybox;
>> 
>> [Skybox.vsh](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial7/Tutorial7/Skybox.vsh): The vertex shader projects skybox vertices;
>

# Solution Hierarchy:
```
./Tutorial7
│   README.md
│   Tutorial7.sln
│
└───Tutorial7
    │   Camera3D.cpp
    │   Camera3D.h
    │   cube.jpg
    │   Group3D.cpp
    │   Group3D.h
    │   main.cpp
    │   Object.fsh
    │   Object.vsh
    │   README.md
    │   SimpleObject3D.cpp
    │   SimpleObject3D.h
    │   Skybox.cpp
    │   Skybox.fsh
    │   Skybox.h
    │   skybox.jpg
    │   Skybox.vsh
    │   Transformational.h
    │   Tutorial7.cpp
    │   Tutorial7.h
    │   Tutorial7.qrc
    │   Tutorial7.ui
    │   Tutorial7.vcxproj
    │   Tutorial7.vcxproj.filters
    │   Tutorial7.vcxproj.user
    │   Widget.cpp
    │   Widget.h
    │
    └───GeneratedFiles
        │   qrc_Tutorial7.cpp
        │   ui_Tutorial7.h
        │
        ├───Debug
        │       moc_Tutorial7.cpp
        │
        └───Release
                moc_Tutorial7.cpp
```