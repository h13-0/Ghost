//This file is automatically generated.
//The original file is lv_draw_sdl_rect.h
#include "GhostSafeLVGL.h"
#include "safe_lv_draw_sdl_rect.h"

//The original function is: lv_draw_sdl_rect_bg_frag_obtain.
SDL_Texture * safe_lv_draw_sdl_rect_bg_frag_obtain(lv_draw_sdl_ctx_t * ctx, lv_coord_t radius)
{
    GhostLV_Lock();
    SDL_Texture * ret = lv_draw_sdl_rect_bg_frag_obtain(ctx, radius);
    GhostLV_Unlock();
    return ret;
}

