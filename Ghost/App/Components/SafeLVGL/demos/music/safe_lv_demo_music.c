//This file is automatically generated.
//The original file is lv_demo_music.h
#include "GhostSafeLVGL.h"
#include "safe_lv_demo_music.h"

//The original function is: lv_demo_music.
void safe_lv_demo_music(void)
{
    GhostLV_Lock();
    lv_demo_music();
    GhostLV_Unlock();
}

