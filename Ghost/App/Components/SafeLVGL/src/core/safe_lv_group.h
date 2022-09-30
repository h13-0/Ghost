//This file is automatically generated.
//The original file is lv_group.h
#include "lvgl.h"

//The original function is: lv_group_create.
lv_group_t * safe_lv_group_create(void);

//The original function is: lv_group_del.
void safe_lv_group_del(lv_group_t * group);

//The original function is: lv_group_set_default.
void safe_lv_group_set_default(lv_group_t * group);

//The original function is: lv_group_get_default.
lv_group_t * safe_lv_group_get_default(void);

//The original function is: lv_group_add_obj.
void safe_lv_group_add_obj(lv_group_t * group, struct _lv_obj_t * obj);

//The original function is: lv_group_remove_obj.
void safe_lv_group_remove_obj(struct _lv_obj_t * obj);

//The original function is: lv_group_remove_all_objs.
void safe_lv_group_remove_all_objs(lv_group_t * group);

//The original function is: lv_group_focus_obj.
void safe_lv_group_focus_obj(struct _lv_obj_t * obj);

//The original function is: lv_group_focus_next.
void safe_lv_group_focus_next(lv_group_t * group);

//The original function is: lv_group_focus_prev.
void safe_lv_group_focus_prev(lv_group_t * group);

//The original function is: lv_group_focus_freeze.
void safe_lv_group_focus_freeze(lv_group_t * group, bool en);

//The original function is: lv_group_set_focus_cb.
void safe_lv_group_set_focus_cb(lv_group_t * group, lv_group_focus_cb_t focus_cb);

//The original function is: lv_group_set_edge_cb.
void safe_lv_group_set_edge_cb(lv_group_t * group, lv_group_edge_cb_t edge_cb);

//The original function is: lv_group_set_refocus_policy.
void safe_lv_group_set_refocus_policy(lv_group_t * group, lv_group_refocus_policy_t policy);

//The original function is: lv_group_set_editing.
void safe_lv_group_set_editing(lv_group_t * group, bool edit);

//The original function is: lv_group_set_wrap.
void safe_lv_group_set_wrap(lv_group_t * group, bool en);

//The original function is: lv_group_get_focused.
struct _lv_obj_t * safe_lv_group_get_focused(const lv_group_t * group);

//The original function is: lv_group_get_focus_cb.
lv_group_focus_cb_t safe_lv_group_get_focus_cb(const lv_group_t * group);

//The original function is: lv_group_get_edge_cb.
lv_group_edge_cb_t safe_lv_group_get_edge_cb(const lv_group_t * group);

//The original function is: lv_group_get_editing.
bool safe_lv_group_get_editing(const lv_group_t * group);

//The original function is: lv_group_get_wrap.
bool safe_lv_group_get_wrap(lv_group_t * group);

//The original function is: lv_group_get_obj_count.
uint32_t safe_lv_group_get_obj_count(lv_group_t * group);

