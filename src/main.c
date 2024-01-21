#include "HF/hf.h"


#include "game/world/chunk/chunk.h"



int main(){
    hf_app app = hf_app_defaults();
    app.parameters = HF_APP_VERBOSE | HF_APP_CREATE_WINDOW | HF_APP_USE_OPENGL;
    app.window.title = "Goober: []";
    app.window.w = 1280;
    app.window.h = 720;
    app.window.x = 320;
    app.window.y = 180;
    hf_app_start(&app);
    f32 last_title_update = hf_get_time();
    
    glClearColor(1, 0.6f, 0, 1);
    
    hf_chunk chunk = hf_create_chunk();
    
    
    hf_mesh mesh = hf_mesh_load_from_file("../res/models/propane tank/tank model final.obj");
    hf_texture texture = hf_texture_from_file("../res/images/dirt.png");
    hf_texture_create(&texture);
    mesh.texture = texture;
    
    
    
    v3f pos = {0, 0, -5};
    v3f rot = {0, -90, 0};
    v3f scale = {1, 1, 1};
    hf_transform transform = {pos, rot, scale};
    
    
    hf_camera_controller cam_controller = { .sensitivity = 0.05f, .movement_speed = 10};
    
    
    while(hf_app_should_update(&app) && !hf_input_get_key_down(HF_KEY_ESCAPE)){
        //update camera controller and renderer camera before rendering
        hf_camera_controller_update(&cam_controller);
        hf_renderer_camera = cam_controller.camera;
        
        
        
        
        if(hf_input_get_mouse_button_down(HF_MOUSE_BUTTON_RIGHT)){
            hf_input_toggle_cursor();
        }
        
        
        
        hf_render_mesh(&chunk.mesh, &hf_default_shader, &transform);
        hf_render_mesh(&mesh, &hf_default_shader, &transform);
        
        
        
        
        
        
        //update title every half second
        if((hf_get_time() - last_title_update) > 10){
            char window_title[128];
            sprintf(window_title, "Goober: [%.1f] [%.1f]", hf_get_fps(), cam_controller.camera.pos.y);
            hf_window_set_title(&app.window, window_title);
            last_title_update = hf_get_time();
        }
        
    }
    
    
    //printf("test\n");
    
    return hf_app_stop(&app);
}