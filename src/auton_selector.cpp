#include "liblvgl/core/lv_disp.h"
#include "liblvgl/core/lv_obj_style.h"
#include "liblvgl/extra/widgets/tabview/lv_tabview.h"
#include "liblvgl/lvgl.h"
#include "liblvgl/misc/lv_area.h"
#include "liblvgl/misc/lv_color.h"

void tabs() {
    //creates tabview object and styles it
    lv_obj_t * tabview;
    tabview = lv_tabview_create(lv_scr_act(), LV_DIR_LEFT, 30);

    lv_obj_set_style_bg_color(tabview, lv_palette_lighten(LV_PALETTE_DEEP_ORANGE, 2), 0);

    lv_obj_t * tab_btns = lv_tabview_get_tab_btns(tabview);
    lv_obj_set_style_bg_color(tab_btns, lv_palette_darken(LV_PALETTE_GREY, 8), 0);
    lv_obj_set_style_text_color(tab_btns, lv_palette_lighten(LV_PALETTE_GREY, 8), 0);

    lv_obj_t * redTab = lv_tabview_add_tab(tabview, "Red");
    lv_obj_t * blueTab = lv_tabview_add_tab(tabview, "Blue");
    lv_obj_t * skillsTab = lv_tabview_add_tab(tabview, "Skills");
}