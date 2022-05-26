//This file is automatically generated.
//The original file is lv_label.h
#include "GhostSafeLVGL.h"
#include "safe_lv_label.h"

//The original function is: lv_label_create.
lv_obj_t * safe_lv_label_create(lv_obj_t * parent)
{
    GhostLV_Lock();
    lv_obj_t * ret = lv_label_create(parent);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_label_set_text.
void safe_lv_label_set_text(lv_obj_t * obj, const char * text)
{
    GhostLV_Lock();
    lv_label_set_text(obj, text);
    GhostLV_Unlock();
}

//The original function is: lv_label_set_long_mode.
void safe_lv_label_set_long_mode(lv_obj_t * obj, lv_label_long_mode_t long_mode)
{
    GhostLV_Lock();
    lv_label_set_long_mode(obj, long_mode);
    GhostLV_Unlock();
}

//The original function is: lv_label_set_recolor.
void safe_lv_label_set_recolor(lv_obj_t * obj, bool en)
{
    GhostLV_Lock();
    lv_label_set_recolor(obj, en);
    GhostLV_Unlock();
}

//The original function is: lv_label_get_text.
char * safe_lv_label_get_text(const lv_obj_t * obj)
{
    GhostLV_Lock();
    char * ret = lv_label_get_text(obj);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_label_get_long_mode.
lv_label_long_mode_t safe_lv_label_get_long_mode(const lv_obj_t * obj)
{
    GhostLV_Lock();
    lv_label_long_mode_t ret = lv_label_get_long_mode(obj);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_label_get_recolor.
bool safe_lv_label_get_recolor(const lv_obj_t * obj)
{
    GhostLV_Lock();
    bool ret = lv_label_get_recolor(obj);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_label_get_letter_on.
uint32_t safe_lv_label_get_letter_on(const lv_obj_t * obj, lv_point_t * pos_in)
{
    GhostLV_Lock();
    uint32_t ret = lv_label_get_letter_on(obj, pos_in);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_label_is_char_under_pos.
bool safe_lv_label_is_char_under_pos(const lv_obj_t * obj, lv_point_t * pos)
{
    GhostLV_Lock();
    bool ret = lv_label_is_char_under_pos(obj, pos);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_label_get_text_selection_start.
uint32_t safe_lv_label_get_text_selection_start(const lv_obj_t * obj)
{
    GhostLV_Lock();
    uint32_t ret = lv_label_get_text_selection_start(obj);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_label_get_text_selection_end.
uint32_t safe_lv_label_get_text_selection_end(const lv_obj_t * obj)
{
    GhostLV_Lock();
    uint32_t ret = lv_label_get_text_selection_end(obj);
    GhostLV_Unlock();
    return ret;
}
