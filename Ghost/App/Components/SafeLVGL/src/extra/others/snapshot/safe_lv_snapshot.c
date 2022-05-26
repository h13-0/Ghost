//This file is automatically generated.
//The original file is lv_snapshot.h
#include "GhostSafeLVGL.h"
#include "safe_lv_snapshot.h"

//The original function is: lv_snapshot_take.
lv_img_dsc_t * safe_lv_snapshot_take(lv_obj_t * obj, lv_img_cf_t cf)
{
    GhostLV_Lock();
    lv_img_dsc_t * ret = lv_snapshot_take(obj, cf);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_snapshot_free.
void safe_lv_snapshot_free(lv_img_dsc_t * dsc)
{
    GhostLV_Lock();
    lv_snapshot_free(dsc);
    GhostLV_Unlock();
}

//The original function is: lv_snapshot_buf_size_needed.
uint32_t safe_lv_snapshot_buf_size_needed(lv_obj_t * obj, lv_img_cf_t cf)
{
    GhostLV_Lock();
    uint32_t ret = lv_snapshot_buf_size_needed(obj, cf);
    GhostLV_Unlock();
    return ret;
}

