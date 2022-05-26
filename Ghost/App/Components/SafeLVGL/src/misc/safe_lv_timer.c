//This file is automatically generated.
//The original file is lv_timer.h
#include "GhostSafeLVGL.h"
#include "safe_lv_timer.h"

//The original function is: lv_timer_handler.
LV_ATTRIBUTE_TIMER_HANDLER uint32_t safe_lv_timer_handler(void)
{
    GhostLV_Lock();
    LV_ATTRIBUTE_TIMER_HANDLER uint32_t ret = lv_timer_handler();
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_timer_create_basic.
lv_timer_t * safe_lv_timer_create_basic(void)
{
    GhostLV_Lock();
    lv_timer_t * ret = lv_timer_create_basic();
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_timer_del.
void safe_lv_timer_del(lv_timer_t * timer)
{
    GhostLV_Lock();
    lv_timer_del(timer);
    GhostLV_Unlock();
}

//The original function is: lv_timer_pause.
void safe_lv_timer_pause(lv_timer_t * timer)
{
    GhostLV_Lock();
    lv_timer_pause(timer);
    GhostLV_Unlock();
}

//The original function is: lv_timer_resume.
void safe_lv_timer_resume(lv_timer_t * timer)
{
    GhostLV_Lock();
    lv_timer_resume(timer);
    GhostLV_Unlock();
}

//The original function is: lv_timer_set_cb.
void safe_lv_timer_set_cb(lv_timer_t * timer, lv_timer_cb_t timer_cb)
{
    GhostLV_Lock();
    lv_timer_set_cb(timer, timer_cb);
    GhostLV_Unlock();
}

//The original function is: lv_timer_ready.
void safe_lv_timer_ready(lv_timer_t * timer)
{
    GhostLV_Lock();
    lv_timer_ready(timer);
    GhostLV_Unlock();
}

//The original function is: lv_timer_reset.
void safe_lv_timer_reset(lv_timer_t * timer)
{
    GhostLV_Lock();
    lv_timer_reset(timer);
    GhostLV_Unlock();
}

//The original function is: lv_timer_enable.
void safe_lv_timer_enable(bool en)
{
    GhostLV_Lock();
    lv_timer_enable(en);
    GhostLV_Unlock();
}

//The original function is: lv_timer_get_idle.
uint8_t safe_lv_timer_get_idle(void)
{
    GhostLV_Lock();
    uint8_t ret = lv_timer_get_idle();
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_timer_get_next.
lv_timer_t * safe_lv_timer_get_next(lv_timer_t * timer)
{
    GhostLV_Lock();
    lv_timer_t * ret = lv_timer_get_next(timer);
    GhostLV_Unlock();
    return ret;
}
