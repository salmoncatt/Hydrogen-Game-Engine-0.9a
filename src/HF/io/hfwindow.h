/* date = September 2nd 2023 9:21 am */

#ifndef HFWINDOW_H
#define HFWINDOW_H

typedef struct hf_window{
    
    u32 w, h, x, y;
    const char* title;
    b8 vsync;
    
    GLFWwindow* window;
    GLFWmonitor* monitor;
    
    
}hf_window;

void hf_window_create(hf_window* window);


#endif //HFWINDOW_H
