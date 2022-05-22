//This file is automatically generated.
//The original file is lv_ffmpeg.h
#include "GhostSafeLVGL.h"
#include "safe_lv_ffmpeg.h"

//The original function is: lv_ffmpeg_init.
void safe_lv_ffmpeg_init(void)
{
    GhostLV_Lock();
    lv_ffmpeg_init();
    GhostLV_Unlock();
}

//The original function is: lv_ffmpeg_get_frame_num.
int safe_lv_ffmpeg_get_frame_num(const char * path)
{
    GhostLV_Lock();
    int ret = lv_ffmpeg_get_frame_num(path);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_ffmpeg_player_create.
lv_obj_t * safe_lv_ffmpeg_player_create(lv_obj_t * parent)
{
    GhostLV_Lock();
    lv_obj_t * ret = lv_ffmpeg_player_create(parent);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_ffmpeg_player_set_src.
lv_res_t safe_lv_ffmpeg_player_set_src(lv_obj_t * obj, const char * path)
{
    GhostLV_Lock();
    lv_res_t ret = lv_ffmpeg_player_set_src(obj, path);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_ffmpeg_player_set_cmd.
void safe_lv_ffmpeg_player_set_cmd(lv_obj_t * obj, lv_ffmpeg_player_cmd_t cmd)
{
    GhostLV_Lock();
    lv_ffmpeg_player_set_cmd(obj, cmd);
    GhostLV_Unlock();
}

//The original function is: lv_ffmpeg_player_set_auto_restart.
void safe_lv_ffmpeg_player_set_auto_restart(lv_obj_t * obj, bool en)
{
    GhostLV_Lock();
    lv_ffmpeg_player_set_auto_restart(obj, en);
    GhostLV_Unlock();
}

