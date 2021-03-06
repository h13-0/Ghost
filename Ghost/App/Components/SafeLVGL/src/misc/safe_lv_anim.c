//This file is automatically generated.
//The original file is lv_anim.h
#include "GhostSafeLVGL.h"
#include "safe_lv_anim.h"

//The original function is: lv_anim_init.
void safe_lv_anim_init(lv_anim_t * a)
{
    GhostLV_Lock();
    lv_anim_init(a);
    GhostLV_Unlock();
}

//The original function is: lv_anim_start.
lv_anim_t * safe_lv_anim_start(const lv_anim_t * a)
{
    GhostLV_Lock();
    lv_anim_t * ret = lv_anim_start(a);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_anim_get_playtime.
uint32_t safe_lv_anim_get_playtime(lv_anim_t * a)
{
    GhostLV_Lock();
    uint32_t ret = lv_anim_get_playtime(a);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_anim_del.
bool safe_lv_anim_del(void * var, lv_anim_exec_xcb_t exec_cb)
{
    GhostLV_Lock();
    bool ret = lv_anim_del(var, exec_cb);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_anim_del_all.
void safe_lv_anim_del_all(void)
{
    GhostLV_Lock();
    lv_anim_del_all();
    GhostLV_Unlock();
}

//The original function is: lv_anim_get.
lv_anim_t * safe_lv_anim_get(void * var, lv_anim_exec_xcb_t exec_cb)
{
    GhostLV_Lock();
    lv_anim_t * ret = lv_anim_get(var, exec_cb);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_anim_count_running.
uint16_t safe_lv_anim_count_running(void)
{
    GhostLV_Lock();
    uint16_t ret = lv_anim_count_running();
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_anim_refr_now.
void safe_lv_anim_refr_now(void)
{
    GhostLV_Lock();
    lv_anim_refr_now();
    GhostLV_Unlock();
}

//The original function is: lv_anim_path_linear.
int32_t safe_lv_anim_path_linear(const lv_anim_t * a)
{
    GhostLV_Lock();
    int32_t ret = lv_anim_path_linear(a);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_anim_path_ease_in.
int32_t safe_lv_anim_path_ease_in(const lv_anim_t * a)
{
    GhostLV_Lock();
    int32_t ret = lv_anim_path_ease_in(a);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_anim_path_ease_out.
int32_t safe_lv_anim_path_ease_out(const lv_anim_t * a)
{
    GhostLV_Lock();
    int32_t ret = lv_anim_path_ease_out(a);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_anim_path_ease_in_out.
int32_t safe_lv_anim_path_ease_in_out(const lv_anim_t * a)
{
    GhostLV_Lock();
    int32_t ret = lv_anim_path_ease_in_out(a);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_anim_path_overshoot.
int32_t safe_lv_anim_path_overshoot(const lv_anim_t * a)
{
    GhostLV_Lock();
    int32_t ret = lv_anim_path_overshoot(a);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_anim_path_bounce.
int32_t safe_lv_anim_path_bounce(const lv_anim_t * a)
{
    GhostLV_Lock();
    int32_t ret = lv_anim_path_bounce(a);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_anim_path_step.
int32_t safe_lv_anim_path_step(const lv_anim_t * a)
{
    GhostLV_Lock();
    int32_t ret = lv_anim_path_step(a);
    GhostLV_Unlock();
    return ret;
}

