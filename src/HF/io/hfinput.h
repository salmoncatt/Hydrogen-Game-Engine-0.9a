/* date = August 23rd 2021 8:08 pm */

#ifndef INPUT_H
#define INPUT_H


#include "../core/hfapp.h"
#include "../math/hfmath.h"
//#include "../datatypes/hfvector.h"


#define HF_MOUSE_BUTTON_0 0
#define HF_MOUSE_BUTTON_1 1
#define HF_MOUSE_BUTTON_2 2
#define HF_MOUSE_BUTTON_3 3
#define HF_MOUSE_BUTTON_4 4
#define HF_MOUSE_BUTTON_5 5
#define HF_MOUSE_BUTTON_6 6
#define HF_MOUSE_BUTTON_7 7
#define HF_MOUSE_BUTTON_LAST 10

#define HF_MOUSE_BUTTON_LEFT HF_MOUSE_BUTTON_0
#define HF_MOUSE_BUTTON_RIGHT HF_MOUSE_BUTTON_1
#define HF_MOUSE_BUTTON_MIDDLE HF_MOUSE_BUTTON_2



#define 	HF_KEY_UNKNOWN   -1
#define 	HF_KEY_SPACE   32
#define 	HF_KEY_APOSTROPHE   39 /* ' */
#define 	HF_KEY_COMMA   44 /* , */
#define 	HF_KEY_MINUS   45 /* - */
#define 	HF_KEY_PERIOD   46 /* . */
#define 	HF_KEY_SLASH   47 /* / */

#define 	HF_KEY_0   48
#define 	HF_KEY_1   49
#define 	HF_KEY_2   50
#define 	HF_KEY_3   51
#define 	HF_KEY_4   52
#define 	HF_KEY_5   53
#define 	HF_KEY_6   54
#define 	HF_KEY_7   55
#define 	HF_KEY_8   56
#define 	HF_KEY_9   57
#define 	HF_KEY_SEMICOLON   59 /* ; */
#define 	HF_KEY_EQUAL   61 /* = */

#define 	HF_KEY_A   65
#define 	HF_KEY_B   66
#define 	HF_KEY_C   67
#define 	HF_KEY_D   68
#define 	HF_KEY_E   69
#define 	HF_KEY_F   70
#define 	HF_KEY_G   71
#define 	HF_KEY_H   72
#define 	HF_KEY_I   73
#define 	HF_KEY_J   74
#define 	HF_KEY_K   75
#define 	HF_KEY_L   76
#define 	HF_KEY_M   77
#define 	HF_KEY_N   78
#define 	HF_KEY_O   79
#define 	HF_KEY_P   80
#define 	HF_KEY_Q   81
#define 	HF_KEY_R   82
#define 	HF_KEY_S   83
#define 	HF_KEY_T   84
#define 	HF_KEY_U   85
#define 	HF_KEY_V   86
#define 	HF_KEY_W   87
#define 	HF_KEY_X   88
#define 	HF_KEY_Y   89
#define 	HF_KEY_Z   90

#define 	HF_KEY_LEFT_BRACKET   91 /* [ */
#define 	HF_KEY_BACKSLASH   92 /* \ */
#define 	HF_KEY_RIGHT_BRACKET   93 /* ] */
#define 	HF_KEY_GRAVE_ACCENT   96 /* ` */
#define 	HF_KEY_WORLD_1   161 /* non-US #1 */
#define 	HF_KEY_WORLD_2   162 /* non-US #2 */
#define 	HF_KEY_ESCAPE   256
#define 	HF_KEY_ENTER   257
#define 	HF_KEY_TAB   258
#define 	HF_KEY_BACKSPACE   259
#define 	HF_KEY_INSERT   260
#define 	HF_KEY_DELETE   261
#define 	HF_KEY_RIGHT   262
#define 	HF_KEY_LEFT   263
#define 	HF_KEY_DOWN   264
#define 	HF_KEY_UP   265
#define 	HF_KEY_PAGE_UP   266
#define 	HF_KEY_PAGE_DOWN   267
#define 	HF_KEY_HOME   268
#define 	HF_KEY_END   269
#define 	HF_KEY_CAPS_LOCK   280
#define 	HF_KEY_SCROLL_LOCK   281
#define 	HF_KEY_NUM_LOCK   282
#define 	HF_KEY_PRINT_SCREEN   283
#define 	HF_KEY_PAUSE   284

#define 	HF_KEY_F1   290
#define 	HF_KEY_F2   291
#define 	HF_KEY_F3   292
#define 	HF_KEY_F4   293
#define 	HF_KEY_F5   294
#define 	HF_KEY_F6   295
#define 	HF_KEY_F7   296
#define 	HF_KEY_F8   297
#define 	HF_KEY_F9   298
#define 	HF_KEY_F10   299
#define 	HF_KEY_F11   300
#define 	HF_KEY_F12   301
#define 	HF_KEY_F13   302
#define 	HF_KEY_F14   303
#define 	HF_KEY_F15   304
#define 	HF_KEY_F16   305
#define 	HF_KEY_F17   306
#define 	HF_KEY_F18   307
#define 	HF_KEY_F19   308
#define 	HF_KEY_F20   309
#define 	HF_KEY_F21   310
#define 	HF_KEY_F22   311
#define 	HF_KEY_F23   312
#define 	HF_KEY_F24   313
#define 	HF_KEY_F25   314
#define 	HF_KEY_KP_0   320
#define 	HF_KEY_KP_1   321
#define 	HF_KEY_KP_2   322
#define 	HF_KEY_KP_3   323
#define 	HF_KEY_KP_4   324
#define 	HF_KEY_KP_5   325
#define 	HF_KEY_KP_6   326
#define 	HF_KEY_KP_7   327
#define 	HF_KEY_KP_8   328
#define 	HF_KEY_KP_9   329
#define 	HF_KEY_KP_DECIMAL   330
#define 	HF_KEY_KP_DIVIDE   331
#define 	HF_KEY_KP_MULTIPLY   332
#define 	HF_KEY_KP_SUBTRACT   333
#define 	HF_KEY_KP_ADD   334
#define 	HF_KEY_KP_ENTER   335
#define 	HF_KEY_KP_EQUAL   336

#define 	HF_KEY_LEFT_SHIFT   340
#define 	HF_KEY_LEFT_CONTROL   341
#define 	HF_KEY_LEFT_ALT   342
#define 	HF_KEY_LEFT_SUPER   343
#define 	HF_KEY_RIGHT_SHIFT   344
#define 	HF_KEY_RIGHT_CONTROL   345
#define 	HF_KEY_RIGHT_ALT   346
#define 	HF_KEY_RIGHT_SUPER   347
#define 	HF_KEY_MENU   348
#define 	HF_KEY_LAST   HF_KEY_MENU



extern b8 hf_input_keys[HF_KEY_LAST];
extern b8 hf_input_keys_old[HF_KEY_LAST];

extern b8 hf_input_buttons[HF_MOUSE_BUTTON_LAST];
extern b8 hf_input_buttons_old[HF_MOUSE_BUTTON_LAST];

extern b8 hf_input_cursor_visibility;
extern b8 hf_input_cursor_visibility_last;
extern u32 hf_input_updates_since_last_switch;

extern v2f hf_input_cursor_pos;
extern v2f hf_input_cursor_pos_last;
extern v2f hf_input_cursor_movement;
extern v2f hf_input_center;


void hf_input_start(hf_app* app);
void hf_input_update(hf_app* app);

void hf_input_key_callback(GLFWwindow* w, int key, int, int action, int);
void hf_input_mouse_button_callback(GLFWwindow* w, int button, int action, int);
void hf_input_mouse_position_callback(GLFWwindow* w, double x, double y);
void hf_input_scroll_movement_callback(GLFWwindow* w, double x, double y);
void hf_input_window_size_callback(GLFWwindow* w, int width, int height);
void hf_input_window_focus_callback(GLFWwindow* w, int focused);
void hf_input_window_position_callback(GLFWwindow* w, int x, int y);




b8 hf_input_get_key(u32 key);
b8 hf_input_get_key_down(u32 key);
b8 hf_input_get_key_up(u32 key);

void hf_input_set_clipboard(const char* text);

b8 hf_input_get_mouse_button(u32 button);
b8 hf_input_get_mouse_button_down(u32 button);
b8 hf_input_get_mouse_button_up(u32 button);

v2f hf_input_get_mouse_movement();

void hf_input_show_cursor(b8 visibility);
void hf_input_toggle_cursor();
b8 hf_input_get_cursor_visibility();

void hf_input_destroy();

void hf_input_set_mouse_position(u32 x, u32 y);





#endif //INPUT_H
