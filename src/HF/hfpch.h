/* date = August 26th 2021 6:47 pm */

//HF's precompiled header file

#ifndef HFPCH_H
#define HFPCH_H

// NOTE(salmoncatt): this gets removed or left depending on how you compile in the makefile
#define HF_DEBUG
#define hf_malloc malloc
#define hf_free free
#define hf_memcpy memcpy
#define hf_err printf
#define hf_log printf
#define hf_strlen strlen




#include "datatypes/hfdatatypes.h"
#include "datatypes/hfarray.h"



#include <GL/gl.h>

#include <GLFW/glfw3.h>


#ifdef _WIN32
#include <windows.h>
//for cpuid
#include <intrin.h>


#elif defined(__linux__)
#include<X11/X.h>
#include<X11/Xlib.h>
#include<GL/glx.h>
#include<GL/glu.h>
//#include <time.h>
#include <sys/time.h>
//for scancodes
#include <X11/XKBlib.h>
//for XDeviceMotionEvent
#include <X11/extensions/XInput.h>
#include <unistd.h>

#endif

#include "datatypes/hfarray.h"
#include "datatypes/hffloatbuffer.h"
#include "datatypes/hfstring.h"

#include "graphics/stb_image.h"
#include "util/hfutil.h"

#include "opengl/hfgl.h"

#include "math/hfmath.h"


#include "ft2build.h"
#include "freetype/freetype.h"

#endif //HFPCH_H
