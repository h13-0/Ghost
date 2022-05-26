Currently supported lvgl version is 8.2.0.
# Known issues.
Some complex function declarations cannot be converted temporarily, such as:
`lv_label_set_text_fmt(lv_obj_t * obj, const char * fmt, ...) LV_FORMAT_ATTRIBUTE(2, 3);`

and the functions related to platform dependency cannot be converted temporarily, such as:
`nxp` `dma2d`.