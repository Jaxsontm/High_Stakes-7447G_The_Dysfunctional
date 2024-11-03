#include "liblvgl/core/lv_disp.h"
#include "liblvgl/core/lv_obj.h"
#include "liblvgl/misc/lv_style.h"

bool toggled = false;

lv_style_t(style);
lv_style_set_bg_color(style, lv_color_black());
lv_style_set_border_width(style, 2);
lv_style_set_border_color(style, lv_color_white());

lv_obj_t * btn = lv_obj_create(lv_scr_act());
lv_obj_add_event_cb(btn, event_handler, LV_EVENT_ALL, NULL);
lv_obj_align(btn, LV_ALIGN_TOP_LEFT, x, y);
lv_obj_set_size(btn, width, height);
lv_obj_add_style(btn, style, 0);

lv_obj_t * label = lv_obj_create(btn);
lv_label_set_text(label, button_text.c_str());
lv_obj_center(label);