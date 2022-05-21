//This file is automatically generated.
//The original file is lv_msgbox.h
#include "GhostSafeLVGL.h"
#include "safe_lv_msgbox.h"

//The original function is: lv_msgbox_get_title.
lv_obj_t * safe_lv_msgbox_get_title(lv_obj_t * obj)
{
    GhostLV_Lock();
    lv_obj_t * ret = lv_msgbox_get_title(obj);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_msgbox_get_close_btn.
lv_obj_t * safe_lv_msgbox_get_close_btn(lv_obj_t * obj)
{
    GhostLV_Lock();
    lv_obj_t * ret = lv_msgbox_get_close_btn(obj);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_msgbox_get_text.
lv_obj_t * safe_lv_msgbox_get_text(lv_obj_t * obj)
{
    GhostLV_Lock();
    lv_obj_t * ret = lv_msgbox_get_text(obj);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_msgbox_get_content.
lv_obj_t * safe_lv_msgbox_get_content(lv_obj_t * obj)
{
    GhostLV_Lock();
    lv_obj_t * ret = lv_msgbox_get_content(obj);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_msgbox_get_btns.
lv_obj_t * safe_lv_msgbox_get_btns(lv_obj_t * obj)
{
    GhostLV_Lock();
    lv_obj_t * ret = lv_msgbox_get_btns(obj);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_msgbox_get_active_btn.
uint16_t safe_lv_msgbox_get_active_btn(lv_obj_t * mbox)
{
    GhostLV_Lock();
    uint16_t ret = lv_msgbox_get_active_btn(mbox);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_msgbox_get_active_btn_text.
const char * safe_lv_msgbox_get_active_btn_text(lv_obj_t * mbox)
{
    GhostLV_Lock();
    const char * ret = lv_msgbox_get_active_btn_text(mbox);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_msgbox_close.
void safe_lv_msgbox_close(lv_obj_t * mbox)
{
    GhostLV_Lock();
    lv_msgbox_close(mbox);
    GhostLV_Unlock();
}

//The original function is: lv_msgbox_close_async.
void safe_lv_msgbox_close_async(lv_obj_t * mbox)
{
    GhostLV_Lock();
    lv_msgbox_close_async(mbox);
    GhostLV_Unlock();
}

