/* date = August 26th 2021 8:23 pm */

#ifndef MESH_H
#define MESH_H

//#include "../datatypes/hfvector.h"

#include "../graphics/hftexture.h"
#include "../datatypes/hfarray.h"

typedef struct hf_mesh{
    
    hf_texture texture;
    
    f32* vertices;
    f32* texture_coords;
    u32* indices;
    f32* normals;
    
    
    u32 vao;
    u32 ibo;
    
    // NOTE(salmoncatt): 2d = 2, 3d = 3
    u32 type;
    
    b8 created;
}hf_mesh;

void hf_mesh_create(hf_mesh* mesh);

void hf_mesh_destroy(hf_mesh* mesh);

hf_mesh hf_mesh_load_from_file(const char* file_path);

#endif //MESH_H
