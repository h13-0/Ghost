//This file is automatically generated.
//The original file is lv_fs.h
#include "lvgl.h"

//The original function is: lv_fs_drv_init.
void safe_lv_fs_drv_init(lv_fs_drv_t * drv);

//The original function is: lv_fs_drv_register.
void safe_lv_fs_drv_register(lv_fs_drv_t * drv);

//The original function is: lv_fs_get_drv.
lv_fs_drv_t * safe_lv_fs_get_drv(char letter);

//The original function is: lv_fs_is_ready.
bool safe_lv_fs_is_ready(char letter);

//The original function is: lv_fs_open.
lv_fs_res_t safe_lv_fs_open(lv_fs_file_t * file_p, const char * path, lv_fs_mode_t mode);

//The original function is: lv_fs_close.
lv_fs_res_t safe_lv_fs_close(lv_fs_file_t * file_p);

//The original function is: lv_fs_dir_open.
lv_fs_res_t safe_lv_fs_dir_open(lv_fs_dir_t * rddir_p, const char * path);

//The original function is: lv_fs_dir_read.
lv_fs_res_t safe_lv_fs_dir_read(lv_fs_dir_t * rddir_p, char * fn);

//The original function is: lv_fs_dir_close.
lv_fs_res_t safe_lv_fs_dir_close(lv_fs_dir_t * rddir_p);

//The original function is: lv_fs_get_letters.
char * safe_lv_fs_get_letters(char * buf);

//The original function is: lv_fs_get_ext.
const char * safe_lv_fs_get_ext(const char * fn);

//The original function is: lv_fs_up.
char * safe_lv_fs_up(char * path);

//The original function is: lv_fs_get_last.
const char * safe_lv_fs_get_last(const char * path);

