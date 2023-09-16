/* date = September 2nd 2023 9:21 am */

#ifndef HFWINDOW_H
#define HFWINDOW_H

typedef struct hf_window{
    
    u32 w, h, x, y, max_fps;
    const char* title;
    b8 vsync;
    
    
    
    GLFWwindow* window;
    GLFWmonitor* monitor;
    
    
}hf_window;

void hf_window_create(hf_window* window);

hf_window hf_window_defaults();

b8 hf_should_window_update(hf_window* window);

void hf_window_destroy(hf_window* window);

void hf_window_set_title(hf_window* window, const char* title);

#endif //HFWINDOW_H
