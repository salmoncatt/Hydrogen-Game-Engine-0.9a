#include "chunk.h"
f32 hf_whole_block_vertices[30] = {
    0, 0, 0,
    1, 0, 0,
    1, 1, 0,
    0, 1, 0,
    0, 0, 1,
    1, 0, 1,
    1, 1, 1,
    0, 1, 1
};

f32 hf_whole_block_indices[50] = {
    0, 1, 3, 3, 1, 2,
    1, 5, 2, 2, 5, 6,
    5, 4, 6, 6, 4, 7,
    4, 0, 7, 7, 0, 3,
    3, 2, 7, 7, 2, 6,
    4, 5, 0, 0, 5, 1
        
};

f32 hf_whole_block_uvs[30] = {
    0,0,0,1,1,1,
    0,0,1,0,1,1
};

//#include "../../../HF/mesh/hfmesh.h"

hf_chunk hf_create_chunk(){
    hf_chunk out = {};
    out.blocks[0][0][0] = 1;
    out.mesh.vertices = hf_array_create_from_data(hf_whole_block_vertices, f32, 24);
    out.mesh.indices = hf_array_create_from_data(hf_whole_block_indices, f32, 36);
    out.mesh.texture_coords = hf_array_create_from_data(hf_whole_block_uvs, f32, 12);
    hf_mesh_create(&out.mesh);
    hf_texture texture = hf_texture_from_file("../res/images/dirt.png");
    hf_texture_create(&texture);
    out.mesh.texture = texture;
    
    return out;
}
