//This file is automatically generated.
//The original file is lv_calendar.h
#include "GhostSafeLVGL.h"
#include "safe_lv_calendar.h"

//The original function is: lv_calendar_create.
lv_obj_t * safe_lv_calendar_create(lv_obj_t * parent)
{
    GhostLV_Lock();
    lv_obj_t * ret = lv_calendar_create(parent);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_calendar_set_day_names.
void safe_lv_calendar_set_day_names(lv_obj_t * obj, const char ** day_names)
{
    GhostLV_Lock();
    lv_calendar_set_day_names(obj, day_names);
    GhostLV_Unlock();
}

//The original function is: lv_calendar_get_btnmatrix.
lv_obj_t * safe_lv_calendar_get_btnmatrix(const lv_obj_t * obj)
{
    GhostLV_Lock();
    lv_obj_t * ret = lv_calendar_get_btnmatrix(obj);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_calendar_get_today_date.
const lv_calendar_date_t * safe_lv_calendar_get_today_date(const lv_obj_t * calendar)
{
    GhostLV_Lock();
    const lv_calendar_date_t * ret = lv_calendar_get_today_date(calendar);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_calendar_get_showed_date.
const lv_calendar_date_t * safe_lv_calendar_get_showed_date(const lv_obj_t * calendar)
{
    GhostLV_Lock();
    const lv_calendar_date_t * ret = lv_calendar_get_showed_date(calendar);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_calendar_get_highlighted_dates.
lv_calendar_date_t * safe_lv_calendar_get_highlighted_dates(const lv_obj_t * calendar)
{
    GhostLV_Lock();
    lv_calendar_date_t * ret = lv_calendar_get_highlighted_dates(calendar);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_calendar_get_highlighted_dates_num.
uint16_t safe_lv_calendar_get_highlighted_dates_num(const lv_obj_t * calendar)
{
    GhostLV_Lock();
    uint16_t ret = lv_calendar_get_highlighted_dates_num(calendar);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_calendar_get_pressed_date.
lv_res_t safe_lv_calendar_get_pressed_date(const lv_obj_t * calendar, lv_calendar_date_t * date)
{
    GhostLV_Lock();
    lv_res_t ret = lv_calendar_get_pressed_date(calendar, date);
    GhostLV_Unlock();
    return ret;
}

