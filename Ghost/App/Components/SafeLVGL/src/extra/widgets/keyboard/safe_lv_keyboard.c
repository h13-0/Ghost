//This file is automatically generated.
//The original file is lv_keyboard.h
#include "GhostSafeLVGL.h"
#include "safe_lv_keyboard.h"

//The original function is: lv_keyboard_create.
lv_obj_t * safe_lv_keyboard_create(lv_obj_t * parent)
{
    GhostLV_Lock();
    lv_obj_t * ret = lv_keyboard_create(parent);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_keyboard_set_textarea.
void safe_lv_keyboard_set_textarea(lv_obj_t * kb, lv_obj_t * ta)
{
    GhostLV_Lock();
    lv_keyboard_set_textarea(kb, ta);
    GhostLV_Unlock();
}

//The original function is: lv_keyboard_set_mode.
void safe_lv_keyboard_set_mode(lv_obj_t * kb, lv_keyboard_mode_t mode)
{
    GhostLV_Lock();
    lv_keyboard_set_mode(kb, mode);
    GhostLV_Unlock();
}

//The original function is: lv_keyboard_set_popovers.
void safe_lv_keyboard_set_popovers(lv_obj_t * kb, bool en)
{
    GhostLV_Lock();
    lv_keyboard_set_popovers(kb, en);
    GhostLV_Unlock();
}

//The original function is: lv_keyboard_get_textarea.
lv_obj_t * safe_lv_keyboard_get_textarea(const lv_obj_t * kb)
{
    GhostLV_Lock();
    lv_obj_t * ret = lv_keyboard_get_textarea(kb);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_keyboard_get_mode.
lv_keyboard_mode_t safe_lv_keyboard_get_mode(const lv_obj_t * kb)
{
    GhostLV_Lock();
    lv_keyboard_mode_t ret = lv_keyboard_get_mode(kb);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_btnmatrix_get_popovers.
bool safe_lv_btnmatrix_get_popovers(const lv_obj_t * obj)
{
    GhostLV_Lock();
    bool ret = lv_btnmatrix_get_popovers(obj);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_keyboard_def_event_cb.
void safe_lv_keyboard_def_event_cb(lv_event_t * e)
{
    GhostLV_Lock();
    lv_keyboard_def_event_cb(e);
    GhostLV_Unlock();
}

