//This file is automatically generated.
//The original file is lv_font.h
#include "GhostSafeLVGL.h"
#include "safe_lv_font.h"

//The original function is: lv_font_get_glyph_bitmap.
const uint8_t * safe_lv_font_get_glyph_bitmap(const lv_font_t * font_p, uint32_t letter)
{
    GhostLV_Lock();
    const uint8_t * ret = lv_font_get_glyph_bitmap(font_p, letter);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_font_get_glyph_width.
uint16_t safe_lv_font_get_glyph_width(const lv_font_t * font, uint32_t letter, uint32_t letter_next)
{
    GhostLV_Lock();
    uint16_t ret = lv_font_get_glyph_width(font, letter, letter_next);
    GhostLV_Unlock();
    return ret;
}

