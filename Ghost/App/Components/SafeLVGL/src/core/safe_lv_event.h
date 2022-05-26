//This file is automatically generated.
//The original file is lv_event.h
#include "lvgl.h"

//The original function is: lv_event_send.
lv_res_t safe_lv_event_send(struct _lv_obj_t * obj, lv_event_code_t event_code, void * param);

//The original function is: lv_obj_event_base.
lv_res_t safe_lv_obj_event_base(const lv_obj_class_t * class_p, lv_event_t * e);

//The original function is: lv_event_get_target.
struct _lv_obj_t * safe_lv_event_get_target(lv_event_t * e);

//The original function is: lv_event_get_current_target.
struct _lv_obj_t * safe_lv_event_get_current_target(lv_event_t * e);

//The original function is: lv_event_get_code.
lv_event_code_t safe_lv_event_get_code(lv_event_t * e);

//The original function is: lv_event_get_param.
void * safe_lv_event_get_param(lv_event_t * e);

//The original function is: lv_event_get_user_data.
void * safe_lv_event_get_user_data(lv_event_t * e);

//The original function is: lv_event_stop_bubbling.
void safe_lv_event_stop_bubbling(lv_event_t * e);

//The original function is: lv_event_stop_processing.
void safe_lv_event_stop_processing(lv_event_t * e);

//The original function is: lv_event_register_id.
uint32_t safe_lv_event_register_id(void);

//The original function is: lv_obj_remove_event_cb.
bool safe_lv_obj_remove_event_cb(struct _lv_obj_t * obj, lv_event_cb_t event_cb);

//The original function is: lv_obj_remove_event_dsc.
bool safe_lv_obj_remove_event_dsc(struct _lv_obj_t * obj, struct _lv_event_dsc_t * event_dsc);

//The original function is: lv_obj_get_event_user_data.
void * safe_lv_obj_get_event_user_data(struct _lv_obj_t * obj, lv_event_cb_t event_cb);

//The original function is: lv_event_get_indev.
lv_indev_t * safe_lv_event_get_indev(lv_event_t * e);

//The original function is: lv_event_get_draw_part_dsc.
lv_obj_draw_part_dsc_t * safe_lv_event_get_draw_part_dsc(lv_event_t * e);

//The original function is: lv_event_get_draw_ctx.
lv_draw_ctx_t * safe_lv_event_get_draw_ctx(lv_event_t * e);

//The original function is: lv_event_get_old_size.
const lv_area_t * safe_lv_event_get_old_size(lv_event_t * e);

//The original function is: lv_event_get_key.
uint32_t safe_lv_event_get_key(lv_event_t * e);

//The original function is: lv_event_get_scroll_anim.
lv_anim_t * safe_lv_event_get_scroll_anim(lv_event_t * e);

//The original function is: lv_event_set_ext_draw_size.
void safe_lv_event_set_ext_draw_size(lv_event_t * e, lv_coord_t size);

//The original function is: lv_event_get_self_size_info.
lv_point_t * safe_lv_event_get_self_size_info(lv_event_t * e);

//The original function is: lv_event_get_hit_test_info.
lv_hit_test_info_t * safe_lv_event_get_hit_test_info(lv_event_t * e);

//The original function is: lv_event_get_cover_area.
const lv_area_t * safe_lv_event_get_cover_area(lv_event_t * e);

//The original function is: lv_event_set_cover_res.
void safe_lv_event_set_cover_res(lv_event_t * e, lv_cover_res_t res);

