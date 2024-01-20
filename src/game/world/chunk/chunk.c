#include "chunk.h"
//#include "../../../HF/mesh/hfmesh.h"

hf_chunk hf_create_chunk(){
    hf_chunk out = {};
    out.blocks[0][0][0] = 1;
    out.mesh.vertices = hf_array_create_from_data(hf_whole_block_vertices, f32, 24);
    out.mesh.indices = hf_array_create_from_data(hf_whole_block_indices, f32, 36);
    hf_texture texture = hf_texture_from_file("../res/images/dirt.png");
    hf_texture_create(&texture);
    out.mesh.texture = texture;
    
    return out;
}
