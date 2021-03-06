//This file is automatically generated.
//The original file is lv_spinbox.h
#include "GhostSafeLVGL.h"
#include "safe_lv_spinbox.h"

//The original function is: lv_spinbox_create.
lv_obj_t * safe_lv_spinbox_create(lv_obj_t * parent)
{
    GhostLV_Lock();
    lv_obj_t * ret = lv_spinbox_create(parent);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_spinbox_set_rollover.
void safe_lv_spinbox_set_rollover(lv_obj_t * obj, bool b)
{
    GhostLV_Lock();
    lv_spinbox_set_rollover(obj, b);
    GhostLV_Unlock();
}

//The original function is: lv_spinbox_set_digit_step_direction.
void safe_lv_spinbox_set_digit_step_direction(lv_obj_t * obj, lv_dir_t direction)
{
    GhostLV_Lock();
    lv_spinbox_set_digit_step_direction(obj, direction);
    GhostLV_Unlock();
}

//The original function is: lv_spinbox_get_rollover.
bool safe_lv_spinbox_get_rollover(lv_obj_t * obj)
{
    GhostLV_Lock();
    bool ret = lv_spinbox_get_rollover(obj);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_spinbox_get_value.
int32_t safe_lv_spinbox_get_value(lv_obj_t * obj)
{
    GhostLV_Lock();
    int32_t ret = lv_spinbox_get_value(obj);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_spinbox_get_step.
int32_t safe_lv_spinbox_get_step(lv_obj_t * obj)
{
    GhostLV_Lock();
    int32_t ret = lv_spinbox_get_step(obj);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_spinbox_step_next.
void safe_lv_spinbox_step_next(lv_obj_t * obj)
{
    GhostLV_Lock();
    lv_spinbox_step_next(obj);
    GhostLV_Unlock();
}

//The original function is: lv_spinbox_step_prev.
void safe_lv_spinbox_step_prev(lv_obj_t * obj)
{
    GhostLV_Lock();
    lv_spinbox_step_prev(obj);
    GhostLV_Unlock();
}

//The original function is: lv_spinbox_increment.
void safe_lv_spinbox_increment(lv_obj_t * obj)
{
    GhostLV_Lock();
    lv_spinbox_increment(obj);
    GhostLV_Unlock();
}

//The original function is: lv_spinbox_decrement.
void safe_lv_spinbox_decrement(lv_obj_t * obj)
{
    GhostLV_Lock();
    lv_spinbox_decrement(obj);
    GhostLV_Unlock();
}

