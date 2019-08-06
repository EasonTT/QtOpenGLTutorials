QtOpenGLTutorials
=================

## Project Introduction:
This project is a Qt tutorial on using OpenGL, which is based on a [Youtube Tutorial](https://www.youtube.com/watch?v=HgoKrrf4iks&list=PL-hrQhpTB95LKMbttX47vCsNeGbJQVz1-) (A Russion tutorial without English subtitles). The tutorial starts with a Qt template on a simple OpenGL application, and then dig into it. Finally, the graphics components includes camera, object engines, object groups, etc.

## Project Environment:
* Windows 10
* Visual Studio 2019
* Qt 5.12.3

## Project Overview:
> [Tutorial 1: Project Template](https://github.com/jingyangcarl/QtOpenGLTutorials/tree/master/Code/Tutorial1/Tutorial1)
>
>> ![Tutorial Result](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial1/Tutorial1/result.jpg)
>>
>> [Youtube Link](https://www.youtube.com/watch?v=HgoKrrf4iks)
>>
>> [Source Code](https://github.com/jingyangcarl/QtOpenGLTutorials/tree/master/Code/Tutorial1/Tutorial1)
>
> [Tutorial 2: Shader Lighting](https://github.com/jingyangcarl/QtOpenGLTutorials/tree/master/Code/Tutorial2/Tutorial2)
>
>> ![Tutorial Result](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial2/Tutorial2/result.jpg)
>>
>> [Youtube Link](https://www.youtube.com/watch?v=Ww-aoNC8VQU)
>>
>> [Source Code](https://github.com/jingyangcarl/QtOpenGLTutorials/tree/master/Code/Tutorial2/Tutorial2)
>
> [Tutorial 3 - Object Groupings](https://github.com/jingyangcarl/QtOpenGLTutorials/tree/master/Code/Tutorial3/Tutorial3)
>
>> ![Tutorial Result](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial3/Tutorial3/result.jpg)
>>
>> [Youtube Link](https://www.youtube.com/watch?v=OyPlRxBRJqs)
>>
>> [Source Code](https://github.com/jingyangcarl/QtOpenGLTutorials/tree/master/Code/Tutorial3/Tutorial3)
>
> [Tutorial 4 - Work with A Camera](https://github.com/jingyangcarl/QtOpenGLTutorials/tree/master/Code/Tutorial4/Tutorial4)
>
>> ![Tutorial Result](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial4/Tutorial4/result.jpg)
>>
>> [Youtube Link](https://www.youtube.com/watch?v=Un6pCMT5HDE)
>>
>> [Source Code](https://github.com/jingyangcarl/QtOpenGLTutorials/tree/master/Code/Tutorial4/Tutorial4)
>
> [Tutorial 5 - SkyBox Surroundings](https://github.com/jingyangcarl/QtOpenGLTutorials/tree/master/Code/Tutorial5/Tutorial5)
>
>> ![Tutorial Result](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial5/Tutorial5/result.gif)
>>
>> [Youtube Link](https://www.youtube.com/watch?v=-adEM8bTaeo)
>>
>> [Source Code](https://github.com/jingyangcarl/QtOpenGLTutorials/tree/master/Code/Tutorial5/Tutorial5)
>
> [Tutorial 6 - Load An Obj File](https://github.com/jingyangcarl/QtOpenGLTutorials/tree/master/Code/Tutorial6/Tutorial6)
>
>> ![Tutorial Result](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial6/Tutorial6/result.gif)
>>
>> [Youtube Link](https://www.youtube.com/watch?v=yM9v9vnNoIE)
>>
>> [Source Code](https://github.com/jingyangcarl/QtOpenGLTutorials/tree/master/Code/Tutorial6/Tutorial6)
>
> [Tutorial 7 - Load Materials from MTL File (1/3)](https://github.com/jingyangcarl/QtOpenGLTutorials/tree/master/Code/Tutorial7/Tutorial7)
>
>> ![Tutorial Result](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial7/Tutorial7/result.gif)
>>
>> [Youtube Link](https://www.youtube.com/watch?v=AEK_-4rtF1o)
>>
>> [Source Code](https://github.com/jingyangcarl/QtOpenGLTutorials/tree/master/Code/Tutorial7/Tutorial7)
>
> [Tutorial 8 - Load Materials from MTL File (2/3)](https://github.com/jingyangcarl/QtOpenGLTutorials/tree/master/Code/Tutorial8/Tutorial8)
>
>> ![Tutorial Result](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial8/Tutorial8/result.gif)
>>
>> [Youtube Link](https://www.youtube.com/watch?v=71HR8glNudc)
>>
>> [Source Code](https://github.com/jingyangcarl/QtOpenGLTutorials/tree/master/Code/Tutorial8/Tutorial8)
>
> [Tutorial 9 - Load Materials from MTL File (3/3)](https://github.com/jingyangcarl/QtOpenGLTutorials/tree/master/Code/Tutorial9/Tutorial9)
>
>> ![Tutorial Result](https://github.com/jingyangcarl/QtOpenGLTutorials/blob/master/Code/Tutorial9/Tutorial9/result.gif)
>>
>> [Youtube Link](https://www.youtube.com/watch?v=TadCATIDZ2c)
>>
>> [Source Code](https://github.com/jingyangcarl/QtOpenGLTutorials/tree/master/Code/Tutorial9/Tutorial9)
>

## Project Structure:
QtOpenGLTutorials:.  
|   .gitattributes  
|   .gitignore  
|   README.md  
|  
+---Code  
|   +---Tutorial1  
|   |   |   README.md  
|   |   |   Tutorial1.sln  
|   |   |  
|   |   \---Tutorial1  
|   |       |   cube.jpg  
|   |       |   FragmentShader.fsh  
|   |       |   main.cpp  
|   |       |   README.md  
|   |       |   result.jpg  
|   |       |   Tutorial1.cpp  
|   |       |   Tutorial1.h  
|   |       |   Tutorial1.qrc  
|   |       |   Tutorial1.ui  
|   |       |   Tutorial1.vcxproj  
|   |       |   Tutorial1.vcxproj.filters  
|   |       |   VertexShader.hlsl  
|   |       |   VertexShader.vsh  
|   |       |   Widget.cpp  
|   |       |   Widget.h  
|   |       |  
|   |       \---GeneratedFiles  
|   |               qrc_Tutorial1.cpp  
|   |               ui_Tutorial1.h  
|   |  
|   +---Tutorial2  
|   |   |   README.md  
|   |   |   Tutorial2.sln  
|   |   |  
|   |   \---Tutorial2  
|   |       |   cube.jpg  
|   |       |   FragmentShader.fsh  
|   |       |   main.cpp  
|   |       |   README.md  
|   |       |   result.jpg  
|   |       |   Tutorial2.cpp  
|   |       |   Tutorial2.h  
|   |       |   Tutorial2.qrc  
|   |       |   Tutorial2.ui  
|   |       |   Tutorial2.vcxproj  
|   |       |   Tutorial2.vcxproj.filters  
|   |       |   VertexShader.vsh  
|   |       |   Widget.cpp  
|   |       |   Widget.h  
|   |       |  
|   |       \---GeneratedFiles  
|   |               qrc_Tutorial2.cpp  
|   |               ui_Tutorial2.h  
|   |  
|   +---Tutorial3  
|   |   |   README.md  
|   |   |   Tutorial3.sln  
|   |   |  
|   |   \---Tutorial3  
|   |       |   cube.jpg  
|   |       |   FragmentShader.fsh  
|   |       |   main.cpp  
|   |       |   README.md  
|   |       |   result.jpg  
|   |       |   SimpleObject3D.cpp  
|   |       |   SimpleObject3D.h  
|   |       |   Tutorial3.cpp  
|   |       |   Tutorial3.h  
|   |       |   Tutorial3.qrc  
|   |       |   Tutorial3.ui  
|   |       |   Tutorial3.vcxproj  
|   |       |   Tutorial3.vcxproj.filters  
|   |       |   VertexShader.vsh  
|   |       |   Widget.cpp  
|   |       |   Widget.h  
|   |       |  
|   |       \---GeneratedFiles  
|   |               qrc_Tutorial3.cpp  
|   |               ui_Tutorial3.h  
|   |  
|   +---Tutorial4  
|   |   |   README.md  
|   |   |   Tutorial4.sln  
|   |   |  
|   |   \---Tutorial4  
|   |       |   cube.jpg  
|   |       |   FragmentShader.fsh  
|   |       |   Group3D.cpp  
|   |       |   Group3D.h  
|   |       |   main.cpp  
|   |       |   README.md  
|   |       |   result.jpg  
|   |       |   SimpleObject3D.cpp  
|   |       |   SimpleObject3D.h  
|   |       |   Transformational.h  
|   |       |   Tutorial4.cpp  
|   |       |   Tutorial4.h  
|   |       |   Tutorial4.qrc  
|   |       |   Tutorial4.ui  
|   |       |   Tutorial4.vcxproj  
|   |       |   Tutorial4.vcxproj.filters  
|   |       |   VertexShader.vsh  
|   |       |   Widget.cpp  
|   |       |   Widget.h  
|   |       |  
|   |       \---GeneratedFiles  
|   |               qrc_Tutorial4.cpp  
|   |               ui_Tutorial4.h  
|   |  
|   +---Tutorial5  
|   |   |   README.md  
|   |   |   Tutorial5.sln  
|   |   |  
|   |   \---Tutorial5  
|   |       |   cube.jpg  
|   |       |   FragmentShader.fsh  
|   |       |   Group3D.cpp  
|   |       |   Group3D.h  
|   |       |   main.cpp  
|   |       |   README.md  
|   |       |   result.gif  
|   |       |   SimpleObject3D.cpp  
|   |       |   SimpleObject3D.h  
|   |       |   Transformational.h  
|   |       |   Tutorial5.cpp  
|   |       |   Tutorial5.h  
|   |       |   Tutorial5.qrc  
|   |       |   Tutorial5.ui  
|   |       |   Tutorial5.vcxproj  
|   |       |   Tutorial5.vcxproj.filters  
|   |       |   VertexShader.vsh  
|   |       |   Widget.cpp  
|   |       |   Widget.h  
|   |       |  
|   |       \---GeneratedFiles  
|   |               qrc_Tutorial5.cpp  
|   |               ui_Tutorial5.h  
|   |  
|   +---Tutorial6  
|   |   |   README.md  
|   |   |   Tutorial6.sln  
|   |   |  
|   |   \---Tutorial6  
|   |       |   Camera3D.cpp  
|   |       |   Camera3D.h  
|   |       |   cube.jpg  
|   |       |   FragmentShader.fsh  
|   |       |   Group3D.cpp  
|   |       |   Group3D.h  
|   |       |   main.cpp  
|   |       |   README.md  
|   |       |   result.gif  
|   |       |   SimpleObject3D.cpp  
|   |       |   SimpleObject3D.h  
|   |       |   Transformational.h  
|   |       |   Tutorial6.cpp  
|   |       |   Tutorial6.h  
|   |       |   Tutorial6.qrc  
|   |       |   Tutorial6.ui  
|   |       |   Tutorial6.vcxproj  
|   |       |   Tutorial6.vcxproj.filters  
|   |       |   VertexShader.vsh  
|   |       |   Widget.cpp  
|   |       |   Widget.h  
|   |       |  
|   |       \---GeneratedFiles  
|   |               qrc_Tutorial6.cpp  
|   |               ui_Tutorial6.h  
|   |  
|   +---Tutorial7  
|   |   |   README.md  
|   |   |   Tutorial7.sln  
|   |   |  
|   |   \---Tutorial7  
|   |       |   Camera3D.cpp  
|   |       |   Camera3D.h  
|   |       |   cube.jpg  
|   |       |   Group3D.cpp  
|   |       |   Group3D.h  
|   |       |   main.cpp  
|   |       |   Object.fsh  
|   |       |   Object.vsh  
|   |       |   README.md  
|   |       |   result.gif  
|   |       |   SimpleObject3D.cpp  
|   |       |   SimpleObject3D.h  
|   |       |   Skybox.cpp  
|   |       |   Skybox.fsh  
|   |       |   Skybox.h  
|   |       |   skybox.jpg  
|   |       |   Skybox.vsh  
|   |       |   Transformational.h  
|   |       |   Tutorial7.cpp  
|   |       |   Tutorial7.h  
|   |       |   Tutorial7.qrc  
|   |       |   Tutorial7.ui  
|   |       |   Tutorial7.vcxproj  
|   |       |   Tutorial7.vcxproj.filters  
|   |       |   Widget.cpp  
|   |       |   Widget.h  
|   |       |  
|   |       \---GeneratedFiles  
|   |               qrc_Tutorial7.cpp  
|   |               ui_Tutorial7.h  
|   |  
|   +---Tutorial8  
|   |   |   README.md  
|   |   |   Tutorial8.sln  
|   |   |  
|   |   \---Tutorial8  
|   |       |   Camera3D.cpp  
|   |       |   Camera3D.h  
|   |       |   cube.jpg  
|   |       |   Group3D.cpp  
|   |       |   Group3D.h  
|   |       |   main.cpp  
|   |       |   Object.fsh  
|   |       |   Object.vsh  
|   |       |   README.md  
|   |       |   result.gif  
|   |       |   SimpleObject3D.cpp  
|   |       |   SimpleObject3D.h  
|   |       |   Skybox.cpp  
|   |       |   Skybox.fsh  
|   |       |   Skybox.h  
|   |       |   skybox.jpg  
|   |       |   Skybox.vsh  
|   |       |   sphere.obj  
|   |       |   Transformational.h  
|   |       |   Tutorial8.cpp  
|   |       |   Tutorial8.h  
|   |       |   Tutorial8.qrc  
|   |       |   Tutorial8.ui  
|   |       |   Tutorial8.vcxproj  
|   |       |   Tutorial8.vcxproj.filters  
|   |       |   Widget.cpp  
|   |       |   Widget.h  
|   |       |  
|   |       \---GeneratedFiles  
|   |               qrc_Tutorial8.cpp  
|   |               ui_Tutorial8.h  
|   |  
|   \---Tutorial9  
|       |   README.md  
|       |   Tutorial9.sln  
|       |  
|       \---Tutorial9  
|           |   Camera3D.cpp  
|           |   Camera3D.h  
|           |   cube.jpg  
|           |   Group3D.cpp  
|           |   Group3D.h  
|           |   main.cpp  
|           |   Material.cpp  
|           |   Material.h  
|           |   MaterialLibrary.cpp  
|           |   MaterialLibrary.h  
|           |   model_textured.jpg  
|           |   model_textured.mtl  
|           |   model_textured.obj  
|           |   Object.fsh  
|           |   Object.vsh  
|           |   ObjectEngine3D.cpp  
|           |   ObjectEngine3D.h  
|           |   README.md  
|           |   result.gif  
|           |   SimpleObject3D.cpp  
|           |   SimpleObject3D.h  
|           |   Skybox.cpp  
|           |   Skybox.fsh  
|           |   Skybox.h  
|           |   skybox.jpg  
|           |   Skybox.vsh  
|           |   Transformational.h  
|           |   Tutorial9.cpp  
|           |   Tutorial9.h  
|           |   Tutorial9.qrc  
|           |   Tutorial9.ui  
|           |   Tutorial9.vcxproj  
|           |   Tutorial9.vcxproj.filters  
|           |   Widget.cpp  
|           |   Widget.h  
|           |  
|           \---GeneratedFiles  
|                   qrc_Tutorial9.cpp  
|                   ui_Tutorial9.h  
|  
\---data  
        cube.mtl  
        cube.obj  
        cube1.jpg  
        cube2.jpg  
        pyramid.obj  
        skybox1.jpg  
        skybox2.jpg  
        skybox3.jpg  
        skybox4.jpg  
        sphere.mtl  
        sphere.obj  
        