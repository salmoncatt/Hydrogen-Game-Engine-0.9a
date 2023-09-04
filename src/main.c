#include "HF/hf.h"



int main(){
    
    hf_window test;
    test.w = 300;
    test.h = 300;
    test.x = 300;
    test.y = 300;
    test.title = "poopy haha";
    
    hf_window_create(&test);
    
    printf("test\n");
    
    return 1;
}