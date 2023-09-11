#include "hfapp.h"
#include "../debug/hfdebug.h"

hf_app* hf_global_app = NULL;

//#include "../text/hffreetype.h"

hf_app hf_app_defaults(){
    hf_app app = {};
    app.name = "HF app";
    //app.parameters = HF_APP_CREATE_WINDOW | HF_APP_USE_OPENGL;
    // NOTE(salmoncatt): smooths fps readings and reduces chatter
    app.fps_smoothing = 0.05f;
    
    return app;
}

void hf_app_start(hf_app* app){
    printf("[HF APP] starting HF app: [%s]...\n", app->name);
    
    hf_global_app = app;
    
#ifdef HF_DONT_BUFFER_STDOUT
    setvbuf(stdout, NULL, _IONBF, 0);
#endif
    
    //hf_time_init(app->fps_smoothing);
    
    if(app->parameters){
        if(app->parameters & HF_APP_VERBOSE){
            printf("[HF APP] app: [%s] is using parameters: [HF_APP_VERBOSE%s%s%s]\n", app->name, (app->parameters & HF_APP_CREATE_WINDOW) ? " HF_APP_CREATE_WINDOW" : "", (app->parameters & HF_APP_USE_ECS) ? " HF_APP_USE_ECS" : "", (app->parameters & HF_APP_USE_OPENGL) ? " HF_APP_USE_OPENGL" : "");
            
        }
        
        
        
        if(app->parameters & HF_APP_CREATE_WINDOW){
            
            glfwSetErrorCallback(hf_glfw_error_callback);
            
            if(!glfwInit()){
                hf_err("[HF APP] could not init GLFW\n");
                return;
            }else if(app->parameters & HF_APP_VERBOSE){
                printf("[HF APP] initialized GLFW\n");
            }
            
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
            
            
            app->window = hf_window_defaults();
            hf_window_create(&app->window);
        }
        
        if(app->parameters & HF_APP_USE_OPENGL){
            hf_gl_init();
        }
        
        
        /* 
                if(app->parameters & HF_APP_USE_ECS){
                    hf_ecs_init(&app->ecs);
                }
         */
        
    }else
        hf_err("[HF APP] app: [%s] doesn't have any parameters, using no HF utilities\n", app->name);
    
    
    
    //hf_gl_init();
    printf("[HF APP] initialized HF app: [%s]\n\n", app->name);
    
    
    
    /* 
        #ifdef _WIN32
            //needs to be weird like this in case of testing a window without opengl
            if(app->parameters & HF_APP_USE_OPENGL){
                hf_gl_load_context(); //creates an empty window to load gl extensions from
                //hf_create_window(&app->window);
            }
            
            
            
            //needs to be weird like this in case of testing a window without opengl
            if(app->parameters & HF_APP_USE_OPENGL){
                hf_gl_init();
                //hf_create_window(&app->window);
            }
            
        #endif
            
            if(app->parameters & HF_APP_USE_OPENGL){
                hf_free_type_init();
                hf_renderer_init(app);
                hf_renderer_init_2d(app);
            }
         */
}

void hf_app_update(hf_app* app){
    /* 
        if(app->parameters & HF_APP_USE_OPENGL){
            hf_renderer_update(app);
        }
        hf_time_update();
        hf_input_update(app);
     */
}

b8 hf_app_should_update(hf_app* app){
    hf_app_update(app);
    
    return hf_should_window_update(&app->window);
}

i32 hf_app_stop(hf_app* app){
    /* 
        hf_log("[HF APP] closing app: [%s]\n", app->name);
        
        if(app->parameters & HF_APP_USE_ECS){
            hf_ecs_destroy(&app->ecs);
        }
        if(app->parameters & HF_APP_CREATE_WINDOW){
            hf_destroy_window(&app->window);
        }
        
        if(app->parameters & HF_APP_USE_OPENGL){
            hf_renderer_destroy(app);
            hf_renderer_destroy_2d(app); 
            hf_gl_close();
            hf_free_type_close();
        }
         */
    if(app->parameters & HF_APP_CREATE_WINDOW){
        //hf_destroy_window(&app->window);
        glfwTerminate();
    }
    
    if(app->parameters & HF_APP_USE_OPENGL){
        //hf_renderer_destroy(app);
        //hf_renderer_destroy_2d(app); 
        hf_gl_close();
        //hf_free_type_close();
    }
    
    printf("[HF APP] closed app [%s]\n", app->name);
    
    return 1;
    //hf_MLD_close(app);
}
