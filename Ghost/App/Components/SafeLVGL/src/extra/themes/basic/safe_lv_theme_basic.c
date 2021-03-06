//This file is automatically generated.
//The original file is lv_theme_basic.h
#include "GhostSafeLVGL.h"
#include "safe_lv_theme_basic.h"

//The original function is: lv_theme_basic_init.
lv_theme_t * safe_lv_theme_basic_init(lv_disp_t * disp)
{
    GhostLV_Lock();
    lv_theme_t * ret = lv_theme_basic_init(disp);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_theme_basic_is_inited.
bool safe_lv_theme_basic_is_inited(void)
{
    GhostLV_Lock();
    bool ret = lv_theme_basic_is_inited();
    GhostLV_Unlock();
    return ret;
}

