/**
 * @file: safe_lvgl.h 
 * @note: This document is generated using [safe_lvgl_converter](https://github.com/h13-0/safe_lvgl_converter),
 *            based on lvgl version 8.3.4.
 * @date: 2022/12/22
 * @time: 00:53:40
 */

#ifndef __SAFE_LVGL_H__ 
#define __SAFE_LVGL_H__ 
#include "lvgl.h"

void safe_lvgl_init(void);

void lv_recursive_unlock(void);

void lv_recursive_lock(void);

void safe_lv_tick_inc(uint32_t tick_period);


uint32_t safe_lv_tick_get(void);


uint32_t safe_lv_tick_elaps(uint32_t prev_tick);


uint32_t safe_lv_timer_handler(void);


static inline uint32_t safe_lv_timer_handler_run_in_period(uint32_t ms);


lv_timer_t * safe_lv_timer_create_basic(void);


lv_timer_t * safe_lv_timer_create(lv_timer_cb_t timer_xcb, uint32_t period, void * user_data);


void safe_lv_timer_del(lv_timer_t * timer);


void safe_lv_timer_pause(lv_timer_t * timer);


void safe_lv_timer_resume(lv_timer_t * timer);


void safe_lv_timer_set_cb(lv_timer_t * timer, lv_timer_cb_t timer_cb);


void safe_lv_timer_set_period(lv_timer_t * timer, uint32_t period);


void safe_lv_timer_ready(lv_timer_t * timer);


void safe_lv_timer_set_repeat_count(lv_timer_t * timer, int32_t repeat_count);


void safe_lv_timer_reset(lv_timer_t * timer);


void safe_lv_timer_enable(bool en);


uint8_t safe_lv_timer_get_idle(void);


lv_timer_t * safe_lv_timer_get_next(lv_timer_t * timer);


int16_t safe_lv_trigo_sin(int16_t angle);


static inline int16_t safe_lv_trigo_cos(int16_t angle);


uint32_t safe_lv_bezier3(uint32_t t, uint32_t u0, uint32_t u1, uint32_t u2, uint32_t u3);


uint16_t safe_lv_atan2(int x, int y);


void safe_lv_sqrt(uint32_t x, lv_sqrt_res_t * q, uint32_t mask);


int64_t safe_lv_pow(int64_t base, int8_t exp);


int32_t safe_lv_map(int32_t x, int32_t min_in, int32_t max_in, int32_t min_out, int32_t max_out);


uint32_t safe_lv_rand(uint32_t min, uint32_t max);


void safe_lv_mem_init(void);


void safe_lv_mem_deinit(void);


void * safe_lv_mem_alloc(size_t size);


void safe_lv_mem_free(void * data);


void * safe_lv_mem_realloc(void * data_p, size_t new_size);


lv_res_t safe_lv_mem_test(void);


void safe_lv_mem_monitor(lv_mem_monitor_t * mon_p);


void * safe_lv_mem_buf_get(uint32_t size);


void safe_lv_mem_buf_release(void * p);


void safe_lv_mem_buf_free_all(void);


void * safe_lv_memcpy(void * dst, const void * src, size_t len);


static inline void * safe_lv_memcpy_small(void * dst, const void * src, size_t len);


void safe_lv_memset(void * dst, uint8_t v, size_t len);


void safe_lv_memset_00(void * dst, size_t len);


void safe_lv_memset_ff(void * dst, size_t len);


lv_res_t safe_lv_async_call(lv_async_cb_t async_xcb, void * user_data);


lv_res_t safe_lv_async_call_cancel(lv_async_cb_t async_xcb, void * user_data);


void safe_lv_anim_init(lv_anim_t * a);


static inline void safe_lv_anim_set_var(lv_anim_t * a, void * var);


static inline void safe_lv_anim_set_exec_cb(lv_anim_t * a, lv_anim_exec_xcb_t exec_cb);


static inline void safe_lv_anim_set_time(lv_anim_t * a, uint32_t duration);


static inline void safe_lv_anim_set_delay(lv_anim_t * a, uint32_t delay);


static inline void safe_lv_anim_set_values(lv_anim_t * a, int32_t start, int32_t end);


static inline void safe_lv_anim_set_custom_exec_cb(lv_anim_t * a, lv_anim_custom_exec_cb_t exec_cb);


static inline void safe_lv_anim_set_path_cb(lv_anim_t * a, lv_anim_path_cb_t path_cb);


static inline void safe_lv_anim_set_start_cb(lv_anim_t * a, lv_anim_start_cb_t start_cb);


static inline void safe_lv_anim_set_get_value_cb(lv_anim_t * a, lv_anim_get_value_cb_t get_value_cb);


static inline void safe_lv_anim_set_ready_cb(lv_anim_t * a, lv_anim_ready_cb_t ready_cb);


static inline void safe_lv_anim_set_deleted_cb(lv_anim_t * a, lv_anim_deleted_cb_t deleted_cb);


static inline void safe_lv_anim_set_playback_time(lv_anim_t * a, uint32_t time);


static inline void safe_lv_anim_set_playback_delay(lv_anim_t * a, uint32_t delay);


static inline void safe_lv_anim_set_repeat_count(lv_anim_t * a, uint16_t cnt);


static inline void safe_lv_anim_set_repeat_delay(lv_anim_t * a, uint32_t delay);


static inline void safe_lv_anim_set_early_apply(lv_anim_t * a, bool en);


static inline void safe_lv_anim_set_user_data(lv_anim_t * a, void * user_data);


lv_anim_t * safe_lv_anim_start(const lv_anim_t * a);


static inline uint32_t safe_lv_anim_get_delay(lv_anim_t * a);


uint32_t safe_lv_anim_get_playtime(lv_anim_t * a);


static inline void * safe_lv_anim_get_user_data(lv_anim_t * a);


bool safe_lv_anim_del(void * var, lv_anim_exec_xcb_t exec_cb);


void safe_lv_anim_del_all(void);


lv_anim_t * safe_lv_anim_get(void * var, lv_anim_exec_xcb_t exec_cb);


struct _lv_timer_t * safe_lv_anim_get_timer(void);


static inline bool safe_lv_anim_custom_del(lv_anim_t * a, lv_anim_custom_exec_cb_t exec_cb);


static inline lv_anim_t * safe_lv_anim_custom_get(lv_anim_t * a, lv_anim_custom_exec_cb_t exec_cb);


uint16_t safe_lv_anim_count_running(void);


uint32_t safe_lv_anim_speed_to_time(uint32_t speed, int32_t start, int32_t end);


void safe_lv_anim_refr_now(void);


int32_t safe_lv_anim_path_linear(const lv_anim_t * a);


int32_t safe_lv_anim_path_ease_in(const lv_anim_t * a);


int32_t safe_lv_anim_path_ease_out(const lv_anim_t * a);


int32_t safe_lv_anim_path_ease_in_out(const lv_anim_t * a);


int32_t safe_lv_anim_path_overshoot(const lv_anim_t * a);


int32_t safe_lv_anim_path_bounce(const lv_anim_t * a);


int32_t safe_lv_anim_path_step(const lv_anim_t * a);


lv_anim_timeline_t * safe_lv_anim_timeline_create(void);


void safe_lv_anim_timeline_del(lv_anim_timeline_t * at);


void safe_lv_anim_timeline_add(lv_anim_timeline_t * at, uint32_t start_time, lv_anim_t * a);


uint32_t safe_lv_anim_timeline_start(lv_anim_timeline_t * at);


void safe_lv_anim_timeline_stop(lv_anim_timeline_t * at);


void safe_lv_anim_timeline_set_reverse(lv_anim_timeline_t * at, bool reverse);


void safe_lv_anim_timeline_set_progress(lv_anim_timeline_t * at, uint16_t progress);


uint32_t safe_lv_anim_timeline_get_playtime(lv_anim_timeline_t * at);


bool safe_lv_anim_timeline_get_reverse(lv_anim_timeline_t * at);


int safe_lv_vsnprintf(char * buffer, size_t count, const char * format, va_list va);


void safe_lv_area_set(lv_area_t * area_p, lv_coord_t x1, lv_coord_t y1, lv_coord_t x2, lv_coord_t y2);


static inline void safe_lv_area_copy(lv_area_t * dest, const lv_area_t * src);


static inline lv_coord_t safe_lv_area_get_width(const lv_area_t * area_p);


static inline lv_coord_t safe_lv_area_get_height(const lv_area_t * area_p);


void safe_lv_area_set_width(lv_area_t * area_p, lv_coord_t w);


void safe_lv_area_set_height(lv_area_t * area_p, lv_coord_t h);


uint32_t safe_lv_area_get_size(const lv_area_t * area_p);


void safe_lv_area_increase(lv_area_t * area, lv_coord_t w_extra, lv_coord_t h_extra);


void safe_lv_area_move(lv_area_t * area, lv_coord_t x_ofs, lv_coord_t y_ofs);


void safe_lv_area_align(const lv_area_t * base, lv_area_t * to_align, lv_align_t align, lv_coord_t ofs_x, lv_coord_t ofs_y);


void safe_lv_point_transform(lv_point_t * p, int32_t angle, int32_t zoom, const lv_point_t * pivot);


static inline lv_coord_t safe_lv_pct(lv_coord_t x);


const uint8_t * safe_lv_font_get_glyph_bitmap(const lv_font_t * font_p, uint32_t letter);


bool safe_lv_font_get_glyph_dsc(const lv_font_t * font_p, lv_font_glyph_dsc_t * dsc_out, uint32_t letter, uint32_t letter_next);


uint16_t safe_lv_font_get_glyph_width(const lv_font_t * font, uint32_t letter, uint32_t letter_next);


static inline lv_coord_t safe_lv_font_get_line_height(const lv_font_t * font_p);


const static inline lv_font_t * safe_lv_font_default(void);


static inline uint8_t safe_lv_color_to1(lv_color_t color);


static inline uint8_t safe_lv_color_to8(lv_color_t color);


static inline uint16_t safe_lv_color_to16(lv_color_t color);


static inline uint32_t safe_lv_color_to32(lv_color_t color);


static inline lv_color_t safe_lv_color_mix(lv_color_t c1, lv_color_t c2, uint8_t mix);


static inline void safe_lv_color_premult(lv_color_t c, uint8_t mix, uint16_t * out);


static inline lv_color_t safe_lv_color_mix_premult(uint16_t * premult_c1, lv_color_t c2, uint8_t mix);


static inline void safe_lv_color_mix_with_alpha(lv_color_t bg_color, lv_opa_t bg_opa, lv_color_t fg_color, lv_opa_t fg_opa, lv_color_t * res_color, lv_opa_t * res_opa);


static inline uint8_t safe_lv_color_brightness(lv_color_t color);


static inline lv_color_t safe_lv_color_make(uint8_t r, uint8_t g, uint8_t b);


static inline lv_color_t safe_lv_color_hex(uint32_t c);


static inline lv_color_t safe_lv_color_hex3(uint32_t c);


static inline void safe_lv_color_filter_dsc_init(lv_color_filter_dsc_t * dsc, lv_color_filter_cb_t cb);


void safe_lv_color_fill(lv_color_t * buf, lv_color_t color, uint32_t px_num);


lv_color_t safe_lv_color_lighten(lv_color_t c, lv_opa_t lvl);


lv_color_t safe_lv_color_darken(lv_color_t c, lv_opa_t lvl);


lv_color_t safe_lv_color_change_lightness(lv_color_t c, lv_opa_t lvl);


lv_color_t safe_lv_color_hsv_to_rgb(uint16_t h, uint8_t s, uint8_t v);


lv_color_hsv_t safe_lv_color_rgb_to_hsv(uint8_t r8, uint8_t g8, uint8_t b8);


lv_color_hsv_t safe_lv_color_to_hsv(lv_color_t color);


static inline lv_color_t safe_lv_color_chroma_key(void);


lv_color_t safe_lv_palette_main(lv_palette_t p);


static inline lv_color_t safe_lv_color_white(void);


static inline lv_color_t safe_lv_color_black(void);


lv_color_t safe_lv_palette_lighten(lv_palette_t p, uint8_t lvl);


lv_color_t safe_lv_palette_darken(lv_palette_t p, uint8_t lvl);


void safe_lv_txt_get_size(lv_point_t * size_res, const char * text, const lv_font_t * font, lv_coord_t letter_space, lv_coord_t line_space, lv_coord_t max_width, lv_text_flag_t flag);


lv_coord_t safe_lv_txt_get_width(const char * txt, uint32_t length, const lv_font_t * font, lv_coord_t letter_space, lv_text_flag_t flag);


static inline void safe_lv_bidi_calculate_align(lv_text_align_t * align, lv_base_dir_t * base_dir, const char * txt);


void safe_lv_style_init(lv_style_t * style);


void safe_lv_style_reset(lv_style_t * style);


lv_style_prop_t safe_lv_style_register_prop(uint8_t flag);


lv_style_prop_t safe_lv_style_get_num_custom_props(void);


bool safe_lv_style_remove_prop(lv_style_t * style, lv_style_prop_t prop);


void safe_lv_style_set_prop(lv_style_t * style, lv_style_prop_t prop, lv_style_value_t value);


void safe_lv_style_set_prop_meta(lv_style_t * style, lv_style_prop_t prop, uint16_t meta);


lv_style_res_t safe_lv_style_get_prop(const lv_style_t * style, lv_style_prop_t prop, lv_style_value_t * value);


void safe_lv_style_transition_dsc_init(lv_style_transition_dsc_t * tr, const lv_style_prop_t props[], lv_anim_path_cb_t path_cb, uint32_t time, uint32_t delay, void * user_data);


lv_style_value_t safe_lv_style_prop_get_default(lv_style_prop_t prop);


static inline lv_style_res_t safe_lv_style_get_prop_inlined(const lv_style_t * style, lv_style_prop_t prop, lv_style_value_t * value);


bool safe_lv_style_is_empty(const lv_style_t * style);


void safe_lv_style_set_width(lv_style_t * style, lv_coord_t value);


void safe_lv_style_set_min_width(lv_style_t * style, lv_coord_t value);


void safe_lv_style_set_max_width(lv_style_t * style, lv_coord_t value);


void safe_lv_style_set_height(lv_style_t * style, lv_coord_t value);


void safe_lv_style_set_min_height(lv_style_t * style, lv_coord_t value);


void safe_lv_style_set_max_height(lv_style_t * style, lv_coord_t value);


void safe_lv_style_set_x(lv_style_t * style, lv_coord_t value);


void safe_lv_style_set_y(lv_style_t * style, lv_coord_t value);


void safe_lv_style_set_align(lv_style_t * style, lv_align_t value);


void safe_lv_style_set_transform_width(lv_style_t * style, lv_coord_t value);


void safe_lv_style_set_transform_height(lv_style_t * style, lv_coord_t value);


void safe_lv_style_set_translate_x(lv_style_t * style, lv_coord_t value);


void safe_lv_style_set_translate_y(lv_style_t * style, lv_coord_t value);


void safe_lv_style_set_transform_zoom(lv_style_t * style, lv_coord_t value);


void safe_lv_style_set_transform_angle(lv_style_t * style, lv_coord_t value);


void safe_lv_style_set_transform_pivot_x(lv_style_t * style, lv_coord_t value);


void safe_lv_style_set_transform_pivot_y(lv_style_t * style, lv_coord_t value);


void safe_lv_style_set_pad_top(lv_style_t * style, lv_coord_t value);


void safe_lv_style_set_pad_bottom(lv_style_t * style, lv_coord_t value);


void safe_lv_style_set_pad_left(lv_style_t * style, lv_coord_t value);


void safe_lv_style_set_pad_right(lv_style_t * style, lv_coord_t value);


void safe_lv_style_set_pad_row(lv_style_t * style, lv_coord_t value);


void safe_lv_style_set_pad_column(lv_style_t * style, lv_coord_t value);


void safe_lv_style_set_bg_color(lv_style_t * style, lv_color_t value);


void safe_lv_style_set_bg_opa(lv_style_t * style, lv_opa_t value);


void safe_lv_style_set_bg_grad_color(lv_style_t * style, lv_color_t value);


void safe_lv_style_set_bg_grad_dir(lv_style_t * style, lv_grad_dir_t value);


void safe_lv_style_set_bg_main_stop(lv_style_t * style, lv_coord_t value);


void safe_lv_style_set_bg_grad_stop(lv_style_t * style, lv_coord_t value);


void safe_lv_style_set_bg_grad(lv_style_t * style, const lv_grad_dsc_t * value);


void safe_lv_style_set_bg_dither_mode(lv_style_t * style, lv_dither_mode_t value);


void safe_lv_style_set_bg_img_src(lv_style_t * style, const void * value);


void safe_lv_style_set_bg_img_opa(lv_style_t * style, lv_opa_t value);


void safe_lv_style_set_bg_img_recolor(lv_style_t * style, lv_color_t value);


void safe_lv_style_set_bg_img_recolor_opa(lv_style_t * style, lv_opa_t value);


void safe_lv_style_set_bg_img_tiled(lv_style_t * style, bool value);


void safe_lv_style_set_border_color(lv_style_t * style, lv_color_t value);


void safe_lv_style_set_border_opa(lv_style_t * style, lv_opa_t value);


void safe_lv_style_set_border_width(lv_style_t * style, lv_coord_t value);


void safe_lv_style_set_border_side(lv_style_t * style, lv_border_side_t value);


void safe_lv_style_set_border_post(lv_style_t * style, bool value);


void safe_lv_style_set_outline_width(lv_style_t * style, lv_coord_t value);


void safe_lv_style_set_outline_color(lv_style_t * style, lv_color_t value);


void safe_lv_style_set_outline_opa(lv_style_t * style, lv_opa_t value);


void safe_lv_style_set_outline_pad(lv_style_t * style, lv_coord_t value);


void safe_lv_style_set_shadow_width(lv_style_t * style, lv_coord_t value);


void safe_lv_style_set_shadow_ofs_x(lv_style_t * style, lv_coord_t value);


void safe_lv_style_set_shadow_ofs_y(lv_style_t * style, lv_coord_t value);


void safe_lv_style_set_shadow_spread(lv_style_t * style, lv_coord_t value);


void safe_lv_style_set_shadow_color(lv_style_t * style, lv_color_t value);


void safe_lv_style_set_shadow_opa(lv_style_t * style, lv_opa_t value);


void safe_lv_style_set_img_opa(lv_style_t * style, lv_opa_t value);


void safe_lv_style_set_img_recolor(lv_style_t * style, lv_color_t value);


void safe_lv_style_set_img_recolor_opa(lv_style_t * style, lv_opa_t value);


void safe_lv_style_set_line_width(lv_style_t * style, lv_coord_t value);


void safe_lv_style_set_line_dash_width(lv_style_t * style, lv_coord_t value);


void safe_lv_style_set_line_dash_gap(lv_style_t * style, lv_coord_t value);


void safe_lv_style_set_line_rounded(lv_style_t * style, bool value);


void safe_lv_style_set_line_color(lv_style_t * style, lv_color_t value);


void safe_lv_style_set_line_opa(lv_style_t * style, lv_opa_t value);


void safe_lv_style_set_arc_width(lv_style_t * style, lv_coord_t value);


void safe_lv_style_set_arc_rounded(lv_style_t * style, bool value);


void safe_lv_style_set_arc_color(lv_style_t * style, lv_color_t value);


void safe_lv_style_set_arc_opa(lv_style_t * style, lv_opa_t value);


void safe_lv_style_set_arc_img_src(lv_style_t * style, const void * value);


void safe_lv_style_set_text_color(lv_style_t * style, lv_color_t value);


void safe_lv_style_set_text_opa(lv_style_t * style, lv_opa_t value);


void safe_lv_style_set_text_font(lv_style_t * style, const lv_font_t * value);


void safe_lv_style_set_text_letter_space(lv_style_t * style, lv_coord_t value);


void safe_lv_style_set_text_line_space(lv_style_t * style, lv_coord_t value);


void safe_lv_style_set_text_decor(lv_style_t * style, lv_text_decor_t value);


void safe_lv_style_set_text_align(lv_style_t * style, lv_text_align_t value);


void safe_lv_style_set_radius(lv_style_t * style, lv_coord_t value);


void safe_lv_style_set_clip_corner(lv_style_t * style, bool value);


void safe_lv_style_set_opa(lv_style_t * style, lv_opa_t value);


void safe_lv_style_set_color_filter_dsc(lv_style_t * style, const lv_color_filter_dsc_t * value);


void safe_lv_style_set_color_filter_opa(lv_style_t * style, lv_opa_t value);


void safe_lv_style_set_anim(lv_style_t * style, const lv_anim_t * value);


void safe_lv_style_set_anim_time(lv_style_t * style, uint32_t value);


void safe_lv_style_set_anim_speed(lv_style_t * style, uint32_t value);


void safe_lv_style_set_transition(lv_style_t * style, const lv_style_transition_dsc_t * value);


void safe_lv_style_set_blend_mode(lv_style_t * style, lv_blend_mode_t value);


void safe_lv_style_set_layout(lv_style_t * style, uint16_t value);


void safe_lv_style_set_base_dir(lv_style_t * style, lv_base_dir_t value);


static inline void safe_lv_style_set_size(lv_style_t * style, lv_coord_t value);


static inline void safe_lv_style_set_pad_all(lv_style_t * style, lv_coord_t value);


static inline void safe_lv_style_set_pad_hor(lv_style_t * style, lv_coord_t value);


static inline void safe_lv_style_set_pad_ver(lv_style_t * style, lv_coord_t value);


static inline void safe_lv_style_set_pad_gap(lv_style_t * style, lv_coord_t value);


static inline bool safe_lv_style_prop_has_flag(lv_style_prop_t prop, uint8_t flag);


lv_img_dsc_t * safe_lv_img_buf_alloc(lv_coord_t w, lv_coord_t h, lv_img_cf_t cf);


lv_color_t safe_lv_img_buf_get_px_color(lv_img_dsc_t * dsc, lv_coord_t x, lv_coord_t y, lv_color_t color);


lv_opa_t safe_lv_img_buf_get_px_alpha(lv_img_dsc_t * dsc, lv_coord_t x, lv_coord_t y);


void safe_lv_img_buf_set_px_color(lv_img_dsc_t * dsc, lv_coord_t x, lv_coord_t y, lv_color_t c);


void safe_lv_img_buf_set_px_alpha(lv_img_dsc_t * dsc, lv_coord_t x, lv_coord_t y, lv_opa_t opa);


void safe_lv_img_buf_set_palette(lv_img_dsc_t * dsc, uint8_t id, lv_color_t c);


void safe_lv_img_buf_free(lv_img_dsc_t * dsc);


uint32_t safe_lv_img_buf_get_img_size(lv_coord_t w, lv_coord_t h, lv_img_cf_t cf);


void safe_lv_fs_drv_init(lv_fs_drv_t * drv);


void safe_lv_fs_drv_register(lv_fs_drv_t * drv);


lv_fs_drv_t * safe_lv_fs_get_drv(char letter);


bool safe_lv_fs_is_ready(char letter);


lv_fs_res_t safe_lv_fs_open(lv_fs_file_t * file_p, const char * path, lv_fs_mode_t mode);


lv_fs_res_t safe_lv_fs_close(lv_fs_file_t * file_p);


lv_fs_res_t safe_lv_fs_read(lv_fs_file_t * file_p, void * buf, uint32_t btr, uint32_t * br);


lv_fs_res_t safe_lv_fs_write(lv_fs_file_t * file_p, const void * buf, uint32_t btw, uint32_t * bw);


lv_fs_res_t safe_lv_fs_seek(lv_fs_file_t * file_p, uint32_t pos, lv_fs_whence_t whence);


lv_fs_res_t safe_lv_fs_tell(lv_fs_file_t * file_p, uint32_t * pos);


lv_fs_res_t safe_lv_fs_dir_open(lv_fs_dir_t * rddir_p, const char * path);


lv_fs_res_t safe_lv_fs_dir_read(lv_fs_dir_t * rddir_p, char * fn);


lv_fs_res_t safe_lv_fs_dir_close(lv_fs_dir_t * rddir_p);


char * safe_lv_fs_get_letters(char * buf);


const char * safe_lv_fs_get_ext(const char * fn);


char * safe_lv_fs_up(char * path);


const char * safe_lv_fs_get_last(const char * path);


lv_res_t safe_lv_img_decoder_get_info(const void * src, lv_img_header_t * header);


lv_res_t safe_lv_img_decoder_open(lv_img_decoder_dsc_t * dsc, const void * src, lv_color_t color, int32_t frame_id);


lv_res_t safe_lv_img_decoder_read_line(lv_img_decoder_dsc_t * dsc, lv_coord_t x, lv_coord_t y, lv_coord_t len, uint8_t * buf);


void safe_lv_img_decoder_close(lv_img_decoder_dsc_t * dsc);


lv_img_decoder_t * safe_lv_img_decoder_create(void);


void safe_lv_img_decoder_delete(lv_img_decoder_t * decoder);


void safe_lv_img_decoder_set_info_cb(lv_img_decoder_t * decoder, lv_img_decoder_info_f_t info_cb);


void safe_lv_img_decoder_set_open_cb(lv_img_decoder_t * decoder, lv_img_decoder_open_f_t open_cb);


void safe_lv_img_decoder_set_read_line_cb(lv_img_decoder_t * decoder, lv_img_decoder_read_line_f_t read_line_cb);


void safe_lv_img_decoder_set_close_cb(lv_img_decoder_t * decoder, lv_img_decoder_close_f_t close_cb);


lv_res_t safe_lv_img_decoder_built_in_info(lv_img_decoder_t * decoder, const void * src, lv_img_header_t * header);


lv_res_t safe_lv_img_decoder_built_in_open(lv_img_decoder_t * decoder, lv_img_decoder_dsc_t * dsc);


lv_res_t safe_lv_img_decoder_built_in_read_line(lv_img_decoder_t * decoder, lv_img_decoder_dsc_t * dsc, lv_coord_t x, lv_coord_t y, lv_coord_t len, uint8_t * buf);


void safe_lv_img_decoder_built_in_close(lv_img_decoder_t * decoder, lv_img_decoder_dsc_t * dsc);


void safe_lv_img_cache_set_size(uint16_t new_slot_num);


void safe_lv_img_cache_invalidate_src(const void * src);


void safe_lv_obj_set_pos(struct _lv_obj_t * obj, lv_coord_t x, lv_coord_t y);


void safe_lv_obj_set_x(struct _lv_obj_t * obj, lv_coord_t x);


void safe_lv_obj_set_y(struct _lv_obj_t * obj, lv_coord_t y);


void safe_lv_obj_set_size(struct _lv_obj_t * obj, lv_coord_t w, lv_coord_t h);


bool safe_lv_obj_refr_size(struct _lv_obj_t * obj);


void safe_lv_obj_set_width(struct _lv_obj_t * obj, lv_coord_t w);


void safe_lv_obj_set_height(struct _lv_obj_t * obj, lv_coord_t h);


void safe_lv_obj_set_content_width(struct _lv_obj_t * obj, lv_coord_t w);


void safe_lv_obj_set_content_height(struct _lv_obj_t * obj, lv_coord_t h);


void safe_lv_obj_set_layout(struct _lv_obj_t * obj, uint32_t layout);


bool safe_lv_obj_is_layout_positioned(const struct _lv_obj_t * obj);


void safe_lv_obj_mark_layout_as_dirty(struct _lv_obj_t * obj);


void safe_lv_obj_update_layout(const struct _lv_obj_t * obj);


uint32_t safe_lv_layout_register(lv_layout_update_cb_t cb, void * user_data);


void safe_lv_obj_set_align(struct _lv_obj_t * obj, lv_align_t align);


void safe_lv_obj_align(struct _lv_obj_t * obj, lv_align_t align, lv_coord_t x_ofs, lv_coord_t y_ofs);


void safe_lv_obj_align_to(struct _lv_obj_t * obj, const struct _lv_obj_t * base, lv_align_t align, lv_coord_t x_ofs, lv_coord_t y_ofs);


static inline void safe_lv_obj_center(struct _lv_obj_t * obj);


void safe_lv_obj_get_coords(const struct _lv_obj_t * obj, lv_area_t * coords);


lv_coord_t safe_lv_obj_get_x(const struct _lv_obj_t * obj);


lv_coord_t safe_lv_obj_get_x2(const struct _lv_obj_t * obj);


lv_coord_t safe_lv_obj_get_y(const struct _lv_obj_t * obj);


lv_coord_t safe_lv_obj_get_y2(const struct _lv_obj_t * obj);


lv_coord_t safe_lv_obj_get_x_aligned(const struct _lv_obj_t * obj);


lv_coord_t safe_lv_obj_get_y_aligned(const struct _lv_obj_t * obj);


lv_coord_t safe_lv_obj_get_width(const struct _lv_obj_t * obj);


lv_coord_t safe_lv_obj_get_height(const struct _lv_obj_t * obj);


lv_coord_t safe_lv_obj_get_content_width(const struct _lv_obj_t * obj);


lv_coord_t safe_lv_obj_get_content_height(const struct _lv_obj_t * obj);


void safe_lv_obj_get_content_coords(const struct _lv_obj_t * obj, lv_area_t * area);


lv_coord_t safe_lv_obj_get_self_width(const struct _lv_obj_t * obj);


lv_coord_t safe_lv_obj_get_self_height(const struct _lv_obj_t * obj);


bool safe_lv_obj_refresh_self_size(struct _lv_obj_t * obj);


void safe_lv_obj_refr_pos(struct _lv_obj_t * obj);


void safe_lv_obj_move_to(struct _lv_obj_t * obj, lv_coord_t x, lv_coord_t y);


void safe_lv_obj_move_children_by(struct _lv_obj_t * obj, lv_coord_t x_diff, lv_coord_t y_diff, bool ignore_floating);


void safe_lv_obj_transform_point(const struct _lv_obj_t * obj, lv_point_t * p, bool recursive, bool inv);


void safe_lv_obj_get_transformed_area(const struct _lv_obj_t * obj, lv_area_t * area, bool recursive, bool inv);


void safe_lv_obj_invalidate_area(const struct _lv_obj_t * obj, const lv_area_t * area);


void safe_lv_obj_invalidate(const struct _lv_obj_t * obj);


bool safe_lv_obj_area_is_visible(const struct _lv_obj_t * obj, lv_area_t * area);


bool safe_lv_obj_is_visible(const struct _lv_obj_t * obj);


void safe_lv_obj_set_ext_click_area(struct _lv_obj_t * obj, lv_coord_t size);


void safe_lv_obj_get_click_area(const struct _lv_obj_t * obj, lv_area_t * area);


bool safe_lv_obj_hit_test(struct _lv_obj_t * obj, const lv_point_t * point);


lv_coord_t safe_lv_clamp_width(lv_coord_t width, lv_coord_t min_width, lv_coord_t max_width, lv_coord_t ref_width);


lv_coord_t safe_lv_clamp_height(lv_coord_t height, lv_coord_t min_height, lv_coord_t max_height, lv_coord_t ref_height);


lv_grad_color_t safe_lv_gradient_calculate(const lv_grad_dsc_t * dsc, lv_coord_t range, lv_coord_t frac);


void safe_lv_gradient_set_cache_size(size_t max_bytes);


void safe_lv_gradient_free_cache(void);


lv_grad_t * safe_lv_gradient_get(const lv_grad_dsc_t * gradient, lv_coord_t w, lv_coord_t h);


void safe_lv_gradient_cleanup(lv_grad_t * grad);


void safe_lv_draw_rect_dsc_init(lv_draw_rect_dsc_t * dsc);


void safe_lv_draw_rect(struct _lv_draw_ctx_t * draw_ctx, const lv_draw_rect_dsc_t * dsc, const lv_area_t * coords);


void safe_lv_draw_label_dsc_init(lv_draw_label_dsc_t * dsc);


void safe_lv_draw_label(struct _lv_draw_ctx_t * draw_ctx, const lv_draw_label_dsc_t * dsc, const lv_area_t * coords, const char * txt, lv_draw_label_hint_t * hint);


void safe_lv_draw_letter(struct _lv_draw_ctx_t * draw_ctx, const lv_draw_label_dsc_t * dsc, const lv_point_t * pos_p, uint32_t letter);


void safe_lv_draw_img_dsc_init(lv_draw_img_dsc_t * dsc);


void safe_lv_draw_img(struct _lv_draw_ctx_t * draw_ctx, const lv_draw_img_dsc_t * dsc, const lv_area_t * coords, const void * src);


void safe_lv_draw_img_decoded(struct _lv_draw_ctx_t * draw_ctx, const lv_draw_img_dsc_t * dsc, const lv_area_t * coords, const uint8_t * map_p, lv_img_cf_t color_format);


lv_img_src_t safe_lv_img_src_get_type(const void * src);


uint8_t safe_lv_img_cf_get_px_size(lv_img_cf_t cf);


bool safe_lv_img_cf_is_chroma_keyed(lv_img_cf_t cf);


bool safe_lv_img_cf_has_alpha(lv_img_cf_t cf);


void safe_lv_draw_line_dsc_init(lv_draw_line_dsc_t * dsc);


void safe_lv_draw_line(struct _lv_draw_ctx_t * draw_ctx, const lv_draw_line_dsc_t * dsc, const lv_point_t * point1, const lv_point_t * point2);


void safe_lv_draw_polygon(struct _lv_draw_ctx_t * draw_ctx, const lv_draw_rect_dsc_t * draw_dsc, const lv_point_t points[], uint16_t point_cnt);


void safe_lv_draw_triangle(struct _lv_draw_ctx_t * draw_ctx, const lv_draw_rect_dsc_t * draw_dsc, const lv_point_t points[]);


void safe_lv_draw_arc_dsc_init(lv_draw_arc_dsc_t * dsc);


void safe_lv_draw_arc(struct _lv_draw_ctx_t * draw_ctx, const lv_draw_arc_dsc_t * dsc, const lv_point_t * center, uint16_t radius, uint16_t start_angle, uint16_t end_angle);


void safe_lv_draw_arc_get_area(lv_coord_t x, lv_coord_t y, uint16_t radius, uint16_t start_angle, uint16_t end_angle, lv_coord_t w, bool rounded, lv_area_t * area);


int16_t safe_lv_draw_mask_add(void * param, void * custom_id);


lv_draw_mask_res_t safe_lv_draw_mask_apply(lv_opa_t * mask_buf, lv_coord_t abs_x, lv_coord_t abs_y, lv_coord_t len);


lv_draw_mask_res_t safe_lv_draw_mask_apply_ids(lv_opa_t * mask_buf, lv_coord_t abs_x, lv_coord_t abs_y, lv_coord_t len, const int16_t * ids, int16_t ids_count);


void * safe_lv_draw_mask_remove_id(int16_t id);


void * safe_lv_draw_mask_remove_custom(void * custom_id);


void safe_lv_draw_mask_free_param(void * p);


uint8_t safe_lv_draw_mask_get_cnt(void);


bool safe_lv_draw_mask_is_any(const lv_area_t * a);


void safe_lv_draw_mask_line_points_init(lv_draw_mask_line_param_t * param, lv_coord_t p1x, lv_coord_t p1y, lv_coord_t p2x, lv_coord_t p2y, lv_draw_mask_line_side_t side);


void safe_lv_draw_mask_line_angle_init(lv_draw_mask_line_param_t * param, lv_coord_t p1x, lv_coord_t py, int16_t angle, lv_draw_mask_line_side_t side);


void safe_lv_draw_mask_angle_init(lv_draw_mask_angle_param_t * param, lv_coord_t vertex_x, lv_coord_t vertex_y, lv_coord_t start_angle, lv_coord_t end_angle);


void safe_lv_draw_mask_radius_init(lv_draw_mask_radius_param_t * param, const lv_area_t * rect, lv_coord_t radius, bool inv);


void safe_lv_draw_mask_fade_init(lv_draw_mask_fade_param_t * param, const lv_area_t * coords, lv_opa_t opa_top, lv_coord_t y_top, lv_opa_t opa_bottom, lv_coord_t y_bottom);


void safe_lv_draw_mask_map_init(lv_draw_mask_map_param_t * param, const lv_area_t * coords, const lv_opa_t * map);


void safe_lv_draw_mask_polygon_init(lv_draw_mask_polygon_param_t * param, const lv_point_t * points, uint16_t point_cnt);


void safe_lv_draw_transform(struct _lv_draw_ctx_t * draw_ctx, const lv_area_t * dest_area, const void * src_buf, lv_coord_t src_w, lv_coord_t src_h, lv_coord_t src_stride, const lv_draw_img_dsc_t * draw_dsc, lv_img_cf_t cf, lv_color_t * cbuf, lv_opa_t * abuf);


struct _lv_draw_layer_ctx_t * safe_lv_draw_layer_create(struct _lv_draw_ctx_t * draw_ctx, const lv_area_t * layer_area, lv_draw_layer_flags_t flags);


void safe_lv_draw_layer_adjust(struct _lv_draw_ctx_t * draw_ctx, struct _lv_draw_layer_ctx_t * layer_ctx, lv_draw_layer_flags_t flags);


void safe_lv_draw_layer_blend(struct _lv_draw_ctx_t * draw_ctx, struct _lv_draw_layer_ctx_t * layer_ctx, lv_draw_img_dsc_t * draw_dsc);


void safe_lv_draw_layer_destroy(struct _lv_draw_ctx_t * draw_ctx, struct _lv_draw_layer_ctx_t * layer_ctx);


void safe_lv_draw_init(void);


void safe_lv_draw_wait_for_finish(lv_draw_ctx_t * draw_ctx);


void safe_lv_disp_drv_init(lv_disp_drv_t * driver);


void safe_lv_disp_draw_buf_init(lv_disp_draw_buf_t * draw_buf, void * buf1, void * buf2, uint32_t size_in_px_cnt);


lv_disp_t * safe_lv_disp_drv_register(lv_disp_drv_t * driver);


void safe_lv_disp_drv_update(lv_disp_t * disp, lv_disp_drv_t * new_drv);


void safe_lv_disp_remove(lv_disp_t * disp);


void safe_lv_disp_set_default(lv_disp_t * disp);


lv_disp_t * safe_lv_disp_get_default(void);


lv_coord_t safe_lv_disp_get_hor_res(lv_disp_t * disp);


lv_coord_t safe_lv_disp_get_ver_res(lv_disp_t * disp);


lv_coord_t safe_lv_disp_get_physical_hor_res(lv_disp_t * disp);


lv_coord_t safe_lv_disp_get_physical_ver_res(lv_disp_t * disp);


lv_coord_t safe_lv_disp_get_offset_x(lv_disp_t * disp);


lv_coord_t safe_lv_disp_get_offset_y(lv_disp_t * disp);


bool safe_lv_disp_get_antialiasing(lv_disp_t * disp);


lv_coord_t safe_lv_disp_get_dpi(const lv_disp_t * disp);


void safe_lv_disp_set_rotation(lv_disp_t * disp, lv_disp_rot_t rotation);


lv_disp_rot_t safe_lv_disp_get_rotation(lv_disp_t * disp);


void safe_lv_disp_flush_ready(lv_disp_drv_t * disp_drv);


bool safe_lv_disp_flush_is_last(lv_disp_drv_t * disp_drv);


lv_disp_t * safe_lv_disp_get_next(lv_disp_t * disp);


lv_disp_draw_buf_t * safe_lv_disp_get_draw_buf(lv_disp_t * disp);


void safe_lv_disp_drv_use_generic_set_px_cb(lv_disp_drv_t * disp_drv, lv_img_cf_t cf);


void safe_lv_indev_drv_init(struct _lv_indev_drv_t * driver);


lv_indev_t * safe_lv_indev_drv_register(struct _lv_indev_drv_t * driver);


void safe_lv_indev_drv_update(lv_indev_t * indev, struct _lv_indev_drv_t * new_drv);


void safe_lv_indev_delete(lv_indev_t * indev);


lv_indev_t * safe_lv_indev_get_next(lv_indev_t * indev);


void safe_lv_obj_del(struct _lv_obj_t * obj);


void safe_lv_obj_clean(struct _lv_obj_t * obj);


void safe_lv_obj_del_delayed(struct _lv_obj_t * obj, uint32_t delay_ms);


void safe_lv_obj_del_anim_ready_cb(lv_anim_t * a);


void safe_lv_obj_del_async(struct _lv_obj_t * obj);


void safe_lv_obj_set_parent(struct _lv_obj_t * obj, struct _lv_obj_t * parent);


void safe_lv_obj_swap(struct _lv_obj_t * obj1, struct _lv_obj_t * obj2);


void safe_lv_obj_move_to_index(struct _lv_obj_t * obj, int32_t index);


struct _lv_obj_t * safe_lv_obj_get_screen(const struct _lv_obj_t * obj);


lv_disp_t * safe_lv_obj_get_disp(const struct _lv_obj_t * obj);


struct _lv_obj_t * safe_lv_obj_get_parent(const struct _lv_obj_t * obj);


struct _lv_obj_t * safe_lv_obj_get_child(const struct _lv_obj_t * obj, int32_t id);


uint32_t safe_lv_obj_get_child_cnt(const struct _lv_obj_t * obj);


uint32_t safe_lv_obj_get_index(const struct _lv_obj_t * obj);


void safe_lv_obj_tree_walk(struct _lv_obj_t * start_obj, lv_obj_tree_walk_cb_t cb, void * user_data);


void safe_lv_obj_set_scrollbar_mode(struct _lv_obj_t * obj, lv_scrollbar_mode_t mode);


void safe_lv_obj_set_scroll_dir(struct _lv_obj_t * obj, lv_dir_t dir);


void safe_lv_obj_set_scroll_snap_x(struct _lv_obj_t * obj, lv_scroll_snap_t align);


void safe_lv_obj_set_scroll_snap_y(struct _lv_obj_t * obj, lv_scroll_snap_t align);


lv_scrollbar_mode_t safe_lv_obj_get_scrollbar_mode(const struct _lv_obj_t * obj);


lv_dir_t safe_lv_obj_get_scroll_dir(const struct _lv_obj_t * obj);


lv_scroll_snap_t safe_lv_obj_get_scroll_snap_x(const struct _lv_obj_t * obj);


lv_scroll_snap_t safe_lv_obj_get_scroll_snap_y(const struct _lv_obj_t * obj);


lv_coord_t safe_lv_obj_get_scroll_x(const struct _lv_obj_t * obj);


lv_coord_t safe_lv_obj_get_scroll_y(const struct _lv_obj_t * obj);


lv_coord_t safe_lv_obj_get_scroll_top(struct _lv_obj_t * obj);


lv_coord_t safe_lv_obj_get_scroll_bottom(struct _lv_obj_t * obj);


lv_coord_t safe_lv_obj_get_scroll_left(struct _lv_obj_t * obj);


lv_coord_t safe_lv_obj_get_scroll_right(struct _lv_obj_t * obj);


void safe_lv_obj_get_scroll_end(struct _lv_obj_t * obj, lv_point_t * end);


void safe_lv_obj_scroll_by(struct _lv_obj_t * obj, lv_coord_t x, lv_coord_t y, lv_anim_enable_t anim_en);


void safe_lv_obj_scroll_by_bounded(struct _lv_obj_t * obj, lv_coord_t dx, lv_coord_t dy, lv_anim_enable_t anim_en);


void safe_lv_obj_scroll_to(struct _lv_obj_t * obj, lv_coord_t x, lv_coord_t y, lv_anim_enable_t anim_en);


void safe_lv_obj_scroll_to_x(struct _lv_obj_t * obj, lv_coord_t x, lv_anim_enable_t anim_en);


void safe_lv_obj_scroll_to_y(struct _lv_obj_t * obj, lv_coord_t y, lv_anim_enable_t anim_en);


void safe_lv_obj_scroll_to_view(struct _lv_obj_t * obj, lv_anim_enable_t anim_en);


void safe_lv_obj_scroll_to_view_recursive(struct _lv_obj_t * obj, lv_anim_enable_t anim_en);


bool safe_lv_obj_is_scrolling(const struct _lv_obj_t * obj);


void safe_lv_obj_update_snap(struct _lv_obj_t * obj, lv_anim_enable_t anim_en);


void safe_lv_obj_get_scrollbar_area(struct _lv_obj_t * obj, lv_area_t * hor, lv_area_t * ver);


void safe_lv_obj_scrollbar_invalidate(struct _lv_obj_t * obj);


void safe_lv_obj_readjust_scroll(struct _lv_obj_t * obj, lv_anim_enable_t anim_en);


void safe_lv_obj_add_style(struct _lv_obj_t * obj, lv_style_t * style, lv_style_selector_t selector);


void safe_lv_obj_remove_style(struct _lv_obj_t * obj, lv_style_t * style, lv_style_selector_t selector);


static inline void safe_lv_obj_remove_style_all(struct _lv_obj_t * obj);


void safe_lv_obj_report_style_change(lv_style_t * style);


void safe_lv_obj_refresh_style(struct _lv_obj_t * obj, lv_part_t part, lv_style_prop_t prop);


void safe_lv_obj_enable_style_refresh(bool en);


lv_style_value_t safe_lv_obj_get_style_prop(const struct _lv_obj_t * obj, lv_part_t part, lv_style_prop_t prop);


void safe_lv_obj_set_local_style_prop(struct _lv_obj_t * obj, lv_style_prop_t prop, lv_style_value_t value, lv_style_selector_t selector);


void safe_lv_obj_set_local_style_prop_meta(struct _lv_obj_t * obj, lv_style_prop_t prop, uint16_t meta, lv_style_selector_t selector);


lv_style_res_t safe_lv_obj_get_local_style_prop(struct _lv_obj_t * obj, lv_style_prop_t prop, lv_style_value_t * value, lv_style_selector_t selector);


bool safe_lv_obj_remove_local_style_prop(struct _lv_obj_t * obj, lv_style_prop_t prop, lv_style_selector_t selector);


void safe_lv_obj_fade_in(struct _lv_obj_t * obj, uint32_t time, uint32_t delay);


void safe_lv_obj_fade_out(struct _lv_obj_t * obj, uint32_t time, uint32_t delay);


lv_state_t safe_lv_obj_style_get_selector_state(lv_style_selector_t selector);


lv_part_t safe_lv_obj_style_get_selector_part(lv_style_selector_t selector);


static inline lv_coord_t safe_lv_obj_get_style_width(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_coord_t safe_lv_obj_get_style_min_width(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_coord_t safe_lv_obj_get_style_max_width(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_coord_t safe_lv_obj_get_style_height(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_coord_t safe_lv_obj_get_style_min_height(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_coord_t safe_lv_obj_get_style_max_height(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_coord_t safe_lv_obj_get_style_x(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_coord_t safe_lv_obj_get_style_y(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_align_t safe_lv_obj_get_style_align(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_coord_t safe_lv_obj_get_style_transform_width(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_coord_t safe_lv_obj_get_style_transform_height(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_coord_t safe_lv_obj_get_style_translate_x(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_coord_t safe_lv_obj_get_style_translate_y(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_coord_t safe_lv_obj_get_style_transform_zoom(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_coord_t safe_lv_obj_get_style_transform_angle(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_coord_t safe_lv_obj_get_style_transform_pivot_x(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_coord_t safe_lv_obj_get_style_transform_pivot_y(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_coord_t safe_lv_obj_get_style_pad_top(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_coord_t safe_lv_obj_get_style_pad_bottom(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_coord_t safe_lv_obj_get_style_pad_left(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_coord_t safe_lv_obj_get_style_pad_right(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_coord_t safe_lv_obj_get_style_pad_row(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_coord_t safe_lv_obj_get_style_pad_column(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_color_t safe_lv_obj_get_style_bg_color(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_color_t safe_lv_obj_get_style_bg_color_filtered(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_opa_t safe_lv_obj_get_style_bg_opa(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_color_t safe_lv_obj_get_style_bg_grad_color(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_color_t safe_lv_obj_get_style_bg_grad_color_filtered(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_grad_dir_t safe_lv_obj_get_style_bg_grad_dir(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_coord_t safe_lv_obj_get_style_bg_main_stop(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_coord_t safe_lv_obj_get_style_bg_grad_stop(const struct _lv_obj_t * obj, uint32_t part);


const static inline lv_grad_dsc_t * safe_lv_obj_get_style_bg_grad(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_dither_mode_t safe_lv_obj_get_style_bg_dither_mode(const struct _lv_obj_t * obj, uint32_t part);


const static inline void * safe_lv_obj_get_style_bg_img_src(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_opa_t safe_lv_obj_get_style_bg_img_opa(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_color_t safe_lv_obj_get_style_bg_img_recolor(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_color_t safe_lv_obj_get_style_bg_img_recolor_filtered(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_opa_t safe_lv_obj_get_style_bg_img_recolor_opa(const struct _lv_obj_t * obj, uint32_t part);


static inline bool safe_lv_obj_get_style_bg_img_tiled(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_color_t safe_lv_obj_get_style_border_color(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_color_t safe_lv_obj_get_style_border_color_filtered(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_opa_t safe_lv_obj_get_style_border_opa(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_coord_t safe_lv_obj_get_style_border_width(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_border_side_t safe_lv_obj_get_style_border_side(const struct _lv_obj_t * obj, uint32_t part);


static inline bool safe_lv_obj_get_style_border_post(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_coord_t safe_lv_obj_get_style_outline_width(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_color_t safe_lv_obj_get_style_outline_color(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_color_t safe_lv_obj_get_style_outline_color_filtered(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_opa_t safe_lv_obj_get_style_outline_opa(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_coord_t safe_lv_obj_get_style_outline_pad(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_coord_t safe_lv_obj_get_style_shadow_width(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_coord_t safe_lv_obj_get_style_shadow_ofs_x(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_coord_t safe_lv_obj_get_style_shadow_ofs_y(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_coord_t safe_lv_obj_get_style_shadow_spread(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_color_t safe_lv_obj_get_style_shadow_color(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_color_t safe_lv_obj_get_style_shadow_color_filtered(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_opa_t safe_lv_obj_get_style_shadow_opa(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_opa_t safe_lv_obj_get_style_img_opa(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_color_t safe_lv_obj_get_style_img_recolor(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_color_t safe_lv_obj_get_style_img_recolor_filtered(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_opa_t safe_lv_obj_get_style_img_recolor_opa(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_coord_t safe_lv_obj_get_style_line_width(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_coord_t safe_lv_obj_get_style_line_dash_width(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_coord_t safe_lv_obj_get_style_line_dash_gap(const struct _lv_obj_t * obj, uint32_t part);


static inline bool safe_lv_obj_get_style_line_rounded(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_color_t safe_lv_obj_get_style_line_color(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_color_t safe_lv_obj_get_style_line_color_filtered(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_opa_t safe_lv_obj_get_style_line_opa(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_coord_t safe_lv_obj_get_style_arc_width(const struct _lv_obj_t * obj, uint32_t part);


static inline bool safe_lv_obj_get_style_arc_rounded(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_color_t safe_lv_obj_get_style_arc_color(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_color_t safe_lv_obj_get_style_arc_color_filtered(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_opa_t safe_lv_obj_get_style_arc_opa(const struct _lv_obj_t * obj, uint32_t part);


const static inline void * safe_lv_obj_get_style_arc_img_src(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_color_t safe_lv_obj_get_style_text_color(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_color_t safe_lv_obj_get_style_text_color_filtered(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_opa_t safe_lv_obj_get_style_text_opa(const struct _lv_obj_t * obj, uint32_t part);


const static inline lv_font_t * safe_lv_obj_get_style_text_font(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_coord_t safe_lv_obj_get_style_text_letter_space(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_coord_t safe_lv_obj_get_style_text_line_space(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_text_decor_t safe_lv_obj_get_style_text_decor(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_text_align_t safe_lv_obj_get_style_text_align(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_coord_t safe_lv_obj_get_style_radius(const struct _lv_obj_t * obj, uint32_t part);


static inline bool safe_lv_obj_get_style_clip_corner(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_opa_t safe_lv_obj_get_style_opa(const struct _lv_obj_t * obj, uint32_t part);


const static inline lv_color_filter_dsc_t * safe_lv_obj_get_style_color_filter_dsc(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_opa_t safe_lv_obj_get_style_color_filter_opa(const struct _lv_obj_t * obj, uint32_t part);


const static inline lv_anim_t * safe_lv_obj_get_style_anim(const struct _lv_obj_t * obj, uint32_t part);


static inline uint32_t safe_lv_obj_get_style_anim_time(const struct _lv_obj_t * obj, uint32_t part);


static inline uint32_t safe_lv_obj_get_style_anim_speed(const struct _lv_obj_t * obj, uint32_t part);


const static inline lv_style_transition_dsc_t * safe_lv_obj_get_style_transition(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_blend_mode_t safe_lv_obj_get_style_blend_mode(const struct _lv_obj_t * obj, uint32_t part);


static inline uint16_t safe_lv_obj_get_style_layout(const struct _lv_obj_t * obj, uint32_t part);


static inline lv_base_dir_t safe_lv_obj_get_style_base_dir(const struct _lv_obj_t * obj, uint32_t part);


void safe_lv_obj_set_style_width(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_min_width(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_max_width(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_height(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_min_height(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_max_height(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_x(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_y(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_align(struct _lv_obj_t * obj, lv_align_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_transform_width(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_transform_height(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_translate_x(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_translate_y(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_transform_zoom(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_transform_angle(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_transform_pivot_x(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_transform_pivot_y(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_pad_top(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_pad_bottom(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_pad_left(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_pad_right(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_pad_row(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_pad_column(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_bg_color(struct _lv_obj_t * obj, lv_color_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_bg_opa(struct _lv_obj_t * obj, lv_opa_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_bg_grad_color(struct _lv_obj_t * obj, lv_color_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_bg_grad_dir(struct _lv_obj_t * obj, lv_grad_dir_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_bg_main_stop(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_bg_grad_stop(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_bg_grad(struct _lv_obj_t * obj, const lv_grad_dsc_t * value, lv_style_selector_t selector);


void safe_lv_obj_set_style_bg_dither_mode(struct _lv_obj_t * obj, lv_dither_mode_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_bg_img_src(struct _lv_obj_t * obj, const void * value, lv_style_selector_t selector);


void safe_lv_obj_set_style_bg_img_opa(struct _lv_obj_t * obj, lv_opa_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_bg_img_recolor(struct _lv_obj_t * obj, lv_color_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_bg_img_recolor_opa(struct _lv_obj_t * obj, lv_opa_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_bg_img_tiled(struct _lv_obj_t * obj, bool value, lv_style_selector_t selector);


void safe_lv_obj_set_style_border_color(struct _lv_obj_t * obj, lv_color_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_border_opa(struct _lv_obj_t * obj, lv_opa_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_border_width(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_border_side(struct _lv_obj_t * obj, lv_border_side_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_border_post(struct _lv_obj_t * obj, bool value, lv_style_selector_t selector);


void safe_lv_obj_set_style_outline_width(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_outline_color(struct _lv_obj_t * obj, lv_color_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_outline_opa(struct _lv_obj_t * obj, lv_opa_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_outline_pad(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_shadow_width(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_shadow_ofs_x(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_shadow_ofs_y(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_shadow_spread(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_shadow_color(struct _lv_obj_t * obj, lv_color_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_shadow_opa(struct _lv_obj_t * obj, lv_opa_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_img_opa(struct _lv_obj_t * obj, lv_opa_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_img_recolor(struct _lv_obj_t * obj, lv_color_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_img_recolor_opa(struct _lv_obj_t * obj, lv_opa_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_line_width(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_line_dash_width(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_line_dash_gap(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_line_rounded(struct _lv_obj_t * obj, bool value, lv_style_selector_t selector);


void safe_lv_obj_set_style_line_color(struct _lv_obj_t * obj, lv_color_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_line_opa(struct _lv_obj_t * obj, lv_opa_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_arc_width(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_arc_rounded(struct _lv_obj_t * obj, bool value, lv_style_selector_t selector);


void safe_lv_obj_set_style_arc_color(struct _lv_obj_t * obj, lv_color_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_arc_opa(struct _lv_obj_t * obj, lv_opa_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_arc_img_src(struct _lv_obj_t * obj, const void * value, lv_style_selector_t selector);


void safe_lv_obj_set_style_text_color(struct _lv_obj_t * obj, lv_color_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_text_opa(struct _lv_obj_t * obj, lv_opa_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_text_font(struct _lv_obj_t * obj, const lv_font_t * value, lv_style_selector_t selector);


void safe_lv_obj_set_style_text_letter_space(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_text_line_space(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_text_decor(struct _lv_obj_t * obj, lv_text_decor_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_text_align(struct _lv_obj_t * obj, lv_text_align_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_radius(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_clip_corner(struct _lv_obj_t * obj, bool value, lv_style_selector_t selector);


void safe_lv_obj_set_style_opa(struct _lv_obj_t * obj, lv_opa_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_color_filter_dsc(struct _lv_obj_t * obj, const lv_color_filter_dsc_t * value, lv_style_selector_t selector);


void safe_lv_obj_set_style_color_filter_opa(struct _lv_obj_t * obj, lv_opa_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_anim(struct _lv_obj_t * obj, const lv_anim_t * value, lv_style_selector_t selector);


void safe_lv_obj_set_style_anim_time(struct _lv_obj_t * obj, uint32_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_anim_speed(struct _lv_obj_t * obj, uint32_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_transition(struct _lv_obj_t * obj, const lv_style_transition_dsc_t * value, lv_style_selector_t selector);


void safe_lv_obj_set_style_blend_mode(struct _lv_obj_t * obj, lv_blend_mode_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_layout(struct _lv_obj_t * obj, uint16_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_base_dir(struct _lv_obj_t * obj, lv_base_dir_t value, lv_style_selector_t selector);


static inline void safe_lv_obj_set_style_pad_all(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector);


static inline void safe_lv_obj_set_style_pad_hor(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector);


static inline void safe_lv_obj_set_style_pad_ver(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector);


static inline void safe_lv_obj_set_style_pad_gap(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector);


static inline void safe_lv_obj_set_style_size(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector);


lv_text_align_t safe_lv_obj_calculate_style_text_align(const struct _lv_obj_t * obj, lv_part_t part, const char * txt);


void safe_lv_obj_init_draw_rect_dsc(struct _lv_obj_t * obj, uint32_t part, lv_draw_rect_dsc_t * draw_dsc);


void safe_lv_obj_init_draw_label_dsc(struct _lv_obj_t * obj, uint32_t part, lv_draw_label_dsc_t * draw_dsc);


void safe_lv_obj_init_draw_img_dsc(struct _lv_obj_t * obj, uint32_t part, lv_draw_img_dsc_t * draw_dsc);


void safe_lv_obj_init_draw_line_dsc(struct _lv_obj_t * obj, uint32_t part, lv_draw_line_dsc_t * draw_dsc);


void safe_lv_obj_init_draw_arc_dsc(struct _lv_obj_t * obj, uint32_t part, lv_draw_arc_dsc_t * draw_dsc);


lv_coord_t safe_lv_obj_calculate_ext_draw_size(struct _lv_obj_t * obj, uint32_t part);


void safe_lv_obj_draw_dsc_init(lv_obj_draw_part_dsc_t * dsc, lv_draw_ctx_t * draw_ctx);


bool safe_lv_obj_draw_part_check_type(lv_obj_draw_part_dsc_t * dsc, const struct _lv_obj_class_t * class_p, uint32_t type);


void safe_lv_obj_refresh_ext_draw_size(struct _lv_obj_t * obj);


struct _lv_obj_t * safe_lv_obj_class_create_obj(const struct _lv_obj_class_t * class_p, struct _lv_obj_t * parent);


void safe_lv_obj_class_init_obj(struct _lv_obj_t * obj);


bool safe_lv_obj_is_editable(struct _lv_obj_t * obj);


bool safe_lv_obj_is_group_def(struct _lv_obj_t * obj);


lv_res_t safe_lv_event_send(struct _lv_obj_t * obj, lv_event_code_t event_code, void * param);


lv_res_t safe_lv_obj_event_base(const lv_obj_class_t * class_p, lv_event_t * e);


struct _lv_obj_t * safe_lv_event_get_target(lv_event_t * e);


struct _lv_obj_t * safe_lv_event_get_current_target(lv_event_t * e);


lv_event_code_t safe_lv_event_get_code(lv_event_t * e);


void * safe_lv_event_get_param(lv_event_t * e);


void * safe_lv_event_get_user_data(lv_event_t * e);


void safe_lv_event_stop_bubbling(lv_event_t * e);


void safe_lv_event_stop_processing(lv_event_t * e);


uint32_t safe_lv_event_register_id(void);


struct _lv_event_dsc_t * safe_lv_obj_add_event_cb(struct _lv_obj_t * obj, lv_event_cb_t event_cb, lv_event_code_t filter, void * user_data);


bool safe_lv_obj_remove_event_cb(struct _lv_obj_t * obj, lv_event_cb_t event_cb);


bool safe_lv_obj_remove_event_cb_with_user_data(struct _lv_obj_t * obj, lv_event_cb_t event_cb, const void * event_user_data);


bool safe_lv_obj_remove_event_dsc(struct _lv_obj_t * obj, struct _lv_event_dsc_t * event_dsc);


void * safe_lv_obj_get_event_user_data(struct _lv_obj_t * obj, lv_event_cb_t event_cb);


lv_indev_t * safe_lv_event_get_indev(lv_event_t * e);


lv_obj_draw_part_dsc_t * safe_lv_event_get_draw_part_dsc(lv_event_t * e);


lv_draw_ctx_t * safe_lv_event_get_draw_ctx(lv_event_t * e);


const lv_area_t * safe_lv_event_get_old_size(lv_event_t * e);


uint32_t safe_lv_event_get_key(lv_event_t * e);


lv_anim_t * safe_lv_event_get_scroll_anim(lv_event_t * e);


void safe_lv_event_set_ext_draw_size(lv_event_t * e, lv_coord_t size);


lv_point_t * safe_lv_event_get_self_size_info(lv_event_t * e);


lv_hit_test_info_t * safe_lv_event_get_hit_test_info(lv_event_t * e);


const lv_area_t * safe_lv_event_get_cover_area(lv_event_t * e);


void safe_lv_event_set_cover_res(lv_event_t * e, lv_cover_res_t res);


lv_group_t * safe_lv_group_create(void);


void safe_lv_group_del(lv_group_t * group);


void safe_lv_group_set_default(lv_group_t * group);


lv_group_t * safe_lv_group_get_default(void);


void safe_lv_group_add_obj(lv_group_t * group, struct _lv_obj_t * obj);


void safe_lv_group_swap_obj(struct _lv_obj_t * obj1, struct _lv_obj_t * obj2);


void safe_lv_group_remove_obj(struct _lv_obj_t * obj);


void safe_lv_group_remove_all_objs(lv_group_t * group);


void safe_lv_group_focus_obj(struct _lv_obj_t * obj);


void safe_lv_group_focus_next(lv_group_t * group);


void safe_lv_group_focus_prev(lv_group_t * group);


void safe_lv_group_focus_freeze(lv_group_t * group, bool en);


lv_res_t safe_lv_group_send_data(lv_group_t * group, uint32_t c);


void safe_lv_group_set_focus_cb(lv_group_t * group, lv_group_focus_cb_t focus_cb);


void safe_lv_group_set_edge_cb(lv_group_t * group, lv_group_edge_cb_t edge_cb);


void safe_lv_group_set_refocus_policy(lv_group_t * group, lv_group_refocus_policy_t policy);


void safe_lv_group_set_editing(lv_group_t * group, bool edit);


void safe_lv_group_set_wrap(lv_group_t * group, bool en);


struct _lv_obj_t * safe_lv_group_get_focused(const lv_group_t * group);


lv_group_focus_cb_t safe_lv_group_get_focus_cb(const lv_group_t * group);


lv_group_edge_cb_t safe_lv_group_get_edge_cb(const lv_group_t * group);


bool safe_lv_group_get_editing(const lv_group_t * group);


bool safe_lv_group_get_wrap(lv_group_t * group);


uint32_t safe_lv_group_get_obj_count(lv_group_t * group);


void safe_lv_init(void);


bool safe_lv_is_initialized(void);


lv_obj_t * safe_lv_obj_create(lv_obj_t * parent);


void safe_lv_obj_add_flag(lv_obj_t * obj, lv_obj_flag_t f);


void safe_lv_obj_clear_flag(lv_obj_t * obj, lv_obj_flag_t f);


void safe_lv_obj_add_state(lv_obj_t * obj, lv_state_t state);


void safe_lv_obj_clear_state(lv_obj_t * obj, lv_state_t state);


static inline void safe_lv_obj_set_user_data(lv_obj_t * obj, void * user_data);


bool safe_lv_obj_has_flag(const lv_obj_t * obj, lv_obj_flag_t f);


bool safe_lv_obj_has_flag_any(const lv_obj_t * obj, lv_obj_flag_t f);


lv_state_t safe_lv_obj_get_state(const lv_obj_t * obj);


bool safe_lv_obj_has_state(const lv_obj_t * obj, lv_state_t state);


void * safe_lv_obj_get_group(const lv_obj_t * obj);


static inline void * safe_lv_obj_get_user_data(lv_obj_t * obj);


void safe_lv_obj_allocate_spec_attr(lv_obj_t * obj);


bool safe_lv_obj_check_type(const lv_obj_t * obj, const lv_obj_class_t * class_p);


bool safe_lv_obj_has_class(const lv_obj_t * obj, const lv_obj_class_t * class_p);


const lv_obj_class_t * safe_lv_obj_get_class(const lv_obj_t * obj);


bool safe_lv_obj_is_valid(const lv_obj_t * obj);


static inline lv_coord_t safe_lv_obj_dpx(const lv_obj_t * obj, lv_coord_t n);


void safe_lv_indev_read_timer_cb(lv_timer_t * timer);


void safe_lv_indev_enable(lv_indev_t * indev, bool en);


lv_indev_t * safe_lv_indev_get_act(void);


lv_indev_type_t safe_lv_indev_get_type(const lv_indev_t * indev);


void safe_lv_indev_reset(lv_indev_t * indev, lv_obj_t * obj);


void safe_lv_indev_reset_long_press(lv_indev_t * indev);


void safe_lv_indev_set_cursor(lv_indev_t * indev, lv_obj_t * cur_obj);


void safe_lv_indev_set_group(lv_indev_t * indev, lv_group_t * group);


void safe_lv_indev_set_button_points(lv_indev_t * indev, const lv_point_t points[]);


void safe_lv_indev_get_point(const lv_indev_t * indev, lv_point_t * point);


lv_dir_t safe_lv_indev_get_gesture_dir(const lv_indev_t * indev);


uint32_t safe_lv_indev_get_key(const lv_indev_t * indev);


lv_dir_t safe_lv_indev_get_scroll_dir(const lv_indev_t * indev);


lv_obj_t * safe_lv_indev_get_scroll_obj(const lv_indev_t * indev);


void safe_lv_indev_get_vect(const lv_indev_t * indev, lv_point_t * point);


void safe_lv_indev_wait_release(lv_indev_t * indev);


lv_obj_t * safe_lv_indev_get_obj_act(void);


lv_timer_t * safe_lv_indev_get_read_timer(lv_disp_t * indev);


lv_obj_t * safe_lv_indev_search_obj(lv_obj_t * obj, lv_point_t * point);


void safe_lv_refr_now(lv_disp_t * disp);


void safe_lv_obj_redraw(lv_draw_ctx_t * draw_ctx, lv_obj_t * obj);


lv_theme_t * safe_lv_theme_get_from_obj(lv_obj_t * obj);


void safe_lv_theme_apply(lv_obj_t * obj);


void safe_lv_theme_set_parent(lv_theme_t * new_theme, lv_theme_t * parent);


void safe_lv_theme_set_apply_cb(lv_theme_t * theme, lv_theme_apply_cb_t apply_cb);


const lv_font_t * safe_lv_theme_get_font_small(lv_obj_t * obj);


const lv_font_t * safe_lv_theme_get_font_normal(lv_obj_t * obj);


const lv_font_t * safe_lv_theme_get_font_large(lv_obj_t * obj);


lv_color_t safe_lv_theme_get_color_primary(lv_obj_t * obj);


lv_color_t safe_lv_theme_get_color_secondary(lv_obj_t * obj);


lv_obj_t * safe_lv_disp_get_scr_act(lv_disp_t * disp);


lv_obj_t * safe_lv_disp_get_scr_prev(lv_disp_t * disp);


void safe_lv_disp_load_scr(lv_obj_t * scr);


lv_obj_t * safe_lv_disp_get_layer_top(lv_disp_t * disp);


lv_obj_t * safe_lv_disp_get_layer_sys(lv_disp_t * disp);


void safe_lv_disp_set_theme(lv_disp_t * disp, lv_theme_t * th);


lv_theme_t * safe_lv_disp_get_theme(lv_disp_t * disp);


void safe_lv_disp_set_bg_color(lv_disp_t * disp, lv_color_t color);


void safe_lv_disp_set_bg_image(lv_disp_t * disp, const void * img_src);


void safe_lv_disp_set_bg_opa(lv_disp_t * disp, lv_opa_t opa);


void safe_lv_scr_load_anim(lv_obj_t * scr, lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool auto_del);


uint32_t safe_lv_disp_get_inactive_time(const lv_disp_t * disp);


void safe_lv_disp_trig_activity(lv_disp_t * disp);


void safe_lv_disp_clean_dcache(lv_disp_t * disp);


void safe_lv_disp_enable_invalidation(lv_disp_t * disp, bool en);


bool safe_lv_disp_is_invalidation_enabled(lv_disp_t * disp);


static inline lv_obj_t * safe_lv_scr_act(void);


static inline lv_obj_t * safe_lv_layer_top(void);


static inline lv_obj_t * safe_lv_layer_sys(void);


static inline void safe_lv_scr_load(lv_obj_t * scr);


static inline lv_coord_t safe_lv_dpx(lv_coord_t n);


static inline lv_coord_t safe_lv_disp_dpx(const lv_disp_t * disp, lv_coord_t n);


lv_font_t * safe_lv_font_load(const char * fontName);


void safe_lv_font_free(lv_font_t * font);


const uint8_t * safe_lv_font_get_bitmap_fmt_txt(const lv_font_t * font, uint32_t letter);


bool safe_lv_font_get_glyph_dsc_fmt_txt(const lv_font_t * font, lv_font_glyph_dsc_t * dsc_out, uint32_t unicode_letter, uint32_t unicode_letter_next);


lv_obj_t * safe_lv_arc_create(lv_obj_t * parent);


void safe_lv_arc_set_start_angle(lv_obj_t * obj, uint16_t start);


void safe_lv_arc_set_end_angle(lv_obj_t * obj, uint16_t end);


void safe_lv_arc_set_angles(lv_obj_t * obj, uint16_t start, uint16_t end);


void safe_lv_arc_set_bg_start_angle(lv_obj_t * obj, uint16_t start);


void safe_lv_arc_set_bg_end_angle(lv_obj_t * obj, uint16_t end);


void safe_lv_arc_set_bg_angles(lv_obj_t * obj, uint16_t start, uint16_t end);


void safe_lv_arc_set_rotation(lv_obj_t * obj, uint16_t rotation);


void safe_lv_arc_set_mode(lv_obj_t * obj, lv_arc_mode_t type);


void safe_lv_arc_set_value(lv_obj_t * obj, int16_t value);


void safe_lv_arc_set_range(lv_obj_t * obj, int16_t min, int16_t max);


void safe_lv_arc_set_change_rate(lv_obj_t * obj, uint16_t rate);


uint16_t safe_lv_arc_get_angle_start(lv_obj_t * obj);


uint16_t safe_lv_arc_get_angle_end(lv_obj_t * obj);


uint16_t safe_lv_arc_get_bg_angle_start(lv_obj_t * obj);


uint16_t safe_lv_arc_get_bg_angle_end(lv_obj_t * obj);


int16_t safe_lv_arc_get_value(const lv_obj_t * obj);


int16_t safe_lv_arc_get_min_value(const lv_obj_t * obj);


int16_t safe_lv_arc_get_max_value(const lv_obj_t * obj);


lv_arc_mode_t safe_lv_arc_get_mode(const lv_obj_t * obj);


void safe_lv_arc_align_obj_to_angle(const lv_obj_t * obj, lv_obj_t * obj_to_align, lv_coord_t r_offset);


void safe_lv_arc_rotate_obj_to_angle(const lv_obj_t * obj, lv_obj_t * obj_to_rotate, lv_coord_t r_offset);


lv_obj_t * safe_lv_btn_create(lv_obj_t * parent);


lv_obj_t * safe_lv_img_create(lv_obj_t * parent);


void safe_lv_img_set_src(lv_obj_t * obj, const void * src);


void safe_lv_img_set_offset_x(lv_obj_t * obj, lv_coord_t x);


void safe_lv_img_set_offset_y(lv_obj_t * obj, lv_coord_t y);


void safe_lv_img_set_angle(lv_obj_t * obj, int16_t angle);


void safe_lv_img_set_pivot(lv_obj_t * obj, lv_coord_t x, lv_coord_t y);


void safe_lv_img_set_zoom(lv_obj_t * obj, uint16_t zoom);


void safe_lv_img_set_antialias(lv_obj_t * obj, bool antialias);


void safe_lv_img_set_size_mode(lv_obj_t * obj, lv_img_size_mode_t mode);


const void * safe_lv_img_get_src(lv_obj_t * obj);


lv_coord_t safe_lv_img_get_offset_x(lv_obj_t * obj);


lv_coord_t safe_lv_img_get_offset_y(lv_obj_t * obj);


uint16_t safe_lv_img_get_angle(lv_obj_t * obj);


void safe_lv_img_get_pivot(lv_obj_t * obj, lv_point_t * pivot);


uint16_t safe_lv_img_get_zoom(lv_obj_t * obj);


bool safe_lv_img_get_antialias(lv_obj_t * obj);


lv_img_size_mode_t safe_lv_img_get_size_mode(lv_obj_t * obj);


lv_obj_t * safe_lv_label_create(lv_obj_t * parent);


void safe_lv_label_set_text(lv_obj_t * obj, const char * text);


void safe_lv_label_set_text_static(lv_obj_t * obj, const char * text);


void safe_lv_label_set_long_mode(lv_obj_t * obj, lv_label_long_mode_t long_mode);


void safe_lv_label_set_recolor(lv_obj_t * obj, bool en);


void safe_lv_label_set_text_sel_start(lv_obj_t * obj, uint32_t index);


void safe_lv_label_set_text_sel_end(lv_obj_t * obj, uint32_t index);


char * safe_lv_label_get_text(const lv_obj_t * obj);


lv_label_long_mode_t safe_lv_label_get_long_mode(const lv_obj_t * obj);


bool safe_lv_label_get_recolor(const lv_obj_t * obj);


void safe_lv_label_get_letter_pos(const lv_obj_t * obj, uint32_t char_id, lv_point_t * pos);


uint32_t safe_lv_label_get_letter_on(const lv_obj_t * obj, lv_point_t * pos_in);


bool safe_lv_label_is_char_under_pos(const lv_obj_t * obj, lv_point_t * pos);


uint32_t safe_lv_label_get_text_selection_start(const lv_obj_t * obj);


uint32_t safe_lv_label_get_text_selection_end(const lv_obj_t * obj);


void safe_lv_label_ins_text(lv_obj_t * obj, uint32_t pos, const char * txt);


void safe_lv_label_cut_text(lv_obj_t * obj, uint32_t pos, uint32_t cnt);


lv_obj_t * safe_lv_line_create(lv_obj_t * parent);


void safe_lv_line_set_points(lv_obj_t * obj, const lv_point_t points[], uint16_t point_num);


void safe_lv_line_set_y_invert(lv_obj_t * obj, bool en);


bool safe_lv_line_get_y_invert(const lv_obj_t * obj);


lv_obj_t * safe_lv_table_create(lv_obj_t * parent);


void safe_lv_table_set_cell_value(lv_obj_t * obj, uint16_t row, uint16_t col, const char * txt);


void safe_lv_table_set_row_cnt(lv_obj_t * obj, uint16_t row_cnt);


void safe_lv_table_set_col_cnt(lv_obj_t * obj, uint16_t col_cnt);


void safe_lv_table_set_col_width(lv_obj_t * obj, uint16_t col_id, lv_coord_t w);


void safe_lv_table_add_cell_ctrl(lv_obj_t * obj, uint16_t row, uint16_t col, lv_table_cell_ctrl_t ctrl);


void safe_lv_table_clear_cell_ctrl(lv_obj_t * obj, uint16_t row, uint16_t col, lv_table_cell_ctrl_t ctrl);


const char * safe_lv_table_get_cell_value(lv_obj_t * obj, uint16_t row, uint16_t col);


uint16_t safe_lv_table_get_row_cnt(lv_obj_t * obj);


uint16_t safe_lv_table_get_col_cnt(lv_obj_t * obj);


lv_coord_t safe_lv_table_get_col_width(lv_obj_t * obj, uint16_t col);


bool safe_lv_table_has_cell_ctrl(lv_obj_t * obj, uint16_t row, uint16_t col, lv_table_cell_ctrl_t ctrl);


void safe_lv_table_get_selected_cell(lv_obj_t * obj, uint16_t * row, uint16_t * col);


lv_obj_t * safe_lv_checkbox_create(lv_obj_t * parent);


void safe_lv_checkbox_set_text(lv_obj_t * obj, const char * txt);


void safe_lv_checkbox_set_text_static(lv_obj_t * obj, const char * txt);


const char * safe_lv_checkbox_get_text(const lv_obj_t * obj);


lv_obj_t * safe_lv_bar_create(lv_obj_t * parent);


void safe_lv_bar_set_value(lv_obj_t * obj, int32_t value, lv_anim_enable_t anim);


void safe_lv_bar_set_start_value(lv_obj_t * obj, int32_t start_value, lv_anim_enable_t anim);


void safe_lv_bar_set_range(lv_obj_t * obj, int32_t min, int32_t max);


void safe_lv_bar_set_mode(lv_obj_t * obj, lv_bar_mode_t mode);


int32_t safe_lv_bar_get_value(const lv_obj_t * obj);


int32_t safe_lv_bar_get_start_value(const lv_obj_t * obj);


int32_t safe_lv_bar_get_min_value(const lv_obj_t * obj);


int32_t safe_lv_bar_get_max_value(const lv_obj_t * obj);


lv_bar_mode_t safe_lv_bar_get_mode(lv_obj_t * obj);


lv_obj_t * safe_lv_slider_create(lv_obj_t * parent);


static inline void safe_lv_slider_set_value(lv_obj_t * obj, int32_t value, lv_anim_enable_t anim);


static inline void safe_lv_slider_set_left_value(lv_obj_t * obj, int32_t value, lv_anim_enable_t anim);


static inline void safe_lv_slider_set_range(lv_obj_t * obj, int32_t min, int32_t max);


static inline void safe_lv_slider_set_mode(lv_obj_t * obj, lv_slider_mode_t mode);


static inline int32_t safe_lv_slider_get_value(const lv_obj_t * obj);


static inline int32_t safe_lv_slider_get_left_value(const lv_obj_t * obj);


static inline int32_t safe_lv_slider_get_min_value(const lv_obj_t * obj);


static inline int32_t safe_lv_slider_get_max_value(const lv_obj_t * obj);


bool safe_lv_slider_is_dragged(const lv_obj_t * obj);


static inline lv_slider_mode_t safe_lv_slider_get_mode(lv_obj_t * slider);


lv_obj_t * safe_lv_btnmatrix_create(lv_obj_t * parent);


void safe_lv_btnmatrix_set_map(lv_obj_t * obj, const char * map[]);


void safe_lv_btnmatrix_set_ctrl_map(lv_obj_t * obj, const lv_btnmatrix_ctrl_t ctrl_map[]);


void safe_lv_btnmatrix_set_selected_btn(lv_obj_t * obj, uint16_t btn_id);


void safe_lv_btnmatrix_set_btn_ctrl(lv_obj_t * obj, uint16_t btn_id, lv_btnmatrix_ctrl_t ctrl);


void safe_lv_btnmatrix_clear_btn_ctrl(lv_obj_t * obj, uint16_t btn_id, lv_btnmatrix_ctrl_t ctrl);


void safe_lv_btnmatrix_set_btn_ctrl_all(lv_obj_t * obj, lv_btnmatrix_ctrl_t ctrl);


void safe_lv_btnmatrix_clear_btn_ctrl_all(lv_obj_t * obj, lv_btnmatrix_ctrl_t ctrl);


void safe_lv_btnmatrix_set_btn_width(lv_obj_t * obj, uint16_t btn_id, uint8_t width);


void safe_lv_btnmatrix_set_one_checked(lv_obj_t * obj, bool en);


const char ** safe_lv_btnmatrix_get_map(const lv_obj_t * obj);


uint16_t safe_lv_btnmatrix_get_selected_btn(const lv_obj_t * obj);


const char * safe_lv_btnmatrix_get_btn_text(const lv_obj_t * obj, uint16_t btn_id);


bool safe_lv_btnmatrix_has_btn_ctrl(lv_obj_t * obj, uint16_t btn_id, lv_btnmatrix_ctrl_t ctrl);


bool safe_lv_btnmatrix_get_one_checked(const lv_obj_t * obj);


lv_obj_t * safe_lv_dropdown_create(lv_obj_t * parent);


void safe_lv_dropdown_set_text(lv_obj_t * obj, const char * txt);


void safe_lv_dropdown_set_options(lv_obj_t * obj, const char * options);


void safe_lv_dropdown_set_options_static(lv_obj_t * obj, const char * options);


void safe_lv_dropdown_add_option(lv_obj_t * obj, const char * option, uint32_t pos);


void safe_lv_dropdown_clear_options(lv_obj_t * obj);


void safe_lv_dropdown_set_selected(lv_obj_t * obj, uint16_t sel_opt);


void safe_lv_dropdown_set_dir(lv_obj_t * obj, lv_dir_t dir);


void safe_lv_dropdown_set_symbol(lv_obj_t * obj, const void * symbol);


void safe_lv_dropdown_set_selected_highlight(lv_obj_t * obj, bool en);


lv_obj_t * safe_lv_dropdown_get_list(lv_obj_t * obj);


const char * safe_lv_dropdown_get_text(lv_obj_t * obj);


const char * safe_lv_dropdown_get_options(const lv_obj_t * obj);


uint16_t safe_lv_dropdown_get_selected(const lv_obj_t * obj);


uint16_t safe_lv_dropdown_get_option_cnt(const lv_obj_t * obj);


void safe_lv_dropdown_get_selected_str(const lv_obj_t * obj, char * buf, uint32_t buf_size);


int32_t safe_lv_dropdown_get_option_index(lv_obj_t * obj, const char * option);


const char * safe_lv_dropdown_get_symbol(lv_obj_t * obj);


bool safe_lv_dropdown_get_selected_highlight(lv_obj_t * obj);


lv_dir_t safe_lv_dropdown_get_dir(const lv_obj_t * obj);


void safe_lv_dropdown_open(lv_obj_t * dropdown_obj);


void safe_lv_dropdown_close(lv_obj_t * obj);


bool safe_lv_dropdown_is_open(lv_obj_t * obj);


lv_obj_t * safe_lv_roller_create(lv_obj_t * parent);


void safe_lv_roller_set_options(lv_obj_t * obj, const char * options, lv_roller_mode_t mode);


void safe_lv_roller_set_selected(lv_obj_t * obj, uint16_t sel_opt, lv_anim_enable_t anim);


void safe_lv_roller_set_visible_row_count(lv_obj_t * obj, uint8_t row_cnt);


uint16_t safe_lv_roller_get_selected(const lv_obj_t * obj);


void safe_lv_roller_get_selected_str(const lv_obj_t * obj, char * buf, uint32_t buf_size);


const char * safe_lv_roller_get_options(const lv_obj_t * obj);


uint16_t safe_lv_roller_get_option_cnt(const lv_obj_t * obj);


lv_obj_t * safe_lv_textarea_create(lv_obj_t * parent);


void safe_lv_textarea_add_char(lv_obj_t * obj, uint32_t c);


void safe_lv_textarea_add_text(lv_obj_t * obj, const char * txt);


void safe_lv_textarea_del_char(lv_obj_t * obj);


void safe_lv_textarea_del_char_forward(lv_obj_t * obj);


void safe_lv_textarea_set_text(lv_obj_t * obj, const char * txt);


void safe_lv_textarea_set_placeholder_text(lv_obj_t * obj, const char * txt);


void safe_lv_textarea_set_cursor_pos(lv_obj_t * obj, int32_t pos);


void safe_lv_textarea_set_cursor_click_pos(lv_obj_t * obj, bool en);


void safe_lv_textarea_set_password_mode(lv_obj_t * obj, bool en);


void safe_lv_textarea_set_password_bullet(lv_obj_t * obj, const char * bullet);


void safe_lv_textarea_set_one_line(lv_obj_t * obj, bool en);


void safe_lv_textarea_set_accepted_chars(lv_obj_t * obj, const char * list);


void safe_lv_textarea_set_max_length(lv_obj_t * obj, uint32_t num);


void safe_lv_textarea_set_insert_replace(lv_obj_t * obj, const char * txt);


void safe_lv_textarea_set_text_selection(lv_obj_t * obj, bool en);


void safe_lv_textarea_set_password_show_time(lv_obj_t * obj, uint16_t time);


void safe_lv_textarea_set_align(lv_obj_t * obj, lv_text_align_t align);


const char * safe_lv_textarea_get_text(const lv_obj_t * obj);


const char * safe_lv_textarea_get_placeholder_text(lv_obj_t * obj);


lv_obj_t * safe_lv_textarea_get_label(const lv_obj_t * obj);


uint32_t safe_lv_textarea_get_cursor_pos(const lv_obj_t * obj);


bool safe_lv_textarea_get_cursor_click_pos(lv_obj_t * obj);


bool safe_lv_textarea_get_password_mode(const lv_obj_t * obj);


const char * safe_lv_textarea_get_password_bullet(lv_obj_t * obj);


bool safe_lv_textarea_get_one_line(const lv_obj_t * obj);


const char * safe_lv_textarea_get_accepted_chars(lv_obj_t * obj);


uint32_t safe_lv_textarea_get_max_length(lv_obj_t * obj);


bool safe_lv_textarea_text_is_selected(const lv_obj_t * obj);


bool safe_lv_textarea_get_text_selection(lv_obj_t * obj);


uint16_t safe_lv_textarea_get_password_show_time(lv_obj_t * obj);


void safe_lv_textarea_clear_selection(lv_obj_t * obj);


void safe_lv_textarea_cursor_right(lv_obj_t * obj);


void safe_lv_textarea_cursor_left(lv_obj_t * obj);


void safe_lv_textarea_cursor_down(lv_obj_t * obj);


void safe_lv_textarea_cursor_up(lv_obj_t * obj);


lv_obj_t * safe_lv_canvas_create(lv_obj_t * parent);


void safe_lv_canvas_set_buffer(lv_obj_t * canvas, void * buf, lv_coord_t w, lv_coord_t h, lv_img_cf_t cf);


void safe_lv_canvas_set_px_color(lv_obj_t * canvas, lv_coord_t x, lv_coord_t y, lv_color_t c);


static inline void safe_lv_canvas_set_px(lv_obj_t * canvas, lv_coord_t x, lv_coord_t y, lv_color_t c);


void safe_lv_canvas_set_px_opa(lv_obj_t * canvas, lv_coord_t x, lv_coord_t y, lv_opa_t opa);


void safe_lv_canvas_set_palette(lv_obj_t * canvas, uint8_t id, lv_color_t c);


lv_color_t safe_lv_canvas_get_px(lv_obj_t * canvas, lv_coord_t x, lv_coord_t y);


lv_img_dsc_t * safe_lv_canvas_get_img(lv_obj_t * canvas);


void safe_lv_canvas_copy_buf(lv_obj_t * canvas, const void * to_copy, lv_coord_t x, lv_coord_t y, lv_coord_t w, lv_coord_t h);


void safe_lv_canvas_transform(lv_obj_t * canvas, lv_img_dsc_t * img, int16_t angle, uint16_t zoom, lv_coord_t offset_x, lv_coord_t offset_y, int32_t pivot_x, int32_t pivot_y, bool antialias);


void safe_lv_canvas_blur_hor(lv_obj_t * canvas, const lv_area_t * area, uint16_t r);


void safe_lv_canvas_blur_ver(lv_obj_t * canvas, const lv_area_t * area, uint16_t r);


void safe_lv_canvas_fill_bg(lv_obj_t * canvas, lv_color_t color, lv_opa_t opa);


void safe_lv_canvas_draw_rect(lv_obj_t * canvas, lv_coord_t x, lv_coord_t y, lv_coord_t w, lv_coord_t h, const lv_draw_rect_dsc_t * draw_dsc);


void safe_lv_canvas_draw_text(lv_obj_t * canvas, lv_coord_t x, lv_coord_t y, lv_coord_t max_w, lv_draw_label_dsc_t * draw_dsc, const char * txt);


void safe_lv_canvas_draw_img(lv_obj_t * canvas, lv_coord_t x, lv_coord_t y, const void * src, const lv_draw_img_dsc_t * draw_dsc);


void safe_lv_canvas_draw_line(lv_obj_t * canvas, const lv_point_t points[], uint32_t point_cnt, const lv_draw_line_dsc_t * draw_dsc);


void safe_lv_canvas_draw_polygon(lv_obj_t * canvas, const lv_point_t points[], uint32_t point_cnt, const lv_draw_rect_dsc_t * draw_dsc);


void safe_lv_canvas_draw_arc(lv_obj_t * canvas, lv_coord_t x, lv_coord_t y, lv_coord_t r, int32_t start_angle, int32_t end_angle, const lv_draw_arc_dsc_t * draw_dsc);


lv_obj_t * safe_lv_switch_create(lv_obj_t * parent);


static inline uint32_t safe_lv_task_handler(void);


static inline void safe_lv_obj_move_foreground(lv_obj_t * obj);


static inline void safe_lv_obj_move_background(lv_obj_t * obj);


static inline uint32_t safe_lv_obj_get_child_id(const struct _lv_obj_t * obj);


void safe_lv_flex_init(void);


void safe_lv_obj_set_flex_flow(lv_obj_t * obj, lv_flex_flow_t flow);


void safe_lv_obj_set_flex_align(lv_obj_t * obj, lv_flex_align_t main_place, lv_flex_align_t cross_place, lv_flex_align_t track_cross_place);


void safe_lv_obj_set_flex_grow(lv_obj_t * obj, uint8_t grow);


void safe_lv_style_set_flex_flow(lv_style_t * style, lv_flex_flow_t value);


void safe_lv_style_set_flex_main_place(lv_style_t * style, lv_flex_align_t value);


void safe_lv_style_set_flex_cross_place(lv_style_t * style, lv_flex_align_t value);


void safe_lv_style_set_flex_track_place(lv_style_t * style, lv_flex_align_t value);


void safe_lv_style_set_flex_grow(lv_style_t * style, uint8_t value);


void safe_lv_obj_set_style_flex_flow(lv_obj_t * obj, lv_flex_flow_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_flex_main_place(lv_obj_t * obj, lv_flex_align_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_flex_cross_place(lv_obj_t * obj, lv_flex_align_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_flex_track_place(lv_obj_t * obj, lv_flex_align_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_flex_grow(lv_obj_t * obj, uint8_t value, lv_style_selector_t selector);


static inline lv_flex_flow_t safe_lv_obj_get_style_flex_flow(const lv_obj_t * obj, uint32_t part);


static inline lv_flex_align_t safe_lv_obj_get_style_flex_main_place(const lv_obj_t * obj, uint32_t part);


static inline lv_flex_align_t safe_lv_obj_get_style_flex_cross_place(const lv_obj_t * obj, uint32_t part);


static inline lv_flex_align_t safe_lv_obj_get_style_flex_track_place(const lv_obj_t * obj, uint32_t part);


static inline uint8_t safe_lv_obj_get_style_flex_grow(const lv_obj_t * obj, uint32_t part);


void safe_lv_grid_init(void);


void safe_lv_obj_set_grid_dsc_array(lv_obj_t * obj, const lv_coord_t col_dsc[], const lv_coord_t row_dsc[]);


void safe_lv_obj_set_grid_align(lv_obj_t * obj, lv_grid_align_t column_align, lv_grid_align_t row_align);


void safe_lv_obj_set_grid_cell(lv_obj_t * obj, lv_grid_align_t column_align, uint8_t col_pos, uint8_t col_span, lv_grid_align_t row_align, uint8_t row_pos, uint8_t row_span);


static inline lv_coord_t safe_lv_grid_fr(uint8_t x);


void safe_lv_style_set_grid_row_dsc_array(lv_style_t * style, const lv_coord_t value[]);


void safe_lv_style_set_grid_column_dsc_array(lv_style_t * style, const lv_coord_t value[]);


void safe_lv_style_set_grid_row_align(lv_style_t * style, lv_grid_align_t value);


void safe_lv_style_set_grid_column_align(lv_style_t * style, lv_grid_align_t value);


void safe_lv_style_set_grid_cell_column_pos(lv_style_t * style, lv_coord_t value);


void safe_lv_style_set_grid_cell_column_span(lv_style_t * style, lv_coord_t value);


void safe_lv_style_set_grid_cell_row_pos(lv_style_t * style, lv_coord_t value);


void safe_lv_style_set_grid_cell_row_span(lv_style_t * style, lv_coord_t value);


void safe_lv_style_set_grid_cell_x_align(lv_style_t * style, lv_coord_t value);


void safe_lv_style_set_grid_cell_y_align(lv_style_t * style, lv_coord_t value);


void safe_lv_obj_set_style_grid_row_dsc_array(lv_obj_t * obj, const lv_coord_t value[], lv_style_selector_t selector);


void safe_lv_obj_set_style_grid_column_dsc_array(lv_obj_t * obj, const lv_coord_t value[], lv_style_selector_t selector);


void safe_lv_obj_set_style_grid_row_align(lv_obj_t * obj, lv_grid_align_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_grid_column_align(lv_obj_t * obj, lv_grid_align_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_grid_cell_column_pos(lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_grid_cell_column_span(lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_grid_cell_row_pos(lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_grid_cell_row_span(lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_grid_cell_x_align(lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector);


void safe_lv_obj_set_style_grid_cell_y_align(lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector);


const static inline lv_coord_t * safe_lv_obj_get_style_grid_row_dsc_array(const lv_obj_t * obj, uint32_t part);


const static inline lv_coord_t * safe_lv_obj_get_style_grid_column_dsc_array(const lv_obj_t * obj, uint32_t part);


static inline lv_grid_align_t safe_lv_obj_get_style_grid_row_align(const lv_obj_t * obj, uint32_t part);


static inline lv_grid_align_t safe_lv_obj_get_style_grid_column_align(const lv_obj_t * obj, uint32_t part);


static inline lv_coord_t safe_lv_obj_get_style_grid_cell_column_pos(const lv_obj_t * obj, uint32_t part);


static inline lv_coord_t safe_lv_obj_get_style_grid_cell_column_span(const lv_obj_t * obj, uint32_t part);


static inline lv_coord_t safe_lv_obj_get_style_grid_cell_row_pos(const lv_obj_t * obj, uint32_t part);


static inline lv_coord_t safe_lv_obj_get_style_grid_cell_row_span(const lv_obj_t * obj, uint32_t part);


static inline lv_coord_t safe_lv_obj_get_style_grid_cell_x_align(const lv_obj_t * obj, uint32_t part);


static inline lv_coord_t safe_lv_obj_get_style_grid_cell_y_align(const lv_obj_t * obj, uint32_t part);


lv_theme_t * safe_lv_theme_default_init(lv_disp_t * disp, lv_color_t color_primary, lv_color_t color_secondary, bool dark, const lv_font_t * font);


lv_theme_t * safe_lv_theme_default_get(void);


bool safe_lv_theme_default_is_inited(void);


lv_theme_t * safe_lv_theme_mono_init(lv_disp_t * disp, bool dark_bg, const lv_font_t * font);


bool safe_lv_theme_mono_is_inited(void);


lv_theme_t * safe_lv_theme_basic_init(lv_disp_t * disp);


bool safe_lv_theme_basic_is_inited(void);


lv_obj_t * safe_lv_animimg_create(lv_obj_t * parent);


void safe_lv_animimg_set_src(lv_obj_t * img, lv_img_dsc_t * dsc[], uint8_t num);


void safe_lv_animimg_start(lv_obj_t * obj);


void safe_lv_animimg_set_duration(lv_obj_t * img, uint32_t duration);


void safe_lv_animimg_set_repeat_count(lv_obj_t * img, uint16_t count);


lv_obj_t * safe_lv_calendar_create(lv_obj_t * parent);


void safe_lv_calendar_set_today_date(lv_obj_t * obj, uint32_t year, uint32_t month, uint32_t day);


void safe_lv_calendar_set_showed_date(lv_obj_t * obj, uint32_t year, uint32_t month);


void safe_lv_calendar_set_highlighted_dates(lv_obj_t * obj, lv_calendar_date_t highlighted[], uint16_t date_num);


void safe_lv_calendar_set_day_names(lv_obj_t * obj, const char ** day_names);


lv_obj_t * safe_lv_calendar_get_btnmatrix(const lv_obj_t * obj);


const lv_calendar_date_t * safe_lv_calendar_get_today_date(const lv_obj_t * calendar);


const lv_calendar_date_t * safe_lv_calendar_get_showed_date(const lv_obj_t * calendar);


lv_calendar_date_t * safe_lv_calendar_get_highlighted_dates(const lv_obj_t * calendar);


uint16_t safe_lv_calendar_get_highlighted_dates_num(const lv_obj_t * calendar);


lv_res_t safe_lv_calendar_get_pressed_date(const lv_obj_t * calendar, lv_calendar_date_t * date);


lv_obj_t * safe_lv_calendar_header_arrow_create(lv_obj_t * parent);


lv_obj_t * safe_lv_calendar_header_dropdown_create(lv_obj_t * parent);


lv_obj_t * safe_lv_chart_create(lv_obj_t * parent);


void safe_lv_chart_set_type(lv_obj_t * obj, lv_chart_type_t type);


void safe_lv_chart_set_point_count(lv_obj_t * obj, uint16_t cnt);


void safe_lv_chart_set_range(lv_obj_t * obj, lv_chart_axis_t axis, lv_coord_t min, lv_coord_t max);


void safe_lv_chart_set_update_mode(lv_obj_t * obj, lv_chart_update_mode_t update_mode);


void safe_lv_chart_set_div_line_count(lv_obj_t * obj, uint8_t hdiv, uint8_t vdiv);


void safe_lv_chart_set_zoom_x(lv_obj_t * obj, uint16_t zoom_x);


void safe_lv_chart_set_zoom_y(lv_obj_t * obj, uint16_t zoom_y);


uint16_t safe_lv_chart_get_zoom_x(const lv_obj_t * obj);


uint16_t safe_lv_chart_get_zoom_y(const lv_obj_t * obj);


void safe_lv_chart_set_axis_tick(lv_obj_t * obj, lv_chart_axis_t axis, lv_coord_t major_len, lv_coord_t minor_len, lv_coord_t major_cnt, lv_coord_t minor_cnt, bool label_en, lv_coord_t draw_size);


lv_chart_type_t safe_lv_chart_get_type(const lv_obj_t * obj);


uint16_t safe_lv_chart_get_point_count(const lv_obj_t * obj);


uint16_t safe_lv_chart_get_x_start_point(const lv_obj_t * obj, lv_chart_series_t * ser);


void safe_lv_chart_get_point_pos_by_id(lv_obj_t * obj, lv_chart_series_t * ser, uint16_t id, lv_point_t * p_out);


void safe_lv_chart_refresh(lv_obj_t * obj);


lv_chart_series_t * safe_lv_chart_add_series(lv_obj_t * obj, lv_color_t color, lv_chart_axis_t axis);


void safe_lv_chart_remove_series(lv_obj_t * obj, lv_chart_series_t * series);


void safe_lv_chart_hide_series(lv_obj_t * chart, lv_chart_series_t * series, bool hide);


void safe_lv_chart_set_series_color(lv_obj_t * chart, lv_chart_series_t * series, lv_color_t color);


void safe_lv_chart_set_x_start_point(lv_obj_t * obj, lv_chart_series_t * ser, uint16_t id);


lv_chart_series_t * safe_lv_chart_get_series_next(const lv_obj_t * chart, const lv_chart_series_t * ser);


lv_chart_cursor_t * safe_lv_chart_add_cursor(lv_obj_t * obj, lv_color_t color, lv_dir_t dir);


void safe_lv_chart_set_cursor_pos(lv_obj_t * chart, lv_chart_cursor_t * cursor, lv_point_t * pos);


void safe_lv_chart_set_cursor_point(lv_obj_t * chart, lv_chart_cursor_t * cursor, lv_chart_series_t * ser, uint16_t point_id);


lv_point_t safe_lv_chart_get_cursor_point(lv_obj_t * chart, lv_chart_cursor_t * cursor);


void safe_lv_chart_set_all_value(lv_obj_t * obj, lv_chart_series_t * ser, lv_coord_t value);


void safe_lv_chart_set_next_value(lv_obj_t * obj, lv_chart_series_t * ser, lv_coord_t value);


void safe_lv_chart_set_next_value2(lv_obj_t * obj, lv_chart_series_t * ser, lv_coord_t x_value, lv_coord_t y_value);


void safe_lv_chart_set_value_by_id(lv_obj_t * obj, lv_chart_series_t * ser, uint16_t id, lv_coord_t value);


void safe_lv_chart_set_value_by_id2(lv_obj_t * obj, lv_chart_series_t * ser, uint16_t id, lv_coord_t x_value, lv_coord_t y_value);


void safe_lv_chart_set_ext_y_array(lv_obj_t * obj, lv_chart_series_t * ser, lv_coord_t array[]);


void safe_lv_chart_set_ext_x_array(lv_obj_t * obj, lv_chart_series_t * ser, lv_coord_t array[]);


lv_coord_t * safe_lv_chart_get_y_array(const lv_obj_t * obj, lv_chart_series_t * ser);


lv_coord_t * safe_lv_chart_get_x_array(const lv_obj_t * obj, lv_chart_series_t * ser);


uint32_t safe_lv_chart_get_pressed_point(const lv_obj_t * obj);


lv_obj_t * safe_lv_keyboard_create(lv_obj_t * parent);


void safe_lv_keyboard_set_textarea(lv_obj_t * kb, lv_obj_t * ta);


void safe_lv_keyboard_set_mode(lv_obj_t * kb, lv_keyboard_mode_t mode);


void safe_lv_keyboard_set_popovers(lv_obj_t * kb, bool en);


void safe_lv_keyboard_set_map(lv_obj_t * kb, lv_keyboard_mode_t mode, const char * map[], const lv_btnmatrix_ctrl_t ctrl_map[]);


lv_obj_t * safe_lv_keyboard_get_textarea(const lv_obj_t * kb);


lv_keyboard_mode_t safe_lv_keyboard_get_mode(const lv_obj_t * kb);


bool safe_lv_btnmatrix_get_popovers(const lv_obj_t * obj);


const static inline char ** safe_lv_keyboard_get_map_array(const lv_obj_t * kb);


static inline uint16_t safe_lv_keyboard_get_selected_btn(const lv_obj_t * obj);


const static inline char * safe_lv_keyboard_get_btn_text(const lv_obj_t * obj, uint16_t btn_id);


void safe_lv_keyboard_def_event_cb(lv_event_t * e);


lv_obj_t * safe_lv_list_create(lv_obj_t * parent);


lv_obj_t * safe_lv_list_add_text(lv_obj_t * list, const char * txt);


lv_obj_t * safe_lv_list_add_btn(lv_obj_t * list, const void * icon, const char * txt);


const char * safe_lv_list_get_btn_text(lv_obj_t * list, lv_obj_t * btn);


lv_obj_t * safe_lv_menu_create(lv_obj_t * parent);


lv_obj_t * safe_lv_menu_page_create(lv_obj_t * parent, char * title);


lv_obj_t * safe_lv_menu_cont_create(lv_obj_t * parent);


lv_obj_t * safe_lv_menu_section_create(lv_obj_t * parent);


lv_obj_t * safe_lv_menu_separator_create(lv_obj_t * parent);


void safe_lv_menu_set_page(lv_obj_t * obj, lv_obj_t * page);


void safe_lv_menu_set_sidebar_page(lv_obj_t * obj, lv_obj_t * page);


void safe_lv_menu_set_mode_header(lv_obj_t * obj, lv_menu_mode_header_t mode_header);


void safe_lv_menu_set_mode_root_back_btn(lv_obj_t * obj, lv_menu_mode_root_back_btn_t mode_root_back_btn);


void safe_lv_menu_set_load_page_event(lv_obj_t * menu, lv_obj_t * obj, lv_obj_t * page);


lv_obj_t * safe_lv_menu_get_cur_main_page(lv_obj_t * obj);


lv_obj_t * safe_lv_menu_get_cur_sidebar_page(lv_obj_t * obj);


lv_obj_t * safe_lv_menu_get_main_header(lv_obj_t * obj);


lv_obj_t * safe_lv_menu_get_main_header_back_btn(lv_obj_t * obj);


lv_obj_t * safe_lv_menu_get_sidebar_header(lv_obj_t * obj);


lv_obj_t * safe_lv_menu_get_sidebar_header_back_btn(lv_obj_t * obj);


bool safe_lv_menu_back_btn_is_root(lv_obj_t * menu, lv_obj_t * obj);


void safe_lv_menu_clear_history(lv_obj_t * obj);


lv_obj_t * safe_lv_msgbox_create(lv_obj_t * parent, const char * title, const char * txt, const char * btn_txts[], bool add_close_btn);


lv_obj_t * safe_lv_msgbox_get_title(lv_obj_t * obj);


lv_obj_t * safe_lv_msgbox_get_close_btn(lv_obj_t * obj);


lv_obj_t * safe_lv_msgbox_get_text(lv_obj_t * obj);


lv_obj_t * safe_lv_msgbox_get_content(lv_obj_t * obj);


lv_obj_t * safe_lv_msgbox_get_btns(lv_obj_t * obj);


uint16_t safe_lv_msgbox_get_active_btn(lv_obj_t * mbox);


const char * safe_lv_msgbox_get_active_btn_text(lv_obj_t * mbox);


void safe_lv_msgbox_close(lv_obj_t * mbox);


void safe_lv_msgbox_close_async(lv_obj_t * mbox);


lv_obj_t * safe_lv_meter_create(lv_obj_t * parent);


lv_meter_scale_t * safe_lv_meter_add_scale(lv_obj_t * obj);


void safe_lv_meter_set_scale_ticks(lv_obj_t * obj, lv_meter_scale_t * scale, uint16_t cnt, uint16_t width, uint16_t len, lv_color_t color);


void safe_lv_meter_set_scale_major_ticks(lv_obj_t * obj, lv_meter_scale_t * scale, uint16_t nth, uint16_t width, uint16_t len, lv_color_t color, int16_t label_gap);


void safe_lv_meter_set_scale_range(lv_obj_t * obj, lv_meter_scale_t * scale, int32_t min, int32_t max, uint32_t angle_range, uint32_t rotation);


lv_meter_indicator_t * safe_lv_meter_add_needle_line(lv_obj_t * obj, lv_meter_scale_t * scale, uint16_t width, lv_color_t color, int16_t r_mod);


lv_meter_indicator_t * safe_lv_meter_add_needle_img(lv_obj_t * obj, lv_meter_scale_t * scale, const void * src, lv_coord_t pivot_x, lv_coord_t pivot_y);


lv_meter_indicator_t * safe_lv_meter_add_arc(lv_obj_t * obj, lv_meter_scale_t * scale, uint16_t width, lv_color_t color, int16_t r_mod);


lv_meter_indicator_t * safe_lv_meter_add_scale_lines(lv_obj_t * obj, lv_meter_scale_t * scale, lv_color_t color_start, lv_color_t color_end, bool local, int16_t width_mod);


void safe_lv_meter_set_indicator_value(lv_obj_t * obj, lv_meter_indicator_t * indic, int32_t value);


void safe_lv_meter_set_indicator_start_value(lv_obj_t * obj, lv_meter_indicator_t * indic, int32_t value);


void safe_lv_meter_set_indicator_end_value(lv_obj_t * obj, lv_meter_indicator_t * indic, int32_t value);


lv_obj_t * safe_lv_spinbox_create(lv_obj_t * parent);


void safe_lv_spinbox_set_value(lv_obj_t * obj, int32_t i);


void safe_lv_spinbox_set_rollover(lv_obj_t * obj, bool b);


void safe_lv_spinbox_set_digit_format(lv_obj_t * obj, uint8_t digit_count, uint8_t separator_position);


void safe_lv_spinbox_set_step(lv_obj_t * obj, uint32_t step);


void safe_lv_spinbox_set_range(lv_obj_t * obj, int32_t range_min, int32_t range_max);


void safe_lv_spinbox_set_cursor_pos(lv_obj_t * obj, uint8_t pos);


void safe_lv_spinbox_set_digit_step_direction(lv_obj_t * obj, lv_dir_t direction);


bool safe_lv_spinbox_get_rollover(lv_obj_t * obj);


int32_t safe_lv_spinbox_get_value(lv_obj_t * obj);


int32_t safe_lv_spinbox_get_step(lv_obj_t * obj);


void safe_lv_spinbox_step_next(lv_obj_t * obj);


void safe_lv_spinbox_step_prev(lv_obj_t * obj);


void safe_lv_spinbox_increment(lv_obj_t * obj);


void safe_lv_spinbox_decrement(lv_obj_t * obj);


lv_obj_t * safe_lv_spinner_create(lv_obj_t * parent, uint32_t time, uint32_t arc_length);


lv_obj_t * safe_lv_tabview_create(lv_obj_t * parent, lv_dir_t tab_pos, lv_coord_t tab_size);


lv_obj_t * safe_lv_tabview_add_tab(lv_obj_t * tv, const char * name);


void safe_lv_tabview_rename_tab(lv_obj_t * obj, uint32_t tab_id, const char * new_name);


lv_obj_t * safe_lv_tabview_get_content(lv_obj_t * tv);


lv_obj_t * safe_lv_tabview_get_tab_btns(lv_obj_t * tv);


void safe_lv_tabview_set_act(lv_obj_t * obj, uint32_t id, lv_anim_enable_t anim_en);


uint16_t safe_lv_tabview_get_tab_act(lv_obj_t * tv);


lv_obj_t * safe_lv_tileview_create(lv_obj_t * parent);


lv_obj_t * safe_lv_tileview_add_tile(lv_obj_t * tv, uint8_t col_id, uint8_t row_id, lv_dir_t dir);


void safe_lv_obj_set_tile(lv_obj_t * tv, lv_obj_t * tile_obj, lv_anim_enable_t anim_en);


void safe_lv_obj_set_tile_id(lv_obj_t * tv, uint32_t col_id, uint32_t row_id, lv_anim_enable_t anim_en);


lv_obj_t * safe_lv_tileview_get_tile_act(lv_obj_t * obj);


lv_obj_t * safe_lv_win_create(lv_obj_t * parent, lv_coord_t header_height);


lv_obj_t * safe_lv_win_add_title(lv_obj_t * win, const char * txt);


lv_obj_t * safe_lv_win_add_btn(lv_obj_t * win, const void * icon, lv_coord_t btn_w);


lv_obj_t * safe_lv_win_get_header(lv_obj_t * win);


lv_obj_t * safe_lv_win_get_content(lv_obj_t * win);


lv_obj_t * safe_lv_colorwheel_create(lv_obj_t * parent, bool knob_recolor);


bool safe_lv_colorwheel_set_hsv(lv_obj_t * obj, lv_color_hsv_t hsv);


bool safe_lv_colorwheel_set_rgb(lv_obj_t * obj, lv_color_t color);


void safe_lv_colorwheel_set_mode(lv_obj_t * obj, lv_colorwheel_mode_t mode);


void safe_lv_colorwheel_set_mode_fixed(lv_obj_t * obj, bool fixed);


lv_color_hsv_t safe_lv_colorwheel_get_hsv(lv_obj_t * obj);


lv_color_t safe_lv_colorwheel_get_rgb(lv_obj_t * obj);


lv_colorwheel_mode_t safe_lv_colorwheel_get_color_mode(lv_obj_t * obj);


bool safe_lv_colorwheel_get_color_mode_fixed(lv_obj_t * obj);


lv_obj_t * safe_lv_led_create(lv_obj_t * parent);


void safe_lv_led_set_color(lv_obj_t * led, lv_color_t color);


void safe_lv_led_set_brightness(lv_obj_t * led, uint8_t bright);


void safe_lv_led_on(lv_obj_t * led);


void safe_lv_led_off(lv_obj_t * led);


void safe_lv_led_toggle(lv_obj_t * led);


uint8_t safe_lv_led_get_brightness(const lv_obj_t * obj);


lv_obj_t * safe_lv_imgbtn_create(lv_obj_t * parent);


void safe_lv_imgbtn_set_src(lv_obj_t * imgbtn, lv_imgbtn_state_t state, const void * src_left, const void * src_mid, const void * src_right);


void safe_lv_imgbtn_set_state(lv_obj_t * imgbtn, lv_imgbtn_state_t state);


const void * safe_lv_imgbtn_get_src_left(lv_obj_t * imgbtn, lv_imgbtn_state_t state);


const void * safe_lv_imgbtn_get_src_middle(lv_obj_t * imgbtn, lv_imgbtn_state_t state);


const void * safe_lv_imgbtn_get_src_right(lv_obj_t * imgbtn, lv_imgbtn_state_t state);


lv_obj_t * safe_lv_spangroup_create(lv_obj_t * par);


lv_span_t * safe_lv_spangroup_new_span(lv_obj_t * obj);


void safe_lv_spangroup_del_span(lv_obj_t * obj, lv_span_t * span);


void safe_lv_span_set_text(lv_span_t * span, const char * text);


void safe_lv_span_set_text_static(lv_span_t * span, const char * text);


void safe_lv_spangroup_set_align(lv_obj_t * obj, lv_text_align_t align);


void safe_lv_spangroup_set_overflow(lv_obj_t * obj, lv_span_overflow_t overflow);


void safe_lv_spangroup_set_indent(lv_obj_t * obj, lv_coord_t indent);


void safe_lv_spangroup_set_mode(lv_obj_t * obj, lv_span_mode_t mode);


void safe_lv_spangroup_set_lines(lv_obj_t * obj, int32_t lines);


lv_span_t * safe_lv_spangroup_get_child(const lv_obj_t * obj, int32_t id);


uint32_t safe_lv_spangroup_get_child_cnt(const lv_obj_t * obj);


lv_text_align_t safe_lv_spangroup_get_align(lv_obj_t * obj);


lv_span_overflow_t safe_lv_spangroup_get_overflow(lv_obj_t * obj);


lv_coord_t safe_lv_spangroup_get_indent(lv_obj_t * obj);


lv_span_mode_t safe_lv_spangroup_get_mode(lv_obj_t * obj);


int32_t safe_lv_spangroup_get_lines(lv_obj_t * obj);


lv_coord_t safe_lv_spangroup_get_max_line_h(lv_obj_t * obj);


uint32_t safe_lv_spangroup_get_expand_width(lv_obj_t * obj, uint32_t max_width);


lv_coord_t safe_lv_spangroup_get_expand_height(lv_obj_t * obj, lv_coord_t width);


void safe_lv_spangroup_refr_mode(lv_obj_t * obj);


void safe_lv_extra_init(void);


static inline int safe_lv_version_major(void);


static inline int safe_lv_version_minor(void);


static inline int safe_lv_version_patch(void);


const static inline char * safe_lv_version_info(void);




#endif /* __SAFE_LVGL_H__ */
