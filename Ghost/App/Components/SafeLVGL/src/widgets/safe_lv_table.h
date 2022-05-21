//This file is automatically generated.
//The original file is lv_table.h
#include "lv_table.h"

//The original function is: lv_table_create.
lv_obj_t * safe_lv_table_create(lv_obj_t * parent);

//The original function is: lv_table_set_cell_value.
void safe_lv_table_set_cell_value(lv_obj_t * obj, uint16_t row, uint16_t col, const char * txt);

//The original function is: lv_table_set_cell_value_fmt.
void safe_lv_table_set_cell_value_fmt(lv_obj_t * obj, uint16_t row, uint16_t col, const char * fmt, ...);

//The original function is: lv_table_set_row_cnt.
void safe_lv_table_set_row_cnt(lv_obj_t * obj, uint16_t row_cnt);

//The original function is: lv_table_set_col_cnt.
void safe_lv_table_set_col_cnt(lv_obj_t * obj, uint16_t col_cnt);

//The original function is: lv_table_set_col_width.
void safe_lv_table_set_col_width(lv_obj_t * obj, uint16_t col_id, lv_coord_t w);

//The original function is: lv_table_add_cell_ctrl.
void safe_lv_table_add_cell_ctrl(lv_obj_t * obj, uint16_t row, uint16_t col, lv_table_cell_ctrl_t ctrl);

//The original function is: lv_table_clear_cell_ctrl.
void safe_lv_table_clear_cell_ctrl(lv_obj_t * obj, uint16_t row, uint16_t col, lv_table_cell_ctrl_t ctrl);

//The original function is: lv_table_get_cell_value.
const char * safe_lv_table_get_cell_value(lv_obj_t * obj, uint16_t row, uint16_t col);

//The original function is: lv_table_get_row_cnt.
uint16_t safe_lv_table_get_row_cnt(lv_obj_t * obj);

//The original function is: lv_table_get_col_cnt.
uint16_t safe_lv_table_get_col_cnt(lv_obj_t * obj);

//The original function is: lv_table_get_col_width.
lv_coord_t safe_lv_table_get_col_width(lv_obj_t * obj, uint16_t col);

//The original function is: lv_table_has_cell_ctrl.
bool safe_lv_table_has_cell_ctrl(lv_obj_t * obj, uint16_t row, uint16_t col, lv_table_cell_ctrl_t ctrl);

//The original function is: lv_table_get_selected_cell.
void safe_lv_table_get_selected_cell(lv_obj_t * obj, uint16_t * row, uint16_t * col);

