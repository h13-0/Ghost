//This file is automatically generated.
//The original file is lv_objx_templ.h
#include "GhostSafeLVGL.h"
#include "safe_lv_objx_templ.h"

//The original function is: lv_templ_create.
lv_obj_t * safe_lv_templ_create(lv_obj_t * parent)
{
    GhostLV_Lock();
    lv_obj_t * ret = lv_templ_create(parent);
    GhostLV_Unlock();
    return ret;
}

