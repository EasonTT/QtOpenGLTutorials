Tutorial 9 - Load Materials from MTL File
=============================

# Tutorial 9 Result:
![Tutorial 9](https://github.com/jingyangcarl/Resources/blob/master/QtOpenGLTutorials/Tutorial9/result.gif)

# Solution Introduction:
This tutorial solution develop functions to load .mtl files, and encapsulate object with MaterialLibrary to ObjectEngine3D;

# Solution Environment:
* Windows 10
* Visual Studio 2019
* Qt 5.12.3

# Solution Documentation:
> Form Files
>> [Tutorial9.ui](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial9/Tutorial9/Tutorial9.ui): Qt UI file, where QOpenGLWidget is promoted to Widget defined in Widget.h;
>
> Header Files
>> [Camera3D.h](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial9/Tutorial9/Camera3D.h): Derived from Transformational class, used to define the camera (view matrix);
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
>> [Group3D.h](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial9/Tutorial9/Group3D.h): Derived from Transformational class, used to define a group of objects (model matrix);
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
>> [Material.h](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial9/Tutorial9/Material.h): 
>>
>>> void setMaterialName(const QString& materialName): This function is used to set material name;
>>> 
>>> const QString& getMaterialName() const: This function is used to get material name;
>>> 
>>> void setDiffuseColor(const QVector3D& diffuseColor): 	This function is used to set diffuse color for the material;
>>> 
>>> const QVector3D& getDiffuseColor() const: This function is used to get diffuse color of the material;
>>> 
>>> void setAmbienceColor(const QVector3D& ambienceColor): This function is used to set ambient color for the material;
>>> 
>>> const QVector3D& getAmbienceColor() const: This function is used to get ambient color of the material;
>>> 
>>> void setSpecularColor(const QVector3D& specularColor): This function is used to set specular color for the material;
>>> 
>>> const QVector3D& getSpecularColor() const: This function is used to get specular color of the material;
>>> 
>>> void setShinnes(const qreal& shinnes): This function is used to set shinnes for the material;
>>> 
>>> const float getShinnes() const: This function is used to get shinnes of the material;
>>> 
>>> void setDiffuseMap(const QString& fileName): This function is used to set texture for material using an image from path;
>>> 
>>> void setDiffuseMap(const QImage& image): This function is used to set texture for material using an image;
>>> 
>>> const QImage& getDiffuseMap() const: This function is used to get diffuse map of the material;
>>> 
>>> const bool isUsingDiffuseMap() const: This function is used to get if diffuse map is used to the material;
>>
>> [MaterialLibrary.h](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial9/Tutorial9/MaterialLibrary.h): 
>>
>>> void addMaterial(Material* material): This function is used to add material to the material list;
>>> 
>>> Material* getMaterial(int index): This function is used to get material from the material list by its index;
>>> 
>>> Material* getMaterial(const QString &materialName): This function is used to get material from the material list by its name;
>>> 
>>> int getCount(): This function is used to get total amount of materials in the material library;
>>> 
>>> void loadMaterialFromFile(const QString& fileName): This function is used to load .mtl file froma given file path, the .mtl file should include material name [newmtl], ambience color [Ka], diffuse color [Kd], specular color [Ks], shinnes [Ns], diffuse map file name [map_Kd], etc.
>>
>> [ObjectEngine3D.h](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial9/Tutorial9/ObjectEngine3D.h): 
>>
>>> void loadObjectFromFile(const QString& fileName): This function is used to load .obj file from a given filepath, the .obj file should include vertex coordinations [v], texture coordinations [vt], normals [vn], vertex indices of a given face [f], material library file name [mtllib], material name [usemtl].
>>> 
>>> void addObject(SimpleObject3D* object): This function is used to append an object to the end of the object list;
>>> 
>>> SimpleObject3D* getObject(int index): This function is used to get an object from object list by its index;
>>> 
>>> void rotate(const QQuaternion& r): This function is used to rotate objects defined in the object engine, which calls Object3D::rotate(const QQuaternion&);
>>> 
>>> void translate(const QVector3D& t): This function is used to translate objects defined in the object engine, which calls Object3D::translate(const QVector3D&);
>>> 
>>> void scale(const float& s): This function is used to scale objects defined in the object engine, which calls Object3D::scale(const float&);
>>> 
>>> void setGlobalTransform(const QMatrix4x4& g): This function is used to set the global transform objects defined in the object engine, which calls Object3D::setGlobalTransform(const QMatrix4x4&);
>>> 
>>> void draw(QOpenGLShaderProgram* shaderProgram, QOpenGLFunctions* functions): This function is used to draw objects defined in the object engine, which calls Object3D::draw(QOpenGLShaderProgram*, QOpenGLFunctions*);
>>
>> [SimpleObject3D.h](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial9/Tutorial9/SimpleObject3D.h): Derived from Transformational class, used to define a 3D object;
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
>> [Skybox.h](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial9/Tutorial9/Skybox.h): Derived from Transformational.h, used to define a skybox;
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
>> [Transformational.h](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial9/Tutorial9/Transformational.h): An abstract class used as a blueprint;
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
>> [Tutorial9.h](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial9/Tutorial9/Tutorial9.h): Qt framework;
>>
>> [Widget.h](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial9/Tutorial9/Widget.h): Derived from QOpenGLWidget, used to implement OpenGL pipeline;
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
>> [Camera3D.cpp](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial9/Tutorial9/Camera3D.cpp): implements Camera3D.h;
>>
>> [Group3D.cpp](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial9/Tutorial9/Group3D.cpp): implements Group3D.h;
>>
>> [main.cpp](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial9/Tutorial9/main.cpp);
>>
>> [Material.cpp](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial9/Tutorial9/Material.cpp): implements Material.h;
>>
>> [MaterialLibrary.cpp](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial9/Tutorial9/MaterialLibrary.cpp): implements MaterialLibrary.h;
>>
>> [ObjectEngine3D.cpp](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial9/Tutorial9/ObjectEngine3D.cpp): implements ObjectEngine3D.h;
>>
>> [SimpleObject3D.cpp](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial9/Tutorial9/SimpleObject3D.cpp): implements SimpleObject3D.h;
>>
>> [Skybox.cpp](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial9/Tutorial9/Skybox.cpp): implements Skybox.h;
>>
>> [Tutorial9.cpp](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial9/Tutorial9/Tutorial9.cpp): implements Tutorial9.h;
>>
>> [Widget.cpp](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial9/Tutorial9/Widget.cpp): implements Widget.h;
>
> Shader Files
>> [Object.fsh](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial9/Tutorial9/Object.fsh): The fragment shader implements phong shading for objects including diffuse light, ambient light, as well as specular light;
>>
>> [Object.vsh](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial9/Tutorial9/Object.vsh): The vertex shader projects object vertices;
>>
>> [Skybox.fsh](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial9/Tutorial9/Skybox.vsh): The fragment shader implements only texture color for skybox;
>> 
>> [Skybox.vsh](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial9/Tutorial9/Skybox.vsh): The vertex shader projects skybox vertices;
>

# Solution Hierarchy:
./Tutorial9
│   README.md
│   Tutorial9.sln
│
└───Tutorial9
    │   Camera3D.cpp
    │   Camera3D.h
    │   cube.jpg
    │   Group3D.cpp
    │   Group3D.h
    │   main.cpp
    │   Material.cpp
    │   Material.h
    │   MaterialLibrary.cpp
    │   MaterialLibrary.h
    │   model_textured.jpg
    │   model_textured.mtl
    │   model_textured.obj
    │   Object.fsh
    │   Object.vsh
    │   ObjectEngine3D.cpp
    │   ObjectEngine3D.h
    │   README.md
    │   SimpleObject3D.cpp
    │   SimpleObject3D.h
    │   Skybox.cpp
    │   Skybox.fsh
    │   Skybox.h
    │   skybox.jpg
    │   Skybox.vsh
    │   Transformational.h
    │   Tutorial9.cpp
    │   Tutorial9.h
    │   Tutorial9.qrc
    │   Tutorial9.ui
    │   Tutorial9.vcxproj
    │   Tutorial9.vcxproj.filters
    │   Tutorial9.vcxproj.user
    │   Widget.cpp
    │   Widget.h
    │
    └───GeneratedFiles
        │   qrc_Tutorial9.cpp
        │   ui_Tutorial9.h
        │
        ├───Debug
        │       moc_Tutorial9.cpp
        │
        └───Release
                moc_Tutorial9.cpp

