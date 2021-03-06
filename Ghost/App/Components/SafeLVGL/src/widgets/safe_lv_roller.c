//This file is automatically generated.
//The original file is lv_roller.h
#include "GhostSafeLVGL.h"
#include "safe_lv_roller.h"

//The original function is: lv_roller_create.
lv_obj_t * safe_lv_roller_create(lv_obj_t * parent)
{
    GhostLV_Lock();
    lv_obj_t * ret = lv_roller_create(parent);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_roller_set_options.
void safe_lv_roller_set_options(lv_obj_t * obj, const char * options, lv_roller_mode_t mode)
{
    GhostLV_Lock();
    lv_roller_set_options(obj, options, mode);
    GhostLV_Unlock();
}

//The original function is: lv_roller_get_selected.
uint16_t safe_lv_roller_get_selected(const lv_obj_t * obj)
{
    GhostLV_Lock();
    uint16_t ret = lv_roller_get_selected(obj);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_roller_get_options.
const char * safe_lv_roller_get_options(const lv_obj_t * obj)
{
    GhostLV_Lock();
    const char * ret = lv_roller_get_options(obj);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_roller_get_option_cnt.
uint16_t safe_lv_roller_get_option_cnt(const lv_obj_t * obj)
{
    GhostLV_Lock();
    uint16_t ret = lv_roller_get_option_cnt(obj);
    GhostLV_Unlock();
    return ret;
}

