//This file is automatically generated.
//The original file is lv_img_decoder.h
#include "GhostSafeLVGL.h"
#include "safe_lv_img_decoder.h"

//The original function is: lv_img_decoder_get_info.
lv_res_t safe_lv_img_decoder_get_info(const void * src, lv_img_header_t * header)
{
    GhostLV_Lock();
    lv_res_t ret = lv_img_decoder_get_info(src, header);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_img_decoder_close.
void safe_lv_img_decoder_close(lv_img_decoder_dsc_t * dsc)
{
    GhostLV_Lock();
    lv_img_decoder_close(dsc);
    GhostLV_Unlock();
}

//The original function is: lv_img_decoder_create.
lv_img_decoder_t * safe_lv_img_decoder_create(void)
{
    GhostLV_Lock();
    lv_img_decoder_t * ret = lv_img_decoder_create();
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_img_decoder_delete.
void safe_lv_img_decoder_delete(lv_img_decoder_t * decoder)
{
    GhostLV_Lock();
    lv_img_decoder_delete(decoder);
    GhostLV_Unlock();
}

//The original function is: lv_img_decoder_set_info_cb.
void safe_lv_img_decoder_set_info_cb(lv_img_decoder_t * decoder, lv_img_decoder_info_f_t info_cb)
{
    GhostLV_Lock();
    lv_img_decoder_set_info_cb(decoder, info_cb);
    GhostLV_Unlock();
}

//The original function is: lv_img_decoder_set_open_cb.
void safe_lv_img_decoder_set_open_cb(lv_img_decoder_t * decoder, lv_img_decoder_open_f_t open_cb)
{
    GhostLV_Lock();
    lv_img_decoder_set_open_cb(decoder, open_cb);
    GhostLV_Unlock();
}

//The original function is: lv_img_decoder_set_read_line_cb.
void safe_lv_img_decoder_set_read_line_cb(lv_img_decoder_t * decoder, lv_img_decoder_read_line_f_t read_line_cb)
{
    GhostLV_Lock();
    lv_img_decoder_set_read_line_cb(decoder, read_line_cb);
    GhostLV_Unlock();
}

//The original function is: lv_img_decoder_set_close_cb.
void safe_lv_img_decoder_set_close_cb(lv_img_decoder_t * decoder, lv_img_decoder_close_f_t close_cb)
{
    GhostLV_Lock();
    lv_img_decoder_set_close_cb(decoder, close_cb);
    GhostLV_Unlock();
}

//The original function is: lv_img_decoder_built_in_info.
lv_res_t safe_lv_img_decoder_built_in_info(lv_img_decoder_t * decoder, const void * src, lv_img_header_t * header)
{
    GhostLV_Lock();
    lv_res_t ret = lv_img_decoder_built_in_info(decoder, src, header);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_img_decoder_built_in_open.
lv_res_t safe_lv_img_decoder_built_in_open(lv_img_decoder_t * decoder, lv_img_decoder_dsc_t * dsc)
{
    GhostLV_Lock();
    lv_res_t ret = lv_img_decoder_built_in_open(decoder, dsc);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_img_decoder_built_in_close.
void safe_lv_img_decoder_built_in_close(lv_img_decoder_t * decoder, lv_img_decoder_dsc_t * dsc)
{
    GhostLV_Lock();
    lv_img_decoder_built_in_close(decoder, dsc);
    GhostLV_Unlock();
}

