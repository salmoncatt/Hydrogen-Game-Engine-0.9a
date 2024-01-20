/* date = January 19th 2024 10:19 pm */

#ifndef VOXELDATA_H
#define VOXELDATA_H



extern f32 hf_whole_block_vertices[] = {
    0, 0, 0,
    1, 0, 0,
    1, 1, 0,
    0, 1, 0,
    0, 0, 1,
    1, 0, 1,
    1, 1, 1,
    0, 1, 1
};

extern f32 hf_whole_block_indices[] = {
    0,1,3,	
    3,1,2,	
    4,5,7,
    7,5,6,
    8,9,11,
    11,9,10,
    12,13,15,
    15,13,14,	
    16,17,19,
    19,17,18,
    20,21,23,
    23,21,22
        
};




#endif //VOXELDATA_H
