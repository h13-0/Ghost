//This file is automatically generated.
//The original file is lv_table.h
#include "GhostSafeLVGL.h"
#include "safe_lv_table.h"

//The original function is: lv_table_create.
lv_obj_t * safe_lv_table_create(lv_obj_t * parent)
{
    GhostLV_Lock();
    lv_obj_t * ret = lv_table_create(parent);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_table_get_row_cnt.
uint16_t safe_lv_table_get_row_cnt(lv_obj_t * obj)
{
    GhostLV_Lock();
    uint16_t ret = lv_table_get_row_cnt(obj);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_table_get_col_cnt.
uint16_t safe_lv_table_get_col_cnt(lv_obj_t * obj)
{
    GhostLV_Lock();
    uint16_t ret = lv_table_get_col_cnt(obj);
    GhostLV_Unlock();
    return ret;
}

