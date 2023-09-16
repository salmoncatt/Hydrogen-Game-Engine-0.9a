#include "hfwindow.h"

void hf_window_create(hf_window* w){
    w->monitor = glfwGetPrimaryMonitor();
    w->window = glfwCreateWindow(w->w, w->h, w->title, NULL, NULL);
    
    if(!w->window){
        hf_err("[HF WINDOW] failed to create glfw window for window: [%s]\n", w->title);
        return;
    }
    
    glfwMakeContextCurrent(w->window);
    
    glfwSetWindowPos(w->window, w->x, w->y);
    
    glfwSwapInterval(w->vsync);
    glEnable(GL_DEPTH_TEST);
    
    glfwShowWindow(w->window);
    
    printf("[HF] created window: [%s], size: [%u, %u], pos: [%u, %u]\n\n", w->title, w->w, w->h, w->x, w->y);
}

hf_window hf_window_defaults(){
    hf_window w = {};
    w.x = 500;
    w.y = 300;
    w.w = 600;
    w.h = 480;
    w.title = "HGE Window";
    w.max_fps = 144;
    return w;
}

b8 hf_should_window_update(hf_window* w){
    glfwSwapBuffers(w->window);
    glfwPollEvents();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    hf_limit_fps(w->max_fps);
    hf_time_update();
    
    return !glfwWindowShouldClose(w->window);
}

void hf_window_set_title(hf_window* window, const char* title){
    glfwSetWindowTitle(window->window, title);
}

