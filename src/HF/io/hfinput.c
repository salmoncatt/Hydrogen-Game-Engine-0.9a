#include "hfinput.h"

b8 hf_input_keys[HF_KEY_LAST];
b8 hf_input_keys_old[HF_KEY_LAST];

b8 hf_input_buttons[HF_MOUSE_BUTTON_LAST];
b8 hf_input_buttons_old[HF_MOUSE_BUTTON_LAST];

b8 hf_input_cursor_visibility = 1;
b8 hf_input_cursor_visibility_last = 1;
u32 hf_input_updates_since_last_switch = 0;

v2f hf_input_cursor_pos = {};
v2f hf_input_cursor_pos_last = {};
v2f hf_input_cursor_movement = {};
v2f hf_input_center = {};

void hf_input_start(hf_app* app){
    glfwSetKeyCallback(app->window.window, hf_input_key_callback);
    glfwSetMouseButtonCallback(app->window.window, hf_input_mouse_button_callback);
    glfwSetCursorPosCallback(app->window.window, hf_input_mouse_position_callback);
    glfwSetScrollCallback(app->window.window, hf_input_scroll_movement_callback);
    glfwSetWindowSizeCallback(app->window.window, hf_input_window_size_callback);
    glfwSetWindowFocusCallback(app->window.window, hf_input_window_focus_callback);
    glfwSetWindowPosCallback(app->window.window, hf_input_window_position_callback);
}

void hf_input_update(hf_app* app){
    hf_memcpy(hf_input_keys_old, hf_input_keys, (sizeof(b8) * HF_KEY_LAST));
    hf_memcpy(hf_input_buttons_old, hf_input_buttons, (sizeof(b8) * HF_MOUSE_BUTTON_LAST));
    
    
    // NOTE(salmoncatt): mouse movement stuff
    hf_input_cursor_movement = hf_sub_v2f(hf_input_cursor_pos, hf_input_cursor_pos_last);
    hf_input_cursor_pos_last = hf_input_cursor_pos;
    
    
    // NOTE(salmoncatt): prevents jumping of camera
    if(hf_input_cursor_visibility != hf_input_cursor_visibility_last){
        hf_input_set_mouse_position(hf_global_app->window.w / 2, hf_global_app->window.h / 2);
        //hf_input_cursor_pos_last = hf_input_cursor_pos;
        hf_input_cursor_movement = (v2f){};
        hf_input_updates_since_last_switch = 1;
    }
    
    if(hf_input_updates_since_last_switch > 0 && hf_input_updates_since_last_switch < 4){
        hf_input_cursor_movement = (v2f){};
        hf_input_updates_since_last_switch += 1;
    }else if(hf_input_updates_since_last_switch >= 4){
        hf_input_updates_since_last_switch = 0;
    }
    
    hf_input_cursor_visibility_last = hf_input_cursor_visibility;
}




void hf_input_key_callback(GLFWwindow* w, int key, int doesntmatter, int action, int dontcare){
    if (key >= 0) {
        hf_input_keys[key] = action;
    }
}

void hf_input_mouse_button_callback(GLFWwindow* w, int button, int action, int dontcare){
    if (button >= 0) {
        hf_input_buttons[button] = action;
    }
}

void hf_input_mouse_position_callback(GLFWwindow* w, double x, double y){
    hf_input_cursor_pos = (v2f){x, y};
}

void hf_input_scroll_movement_callback(GLFWwindow* w, double x, double y){
    
}

void hf_input_window_size_callback(GLFWwindow* window, int w, int h){
    hf_global_app->window.w = w;
    hf_global_app->window.h = h;
}

void hf_input_window_focus_callback(GLFWwindow* w, int focused){
    
}

void hf_input_window_position_callback(GLFWwindow* w, int x, int y){
    
}







v2f hf_input_get_mouse_movement(){
    return hf_input_cursor_movement;
}

b8 hf_input_get_key(u32 key){
    return hf_input_keys[key];
}


b8 hf_input_get_key_down(u32 key){
    return (hf_input_keys[key] && !hf_input_keys_old[key]);
}


b8 hf_input_get_key_up(u32 key){
    return (!hf_input_keys[key] && hf_input_keys_old[key]);
}

void hf_input_set_clipboard(const char* text);

b8 hf_input_get_mouse_button(u32 button){
    return hf_input_buttons[button];
}

b8 hf_input_get_mouse_button_down(u32 button){
    return (hf_input_buttons[button] && !hf_input_buttons_old[button]);
}

b8 hf_input_get_mouse_button_up(u32 button){
    return (!hf_input_buttons[button] && hf_input_buttons_old[button]);
}


void hf_input_show_cursor(b8 visibility){
    glfwSetInputMode(hf_global_app->window.window, GLFW_CURSOR, visibility ? GLFW_CURSOR_NORMAL : GLFW_CURSOR_DISABLED);
    hf_input_cursor_visibility = visibility;
}

void hf_input_toggle_cursor(){
    hf_input_show_cursor(!hf_input_cursor_visibility);
}

b8 hf_input_get_cursor_visibility(){
    return hf_input_cursor_visibility;
}

void hf_input_destroy(){
    //hf_log("[HF Input] destroying...\n");
    //hf_vector_free(&hf_input_keys);
    //hf_log("[HF Input] destroyed\n");
}

void hf_input_set_mouse_position(u32 x, u32 y){
    glfwSetCursorPos(hf_global_app->window.window, x, y);
    hf_input_cursor_pos = (v2f){x, y};
}