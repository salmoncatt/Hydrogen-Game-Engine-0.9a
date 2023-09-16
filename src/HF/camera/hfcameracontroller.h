/* date = March 7th 2022 6:24 pm */

#ifndef HFCAMERACONTROLLER_H
#define HFCAMERACONTROLLER_H

#include "hfcamera.h"

typedef struct hf_camera_controller{
    
    hf_camera camera;
    f32 sensitivity, movement_speed;
    v3f direction;
    
}hf_camera_controller;

void hf_camera_controller_update(hf_camera_controller* controller);

#endif //HFDEBUGCAMERA_H
