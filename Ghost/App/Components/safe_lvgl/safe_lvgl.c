/**
 * @file: safe_lvgl.c
 * @note: This document is generated using [safe_lvgl_converter](https://github.com/h13-0/safe_lvgl_converter),
 *            based on lvgl version 8.3.4.
 * @date: 2022/12/22
 * @time: 00:53:40
 */
#include "safe_lvgl.h"
#include "GhostThread.h"

static GhostRecursiveMutex_t recursiveMutex;

void safe_lvgl_init(void)
{
    // recursive mutex init.
    GhostRecursiveMutexInit(&recursiveMutex);
}

void lv_recursive_unlock(void)
{
    // Unlock recursive mutex.
    GhostRecursiveMutexUnlock(&recursiveMutex);
}

void lv_recursive_lock(void)
{
    // Lock recursive mutex.
    GhostRecursiveMutexLock(&recursiveMutex);
}

void safe_lv_tick_inc(uint32_t tick_period)
{
    lv_recursive_lock();
    lv_tick_inc(tick_period);
    lv_recursive_unlock();
    
}


uint32_t safe_lv_tick_get(void)
{
    lv_recursive_lock();
    uint32_t ret = lv_tick_get();
    lv_recursive_unlock();
    return ret;
}


uint32_t safe_lv_tick_elaps(uint32_t prev_tick)
{
    lv_recursive_lock();
    uint32_t ret = lv_tick_elaps(prev_tick);
    lv_recursive_unlock();
    return ret;
}


uint32_t safe_lv_timer_handler(void)
{
    lv_recursive_lock();
    uint32_t ret = lv_timer_handler();
    lv_recursive_unlock();
    return ret;
}


static inline uint32_t safe_lv_timer_handler_run_in_period(uint32_t ms)
{
    lv_recursive_lock();
    uint32_t ret = lv_timer_handler_run_in_period(ms);
    lv_recursive_unlock();
    return ret;
}


lv_timer_t * safe_lv_timer_create_basic(void)
{
    lv_recursive_lock();
    lv_timer_t * ret = lv_timer_create_basic();
    lv_recursive_unlock();
    return ret;
}


lv_timer_t * safe_lv_timer_create(lv_timer_cb_t timer_xcb, uint32_t period, void * user_data)
{
    lv_recursive_lock();
    lv_timer_t * ret = lv_timer_create(timer_xcb, period, user_data);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_timer_del(lv_timer_t * timer)
{
    lv_recursive_lock();
    lv_timer_del(timer);
    lv_recursive_unlock();
    
}


void safe_lv_timer_pause(lv_timer_t * timer)
{
    lv_recursive_lock();
    lv_timer_pause(timer);
    lv_recursive_unlock();
    
}


void safe_lv_timer_resume(lv_timer_t * timer)
{
    lv_recursive_lock();
    lv_timer_resume(timer);
    lv_recursive_unlock();
    
}


void safe_lv_timer_set_cb(lv_timer_t * timer, lv_timer_cb_t timer_cb)
{
    lv_recursive_lock();
    lv_timer_set_cb(timer, timer_cb);
    lv_recursive_unlock();
    
}


void safe_lv_timer_set_period(lv_timer_t * timer, uint32_t period)
{
    lv_recursive_lock();
    lv_timer_set_period(timer, period);
    lv_recursive_unlock();
    
}


void safe_lv_timer_ready(lv_timer_t * timer)
{
    lv_recursive_lock();
    lv_timer_ready(timer);
    lv_recursive_unlock();
    
}


void safe_lv_timer_set_repeat_count(lv_timer_t * timer, int32_t repeat_count)
{
    lv_recursive_lock();
    lv_timer_set_repeat_count(timer, repeat_count);
    lv_recursive_unlock();
    
}


void safe_lv_timer_reset(lv_timer_t * timer)
{
    lv_recursive_lock();
    lv_timer_reset(timer);
    lv_recursive_unlock();
    
}


void safe_lv_timer_enable(bool en)
{
    lv_recursive_lock();
    lv_timer_enable(en);
    lv_recursive_unlock();
    
}


uint8_t safe_lv_timer_get_idle(void)
{
    lv_recursive_lock();
    uint8_t ret = lv_timer_get_idle();
    lv_recursive_unlock();
    return ret;
}


lv_timer_t * safe_lv_timer_get_next(lv_timer_t * timer)
{
    lv_recursive_lock();
    lv_timer_t * ret = lv_timer_get_next(timer);
    lv_recursive_unlock();
    return ret;
}


int16_t safe_lv_trigo_sin(int16_t angle)
{
    lv_recursive_lock();
    int16_t ret = lv_trigo_sin(angle);
    lv_recursive_unlock();
    return ret;
}


static inline int16_t safe_lv_trigo_cos(int16_t angle)
{
    lv_recursive_lock();
    int16_t ret = lv_trigo_cos(angle);
    lv_recursive_unlock();
    return ret;
}


uint32_t safe_lv_bezier3(uint32_t t, uint32_t u0, uint32_t u1, uint32_t u2, uint32_t u3)
{
    lv_recursive_lock();
    uint32_t ret = lv_bezier3(t, u0, u1, u2, u3);
    lv_recursive_unlock();
    return ret;
}


uint16_t safe_lv_atan2(int x, int y)
{
    lv_recursive_lock();
    uint16_t ret = lv_atan2(x, y);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_sqrt(uint32_t x, lv_sqrt_res_t * q, uint32_t mask)
{
    lv_recursive_lock();
    lv_sqrt(x, q, mask);
    lv_recursive_unlock();
    
}


int64_t safe_lv_pow(int64_t base, int8_t exp)
{
    lv_recursive_lock();
    int64_t ret = lv_pow(base, exp);
    lv_recursive_unlock();
    return ret;
}


int32_t safe_lv_map(int32_t x, int32_t min_in, int32_t max_in, int32_t min_out, int32_t max_out)
{
    lv_recursive_lock();
    int32_t ret = lv_map(x, min_in, max_in, min_out, max_out);
    lv_recursive_unlock();
    return ret;
}


uint32_t safe_lv_rand(uint32_t min, uint32_t max)
{
    lv_recursive_lock();
    uint32_t ret = lv_rand(min, max);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_mem_init(void)
{
    lv_recursive_lock();
    lv_mem_init();
    lv_recursive_unlock();
    
}


void safe_lv_mem_deinit(void)
{
    lv_recursive_lock();
    lv_mem_deinit();
    lv_recursive_unlock();
    
}


void * safe_lv_mem_alloc(size_t size)
{
    lv_recursive_lock();
    void * ret = lv_mem_alloc(size);
    lv_recursive_unlock();
    
}


void safe_lv_mem_free(void * data)
{
    lv_recursive_lock();
    lv_mem_free(data);
    lv_recursive_unlock();
    
}


void * safe_lv_mem_realloc(void * data_p, size_t new_size)
{
    lv_recursive_lock();
    void * ret = lv_mem_realloc(data_p, new_size);
    lv_recursive_unlock();
    
}


lv_res_t safe_lv_mem_test(void)
{
    lv_recursive_lock();
    lv_res_t ret = lv_mem_test();
    lv_recursive_unlock();
    return ret;
}


void safe_lv_mem_monitor(lv_mem_monitor_t * mon_p)
{
    lv_recursive_lock();
    lv_mem_monitor(mon_p);
    lv_recursive_unlock();
    
}


void * safe_lv_mem_buf_get(uint32_t size)
{
    lv_recursive_lock();
    void * ret = lv_mem_buf_get(size);
    lv_recursive_unlock();
    
}


void safe_lv_mem_buf_release(void * p)
{
    lv_recursive_lock();
    lv_mem_buf_release(p);
    lv_recursive_unlock();
    
}


void safe_lv_mem_buf_free_all(void)
{
    lv_recursive_lock();
    lv_mem_buf_free_all();
    lv_recursive_unlock();
    
}


void * safe_lv_memcpy(void * dst, const void * src, size_t len)
{
    lv_recursive_lock();
    void * ret = lv_memcpy(dst, src, len);
    lv_recursive_unlock();
    
}


static inline void * safe_lv_memcpy_small(void * dst, const void * src, size_t len)
{
    lv_recursive_lock();
    void * ret = lv_memcpy_small(dst, src, len);
    lv_recursive_unlock();
    
}


void safe_lv_memset(void * dst, uint8_t v, size_t len)
{
    lv_recursive_lock();
    lv_memset(dst, v, len);
    lv_recursive_unlock();
    
}


void safe_lv_memset_00(void * dst, size_t len)
{
    lv_recursive_lock();
    lv_memset_00(dst, len);
    lv_recursive_unlock();
    
}


void safe_lv_memset_ff(void * dst, size_t len)
{
    lv_recursive_lock();
    lv_memset_ff(dst, len);
    lv_recursive_unlock();
    
}


lv_res_t safe_lv_async_call(lv_async_cb_t async_xcb, void * user_data)
{
    lv_recursive_lock();
    lv_res_t ret = lv_async_call(async_xcb, user_data);
    lv_recursive_unlock();
    return ret;
}


lv_res_t safe_lv_async_call_cancel(lv_async_cb_t async_xcb, void * user_data)
{
    lv_recursive_lock();
    lv_res_t ret = lv_async_call_cancel(async_xcb, user_data);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_anim_init(lv_anim_t * a)
{
    lv_recursive_lock();
    lv_anim_init(a);
    lv_recursive_unlock();
    
}


static inline void safe_lv_anim_set_var(lv_anim_t * a, void * var)
{
    lv_recursive_lock();
    lv_anim_set_var(a, var);
    lv_recursive_unlock();
    
}


static inline void safe_lv_anim_set_exec_cb(lv_anim_t * a, lv_anim_exec_xcb_t exec_cb)
{
    lv_recursive_lock();
    lv_anim_set_exec_cb(a, exec_cb);
    lv_recursive_unlock();
    
}


static inline void safe_lv_anim_set_time(lv_anim_t * a, uint32_t duration)
{
    lv_recursive_lock();
    lv_anim_set_time(a, duration);
    lv_recursive_unlock();
    
}


static inline void safe_lv_anim_set_delay(lv_anim_t * a, uint32_t delay)
{
    lv_recursive_lock();
    lv_anim_set_delay(a, delay);
    lv_recursive_unlock();
    
}


static inline void safe_lv_anim_set_values(lv_anim_t * a, int32_t start, int32_t end)
{
    lv_recursive_lock();
    lv_anim_set_values(a, start, end);
    lv_recursive_unlock();
    
}


static inline void safe_lv_anim_set_custom_exec_cb(lv_anim_t * a, lv_anim_custom_exec_cb_t exec_cb)
{
    lv_recursive_lock();
    lv_anim_set_custom_exec_cb(a, exec_cb);
    lv_recursive_unlock();
    
}


static inline void safe_lv_anim_set_path_cb(lv_anim_t * a, lv_anim_path_cb_t path_cb)
{
    lv_recursive_lock();
    lv_anim_set_path_cb(a, path_cb);
    lv_recursive_unlock();
    
}


static inline void safe_lv_anim_set_start_cb(lv_anim_t * a, lv_anim_start_cb_t start_cb)
{
    lv_recursive_lock();
    lv_anim_set_start_cb(a, start_cb);
    lv_recursive_unlock();
    
}


static inline void safe_lv_anim_set_get_value_cb(lv_anim_t * a, lv_anim_get_value_cb_t get_value_cb)
{
    lv_recursive_lock();
    lv_anim_set_get_value_cb(a, get_value_cb);
    lv_recursive_unlock();
    
}


static inline void safe_lv_anim_set_ready_cb(lv_anim_t * a, lv_anim_ready_cb_t ready_cb)
{
    lv_recursive_lock();
    lv_anim_set_ready_cb(a, ready_cb);
    lv_recursive_unlock();
    
}


static inline void safe_lv_anim_set_deleted_cb(lv_anim_t * a, lv_anim_deleted_cb_t deleted_cb)
{
    lv_recursive_lock();
    lv_anim_set_deleted_cb(a, deleted_cb);
    lv_recursive_unlock();
    
}


static inline void safe_lv_anim_set_playback_time(lv_anim_t * a, uint32_t time)
{
    lv_recursive_lock();
    lv_anim_set_playback_time(a, time);
    lv_recursive_unlock();
    
}


static inline void safe_lv_anim_set_playback_delay(lv_anim_t * a, uint32_t delay)
{
    lv_recursive_lock();
    lv_anim_set_playback_delay(a, delay);
    lv_recursive_unlock();
    
}


static inline void safe_lv_anim_set_repeat_count(lv_anim_t * a, uint16_t cnt)
{
    lv_recursive_lock();
    lv_anim_set_repeat_count(a, cnt);
    lv_recursive_unlock();
    
}


static inline void safe_lv_anim_set_repeat_delay(lv_anim_t * a, uint32_t delay)
{
    lv_recursive_lock();
    lv_anim_set_repeat_delay(a, delay);
    lv_recursive_unlock();
    
}


static inline void safe_lv_anim_set_early_apply(lv_anim_t * a, bool en)
{
    lv_recursive_lock();
    lv_anim_set_early_apply(a, en);
    lv_recursive_unlock();
    
}


static inline void safe_lv_anim_set_user_data(lv_anim_t * a, void * user_data)
{
    lv_recursive_lock();
    lv_anim_set_user_data(a, user_data);
    lv_recursive_unlock();
    
}


lv_anim_t * safe_lv_anim_start(const lv_anim_t * a)
{
    lv_recursive_lock();
    lv_anim_t * ret = lv_anim_start(a);
    lv_recursive_unlock();
    return ret;
}


static inline uint32_t safe_lv_anim_get_delay(lv_anim_t * a)
{
    lv_recursive_lock();
    uint32_t ret = lv_anim_get_delay(a);
    lv_recursive_unlock();
    return ret;
}


uint32_t safe_lv_anim_get_playtime(lv_anim_t * a)
{
    lv_recursive_lock();
    uint32_t ret = lv_anim_get_playtime(a);
    lv_recursive_unlock();
    return ret;
}


static inline void * safe_lv_anim_get_user_data(lv_anim_t * a)
{
    lv_recursive_lock();
    void * ret = lv_anim_get_user_data(a);
    lv_recursive_unlock();
    
}


bool safe_lv_anim_del(void * var, lv_anim_exec_xcb_t exec_cb)
{
    lv_recursive_lock();
    bool ret = lv_anim_del(var, exec_cb);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_anim_del_all(void)
{
    lv_recursive_lock();
    lv_anim_del_all();
    lv_recursive_unlock();
    
}


lv_anim_t * safe_lv_anim_get(void * var, lv_anim_exec_xcb_t exec_cb)
{
    lv_recursive_lock();
    lv_anim_t * ret = lv_anim_get(var, exec_cb);
    lv_recursive_unlock();
    return ret;
}


struct _lv_timer_t * safe_lv_anim_get_timer(void)
{
    lv_recursive_lock();
    struct _lv_timer_t * ret = lv_anim_get_timer();
    lv_recursive_unlock();
    return ret;
}


static inline bool safe_lv_anim_custom_del(lv_anim_t * a, lv_anim_custom_exec_cb_t exec_cb)
{
    lv_recursive_lock();
    bool ret = lv_anim_custom_del(a, exec_cb);
    lv_recursive_unlock();
    return ret;
}


static inline lv_anim_t * safe_lv_anim_custom_get(lv_anim_t * a, lv_anim_custom_exec_cb_t exec_cb)
{
    lv_recursive_lock();
    lv_anim_t * ret = lv_anim_custom_get(a, exec_cb);
    lv_recursive_unlock();
    return ret;
}


uint16_t safe_lv_anim_count_running(void)
{
    lv_recursive_lock();
    uint16_t ret = lv_anim_count_running();
    lv_recursive_unlock();
    return ret;
}


uint32_t safe_lv_anim_speed_to_time(uint32_t speed, int32_t start, int32_t end)
{
    lv_recursive_lock();
    uint32_t ret = lv_anim_speed_to_time(speed, start, end);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_anim_refr_now(void)
{
    lv_recursive_lock();
    lv_anim_refr_now();
    lv_recursive_unlock();
    
}


int32_t safe_lv_anim_path_linear(const lv_anim_t * a)
{
    lv_recursive_lock();
    int32_t ret = lv_anim_path_linear(a);
    lv_recursive_unlock();
    return ret;
}


int32_t safe_lv_anim_path_ease_in(const lv_anim_t * a)
{
    lv_recursive_lock();
    int32_t ret = lv_anim_path_ease_in(a);
    lv_recursive_unlock();
    return ret;
}


int32_t safe_lv_anim_path_ease_out(const lv_anim_t * a)
{
    lv_recursive_lock();
    int32_t ret = lv_anim_path_ease_out(a);
    lv_recursive_unlock();
    return ret;
}


int32_t safe_lv_anim_path_ease_in_out(const lv_anim_t * a)
{
    lv_recursive_lock();
    int32_t ret = lv_anim_path_ease_in_out(a);
    lv_recursive_unlock();
    return ret;
}


int32_t safe_lv_anim_path_overshoot(const lv_anim_t * a)
{
    lv_recursive_lock();
    int32_t ret = lv_anim_path_overshoot(a);
    lv_recursive_unlock();
    return ret;
}


int32_t safe_lv_anim_path_bounce(const lv_anim_t * a)
{
    lv_recursive_lock();
    int32_t ret = lv_anim_path_bounce(a);
    lv_recursive_unlock();
    return ret;
}


int32_t safe_lv_anim_path_step(const lv_anim_t * a)
{
    lv_recursive_lock();
    int32_t ret = lv_anim_path_step(a);
    lv_recursive_unlock();
    return ret;
}


lv_anim_timeline_t * safe_lv_anim_timeline_create(void)
{
    lv_recursive_lock();
    lv_anim_timeline_t * ret = lv_anim_timeline_create();
    lv_recursive_unlock();
    return ret;
}


void safe_lv_anim_timeline_del(lv_anim_timeline_t * at)
{
    lv_recursive_lock();
    lv_anim_timeline_del(at);
    lv_recursive_unlock();
    
}


void safe_lv_anim_timeline_add(lv_anim_timeline_t * at, uint32_t start_time, lv_anim_t * a)
{
    lv_recursive_lock();
    lv_anim_timeline_add(at, start_time, a);
    lv_recursive_unlock();
    
}


uint32_t safe_lv_anim_timeline_start(lv_anim_timeline_t * at)
{
    lv_recursive_lock();
    uint32_t ret = lv_anim_timeline_start(at);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_anim_timeline_stop(lv_anim_timeline_t * at)
{
    lv_recursive_lock();
    lv_anim_timeline_stop(at);
    lv_recursive_unlock();
    
}


void safe_lv_anim_timeline_set_reverse(lv_anim_timeline_t * at, bool reverse)
{
    lv_recursive_lock();
    lv_anim_timeline_set_reverse(at, reverse);
    lv_recursive_unlock();
    
}


void safe_lv_anim_timeline_set_progress(lv_anim_timeline_t * at, uint16_t progress)
{
    lv_recursive_lock();
    lv_anim_timeline_set_progress(at, progress);
    lv_recursive_unlock();
    
}


uint32_t safe_lv_anim_timeline_get_playtime(lv_anim_timeline_t * at)
{
    lv_recursive_lock();
    uint32_t ret = lv_anim_timeline_get_playtime(at);
    lv_recursive_unlock();
    return ret;
}


bool safe_lv_anim_timeline_get_reverse(lv_anim_timeline_t * at)
{
    lv_recursive_lock();
    bool ret = lv_anim_timeline_get_reverse(at);
    lv_recursive_unlock();
    return ret;
}


int safe_lv_vsnprintf(char * buffer, size_t count, const char * format, va_list va)
{
    lv_recursive_lock();
    int ret = lv_vsnprintf(buffer, count, format, va);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_area_set(lv_area_t * area_p, lv_coord_t x1, lv_coord_t y1, lv_coord_t x2, lv_coord_t y2)
{
    lv_recursive_lock();
    lv_area_set(area_p, x1, y1, x2, y2);
    lv_recursive_unlock();
    
}


static inline void safe_lv_area_copy(lv_area_t * dest, const lv_area_t * src)
{
    lv_recursive_lock();
    lv_area_copy(dest, src);
    lv_recursive_unlock();
    
}


static inline lv_coord_t safe_lv_area_get_width(const lv_area_t * area_p)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_area_get_width(area_p);
    lv_recursive_unlock();
    return ret;
}


static inline lv_coord_t safe_lv_area_get_height(const lv_area_t * area_p)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_area_get_height(area_p);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_area_set_width(lv_area_t * area_p, lv_coord_t w)
{
    lv_recursive_lock();
    lv_area_set_width(area_p, w);
    lv_recursive_unlock();
    
}


void safe_lv_area_set_height(lv_area_t * area_p, lv_coord_t h)
{
    lv_recursive_lock();
    lv_area_set_height(area_p, h);
    lv_recursive_unlock();
    
}


uint32_t safe_lv_area_get_size(const lv_area_t * area_p)
{
    lv_recursive_lock();
    uint32_t ret = lv_area_get_size(area_p);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_area_increase(lv_area_t * area, lv_coord_t w_extra, lv_coord_t h_extra)
{
    lv_recursive_lock();
    lv_area_increase(area, w_extra, h_extra);
    lv_recursive_unlock();
    
}


void safe_lv_area_move(lv_area_t * area, lv_coord_t x_ofs, lv_coord_t y_ofs)
{
    lv_recursive_lock();
    lv_area_move(area, x_ofs, y_ofs);
    lv_recursive_unlock();
    
}


void safe_lv_area_align(const lv_area_t * base, lv_area_t * to_align, lv_align_t align, lv_coord_t ofs_x, lv_coord_t ofs_y)
{
    lv_recursive_lock();
    lv_area_align(base, to_align, align, ofs_x, ofs_y);
    lv_recursive_unlock();
    
}


void safe_lv_point_transform(lv_point_t * p, int32_t angle, int32_t zoom, const lv_point_t * pivot)
{
    lv_recursive_lock();
    lv_point_transform(p, angle, zoom, pivot);
    lv_recursive_unlock();
    
}


static inline lv_coord_t safe_lv_pct(lv_coord_t x)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_pct(x);
    lv_recursive_unlock();
    return ret;
}


const uint8_t * safe_lv_font_get_glyph_bitmap(const lv_font_t * font_p, uint32_t letter)
{
    lv_recursive_lock();
    uint8_t * ret = lv_font_get_glyph_bitmap(font_p, letter);
    lv_recursive_unlock();
    return ret;
}


bool safe_lv_font_get_glyph_dsc(const lv_font_t * font_p, lv_font_glyph_dsc_t * dsc_out, uint32_t letter, uint32_t letter_next)
{
    lv_recursive_lock();
    bool ret = lv_font_get_glyph_dsc(font_p, dsc_out, letter, letter_next);
    lv_recursive_unlock();
    return ret;
}


uint16_t safe_lv_font_get_glyph_width(const lv_font_t * font, uint32_t letter, uint32_t letter_next)
{
    lv_recursive_lock();
    uint16_t ret = lv_font_get_glyph_width(font, letter, letter_next);
    lv_recursive_unlock();
    return ret;
}


static inline lv_coord_t safe_lv_font_get_line_height(const lv_font_t * font_p)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_font_get_line_height(font_p);
    lv_recursive_unlock();
    return ret;
}


const static inline lv_font_t * safe_lv_font_default(void)
{
    lv_recursive_lock();
    lv_font_t * ret = lv_font_default();
    lv_recursive_unlock();
    return ret;
}


static inline uint8_t safe_lv_color_to1(lv_color_t color)
{
    lv_recursive_lock();
    uint8_t ret = lv_color_to1(color);
    lv_recursive_unlock();
    return ret;
}


static inline uint8_t safe_lv_color_to8(lv_color_t color)
{
    lv_recursive_lock();
    uint8_t ret = lv_color_to8(color);
    lv_recursive_unlock();
    return ret;
}


static inline uint16_t safe_lv_color_to16(lv_color_t color)
{
    lv_recursive_lock();
    uint16_t ret = lv_color_to16(color);
    lv_recursive_unlock();
    return ret;
}


static inline uint32_t safe_lv_color_to32(lv_color_t color)
{
    lv_recursive_lock();
    uint32_t ret = lv_color_to32(color);
    lv_recursive_unlock();
    return ret;
}


static inline lv_color_t safe_lv_color_mix(lv_color_t c1, lv_color_t c2, uint8_t mix)
{
    lv_recursive_lock();
    lv_color_t ret = lv_color_mix(c1, c2, mix);
    lv_recursive_unlock();
    return ret;
}


static inline void safe_lv_color_premult(lv_color_t c, uint8_t mix, uint16_t * out)
{
    lv_recursive_lock();
    lv_color_premult(c, mix, out);
    lv_recursive_unlock();
    
}


static inline lv_color_t safe_lv_color_mix_premult(uint16_t * premult_c1, lv_color_t c2, uint8_t mix)
{
    lv_recursive_lock();
    lv_color_t ret = lv_color_mix_premult(premult_c1, c2, mix);
    lv_recursive_unlock();
    return ret;
}


static inline void safe_lv_color_mix_with_alpha(lv_color_t bg_color, lv_opa_t bg_opa, lv_color_t fg_color, lv_opa_t fg_opa, lv_color_t * res_color, lv_opa_t * res_opa)
{
    lv_recursive_lock();
    lv_color_mix_with_alpha(bg_color, bg_opa, fg_color, fg_opa, res_color, res_opa);
    lv_recursive_unlock();
    
}


static inline uint8_t safe_lv_color_brightness(lv_color_t color)
{
    lv_recursive_lock();
    uint8_t ret = lv_color_brightness(color);
    lv_recursive_unlock();
    return ret;
}


static inline lv_color_t safe_lv_color_make(uint8_t r, uint8_t g, uint8_t b)
{
    lv_recursive_lock();
    lv_color_t ret = lv_color_make(r, g, b);
    lv_recursive_unlock();
    return ret;
}


static inline lv_color_t safe_lv_color_hex(uint32_t c)
{
    lv_recursive_lock();
    lv_color_t ret = lv_color_hex(c);
    lv_recursive_unlock();
    return ret;
}


static inline lv_color_t safe_lv_color_hex3(uint32_t c)
{
    lv_recursive_lock();
    lv_color_t ret = lv_color_hex3(c);
    lv_recursive_unlock();
    return ret;
}


static inline void safe_lv_color_filter_dsc_init(lv_color_filter_dsc_t * dsc, lv_color_filter_cb_t cb)
{
    lv_recursive_lock();
    lv_color_filter_dsc_init(dsc, cb);
    lv_recursive_unlock();
    
}


void safe_lv_color_fill(lv_color_t * buf, lv_color_t color, uint32_t px_num)
{
    lv_recursive_lock();
    lv_color_fill(buf, color, px_num);
    lv_recursive_unlock();
    
}


lv_color_t safe_lv_color_lighten(lv_color_t c, lv_opa_t lvl)
{
    lv_recursive_lock();
    lv_color_t ret = lv_color_lighten(c, lvl);
    lv_recursive_unlock();
    return ret;
}


lv_color_t safe_lv_color_darken(lv_color_t c, lv_opa_t lvl)
{
    lv_recursive_lock();
    lv_color_t ret = lv_color_darken(c, lvl);
    lv_recursive_unlock();
    return ret;
}


lv_color_t safe_lv_color_change_lightness(lv_color_t c, lv_opa_t lvl)
{
    lv_recursive_lock();
    lv_color_t ret = lv_color_change_lightness(c, lvl);
    lv_recursive_unlock();
    return ret;
}


lv_color_t safe_lv_color_hsv_to_rgb(uint16_t h, uint8_t s, uint8_t v)
{
    lv_recursive_lock();
    lv_color_t ret = lv_color_hsv_to_rgb(h, s, v);
    lv_recursive_unlock();
    return ret;
}


lv_color_hsv_t safe_lv_color_rgb_to_hsv(uint8_t r8, uint8_t g8, uint8_t b8)
{
    lv_recursive_lock();
    lv_color_hsv_t ret = lv_color_rgb_to_hsv(r8, g8, b8);
    lv_recursive_unlock();
    return ret;
}


lv_color_hsv_t safe_lv_color_to_hsv(lv_color_t color)
{
    lv_recursive_lock();
    lv_color_hsv_t ret = lv_color_to_hsv(color);
    lv_recursive_unlock();
    return ret;
}


static inline lv_color_t safe_lv_color_chroma_key(void)
{
    lv_recursive_lock();
    lv_color_t ret = lv_color_chroma_key();
    lv_recursive_unlock();
    return ret;
}


lv_color_t safe_lv_palette_main(lv_palette_t p)
{
    lv_recursive_lock();
    lv_color_t ret = lv_palette_main(p);
    lv_recursive_unlock();
    return ret;
}


static inline lv_color_t safe_lv_color_white(void)
{
    lv_recursive_lock();
    lv_color_t ret = lv_color_white();
    lv_recursive_unlock();
    return ret;
}


static inline lv_color_t safe_lv_color_black(void)
{
    lv_recursive_lock();
    lv_color_t ret = lv_color_black();
    lv_recursive_unlock();
    return ret;
}


lv_color_t safe_lv_palette_lighten(lv_palette_t p, uint8_t lvl)
{
    lv_recursive_lock();
    lv_color_t ret = lv_palette_lighten(p, lvl);
    lv_recursive_unlock();
    return ret;
}


lv_color_t safe_lv_palette_darken(lv_palette_t p, uint8_t lvl)
{
    lv_recursive_lock();
    lv_color_t ret = lv_palette_darken(p, lvl);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_txt_get_size(lv_point_t * size_res, const char * text, const lv_font_t * font, lv_coord_t letter_space, lv_coord_t line_space, lv_coord_t max_width, lv_text_flag_t flag)
{
    lv_recursive_lock();
    lv_txt_get_size(size_res, text, font, letter_space, line_space, max_width, flag);
    lv_recursive_unlock();
    
}


lv_coord_t safe_lv_txt_get_width(const char * txt, uint32_t length, const lv_font_t * font, lv_coord_t letter_space, lv_text_flag_t flag)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_txt_get_width(txt, length, font, letter_space, flag);
    lv_recursive_unlock();
    return ret;
}


static inline void safe_lv_bidi_calculate_align(lv_text_align_t * align, lv_base_dir_t * base_dir, const char * txt)
{
    lv_recursive_lock();
    lv_bidi_calculate_align(align, base_dir, txt);
    lv_recursive_unlock();
    
}


void safe_lv_style_init(lv_style_t * style)
{
    lv_recursive_lock();
    lv_style_init(style);
    lv_recursive_unlock();
    
}


void safe_lv_style_reset(lv_style_t * style)
{
    lv_recursive_lock();
    lv_style_reset(style);
    lv_recursive_unlock();
    
}


lv_style_prop_t safe_lv_style_register_prop(uint8_t flag)
{
    lv_recursive_lock();
    lv_style_prop_t ret = lv_style_register_prop(flag);
    lv_recursive_unlock();
    return ret;
}


lv_style_prop_t safe_lv_style_get_num_custom_props(void)
{
    lv_recursive_lock();
    lv_style_prop_t ret = lv_style_get_num_custom_props();
    lv_recursive_unlock();
    return ret;
}


bool safe_lv_style_remove_prop(lv_style_t * style, lv_style_prop_t prop)
{
    lv_recursive_lock();
    bool ret = lv_style_remove_prop(style, prop);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_style_set_prop(lv_style_t * style, lv_style_prop_t prop, lv_style_value_t value)
{
    lv_recursive_lock();
    lv_style_set_prop(style, prop, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_prop_meta(lv_style_t * style, lv_style_prop_t prop, uint16_t meta)
{
    lv_recursive_lock();
    lv_style_set_prop_meta(style, prop, meta);
    lv_recursive_unlock();
    
}


lv_style_res_t safe_lv_style_get_prop(const lv_style_t * style, lv_style_prop_t prop, lv_style_value_t * value)
{
    lv_recursive_lock();
    lv_style_res_t ret = lv_style_get_prop(style, prop, value);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_style_transition_dsc_init(lv_style_transition_dsc_t * tr, const lv_style_prop_t props[], lv_anim_path_cb_t path_cb, uint32_t time, uint32_t delay, void * user_data)
{
    lv_recursive_lock();
    lv_style_transition_dsc_init(tr, props, path_cb, time, delay, user_data);
    lv_recursive_unlock();
    
}


lv_style_value_t safe_lv_style_prop_get_default(lv_style_prop_t prop)
{
    lv_recursive_lock();
    lv_style_value_t ret = lv_style_prop_get_default(prop);
    lv_recursive_unlock();
    return ret;
}


static inline lv_style_res_t safe_lv_style_get_prop_inlined(const lv_style_t * style, lv_style_prop_t prop, lv_style_value_t * value)
{
    lv_recursive_lock();
    lv_style_res_t ret = lv_style_get_prop_inlined(style, prop, value);
    lv_recursive_unlock();
    return ret;
}


bool safe_lv_style_is_empty(const lv_style_t * style)
{
    lv_recursive_lock();
    bool ret = lv_style_is_empty(style);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_style_set_width(lv_style_t * style, lv_coord_t value)
{
    lv_recursive_lock();
    lv_style_set_width(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_min_width(lv_style_t * style, lv_coord_t value)
{
    lv_recursive_lock();
    lv_style_set_min_width(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_max_width(lv_style_t * style, lv_coord_t value)
{
    lv_recursive_lock();
    lv_style_set_max_width(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_height(lv_style_t * style, lv_coord_t value)
{
    lv_recursive_lock();
    lv_style_set_height(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_min_height(lv_style_t * style, lv_coord_t value)
{
    lv_recursive_lock();
    lv_style_set_min_height(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_max_height(lv_style_t * style, lv_coord_t value)
{
    lv_recursive_lock();
    lv_style_set_max_height(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_x(lv_style_t * style, lv_coord_t value)
{
    lv_recursive_lock();
    lv_style_set_x(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_y(lv_style_t * style, lv_coord_t value)
{
    lv_recursive_lock();
    lv_style_set_y(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_align(lv_style_t * style, lv_align_t value)
{
    lv_recursive_lock();
    lv_style_set_align(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_transform_width(lv_style_t * style, lv_coord_t value)
{
    lv_recursive_lock();
    lv_style_set_transform_width(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_transform_height(lv_style_t * style, lv_coord_t value)
{
    lv_recursive_lock();
    lv_style_set_transform_height(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_translate_x(lv_style_t * style, lv_coord_t value)
{
    lv_recursive_lock();
    lv_style_set_translate_x(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_translate_y(lv_style_t * style, lv_coord_t value)
{
    lv_recursive_lock();
    lv_style_set_translate_y(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_transform_zoom(lv_style_t * style, lv_coord_t value)
{
    lv_recursive_lock();
    lv_style_set_transform_zoom(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_transform_angle(lv_style_t * style, lv_coord_t value)
{
    lv_recursive_lock();
    lv_style_set_transform_angle(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_transform_pivot_x(lv_style_t * style, lv_coord_t value)
{
    lv_recursive_lock();
    lv_style_set_transform_pivot_x(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_transform_pivot_y(lv_style_t * style, lv_coord_t value)
{
    lv_recursive_lock();
    lv_style_set_transform_pivot_y(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_pad_top(lv_style_t * style, lv_coord_t value)
{
    lv_recursive_lock();
    lv_style_set_pad_top(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_pad_bottom(lv_style_t * style, lv_coord_t value)
{
    lv_recursive_lock();
    lv_style_set_pad_bottom(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_pad_left(lv_style_t * style, lv_coord_t value)
{
    lv_recursive_lock();
    lv_style_set_pad_left(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_pad_right(lv_style_t * style, lv_coord_t value)
{
    lv_recursive_lock();
    lv_style_set_pad_right(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_pad_row(lv_style_t * style, lv_coord_t value)
{
    lv_recursive_lock();
    lv_style_set_pad_row(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_pad_column(lv_style_t * style, lv_coord_t value)
{
    lv_recursive_lock();
    lv_style_set_pad_column(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_bg_color(lv_style_t * style, lv_color_t value)
{
    lv_recursive_lock();
    lv_style_set_bg_color(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_bg_opa(lv_style_t * style, lv_opa_t value)
{
    lv_recursive_lock();
    lv_style_set_bg_opa(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_bg_grad_color(lv_style_t * style, lv_color_t value)
{
    lv_recursive_lock();
    lv_style_set_bg_grad_color(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_bg_grad_dir(lv_style_t * style, lv_grad_dir_t value)
{
    lv_recursive_lock();
    lv_style_set_bg_grad_dir(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_bg_main_stop(lv_style_t * style, lv_coord_t value)
{
    lv_recursive_lock();
    lv_style_set_bg_main_stop(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_bg_grad_stop(lv_style_t * style, lv_coord_t value)
{
    lv_recursive_lock();
    lv_style_set_bg_grad_stop(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_bg_grad(lv_style_t * style, const lv_grad_dsc_t * value)
{
    lv_recursive_lock();
    lv_style_set_bg_grad(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_bg_dither_mode(lv_style_t * style, lv_dither_mode_t value)
{
    lv_recursive_lock();
    lv_style_set_bg_dither_mode(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_bg_img_src(lv_style_t * style, const void * value)
{
    lv_recursive_lock();
    lv_style_set_bg_img_src(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_bg_img_opa(lv_style_t * style, lv_opa_t value)
{
    lv_recursive_lock();
    lv_style_set_bg_img_opa(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_bg_img_recolor(lv_style_t * style, lv_color_t value)
{
    lv_recursive_lock();
    lv_style_set_bg_img_recolor(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_bg_img_recolor_opa(lv_style_t * style, lv_opa_t value)
{
    lv_recursive_lock();
    lv_style_set_bg_img_recolor_opa(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_bg_img_tiled(lv_style_t * style, bool value)
{
    lv_recursive_lock();
    lv_style_set_bg_img_tiled(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_border_color(lv_style_t * style, lv_color_t value)
{
    lv_recursive_lock();
    lv_style_set_border_color(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_border_opa(lv_style_t * style, lv_opa_t value)
{
    lv_recursive_lock();
    lv_style_set_border_opa(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_border_width(lv_style_t * style, lv_coord_t value)
{
    lv_recursive_lock();
    lv_style_set_border_width(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_border_side(lv_style_t * style, lv_border_side_t value)
{
    lv_recursive_lock();
    lv_style_set_border_side(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_border_post(lv_style_t * style, bool value)
{
    lv_recursive_lock();
    lv_style_set_border_post(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_outline_width(lv_style_t * style, lv_coord_t value)
{
    lv_recursive_lock();
    lv_style_set_outline_width(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_outline_color(lv_style_t * style, lv_color_t value)
{
    lv_recursive_lock();
    lv_style_set_outline_color(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_outline_opa(lv_style_t * style, lv_opa_t value)
{
    lv_recursive_lock();
    lv_style_set_outline_opa(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_outline_pad(lv_style_t * style, lv_coord_t value)
{
    lv_recursive_lock();
    lv_style_set_outline_pad(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_shadow_width(lv_style_t * style, lv_coord_t value)
{
    lv_recursive_lock();
    lv_style_set_shadow_width(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_shadow_ofs_x(lv_style_t * style, lv_coord_t value)
{
    lv_recursive_lock();
    lv_style_set_shadow_ofs_x(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_shadow_ofs_y(lv_style_t * style, lv_coord_t value)
{
    lv_recursive_lock();
    lv_style_set_shadow_ofs_y(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_shadow_spread(lv_style_t * style, lv_coord_t value)
{
    lv_recursive_lock();
    lv_style_set_shadow_spread(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_shadow_color(lv_style_t * style, lv_color_t value)
{
    lv_recursive_lock();
    lv_style_set_shadow_color(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_shadow_opa(lv_style_t * style, lv_opa_t value)
{
    lv_recursive_lock();
    lv_style_set_shadow_opa(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_img_opa(lv_style_t * style, lv_opa_t value)
{
    lv_recursive_lock();
    lv_style_set_img_opa(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_img_recolor(lv_style_t * style, lv_color_t value)
{
    lv_recursive_lock();
    lv_style_set_img_recolor(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_img_recolor_opa(lv_style_t * style, lv_opa_t value)
{
    lv_recursive_lock();
    lv_style_set_img_recolor_opa(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_line_width(lv_style_t * style, lv_coord_t value)
{
    lv_recursive_lock();
    lv_style_set_line_width(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_line_dash_width(lv_style_t * style, lv_coord_t value)
{
    lv_recursive_lock();
    lv_style_set_line_dash_width(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_line_dash_gap(lv_style_t * style, lv_coord_t value)
{
    lv_recursive_lock();
    lv_style_set_line_dash_gap(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_line_rounded(lv_style_t * style, bool value)
{
    lv_recursive_lock();
    lv_style_set_line_rounded(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_line_color(lv_style_t * style, lv_color_t value)
{
    lv_recursive_lock();
    lv_style_set_line_color(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_line_opa(lv_style_t * style, lv_opa_t value)
{
    lv_recursive_lock();
    lv_style_set_line_opa(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_arc_width(lv_style_t * style, lv_coord_t value)
{
    lv_recursive_lock();
    lv_style_set_arc_width(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_arc_rounded(lv_style_t * style, bool value)
{
    lv_recursive_lock();
    lv_style_set_arc_rounded(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_arc_color(lv_style_t * style, lv_color_t value)
{
    lv_recursive_lock();
    lv_style_set_arc_color(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_arc_opa(lv_style_t * style, lv_opa_t value)
{
    lv_recursive_lock();
    lv_style_set_arc_opa(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_arc_img_src(lv_style_t * style, const void * value)
{
    lv_recursive_lock();
    lv_style_set_arc_img_src(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_text_color(lv_style_t * style, lv_color_t value)
{
    lv_recursive_lock();
    lv_style_set_text_color(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_text_opa(lv_style_t * style, lv_opa_t value)
{
    lv_recursive_lock();
    lv_style_set_text_opa(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_text_font(lv_style_t * style, const lv_font_t * value)
{
    lv_recursive_lock();
    lv_style_set_text_font(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_text_letter_space(lv_style_t * style, lv_coord_t value)
{
    lv_recursive_lock();
    lv_style_set_text_letter_space(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_text_line_space(lv_style_t * style, lv_coord_t value)
{
    lv_recursive_lock();
    lv_style_set_text_line_space(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_text_decor(lv_style_t * style, lv_text_decor_t value)
{
    lv_recursive_lock();
    lv_style_set_text_decor(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_text_align(lv_style_t * style, lv_text_align_t value)
{
    lv_recursive_lock();
    lv_style_set_text_align(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_radius(lv_style_t * style, lv_coord_t value)
{
    lv_recursive_lock();
    lv_style_set_radius(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_clip_corner(lv_style_t * style, bool value)
{
    lv_recursive_lock();
    lv_style_set_clip_corner(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_opa(lv_style_t * style, lv_opa_t value)
{
    lv_recursive_lock();
    lv_style_set_opa(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_color_filter_dsc(lv_style_t * style, const lv_color_filter_dsc_t * value)
{
    lv_recursive_lock();
    lv_style_set_color_filter_dsc(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_color_filter_opa(lv_style_t * style, lv_opa_t value)
{
    lv_recursive_lock();
    lv_style_set_color_filter_opa(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_anim(lv_style_t * style, const lv_anim_t * value)
{
    lv_recursive_lock();
    lv_style_set_anim(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_anim_time(lv_style_t * style, uint32_t value)
{
    lv_recursive_lock();
    lv_style_set_anim_time(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_anim_speed(lv_style_t * style, uint32_t value)
{
    lv_recursive_lock();
    lv_style_set_anim_speed(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_transition(lv_style_t * style, const lv_style_transition_dsc_t * value)
{
    lv_recursive_lock();
    lv_style_set_transition(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_blend_mode(lv_style_t * style, lv_blend_mode_t value)
{
    lv_recursive_lock();
    lv_style_set_blend_mode(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_layout(lv_style_t * style, uint16_t value)
{
    lv_recursive_lock();
    lv_style_set_layout(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_base_dir(lv_style_t * style, lv_base_dir_t value)
{
    lv_recursive_lock();
    lv_style_set_base_dir(style, value);
    lv_recursive_unlock();
    
}


static inline void safe_lv_style_set_size(lv_style_t * style, lv_coord_t value)
{
    lv_recursive_lock();
    lv_style_set_size(style, value);
    lv_recursive_unlock();
    
}


static inline void safe_lv_style_set_pad_all(lv_style_t * style, lv_coord_t value)
{
    lv_recursive_lock();
    lv_style_set_pad_all(style, value);
    lv_recursive_unlock();
    
}


static inline void safe_lv_style_set_pad_hor(lv_style_t * style, lv_coord_t value)
{
    lv_recursive_lock();
    lv_style_set_pad_hor(style, value);
    lv_recursive_unlock();
    
}


static inline void safe_lv_style_set_pad_ver(lv_style_t * style, lv_coord_t value)
{
    lv_recursive_lock();
    lv_style_set_pad_ver(style, value);
    lv_recursive_unlock();
    
}


static inline void safe_lv_style_set_pad_gap(lv_style_t * style, lv_coord_t value)
{
    lv_recursive_lock();
    lv_style_set_pad_gap(style, value);
    lv_recursive_unlock();
    
}


static inline bool safe_lv_style_prop_has_flag(lv_style_prop_t prop, uint8_t flag)
{
    lv_recursive_lock();
    bool ret = lv_style_prop_has_flag(prop, flag);
    lv_recursive_unlock();
    return ret;
}


lv_img_dsc_t * safe_lv_img_buf_alloc(lv_coord_t w, lv_coord_t h, lv_img_cf_t cf)
{
    lv_recursive_lock();
    lv_img_dsc_t * ret = lv_img_buf_alloc(w, h, cf);
    lv_recursive_unlock();
    return ret;
}


lv_color_t safe_lv_img_buf_get_px_color(lv_img_dsc_t * dsc, lv_coord_t x, lv_coord_t y, lv_color_t color)
{
    lv_recursive_lock();
    lv_color_t ret = lv_img_buf_get_px_color(dsc, x, y, color);
    lv_recursive_unlock();
    return ret;
}


lv_opa_t safe_lv_img_buf_get_px_alpha(lv_img_dsc_t * dsc, lv_coord_t x, lv_coord_t y)
{
    lv_recursive_lock();
    lv_opa_t ret = lv_img_buf_get_px_alpha(dsc, x, y);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_img_buf_set_px_color(lv_img_dsc_t * dsc, lv_coord_t x, lv_coord_t y, lv_color_t c)
{
    lv_recursive_lock();
    lv_img_buf_set_px_color(dsc, x, y, c);
    lv_recursive_unlock();
    
}


void safe_lv_img_buf_set_px_alpha(lv_img_dsc_t * dsc, lv_coord_t x, lv_coord_t y, lv_opa_t opa)
{
    lv_recursive_lock();
    lv_img_buf_set_px_alpha(dsc, x, y, opa);
    lv_recursive_unlock();
    
}


void safe_lv_img_buf_set_palette(lv_img_dsc_t * dsc, uint8_t id, lv_color_t c)
{
    lv_recursive_lock();
    lv_img_buf_set_palette(dsc, id, c);
    lv_recursive_unlock();
    
}


void safe_lv_img_buf_free(lv_img_dsc_t * dsc)
{
    lv_recursive_lock();
    lv_img_buf_free(dsc);
    lv_recursive_unlock();
    
}


uint32_t safe_lv_img_buf_get_img_size(lv_coord_t w, lv_coord_t h, lv_img_cf_t cf)
{
    lv_recursive_lock();
    uint32_t ret = lv_img_buf_get_img_size(w, h, cf);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_fs_drv_init(lv_fs_drv_t * drv)
{
    lv_recursive_lock();
    lv_fs_drv_init(drv);
    lv_recursive_unlock();
    
}


void safe_lv_fs_drv_register(lv_fs_drv_t * drv)
{
    lv_recursive_lock();
    lv_fs_drv_register(drv);
    lv_recursive_unlock();
    
}


lv_fs_drv_t * safe_lv_fs_get_drv(char letter)
{
    lv_recursive_lock();
    lv_fs_drv_t * ret = lv_fs_get_drv(letter);
    lv_recursive_unlock();
    return ret;
}


bool safe_lv_fs_is_ready(char letter)
{
    lv_recursive_lock();
    bool ret = lv_fs_is_ready(letter);
    lv_recursive_unlock();
    return ret;
}


lv_fs_res_t safe_lv_fs_open(lv_fs_file_t * file_p, const char * path, lv_fs_mode_t mode)
{
    lv_recursive_lock();
    lv_fs_res_t ret = lv_fs_open(file_p, path, mode);
    lv_recursive_unlock();
    return ret;
}


lv_fs_res_t safe_lv_fs_close(lv_fs_file_t * file_p)
{
    lv_recursive_lock();
    lv_fs_res_t ret = lv_fs_close(file_p);
    lv_recursive_unlock();
    return ret;
}


lv_fs_res_t safe_lv_fs_read(lv_fs_file_t * file_p, void * buf, uint32_t btr, uint32_t * br)
{
    lv_recursive_lock();
    lv_fs_res_t ret = lv_fs_read(file_p, buf, btr, br);
    lv_recursive_unlock();
    return ret;
}


lv_fs_res_t safe_lv_fs_write(lv_fs_file_t * file_p, const void * buf, uint32_t btw, uint32_t * bw)
{
    lv_recursive_lock();
    lv_fs_res_t ret = lv_fs_write(file_p, buf, btw, bw);
    lv_recursive_unlock();
    return ret;
}


lv_fs_res_t safe_lv_fs_seek(lv_fs_file_t * file_p, uint32_t pos, lv_fs_whence_t whence)
{
    lv_recursive_lock();
    lv_fs_res_t ret = lv_fs_seek(file_p, pos, whence);
    lv_recursive_unlock();
    return ret;
}


lv_fs_res_t safe_lv_fs_tell(lv_fs_file_t * file_p, uint32_t * pos)
{
    lv_recursive_lock();
    lv_fs_res_t ret = lv_fs_tell(file_p, pos);
    lv_recursive_unlock();
    return ret;
}


lv_fs_res_t safe_lv_fs_dir_open(lv_fs_dir_t * rddir_p, const char * path)
{
    lv_recursive_lock();
    lv_fs_res_t ret = lv_fs_dir_open(rddir_p, path);
    lv_recursive_unlock();
    return ret;
}


lv_fs_res_t safe_lv_fs_dir_read(lv_fs_dir_t * rddir_p, char * fn)
{
    lv_recursive_lock();
    lv_fs_res_t ret = lv_fs_dir_read(rddir_p, fn);
    lv_recursive_unlock();
    return ret;
}


lv_fs_res_t safe_lv_fs_dir_close(lv_fs_dir_t * rddir_p)
{
    lv_recursive_lock();
    lv_fs_res_t ret = lv_fs_dir_close(rddir_p);
    lv_recursive_unlock();
    return ret;
}


char * safe_lv_fs_get_letters(char * buf)
{
    lv_recursive_lock();
    char * ret = lv_fs_get_letters(buf);
    lv_recursive_unlock();
    return ret;
}


const char * safe_lv_fs_get_ext(const char * fn)
{
    lv_recursive_lock();
    char * ret = lv_fs_get_ext(fn);
    lv_recursive_unlock();
    return ret;
}


char * safe_lv_fs_up(char * path)
{
    lv_recursive_lock();
    char * ret = lv_fs_up(path);
    lv_recursive_unlock();
    return ret;
}


const char * safe_lv_fs_get_last(const char * path)
{
    lv_recursive_lock();
    char * ret = lv_fs_get_last(path);
    lv_recursive_unlock();
    return ret;
}


lv_res_t safe_lv_img_decoder_get_info(const void * src, lv_img_header_t * header)
{
    lv_recursive_lock();
    lv_res_t ret = lv_img_decoder_get_info(src, header);
    lv_recursive_unlock();
    return ret;
}


lv_res_t safe_lv_img_decoder_open(lv_img_decoder_dsc_t * dsc, const void * src, lv_color_t color, int32_t frame_id)
{
    lv_recursive_lock();
    lv_res_t ret = lv_img_decoder_open(dsc, src, color, frame_id);
    lv_recursive_unlock();
    return ret;
}


lv_res_t safe_lv_img_decoder_read_line(lv_img_decoder_dsc_t * dsc, lv_coord_t x, lv_coord_t y, lv_coord_t len, uint8_t * buf)
{
    lv_recursive_lock();
    lv_res_t ret = lv_img_decoder_read_line(dsc, x, y, len, buf);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_img_decoder_close(lv_img_decoder_dsc_t * dsc)
{
    lv_recursive_lock();
    lv_img_decoder_close(dsc);
    lv_recursive_unlock();
    
}


lv_img_decoder_t * safe_lv_img_decoder_create(void)
{
    lv_recursive_lock();
    lv_img_decoder_t * ret = lv_img_decoder_create();
    lv_recursive_unlock();
    return ret;
}


void safe_lv_img_decoder_delete(lv_img_decoder_t * decoder)
{
    lv_recursive_lock();
    lv_img_decoder_delete(decoder);
    lv_recursive_unlock();
    
}


void safe_lv_img_decoder_set_info_cb(lv_img_decoder_t * decoder, lv_img_decoder_info_f_t info_cb)
{
    lv_recursive_lock();
    lv_img_decoder_set_info_cb(decoder, info_cb);
    lv_recursive_unlock();
    
}


void safe_lv_img_decoder_set_open_cb(lv_img_decoder_t * decoder, lv_img_decoder_open_f_t open_cb)
{
    lv_recursive_lock();
    lv_img_decoder_set_open_cb(decoder, open_cb);
    lv_recursive_unlock();
    
}


void safe_lv_img_decoder_set_read_line_cb(lv_img_decoder_t * decoder, lv_img_decoder_read_line_f_t read_line_cb)
{
    lv_recursive_lock();
    lv_img_decoder_set_read_line_cb(decoder, read_line_cb);
    lv_recursive_unlock();
    
}


void safe_lv_img_decoder_set_close_cb(lv_img_decoder_t * decoder, lv_img_decoder_close_f_t close_cb)
{
    lv_recursive_lock();
    lv_img_decoder_set_close_cb(decoder, close_cb);
    lv_recursive_unlock();
    
}


lv_res_t safe_lv_img_decoder_built_in_info(lv_img_decoder_t * decoder, const void * src, lv_img_header_t * header)
{
    lv_recursive_lock();
    lv_res_t ret = lv_img_decoder_built_in_info(decoder, src, header);
    lv_recursive_unlock();
    return ret;
}


lv_res_t safe_lv_img_decoder_built_in_open(lv_img_decoder_t * decoder, lv_img_decoder_dsc_t * dsc)
{
    lv_recursive_lock();
    lv_res_t ret = lv_img_decoder_built_in_open(decoder, dsc);
    lv_recursive_unlock();
    return ret;
}


lv_res_t safe_lv_img_decoder_built_in_read_line(lv_img_decoder_t * decoder, lv_img_decoder_dsc_t * dsc, lv_coord_t x, lv_coord_t y, lv_coord_t len, uint8_t * buf)
{
    lv_recursive_lock();
    lv_res_t ret = lv_img_decoder_built_in_read_line(decoder, dsc, x, y, len, buf);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_img_decoder_built_in_close(lv_img_decoder_t * decoder, lv_img_decoder_dsc_t * dsc)
{
    lv_recursive_lock();
    lv_img_decoder_built_in_close(decoder, dsc);
    lv_recursive_unlock();
    
}


void safe_lv_img_cache_set_size(uint16_t new_slot_num)
{
    lv_recursive_lock();
    lv_img_cache_set_size(new_slot_num);
    lv_recursive_unlock();
    
}


void safe_lv_img_cache_invalidate_src(const void * src)
{
    lv_recursive_lock();
    lv_img_cache_invalidate_src(src);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_pos(struct _lv_obj_t * obj, lv_coord_t x, lv_coord_t y)
{
    lv_recursive_lock();
    lv_obj_set_pos(obj, x, y);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_x(struct _lv_obj_t * obj, lv_coord_t x)
{
    lv_recursive_lock();
    lv_obj_set_x(obj, x);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_y(struct _lv_obj_t * obj, lv_coord_t y)
{
    lv_recursive_lock();
    lv_obj_set_y(obj, y);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_size(struct _lv_obj_t * obj, lv_coord_t w, lv_coord_t h)
{
    lv_recursive_lock();
    lv_obj_set_size(obj, w, h);
    lv_recursive_unlock();
    
}


bool safe_lv_obj_refr_size(struct _lv_obj_t * obj)
{
    lv_recursive_lock();
    bool ret = lv_obj_refr_size(obj);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_obj_set_width(struct _lv_obj_t * obj, lv_coord_t w)
{
    lv_recursive_lock();
    lv_obj_set_width(obj, w);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_height(struct _lv_obj_t * obj, lv_coord_t h)
{
    lv_recursive_lock();
    lv_obj_set_height(obj, h);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_content_width(struct _lv_obj_t * obj, lv_coord_t w)
{
    lv_recursive_lock();
    lv_obj_set_content_width(obj, w);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_content_height(struct _lv_obj_t * obj, lv_coord_t h)
{
    lv_recursive_lock();
    lv_obj_set_content_height(obj, h);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_layout(struct _lv_obj_t * obj, uint32_t layout)
{
    lv_recursive_lock();
    lv_obj_set_layout(obj, layout);
    lv_recursive_unlock();
    
}


bool safe_lv_obj_is_layout_positioned(const struct _lv_obj_t * obj)
{
    lv_recursive_lock();
    bool ret = lv_obj_is_layout_positioned(obj);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_obj_mark_layout_as_dirty(struct _lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_obj_mark_layout_as_dirty(obj);
    lv_recursive_unlock();
    
}


void safe_lv_obj_update_layout(const struct _lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_obj_update_layout(obj);
    lv_recursive_unlock();
    
}


uint32_t safe_lv_layout_register(lv_layout_update_cb_t cb, void * user_data)
{
    lv_recursive_lock();
    uint32_t ret = lv_layout_register(cb, user_data);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_obj_set_align(struct _lv_obj_t * obj, lv_align_t align)
{
    lv_recursive_lock();
    lv_obj_set_align(obj, align);
    lv_recursive_unlock();
    
}


void safe_lv_obj_align(struct _lv_obj_t * obj, lv_align_t align, lv_coord_t x_ofs, lv_coord_t y_ofs)
{
    lv_recursive_lock();
    lv_obj_align(obj, align, x_ofs, y_ofs);
    lv_recursive_unlock();
    
}


void safe_lv_obj_align_to(struct _lv_obj_t * obj, const struct _lv_obj_t * base, lv_align_t align, lv_coord_t x_ofs, lv_coord_t y_ofs)
{
    lv_recursive_lock();
    lv_obj_align_to(obj, base, align, x_ofs, y_ofs);
    lv_recursive_unlock();
    
}


static inline void safe_lv_obj_center(struct _lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_obj_center(obj);
    lv_recursive_unlock();
    
}


void safe_lv_obj_get_coords(const struct _lv_obj_t * obj, lv_area_t * coords)
{
    lv_recursive_lock();
    lv_obj_get_coords(obj, coords);
    lv_recursive_unlock();
    
}


lv_coord_t safe_lv_obj_get_x(const struct _lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_x(obj);
    lv_recursive_unlock();
    return ret;
}


lv_coord_t safe_lv_obj_get_x2(const struct _lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_x2(obj);
    lv_recursive_unlock();
    return ret;
}


lv_coord_t safe_lv_obj_get_y(const struct _lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_y(obj);
    lv_recursive_unlock();
    return ret;
}


lv_coord_t safe_lv_obj_get_y2(const struct _lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_y2(obj);
    lv_recursive_unlock();
    return ret;
}


lv_coord_t safe_lv_obj_get_x_aligned(const struct _lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_x_aligned(obj);
    lv_recursive_unlock();
    return ret;
}


lv_coord_t safe_lv_obj_get_y_aligned(const struct _lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_y_aligned(obj);
    lv_recursive_unlock();
    return ret;
}


lv_coord_t safe_lv_obj_get_width(const struct _lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_width(obj);
    lv_recursive_unlock();
    return ret;
}


lv_coord_t safe_lv_obj_get_height(const struct _lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_height(obj);
    lv_recursive_unlock();
    return ret;
}


lv_coord_t safe_lv_obj_get_content_width(const struct _lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_content_width(obj);
    lv_recursive_unlock();
    return ret;
}


lv_coord_t safe_lv_obj_get_content_height(const struct _lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_content_height(obj);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_obj_get_content_coords(const struct _lv_obj_t * obj, lv_area_t * area)
{
    lv_recursive_lock();
    lv_obj_get_content_coords(obj, area);
    lv_recursive_unlock();
    
}


lv_coord_t safe_lv_obj_get_self_width(const struct _lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_self_width(obj);
    lv_recursive_unlock();
    return ret;
}


lv_coord_t safe_lv_obj_get_self_height(const struct _lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_self_height(obj);
    lv_recursive_unlock();
    return ret;
}


bool safe_lv_obj_refresh_self_size(struct _lv_obj_t * obj)
{
    lv_recursive_lock();
    bool ret = lv_obj_refresh_self_size(obj);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_obj_refr_pos(struct _lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_obj_refr_pos(obj);
    lv_recursive_unlock();
    
}


void safe_lv_obj_move_to(struct _lv_obj_t * obj, lv_coord_t x, lv_coord_t y)
{
    lv_recursive_lock();
    lv_obj_move_to(obj, x, y);
    lv_recursive_unlock();
    
}


void safe_lv_obj_move_children_by(struct _lv_obj_t * obj, lv_coord_t x_diff, lv_coord_t y_diff, bool ignore_floating)
{
    lv_recursive_lock();
    lv_obj_move_children_by(obj, x_diff, y_diff, ignore_floating);
    lv_recursive_unlock();
    
}


void safe_lv_obj_transform_point(const struct _lv_obj_t * obj, lv_point_t * p, bool recursive, bool inv)
{
    lv_recursive_lock();
    lv_obj_transform_point(obj, p, recursive, inv);
    lv_recursive_unlock();
    
}


void safe_lv_obj_get_transformed_area(const struct _lv_obj_t * obj, lv_area_t * area, bool recursive, bool inv)
{
    lv_recursive_lock();
    lv_obj_get_transformed_area(obj, area, recursive, inv);
    lv_recursive_unlock();
    
}


void safe_lv_obj_invalidate_area(const struct _lv_obj_t * obj, const lv_area_t * area)
{
    lv_recursive_lock();
    lv_obj_invalidate_area(obj, area);
    lv_recursive_unlock();
    
}


void safe_lv_obj_invalidate(const struct _lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_obj_invalidate(obj);
    lv_recursive_unlock();
    
}


bool safe_lv_obj_area_is_visible(const struct _lv_obj_t * obj, lv_area_t * area)
{
    lv_recursive_lock();
    bool ret = lv_obj_area_is_visible(obj, area);
    lv_recursive_unlock();
    return ret;
}


bool safe_lv_obj_is_visible(const struct _lv_obj_t * obj)
{
    lv_recursive_lock();
    bool ret = lv_obj_is_visible(obj);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_obj_set_ext_click_area(struct _lv_obj_t * obj, lv_coord_t size)
{
    lv_recursive_lock();
    lv_obj_set_ext_click_area(obj, size);
    lv_recursive_unlock();
    
}


void safe_lv_obj_get_click_area(const struct _lv_obj_t * obj, lv_area_t * area)
{
    lv_recursive_lock();
    lv_obj_get_click_area(obj, area);
    lv_recursive_unlock();
    
}


bool safe_lv_obj_hit_test(struct _lv_obj_t * obj, const lv_point_t * point)
{
    lv_recursive_lock();
    bool ret = lv_obj_hit_test(obj, point);
    lv_recursive_unlock();
    return ret;
}


lv_coord_t safe_lv_clamp_width(lv_coord_t width, lv_coord_t min_width, lv_coord_t max_width, lv_coord_t ref_width)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_clamp_width(width, min_width, max_width, ref_width);
    lv_recursive_unlock();
    return ret;
}


lv_coord_t safe_lv_clamp_height(lv_coord_t height, lv_coord_t min_height, lv_coord_t max_height, lv_coord_t ref_height)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_clamp_height(height, min_height, max_height, ref_height);
    lv_recursive_unlock();
    return ret;
}


lv_grad_color_t safe_lv_gradient_calculate(const lv_grad_dsc_t * dsc, lv_coord_t range, lv_coord_t frac)
{
    lv_recursive_lock();
    lv_grad_color_t ret = lv_gradient_calculate(dsc, range, frac);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_gradient_set_cache_size(size_t max_bytes)
{
    lv_recursive_lock();
    lv_gradient_set_cache_size(max_bytes);
    lv_recursive_unlock();
    
}


void safe_lv_gradient_free_cache(void)
{
    lv_recursive_lock();
    lv_gradient_free_cache();
    lv_recursive_unlock();
    
}


lv_grad_t * safe_lv_gradient_get(const lv_grad_dsc_t * gradient, lv_coord_t w, lv_coord_t h)
{
    lv_recursive_lock();
    lv_grad_t * ret = lv_gradient_get(gradient, w, h);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_gradient_cleanup(lv_grad_t * grad)
{
    lv_recursive_lock();
    lv_gradient_cleanup(grad);
    lv_recursive_unlock();
    
}


void safe_lv_draw_rect_dsc_init(lv_draw_rect_dsc_t * dsc)
{
    lv_recursive_lock();
    lv_draw_rect_dsc_init(dsc);
    lv_recursive_unlock();
    
}


void safe_lv_draw_rect(struct _lv_draw_ctx_t * draw_ctx, const lv_draw_rect_dsc_t * dsc, const lv_area_t * coords)
{
    lv_recursive_lock();
    lv_draw_rect(draw_ctx, dsc, coords);
    lv_recursive_unlock();
    
}


void safe_lv_draw_label_dsc_init(lv_draw_label_dsc_t * dsc)
{
    lv_recursive_lock();
    lv_draw_label_dsc_init(dsc);
    lv_recursive_unlock();
    
}


void safe_lv_draw_label(struct _lv_draw_ctx_t * draw_ctx, const lv_draw_label_dsc_t * dsc, const lv_area_t * coords, const char * txt, lv_draw_label_hint_t * hint)
{
    lv_recursive_lock();
    lv_draw_label(draw_ctx, dsc, coords, txt, hint);
    lv_recursive_unlock();
    
}


void safe_lv_draw_letter(struct _lv_draw_ctx_t * draw_ctx, const lv_draw_label_dsc_t * dsc, const lv_point_t * pos_p, uint32_t letter)
{
    lv_recursive_lock();
    lv_draw_letter(draw_ctx, dsc, pos_p, letter);
    lv_recursive_unlock();
    
}


void safe_lv_draw_img_dsc_init(lv_draw_img_dsc_t * dsc)
{
    lv_recursive_lock();
    lv_draw_img_dsc_init(dsc);
    lv_recursive_unlock();
    
}


void safe_lv_draw_img(struct _lv_draw_ctx_t * draw_ctx, const lv_draw_img_dsc_t * dsc, const lv_area_t * coords, const void * src)
{
    lv_recursive_lock();
    lv_draw_img(draw_ctx, dsc, coords, src);
    lv_recursive_unlock();
    
}


void safe_lv_draw_img_decoded(struct _lv_draw_ctx_t * draw_ctx, const lv_draw_img_dsc_t * dsc, const lv_area_t * coords, const uint8_t * map_p, lv_img_cf_t color_format)
{
    lv_recursive_lock();
    lv_draw_img_decoded(draw_ctx, dsc, coords, map_p, color_format);
    lv_recursive_unlock();
    
}


lv_img_src_t safe_lv_img_src_get_type(const void * src)
{
    lv_recursive_lock();
    lv_img_src_t ret = lv_img_src_get_type(src);
    lv_recursive_unlock();
    return ret;
}


uint8_t safe_lv_img_cf_get_px_size(lv_img_cf_t cf)
{
    lv_recursive_lock();
    uint8_t ret = lv_img_cf_get_px_size(cf);
    lv_recursive_unlock();
    return ret;
}


bool safe_lv_img_cf_is_chroma_keyed(lv_img_cf_t cf)
{
    lv_recursive_lock();
    bool ret = lv_img_cf_is_chroma_keyed(cf);
    lv_recursive_unlock();
    return ret;
}


bool safe_lv_img_cf_has_alpha(lv_img_cf_t cf)
{
    lv_recursive_lock();
    bool ret = lv_img_cf_has_alpha(cf);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_draw_line_dsc_init(lv_draw_line_dsc_t * dsc)
{
    lv_recursive_lock();
    lv_draw_line_dsc_init(dsc);
    lv_recursive_unlock();
    
}


void safe_lv_draw_line(struct _lv_draw_ctx_t * draw_ctx, const lv_draw_line_dsc_t * dsc, const lv_point_t * point1, const lv_point_t * point2)
{
    lv_recursive_lock();
    lv_draw_line(draw_ctx, dsc, point1, point2);
    lv_recursive_unlock();
    
}


void safe_lv_draw_polygon(struct _lv_draw_ctx_t * draw_ctx, const lv_draw_rect_dsc_t * draw_dsc, const lv_point_t points[], uint16_t point_cnt)
{
    lv_recursive_lock();
    lv_draw_polygon(draw_ctx, draw_dsc, points, point_cnt);
    lv_recursive_unlock();
    
}


void safe_lv_draw_triangle(struct _lv_draw_ctx_t * draw_ctx, const lv_draw_rect_dsc_t * draw_dsc, const lv_point_t points[])
{
    lv_recursive_lock();
    lv_draw_triangle(draw_ctx, draw_dsc, points);
    lv_recursive_unlock();
    
}


void safe_lv_draw_arc_dsc_init(lv_draw_arc_dsc_t * dsc)
{
    lv_recursive_lock();
    lv_draw_arc_dsc_init(dsc);
    lv_recursive_unlock();
    
}


void safe_lv_draw_arc(struct _lv_draw_ctx_t * draw_ctx, const lv_draw_arc_dsc_t * dsc, const lv_point_t * center, uint16_t radius, uint16_t start_angle, uint16_t end_angle)
{
    lv_recursive_lock();
    lv_draw_arc(draw_ctx, dsc, center, radius, start_angle, end_angle);
    lv_recursive_unlock();
    
}


void safe_lv_draw_arc_get_area(lv_coord_t x, lv_coord_t y, uint16_t radius, uint16_t start_angle, uint16_t end_angle, lv_coord_t w, bool rounded, lv_area_t * area)
{
    lv_recursive_lock();
    lv_draw_arc_get_area(x, y, radius, start_angle, end_angle, w, rounded, area);
    lv_recursive_unlock();
    
}


int16_t safe_lv_draw_mask_add(void * param, void * custom_id)
{
    lv_recursive_lock();
    int16_t ret = lv_draw_mask_add(param, custom_id);
    lv_recursive_unlock();
    return ret;
}


lv_draw_mask_res_t safe_lv_draw_mask_apply(lv_opa_t * mask_buf, lv_coord_t abs_x, lv_coord_t abs_y, lv_coord_t len)
{
    lv_recursive_lock();
    lv_draw_mask_res_t ret = lv_draw_mask_apply(mask_buf, abs_x, abs_y, len);
    lv_recursive_unlock();
    return ret;
}


lv_draw_mask_res_t safe_lv_draw_mask_apply_ids(lv_opa_t * mask_buf, lv_coord_t abs_x, lv_coord_t abs_y, lv_coord_t len, const int16_t * ids, int16_t ids_count)
{
    lv_recursive_lock();
    lv_draw_mask_res_t ret = lv_draw_mask_apply_ids(mask_buf, abs_x, abs_y, len, ids, ids_count);
    lv_recursive_unlock();
    return ret;
}


void * safe_lv_draw_mask_remove_id(int16_t id)
{
    lv_recursive_lock();
    void * ret = lv_draw_mask_remove_id(id);
    lv_recursive_unlock();
    
}


void * safe_lv_draw_mask_remove_custom(void * custom_id)
{
    lv_recursive_lock();
    void * ret = lv_draw_mask_remove_custom(custom_id);
    lv_recursive_unlock();
    
}


void safe_lv_draw_mask_free_param(void * p)
{
    lv_recursive_lock();
    lv_draw_mask_free_param(p);
    lv_recursive_unlock();
    
}


uint8_t safe_lv_draw_mask_get_cnt(void)
{
    lv_recursive_lock();
    uint8_t ret = lv_draw_mask_get_cnt();
    lv_recursive_unlock();
    return ret;
}


bool safe_lv_draw_mask_is_any(const lv_area_t * a)
{
    lv_recursive_lock();
    bool ret = lv_draw_mask_is_any(a);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_draw_mask_line_points_init(lv_draw_mask_line_param_t * param, lv_coord_t p1x, lv_coord_t p1y, lv_coord_t p2x, lv_coord_t p2y, lv_draw_mask_line_side_t side)
{
    lv_recursive_lock();
    lv_draw_mask_line_points_init(param, p1x, p1y, p2x, p2y, side);
    lv_recursive_unlock();
    
}


void safe_lv_draw_mask_line_angle_init(lv_draw_mask_line_param_t * param, lv_coord_t p1x, lv_coord_t py, int16_t angle, lv_draw_mask_line_side_t side)
{
    lv_recursive_lock();
    lv_draw_mask_line_angle_init(param, p1x, py, angle, side);
    lv_recursive_unlock();
    
}


void safe_lv_draw_mask_angle_init(lv_draw_mask_angle_param_t * param, lv_coord_t vertex_x, lv_coord_t vertex_y, lv_coord_t start_angle, lv_coord_t end_angle)
{
    lv_recursive_lock();
    lv_draw_mask_angle_init(param, vertex_x, vertex_y, start_angle, end_angle);
    lv_recursive_unlock();
    
}


void safe_lv_draw_mask_radius_init(lv_draw_mask_radius_param_t * param, const lv_area_t * rect, lv_coord_t radius, bool inv)
{
    lv_recursive_lock();
    lv_draw_mask_radius_init(param, rect, radius, inv);
    lv_recursive_unlock();
    
}


void safe_lv_draw_mask_fade_init(lv_draw_mask_fade_param_t * param, const lv_area_t * coords, lv_opa_t opa_top, lv_coord_t y_top, lv_opa_t opa_bottom, lv_coord_t y_bottom)
{
    lv_recursive_lock();
    lv_draw_mask_fade_init(param, coords, opa_top, y_top, opa_bottom, y_bottom);
    lv_recursive_unlock();
    
}


void safe_lv_draw_mask_map_init(lv_draw_mask_map_param_t * param, const lv_area_t * coords, const lv_opa_t * map)
{
    lv_recursive_lock();
    lv_draw_mask_map_init(param, coords, map);
    lv_recursive_unlock();
    
}


void safe_lv_draw_mask_polygon_init(lv_draw_mask_polygon_param_t * param, const lv_point_t * points, uint16_t point_cnt)
{
    lv_recursive_lock();
    lv_draw_mask_polygon_init(param, points, point_cnt);
    lv_recursive_unlock();
    
}


void safe_lv_draw_transform(struct _lv_draw_ctx_t * draw_ctx, const lv_area_t * dest_area, const void * src_buf, lv_coord_t src_w, lv_coord_t src_h, lv_coord_t src_stride, const lv_draw_img_dsc_t * draw_dsc, lv_img_cf_t cf, lv_color_t * cbuf, lv_opa_t * abuf)
{
    lv_recursive_lock();
    lv_draw_transform(draw_ctx, dest_area, src_buf, src_w, src_h, src_stride, draw_dsc, cf, cbuf, abuf);
    lv_recursive_unlock();
    
}


struct _lv_draw_layer_ctx_t * safe_lv_draw_layer_create(struct _lv_draw_ctx_t * draw_ctx, const lv_area_t * layer_area, lv_draw_layer_flags_t flags)
{
    lv_recursive_lock();
    struct _lv_draw_layer_ctx_t * ret = lv_draw_layer_create(draw_ctx, layer_area, flags);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_draw_layer_adjust(struct _lv_draw_ctx_t * draw_ctx, struct _lv_draw_layer_ctx_t * layer_ctx, lv_draw_layer_flags_t flags)
{
    lv_recursive_lock();
    lv_draw_layer_adjust(draw_ctx, layer_ctx, flags);
    lv_recursive_unlock();
    
}


void safe_lv_draw_layer_blend(struct _lv_draw_ctx_t * draw_ctx, struct _lv_draw_layer_ctx_t * layer_ctx, lv_draw_img_dsc_t * draw_dsc)
{
    lv_recursive_lock();
    lv_draw_layer_blend(draw_ctx, layer_ctx, draw_dsc);
    lv_recursive_unlock();
    
}


void safe_lv_draw_layer_destroy(struct _lv_draw_ctx_t * draw_ctx, struct _lv_draw_layer_ctx_t * layer_ctx)
{
    lv_recursive_lock();
    lv_draw_layer_destroy(draw_ctx, layer_ctx);
    lv_recursive_unlock();
    
}


void safe_lv_draw_init(void)
{
    lv_recursive_lock();
    lv_draw_init();
    lv_recursive_unlock();
    
}


void safe_lv_draw_wait_for_finish(lv_draw_ctx_t * draw_ctx)
{
    lv_recursive_lock();
    lv_draw_wait_for_finish(draw_ctx);
    lv_recursive_unlock();
    
}


void safe_lv_disp_drv_init(lv_disp_drv_t * driver)
{
    lv_recursive_lock();
    lv_disp_drv_init(driver);
    lv_recursive_unlock();
    
}


void safe_lv_disp_draw_buf_init(lv_disp_draw_buf_t * draw_buf, void * buf1, void * buf2, uint32_t size_in_px_cnt)
{
    lv_recursive_lock();
    lv_disp_draw_buf_init(draw_buf, buf1, buf2, size_in_px_cnt);
    lv_recursive_unlock();
    
}


lv_disp_t * safe_lv_disp_drv_register(lv_disp_drv_t * driver)
{
    lv_recursive_lock();
    lv_disp_t * ret = lv_disp_drv_register(driver);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_disp_drv_update(lv_disp_t * disp, lv_disp_drv_t * new_drv)
{
    lv_recursive_lock();
    lv_disp_drv_update(disp, new_drv);
    lv_recursive_unlock();
    
}


void safe_lv_disp_remove(lv_disp_t * disp)
{
    lv_recursive_lock();
    lv_disp_remove(disp);
    lv_recursive_unlock();
    
}


void safe_lv_disp_set_default(lv_disp_t * disp)
{
    lv_recursive_lock();
    lv_disp_set_default(disp);
    lv_recursive_unlock();
    
}


lv_disp_t * safe_lv_disp_get_default(void)
{
    lv_recursive_lock();
    lv_disp_t * ret = lv_disp_get_default();
    lv_recursive_unlock();
    return ret;
}


lv_coord_t safe_lv_disp_get_hor_res(lv_disp_t * disp)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_disp_get_hor_res(disp);
    lv_recursive_unlock();
    return ret;
}


lv_coord_t safe_lv_disp_get_ver_res(lv_disp_t * disp)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_disp_get_ver_res(disp);
    lv_recursive_unlock();
    return ret;
}


lv_coord_t safe_lv_disp_get_physical_hor_res(lv_disp_t * disp)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_disp_get_physical_hor_res(disp);
    lv_recursive_unlock();
    return ret;
}


lv_coord_t safe_lv_disp_get_physical_ver_res(lv_disp_t * disp)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_disp_get_physical_ver_res(disp);
    lv_recursive_unlock();
    return ret;
}


lv_coord_t safe_lv_disp_get_offset_x(lv_disp_t * disp)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_disp_get_offset_x(disp);
    lv_recursive_unlock();
    return ret;
}


lv_coord_t safe_lv_disp_get_offset_y(lv_disp_t * disp)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_disp_get_offset_y(disp);
    lv_recursive_unlock();
    return ret;
}


bool safe_lv_disp_get_antialiasing(lv_disp_t * disp)
{
    lv_recursive_lock();
    bool ret = lv_disp_get_antialiasing(disp);
    lv_recursive_unlock();
    return ret;
}


lv_coord_t safe_lv_disp_get_dpi(const lv_disp_t * disp)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_disp_get_dpi(disp);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_disp_set_rotation(lv_disp_t * disp, lv_disp_rot_t rotation)
{
    lv_recursive_lock();
    lv_disp_set_rotation(disp, rotation);
    lv_recursive_unlock();
    
}


lv_disp_rot_t safe_lv_disp_get_rotation(lv_disp_t * disp)
{
    lv_recursive_lock();
    lv_disp_rot_t ret = lv_disp_get_rotation(disp);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_disp_flush_ready(lv_disp_drv_t * disp_drv)
{
    lv_recursive_lock();
    lv_disp_flush_ready(disp_drv);
    lv_recursive_unlock();
    
}


bool safe_lv_disp_flush_is_last(lv_disp_drv_t * disp_drv)
{
    lv_recursive_lock();
    bool ret = lv_disp_flush_is_last(disp_drv);
    lv_recursive_unlock();
    return ret;
}


lv_disp_t * safe_lv_disp_get_next(lv_disp_t * disp)
{
    lv_recursive_lock();
    lv_disp_t * ret = lv_disp_get_next(disp);
    lv_recursive_unlock();
    return ret;
}


lv_disp_draw_buf_t * safe_lv_disp_get_draw_buf(lv_disp_t * disp)
{
    lv_recursive_lock();
    lv_disp_draw_buf_t * ret = lv_disp_get_draw_buf(disp);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_disp_drv_use_generic_set_px_cb(lv_disp_drv_t * disp_drv, lv_img_cf_t cf)
{
    lv_recursive_lock();
    lv_disp_drv_use_generic_set_px_cb(disp_drv, cf);
    lv_recursive_unlock();
    
}


void safe_lv_indev_drv_init(struct _lv_indev_drv_t * driver)
{
    lv_recursive_lock();
    lv_indev_drv_init(driver);
    lv_recursive_unlock();
    
}


lv_indev_t * safe_lv_indev_drv_register(struct _lv_indev_drv_t * driver)
{
    lv_recursive_lock();
    lv_indev_t * ret = lv_indev_drv_register(driver);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_indev_drv_update(lv_indev_t * indev, struct _lv_indev_drv_t * new_drv)
{
    lv_recursive_lock();
    lv_indev_drv_update(indev, new_drv);
    lv_recursive_unlock();
    
}


void safe_lv_indev_delete(lv_indev_t * indev)
{
    lv_recursive_lock();
    lv_indev_delete(indev);
    lv_recursive_unlock();
    
}


lv_indev_t * safe_lv_indev_get_next(lv_indev_t * indev)
{
    lv_recursive_lock();
    lv_indev_t * ret = lv_indev_get_next(indev);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_obj_del(struct _lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_obj_del(obj);
    lv_recursive_unlock();
    
}


void safe_lv_obj_clean(struct _lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_obj_clean(obj);
    lv_recursive_unlock();
    
}


void safe_lv_obj_del_delayed(struct _lv_obj_t * obj, uint32_t delay_ms)
{
    lv_recursive_lock();
    lv_obj_del_delayed(obj, delay_ms);
    lv_recursive_unlock();
    
}


void safe_lv_obj_del_anim_ready_cb(lv_anim_t * a)
{
    lv_recursive_lock();
    lv_obj_del_anim_ready_cb(a);
    lv_recursive_unlock();
    
}


void safe_lv_obj_del_async(struct _lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_obj_del_async(obj);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_parent(struct _lv_obj_t * obj, struct _lv_obj_t * parent)
{
    lv_recursive_lock();
    lv_obj_set_parent(obj, parent);
    lv_recursive_unlock();
    
}


void safe_lv_obj_swap(struct _lv_obj_t * obj1, struct _lv_obj_t * obj2)
{
    lv_recursive_lock();
    lv_obj_swap(obj1, obj2);
    lv_recursive_unlock();
    
}


void safe_lv_obj_move_to_index(struct _lv_obj_t * obj, int32_t index)
{
    lv_recursive_lock();
    lv_obj_move_to_index(obj, index);
    lv_recursive_unlock();
    
}


struct _lv_obj_t * safe_lv_obj_get_screen(const struct _lv_obj_t * obj)
{
    lv_recursive_lock();
    struct _lv_obj_t * ret = lv_obj_get_screen(obj);
    lv_recursive_unlock();
    return ret;
}


lv_disp_t * safe_lv_obj_get_disp(const struct _lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_disp_t * ret = lv_obj_get_disp(obj);
    lv_recursive_unlock();
    return ret;
}


struct _lv_obj_t * safe_lv_obj_get_parent(const struct _lv_obj_t * obj)
{
    lv_recursive_lock();
    struct _lv_obj_t * ret = lv_obj_get_parent(obj);
    lv_recursive_unlock();
    return ret;
}


struct _lv_obj_t * safe_lv_obj_get_child(const struct _lv_obj_t * obj, int32_t id)
{
    lv_recursive_lock();
    struct _lv_obj_t * ret = lv_obj_get_child(obj, id);
    lv_recursive_unlock();
    return ret;
}


uint32_t safe_lv_obj_get_child_cnt(const struct _lv_obj_t * obj)
{
    lv_recursive_lock();
    uint32_t ret = lv_obj_get_child_cnt(obj);
    lv_recursive_unlock();
    return ret;
}


uint32_t safe_lv_obj_get_index(const struct _lv_obj_t * obj)
{
    lv_recursive_lock();
    uint32_t ret = lv_obj_get_index(obj);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_obj_tree_walk(struct _lv_obj_t * start_obj, lv_obj_tree_walk_cb_t cb, void * user_data)
{
    lv_recursive_lock();
    lv_obj_tree_walk(start_obj, cb, user_data);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_scrollbar_mode(struct _lv_obj_t * obj, lv_scrollbar_mode_t mode)
{
    lv_recursive_lock();
    lv_obj_set_scrollbar_mode(obj, mode);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_scroll_dir(struct _lv_obj_t * obj, lv_dir_t dir)
{
    lv_recursive_lock();
    lv_obj_set_scroll_dir(obj, dir);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_scroll_snap_x(struct _lv_obj_t * obj, lv_scroll_snap_t align)
{
    lv_recursive_lock();
    lv_obj_set_scroll_snap_x(obj, align);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_scroll_snap_y(struct _lv_obj_t * obj, lv_scroll_snap_t align)
{
    lv_recursive_lock();
    lv_obj_set_scroll_snap_y(obj, align);
    lv_recursive_unlock();
    
}


lv_scrollbar_mode_t safe_lv_obj_get_scrollbar_mode(const struct _lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_scrollbar_mode_t ret = lv_obj_get_scrollbar_mode(obj);
    lv_recursive_unlock();
    return ret;
}


lv_dir_t safe_lv_obj_get_scroll_dir(const struct _lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_dir_t ret = lv_obj_get_scroll_dir(obj);
    lv_recursive_unlock();
    return ret;
}


lv_scroll_snap_t safe_lv_obj_get_scroll_snap_x(const struct _lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_scroll_snap_t ret = lv_obj_get_scroll_snap_x(obj);
    lv_recursive_unlock();
    return ret;
}


lv_scroll_snap_t safe_lv_obj_get_scroll_snap_y(const struct _lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_scroll_snap_t ret = lv_obj_get_scroll_snap_y(obj);
    lv_recursive_unlock();
    return ret;
}


lv_coord_t safe_lv_obj_get_scroll_x(const struct _lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_scroll_x(obj);
    lv_recursive_unlock();
    return ret;
}


lv_coord_t safe_lv_obj_get_scroll_y(const struct _lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_scroll_y(obj);
    lv_recursive_unlock();
    return ret;
}


lv_coord_t safe_lv_obj_get_scroll_top(struct _lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_scroll_top(obj);
    lv_recursive_unlock();
    return ret;
}


lv_coord_t safe_lv_obj_get_scroll_bottom(struct _lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_scroll_bottom(obj);
    lv_recursive_unlock();
    return ret;
}


lv_coord_t safe_lv_obj_get_scroll_left(struct _lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_scroll_left(obj);
    lv_recursive_unlock();
    return ret;
}


lv_coord_t safe_lv_obj_get_scroll_right(struct _lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_scroll_right(obj);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_obj_get_scroll_end(struct _lv_obj_t * obj, lv_point_t * end)
{
    lv_recursive_lock();
    lv_obj_get_scroll_end(obj, end);
    lv_recursive_unlock();
    
}


void safe_lv_obj_scroll_by(struct _lv_obj_t * obj, lv_coord_t x, lv_coord_t y, lv_anim_enable_t anim_en)
{
    lv_recursive_lock();
    lv_obj_scroll_by(obj, x, y, anim_en);
    lv_recursive_unlock();
    
}


void safe_lv_obj_scroll_by_bounded(struct _lv_obj_t * obj, lv_coord_t dx, lv_coord_t dy, lv_anim_enable_t anim_en)
{
    lv_recursive_lock();
    lv_obj_scroll_by_bounded(obj, dx, dy, anim_en);
    lv_recursive_unlock();
    
}


void safe_lv_obj_scroll_to(struct _lv_obj_t * obj, lv_coord_t x, lv_coord_t y, lv_anim_enable_t anim_en)
{
    lv_recursive_lock();
    lv_obj_scroll_to(obj, x, y, anim_en);
    lv_recursive_unlock();
    
}


void safe_lv_obj_scroll_to_x(struct _lv_obj_t * obj, lv_coord_t x, lv_anim_enable_t anim_en)
{
    lv_recursive_lock();
    lv_obj_scroll_to_x(obj, x, anim_en);
    lv_recursive_unlock();
    
}


void safe_lv_obj_scroll_to_y(struct _lv_obj_t * obj, lv_coord_t y, lv_anim_enable_t anim_en)
{
    lv_recursive_lock();
    lv_obj_scroll_to_y(obj, y, anim_en);
    lv_recursive_unlock();
    
}


void safe_lv_obj_scroll_to_view(struct _lv_obj_t * obj, lv_anim_enable_t anim_en)
{
    lv_recursive_lock();
    lv_obj_scroll_to_view(obj, anim_en);
    lv_recursive_unlock();
    
}


void safe_lv_obj_scroll_to_view_recursive(struct _lv_obj_t * obj, lv_anim_enable_t anim_en)
{
    lv_recursive_lock();
    lv_obj_scroll_to_view_recursive(obj, anim_en);
    lv_recursive_unlock();
    
}


bool safe_lv_obj_is_scrolling(const struct _lv_obj_t * obj)
{
    lv_recursive_lock();
    bool ret = lv_obj_is_scrolling(obj);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_obj_update_snap(struct _lv_obj_t * obj, lv_anim_enable_t anim_en)
{
    lv_recursive_lock();
    lv_obj_update_snap(obj, anim_en);
    lv_recursive_unlock();
    
}


void safe_lv_obj_get_scrollbar_area(struct _lv_obj_t * obj, lv_area_t * hor, lv_area_t * ver)
{
    lv_recursive_lock();
    lv_obj_get_scrollbar_area(obj, hor, ver);
    lv_recursive_unlock();
    
}


void safe_lv_obj_scrollbar_invalidate(struct _lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_obj_scrollbar_invalidate(obj);
    lv_recursive_unlock();
    
}


void safe_lv_obj_readjust_scroll(struct _lv_obj_t * obj, lv_anim_enable_t anim_en)
{
    lv_recursive_lock();
    lv_obj_readjust_scroll(obj, anim_en);
    lv_recursive_unlock();
    
}


void safe_lv_obj_add_style(struct _lv_obj_t * obj, lv_style_t * style, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_add_style(obj, style, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_remove_style(struct _lv_obj_t * obj, lv_style_t * style, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_remove_style(obj, style, selector);
    lv_recursive_unlock();
    
}


static inline void safe_lv_obj_remove_style_all(struct _lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_obj_remove_style_all(obj);
    lv_recursive_unlock();
    
}


void safe_lv_obj_report_style_change(lv_style_t * style)
{
    lv_recursive_lock();
    lv_obj_report_style_change(style);
    lv_recursive_unlock();
    
}


void safe_lv_obj_refresh_style(struct _lv_obj_t * obj, lv_part_t part, lv_style_prop_t prop)
{
    lv_recursive_lock();
    lv_obj_refresh_style(obj, part, prop);
    lv_recursive_unlock();
    
}


void safe_lv_obj_enable_style_refresh(bool en)
{
    lv_recursive_lock();
    lv_obj_enable_style_refresh(en);
    lv_recursive_unlock();
    
}


lv_style_value_t safe_lv_obj_get_style_prop(const struct _lv_obj_t * obj, lv_part_t part, lv_style_prop_t prop)
{
    lv_recursive_lock();
    lv_style_value_t ret = lv_obj_get_style_prop(obj, part, prop);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_obj_set_local_style_prop(struct _lv_obj_t * obj, lv_style_prop_t prop, lv_style_value_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_local_style_prop(obj, prop, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_local_style_prop_meta(struct _lv_obj_t * obj, lv_style_prop_t prop, uint16_t meta, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_local_style_prop_meta(obj, prop, meta, selector);
    lv_recursive_unlock();
    
}


lv_style_res_t safe_lv_obj_get_local_style_prop(struct _lv_obj_t * obj, lv_style_prop_t prop, lv_style_value_t * value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_style_res_t ret = lv_obj_get_local_style_prop(obj, prop, value, selector);
    lv_recursive_unlock();
    return ret;
}


bool safe_lv_obj_remove_local_style_prop(struct _lv_obj_t * obj, lv_style_prop_t prop, lv_style_selector_t selector)
{
    lv_recursive_lock();
    bool ret = lv_obj_remove_local_style_prop(obj, prop, selector);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_obj_fade_in(struct _lv_obj_t * obj, uint32_t time, uint32_t delay)
{
    lv_recursive_lock();
    lv_obj_fade_in(obj, time, delay);
    lv_recursive_unlock();
    
}


void safe_lv_obj_fade_out(struct _lv_obj_t * obj, uint32_t time, uint32_t delay)
{
    lv_recursive_lock();
    lv_obj_fade_out(obj, time, delay);
    lv_recursive_unlock();
    
}


lv_state_t safe_lv_obj_style_get_selector_state(lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_state_t ret = lv_obj_style_get_selector_state(selector);
    lv_recursive_unlock();
    return ret;
}


lv_part_t safe_lv_obj_style_get_selector_part(lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_part_t ret = lv_obj_style_get_selector_part(selector);
    lv_recursive_unlock();
    return ret;
}


static inline lv_coord_t safe_lv_obj_get_style_width(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_style_width(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_coord_t safe_lv_obj_get_style_min_width(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_style_min_width(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_coord_t safe_lv_obj_get_style_max_width(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_style_max_width(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_coord_t safe_lv_obj_get_style_height(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_style_height(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_coord_t safe_lv_obj_get_style_min_height(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_style_min_height(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_coord_t safe_lv_obj_get_style_max_height(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_style_max_height(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_coord_t safe_lv_obj_get_style_x(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_style_x(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_coord_t safe_lv_obj_get_style_y(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_style_y(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_align_t safe_lv_obj_get_style_align(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_align_t ret = lv_obj_get_style_align(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_coord_t safe_lv_obj_get_style_transform_width(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_style_transform_width(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_coord_t safe_lv_obj_get_style_transform_height(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_style_transform_height(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_coord_t safe_lv_obj_get_style_translate_x(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_style_translate_x(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_coord_t safe_lv_obj_get_style_translate_y(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_style_translate_y(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_coord_t safe_lv_obj_get_style_transform_zoom(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_style_transform_zoom(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_coord_t safe_lv_obj_get_style_transform_angle(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_style_transform_angle(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_coord_t safe_lv_obj_get_style_transform_pivot_x(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_style_transform_pivot_x(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_coord_t safe_lv_obj_get_style_transform_pivot_y(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_style_transform_pivot_y(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_coord_t safe_lv_obj_get_style_pad_top(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_style_pad_top(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_coord_t safe_lv_obj_get_style_pad_bottom(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_style_pad_bottom(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_coord_t safe_lv_obj_get_style_pad_left(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_style_pad_left(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_coord_t safe_lv_obj_get_style_pad_right(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_style_pad_right(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_coord_t safe_lv_obj_get_style_pad_row(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_style_pad_row(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_coord_t safe_lv_obj_get_style_pad_column(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_style_pad_column(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_color_t safe_lv_obj_get_style_bg_color(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_color_t ret = lv_obj_get_style_bg_color(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_color_t safe_lv_obj_get_style_bg_color_filtered(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_color_t ret = lv_obj_get_style_bg_color_filtered(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_opa_t safe_lv_obj_get_style_bg_opa(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_opa_t ret = lv_obj_get_style_bg_opa(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_color_t safe_lv_obj_get_style_bg_grad_color(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_color_t ret = lv_obj_get_style_bg_grad_color(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_color_t safe_lv_obj_get_style_bg_grad_color_filtered(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_color_t ret = lv_obj_get_style_bg_grad_color_filtered(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_grad_dir_t safe_lv_obj_get_style_bg_grad_dir(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_grad_dir_t ret = lv_obj_get_style_bg_grad_dir(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_coord_t safe_lv_obj_get_style_bg_main_stop(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_style_bg_main_stop(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_coord_t safe_lv_obj_get_style_bg_grad_stop(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_style_bg_grad_stop(obj, part);
    lv_recursive_unlock();
    return ret;
}


const static inline lv_grad_dsc_t * safe_lv_obj_get_style_bg_grad(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_grad_dsc_t * ret = lv_obj_get_style_bg_grad(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_dither_mode_t safe_lv_obj_get_style_bg_dither_mode(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_dither_mode_t ret = lv_obj_get_style_bg_dither_mode(obj, part);
    lv_recursive_unlock();
    return ret;
}


const static inline void * safe_lv_obj_get_style_bg_img_src(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    void * ret = lv_obj_get_style_bg_img_src(obj, part);
    lv_recursive_unlock();
    
}


static inline lv_opa_t safe_lv_obj_get_style_bg_img_opa(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_opa_t ret = lv_obj_get_style_bg_img_opa(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_color_t safe_lv_obj_get_style_bg_img_recolor(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_color_t ret = lv_obj_get_style_bg_img_recolor(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_color_t safe_lv_obj_get_style_bg_img_recolor_filtered(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_color_t ret = lv_obj_get_style_bg_img_recolor_filtered(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_opa_t safe_lv_obj_get_style_bg_img_recolor_opa(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_opa_t ret = lv_obj_get_style_bg_img_recolor_opa(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline bool safe_lv_obj_get_style_bg_img_tiled(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    bool ret = lv_obj_get_style_bg_img_tiled(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_color_t safe_lv_obj_get_style_border_color(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_color_t ret = lv_obj_get_style_border_color(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_color_t safe_lv_obj_get_style_border_color_filtered(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_color_t ret = lv_obj_get_style_border_color_filtered(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_opa_t safe_lv_obj_get_style_border_opa(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_opa_t ret = lv_obj_get_style_border_opa(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_coord_t safe_lv_obj_get_style_border_width(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_style_border_width(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_border_side_t safe_lv_obj_get_style_border_side(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_border_side_t ret = lv_obj_get_style_border_side(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline bool safe_lv_obj_get_style_border_post(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    bool ret = lv_obj_get_style_border_post(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_coord_t safe_lv_obj_get_style_outline_width(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_style_outline_width(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_color_t safe_lv_obj_get_style_outline_color(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_color_t ret = lv_obj_get_style_outline_color(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_color_t safe_lv_obj_get_style_outline_color_filtered(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_color_t ret = lv_obj_get_style_outline_color_filtered(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_opa_t safe_lv_obj_get_style_outline_opa(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_opa_t ret = lv_obj_get_style_outline_opa(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_coord_t safe_lv_obj_get_style_outline_pad(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_style_outline_pad(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_coord_t safe_lv_obj_get_style_shadow_width(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_style_shadow_width(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_coord_t safe_lv_obj_get_style_shadow_ofs_x(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_style_shadow_ofs_x(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_coord_t safe_lv_obj_get_style_shadow_ofs_y(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_style_shadow_ofs_y(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_coord_t safe_lv_obj_get_style_shadow_spread(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_style_shadow_spread(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_color_t safe_lv_obj_get_style_shadow_color(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_color_t ret = lv_obj_get_style_shadow_color(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_color_t safe_lv_obj_get_style_shadow_color_filtered(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_color_t ret = lv_obj_get_style_shadow_color_filtered(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_opa_t safe_lv_obj_get_style_shadow_opa(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_opa_t ret = lv_obj_get_style_shadow_opa(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_opa_t safe_lv_obj_get_style_img_opa(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_opa_t ret = lv_obj_get_style_img_opa(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_color_t safe_lv_obj_get_style_img_recolor(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_color_t ret = lv_obj_get_style_img_recolor(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_color_t safe_lv_obj_get_style_img_recolor_filtered(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_color_t ret = lv_obj_get_style_img_recolor_filtered(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_opa_t safe_lv_obj_get_style_img_recolor_opa(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_opa_t ret = lv_obj_get_style_img_recolor_opa(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_coord_t safe_lv_obj_get_style_line_width(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_style_line_width(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_coord_t safe_lv_obj_get_style_line_dash_width(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_style_line_dash_width(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_coord_t safe_lv_obj_get_style_line_dash_gap(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_style_line_dash_gap(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline bool safe_lv_obj_get_style_line_rounded(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    bool ret = lv_obj_get_style_line_rounded(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_color_t safe_lv_obj_get_style_line_color(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_color_t ret = lv_obj_get_style_line_color(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_color_t safe_lv_obj_get_style_line_color_filtered(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_color_t ret = lv_obj_get_style_line_color_filtered(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_opa_t safe_lv_obj_get_style_line_opa(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_opa_t ret = lv_obj_get_style_line_opa(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_coord_t safe_lv_obj_get_style_arc_width(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_style_arc_width(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline bool safe_lv_obj_get_style_arc_rounded(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    bool ret = lv_obj_get_style_arc_rounded(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_color_t safe_lv_obj_get_style_arc_color(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_color_t ret = lv_obj_get_style_arc_color(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_color_t safe_lv_obj_get_style_arc_color_filtered(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_color_t ret = lv_obj_get_style_arc_color_filtered(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_opa_t safe_lv_obj_get_style_arc_opa(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_opa_t ret = lv_obj_get_style_arc_opa(obj, part);
    lv_recursive_unlock();
    return ret;
}


const static inline void * safe_lv_obj_get_style_arc_img_src(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    void * ret = lv_obj_get_style_arc_img_src(obj, part);
    lv_recursive_unlock();
    
}


static inline lv_color_t safe_lv_obj_get_style_text_color(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_color_t ret = lv_obj_get_style_text_color(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_color_t safe_lv_obj_get_style_text_color_filtered(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_color_t ret = lv_obj_get_style_text_color_filtered(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_opa_t safe_lv_obj_get_style_text_opa(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_opa_t ret = lv_obj_get_style_text_opa(obj, part);
    lv_recursive_unlock();
    return ret;
}


const static inline lv_font_t * safe_lv_obj_get_style_text_font(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_font_t * ret = lv_obj_get_style_text_font(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_coord_t safe_lv_obj_get_style_text_letter_space(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_style_text_letter_space(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_coord_t safe_lv_obj_get_style_text_line_space(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_style_text_line_space(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_text_decor_t safe_lv_obj_get_style_text_decor(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_text_decor_t ret = lv_obj_get_style_text_decor(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_text_align_t safe_lv_obj_get_style_text_align(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_text_align_t ret = lv_obj_get_style_text_align(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_coord_t safe_lv_obj_get_style_radius(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_style_radius(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline bool safe_lv_obj_get_style_clip_corner(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    bool ret = lv_obj_get_style_clip_corner(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_opa_t safe_lv_obj_get_style_opa(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_opa_t ret = lv_obj_get_style_opa(obj, part);
    lv_recursive_unlock();
    return ret;
}


const static inline lv_color_filter_dsc_t * safe_lv_obj_get_style_color_filter_dsc(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_color_filter_dsc_t * ret = lv_obj_get_style_color_filter_dsc(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_opa_t safe_lv_obj_get_style_color_filter_opa(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_opa_t ret = lv_obj_get_style_color_filter_opa(obj, part);
    lv_recursive_unlock();
    return ret;
}


const static inline lv_anim_t * safe_lv_obj_get_style_anim(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_anim_t * ret = lv_obj_get_style_anim(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline uint32_t safe_lv_obj_get_style_anim_time(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    uint32_t ret = lv_obj_get_style_anim_time(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline uint32_t safe_lv_obj_get_style_anim_speed(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    uint32_t ret = lv_obj_get_style_anim_speed(obj, part);
    lv_recursive_unlock();
    return ret;
}


const static inline lv_style_transition_dsc_t * safe_lv_obj_get_style_transition(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_style_transition_dsc_t * ret = lv_obj_get_style_transition(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_blend_mode_t safe_lv_obj_get_style_blend_mode(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_blend_mode_t ret = lv_obj_get_style_blend_mode(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline uint16_t safe_lv_obj_get_style_layout(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    uint16_t ret = lv_obj_get_style_layout(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_base_dir_t safe_lv_obj_get_style_base_dir(const struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_base_dir_t ret = lv_obj_get_style_base_dir(obj, part);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_obj_set_style_width(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_width(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_min_width(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_min_width(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_max_width(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_max_width(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_height(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_height(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_min_height(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_min_height(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_max_height(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_max_height(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_x(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_x(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_y(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_y(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_align(struct _lv_obj_t * obj, lv_align_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_align(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_transform_width(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_transform_width(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_transform_height(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_transform_height(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_translate_x(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_translate_x(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_translate_y(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_translate_y(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_transform_zoom(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_transform_zoom(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_transform_angle(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_transform_angle(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_transform_pivot_x(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_transform_pivot_x(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_transform_pivot_y(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_transform_pivot_y(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_pad_top(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_pad_top(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_pad_bottom(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_pad_bottom(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_pad_left(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_pad_left(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_pad_right(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_pad_right(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_pad_row(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_pad_row(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_pad_column(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_pad_column(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_bg_color(struct _lv_obj_t * obj, lv_color_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_bg_color(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_bg_opa(struct _lv_obj_t * obj, lv_opa_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_bg_opa(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_bg_grad_color(struct _lv_obj_t * obj, lv_color_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_bg_grad_color(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_bg_grad_dir(struct _lv_obj_t * obj, lv_grad_dir_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_bg_grad_dir(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_bg_main_stop(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_bg_main_stop(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_bg_grad_stop(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_bg_grad_stop(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_bg_grad(struct _lv_obj_t * obj, const lv_grad_dsc_t * value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_bg_grad(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_bg_dither_mode(struct _lv_obj_t * obj, lv_dither_mode_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_bg_dither_mode(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_bg_img_src(struct _lv_obj_t * obj, const void * value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_bg_img_src(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_bg_img_opa(struct _lv_obj_t * obj, lv_opa_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_bg_img_opa(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_bg_img_recolor(struct _lv_obj_t * obj, lv_color_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_bg_img_recolor(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_bg_img_recolor_opa(struct _lv_obj_t * obj, lv_opa_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_bg_img_recolor_opa(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_bg_img_tiled(struct _lv_obj_t * obj, bool value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_bg_img_tiled(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_border_color(struct _lv_obj_t * obj, lv_color_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_border_color(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_border_opa(struct _lv_obj_t * obj, lv_opa_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_border_opa(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_border_width(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_border_width(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_border_side(struct _lv_obj_t * obj, lv_border_side_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_border_side(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_border_post(struct _lv_obj_t * obj, bool value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_border_post(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_outline_width(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_outline_width(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_outline_color(struct _lv_obj_t * obj, lv_color_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_outline_color(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_outline_opa(struct _lv_obj_t * obj, lv_opa_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_outline_opa(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_outline_pad(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_outline_pad(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_shadow_width(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_shadow_width(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_shadow_ofs_x(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_shadow_ofs_x(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_shadow_ofs_y(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_shadow_ofs_y(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_shadow_spread(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_shadow_spread(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_shadow_color(struct _lv_obj_t * obj, lv_color_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_shadow_color(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_shadow_opa(struct _lv_obj_t * obj, lv_opa_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_shadow_opa(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_img_opa(struct _lv_obj_t * obj, lv_opa_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_img_opa(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_img_recolor(struct _lv_obj_t * obj, lv_color_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_img_recolor(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_img_recolor_opa(struct _lv_obj_t * obj, lv_opa_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_img_recolor_opa(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_line_width(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_line_width(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_line_dash_width(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_line_dash_width(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_line_dash_gap(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_line_dash_gap(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_line_rounded(struct _lv_obj_t * obj, bool value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_line_rounded(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_line_color(struct _lv_obj_t * obj, lv_color_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_line_color(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_line_opa(struct _lv_obj_t * obj, lv_opa_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_line_opa(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_arc_width(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_arc_width(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_arc_rounded(struct _lv_obj_t * obj, bool value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_arc_rounded(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_arc_color(struct _lv_obj_t * obj, lv_color_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_arc_color(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_arc_opa(struct _lv_obj_t * obj, lv_opa_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_arc_opa(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_arc_img_src(struct _lv_obj_t * obj, const void * value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_arc_img_src(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_text_color(struct _lv_obj_t * obj, lv_color_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_text_color(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_text_opa(struct _lv_obj_t * obj, lv_opa_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_text_opa(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_text_font(struct _lv_obj_t * obj, const lv_font_t * value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_text_font(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_text_letter_space(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_text_letter_space(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_text_line_space(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_text_line_space(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_text_decor(struct _lv_obj_t * obj, lv_text_decor_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_text_decor(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_text_align(struct _lv_obj_t * obj, lv_text_align_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_text_align(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_radius(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_radius(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_clip_corner(struct _lv_obj_t * obj, bool value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_clip_corner(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_opa(struct _lv_obj_t * obj, lv_opa_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_opa(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_color_filter_dsc(struct _lv_obj_t * obj, const lv_color_filter_dsc_t * value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_color_filter_dsc(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_color_filter_opa(struct _lv_obj_t * obj, lv_opa_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_color_filter_opa(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_anim(struct _lv_obj_t * obj, const lv_anim_t * value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_anim(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_anim_time(struct _lv_obj_t * obj, uint32_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_anim_time(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_anim_speed(struct _lv_obj_t * obj, uint32_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_anim_speed(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_transition(struct _lv_obj_t * obj, const lv_style_transition_dsc_t * value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_transition(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_blend_mode(struct _lv_obj_t * obj, lv_blend_mode_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_blend_mode(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_layout(struct _lv_obj_t * obj, uint16_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_layout(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_base_dir(struct _lv_obj_t * obj, lv_base_dir_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_base_dir(obj, value, selector);
    lv_recursive_unlock();
    
}


static inline void safe_lv_obj_set_style_pad_all(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_pad_all(obj, value, selector);
    lv_recursive_unlock();
    
}


static inline void safe_lv_obj_set_style_pad_hor(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_pad_hor(obj, value, selector);
    lv_recursive_unlock();
    
}


static inline void safe_lv_obj_set_style_pad_ver(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_pad_ver(obj, value, selector);
    lv_recursive_unlock();
    
}


static inline void safe_lv_obj_set_style_pad_gap(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_pad_gap(obj, value, selector);
    lv_recursive_unlock();
    
}


static inline void safe_lv_obj_set_style_size(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_size(obj, value, selector);
    lv_recursive_unlock();
    
}


lv_text_align_t safe_lv_obj_calculate_style_text_align(const struct _lv_obj_t * obj, lv_part_t part, const char * txt)
{
    lv_recursive_lock();
    lv_text_align_t ret = lv_obj_calculate_style_text_align(obj, part, txt);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_obj_init_draw_rect_dsc(struct _lv_obj_t * obj, uint32_t part, lv_draw_rect_dsc_t * draw_dsc)
{
    lv_recursive_lock();
    lv_obj_init_draw_rect_dsc(obj, part, draw_dsc);
    lv_recursive_unlock();
    
}


void safe_lv_obj_init_draw_label_dsc(struct _lv_obj_t * obj, uint32_t part, lv_draw_label_dsc_t * draw_dsc)
{
    lv_recursive_lock();
    lv_obj_init_draw_label_dsc(obj, part, draw_dsc);
    lv_recursive_unlock();
    
}


void safe_lv_obj_init_draw_img_dsc(struct _lv_obj_t * obj, uint32_t part, lv_draw_img_dsc_t * draw_dsc)
{
    lv_recursive_lock();
    lv_obj_init_draw_img_dsc(obj, part, draw_dsc);
    lv_recursive_unlock();
    
}


void safe_lv_obj_init_draw_line_dsc(struct _lv_obj_t * obj, uint32_t part, lv_draw_line_dsc_t * draw_dsc)
{
    lv_recursive_lock();
    lv_obj_init_draw_line_dsc(obj, part, draw_dsc);
    lv_recursive_unlock();
    
}


void safe_lv_obj_init_draw_arc_dsc(struct _lv_obj_t * obj, uint32_t part, lv_draw_arc_dsc_t * draw_dsc)
{
    lv_recursive_lock();
    lv_obj_init_draw_arc_dsc(obj, part, draw_dsc);
    lv_recursive_unlock();
    
}


lv_coord_t safe_lv_obj_calculate_ext_draw_size(struct _lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_calculate_ext_draw_size(obj, part);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_obj_draw_dsc_init(lv_obj_draw_part_dsc_t * dsc, lv_draw_ctx_t * draw_ctx)
{
    lv_recursive_lock();
    lv_obj_draw_dsc_init(dsc, draw_ctx);
    lv_recursive_unlock();
    
}


bool safe_lv_obj_draw_part_check_type(lv_obj_draw_part_dsc_t * dsc, const struct _lv_obj_class_t * class_p, uint32_t type)
{
    lv_recursive_lock();
    bool ret = lv_obj_draw_part_check_type(dsc, class_p, type);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_obj_refresh_ext_draw_size(struct _lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_obj_refresh_ext_draw_size(obj);
    lv_recursive_unlock();
    
}


struct _lv_obj_t * safe_lv_obj_class_create_obj(const struct _lv_obj_class_t * class_p, struct _lv_obj_t * parent)
{
    lv_recursive_lock();
    struct _lv_obj_t * ret = lv_obj_class_create_obj(class_p, parent);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_obj_class_init_obj(struct _lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_obj_class_init_obj(obj);
    lv_recursive_unlock();
    
}


bool safe_lv_obj_is_editable(struct _lv_obj_t * obj)
{
    lv_recursive_lock();
    bool ret = lv_obj_is_editable(obj);
    lv_recursive_unlock();
    return ret;
}


bool safe_lv_obj_is_group_def(struct _lv_obj_t * obj)
{
    lv_recursive_lock();
    bool ret = lv_obj_is_group_def(obj);
    lv_recursive_unlock();
    return ret;
}


lv_res_t safe_lv_event_send(struct _lv_obj_t * obj, lv_event_code_t event_code, void * param)
{
    lv_recursive_lock();
    lv_res_t ret = lv_event_send(obj, event_code, param);
    lv_recursive_unlock();
    return ret;
}


lv_res_t safe_lv_obj_event_base(const lv_obj_class_t * class_p, lv_event_t * e)
{
    lv_recursive_lock();
    lv_res_t ret = lv_obj_event_base(class_p, e);
    lv_recursive_unlock();
    return ret;
}


struct _lv_obj_t * safe_lv_event_get_target(lv_event_t * e)
{
    lv_recursive_lock();
    struct _lv_obj_t * ret = lv_event_get_target(e);
    lv_recursive_unlock();
    return ret;
}


struct _lv_obj_t * safe_lv_event_get_current_target(lv_event_t * e)
{
    lv_recursive_lock();
    struct _lv_obj_t * ret = lv_event_get_current_target(e);
    lv_recursive_unlock();
    return ret;
}


lv_event_code_t safe_lv_event_get_code(lv_event_t * e)
{
    lv_recursive_lock();
    lv_event_code_t ret = lv_event_get_code(e);
    lv_recursive_unlock();
    return ret;
}


void * safe_lv_event_get_param(lv_event_t * e)
{
    lv_recursive_lock();
    void * ret = lv_event_get_param(e);
    lv_recursive_unlock();
    
}


void * safe_lv_event_get_user_data(lv_event_t * e)
{
    lv_recursive_lock();
    void * ret = lv_event_get_user_data(e);
    lv_recursive_unlock();
    
}


void safe_lv_event_stop_bubbling(lv_event_t * e)
{
    lv_recursive_lock();
    lv_event_stop_bubbling(e);
    lv_recursive_unlock();
    
}


void safe_lv_event_stop_processing(lv_event_t * e)
{
    lv_recursive_lock();
    lv_event_stop_processing(e);
    lv_recursive_unlock();
    
}


uint32_t safe_lv_event_register_id(void)
{
    lv_recursive_lock();
    uint32_t ret = lv_event_register_id();
    lv_recursive_unlock();
    return ret;
}


struct _lv_event_dsc_t * safe_lv_obj_add_event_cb(struct _lv_obj_t * obj, lv_event_cb_t event_cb, lv_event_code_t filter, void * user_data)
{
    lv_recursive_lock();
    struct _lv_event_dsc_t * ret = lv_obj_add_event_cb(obj, event_cb, filter, user_data);
    lv_recursive_unlock();
    return ret;
}


bool safe_lv_obj_remove_event_cb(struct _lv_obj_t * obj, lv_event_cb_t event_cb)
{
    lv_recursive_lock();
    bool ret = lv_obj_remove_event_cb(obj, event_cb);
    lv_recursive_unlock();
    return ret;
}


bool safe_lv_obj_remove_event_cb_with_user_data(struct _lv_obj_t * obj, lv_event_cb_t event_cb, const void * event_user_data)
{
    lv_recursive_lock();
    bool ret = lv_obj_remove_event_cb_with_user_data(obj, event_cb, event_user_data);
    lv_recursive_unlock();
    return ret;
}


bool safe_lv_obj_remove_event_dsc(struct _lv_obj_t * obj, struct _lv_event_dsc_t * event_dsc)
{
    lv_recursive_lock();
    bool ret = lv_obj_remove_event_dsc(obj, event_dsc);
    lv_recursive_unlock();
    return ret;
}


void * safe_lv_obj_get_event_user_data(struct _lv_obj_t * obj, lv_event_cb_t event_cb)
{
    lv_recursive_lock();
    void * ret = lv_obj_get_event_user_data(obj, event_cb);
    lv_recursive_unlock();
    
}


lv_indev_t * safe_lv_event_get_indev(lv_event_t * e)
{
    lv_recursive_lock();
    lv_indev_t * ret = lv_event_get_indev(e);
    lv_recursive_unlock();
    return ret;
}


lv_obj_draw_part_dsc_t * safe_lv_event_get_draw_part_dsc(lv_event_t * e)
{
    lv_recursive_lock();
    lv_obj_draw_part_dsc_t * ret = lv_event_get_draw_part_dsc(e);
    lv_recursive_unlock();
    return ret;
}


lv_draw_ctx_t * safe_lv_event_get_draw_ctx(lv_event_t * e)
{
    lv_recursive_lock();
    lv_draw_ctx_t * ret = lv_event_get_draw_ctx(e);
    lv_recursive_unlock();
    return ret;
}


const lv_area_t * safe_lv_event_get_old_size(lv_event_t * e)
{
    lv_recursive_lock();
    lv_area_t * ret = lv_event_get_old_size(e);
    lv_recursive_unlock();
    return ret;
}


uint32_t safe_lv_event_get_key(lv_event_t * e)
{
    lv_recursive_lock();
    uint32_t ret = lv_event_get_key(e);
    lv_recursive_unlock();
    return ret;
}


lv_anim_t * safe_lv_event_get_scroll_anim(lv_event_t * e)
{
    lv_recursive_lock();
    lv_anim_t * ret = lv_event_get_scroll_anim(e);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_event_set_ext_draw_size(lv_event_t * e, lv_coord_t size)
{
    lv_recursive_lock();
    lv_event_set_ext_draw_size(e, size);
    lv_recursive_unlock();
    
}


lv_point_t * safe_lv_event_get_self_size_info(lv_event_t * e)
{
    lv_recursive_lock();
    lv_point_t * ret = lv_event_get_self_size_info(e);
    lv_recursive_unlock();
    return ret;
}


lv_hit_test_info_t * safe_lv_event_get_hit_test_info(lv_event_t * e)
{
    lv_recursive_lock();
    lv_hit_test_info_t * ret = lv_event_get_hit_test_info(e);
    lv_recursive_unlock();
    return ret;
}


const lv_area_t * safe_lv_event_get_cover_area(lv_event_t * e)
{
    lv_recursive_lock();
    lv_area_t * ret = lv_event_get_cover_area(e);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_event_set_cover_res(lv_event_t * e, lv_cover_res_t res)
{
    lv_recursive_lock();
    lv_event_set_cover_res(e, res);
    lv_recursive_unlock();
    
}


lv_group_t * safe_lv_group_create(void)
{
    lv_recursive_lock();
    lv_group_t * ret = lv_group_create();
    lv_recursive_unlock();
    return ret;
}


void safe_lv_group_del(lv_group_t * group)
{
    lv_recursive_lock();
    lv_group_del(group);
    lv_recursive_unlock();
    
}


void safe_lv_group_set_default(lv_group_t * group)
{
    lv_recursive_lock();
    lv_group_set_default(group);
    lv_recursive_unlock();
    
}


lv_group_t * safe_lv_group_get_default(void)
{
    lv_recursive_lock();
    lv_group_t * ret = lv_group_get_default();
    lv_recursive_unlock();
    return ret;
}


void safe_lv_group_add_obj(lv_group_t * group, struct _lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_group_add_obj(group, obj);
    lv_recursive_unlock();
    
}


void safe_lv_group_swap_obj(struct _lv_obj_t * obj1, struct _lv_obj_t * obj2)
{
    lv_recursive_lock();
    lv_group_swap_obj(obj1, obj2);
    lv_recursive_unlock();
    
}


void safe_lv_group_remove_obj(struct _lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_group_remove_obj(obj);
    lv_recursive_unlock();
    
}


void safe_lv_group_remove_all_objs(lv_group_t * group)
{
    lv_recursive_lock();
    lv_group_remove_all_objs(group);
    lv_recursive_unlock();
    
}


void safe_lv_group_focus_obj(struct _lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_group_focus_obj(obj);
    lv_recursive_unlock();
    
}


void safe_lv_group_focus_next(lv_group_t * group)
{
    lv_recursive_lock();
    lv_group_focus_next(group);
    lv_recursive_unlock();
    
}


void safe_lv_group_focus_prev(lv_group_t * group)
{
    lv_recursive_lock();
    lv_group_focus_prev(group);
    lv_recursive_unlock();
    
}


void safe_lv_group_focus_freeze(lv_group_t * group, bool en)
{
    lv_recursive_lock();
    lv_group_focus_freeze(group, en);
    lv_recursive_unlock();
    
}


lv_res_t safe_lv_group_send_data(lv_group_t * group, uint32_t c)
{
    lv_recursive_lock();
    lv_res_t ret = lv_group_send_data(group, c);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_group_set_focus_cb(lv_group_t * group, lv_group_focus_cb_t focus_cb)
{
    lv_recursive_lock();
    lv_group_set_focus_cb(group, focus_cb);
    lv_recursive_unlock();
    
}


void safe_lv_group_set_edge_cb(lv_group_t * group, lv_group_edge_cb_t edge_cb)
{
    lv_recursive_lock();
    lv_group_set_edge_cb(group, edge_cb);
    lv_recursive_unlock();
    
}


void safe_lv_group_set_refocus_policy(lv_group_t * group, lv_group_refocus_policy_t policy)
{
    lv_recursive_lock();
    lv_group_set_refocus_policy(group, policy);
    lv_recursive_unlock();
    
}


void safe_lv_group_set_editing(lv_group_t * group, bool edit)
{
    lv_recursive_lock();
    lv_group_set_editing(group, edit);
    lv_recursive_unlock();
    
}


void safe_lv_group_set_wrap(lv_group_t * group, bool en)
{
    lv_recursive_lock();
    lv_group_set_wrap(group, en);
    lv_recursive_unlock();
    
}


struct _lv_obj_t * safe_lv_group_get_focused(const lv_group_t * group)
{
    lv_recursive_lock();
    struct _lv_obj_t * ret = lv_group_get_focused(group);
    lv_recursive_unlock();
    return ret;
}


lv_group_focus_cb_t safe_lv_group_get_focus_cb(const lv_group_t * group)
{
    lv_recursive_lock();
    lv_group_focus_cb_t ret = lv_group_get_focus_cb(group);
    lv_recursive_unlock();
    return ret;
}


lv_group_edge_cb_t safe_lv_group_get_edge_cb(const lv_group_t * group)
{
    lv_recursive_lock();
    lv_group_edge_cb_t ret = lv_group_get_edge_cb(group);
    lv_recursive_unlock();
    return ret;
}


bool safe_lv_group_get_editing(const lv_group_t * group)
{
    lv_recursive_lock();
    bool ret = lv_group_get_editing(group);
    lv_recursive_unlock();
    return ret;
}


bool safe_lv_group_get_wrap(lv_group_t * group)
{
    lv_recursive_lock();
    bool ret = lv_group_get_wrap(group);
    lv_recursive_unlock();
    return ret;
}


uint32_t safe_lv_group_get_obj_count(lv_group_t * group)
{
    lv_recursive_lock();
    uint32_t ret = lv_group_get_obj_count(group);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_init(void)
{
    lv_recursive_lock();
    lv_init();
    lv_recursive_unlock();
    
}


bool safe_lv_is_initialized(void)
{
    lv_recursive_lock();
    bool ret = lv_is_initialized();
    lv_recursive_unlock();
    return ret;
}


lv_obj_t * safe_lv_obj_create(lv_obj_t * parent)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_obj_create(parent);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_obj_add_flag(lv_obj_t * obj, lv_obj_flag_t f)
{
    lv_recursive_lock();
    lv_obj_add_flag(obj, f);
    lv_recursive_unlock();
    
}


void safe_lv_obj_clear_flag(lv_obj_t * obj, lv_obj_flag_t f)
{
    lv_recursive_lock();
    lv_obj_clear_flag(obj, f);
    lv_recursive_unlock();
    
}


void safe_lv_obj_add_state(lv_obj_t * obj, lv_state_t state)
{
    lv_recursive_lock();
    lv_obj_add_state(obj, state);
    lv_recursive_unlock();
    
}


void safe_lv_obj_clear_state(lv_obj_t * obj, lv_state_t state)
{
    lv_recursive_lock();
    lv_obj_clear_state(obj, state);
    lv_recursive_unlock();
    
}


static inline void safe_lv_obj_set_user_data(lv_obj_t * obj, void * user_data)
{
    lv_recursive_lock();
    lv_obj_set_user_data(obj, user_data);
    lv_recursive_unlock();
    
}


bool safe_lv_obj_has_flag(const lv_obj_t * obj, lv_obj_flag_t f)
{
    lv_recursive_lock();
    bool ret = lv_obj_has_flag(obj, f);
    lv_recursive_unlock();
    return ret;
}


bool safe_lv_obj_has_flag_any(const lv_obj_t * obj, lv_obj_flag_t f)
{
    lv_recursive_lock();
    bool ret = lv_obj_has_flag_any(obj, f);
    lv_recursive_unlock();
    return ret;
}


lv_state_t safe_lv_obj_get_state(const lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_state_t ret = lv_obj_get_state(obj);
    lv_recursive_unlock();
    return ret;
}


bool safe_lv_obj_has_state(const lv_obj_t * obj, lv_state_t state)
{
    lv_recursive_lock();
    bool ret = lv_obj_has_state(obj, state);
    lv_recursive_unlock();
    return ret;
}


void * safe_lv_obj_get_group(const lv_obj_t * obj)
{
    lv_recursive_lock();
    void * ret = lv_obj_get_group(obj);
    lv_recursive_unlock();
    
}


static inline void * safe_lv_obj_get_user_data(lv_obj_t * obj)
{
    lv_recursive_lock();
    void * ret = lv_obj_get_user_data(obj);
    lv_recursive_unlock();
    
}


void safe_lv_obj_allocate_spec_attr(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_obj_allocate_spec_attr(obj);
    lv_recursive_unlock();
    
}


bool safe_lv_obj_check_type(const lv_obj_t * obj, const lv_obj_class_t * class_p)
{
    lv_recursive_lock();
    bool ret = lv_obj_check_type(obj, class_p);
    lv_recursive_unlock();
    return ret;
}


bool safe_lv_obj_has_class(const lv_obj_t * obj, const lv_obj_class_t * class_p)
{
    lv_recursive_lock();
    bool ret = lv_obj_has_class(obj, class_p);
    lv_recursive_unlock();
    return ret;
}


const lv_obj_class_t * safe_lv_obj_get_class(const lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_obj_class_t * ret = lv_obj_get_class(obj);
    lv_recursive_unlock();
    return ret;
}


bool safe_lv_obj_is_valid(const lv_obj_t * obj)
{
    lv_recursive_lock();
    bool ret = lv_obj_is_valid(obj);
    lv_recursive_unlock();
    return ret;
}


static inline lv_coord_t safe_lv_obj_dpx(const lv_obj_t * obj, lv_coord_t n)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_dpx(obj, n);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_indev_read_timer_cb(lv_timer_t * timer)
{
    lv_recursive_lock();
    lv_indev_read_timer_cb(timer);
    lv_recursive_unlock();
    
}


void safe_lv_indev_enable(lv_indev_t * indev, bool en)
{
    lv_recursive_lock();
    lv_indev_enable(indev, en);
    lv_recursive_unlock();
    
}


lv_indev_t * safe_lv_indev_get_act(void)
{
    lv_recursive_lock();
    lv_indev_t * ret = lv_indev_get_act();
    lv_recursive_unlock();
    return ret;
}


lv_indev_type_t safe_lv_indev_get_type(const lv_indev_t * indev)
{
    lv_recursive_lock();
    lv_indev_type_t ret = lv_indev_get_type(indev);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_indev_reset(lv_indev_t * indev, lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_indev_reset(indev, obj);
    lv_recursive_unlock();
    
}


void safe_lv_indev_reset_long_press(lv_indev_t * indev)
{
    lv_recursive_lock();
    lv_indev_reset_long_press(indev);
    lv_recursive_unlock();
    
}


void safe_lv_indev_set_cursor(lv_indev_t * indev, lv_obj_t * cur_obj)
{
    lv_recursive_lock();
    lv_indev_set_cursor(indev, cur_obj);
    lv_recursive_unlock();
    
}


void safe_lv_indev_set_group(lv_indev_t * indev, lv_group_t * group)
{
    lv_recursive_lock();
    lv_indev_set_group(indev, group);
    lv_recursive_unlock();
    
}


void safe_lv_indev_set_button_points(lv_indev_t * indev, const lv_point_t points[])
{
    lv_recursive_lock();
    lv_indev_set_button_points(indev, points);
    lv_recursive_unlock();
    
}


void safe_lv_indev_get_point(const lv_indev_t * indev, lv_point_t * point)
{
    lv_recursive_lock();
    lv_indev_get_point(indev, point);
    lv_recursive_unlock();
    
}


lv_dir_t safe_lv_indev_get_gesture_dir(const lv_indev_t * indev)
{
    lv_recursive_lock();
    lv_dir_t ret = lv_indev_get_gesture_dir(indev);
    lv_recursive_unlock();
    return ret;
}


uint32_t safe_lv_indev_get_key(const lv_indev_t * indev)
{
    lv_recursive_lock();
    uint32_t ret = lv_indev_get_key(indev);
    lv_recursive_unlock();
    return ret;
}


lv_dir_t safe_lv_indev_get_scroll_dir(const lv_indev_t * indev)
{
    lv_recursive_lock();
    lv_dir_t ret = lv_indev_get_scroll_dir(indev);
    lv_recursive_unlock();
    return ret;
}


lv_obj_t * safe_lv_indev_get_scroll_obj(const lv_indev_t * indev)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_indev_get_scroll_obj(indev);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_indev_get_vect(const lv_indev_t * indev, lv_point_t * point)
{
    lv_recursive_lock();
    lv_indev_get_vect(indev, point);
    lv_recursive_unlock();
    
}


void safe_lv_indev_wait_release(lv_indev_t * indev)
{
    lv_recursive_lock();
    lv_indev_wait_release(indev);
    lv_recursive_unlock();
    
}


lv_obj_t * safe_lv_indev_get_obj_act(void)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_indev_get_obj_act();
    lv_recursive_unlock();
    return ret;
}


lv_timer_t * safe_lv_indev_get_read_timer(lv_disp_t * indev)
{
    lv_recursive_lock();
    lv_timer_t * ret = lv_indev_get_read_timer(indev);
    lv_recursive_unlock();
    return ret;
}


lv_obj_t * safe_lv_indev_search_obj(lv_obj_t * obj, lv_point_t * point)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_indev_search_obj(obj, point);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_refr_now(lv_disp_t * disp)
{
    lv_recursive_lock();
    lv_refr_now(disp);
    lv_recursive_unlock();
    
}


void safe_lv_obj_redraw(lv_draw_ctx_t * draw_ctx, lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_obj_redraw(draw_ctx, obj);
    lv_recursive_unlock();
    
}


lv_theme_t * safe_lv_theme_get_from_obj(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_theme_t * ret = lv_theme_get_from_obj(obj);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_theme_apply(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_theme_apply(obj);
    lv_recursive_unlock();
    
}


void safe_lv_theme_set_parent(lv_theme_t * new_theme, lv_theme_t * parent)
{
    lv_recursive_lock();
    lv_theme_set_parent(new_theme, parent);
    lv_recursive_unlock();
    
}


void safe_lv_theme_set_apply_cb(lv_theme_t * theme, lv_theme_apply_cb_t apply_cb)
{
    lv_recursive_lock();
    lv_theme_set_apply_cb(theme, apply_cb);
    lv_recursive_unlock();
    
}


const lv_font_t * safe_lv_theme_get_font_small(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_font_t * ret = lv_theme_get_font_small(obj);
    lv_recursive_unlock();
    return ret;
}


const lv_font_t * safe_lv_theme_get_font_normal(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_font_t * ret = lv_theme_get_font_normal(obj);
    lv_recursive_unlock();
    return ret;
}


const lv_font_t * safe_lv_theme_get_font_large(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_font_t * ret = lv_theme_get_font_large(obj);
    lv_recursive_unlock();
    return ret;
}


lv_color_t safe_lv_theme_get_color_primary(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_color_t ret = lv_theme_get_color_primary(obj);
    lv_recursive_unlock();
    return ret;
}


lv_color_t safe_lv_theme_get_color_secondary(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_color_t ret = lv_theme_get_color_secondary(obj);
    lv_recursive_unlock();
    return ret;
}


lv_obj_t * safe_lv_disp_get_scr_act(lv_disp_t * disp)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_disp_get_scr_act(disp);
    lv_recursive_unlock();
    return ret;
}


lv_obj_t * safe_lv_disp_get_scr_prev(lv_disp_t * disp)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_disp_get_scr_prev(disp);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_disp_load_scr(lv_obj_t * scr)
{
    lv_recursive_lock();
    lv_disp_load_scr(scr);
    lv_recursive_unlock();
    
}


lv_obj_t * safe_lv_disp_get_layer_top(lv_disp_t * disp)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_disp_get_layer_top(disp);
    lv_recursive_unlock();
    return ret;
}


lv_obj_t * safe_lv_disp_get_layer_sys(lv_disp_t * disp)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_disp_get_layer_sys(disp);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_disp_set_theme(lv_disp_t * disp, lv_theme_t * th)
{
    lv_recursive_lock();
    lv_disp_set_theme(disp, th);
    lv_recursive_unlock();
    
}


lv_theme_t * safe_lv_disp_get_theme(lv_disp_t * disp)
{
    lv_recursive_lock();
    lv_theme_t * ret = lv_disp_get_theme(disp);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_disp_set_bg_color(lv_disp_t * disp, lv_color_t color)
{
    lv_recursive_lock();
    lv_disp_set_bg_color(disp, color);
    lv_recursive_unlock();
    
}


void safe_lv_disp_set_bg_image(lv_disp_t * disp, const void * img_src)
{
    lv_recursive_lock();
    lv_disp_set_bg_image(disp, img_src);
    lv_recursive_unlock();
    
}


void safe_lv_disp_set_bg_opa(lv_disp_t * disp, lv_opa_t opa)
{
    lv_recursive_lock();
    lv_disp_set_bg_opa(disp, opa);
    lv_recursive_unlock();
    
}


void safe_lv_scr_load_anim(lv_obj_t * scr, lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool auto_del)
{
    lv_recursive_lock();
    lv_scr_load_anim(scr, anim_type, time, delay, auto_del);
    lv_recursive_unlock();
    
}


uint32_t safe_lv_disp_get_inactive_time(const lv_disp_t * disp)
{
    lv_recursive_lock();
    uint32_t ret = lv_disp_get_inactive_time(disp);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_disp_trig_activity(lv_disp_t * disp)
{
    lv_recursive_lock();
    lv_disp_trig_activity(disp);
    lv_recursive_unlock();
    
}


void safe_lv_disp_clean_dcache(lv_disp_t * disp)
{
    lv_recursive_lock();
    lv_disp_clean_dcache(disp);
    lv_recursive_unlock();
    
}


void safe_lv_disp_enable_invalidation(lv_disp_t * disp, bool en)
{
    lv_recursive_lock();
    lv_disp_enable_invalidation(disp, en);
    lv_recursive_unlock();
    
}


bool safe_lv_disp_is_invalidation_enabled(lv_disp_t * disp)
{
    lv_recursive_lock();
    bool ret = lv_disp_is_invalidation_enabled(disp);
    lv_recursive_unlock();
    return ret;
}


static inline lv_obj_t * safe_lv_scr_act(void)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_scr_act();
    lv_recursive_unlock();
    return ret;
}


static inline lv_obj_t * safe_lv_layer_top(void)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_layer_top();
    lv_recursive_unlock();
    return ret;
}


static inline lv_obj_t * safe_lv_layer_sys(void)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_layer_sys();
    lv_recursive_unlock();
    return ret;
}


static inline void safe_lv_scr_load(lv_obj_t * scr)
{
    lv_recursive_lock();
    lv_scr_load(scr);
    lv_recursive_unlock();
    
}


static inline lv_coord_t safe_lv_dpx(lv_coord_t n)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_dpx(n);
    lv_recursive_unlock();
    return ret;
}


static inline lv_coord_t safe_lv_disp_dpx(const lv_disp_t * disp, lv_coord_t n)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_disp_dpx(disp, n);
    lv_recursive_unlock();
    return ret;
}


lv_font_t * safe_lv_font_load(const char * fontName)
{
    lv_recursive_lock();
    lv_font_t * ret = lv_font_load(fontName);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_font_free(lv_font_t * font)
{
    lv_recursive_lock();
    lv_font_free(font);
    lv_recursive_unlock();
    
}


const uint8_t * safe_lv_font_get_bitmap_fmt_txt(const lv_font_t * font, uint32_t letter)
{
    lv_recursive_lock();
    uint8_t * ret = lv_font_get_bitmap_fmt_txt(font, letter);
    lv_recursive_unlock();
    return ret;
}


bool safe_lv_font_get_glyph_dsc_fmt_txt(const lv_font_t * font, lv_font_glyph_dsc_t * dsc_out, uint32_t unicode_letter, uint32_t unicode_letter_next)
{
    lv_recursive_lock();
    bool ret = lv_font_get_glyph_dsc_fmt_txt(font, dsc_out, unicode_letter, unicode_letter_next);
    lv_recursive_unlock();
    return ret;
}


lv_obj_t * safe_lv_arc_create(lv_obj_t * parent)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_arc_create(parent);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_arc_set_start_angle(lv_obj_t * obj, uint16_t start)
{
    lv_recursive_lock();
    lv_arc_set_start_angle(obj, start);
    lv_recursive_unlock();
    
}


void safe_lv_arc_set_end_angle(lv_obj_t * obj, uint16_t end)
{
    lv_recursive_lock();
    lv_arc_set_end_angle(obj, end);
    lv_recursive_unlock();
    
}


void safe_lv_arc_set_angles(lv_obj_t * obj, uint16_t start, uint16_t end)
{
    lv_recursive_lock();
    lv_arc_set_angles(obj, start, end);
    lv_recursive_unlock();
    
}


void safe_lv_arc_set_bg_start_angle(lv_obj_t * obj, uint16_t start)
{
    lv_recursive_lock();
    lv_arc_set_bg_start_angle(obj, start);
    lv_recursive_unlock();
    
}


void safe_lv_arc_set_bg_end_angle(lv_obj_t * obj, uint16_t end)
{
    lv_recursive_lock();
    lv_arc_set_bg_end_angle(obj, end);
    lv_recursive_unlock();
    
}


void safe_lv_arc_set_bg_angles(lv_obj_t * obj, uint16_t start, uint16_t end)
{
    lv_recursive_lock();
    lv_arc_set_bg_angles(obj, start, end);
    lv_recursive_unlock();
    
}


void safe_lv_arc_set_rotation(lv_obj_t * obj, uint16_t rotation)
{
    lv_recursive_lock();
    lv_arc_set_rotation(obj, rotation);
    lv_recursive_unlock();
    
}


void safe_lv_arc_set_mode(lv_obj_t * obj, lv_arc_mode_t type)
{
    lv_recursive_lock();
    lv_arc_set_mode(obj, type);
    lv_recursive_unlock();
    
}


void safe_lv_arc_set_value(lv_obj_t * obj, int16_t value)
{
    lv_recursive_lock();
    lv_arc_set_value(obj, value);
    lv_recursive_unlock();
    
}


void safe_lv_arc_set_range(lv_obj_t * obj, int16_t min, int16_t max)
{
    lv_recursive_lock();
    lv_arc_set_range(obj, min, max);
    lv_recursive_unlock();
    
}


void safe_lv_arc_set_change_rate(lv_obj_t * obj, uint16_t rate)
{
    lv_recursive_lock();
    lv_arc_set_change_rate(obj, rate);
    lv_recursive_unlock();
    
}


uint16_t safe_lv_arc_get_angle_start(lv_obj_t * obj)
{
    lv_recursive_lock();
    uint16_t ret = lv_arc_get_angle_start(obj);
    lv_recursive_unlock();
    return ret;
}


uint16_t safe_lv_arc_get_angle_end(lv_obj_t * obj)
{
    lv_recursive_lock();
    uint16_t ret = lv_arc_get_angle_end(obj);
    lv_recursive_unlock();
    return ret;
}


uint16_t safe_lv_arc_get_bg_angle_start(lv_obj_t * obj)
{
    lv_recursive_lock();
    uint16_t ret = lv_arc_get_bg_angle_start(obj);
    lv_recursive_unlock();
    return ret;
}


uint16_t safe_lv_arc_get_bg_angle_end(lv_obj_t * obj)
{
    lv_recursive_lock();
    uint16_t ret = lv_arc_get_bg_angle_end(obj);
    lv_recursive_unlock();
    return ret;
}


int16_t safe_lv_arc_get_value(const lv_obj_t * obj)
{
    lv_recursive_lock();
    int16_t ret = lv_arc_get_value(obj);
    lv_recursive_unlock();
    return ret;
}


int16_t safe_lv_arc_get_min_value(const lv_obj_t * obj)
{
    lv_recursive_lock();
    int16_t ret = lv_arc_get_min_value(obj);
    lv_recursive_unlock();
    return ret;
}


int16_t safe_lv_arc_get_max_value(const lv_obj_t * obj)
{
    lv_recursive_lock();
    int16_t ret = lv_arc_get_max_value(obj);
    lv_recursive_unlock();
    return ret;
}


lv_arc_mode_t safe_lv_arc_get_mode(const lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_arc_mode_t ret = lv_arc_get_mode(obj);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_arc_align_obj_to_angle(const lv_obj_t * obj, lv_obj_t * obj_to_align, lv_coord_t r_offset)
{
    lv_recursive_lock();
    lv_arc_align_obj_to_angle(obj, obj_to_align, r_offset);
    lv_recursive_unlock();
    
}


void safe_lv_arc_rotate_obj_to_angle(const lv_obj_t * obj, lv_obj_t * obj_to_rotate, lv_coord_t r_offset)
{
    lv_recursive_lock();
    lv_arc_rotate_obj_to_angle(obj, obj_to_rotate, r_offset);
    lv_recursive_unlock();
    
}


lv_obj_t * safe_lv_btn_create(lv_obj_t * parent)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_btn_create(parent);
    lv_recursive_unlock();
    return ret;
}


lv_obj_t * safe_lv_img_create(lv_obj_t * parent)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_img_create(parent);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_img_set_src(lv_obj_t * obj, const void * src)
{
    lv_recursive_lock();
    lv_img_set_src(obj, src);
    lv_recursive_unlock();
    
}


void safe_lv_img_set_offset_x(lv_obj_t * obj, lv_coord_t x)
{
    lv_recursive_lock();
    lv_img_set_offset_x(obj, x);
    lv_recursive_unlock();
    
}


void safe_lv_img_set_offset_y(lv_obj_t * obj, lv_coord_t y)
{
    lv_recursive_lock();
    lv_img_set_offset_y(obj, y);
    lv_recursive_unlock();
    
}


void safe_lv_img_set_angle(lv_obj_t * obj, int16_t angle)
{
    lv_recursive_lock();
    lv_img_set_angle(obj, angle);
    lv_recursive_unlock();
    
}


void safe_lv_img_set_pivot(lv_obj_t * obj, lv_coord_t x, lv_coord_t y)
{
    lv_recursive_lock();
    lv_img_set_pivot(obj, x, y);
    lv_recursive_unlock();
    
}


void safe_lv_img_set_zoom(lv_obj_t * obj, uint16_t zoom)
{
    lv_recursive_lock();
    lv_img_set_zoom(obj, zoom);
    lv_recursive_unlock();
    
}


void safe_lv_img_set_antialias(lv_obj_t * obj, bool antialias)
{
    lv_recursive_lock();
    lv_img_set_antialias(obj, antialias);
    lv_recursive_unlock();
    
}


void safe_lv_img_set_size_mode(lv_obj_t * obj, lv_img_size_mode_t mode)
{
    lv_recursive_lock();
    lv_img_set_size_mode(obj, mode);
    lv_recursive_unlock();
    
}


const void * safe_lv_img_get_src(lv_obj_t * obj)
{
    lv_recursive_lock();
    void * ret = lv_img_get_src(obj);
    lv_recursive_unlock();
    
}


lv_coord_t safe_lv_img_get_offset_x(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_img_get_offset_x(obj);
    lv_recursive_unlock();
    return ret;
}


lv_coord_t safe_lv_img_get_offset_y(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_img_get_offset_y(obj);
    lv_recursive_unlock();
    return ret;
}


uint16_t safe_lv_img_get_angle(lv_obj_t * obj)
{
    lv_recursive_lock();
    uint16_t ret = lv_img_get_angle(obj);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_img_get_pivot(lv_obj_t * obj, lv_point_t * pivot)
{
    lv_recursive_lock();
    lv_img_get_pivot(obj, pivot);
    lv_recursive_unlock();
    
}


uint16_t safe_lv_img_get_zoom(lv_obj_t * obj)
{
    lv_recursive_lock();
    uint16_t ret = lv_img_get_zoom(obj);
    lv_recursive_unlock();
    return ret;
}


bool safe_lv_img_get_antialias(lv_obj_t * obj)
{
    lv_recursive_lock();
    bool ret = lv_img_get_antialias(obj);
    lv_recursive_unlock();
    return ret;
}


lv_img_size_mode_t safe_lv_img_get_size_mode(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_img_size_mode_t ret = lv_img_get_size_mode(obj);
    lv_recursive_unlock();
    return ret;
}


lv_obj_t * safe_lv_label_create(lv_obj_t * parent)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_label_create(parent);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_label_set_text(lv_obj_t * obj, const char * text)
{
    lv_recursive_lock();
    lv_label_set_text(obj, text);
    lv_recursive_unlock();
    
}


void safe_lv_label_set_text_static(lv_obj_t * obj, const char * text)
{
    lv_recursive_lock();
    lv_label_set_text_static(obj, text);
    lv_recursive_unlock();
    
}


void safe_lv_label_set_long_mode(lv_obj_t * obj, lv_label_long_mode_t long_mode)
{
    lv_recursive_lock();
    lv_label_set_long_mode(obj, long_mode);
    lv_recursive_unlock();
    
}


void safe_lv_label_set_recolor(lv_obj_t * obj, bool en)
{
    lv_recursive_lock();
    lv_label_set_recolor(obj, en);
    lv_recursive_unlock();
    
}


void safe_lv_label_set_text_sel_start(lv_obj_t * obj, uint32_t index)
{
    lv_recursive_lock();
    lv_label_set_text_sel_start(obj, index);
    lv_recursive_unlock();
    
}


void safe_lv_label_set_text_sel_end(lv_obj_t * obj, uint32_t index)
{
    lv_recursive_lock();
    lv_label_set_text_sel_end(obj, index);
    lv_recursive_unlock();
    
}


char * safe_lv_label_get_text(const lv_obj_t * obj)
{
    lv_recursive_lock();
    char * ret = lv_label_get_text(obj);
    lv_recursive_unlock();
    return ret;
}


lv_label_long_mode_t safe_lv_label_get_long_mode(const lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_label_long_mode_t ret = lv_label_get_long_mode(obj);
    lv_recursive_unlock();
    return ret;
}


bool safe_lv_label_get_recolor(const lv_obj_t * obj)
{
    lv_recursive_lock();
    bool ret = lv_label_get_recolor(obj);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_label_get_letter_pos(const lv_obj_t * obj, uint32_t char_id, lv_point_t * pos)
{
    lv_recursive_lock();
    lv_label_get_letter_pos(obj, char_id, pos);
    lv_recursive_unlock();
    
}


uint32_t safe_lv_label_get_letter_on(const lv_obj_t * obj, lv_point_t * pos_in)
{
    lv_recursive_lock();
    uint32_t ret = lv_label_get_letter_on(obj, pos_in);
    lv_recursive_unlock();
    return ret;
}


bool safe_lv_label_is_char_under_pos(const lv_obj_t * obj, lv_point_t * pos)
{
    lv_recursive_lock();
    bool ret = lv_label_is_char_under_pos(obj, pos);
    lv_recursive_unlock();
    return ret;
}


uint32_t safe_lv_label_get_text_selection_start(const lv_obj_t * obj)
{
    lv_recursive_lock();
    uint32_t ret = lv_label_get_text_selection_start(obj);
    lv_recursive_unlock();
    return ret;
}


uint32_t safe_lv_label_get_text_selection_end(const lv_obj_t * obj)
{
    lv_recursive_lock();
    uint32_t ret = lv_label_get_text_selection_end(obj);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_label_ins_text(lv_obj_t * obj, uint32_t pos, const char * txt)
{
    lv_recursive_lock();
    lv_label_ins_text(obj, pos, txt);
    lv_recursive_unlock();
    
}


void safe_lv_label_cut_text(lv_obj_t * obj, uint32_t pos, uint32_t cnt)
{
    lv_recursive_lock();
    lv_label_cut_text(obj, pos, cnt);
    lv_recursive_unlock();
    
}


lv_obj_t * safe_lv_line_create(lv_obj_t * parent)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_line_create(parent);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_line_set_points(lv_obj_t * obj, const lv_point_t points[], uint16_t point_num)
{
    lv_recursive_lock();
    lv_line_set_points(obj, points, point_num);
    lv_recursive_unlock();
    
}


void safe_lv_line_set_y_invert(lv_obj_t * obj, bool en)
{
    lv_recursive_lock();
    lv_line_set_y_invert(obj, en);
    lv_recursive_unlock();
    
}


bool safe_lv_line_get_y_invert(const lv_obj_t * obj)
{
    lv_recursive_lock();
    bool ret = lv_line_get_y_invert(obj);
    lv_recursive_unlock();
    return ret;
}


lv_obj_t * safe_lv_table_create(lv_obj_t * parent)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_table_create(parent);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_table_set_cell_value(lv_obj_t * obj, uint16_t row, uint16_t col, const char * txt)
{
    lv_recursive_lock();
    lv_table_set_cell_value(obj, row, col, txt);
    lv_recursive_unlock();
    
}


void safe_lv_table_set_row_cnt(lv_obj_t * obj, uint16_t row_cnt)
{
    lv_recursive_lock();
    lv_table_set_row_cnt(obj, row_cnt);
    lv_recursive_unlock();
    
}


void safe_lv_table_set_col_cnt(lv_obj_t * obj, uint16_t col_cnt)
{
    lv_recursive_lock();
    lv_table_set_col_cnt(obj, col_cnt);
    lv_recursive_unlock();
    
}


void safe_lv_table_set_col_width(lv_obj_t * obj, uint16_t col_id, lv_coord_t w)
{
    lv_recursive_lock();
    lv_table_set_col_width(obj, col_id, w);
    lv_recursive_unlock();
    
}


void safe_lv_table_add_cell_ctrl(lv_obj_t * obj, uint16_t row, uint16_t col, lv_table_cell_ctrl_t ctrl)
{
    lv_recursive_lock();
    lv_table_add_cell_ctrl(obj, row, col, ctrl);
    lv_recursive_unlock();
    
}


void safe_lv_table_clear_cell_ctrl(lv_obj_t * obj, uint16_t row, uint16_t col, lv_table_cell_ctrl_t ctrl)
{
    lv_recursive_lock();
    lv_table_clear_cell_ctrl(obj, row, col, ctrl);
    lv_recursive_unlock();
    
}


const char * safe_lv_table_get_cell_value(lv_obj_t * obj, uint16_t row, uint16_t col)
{
    lv_recursive_lock();
    char * ret = lv_table_get_cell_value(obj, row, col);
    lv_recursive_unlock();
    return ret;
}


uint16_t safe_lv_table_get_row_cnt(lv_obj_t * obj)
{
    lv_recursive_lock();
    uint16_t ret = lv_table_get_row_cnt(obj);
    lv_recursive_unlock();
    return ret;
}


uint16_t safe_lv_table_get_col_cnt(lv_obj_t * obj)
{
    lv_recursive_lock();
    uint16_t ret = lv_table_get_col_cnt(obj);
    lv_recursive_unlock();
    return ret;
}


lv_coord_t safe_lv_table_get_col_width(lv_obj_t * obj, uint16_t col)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_table_get_col_width(obj, col);
    lv_recursive_unlock();
    return ret;
}


bool safe_lv_table_has_cell_ctrl(lv_obj_t * obj, uint16_t row, uint16_t col, lv_table_cell_ctrl_t ctrl)
{
    lv_recursive_lock();
    bool ret = lv_table_has_cell_ctrl(obj, row, col, ctrl);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_table_get_selected_cell(lv_obj_t * obj, uint16_t * row, uint16_t * col)
{
    lv_recursive_lock();
    lv_table_get_selected_cell(obj, row, col);
    lv_recursive_unlock();
    
}


lv_obj_t * safe_lv_checkbox_create(lv_obj_t * parent)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_checkbox_create(parent);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_checkbox_set_text(lv_obj_t * obj, const char * txt)
{
    lv_recursive_lock();
    lv_checkbox_set_text(obj, txt);
    lv_recursive_unlock();
    
}


void safe_lv_checkbox_set_text_static(lv_obj_t * obj, const char * txt)
{
    lv_recursive_lock();
    lv_checkbox_set_text_static(obj, txt);
    lv_recursive_unlock();
    
}


const char * safe_lv_checkbox_get_text(const lv_obj_t * obj)
{
    lv_recursive_lock();
    char * ret = lv_checkbox_get_text(obj);
    lv_recursive_unlock();
    return ret;
}


lv_obj_t * safe_lv_bar_create(lv_obj_t * parent)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_bar_create(parent);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_bar_set_value(lv_obj_t * obj, int32_t value, lv_anim_enable_t anim)
{
    lv_recursive_lock();
    lv_bar_set_value(obj, value, anim);
    lv_recursive_unlock();
    
}


void safe_lv_bar_set_start_value(lv_obj_t * obj, int32_t start_value, lv_anim_enable_t anim)
{
    lv_recursive_lock();
    lv_bar_set_start_value(obj, start_value, anim);
    lv_recursive_unlock();
    
}


void safe_lv_bar_set_range(lv_obj_t * obj, int32_t min, int32_t max)
{
    lv_recursive_lock();
    lv_bar_set_range(obj, min, max);
    lv_recursive_unlock();
    
}


void safe_lv_bar_set_mode(lv_obj_t * obj, lv_bar_mode_t mode)
{
    lv_recursive_lock();
    lv_bar_set_mode(obj, mode);
    lv_recursive_unlock();
    
}


int32_t safe_lv_bar_get_value(const lv_obj_t * obj)
{
    lv_recursive_lock();
    int32_t ret = lv_bar_get_value(obj);
    lv_recursive_unlock();
    return ret;
}


int32_t safe_lv_bar_get_start_value(const lv_obj_t * obj)
{
    lv_recursive_lock();
    int32_t ret = lv_bar_get_start_value(obj);
    lv_recursive_unlock();
    return ret;
}


int32_t safe_lv_bar_get_min_value(const lv_obj_t * obj)
{
    lv_recursive_lock();
    int32_t ret = lv_bar_get_min_value(obj);
    lv_recursive_unlock();
    return ret;
}


int32_t safe_lv_bar_get_max_value(const lv_obj_t * obj)
{
    lv_recursive_lock();
    int32_t ret = lv_bar_get_max_value(obj);
    lv_recursive_unlock();
    return ret;
}


lv_bar_mode_t safe_lv_bar_get_mode(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_bar_mode_t ret = lv_bar_get_mode(obj);
    lv_recursive_unlock();
    return ret;
}


lv_obj_t * safe_lv_slider_create(lv_obj_t * parent)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_slider_create(parent);
    lv_recursive_unlock();
    return ret;
}


static inline void safe_lv_slider_set_value(lv_obj_t * obj, int32_t value, lv_anim_enable_t anim)
{
    lv_recursive_lock();
    lv_slider_set_value(obj, value, anim);
    lv_recursive_unlock();
    
}


static inline void safe_lv_slider_set_left_value(lv_obj_t * obj, int32_t value, lv_anim_enable_t anim)
{
    lv_recursive_lock();
    lv_slider_set_left_value(obj, value, anim);
    lv_recursive_unlock();
    
}


static inline void safe_lv_slider_set_range(lv_obj_t * obj, int32_t min, int32_t max)
{
    lv_recursive_lock();
    lv_slider_set_range(obj, min, max);
    lv_recursive_unlock();
    
}


static inline void safe_lv_slider_set_mode(lv_obj_t * obj, lv_slider_mode_t mode)
{
    lv_recursive_lock();
    lv_slider_set_mode(obj, mode);
    lv_recursive_unlock();
    
}


static inline int32_t safe_lv_slider_get_value(const lv_obj_t * obj)
{
    lv_recursive_lock();
    int32_t ret = lv_slider_get_value(obj);
    lv_recursive_unlock();
    return ret;
}


static inline int32_t safe_lv_slider_get_left_value(const lv_obj_t * obj)
{
    lv_recursive_lock();
    int32_t ret = lv_slider_get_left_value(obj);
    lv_recursive_unlock();
    return ret;
}


static inline int32_t safe_lv_slider_get_min_value(const lv_obj_t * obj)
{
    lv_recursive_lock();
    int32_t ret = lv_slider_get_min_value(obj);
    lv_recursive_unlock();
    return ret;
}


static inline int32_t safe_lv_slider_get_max_value(const lv_obj_t * obj)
{
    lv_recursive_lock();
    int32_t ret = lv_slider_get_max_value(obj);
    lv_recursive_unlock();
    return ret;
}


bool safe_lv_slider_is_dragged(const lv_obj_t * obj)
{
    lv_recursive_lock();
    bool ret = lv_slider_is_dragged(obj);
    lv_recursive_unlock();
    return ret;
}


static inline lv_slider_mode_t safe_lv_slider_get_mode(lv_obj_t * slider)
{
    lv_recursive_lock();
    lv_slider_mode_t ret = lv_slider_get_mode(slider);
    lv_recursive_unlock();
    return ret;
}


lv_obj_t * safe_lv_btnmatrix_create(lv_obj_t * parent)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_btnmatrix_create(parent);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_btnmatrix_set_map(lv_obj_t * obj, const char * map[])
{
    lv_recursive_lock();
    lv_btnmatrix_set_map(obj, map);
    lv_recursive_unlock();
    
}


void safe_lv_btnmatrix_set_ctrl_map(lv_obj_t * obj, const lv_btnmatrix_ctrl_t ctrl_map[])
{
    lv_recursive_lock();
    lv_btnmatrix_set_ctrl_map(obj, ctrl_map);
    lv_recursive_unlock();
    
}


void safe_lv_btnmatrix_set_selected_btn(lv_obj_t * obj, uint16_t btn_id)
{
    lv_recursive_lock();
    lv_btnmatrix_set_selected_btn(obj, btn_id);
    lv_recursive_unlock();
    
}


void safe_lv_btnmatrix_set_btn_ctrl(lv_obj_t * obj, uint16_t btn_id, lv_btnmatrix_ctrl_t ctrl)
{
    lv_recursive_lock();
    lv_btnmatrix_set_btn_ctrl(obj, btn_id, ctrl);
    lv_recursive_unlock();
    
}


void safe_lv_btnmatrix_clear_btn_ctrl(lv_obj_t * obj, uint16_t btn_id, lv_btnmatrix_ctrl_t ctrl)
{
    lv_recursive_lock();
    lv_btnmatrix_clear_btn_ctrl(obj, btn_id, ctrl);
    lv_recursive_unlock();
    
}


void safe_lv_btnmatrix_set_btn_ctrl_all(lv_obj_t * obj, lv_btnmatrix_ctrl_t ctrl)
{
    lv_recursive_lock();
    lv_btnmatrix_set_btn_ctrl_all(obj, ctrl);
    lv_recursive_unlock();
    
}


void safe_lv_btnmatrix_clear_btn_ctrl_all(lv_obj_t * obj, lv_btnmatrix_ctrl_t ctrl)
{
    lv_recursive_lock();
    lv_btnmatrix_clear_btn_ctrl_all(obj, ctrl);
    lv_recursive_unlock();
    
}


void safe_lv_btnmatrix_set_btn_width(lv_obj_t * obj, uint16_t btn_id, uint8_t width)
{
    lv_recursive_lock();
    lv_btnmatrix_set_btn_width(obj, btn_id, width);
    lv_recursive_unlock();
    
}


void safe_lv_btnmatrix_set_one_checked(lv_obj_t * obj, bool en)
{
    lv_recursive_lock();
    lv_btnmatrix_set_one_checked(obj, en);
    lv_recursive_unlock();
    
}


const char ** safe_lv_btnmatrix_get_map(const lv_obj_t * obj)
{
    lv_recursive_lock();
    char ** ret = lv_btnmatrix_get_map(obj);
    lv_recursive_unlock();
    return ret;
}


uint16_t safe_lv_btnmatrix_get_selected_btn(const lv_obj_t * obj)
{
    lv_recursive_lock();
    uint16_t ret = lv_btnmatrix_get_selected_btn(obj);
    lv_recursive_unlock();
    return ret;
}


const char * safe_lv_btnmatrix_get_btn_text(const lv_obj_t * obj, uint16_t btn_id)
{
    lv_recursive_lock();
    char * ret = lv_btnmatrix_get_btn_text(obj, btn_id);
    lv_recursive_unlock();
    return ret;
}


bool safe_lv_btnmatrix_has_btn_ctrl(lv_obj_t * obj, uint16_t btn_id, lv_btnmatrix_ctrl_t ctrl)
{
    lv_recursive_lock();
    bool ret = lv_btnmatrix_has_btn_ctrl(obj, btn_id, ctrl);
    lv_recursive_unlock();
    return ret;
}


bool safe_lv_btnmatrix_get_one_checked(const lv_obj_t * obj)
{
    lv_recursive_lock();
    bool ret = lv_btnmatrix_get_one_checked(obj);
    lv_recursive_unlock();
    return ret;
}


lv_obj_t * safe_lv_dropdown_create(lv_obj_t * parent)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_dropdown_create(parent);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_dropdown_set_text(lv_obj_t * obj, const char * txt)
{
    lv_recursive_lock();
    lv_dropdown_set_text(obj, txt);
    lv_recursive_unlock();
    
}


void safe_lv_dropdown_set_options(lv_obj_t * obj, const char * options)
{
    lv_recursive_lock();
    lv_dropdown_set_options(obj, options);
    lv_recursive_unlock();
    
}


void safe_lv_dropdown_set_options_static(lv_obj_t * obj, const char * options)
{
    lv_recursive_lock();
    lv_dropdown_set_options_static(obj, options);
    lv_recursive_unlock();
    
}


void safe_lv_dropdown_add_option(lv_obj_t * obj, const char * option, uint32_t pos)
{
    lv_recursive_lock();
    lv_dropdown_add_option(obj, option, pos);
    lv_recursive_unlock();
    
}


void safe_lv_dropdown_clear_options(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_dropdown_clear_options(obj);
    lv_recursive_unlock();
    
}


void safe_lv_dropdown_set_selected(lv_obj_t * obj, uint16_t sel_opt)
{
    lv_recursive_lock();
    lv_dropdown_set_selected(obj, sel_opt);
    lv_recursive_unlock();
    
}


void safe_lv_dropdown_set_dir(lv_obj_t * obj, lv_dir_t dir)
{
    lv_recursive_lock();
    lv_dropdown_set_dir(obj, dir);
    lv_recursive_unlock();
    
}


void safe_lv_dropdown_set_symbol(lv_obj_t * obj, const void * symbol)
{
    lv_recursive_lock();
    lv_dropdown_set_symbol(obj, symbol);
    lv_recursive_unlock();
    
}


void safe_lv_dropdown_set_selected_highlight(lv_obj_t * obj, bool en)
{
    lv_recursive_lock();
    lv_dropdown_set_selected_highlight(obj, en);
    lv_recursive_unlock();
    
}


lv_obj_t * safe_lv_dropdown_get_list(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_dropdown_get_list(obj);
    lv_recursive_unlock();
    return ret;
}


const char * safe_lv_dropdown_get_text(lv_obj_t * obj)
{
    lv_recursive_lock();
    char * ret = lv_dropdown_get_text(obj);
    lv_recursive_unlock();
    return ret;
}


const char * safe_lv_dropdown_get_options(const lv_obj_t * obj)
{
    lv_recursive_lock();
    char * ret = lv_dropdown_get_options(obj);
    lv_recursive_unlock();
    return ret;
}


uint16_t safe_lv_dropdown_get_selected(const lv_obj_t * obj)
{
    lv_recursive_lock();
    uint16_t ret = lv_dropdown_get_selected(obj);
    lv_recursive_unlock();
    return ret;
}


uint16_t safe_lv_dropdown_get_option_cnt(const lv_obj_t * obj)
{
    lv_recursive_lock();
    uint16_t ret = lv_dropdown_get_option_cnt(obj);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_dropdown_get_selected_str(const lv_obj_t * obj, char * buf, uint32_t buf_size)
{
    lv_recursive_lock();
    lv_dropdown_get_selected_str(obj, buf, buf_size);
    lv_recursive_unlock();
    
}


int32_t safe_lv_dropdown_get_option_index(lv_obj_t * obj, const char * option)
{
    lv_recursive_lock();
    int32_t ret = lv_dropdown_get_option_index(obj, option);
    lv_recursive_unlock();
    return ret;
}


const char * safe_lv_dropdown_get_symbol(lv_obj_t * obj)
{
    lv_recursive_lock();
    char * ret = lv_dropdown_get_symbol(obj);
    lv_recursive_unlock();
    return ret;
}


bool safe_lv_dropdown_get_selected_highlight(lv_obj_t * obj)
{
    lv_recursive_lock();
    bool ret = lv_dropdown_get_selected_highlight(obj);
    lv_recursive_unlock();
    return ret;
}


lv_dir_t safe_lv_dropdown_get_dir(const lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_dir_t ret = lv_dropdown_get_dir(obj);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_dropdown_open(lv_obj_t * dropdown_obj)
{
    lv_recursive_lock();
    lv_dropdown_open(dropdown_obj);
    lv_recursive_unlock();
    
}


void safe_lv_dropdown_close(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_dropdown_close(obj);
    lv_recursive_unlock();
    
}


bool safe_lv_dropdown_is_open(lv_obj_t * obj)
{
    lv_recursive_lock();
    bool ret = lv_dropdown_is_open(obj);
    lv_recursive_unlock();
    return ret;
}


lv_obj_t * safe_lv_roller_create(lv_obj_t * parent)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_roller_create(parent);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_roller_set_options(lv_obj_t * obj, const char * options, lv_roller_mode_t mode)
{
    lv_recursive_lock();
    lv_roller_set_options(obj, options, mode);
    lv_recursive_unlock();
    
}


void safe_lv_roller_set_selected(lv_obj_t * obj, uint16_t sel_opt, lv_anim_enable_t anim)
{
    lv_recursive_lock();
    lv_roller_set_selected(obj, sel_opt, anim);
    lv_recursive_unlock();
    
}


void safe_lv_roller_set_visible_row_count(lv_obj_t * obj, uint8_t row_cnt)
{
    lv_recursive_lock();
    lv_roller_set_visible_row_count(obj, row_cnt);
    lv_recursive_unlock();
    
}


uint16_t safe_lv_roller_get_selected(const lv_obj_t * obj)
{
    lv_recursive_lock();
    uint16_t ret = lv_roller_get_selected(obj);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_roller_get_selected_str(const lv_obj_t * obj, char * buf, uint32_t buf_size)
{
    lv_recursive_lock();
    lv_roller_get_selected_str(obj, buf, buf_size);
    lv_recursive_unlock();
    
}


const char * safe_lv_roller_get_options(const lv_obj_t * obj)
{
    lv_recursive_lock();
    char * ret = lv_roller_get_options(obj);
    lv_recursive_unlock();
    return ret;
}


uint16_t safe_lv_roller_get_option_cnt(const lv_obj_t * obj)
{
    lv_recursive_lock();
    uint16_t ret = lv_roller_get_option_cnt(obj);
    lv_recursive_unlock();
    return ret;
}


lv_obj_t * safe_lv_textarea_create(lv_obj_t * parent)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_textarea_create(parent);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_textarea_add_char(lv_obj_t * obj, uint32_t c)
{
    lv_recursive_lock();
    lv_textarea_add_char(obj, c);
    lv_recursive_unlock();
    
}


void safe_lv_textarea_add_text(lv_obj_t * obj, const char * txt)
{
    lv_recursive_lock();
    lv_textarea_add_text(obj, txt);
    lv_recursive_unlock();
    
}


void safe_lv_textarea_del_char(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_textarea_del_char(obj);
    lv_recursive_unlock();
    
}


void safe_lv_textarea_del_char_forward(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_textarea_del_char_forward(obj);
    lv_recursive_unlock();
    
}


void safe_lv_textarea_set_text(lv_obj_t * obj, const char * txt)
{
    lv_recursive_lock();
    lv_textarea_set_text(obj, txt);
    lv_recursive_unlock();
    
}


void safe_lv_textarea_set_placeholder_text(lv_obj_t * obj, const char * txt)
{
    lv_recursive_lock();
    lv_textarea_set_placeholder_text(obj, txt);
    lv_recursive_unlock();
    
}


void safe_lv_textarea_set_cursor_pos(lv_obj_t * obj, int32_t pos)
{
    lv_recursive_lock();
    lv_textarea_set_cursor_pos(obj, pos);
    lv_recursive_unlock();
    
}


void safe_lv_textarea_set_cursor_click_pos(lv_obj_t * obj, bool en)
{
    lv_recursive_lock();
    lv_textarea_set_cursor_click_pos(obj, en);
    lv_recursive_unlock();
    
}


void safe_lv_textarea_set_password_mode(lv_obj_t * obj, bool en)
{
    lv_recursive_lock();
    lv_textarea_set_password_mode(obj, en);
    lv_recursive_unlock();
    
}


void safe_lv_textarea_set_password_bullet(lv_obj_t * obj, const char * bullet)
{
    lv_recursive_lock();
    lv_textarea_set_password_bullet(obj, bullet);
    lv_recursive_unlock();
    
}


void safe_lv_textarea_set_one_line(lv_obj_t * obj, bool en)
{
    lv_recursive_lock();
    lv_textarea_set_one_line(obj, en);
    lv_recursive_unlock();
    
}


void safe_lv_textarea_set_accepted_chars(lv_obj_t * obj, const char * list)
{
    lv_recursive_lock();
    lv_textarea_set_accepted_chars(obj, list);
    lv_recursive_unlock();
    
}


void safe_lv_textarea_set_max_length(lv_obj_t * obj, uint32_t num)
{
    lv_recursive_lock();
    lv_textarea_set_max_length(obj, num);
    lv_recursive_unlock();
    
}


void safe_lv_textarea_set_insert_replace(lv_obj_t * obj, const char * txt)
{
    lv_recursive_lock();
    lv_textarea_set_insert_replace(obj, txt);
    lv_recursive_unlock();
    
}


void safe_lv_textarea_set_text_selection(lv_obj_t * obj, bool en)
{
    lv_recursive_lock();
    lv_textarea_set_text_selection(obj, en);
    lv_recursive_unlock();
    
}


void safe_lv_textarea_set_password_show_time(lv_obj_t * obj, uint16_t time)
{
    lv_recursive_lock();
    lv_textarea_set_password_show_time(obj, time);
    lv_recursive_unlock();
    
}


void safe_lv_textarea_set_align(lv_obj_t * obj, lv_text_align_t align)
{
    lv_recursive_lock();
    lv_textarea_set_align(obj, align);
    lv_recursive_unlock();
    
}


const char * safe_lv_textarea_get_text(const lv_obj_t * obj)
{
    lv_recursive_lock();
    char * ret = lv_textarea_get_text(obj);
    lv_recursive_unlock();
    return ret;
}


const char * safe_lv_textarea_get_placeholder_text(lv_obj_t * obj)
{
    lv_recursive_lock();
    char * ret = lv_textarea_get_placeholder_text(obj);
    lv_recursive_unlock();
    return ret;
}


lv_obj_t * safe_lv_textarea_get_label(const lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_textarea_get_label(obj);
    lv_recursive_unlock();
    return ret;
}


uint32_t safe_lv_textarea_get_cursor_pos(const lv_obj_t * obj)
{
    lv_recursive_lock();
    uint32_t ret = lv_textarea_get_cursor_pos(obj);
    lv_recursive_unlock();
    return ret;
}


bool safe_lv_textarea_get_cursor_click_pos(lv_obj_t * obj)
{
    lv_recursive_lock();
    bool ret = lv_textarea_get_cursor_click_pos(obj);
    lv_recursive_unlock();
    return ret;
}


bool safe_lv_textarea_get_password_mode(const lv_obj_t * obj)
{
    lv_recursive_lock();
    bool ret = lv_textarea_get_password_mode(obj);
    lv_recursive_unlock();
    return ret;
}


const char * safe_lv_textarea_get_password_bullet(lv_obj_t * obj)
{
    lv_recursive_lock();
    char * ret = lv_textarea_get_password_bullet(obj);
    lv_recursive_unlock();
    return ret;
}


bool safe_lv_textarea_get_one_line(const lv_obj_t * obj)
{
    lv_recursive_lock();
    bool ret = lv_textarea_get_one_line(obj);
    lv_recursive_unlock();
    return ret;
}


const char * safe_lv_textarea_get_accepted_chars(lv_obj_t * obj)
{
    lv_recursive_lock();
    char * ret = lv_textarea_get_accepted_chars(obj);
    lv_recursive_unlock();
    return ret;
}


uint32_t safe_lv_textarea_get_max_length(lv_obj_t * obj)
{
    lv_recursive_lock();
    uint32_t ret = lv_textarea_get_max_length(obj);
    lv_recursive_unlock();
    return ret;
}


bool safe_lv_textarea_text_is_selected(const lv_obj_t * obj)
{
    lv_recursive_lock();
    bool ret = lv_textarea_text_is_selected(obj);
    lv_recursive_unlock();
    return ret;
}


bool safe_lv_textarea_get_text_selection(lv_obj_t * obj)
{
    lv_recursive_lock();
    bool ret = lv_textarea_get_text_selection(obj);
    lv_recursive_unlock();
    return ret;
}


uint16_t safe_lv_textarea_get_password_show_time(lv_obj_t * obj)
{
    lv_recursive_lock();
    uint16_t ret = lv_textarea_get_password_show_time(obj);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_textarea_clear_selection(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_textarea_clear_selection(obj);
    lv_recursive_unlock();
    
}


void safe_lv_textarea_cursor_right(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_textarea_cursor_right(obj);
    lv_recursive_unlock();
    
}


void safe_lv_textarea_cursor_left(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_textarea_cursor_left(obj);
    lv_recursive_unlock();
    
}


void safe_lv_textarea_cursor_down(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_textarea_cursor_down(obj);
    lv_recursive_unlock();
    
}


void safe_lv_textarea_cursor_up(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_textarea_cursor_up(obj);
    lv_recursive_unlock();
    
}


lv_obj_t * safe_lv_canvas_create(lv_obj_t * parent)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_canvas_create(parent);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_canvas_set_buffer(lv_obj_t * canvas, void * buf, lv_coord_t w, lv_coord_t h, lv_img_cf_t cf)
{
    lv_recursive_lock();
    lv_canvas_set_buffer(canvas, buf, w, h, cf);
    lv_recursive_unlock();
    
}


void safe_lv_canvas_set_px_color(lv_obj_t * canvas, lv_coord_t x, lv_coord_t y, lv_color_t c)
{
    lv_recursive_lock();
    lv_canvas_set_px_color(canvas, x, y, c);
    lv_recursive_unlock();
    
}


static inline void safe_lv_canvas_set_px(lv_obj_t * canvas, lv_coord_t x, lv_coord_t y, lv_color_t c)
{
    lv_recursive_lock();
    lv_canvas_set_px(canvas, x, y, c);
    lv_recursive_unlock();
    
}


void safe_lv_canvas_set_px_opa(lv_obj_t * canvas, lv_coord_t x, lv_coord_t y, lv_opa_t opa)
{
    lv_recursive_lock();
    lv_canvas_set_px_opa(canvas, x, y, opa);
    lv_recursive_unlock();
    
}


void safe_lv_canvas_set_palette(lv_obj_t * canvas, uint8_t id, lv_color_t c)
{
    lv_recursive_lock();
    lv_canvas_set_palette(canvas, id, c);
    lv_recursive_unlock();
    
}


lv_color_t safe_lv_canvas_get_px(lv_obj_t * canvas, lv_coord_t x, lv_coord_t y)
{
    lv_recursive_lock();
    lv_color_t ret = lv_canvas_get_px(canvas, x, y);
    lv_recursive_unlock();
    return ret;
}


lv_img_dsc_t * safe_lv_canvas_get_img(lv_obj_t * canvas)
{
    lv_recursive_lock();
    lv_img_dsc_t * ret = lv_canvas_get_img(canvas);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_canvas_copy_buf(lv_obj_t * canvas, const void * to_copy, lv_coord_t x, lv_coord_t y, lv_coord_t w, lv_coord_t h)
{
    lv_recursive_lock();
    lv_canvas_copy_buf(canvas, to_copy, x, y, w, h);
    lv_recursive_unlock();
    
}


void safe_lv_canvas_transform(lv_obj_t * canvas, lv_img_dsc_t * img, int16_t angle, uint16_t zoom, lv_coord_t offset_x, lv_coord_t offset_y, int32_t pivot_x, int32_t pivot_y, bool antialias)
{
    lv_recursive_lock();
    lv_canvas_transform(canvas, img, angle, zoom, offset_x, offset_y, pivot_x, pivot_y, antialias);
    lv_recursive_unlock();
    
}


void safe_lv_canvas_blur_hor(lv_obj_t * canvas, const lv_area_t * area, uint16_t r)
{
    lv_recursive_lock();
    lv_canvas_blur_hor(canvas, area, r);
    lv_recursive_unlock();
    
}


void safe_lv_canvas_blur_ver(lv_obj_t * canvas, const lv_area_t * area, uint16_t r)
{
    lv_recursive_lock();
    lv_canvas_blur_ver(canvas, area, r);
    lv_recursive_unlock();
    
}


void safe_lv_canvas_fill_bg(lv_obj_t * canvas, lv_color_t color, lv_opa_t opa)
{
    lv_recursive_lock();
    lv_canvas_fill_bg(canvas, color, opa);
    lv_recursive_unlock();
    
}


void safe_lv_canvas_draw_rect(lv_obj_t * canvas, lv_coord_t x, lv_coord_t y, lv_coord_t w, lv_coord_t h, const lv_draw_rect_dsc_t * draw_dsc)
{
    lv_recursive_lock();
    lv_canvas_draw_rect(canvas, x, y, w, h, draw_dsc);
    lv_recursive_unlock();
    
}


void safe_lv_canvas_draw_text(lv_obj_t * canvas, lv_coord_t x, lv_coord_t y, lv_coord_t max_w, lv_draw_label_dsc_t * draw_dsc, const char * txt)
{
    lv_recursive_lock();
    lv_canvas_draw_text(canvas, x, y, max_w, draw_dsc, txt);
    lv_recursive_unlock();
    
}


void safe_lv_canvas_draw_img(lv_obj_t * canvas, lv_coord_t x, lv_coord_t y, const void * src, const lv_draw_img_dsc_t * draw_dsc)
{
    lv_recursive_lock();
    lv_canvas_draw_img(canvas, x, y, src, draw_dsc);
    lv_recursive_unlock();
    
}


void safe_lv_canvas_draw_line(lv_obj_t * canvas, const lv_point_t points[], uint32_t point_cnt, const lv_draw_line_dsc_t * draw_dsc)
{
    lv_recursive_lock();
    lv_canvas_draw_line(canvas, points, point_cnt, draw_dsc);
    lv_recursive_unlock();
    
}


void safe_lv_canvas_draw_polygon(lv_obj_t * canvas, const lv_point_t points[], uint32_t point_cnt, const lv_draw_rect_dsc_t * draw_dsc)
{
    lv_recursive_lock();
    lv_canvas_draw_polygon(canvas, points, point_cnt, draw_dsc);
    lv_recursive_unlock();
    
}


void safe_lv_canvas_draw_arc(lv_obj_t * canvas, lv_coord_t x, lv_coord_t y, lv_coord_t r, int32_t start_angle, int32_t end_angle, const lv_draw_arc_dsc_t * draw_dsc)
{
    lv_recursive_lock();
    lv_canvas_draw_arc(canvas, x, y, r, start_angle, end_angle, draw_dsc);
    lv_recursive_unlock();
    
}


lv_obj_t * safe_lv_switch_create(lv_obj_t * parent)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_switch_create(parent);
    lv_recursive_unlock();
    return ret;
}


static inline uint32_t safe_lv_task_handler(void)
{
    lv_recursive_lock();
    uint32_t ret = lv_task_handler();
    lv_recursive_unlock();
    return ret;
}


static inline void safe_lv_obj_move_foreground(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_obj_move_foreground(obj);
    lv_recursive_unlock();
    
}


static inline void safe_lv_obj_move_background(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_obj_move_background(obj);
    lv_recursive_unlock();
    
}


static inline uint32_t safe_lv_obj_get_child_id(const struct _lv_obj_t * obj)
{
    lv_recursive_lock();
    uint32_t ret = lv_obj_get_child_id(obj);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_flex_init(void)
{
    lv_recursive_lock();
    lv_flex_init();
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_flex_flow(lv_obj_t * obj, lv_flex_flow_t flow)
{
    lv_recursive_lock();
    lv_obj_set_flex_flow(obj, flow);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_flex_align(lv_obj_t * obj, lv_flex_align_t main_place, lv_flex_align_t cross_place, lv_flex_align_t track_cross_place)
{
    lv_recursive_lock();
    lv_obj_set_flex_align(obj, main_place, cross_place, track_cross_place);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_flex_grow(lv_obj_t * obj, uint8_t grow)
{
    lv_recursive_lock();
    lv_obj_set_flex_grow(obj, grow);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_flex_flow(lv_style_t * style, lv_flex_flow_t value)
{
    lv_recursive_lock();
    lv_style_set_flex_flow(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_flex_main_place(lv_style_t * style, lv_flex_align_t value)
{
    lv_recursive_lock();
    lv_style_set_flex_main_place(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_flex_cross_place(lv_style_t * style, lv_flex_align_t value)
{
    lv_recursive_lock();
    lv_style_set_flex_cross_place(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_flex_track_place(lv_style_t * style, lv_flex_align_t value)
{
    lv_recursive_lock();
    lv_style_set_flex_track_place(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_flex_grow(lv_style_t * style, uint8_t value)
{
    lv_recursive_lock();
    lv_style_set_flex_grow(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_flex_flow(lv_obj_t * obj, lv_flex_flow_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_flex_flow(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_flex_main_place(lv_obj_t * obj, lv_flex_align_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_flex_main_place(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_flex_cross_place(lv_obj_t * obj, lv_flex_align_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_flex_cross_place(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_flex_track_place(lv_obj_t * obj, lv_flex_align_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_flex_track_place(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_flex_grow(lv_obj_t * obj, uint8_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_flex_grow(obj, value, selector);
    lv_recursive_unlock();
    
}


static inline lv_flex_flow_t safe_lv_obj_get_style_flex_flow(const lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_flex_flow_t ret = lv_obj_get_style_flex_flow(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_flex_align_t safe_lv_obj_get_style_flex_main_place(const lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_flex_align_t ret = lv_obj_get_style_flex_main_place(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_flex_align_t safe_lv_obj_get_style_flex_cross_place(const lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_flex_align_t ret = lv_obj_get_style_flex_cross_place(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_flex_align_t safe_lv_obj_get_style_flex_track_place(const lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_flex_align_t ret = lv_obj_get_style_flex_track_place(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline uint8_t safe_lv_obj_get_style_flex_grow(const lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    uint8_t ret = lv_obj_get_style_flex_grow(obj, part);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_grid_init(void)
{
    lv_recursive_lock();
    lv_grid_init();
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_grid_dsc_array(lv_obj_t * obj, const lv_coord_t col_dsc[], const lv_coord_t row_dsc[])
{
    lv_recursive_lock();
    lv_obj_set_grid_dsc_array(obj, col_dsc, row_dsc);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_grid_align(lv_obj_t * obj, lv_grid_align_t column_align, lv_grid_align_t row_align)
{
    lv_recursive_lock();
    lv_obj_set_grid_align(obj, column_align, row_align);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_grid_cell(lv_obj_t * obj, lv_grid_align_t column_align, uint8_t col_pos, uint8_t col_span, lv_grid_align_t row_align, uint8_t row_pos, uint8_t row_span)
{
    lv_recursive_lock();
    lv_obj_set_grid_cell(obj, column_align, col_pos, col_span, row_align, row_pos, row_span);
    lv_recursive_unlock();
    
}


static inline lv_coord_t safe_lv_grid_fr(uint8_t x)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_grid_fr(x);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_style_set_grid_row_dsc_array(lv_style_t * style, const lv_coord_t value[])
{
    lv_recursive_lock();
    lv_style_set_grid_row_dsc_array(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_grid_column_dsc_array(lv_style_t * style, const lv_coord_t value[])
{
    lv_recursive_lock();
    lv_style_set_grid_column_dsc_array(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_grid_row_align(lv_style_t * style, lv_grid_align_t value)
{
    lv_recursive_lock();
    lv_style_set_grid_row_align(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_grid_column_align(lv_style_t * style, lv_grid_align_t value)
{
    lv_recursive_lock();
    lv_style_set_grid_column_align(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_grid_cell_column_pos(lv_style_t * style, lv_coord_t value)
{
    lv_recursive_lock();
    lv_style_set_grid_cell_column_pos(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_grid_cell_column_span(lv_style_t * style, lv_coord_t value)
{
    lv_recursive_lock();
    lv_style_set_grid_cell_column_span(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_grid_cell_row_pos(lv_style_t * style, lv_coord_t value)
{
    lv_recursive_lock();
    lv_style_set_grid_cell_row_pos(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_grid_cell_row_span(lv_style_t * style, lv_coord_t value)
{
    lv_recursive_lock();
    lv_style_set_grid_cell_row_span(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_grid_cell_x_align(lv_style_t * style, lv_coord_t value)
{
    lv_recursive_lock();
    lv_style_set_grid_cell_x_align(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_style_set_grid_cell_y_align(lv_style_t * style, lv_coord_t value)
{
    lv_recursive_lock();
    lv_style_set_grid_cell_y_align(style, value);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_grid_row_dsc_array(lv_obj_t * obj, const lv_coord_t value[], lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_grid_row_dsc_array(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_grid_column_dsc_array(lv_obj_t * obj, const lv_coord_t value[], lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_grid_column_dsc_array(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_grid_row_align(lv_obj_t * obj, lv_grid_align_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_grid_row_align(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_grid_column_align(lv_obj_t * obj, lv_grid_align_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_grid_column_align(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_grid_cell_column_pos(lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_grid_cell_column_pos(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_grid_cell_column_span(lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_grid_cell_column_span(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_grid_cell_row_pos(lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_grid_cell_row_pos(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_grid_cell_row_span(lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_grid_cell_row_span(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_grid_cell_x_align(lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_grid_cell_x_align(obj, value, selector);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_style_grid_cell_y_align(lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_recursive_lock();
    lv_obj_set_style_grid_cell_y_align(obj, value, selector);
    lv_recursive_unlock();
    
}


const static inline lv_coord_t * safe_lv_obj_get_style_grid_row_dsc_array(const lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_coord_t * ret = lv_obj_get_style_grid_row_dsc_array(obj, part);
    lv_recursive_unlock();
    return ret;
}


const static inline lv_coord_t * safe_lv_obj_get_style_grid_column_dsc_array(const lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_coord_t * ret = lv_obj_get_style_grid_column_dsc_array(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_grid_align_t safe_lv_obj_get_style_grid_row_align(const lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_grid_align_t ret = lv_obj_get_style_grid_row_align(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_grid_align_t safe_lv_obj_get_style_grid_column_align(const lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_grid_align_t ret = lv_obj_get_style_grid_column_align(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_coord_t safe_lv_obj_get_style_grid_cell_column_pos(const lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_style_grid_cell_column_pos(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_coord_t safe_lv_obj_get_style_grid_cell_column_span(const lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_style_grid_cell_column_span(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_coord_t safe_lv_obj_get_style_grid_cell_row_pos(const lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_style_grid_cell_row_pos(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_coord_t safe_lv_obj_get_style_grid_cell_row_span(const lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_style_grid_cell_row_span(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_coord_t safe_lv_obj_get_style_grid_cell_x_align(const lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_style_grid_cell_x_align(obj, part);
    lv_recursive_unlock();
    return ret;
}


static inline lv_coord_t safe_lv_obj_get_style_grid_cell_y_align(const lv_obj_t * obj, uint32_t part)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_obj_get_style_grid_cell_y_align(obj, part);
    lv_recursive_unlock();
    return ret;
}


lv_theme_t * safe_lv_theme_default_init(lv_disp_t * disp, lv_color_t color_primary, lv_color_t color_secondary, bool dark, const lv_font_t * font)
{
    lv_recursive_lock();
    lv_theme_t * ret = lv_theme_default_init(disp, color_primary, color_secondary, dark, font);
    lv_recursive_unlock();
    return ret;
}


lv_theme_t * safe_lv_theme_default_get(void)
{
    lv_recursive_lock();
    lv_theme_t * ret = lv_theme_default_get();
    lv_recursive_unlock();
    return ret;
}


bool safe_lv_theme_default_is_inited(void)
{
    lv_recursive_lock();
    bool ret = lv_theme_default_is_inited();
    lv_recursive_unlock();
    return ret;
}


lv_theme_t * safe_lv_theme_mono_init(lv_disp_t * disp, bool dark_bg, const lv_font_t * font)
{
    lv_recursive_lock();
    lv_theme_t * ret = lv_theme_mono_init(disp, dark_bg, font);
    lv_recursive_unlock();
    return ret;
}


bool safe_lv_theme_mono_is_inited(void)
{
    lv_recursive_lock();
    bool ret = lv_theme_mono_is_inited();
    lv_recursive_unlock();
    return ret;
}


lv_theme_t * safe_lv_theme_basic_init(lv_disp_t * disp)
{
    lv_recursive_lock();
    lv_theme_t * ret = lv_theme_basic_init(disp);
    lv_recursive_unlock();
    return ret;
}


bool safe_lv_theme_basic_is_inited(void)
{
    lv_recursive_lock();
    bool ret = lv_theme_basic_is_inited();
    lv_recursive_unlock();
    return ret;
}


lv_obj_t * safe_lv_animimg_create(lv_obj_t * parent)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_animimg_create(parent);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_animimg_set_src(lv_obj_t * img, lv_img_dsc_t * dsc[], uint8_t num)
{
    lv_recursive_lock();
    lv_animimg_set_src(img, dsc, num);
    lv_recursive_unlock();
    
}


void safe_lv_animimg_start(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_animimg_start(obj);
    lv_recursive_unlock();
    
}


void safe_lv_animimg_set_duration(lv_obj_t * img, uint32_t duration)
{
    lv_recursive_lock();
    lv_animimg_set_duration(img, duration);
    lv_recursive_unlock();
    
}


void safe_lv_animimg_set_repeat_count(lv_obj_t * img, uint16_t count)
{
    lv_recursive_lock();
    lv_animimg_set_repeat_count(img, count);
    lv_recursive_unlock();
    
}


lv_obj_t * safe_lv_calendar_create(lv_obj_t * parent)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_calendar_create(parent);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_calendar_set_today_date(lv_obj_t * obj, uint32_t year, uint32_t month, uint32_t day)
{
    lv_recursive_lock();
    lv_calendar_set_today_date(obj, year, month, day);
    lv_recursive_unlock();
    
}


void safe_lv_calendar_set_showed_date(lv_obj_t * obj, uint32_t year, uint32_t month)
{
    lv_recursive_lock();
    lv_calendar_set_showed_date(obj, year, month);
    lv_recursive_unlock();
    
}


void safe_lv_calendar_set_highlighted_dates(lv_obj_t * obj, lv_calendar_date_t highlighted[], uint16_t date_num)
{
    lv_recursive_lock();
    lv_calendar_set_highlighted_dates(obj, highlighted, date_num);
    lv_recursive_unlock();
    
}


void safe_lv_calendar_set_day_names(lv_obj_t * obj, const char ** day_names)
{
    lv_recursive_lock();
    lv_calendar_set_day_names(obj, day_names);
    lv_recursive_unlock();
    
}


lv_obj_t * safe_lv_calendar_get_btnmatrix(const lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_calendar_get_btnmatrix(obj);
    lv_recursive_unlock();
    return ret;
}


const lv_calendar_date_t * safe_lv_calendar_get_today_date(const lv_obj_t * calendar)
{
    lv_recursive_lock();
    lv_calendar_date_t * ret = lv_calendar_get_today_date(calendar);
    lv_recursive_unlock();
    return ret;
}


const lv_calendar_date_t * safe_lv_calendar_get_showed_date(const lv_obj_t * calendar)
{
    lv_recursive_lock();
    lv_calendar_date_t * ret = lv_calendar_get_showed_date(calendar);
    lv_recursive_unlock();
    return ret;
}


lv_calendar_date_t * safe_lv_calendar_get_highlighted_dates(const lv_obj_t * calendar)
{
    lv_recursive_lock();
    lv_calendar_date_t * ret = lv_calendar_get_highlighted_dates(calendar);
    lv_recursive_unlock();
    return ret;
}


uint16_t safe_lv_calendar_get_highlighted_dates_num(const lv_obj_t * calendar)
{
    lv_recursive_lock();
    uint16_t ret = lv_calendar_get_highlighted_dates_num(calendar);
    lv_recursive_unlock();
    return ret;
}


lv_res_t safe_lv_calendar_get_pressed_date(const lv_obj_t * calendar, lv_calendar_date_t * date)
{
    lv_recursive_lock();
    lv_res_t ret = lv_calendar_get_pressed_date(calendar, date);
    lv_recursive_unlock();
    return ret;
}


lv_obj_t * safe_lv_calendar_header_arrow_create(lv_obj_t * parent)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_calendar_header_arrow_create(parent);
    lv_recursive_unlock();
    return ret;
}


lv_obj_t * safe_lv_calendar_header_dropdown_create(lv_obj_t * parent)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_calendar_header_dropdown_create(parent);
    lv_recursive_unlock();
    return ret;
}


lv_obj_t * safe_lv_chart_create(lv_obj_t * parent)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_chart_create(parent);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_chart_set_type(lv_obj_t * obj, lv_chart_type_t type)
{
    lv_recursive_lock();
    lv_chart_set_type(obj, type);
    lv_recursive_unlock();
    
}


void safe_lv_chart_set_point_count(lv_obj_t * obj, uint16_t cnt)
{
    lv_recursive_lock();
    lv_chart_set_point_count(obj, cnt);
    lv_recursive_unlock();
    
}


void safe_lv_chart_set_range(lv_obj_t * obj, lv_chart_axis_t axis, lv_coord_t min, lv_coord_t max)
{
    lv_recursive_lock();
    lv_chart_set_range(obj, axis, min, max);
    lv_recursive_unlock();
    
}


void safe_lv_chart_set_update_mode(lv_obj_t * obj, lv_chart_update_mode_t update_mode)
{
    lv_recursive_lock();
    lv_chart_set_update_mode(obj, update_mode);
    lv_recursive_unlock();
    
}


void safe_lv_chart_set_div_line_count(lv_obj_t * obj, uint8_t hdiv, uint8_t vdiv)
{
    lv_recursive_lock();
    lv_chart_set_div_line_count(obj, hdiv, vdiv);
    lv_recursive_unlock();
    
}


void safe_lv_chart_set_zoom_x(lv_obj_t * obj, uint16_t zoom_x)
{
    lv_recursive_lock();
    lv_chart_set_zoom_x(obj, zoom_x);
    lv_recursive_unlock();
    
}


void safe_lv_chart_set_zoom_y(lv_obj_t * obj, uint16_t zoom_y)
{
    lv_recursive_lock();
    lv_chart_set_zoom_y(obj, zoom_y);
    lv_recursive_unlock();
    
}


uint16_t safe_lv_chart_get_zoom_x(const lv_obj_t * obj)
{
    lv_recursive_lock();
    uint16_t ret = lv_chart_get_zoom_x(obj);
    lv_recursive_unlock();
    return ret;
}


uint16_t safe_lv_chart_get_zoom_y(const lv_obj_t * obj)
{
    lv_recursive_lock();
    uint16_t ret = lv_chart_get_zoom_y(obj);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_chart_set_axis_tick(lv_obj_t * obj, lv_chart_axis_t axis, lv_coord_t major_len, lv_coord_t minor_len, lv_coord_t major_cnt, lv_coord_t minor_cnt, bool label_en, lv_coord_t draw_size)
{
    lv_recursive_lock();
    lv_chart_set_axis_tick(obj, axis, major_len, minor_len, major_cnt, minor_cnt, label_en, draw_size);
    lv_recursive_unlock();
    
}


lv_chart_type_t safe_lv_chart_get_type(const lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_chart_type_t ret = lv_chart_get_type(obj);
    lv_recursive_unlock();
    return ret;
}


uint16_t safe_lv_chart_get_point_count(const lv_obj_t * obj)
{
    lv_recursive_lock();
    uint16_t ret = lv_chart_get_point_count(obj);
    lv_recursive_unlock();
    return ret;
}


uint16_t safe_lv_chart_get_x_start_point(const lv_obj_t * obj, lv_chart_series_t * ser)
{
    lv_recursive_lock();
    uint16_t ret = lv_chart_get_x_start_point(obj, ser);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_chart_get_point_pos_by_id(lv_obj_t * obj, lv_chart_series_t * ser, uint16_t id, lv_point_t * p_out)
{
    lv_recursive_lock();
    lv_chart_get_point_pos_by_id(obj, ser, id, p_out);
    lv_recursive_unlock();
    
}


void safe_lv_chart_refresh(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_chart_refresh(obj);
    lv_recursive_unlock();
    
}


lv_chart_series_t * safe_lv_chart_add_series(lv_obj_t * obj, lv_color_t color, lv_chart_axis_t axis)
{
    lv_recursive_lock();
    lv_chart_series_t * ret = lv_chart_add_series(obj, color, axis);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_chart_remove_series(lv_obj_t * obj, lv_chart_series_t * series)
{
    lv_recursive_lock();
    lv_chart_remove_series(obj, series);
    lv_recursive_unlock();
    
}


void safe_lv_chart_hide_series(lv_obj_t * chart, lv_chart_series_t * series, bool hide)
{
    lv_recursive_lock();
    lv_chart_hide_series(chart, series, hide);
    lv_recursive_unlock();
    
}


void safe_lv_chart_set_series_color(lv_obj_t * chart, lv_chart_series_t * series, lv_color_t color)
{
    lv_recursive_lock();
    lv_chart_set_series_color(chart, series, color);
    lv_recursive_unlock();
    
}


void safe_lv_chart_set_x_start_point(lv_obj_t * obj, lv_chart_series_t * ser, uint16_t id)
{
    lv_recursive_lock();
    lv_chart_set_x_start_point(obj, ser, id);
    lv_recursive_unlock();
    
}


lv_chart_series_t * safe_lv_chart_get_series_next(const lv_obj_t * chart, const lv_chart_series_t * ser)
{
    lv_recursive_lock();
    lv_chart_series_t * ret = lv_chart_get_series_next(chart, ser);
    lv_recursive_unlock();
    return ret;
}


lv_chart_cursor_t * safe_lv_chart_add_cursor(lv_obj_t * obj, lv_color_t color, lv_dir_t dir)
{
    lv_recursive_lock();
    lv_chart_cursor_t * ret = lv_chart_add_cursor(obj, color, dir);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_chart_set_cursor_pos(lv_obj_t * chart, lv_chart_cursor_t * cursor, lv_point_t * pos)
{
    lv_recursive_lock();
    lv_chart_set_cursor_pos(chart, cursor, pos);
    lv_recursive_unlock();
    
}


void safe_lv_chart_set_cursor_point(lv_obj_t * chart, lv_chart_cursor_t * cursor, lv_chart_series_t * ser, uint16_t point_id)
{
    lv_recursive_lock();
    lv_chart_set_cursor_point(chart, cursor, ser, point_id);
    lv_recursive_unlock();
    
}


lv_point_t safe_lv_chart_get_cursor_point(lv_obj_t * chart, lv_chart_cursor_t * cursor)
{
    lv_recursive_lock();
    lv_point_t ret = lv_chart_get_cursor_point(chart, cursor);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_chart_set_all_value(lv_obj_t * obj, lv_chart_series_t * ser, lv_coord_t value)
{
    lv_recursive_lock();
    lv_chart_set_all_value(obj, ser, value);
    lv_recursive_unlock();
    
}


void safe_lv_chart_set_next_value(lv_obj_t * obj, lv_chart_series_t * ser, lv_coord_t value)
{
    lv_recursive_lock();
    lv_chart_set_next_value(obj, ser, value);
    lv_recursive_unlock();
    
}


void safe_lv_chart_set_next_value2(lv_obj_t * obj, lv_chart_series_t * ser, lv_coord_t x_value, lv_coord_t y_value)
{
    lv_recursive_lock();
    lv_chart_set_next_value2(obj, ser, x_value, y_value);
    lv_recursive_unlock();
    
}


void safe_lv_chart_set_value_by_id(lv_obj_t * obj, lv_chart_series_t * ser, uint16_t id, lv_coord_t value)
{
    lv_recursive_lock();
    lv_chart_set_value_by_id(obj, ser, id, value);
    lv_recursive_unlock();
    
}


void safe_lv_chart_set_value_by_id2(lv_obj_t * obj, lv_chart_series_t * ser, uint16_t id, lv_coord_t x_value, lv_coord_t y_value)
{
    lv_recursive_lock();
    lv_chart_set_value_by_id2(obj, ser, id, x_value, y_value);
    lv_recursive_unlock();
    
}


void safe_lv_chart_set_ext_y_array(lv_obj_t * obj, lv_chart_series_t * ser, lv_coord_t array[])
{
    lv_recursive_lock();
    lv_chart_set_ext_y_array(obj, ser, array);
    lv_recursive_unlock();
    
}


void safe_lv_chart_set_ext_x_array(lv_obj_t * obj, lv_chart_series_t * ser, lv_coord_t array[])
{
    lv_recursive_lock();
    lv_chart_set_ext_x_array(obj, ser, array);
    lv_recursive_unlock();
    
}


lv_coord_t * safe_lv_chart_get_y_array(const lv_obj_t * obj, lv_chart_series_t * ser)
{
    lv_recursive_lock();
    lv_coord_t * ret = lv_chart_get_y_array(obj, ser);
    lv_recursive_unlock();
    return ret;
}


lv_coord_t * safe_lv_chart_get_x_array(const lv_obj_t * obj, lv_chart_series_t * ser)
{
    lv_recursive_lock();
    lv_coord_t * ret = lv_chart_get_x_array(obj, ser);
    lv_recursive_unlock();
    return ret;
}


uint32_t safe_lv_chart_get_pressed_point(const lv_obj_t * obj)
{
    lv_recursive_lock();
    uint32_t ret = lv_chart_get_pressed_point(obj);
    lv_recursive_unlock();
    return ret;
}


lv_obj_t * safe_lv_keyboard_create(lv_obj_t * parent)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_keyboard_create(parent);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_keyboard_set_textarea(lv_obj_t * kb, lv_obj_t * ta)
{
    lv_recursive_lock();
    lv_keyboard_set_textarea(kb, ta);
    lv_recursive_unlock();
    
}


void safe_lv_keyboard_set_mode(lv_obj_t * kb, lv_keyboard_mode_t mode)
{
    lv_recursive_lock();
    lv_keyboard_set_mode(kb, mode);
    lv_recursive_unlock();
    
}


void safe_lv_keyboard_set_popovers(lv_obj_t * kb, bool en)
{
    lv_recursive_lock();
    lv_keyboard_set_popovers(kb, en);
    lv_recursive_unlock();
    
}


void safe_lv_keyboard_set_map(lv_obj_t * kb, lv_keyboard_mode_t mode, const char * map[], const lv_btnmatrix_ctrl_t ctrl_map[])
{
    lv_recursive_lock();
    lv_keyboard_set_map(kb, mode, map, ctrl_map);
    lv_recursive_unlock();
    
}


lv_obj_t * safe_lv_keyboard_get_textarea(const lv_obj_t * kb)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_keyboard_get_textarea(kb);
    lv_recursive_unlock();
    return ret;
}


lv_keyboard_mode_t safe_lv_keyboard_get_mode(const lv_obj_t * kb)
{
    lv_recursive_lock();
    lv_keyboard_mode_t ret = lv_keyboard_get_mode(kb);
    lv_recursive_unlock();
    return ret;
}


bool safe_lv_btnmatrix_get_popovers(const lv_obj_t * obj)
{
    lv_recursive_lock();
    bool ret = lv_btnmatrix_get_popovers(obj);
    lv_recursive_unlock();
    return ret;
}


const static inline char ** safe_lv_keyboard_get_map_array(const lv_obj_t * kb)
{
    lv_recursive_lock();
    char ** ret = lv_keyboard_get_map_array(kb);
    lv_recursive_unlock();
    return ret;
}


static inline uint16_t safe_lv_keyboard_get_selected_btn(const lv_obj_t * obj)
{
    lv_recursive_lock();
    uint16_t ret = lv_keyboard_get_selected_btn(obj);
    lv_recursive_unlock();
    return ret;
}


const static inline char * safe_lv_keyboard_get_btn_text(const lv_obj_t * obj, uint16_t btn_id)
{
    lv_recursive_lock();
    char * ret = lv_keyboard_get_btn_text(obj, btn_id);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_keyboard_def_event_cb(lv_event_t * e)
{
    lv_recursive_lock();
    lv_keyboard_def_event_cb(e);
    lv_recursive_unlock();
    
}


lv_obj_t * safe_lv_list_create(lv_obj_t * parent)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_list_create(parent);
    lv_recursive_unlock();
    return ret;
}


lv_obj_t * safe_lv_list_add_text(lv_obj_t * list, const char * txt)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_list_add_text(list, txt);
    lv_recursive_unlock();
    return ret;
}


lv_obj_t * safe_lv_list_add_btn(lv_obj_t * list, const void * icon, const char * txt)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_list_add_btn(list, icon, txt);
    lv_recursive_unlock();
    return ret;
}


const char * safe_lv_list_get_btn_text(lv_obj_t * list, lv_obj_t * btn)
{
    lv_recursive_lock();
    char * ret = lv_list_get_btn_text(list, btn);
    lv_recursive_unlock();
    return ret;
}


lv_obj_t * safe_lv_menu_create(lv_obj_t * parent)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_menu_create(parent);
    lv_recursive_unlock();
    return ret;
}


lv_obj_t * safe_lv_menu_page_create(lv_obj_t * parent, char * title)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_menu_page_create(parent, title);
    lv_recursive_unlock();
    return ret;
}


lv_obj_t * safe_lv_menu_cont_create(lv_obj_t * parent)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_menu_cont_create(parent);
    lv_recursive_unlock();
    return ret;
}


lv_obj_t * safe_lv_menu_section_create(lv_obj_t * parent)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_menu_section_create(parent);
    lv_recursive_unlock();
    return ret;
}


lv_obj_t * safe_lv_menu_separator_create(lv_obj_t * parent)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_menu_separator_create(parent);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_menu_set_page(lv_obj_t * obj, lv_obj_t * page)
{
    lv_recursive_lock();
    lv_menu_set_page(obj, page);
    lv_recursive_unlock();
    
}


void safe_lv_menu_set_sidebar_page(lv_obj_t * obj, lv_obj_t * page)
{
    lv_recursive_lock();
    lv_menu_set_sidebar_page(obj, page);
    lv_recursive_unlock();
    
}


void safe_lv_menu_set_mode_header(lv_obj_t * obj, lv_menu_mode_header_t mode_header)
{
    lv_recursive_lock();
    lv_menu_set_mode_header(obj, mode_header);
    lv_recursive_unlock();
    
}


void safe_lv_menu_set_mode_root_back_btn(lv_obj_t * obj, lv_menu_mode_root_back_btn_t mode_root_back_btn)
{
    lv_recursive_lock();
    lv_menu_set_mode_root_back_btn(obj, mode_root_back_btn);
    lv_recursive_unlock();
    
}


void safe_lv_menu_set_load_page_event(lv_obj_t * menu, lv_obj_t * obj, lv_obj_t * page)
{
    lv_recursive_lock();
    lv_menu_set_load_page_event(menu, obj, page);
    lv_recursive_unlock();
    
}


lv_obj_t * safe_lv_menu_get_cur_main_page(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_menu_get_cur_main_page(obj);
    lv_recursive_unlock();
    return ret;
}


lv_obj_t * safe_lv_menu_get_cur_sidebar_page(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_menu_get_cur_sidebar_page(obj);
    lv_recursive_unlock();
    return ret;
}


lv_obj_t * safe_lv_menu_get_main_header(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_menu_get_main_header(obj);
    lv_recursive_unlock();
    return ret;
}


lv_obj_t * safe_lv_menu_get_main_header_back_btn(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_menu_get_main_header_back_btn(obj);
    lv_recursive_unlock();
    return ret;
}


lv_obj_t * safe_lv_menu_get_sidebar_header(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_menu_get_sidebar_header(obj);
    lv_recursive_unlock();
    return ret;
}


lv_obj_t * safe_lv_menu_get_sidebar_header_back_btn(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_menu_get_sidebar_header_back_btn(obj);
    lv_recursive_unlock();
    return ret;
}


bool safe_lv_menu_back_btn_is_root(lv_obj_t * menu, lv_obj_t * obj)
{
    lv_recursive_lock();
    bool ret = lv_menu_back_btn_is_root(menu, obj);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_menu_clear_history(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_menu_clear_history(obj);
    lv_recursive_unlock();
    
}


lv_obj_t * safe_lv_msgbox_create(lv_obj_t * parent, const char * title, const char * txt, const char * btn_txts[], bool add_close_btn)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_msgbox_create(parent, title, txt, btn_txts, add_close_btn);
    lv_recursive_unlock();
    return ret;
}


lv_obj_t * safe_lv_msgbox_get_title(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_msgbox_get_title(obj);
    lv_recursive_unlock();
    return ret;
}


lv_obj_t * safe_lv_msgbox_get_close_btn(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_msgbox_get_close_btn(obj);
    lv_recursive_unlock();
    return ret;
}


lv_obj_t * safe_lv_msgbox_get_text(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_msgbox_get_text(obj);
    lv_recursive_unlock();
    return ret;
}


lv_obj_t * safe_lv_msgbox_get_content(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_msgbox_get_content(obj);
    lv_recursive_unlock();
    return ret;
}


lv_obj_t * safe_lv_msgbox_get_btns(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_msgbox_get_btns(obj);
    lv_recursive_unlock();
    return ret;
}


uint16_t safe_lv_msgbox_get_active_btn(lv_obj_t * mbox)
{
    lv_recursive_lock();
    uint16_t ret = lv_msgbox_get_active_btn(mbox);
    lv_recursive_unlock();
    return ret;
}


const char * safe_lv_msgbox_get_active_btn_text(lv_obj_t * mbox)
{
    lv_recursive_lock();
    char * ret = lv_msgbox_get_active_btn_text(mbox);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_msgbox_close(lv_obj_t * mbox)
{
    lv_recursive_lock();
    lv_msgbox_close(mbox);
    lv_recursive_unlock();
    
}


void safe_lv_msgbox_close_async(lv_obj_t * mbox)
{
    lv_recursive_lock();
    lv_msgbox_close_async(mbox);
    lv_recursive_unlock();
    
}


lv_obj_t * safe_lv_meter_create(lv_obj_t * parent)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_meter_create(parent);
    lv_recursive_unlock();
    return ret;
}


lv_meter_scale_t * safe_lv_meter_add_scale(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_meter_scale_t * ret = lv_meter_add_scale(obj);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_meter_set_scale_ticks(lv_obj_t * obj, lv_meter_scale_t * scale, uint16_t cnt, uint16_t width, uint16_t len, lv_color_t color)
{
    lv_recursive_lock();
    lv_meter_set_scale_ticks(obj, scale, cnt, width, len, color);
    lv_recursive_unlock();
    
}


void safe_lv_meter_set_scale_major_ticks(lv_obj_t * obj, lv_meter_scale_t * scale, uint16_t nth, uint16_t width, uint16_t len, lv_color_t color, int16_t label_gap)
{
    lv_recursive_lock();
    lv_meter_set_scale_major_ticks(obj, scale, nth, width, len, color, label_gap);
    lv_recursive_unlock();
    
}


void safe_lv_meter_set_scale_range(lv_obj_t * obj, lv_meter_scale_t * scale, int32_t min, int32_t max, uint32_t angle_range, uint32_t rotation)
{
    lv_recursive_lock();
    lv_meter_set_scale_range(obj, scale, min, max, angle_range, rotation);
    lv_recursive_unlock();
    
}


lv_meter_indicator_t * safe_lv_meter_add_needle_line(lv_obj_t * obj, lv_meter_scale_t * scale, uint16_t width, lv_color_t color, int16_t r_mod)
{
    lv_recursive_lock();
    lv_meter_indicator_t * ret = lv_meter_add_needle_line(obj, scale, width, color, r_mod);
    lv_recursive_unlock();
    return ret;
}


lv_meter_indicator_t * safe_lv_meter_add_needle_img(lv_obj_t * obj, lv_meter_scale_t * scale, const void * src, lv_coord_t pivot_x, lv_coord_t pivot_y)
{
    lv_recursive_lock();
    lv_meter_indicator_t * ret = lv_meter_add_needle_img(obj, scale, src, pivot_x, pivot_y);
    lv_recursive_unlock();
    return ret;
}


lv_meter_indicator_t * safe_lv_meter_add_arc(lv_obj_t * obj, lv_meter_scale_t * scale, uint16_t width, lv_color_t color, int16_t r_mod)
{
    lv_recursive_lock();
    lv_meter_indicator_t * ret = lv_meter_add_arc(obj, scale, width, color, r_mod);
    lv_recursive_unlock();
    return ret;
}


lv_meter_indicator_t * safe_lv_meter_add_scale_lines(lv_obj_t * obj, lv_meter_scale_t * scale, lv_color_t color_start, lv_color_t color_end, bool local, int16_t width_mod)
{
    lv_recursive_lock();
    lv_meter_indicator_t * ret = lv_meter_add_scale_lines(obj, scale, color_start, color_end, local, width_mod);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_meter_set_indicator_value(lv_obj_t * obj, lv_meter_indicator_t * indic, int32_t value)
{
    lv_recursive_lock();
    lv_meter_set_indicator_value(obj, indic, value);
    lv_recursive_unlock();
    
}


void safe_lv_meter_set_indicator_start_value(lv_obj_t * obj, lv_meter_indicator_t * indic, int32_t value)
{
    lv_recursive_lock();
    lv_meter_set_indicator_start_value(obj, indic, value);
    lv_recursive_unlock();
    
}


void safe_lv_meter_set_indicator_end_value(lv_obj_t * obj, lv_meter_indicator_t * indic, int32_t value)
{
    lv_recursive_lock();
    lv_meter_set_indicator_end_value(obj, indic, value);
    lv_recursive_unlock();
    
}


lv_obj_t * safe_lv_spinbox_create(lv_obj_t * parent)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_spinbox_create(parent);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_spinbox_set_value(lv_obj_t * obj, int32_t i)
{
    lv_recursive_lock();
    lv_spinbox_set_value(obj, i);
    lv_recursive_unlock();
    
}


void safe_lv_spinbox_set_rollover(lv_obj_t * obj, bool b)
{
    lv_recursive_lock();
    lv_spinbox_set_rollover(obj, b);
    lv_recursive_unlock();
    
}


void safe_lv_spinbox_set_digit_format(lv_obj_t * obj, uint8_t digit_count, uint8_t separator_position)
{
    lv_recursive_lock();
    lv_spinbox_set_digit_format(obj, digit_count, separator_position);
    lv_recursive_unlock();
    
}


void safe_lv_spinbox_set_step(lv_obj_t * obj, uint32_t step)
{
    lv_recursive_lock();
    lv_spinbox_set_step(obj, step);
    lv_recursive_unlock();
    
}


void safe_lv_spinbox_set_range(lv_obj_t * obj, int32_t range_min, int32_t range_max)
{
    lv_recursive_lock();
    lv_spinbox_set_range(obj, range_min, range_max);
    lv_recursive_unlock();
    
}


void safe_lv_spinbox_set_cursor_pos(lv_obj_t * obj, uint8_t pos)
{
    lv_recursive_lock();
    lv_spinbox_set_cursor_pos(obj, pos);
    lv_recursive_unlock();
    
}


void safe_lv_spinbox_set_digit_step_direction(lv_obj_t * obj, lv_dir_t direction)
{
    lv_recursive_lock();
    lv_spinbox_set_digit_step_direction(obj, direction);
    lv_recursive_unlock();
    
}


bool safe_lv_spinbox_get_rollover(lv_obj_t * obj)
{
    lv_recursive_lock();
    bool ret = lv_spinbox_get_rollover(obj);
    lv_recursive_unlock();
    return ret;
}


int32_t safe_lv_spinbox_get_value(lv_obj_t * obj)
{
    lv_recursive_lock();
    int32_t ret = lv_spinbox_get_value(obj);
    lv_recursive_unlock();
    return ret;
}


int32_t safe_lv_spinbox_get_step(lv_obj_t * obj)
{
    lv_recursive_lock();
    int32_t ret = lv_spinbox_get_step(obj);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_spinbox_step_next(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_spinbox_step_next(obj);
    lv_recursive_unlock();
    
}


void safe_lv_spinbox_step_prev(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_spinbox_step_prev(obj);
    lv_recursive_unlock();
    
}


void safe_lv_spinbox_increment(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_spinbox_increment(obj);
    lv_recursive_unlock();
    
}


void safe_lv_spinbox_decrement(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_spinbox_decrement(obj);
    lv_recursive_unlock();
    
}


lv_obj_t * safe_lv_spinner_create(lv_obj_t * parent, uint32_t time, uint32_t arc_length)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_spinner_create(parent, time, arc_length);
    lv_recursive_unlock();
    return ret;
}


lv_obj_t * safe_lv_tabview_create(lv_obj_t * parent, lv_dir_t tab_pos, lv_coord_t tab_size)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_tabview_create(parent, tab_pos, tab_size);
    lv_recursive_unlock();
    return ret;
}


lv_obj_t * safe_lv_tabview_add_tab(lv_obj_t * tv, const char * name)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_tabview_add_tab(tv, name);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_tabview_rename_tab(lv_obj_t * obj, uint32_t tab_id, const char * new_name)
{
    lv_recursive_lock();
    lv_tabview_rename_tab(obj, tab_id, new_name);
    lv_recursive_unlock();
    
}


lv_obj_t * safe_lv_tabview_get_content(lv_obj_t * tv)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_tabview_get_content(tv);
    lv_recursive_unlock();
    return ret;
}


lv_obj_t * safe_lv_tabview_get_tab_btns(lv_obj_t * tv)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_tabview_get_tab_btns(tv);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_tabview_set_act(lv_obj_t * obj, uint32_t id, lv_anim_enable_t anim_en)
{
    lv_recursive_lock();
    lv_tabview_set_act(obj, id, anim_en);
    lv_recursive_unlock();
    
}


uint16_t safe_lv_tabview_get_tab_act(lv_obj_t * tv)
{
    lv_recursive_lock();
    uint16_t ret = lv_tabview_get_tab_act(tv);
    lv_recursive_unlock();
    return ret;
}


lv_obj_t * safe_lv_tileview_create(lv_obj_t * parent)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_tileview_create(parent);
    lv_recursive_unlock();
    return ret;
}


lv_obj_t * safe_lv_tileview_add_tile(lv_obj_t * tv, uint8_t col_id, uint8_t row_id, lv_dir_t dir)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_tileview_add_tile(tv, col_id, row_id, dir);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_obj_set_tile(lv_obj_t * tv, lv_obj_t * tile_obj, lv_anim_enable_t anim_en)
{
    lv_recursive_lock();
    lv_obj_set_tile(tv, tile_obj, anim_en);
    lv_recursive_unlock();
    
}


void safe_lv_obj_set_tile_id(lv_obj_t * tv, uint32_t col_id, uint32_t row_id, lv_anim_enable_t anim_en)
{
    lv_recursive_lock();
    lv_obj_set_tile_id(tv, col_id, row_id, anim_en);
    lv_recursive_unlock();
    
}


lv_obj_t * safe_lv_tileview_get_tile_act(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_tileview_get_tile_act(obj);
    lv_recursive_unlock();
    return ret;
}


lv_obj_t * safe_lv_win_create(lv_obj_t * parent, lv_coord_t header_height)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_win_create(parent, header_height);
    lv_recursive_unlock();
    return ret;
}


lv_obj_t * safe_lv_win_add_title(lv_obj_t * win, const char * txt)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_win_add_title(win, txt);
    lv_recursive_unlock();
    return ret;
}


lv_obj_t * safe_lv_win_add_btn(lv_obj_t * win, const void * icon, lv_coord_t btn_w)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_win_add_btn(win, icon, btn_w);
    lv_recursive_unlock();
    return ret;
}


lv_obj_t * safe_lv_win_get_header(lv_obj_t * win)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_win_get_header(win);
    lv_recursive_unlock();
    return ret;
}


lv_obj_t * safe_lv_win_get_content(lv_obj_t * win)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_win_get_content(win);
    lv_recursive_unlock();
    return ret;
}


lv_obj_t * safe_lv_colorwheel_create(lv_obj_t * parent, bool knob_recolor)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_colorwheel_create(parent, knob_recolor);
    lv_recursive_unlock();
    return ret;
}


bool safe_lv_colorwheel_set_hsv(lv_obj_t * obj, lv_color_hsv_t hsv)
{
    lv_recursive_lock();
    bool ret = lv_colorwheel_set_hsv(obj, hsv);
    lv_recursive_unlock();
    return ret;
}


bool safe_lv_colorwheel_set_rgb(lv_obj_t * obj, lv_color_t color)
{
    lv_recursive_lock();
    bool ret = lv_colorwheel_set_rgb(obj, color);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_colorwheel_set_mode(lv_obj_t * obj, lv_colorwheel_mode_t mode)
{
    lv_recursive_lock();
    lv_colorwheel_set_mode(obj, mode);
    lv_recursive_unlock();
    
}


void safe_lv_colorwheel_set_mode_fixed(lv_obj_t * obj, bool fixed)
{
    lv_recursive_lock();
    lv_colorwheel_set_mode_fixed(obj, fixed);
    lv_recursive_unlock();
    
}


lv_color_hsv_t safe_lv_colorwheel_get_hsv(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_color_hsv_t ret = lv_colorwheel_get_hsv(obj);
    lv_recursive_unlock();
    return ret;
}


lv_color_t safe_lv_colorwheel_get_rgb(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_color_t ret = lv_colorwheel_get_rgb(obj);
    lv_recursive_unlock();
    return ret;
}


lv_colorwheel_mode_t safe_lv_colorwheel_get_color_mode(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_colorwheel_mode_t ret = lv_colorwheel_get_color_mode(obj);
    lv_recursive_unlock();
    return ret;
}


bool safe_lv_colorwheel_get_color_mode_fixed(lv_obj_t * obj)
{
    lv_recursive_lock();
    bool ret = lv_colorwheel_get_color_mode_fixed(obj);
    lv_recursive_unlock();
    return ret;
}


lv_obj_t * safe_lv_led_create(lv_obj_t * parent)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_led_create(parent);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_led_set_color(lv_obj_t * led, lv_color_t color)
{
    lv_recursive_lock();
    lv_led_set_color(led, color);
    lv_recursive_unlock();
    
}


void safe_lv_led_set_brightness(lv_obj_t * led, uint8_t bright)
{
    lv_recursive_lock();
    lv_led_set_brightness(led, bright);
    lv_recursive_unlock();
    
}


void safe_lv_led_on(lv_obj_t * led)
{
    lv_recursive_lock();
    lv_led_on(led);
    lv_recursive_unlock();
    
}


void safe_lv_led_off(lv_obj_t * led)
{
    lv_recursive_lock();
    lv_led_off(led);
    lv_recursive_unlock();
    
}


void safe_lv_led_toggle(lv_obj_t * led)
{
    lv_recursive_lock();
    lv_led_toggle(led);
    lv_recursive_unlock();
    
}


uint8_t safe_lv_led_get_brightness(const lv_obj_t * obj)
{
    lv_recursive_lock();
    uint8_t ret = lv_led_get_brightness(obj);
    lv_recursive_unlock();
    return ret;
}


lv_obj_t * safe_lv_imgbtn_create(lv_obj_t * parent)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_imgbtn_create(parent);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_imgbtn_set_src(lv_obj_t * imgbtn, lv_imgbtn_state_t state, const void * src_left, const void * src_mid, const void * src_right)
{
    lv_recursive_lock();
    lv_imgbtn_set_src(imgbtn, state, src_left, src_mid, src_right);
    lv_recursive_unlock();
    
}


void safe_lv_imgbtn_set_state(lv_obj_t * imgbtn, lv_imgbtn_state_t state)
{
    lv_recursive_lock();
    lv_imgbtn_set_state(imgbtn, state);
    lv_recursive_unlock();
    
}


const void * safe_lv_imgbtn_get_src_left(lv_obj_t * imgbtn, lv_imgbtn_state_t state)
{
    lv_recursive_lock();
    void * ret = lv_imgbtn_get_src_left(imgbtn, state);
    lv_recursive_unlock();
    
}


const void * safe_lv_imgbtn_get_src_middle(lv_obj_t * imgbtn, lv_imgbtn_state_t state)
{
    lv_recursive_lock();
    void * ret = lv_imgbtn_get_src_middle(imgbtn, state);
    lv_recursive_unlock();
    
}


const void * safe_lv_imgbtn_get_src_right(lv_obj_t * imgbtn, lv_imgbtn_state_t state)
{
    lv_recursive_lock();
    void * ret = lv_imgbtn_get_src_right(imgbtn, state);
    lv_recursive_unlock();
    
}


lv_obj_t * safe_lv_spangroup_create(lv_obj_t * par)
{
    lv_recursive_lock();
    lv_obj_t * ret = lv_spangroup_create(par);
    lv_recursive_unlock();
    return ret;
}


lv_span_t * safe_lv_spangroup_new_span(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_span_t * ret = lv_spangroup_new_span(obj);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_spangroup_del_span(lv_obj_t * obj, lv_span_t * span)
{
    lv_recursive_lock();
    lv_spangroup_del_span(obj, span);
    lv_recursive_unlock();
    
}


void safe_lv_span_set_text(lv_span_t * span, const char * text)
{
    lv_recursive_lock();
    lv_span_set_text(span, text);
    lv_recursive_unlock();
    
}


void safe_lv_span_set_text_static(lv_span_t * span, const char * text)
{
    lv_recursive_lock();
    lv_span_set_text_static(span, text);
    lv_recursive_unlock();
    
}


void safe_lv_spangroup_set_align(lv_obj_t * obj, lv_text_align_t align)
{
    lv_recursive_lock();
    lv_spangroup_set_align(obj, align);
    lv_recursive_unlock();
    
}


void safe_lv_spangroup_set_overflow(lv_obj_t * obj, lv_span_overflow_t overflow)
{
    lv_recursive_lock();
    lv_spangroup_set_overflow(obj, overflow);
    lv_recursive_unlock();
    
}


void safe_lv_spangroup_set_indent(lv_obj_t * obj, lv_coord_t indent)
{
    lv_recursive_lock();
    lv_spangroup_set_indent(obj, indent);
    lv_recursive_unlock();
    
}


void safe_lv_spangroup_set_mode(lv_obj_t * obj, lv_span_mode_t mode)
{
    lv_recursive_lock();
    lv_spangroup_set_mode(obj, mode);
    lv_recursive_unlock();
    
}


void safe_lv_spangroup_set_lines(lv_obj_t * obj, int32_t lines)
{
    lv_recursive_lock();
    lv_spangroup_set_lines(obj, lines);
    lv_recursive_unlock();
    
}


lv_span_t * safe_lv_spangroup_get_child(const lv_obj_t * obj, int32_t id)
{
    lv_recursive_lock();
    lv_span_t * ret = lv_spangroup_get_child(obj, id);
    lv_recursive_unlock();
    return ret;
}


uint32_t safe_lv_spangroup_get_child_cnt(const lv_obj_t * obj)
{
    lv_recursive_lock();
    uint32_t ret = lv_spangroup_get_child_cnt(obj);
    lv_recursive_unlock();
    return ret;
}


lv_text_align_t safe_lv_spangroup_get_align(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_text_align_t ret = lv_spangroup_get_align(obj);
    lv_recursive_unlock();
    return ret;
}


lv_span_overflow_t safe_lv_spangroup_get_overflow(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_span_overflow_t ret = lv_spangroup_get_overflow(obj);
    lv_recursive_unlock();
    return ret;
}


lv_coord_t safe_lv_spangroup_get_indent(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_spangroup_get_indent(obj);
    lv_recursive_unlock();
    return ret;
}


lv_span_mode_t safe_lv_spangroup_get_mode(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_span_mode_t ret = lv_spangroup_get_mode(obj);
    lv_recursive_unlock();
    return ret;
}


int32_t safe_lv_spangroup_get_lines(lv_obj_t * obj)
{
    lv_recursive_lock();
    int32_t ret = lv_spangroup_get_lines(obj);
    lv_recursive_unlock();
    return ret;
}


lv_coord_t safe_lv_spangroup_get_max_line_h(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_spangroup_get_max_line_h(obj);
    lv_recursive_unlock();
    return ret;
}


uint32_t safe_lv_spangroup_get_expand_width(lv_obj_t * obj, uint32_t max_width)
{
    lv_recursive_lock();
    uint32_t ret = lv_spangroup_get_expand_width(obj, max_width);
    lv_recursive_unlock();
    return ret;
}


lv_coord_t safe_lv_spangroup_get_expand_height(lv_obj_t * obj, lv_coord_t width)
{
    lv_recursive_lock();
    lv_coord_t ret = lv_spangroup_get_expand_height(obj, width);
    lv_recursive_unlock();
    return ret;
}


void safe_lv_spangroup_refr_mode(lv_obj_t * obj)
{
    lv_recursive_lock();
    lv_spangroup_refr_mode(obj);
    lv_recursive_unlock();
    
}


void safe_lv_extra_init(void)
{
    lv_recursive_lock();
    lv_extra_init();
    lv_recursive_unlock();
    
}


static inline int safe_lv_version_major(void)
{
    lv_recursive_lock();
    int ret = lv_version_major();
    lv_recursive_unlock();
    return ret;
}


static inline int safe_lv_version_minor(void)
{
    lv_recursive_lock();
    int ret = lv_version_minor();
    lv_recursive_unlock();
    return ret;
}


static inline int safe_lv_version_patch(void)
{
    lv_recursive_lock();
    int ret = lv_version_patch();
    lv_recursive_unlock();
    return ret;
}


const static inline char * safe_lv_version_info(void)
{
    lv_recursive_lock();
    char * ret = lv_version_info();
    lv_recursive_unlock();
    return ret;
}



