//This file is automatically generated.
//The original file is lv_checkbox.h
#include "GhostSafeLVGL.h"
#include "safe_lv_checkbox.h"

//The original function is: lv_checkbox_create.
lv_obj_t * safe_lv_checkbox_create(lv_obj_t * parent)
{
    GhostLV_Lock();
    lv_obj_t * ret = lv_checkbox_create(parent);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_checkbox_set_text.
void safe_lv_checkbox_set_text(lv_obj_t * obj, const char * txt)
{
    GhostLV_Lock();
    lv_checkbox_set_text(obj, txt);
    GhostLV_Unlock();
}

//The original function is: lv_checkbox_get_text.
const char * safe_lv_checkbox_get_text(const lv_obj_t * obj)
{
    GhostLV_Lock();
    const char * ret = lv_checkbox_get_text(obj);
    GhostLV_Unlock();
    return ret;
}

