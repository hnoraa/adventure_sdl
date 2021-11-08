# Installation
(tips & tricks)

## SDL links
SDL - https://www.libsdl.org
SDL Image - https://www.libsdl.org/projects/SDL_image/

## SDL Source
For Windows, download the ```*-VC.zip``` archives

## Visual Studio Setup
### Initial
1. Create an empty C++ project.
2. Create a new empty c++ file called main.cpp
3. Make sure the Debug/Release Configurations are set to x64 if using SDL x64

### Properties
Ref: https://www.youtube.com/watch?v=QQzAHcojEKg&list=PLhfAbcv9cehhkG7ZQK0nfIGJC_C-wSLrx

From the project properties (right-click, select Properties).
1. Select C/C++>General
	1. In Additional Include Directories add <SDL install location>\include
2. Select Linker>General
	1. In Additional Library Directories add <SDL install location>\lib\<x86|x64>
3. Select Linker>Input
	1. In Additional Dependencies add SDL2.lin and SDL2main.lib
4. Select Linker>System
	1. Set SubSystem to Console (/SUBSYSTEM:CONSOLE)
5. Click Apply and OK
6. Copy SDL2.dll file to the project folder (from <SDL install location>\lib). The project directory is the where main.cpp is