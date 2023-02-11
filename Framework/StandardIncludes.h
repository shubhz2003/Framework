//Header Guard(Guards your header so it can be only included once in your code)
#ifndef STANDARD_INCLUDES_H
#define STANDAR_INCLUDES_H

#define SDL_MAIN_HANDLED

//Contains most things that are needed in almost all files
// Include standard headers
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cinttypes>
#include <stdio.h>
#include <thread>
#include <map>
#include <SDL.h>

//Project Headers
#include "Singleton.h"

//OS specific includes and defines
//Pre-Compiler Directive- Checks and complies for whichever environment its on
#ifdef _WIN32
#include <Windows.h>
#include <direct.h>
//Macro is like a function but we define it in a header file
//So a macro is basically a Global Function
//\ indicates a multi line macro definition

#define M_ASSERT(_cond, _msg) \
	if (!(_cond)) { OutputDebugStringA(_msg); std::abort(); }
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

using namespace std;

#endif // STANDARD_INCLUDES_H


