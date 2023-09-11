#include "HF/hf.h"



int main(){
    hf_app app = hf_app_defaults();
    app.parameters = HF_APP_VERBOSE | HF_APP_CREATE_WINDOW | HF_APP_USE_OPENGL;
    
    hf_app_start(&app);
    
    glClearColor(1, 0.6f, 0, 1);
    
    while(hf_app_should_update(&app)){
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
    
    
    //printf("test\n");
    
    return hf_app_stop(&app);
}