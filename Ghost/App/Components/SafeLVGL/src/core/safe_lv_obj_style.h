//This file is automatically generated.
//The original file is lv_obj_style.h
#include "lvgl.h"

//The original function is: lv_obj_add_style.
void safe_lv_obj_add_style(struct _lv_obj_t * obj, lv_style_t * style, lv_style_selector_t selector);

//The original function is: lv_obj_remove_style.
void safe_lv_obj_remove_style(struct _lv_obj_t * obj, lv_style_t * style, lv_style_selector_t selector);

//The original function is: lv_obj_report_style_change.
void safe_lv_obj_report_style_change(lv_style_t * style);

//The original function is: lv_obj_refresh_style.
void safe_lv_obj_refresh_style(struct _lv_obj_t * obj, lv_part_t part, lv_style_prop_t prop);

//The original function is: lv_obj_enable_style_refresh.
void safe_lv_obj_enable_style_refresh(bool en);

//The original function is: lv_obj_get_style_prop.
lv_style_value_t safe_lv_obj_get_style_prop(const struct _lv_obj_t * obj, lv_part_t part, lv_style_prop_t prop);

//The original function is: lv_obj_remove_local_style_prop.
bool safe_lv_obj_remove_local_style_prop(struct _lv_obj_t * obj, lv_style_prop_t prop, lv_style_selector_t selector);

//The original function is: lv_obj_style_get_selector_state.
lv_state_t safe_lv_obj_style_get_selector_state(lv_style_selector_t selector);

//The original function is: lv_obj_style_get_selector_part.
lv_part_t safe_lv_obj_style_get_selector_part(lv_style_selector_t selector);

//The original function is: lv_obj_calculate_style_text_align.
lv_text_align_t safe_lv_obj_calculate_style_text_align(const struct _lv_obj_t * obj, lv_part_t part, const char * txt);

