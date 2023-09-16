#include "hfcameracontroller.h"

void hf_camera_controller_update(hf_camera_controller* controller){
    f32 speed = hf_get_delta_time() * ((hf_input_get_key(HF_KEY_LEFT_SHIFT)) ? controller->movement_speed * 2 : controller->movement_speed);
    
    f32 dir_x = controller->direction.x * speed;
    f32 dir_z = controller->direction.z * speed;
    
    //hf_log("[%f %f]", camera->direction.x, camera->direction.z);
    
    if(hf_input_get_key(HF_KEY_W))
        controller->camera.pos = hf_add_v3f(controller->camera.pos, hf_v3f(-dir_x, 0, -dir_z));
    if(hf_input_get_key(HF_KEY_A))
        controller->camera.pos = hf_add_v3f(controller->camera.pos, hf_v3f(-dir_z, 0, dir_x));
    if(hf_input_get_key(HF_KEY_S))
        controller->camera.pos = hf_add_v3f(controller->camera.pos, hf_v3f(dir_x, 0, dir_z));
    if(hf_input_get_key(HF_KEY_D))
        controller->camera.pos = hf_add_v3f(controller->camera.pos, hf_v3f(dir_z, 0, -dir_x));
    if(hf_input_get_key(HF_KEY_SPACE))
        controller->camera.pos = hf_add_v3f(controller->camera.pos, hf_v3f(0, speed, 0));
    if(hf_input_get_key(HF_KEY_LEFT_CONTROL))
        controller->camera.pos = hf_add_v3f(controller->camera.pos, hf_v3f(0, -speed, 0));
    
    v2f rotation_amount = hf_mul_v2f_f(hf_input_get_mouse_movement(), -controller->sensitivity);
    
    controller->camera.rot = hf_add_v3f(controller->camera.rot, hf_v3f(rotation_amount.y, rotation_amount.x, 0));
    
    controller->direction = hf_get_dir_from_rot(hf_v3f(0, controller->camera.rot.y, 0));
    
    
    
    if (controller->camera.rot.x < -90)
        controller->camera.rot.x = -90;
    else if (controller->camera.rot.x > 90)
        controller->camera.rot.x = 90;
}