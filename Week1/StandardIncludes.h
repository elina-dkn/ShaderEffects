#ifndef STANDARD_INCLUDES_H
#define STANDARD_INCLUDES_H
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <iostream>

#define GLM_ENABLE_EXPERIMENTAL

#ifdef _WIN32
#include <Windows.h>
#define M_ASSERT(_cond, _msg) \
    if (!(_cond)) { OutputDebugStringA(_msg); std::abort(); glfwTerminate();}
#endif

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <OBJ_Loader.h>

#include <ft2build.h>
#include FT_FREETYPE_H

#include "Resolution.h"
#include "Singleton.h"

using namespace std;

#endif
