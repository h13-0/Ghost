//This file is automatically generated.
//The original file is lv_indev.h
#include "GhostSafeLVGL.h"
#include "safe_lv_indev.h"

//The original function is: lv_indev_read_timer_cb.
void safe_lv_indev_read_timer_cb(lv_timer_t * timer)
{
    GhostLV_Lock();
    lv_indev_read_timer_cb(timer);
    GhostLV_Unlock();
}

//The original function is: lv_indev_enable.
void safe_lv_indev_enable(lv_indev_t * indev, bool en)
{
    GhostLV_Lock();
    lv_indev_enable(indev, en);
    GhostLV_Unlock();
}

//The original function is: lv_indev_get_act.
lv_indev_t * safe_lv_indev_get_act(void)
{
    GhostLV_Lock();
    lv_indev_t * ret = lv_indev_get_act();
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_indev_get_type.
lv_indev_type_t safe_lv_indev_get_type(const lv_indev_t * indev)
{
    GhostLV_Lock();
    lv_indev_type_t ret = lv_indev_get_type(indev);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_indev_reset.
void safe_lv_indev_reset(lv_indev_t * indev, lv_obj_t * obj)
{
    GhostLV_Lock();
    lv_indev_reset(indev, obj);
    GhostLV_Unlock();
}

//The original function is: lv_indev_reset_long_press.
void safe_lv_indev_reset_long_press(lv_indev_t * indev)
{
    GhostLV_Lock();
    lv_indev_reset_long_press(indev);
    GhostLV_Unlock();
}

//The original function is: lv_indev_set_cursor.
void safe_lv_indev_set_cursor(lv_indev_t * indev, lv_obj_t * cur_obj)
{
    GhostLV_Lock();
    lv_indev_set_cursor(indev, cur_obj);
    GhostLV_Unlock();
}

//The original function is: lv_indev_set_group.
void safe_lv_indev_set_group(lv_indev_t * indev, lv_group_t * group)
{
    GhostLV_Lock();
    lv_indev_set_group(indev, group);
    GhostLV_Unlock();
}

//The original function is: lv_indev_get_point.
void safe_lv_indev_get_point(const lv_indev_t * indev, lv_point_t * point)
{
    GhostLV_Lock();
    lv_indev_get_point(indev, point);
    GhostLV_Unlock();
}

//The original function is: lv_indev_get_gesture_dir.
lv_dir_t safe_lv_indev_get_gesture_dir(const lv_indev_t * indev)
{
    GhostLV_Lock();
    lv_dir_t ret = lv_indev_get_gesture_dir(indev);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_indev_get_key.
uint32_t safe_lv_indev_get_key(const lv_indev_t * indev)
{
    GhostLV_Lock();
    uint32_t ret = lv_indev_get_key(indev);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_indev_get_scroll_dir.
lv_dir_t safe_lv_indev_get_scroll_dir(const lv_indev_t * indev)
{
    GhostLV_Lock();
    lv_dir_t ret = lv_indev_get_scroll_dir(indev);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_indev_get_scroll_obj.
lv_obj_t * safe_lv_indev_get_scroll_obj(const lv_indev_t * indev)
{
    GhostLV_Lock();
    lv_obj_t * ret = lv_indev_get_scroll_obj(indev);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_indev_get_vect.
void safe_lv_indev_get_vect(const lv_indev_t * indev, lv_point_t * point)
{
    GhostLV_Lock();
    lv_indev_get_vect(indev, point);
    GhostLV_Unlock();
}

//The original function is: lv_indev_wait_release.
void safe_lv_indev_wait_release(lv_indev_t * indev)
{
    GhostLV_Lock();
    lv_indev_wait_release(indev);
    GhostLV_Unlock();
}

//The original function is: lv_indev_get_obj_act.
lv_obj_t * safe_lv_indev_get_obj_act(void)
{
    GhostLV_Lock();
    lv_obj_t * ret = lv_indev_get_obj_act();
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_indev_get_read_timer.
lv_timer_t * safe_lv_indev_get_read_timer(lv_disp_t * indev)
{
    GhostLV_Lock();
    lv_timer_t * ret = lv_indev_get_read_timer(indev);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_indev_search_obj.
lv_obj_t * safe_lv_indev_search_obj(lv_obj_t * obj, lv_point_t * point)
{
    GhostLV_Lock();
    lv_obj_t * ret = lv_indev_search_obj(obj, point);
    GhostLV_Unlock();
    return ret;
}

