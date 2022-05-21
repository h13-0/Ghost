//This file is automatically generated.
//The original file is lv_api_map.h
#include "GhostSafeLVGL.h"
#include "safe_lv_api_map.h"

//The original function is: lv_obj_get_parent.
lv_obj_t * parent = safe_lv_obj_get_parent(obj)
{
    GhostLV_Lock();
    lv_obj_t * parent = ret = lv_obj_get_parent(obj);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_obj_get_child_cnt.
lv_obj_move_to_index(obj, safe_lv_obj_get_child_cnt(parent) - 1)
{
    GhostLV_Lock();
    lv_obj_move_to_index(obj, ret = lv_obj_get_child_cnt(1);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_obj_get_index.
LV_LOG_WARN("lv_obj_get_child_id(obj) is deprecated, please use safe_lv_obj_get_index(obj).")
{
    GhostLV_Lock();
    LV_LOG_WARN("lv_obj_get_child_id(obj) is deprecated, please use ret = lv_obj_get_index(obj).");
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_obj_get_index.
return safe_lv_obj_get_index(obj)
{
    GhostLV_Lock();
    return ret = lv_obj_get_index(obj);
    GhostLV_Unlock();
    return ret;
}

