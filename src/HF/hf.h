/* date = August 16th 2021 0:49 pm */

#ifndef HF_H
#define HF_H

#define HF_RES "../res/"

#define HF_SUCCESS 1
#define HF_FAIL 0

// TODO(salmoncatt): add linux headers n stuff pls

#include "core/hfapp.h"

//#include "ecs/hfecs.h"
//#include "ecs/hfcomponents.h"

#include "datatypes/hfdatatypes.h"
#include "datatypes/hfarray.h"
#include "datatypes/hffloatbuffer.h"
#include "datatypes/hfstring.h"

#include "util/hfutil.h"
#include "opengl/hfgl.h"

#include "math/hfmath.h"
#include "debug/hfdebug.h"


#include "io/hfwindow.h"
#include "io/hfinput.h"


/* 
#ifdef _WIN32
#include "io/hfwindow_win.h"
#elif __unix__
#include "io/hfwindow_linux.h"
#endif
 */

/* 
#include "io/hfinput.h"
#include "io/hfserial.h" //for arduino n stuff
#include "io/hf3dprint.h"
 */


/* 
#include "ai/machine_learning.h"
//#endif

#include "time/hfprofiler.h"
 */
#include "time/hftime.h"

#include "graphics/stb_image.h"
#include "graphics/hfimage.h"
#include "graphics/hftexture.h"

#include "mesh/hfmesh.h"

#include "rendering/hfrenderer.h"
#include "rendering/hfshader.h"
/* 
#include "rendering/hfrenderer2d.h"

#include "gui/hfgui.h"
#include "gui/hfguipanel.h"

#include "text/hffreetype.h"
#include "text/hf_font.h"
 */

#include "camera/hfcamera.h"
#include "camera/hfcameracontroller.h"

#endif //HF_H
