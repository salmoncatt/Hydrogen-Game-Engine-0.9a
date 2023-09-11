#include "hfarray.h"


void* hf_internal_array_create(u64 capacity, u64 stride){
    u64 header_size = HF_ARRAY_FIELDS_SIZE * sizeof(u64);
    u64 data_size = capacity * stride;
    u64* array = (u64*)hf_malloc(header_size + data_size);
    array[HF_ARRAY_CAPACITY] = capacity;
    array[HF_ARRAY_STRIDE] = stride;
    array[HF_ARRAY_SIZE] = 0;
    
    return (void*)(array + HF_ARRAY_FIELDS_SIZE);
}

void* hf_internal_array_create_from_data(void* data, u64 stride, u64 length){
    u64 header_size = HF_ARRAY_FIELDS_SIZE * sizeof(u64);
    u64 data_size = (length + 10) * stride;
    u64* array = (u64*)hf_malloc(header_size + data_size);
    array[HF_ARRAY_CAPACITY] = length + 10;
    array[HF_ARRAY_STRIDE] = stride;
    array[HF_ARRAY_SIZE] = length;
    
    hf_memcpy((void*)(array + HF_ARRAY_FIELDS_SIZE), data, data_size);
    
    return (void*)(array + HF_ARRAY_FIELDS_SIZE);
}

void hf_array_free(void* array){
    if(array){
        hf_free(((u64*)(array) - HF_ARRAY_FIELDS_SIZE));
        array = NULL;
    }
}

u64 hf_array_field_get(void* array, u64 field_id){
    return ((u64*)(array) - HF_ARRAY_FIELDS_SIZE)[field_id];
}

void hf_array_field_set(void* array, u64 field_id, u64 value){
    ((u64*)(array) - HF_ARRAY_FIELDS_SIZE)[field_id] = value;
}

void* hf_array_resize(void* array, u64 capacity){
    void* temp = hf_internal_array_create(capacity, hf_array_stride(array));
    hf_memcpy(temp, array, hf_array_size(array) * hf_array_stride(array));
    hf_array_field_set(temp, HF_ARRAY_SIZE, hf_array_size(array));
    hf_array_free(array);
    
    return temp;
}

void* hf_internal_array_push_back(void* array, void* value){
    if(hf_array_size(array) >= hf_array_capacity(array)){
        array = hf_array_resize(array, hf_array_size(array) * 2);
    }
    
    hf_memcpy(array + hf_array_size(array) * hf_array_stride(array), value, hf_array_stride(array));
    hf_array_field_set(array, HF_ARRAY_SIZE, hf_array_size(array) + 1);
    
    return array;
}