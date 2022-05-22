//This file is automatically generated.
//The original file is lv_img_buf.h
#include "GhostSafeLVGL.h"
#include "safe_lv_img_buf.h"

//The original function is: lv_img_buf_alloc.
lv_img_dsc_t * safe_lv_img_buf_alloc(lv_coord_t w, lv_coord_t h, lv_img_cf_t cf)
{
    GhostLV_Lock();
    lv_img_dsc_t * ret = lv_img_buf_alloc(w, h, cf);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_img_buf_get_px_color.
lv_color_t safe_lv_img_buf_get_px_color(lv_img_dsc_t * dsc, lv_coord_t x, lv_coord_t y, lv_color_t color)
{
    GhostLV_Lock();
    lv_color_t ret = lv_img_buf_get_px_color(dsc, x, y, color);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_img_buf_get_px_alpha.
lv_opa_t safe_lv_img_buf_get_px_alpha(lv_img_dsc_t * dsc, lv_coord_t x, lv_coord_t y)
{
    GhostLV_Lock();
    lv_opa_t ret = lv_img_buf_get_px_alpha(dsc, x, y);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_img_buf_set_px_color.
void safe_lv_img_buf_set_px_color(lv_img_dsc_t * dsc, lv_coord_t x, lv_coord_t y, lv_color_t c)
{
    GhostLV_Lock();
    lv_img_buf_set_px_color(dsc, x, y, c);
    GhostLV_Unlock();
}

//The original function is: lv_img_buf_set_px_alpha.
void safe_lv_img_buf_set_px_alpha(lv_img_dsc_t * dsc, lv_coord_t x, lv_coord_t y, lv_opa_t opa)
{
    GhostLV_Lock();
    lv_img_buf_set_px_alpha(dsc, x, y, opa);
    GhostLV_Unlock();
}

//The original function is: lv_img_buf_set_palette.
void safe_lv_img_buf_set_palette(lv_img_dsc_t * dsc, uint8_t id, lv_color_t c)
{
    GhostLV_Lock();
    lv_img_buf_set_palette(dsc, id, c);
    GhostLV_Unlock();
}

//The original function is: lv_img_buf_free.
void safe_lv_img_buf_free(lv_img_dsc_t * dsc)
{
    GhostLV_Lock();
    lv_img_buf_free(dsc);
    GhostLV_Unlock();
}

//The original function is: lv_img_buf_get_img_size.
uint32_t safe_lv_img_buf_get_img_size(lv_coord_t w, lv_coord_t h, lv_img_cf_t cf)
{
    GhostLV_Lock();
    uint32_t ret = lv_img_buf_get_img_size(w, h, cf);
    GhostLV_Unlock();
    return ret;
}

