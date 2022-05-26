//This file is automatically generated.
//The original file is lv_arc.h
#include "GhostSafeLVGL.h"
#include "safe_lv_arc.h"

//The original function is: lv_arc_create.
lv_obj_t * safe_lv_arc_create(lv_obj_t * parent)
{
    GhostLV_Lock();
    lv_obj_t * ret = lv_arc_create(parent);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_arc_set_mode.
void safe_lv_arc_set_mode(lv_obj_t * arc, lv_arc_mode_t type)
{
    GhostLV_Lock();
    lv_arc_set_mode(arc, type);
    GhostLV_Unlock();
}

//The original function is: lv_arc_get_angle_start.
uint16_t safe_lv_arc_get_angle_start(lv_obj_t * obj)
{
    GhostLV_Lock();
    uint16_t ret = lv_arc_get_angle_start(obj);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_arc_get_angle_end.
uint16_t safe_lv_arc_get_angle_end(lv_obj_t * obj)
{
    GhostLV_Lock();
    uint16_t ret = lv_arc_get_angle_end(obj);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_arc_get_bg_angle_start.
uint16_t safe_lv_arc_get_bg_angle_start(lv_obj_t * obj)
{
    GhostLV_Lock();
    uint16_t ret = lv_arc_get_bg_angle_start(obj);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_arc_get_bg_angle_end.
uint16_t safe_lv_arc_get_bg_angle_end(lv_obj_t * obj)
{
    GhostLV_Lock();
    uint16_t ret = lv_arc_get_bg_angle_end(obj);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_arc_get_value.
int16_t safe_lv_arc_get_value(const lv_obj_t * obj)
{
    GhostLV_Lock();
    int16_t ret = lv_arc_get_value(obj);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_arc_get_min_value.
int16_t safe_lv_arc_get_min_value(const lv_obj_t * obj)
{
    GhostLV_Lock();
    int16_t ret = lv_arc_get_min_value(obj);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_arc_get_max_value.
int16_t safe_lv_arc_get_max_value(const lv_obj_t * obj)
{
    GhostLV_Lock();
    int16_t ret = lv_arc_get_max_value(obj);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_arc_get_mode.
lv_arc_mode_t safe_lv_arc_get_mode(const lv_obj_t * obj)
{
    GhostLV_Lock();
    lv_arc_mode_t ret = lv_arc_get_mode(obj);
    GhostLV_Unlock();
    return ret;
}

