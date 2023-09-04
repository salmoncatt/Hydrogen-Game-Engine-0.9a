#include "hfwindow.h"

void hf_window_create(hf_window* w){
    w->monitor = glfwGetPrimaryMonitor();
    w->window = glfwCreateWindow(w->w, w->h, w->title, NULL, NULL);
    
    if(!w->window){
        hf_err("[HF WINDOW] failed to create glfw window for window: [%s]", w->title);
    }
    
    glfwMakeContextCurrent(w->window);
    
    
    glfwSwapInterval(w->vsync);
    glEnable(GL_DEPTH_TEST);
    
    glfwShowWindow(w->window);
    
    printf("[HF] created window: [%s], size: [%u, %u], pos: [%u, %u]\n\n", w->title, w->w, w->h, w->x, w->y);
}