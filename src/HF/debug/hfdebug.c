#include "hfdebug.h"

void hf_glfw_error_callback(i32 error, const char* description){
    printf("[HF GLFW] GLFW error: (%i) %s\n", error, description);
}