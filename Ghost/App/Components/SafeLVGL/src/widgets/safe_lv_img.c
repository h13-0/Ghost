//This file is automatically generated.
//The original file is lv_img.h
#include "GhostSafeLVGL.h"
#include "safe_lv_img.h"

//The original function is: lv_img_create.
lv_obj_t * safe_lv_img_create(lv_obj_t * parent)
{
    GhostLV_Lock();
    lv_obj_t * ret = lv_img_create(parent);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_img_set_src.
void safe_lv_img_set_src(lv_obj_t * obj, const void * src)
{
    GhostLV_Lock();
    lv_img_set_src(obj, src);
    GhostLV_Unlock();
}

//The original function is: lv_img_set_offset_x.
void safe_lv_img_set_offset_x(lv_obj_t * obj, lv_coord_t x)
{
    GhostLV_Lock();
    lv_img_set_offset_x(obj, x);
    GhostLV_Unlock();
}

//The original function is: lv_img_set_offset_y.
void safe_lv_img_set_offset_y(lv_obj_t * obj, lv_coord_t y)
{
    GhostLV_Lock();
    lv_img_set_offset_y(obj, y);
    GhostLV_Unlock();
}

//The original function is: lv_img_set_angle.
void safe_lv_img_set_angle(lv_obj_t * obj, int16_t angle)
{
    GhostLV_Lock();
    lv_img_set_angle(obj, angle);
    GhostLV_Unlock();
}

//The original function is: lv_img_set_pivot.
void safe_lv_img_set_pivot(lv_obj_t * obj, lv_coord_t x, lv_coord_t y)
{
    GhostLV_Lock();
    lv_img_set_pivot(obj, x, y);
    GhostLV_Unlock();
}

//The original function is: lv_img_set_zoom.
void safe_lv_img_set_zoom(lv_obj_t * obj, uint16_t zoom)
{
    GhostLV_Lock();
    lv_img_set_zoom(obj, zoom);
    GhostLV_Unlock();
}

//The original function is: lv_img_set_antialias.
void safe_lv_img_set_antialias(lv_obj_t * obj, bool antialias)
{
    GhostLV_Lock();
    lv_img_set_antialias(obj, antialias);
    GhostLV_Unlock();
}

//The original function is: lv_img_set_size_mode.
void safe_lv_img_set_size_mode(lv_obj_t * obj, lv_img_size_mode_t mode)
{
    GhostLV_Lock();
    lv_img_set_size_mode(obj, mode);
    GhostLV_Unlock();
}

//The original function is: lv_img_get_src.
const void * safe_lv_img_get_src(lv_obj_t * obj)
{
    GhostLV_Lock();
    const void * ret = lv_img_get_src(obj);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_img_get_offset_x.
lv_coord_t safe_lv_img_get_offset_x(lv_obj_t * obj)
{
    GhostLV_Lock();
    lv_coord_t ret = lv_img_get_offset_x(obj);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_img_get_offset_y.
lv_coord_t safe_lv_img_get_offset_y(lv_obj_t * obj)
{
    GhostLV_Lock();
    lv_coord_t ret = lv_img_get_offset_y(obj);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_img_get_angle.
uint16_t safe_lv_img_get_angle(lv_obj_t * obj)
{
    GhostLV_Lock();
    uint16_t ret = lv_img_get_angle(obj);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_img_get_pivot.
void safe_lv_img_get_pivot(lv_obj_t * obj, lv_point_t * pivot)
{
    GhostLV_Lock();
    lv_img_get_pivot(obj, pivot);
    GhostLV_Unlock();
}

//The original function is: lv_img_get_zoom.
uint16_t safe_lv_img_get_zoom(lv_obj_t * obj)
{
    GhostLV_Lock();
    uint16_t ret = lv_img_get_zoom(obj);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_img_get_antialias.
bool safe_lv_img_get_antialias(lv_obj_t * obj)
{
    GhostLV_Lock();
    bool ret = lv_img_get_antialias(obj);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_img_get_size_mode.
lv_img_size_mode_t safe_lv_img_get_size_mode(lv_obj_t * obj)
{
    GhostLV_Lock();
    lv_img_size_mode_t ret = lv_img_get_size_mode(obj);
    GhostLV_Unlock();
    return ret;
}

