#include "HF/hf.h"



int main(){
    hf_app app = hf_app_defaults();
    app.parameters = HF_APP_VERBOSE | HF_APP_CREATE_WINDOW | HF_APP_USE_OPENGL;
    
    hf_app_start(&app);
    
    glClearColor(1, 0.6f, 0, 1);
    
    
    
    
    hf_mesh mesh = hf_mesh_load_from_file("../res/models/propane tank/tank model final.obj");
    hf_texture texture = hf_texture_from_file("../res/models/propane tank/Material_BaseColor.png");
    hf_texture_create(&texture);
    mesh.texture = texture;
    
    v3f pos = {0, 0, -5};
    v3f rot = {0, -90, 0};
    v3f scale = {1, 1, 1};
    hf_transform transform = {pos, rot, scale};
    
    
    while(hf_app_should_update(&app)){
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        hf_render_mesh(&mesh, &hf_default_shader, &transform);
        
        
        
        
    }
    
    
    //printf("test\n");
    
    return hf_app_stop(&app);
}