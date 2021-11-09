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
1. Select VC++ Directories
	1. In Include Directories add <SDL install location>\include
	2. In Library Directories add <SDL install location>\lib\<x86|x64>
2. Select C/C++>General
	1. In Additional Include Directories add <SDL install location>\include
3. Select Linker>General
	1. In Additional Library Directories add <SDL install location>\lib\<x86|x64>
4. Select Linker>Input
	1. In Additional Dependencies add SDL2.lib and SDL2main.lib
5. Select Linker>System
	1. Set SubSystem to Console (/SUBSYSTEM:CONSOLE)
6. Click Apply and OK
7. Copy SDL2.dll file to the project folder (from <SDL install location>\lib). The project directory is the where main.cpp is

### SDL Image (or any other SDL subsystem: ie. mixer, just replace the word image with whatever)
1. Copy zlib1.dll, SDL2_image.dll and any lib<imageType>.dll libraries needed from <SDL image install location>\lib into the project directory
2. From the project properties (right-click, select Properties).
	1. Select VC++ Directories
		1. In Include Directories add <SDL image install location>\include
		2. In Library Directories add <SDL image install location>\lib\<x86|x64>
	2. Select C/C++>General
		1. In Additional Include Directories add <SDL image install location>\include
	3. Select Linker>General
		1. In Additional Library Directories add <SDL install location>\lib\<x86|x64>
	4. Select Linker>Input
		1. In Additional Dependencies add SDL2_image.lib
	5. Click Apply and OK

## Linux Setup
To install SDL run: ```sudo apt-get install libsdl2-dev libsdl2-image-dev``` (add any additional libraries, need the -dev installs)