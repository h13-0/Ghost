//This file is automatically generated.
//The original file is lv_qrcode.h
#include "GhostSafeLVGL.h"
#include "safe_lv_qrcode.h"

//The original function is: lv_qrcode_create.
lv_obj_t * safe_lv_qrcode_create(lv_obj_t * parent, lv_coord_t size, lv_color_t dark_color, lv_color_t light_color)
{
    GhostLV_Lock();
    lv_obj_t * ret = lv_qrcode_create(parent, size, dark_color, light_color);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_qrcode_update.
lv_res_t safe_lv_qrcode_update(lv_obj_t * qrcode, const void * data, uint32_t data_len)
{
    GhostLV_Lock();
    lv_res_t ret = lv_qrcode_update(qrcode, data, data_len);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_qrcode_delete.
void safe_lv_qrcode_delete(lv_obj_t * qrcode)
{
    GhostLV_Lock();
    lv_qrcode_delete(qrcode);
    GhostLV_Unlock();
}

