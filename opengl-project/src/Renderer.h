#pragma once

#include <GL/glew.h>

#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x,__FILE__,__LINE__))

void GLClearError();

/// <summary>
/// Logs any OpenGL errors for a given function call. Use with Macro GLLogCall.
/// </summary>
/// <param name="function"></param>
/// <param name="file"></param>
/// <param name="line"></param>
/// <returns></returns>
bool GLLogCall(const char* function, const char* file, int line);