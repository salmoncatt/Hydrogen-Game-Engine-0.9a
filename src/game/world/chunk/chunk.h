/* date = January 19th 2024 10:42 pm */

#ifndef CHUNK_H
#define CHUNK_H

#include "voxeldata.h"

#include "../../../HF/mesh/hfmesh.h"


typedef struct hf_chunk{
    u16 blocks[16][256][16];
    
    
    hf_mesh mesh;
    
    
    
}hf_chunk;

hf_chunk hf_create_chunk();


#endif //CHUNK_H
