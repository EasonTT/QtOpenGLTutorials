Tutorial 4 - Object Groupings (2/2)
=============================

# Tutorial 4 Result
![Tutorial 4](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial4/Tutorial4/result.jpg)

# Solution Introduction
This tutorial solution introduces how to add other objects and translate it to a given position;

# Solution Environment:
* Windows 10
* Visual Studio 2019
* Qt 5.12.3

# Solution Hierarchy:
> Form Files
>> [Tutorial4.ui](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial4/Tutorial4/Tutorial4.ui): Qt UI file, where QOpenGLWidget is promoted to Widget defined in Widget.h;
>
> Header Files
>> [Group3D.h](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial4/Tutorial4/Group3D.h): Derived from Transformational.h, used to define a group of objects;
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
>>
>> [SimpleObject3D.h](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial4/Tutorial4/SimpleObject3D.h): Used to define a 3D object;
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
>> [Transformational.h](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial4/Tutorial4/Transformational.h): An abstract class used as a blueprint;
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
>> [Tutorial4.h](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial4/Tutorial4/Tutorial4.h): Qt framework;
>>
>> [Widget.h](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial4/Tutorial4/Widget.h): Derived from QOpenGLWidget, used to implement OpenGL pipeline;
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
>>> void Widget::wheelEvent(QWheelEvent* event): This function is used to process wheel events, which is a Qt event function;
>>>
>>> void initShaders(): This function is used to initialize shaders objects;
>>> 
>>> void initCube(float width): This function is used to load graphics data for a cube, including vertex data and index data;
>>
>
> Source Files
>> [main.cpp](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial4/Tutorial4/main.cpp)
>>
>> [Group3D.cpp](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial4/Tutorial4/Group3D.cpp): implement Group3D.h;
>>
>> [SimpleObject3D.cpp](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial4/Tutorial4/SimpleObject3D.cpp): implement SimpleObject3D.h;
>>
>> [Tutorial4.cpp](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial4/Tutorial4/Tutorial4.cpp): implement Tutorial4.h;
>>
>> [Widget.cpp](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial4/Tutorial4/Widget.cpp): implement Widget.h;
>
> Shader Files
>> [FragmentShader.fsh](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial4/Tutorial4/FragmentShader.fsh): The fragment shader implements phong shading including diffuse light, ambient light, as well as specular light;
>>
>> [VertexShader.vsh](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial4/Tutorial4/VertexShader.vsh): The vertex shader projects vertices;
>
