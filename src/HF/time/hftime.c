#include "hftime.h"


#ifdef _WIN32

f64 hf_cpu_freq; //only for windows
i64 hf_time_start;

#elif defined(__linux__)

struct timeval hf_time_start;

#endif

f64 hf_fps_smoothing;

f64 hf_frame_time;
f64 hf_last_frame_time;
f64 hf_last_fps;
f64 hf_sleep_time;


void hf_time_init(){
    hf_fps_smoothing = 10.0f;
    
    printf("[HF TIME] intialized time functions\n");
}



//returns time elapsed in milli
f64 hf_get_time(){
    return glfwGetTime() * 1000.0;
}

void hf_time_update(){
    hf_frame_time = (f64)((hf_get_time() - hf_last_frame_time) / 1000);
    hf_last_frame_time = hf_get_time();
    hf_last_fps = hf_lerp(hf_last_fps, 1.0 / hf_get_delta_time(), hf_fps_smoothing * hf_get_delta_time());
}

f64 hf_get_delta_time(){
    return hf_frame_time;
}

f64 hf_get_fps(){
    //hf_last_fps = 1.0 / hf_get_delta_time();
    
    return hf_last_fps;
}

void hf_limit_fps(f64 fps){
    /* 
        f64 wait_time = (f64)(1000 / fps);
        hf_sleep_time = wait_time - hf_get_delta_time();
        
        while(hf_sleep_time > 0){
            hf_sleep_time = wait_time - hf_get_delta_time();
        }
     */
    
    f64 desired_time = ((hf_last_frame_time / 1000.0) + 1.0 / fps);
    
    if (glfwGetTime() < desired_time) {
        hf_sleep((desired_time - glfwGetTime()) * 1000.0);
        
        while(glfwGetTime() < desired_time){
            //do nothing
        }
    }
    
    //if(hf_sleep_time > 0)
    //hf_sleep(hf_sleep_time);
}

void hf_sleep(f64 milli){
    
#ifdef _WIN32
    timeBeginPeriod(1);
    Sleep((u64)milli);
    timeEndPeriod(1);
#elif defined(__linux__)
    if (milli >= 1000)
        sleep(milli / 1000);
    usleep(((i64)milli % (i64)1000) * 1000);
#endif
    
    return;
}