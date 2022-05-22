//This file is automatically generated.
//The original file is lv_spinner.h
#include "GhostSafeLVGL.h"
#include "safe_lv_spinner.h"

//The original function is: lv_spinner_create.
lv_obj_t * safe_lv_spinner_create(lv_obj_t * parent, uint32_t time, uint32_t arc_length)
{
    GhostLV_Lock();
    lv_obj_t * ret = lv_spinner_create(parent, time, arc_length);
    GhostLV_Unlock();
    return ret;
}

