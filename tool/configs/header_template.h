/**
 * @file: ${filename} 
 * @note: This document is generated using [safe_lvgl_converter](https://github.com/h13-0/safe_lvgl_converter),
 *            based on lvgl version ${lvgl_version}.
 * @date: ${date}
 * @time: ${time}
 */

#ifndef __SAFE_LVGL_H__ 
#define __SAFE_LVGL_H__ 
#include "lvgl.h"

void safe_lvgl_init(void);

void lv_recursive_unlock(void);

void lv_recursive_lock(void);

${contents_here}

#endif /* __SAFE_LVGL_H__ */
