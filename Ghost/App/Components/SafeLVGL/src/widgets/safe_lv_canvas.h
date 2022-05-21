//This file is automatically generated.
//The original file is lv_canvas.h
#include "lv_canvas.h"

//The original function is: lv_canvas_create.
lv_obj_t * safe_lv_canvas_create(lv_obj_t * parent);

//The original function is: lv_canvas_set_buffer.
void safe_lv_canvas_set_buffer(lv_obj_t * canvas, void * buf, lv_coord_t w, lv_coord_t h, lv_img_cf_t cf);

//The original function is: lv_canvas_set_px_color.
void safe_lv_canvas_set_px_color(lv_obj_t * canvas, lv_coord_t x, lv_coord_t y, lv_color_t c);

//The original function is: lv_canvas_set_px_opa.
void safe_lv_canvas_set_px_opa(lv_obj_t * canvas, lv_coord_t x, lv_coord_t y, lv_opa_t opa);

//The original function is: lv_canvas_set_palette.
void safe_lv_canvas_set_palette(lv_obj_t * canvas, uint8_t id, lv_color_t c);

//The original function is: lv_canvas_get_px.
lv_color_t safe_lv_canvas_get_px(lv_obj_t * canvas, lv_coord_t x, lv_coord_t y);

//The original function is: lv_canvas_get_img.
lv_img_dsc_t * safe_lv_canvas_get_img(lv_obj_t * canvas);

//The original function is: lv_canvas_blur_hor.
void safe_lv_canvas_blur_hor(lv_obj_t * canvas, const lv_area_t * area, uint16_t r);

//The original function is: lv_canvas_blur_ver.
void safe_lv_canvas_blur_ver(lv_obj_t * canvas, const lv_area_t * area, uint16_t r);

//The original function is: lv_canvas_fill_bg.
void safe_lv_canvas_fill_bg(lv_obj_t * canvas, lv_color_t color, lv_opa_t opa);

