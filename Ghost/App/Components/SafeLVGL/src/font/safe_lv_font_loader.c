//This file is automatically generated.
//The original file is lv_font_loader.h
#include "GhostSafeLVGL.h"
#include "safe_lv_font_loader.h"

//The original function is: lv_font_load.
lv_font_t * safe_lv_font_load(const char * fontName)
{
    GhostLV_Lock();
    lv_font_t * ret = lv_font_load(fontName);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_font_free.
void safe_lv_font_free(lv_font_t * font)
{
    GhostLV_Lock();
    lv_font_free(font);
    GhostLV_Unlock();
}
