//This file is automatically generated.
//The original file is lv_list.h
#include "GhostSafeLVGL.h"
#include "safe_lv_list.h"

//The original function is: lv_list_create.
lv_obj_t * safe_lv_list_create(lv_obj_t * parent)
{
    GhostLV_Lock();
    lv_obj_t * ret = lv_list_create(parent);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_list_add_text.
lv_obj_t * safe_lv_list_add_text(lv_obj_t * list, const char * txt)
{
    GhostLV_Lock();
    lv_obj_t * ret = lv_list_add_text(list, txt);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_list_add_btn.
lv_obj_t * safe_lv_list_add_btn(lv_obj_t * list, const char * icon, const char * txt)
{
    GhostLV_Lock();
    lv_obj_t * ret = lv_list_add_btn(list, icon, txt);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_list_get_btn_text.
const char * safe_lv_list_get_btn_text(lv_obj_t * list, lv_obj_t * btn)
{
    GhostLV_Lock();
    const char * ret = lv_list_get_btn_text(list, btn);
    GhostLV_Unlock();
    return ret;
}

