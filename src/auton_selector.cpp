#include "liblvgl/core/lv_disp.h"
#include "liblvgl/core/lv_event.h"
#include "liblvgl/core/lv_obj.h"
#include "liblvgl/core/lv_obj_pos.h"
#include "liblvgl/core/lv_obj_style.h"
#include "liblvgl/draw/lv_draw_rect.h"
#include "liblvgl/extra/widgets/tabview/lv_tabview.h"
#include "liblvgl/lv_conf_internal.h"
#include "liblvgl/misc/lv_area.h"
#include "liblvgl/misc/lv_color.h"
#include "liblvgl/widgets/lv_dropdown.h"
#include "liblvgl/widgets/lv_label.h"
#include "subsystemsHeaders/drive.hpp"
#include "auton_selector.hpp"

int autonSelection = 0;


static void autonSelect (lv_event_t * e) {
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);
    lv_obj_t * auton = lv_label_create(lv_scr_act());
    lv_label_set_text(auton, "Selected: ");
    lv_obj_align(auton, LV_ALIGN_BOTTOM_LEFT, 110 , -10);

    if (code == LV_EVENT_VALUE_CHANGED) {
        char selected[6];
        lv_dropdown_get_selected_str(obj, selected, sizeof(selected));
        lv_label_set_text_fmt(auton, "Selected: %s", selected);
    }
}

void selector() {
    //creates tabview and colors the background orange
    lv_obj_t * tabview;
    tabview = lv_tabview_create(lv_scr_act(), LV_DIR_LEFT, 100);
    lv_obj_set_style_bg_color(tabview, lv_palette_darken(LV_PALETTE_DEEP_ORANGE, 2), 0);

    //creates tab buttons and colors them
    lv_obj_t * tab_btns = lv_tabview_get_tab_btns(tabview);
    lv_obj_set_style_bg_color(tab_btns, lv_color_black(), 0);
    lv_obj_set_style_text_color(tab_btns, lv_color_white(), 0);
    lv_obj_set_style_text_letter_space(tab_btns, 2, 0);

    //creates the actual tabs
    lv_obj_t * redTab = lv_tabview_add_tab(tabview, "Red");
    lv_obj_t * blueTab = lv_tabview_add_tab(tabview, "Blue");
    lv_obj_t * skillsTab = lv_tabview_add_tab(tabview, "Skills");

    //red view///////////////////////////////////
    lv_obj_t * labelRed = lv_label_create(redTab);
    lv_obj_t * tabviewRed;
    tabviewRed = lv_tabview_create(redTab, LV_DIR_TOP, 50);

    lv_obj_set_style_bg_color(tabviewRed, lv_palette_darken(LV_PALETTE_DEEP_ORANGE, 2), 0);
    
    lv_obj_t * red_tab_btns = lv_tabview_get_tab_btns(tabviewRed);
    lv_obj_set_style_text_letter_space(red_tab_btns, 2, 0);
    lv_obj_set_style_bg_color(red_tab_btns, lv_color_black(), 0);

    lv_obj_t * qualTabRed = lv_tabview_add_tab(tabviewRed, "Qual");
    lv_obj_t * elimTabRed = lv_tabview_add_tab(tabviewRed, "Elim");

    lv_obj_t * qualRedDropDown = lv_dropdown_create(qualTabRed);
    lv_dropdown_set_options(qualRedDropDown, "None\n" "Left\n" "Right\n" "Solo");
    lv_obj_align(qualRedDropDown, LV_ALIGN_TOP_LEFT, 5, 0);
    lv_dropdown_set_dir(qualRedDropDown, LV_DIR_RIGHT);
    lv_dropdown_set_symbol(qualRedDropDown, LV_SYMBOL_RIGHT);
    lv_obj_set_style_bg_color(qualRedDropDown, lv_color_black(), 0);

    lv_obj_t * elimRedDropDown = lv_dropdown_create(elimTabRed);
    lv_dropdown_set_options(elimRedDropDown, "None\n" "Left\n" "Right");
    lv_obj_align(elimRedDropDown, LV_ALIGN_TOP_RIGHT, -5, 0);
    lv_dropdown_set_dir(elimRedDropDown, LV_DIR_LEFT);
    lv_dropdown_set_symbol(elimRedDropDown, LV_SYMBOL_LEFT);
    lv_obj_set_style_bg_color(elimRedDropDown, lv_color_black(), 0);

    //blue view/////////////////////////////////////
    lv_obj_t * labelBlue = lv_label_create(blueTab);
    lv_obj_t * tabviewBlue;
    tabviewBlue = lv_tabview_create(blueTab, LV_DIR_TOP, 50);

    lv_obj_set_style_bg_color(tabviewBlue, lv_palette_darken(LV_PALETTE_DEEP_ORANGE, 2), 0);
    
    lv_obj_t * blue_tab_btns = lv_tabview_get_tab_btns(tabviewBlue);
    lv_obj_set_style_text_letter_space(blue_tab_btns, 2, 0);
    lv_obj_set_style_bg_color(blue_tab_btns, lv_color_black(), 0);

    lv_obj_t * qualTabBlue = lv_tabview_add_tab(tabviewBlue, "Qual");
    lv_obj_t * elimTabBlue = lv_tabview_add_tab(tabviewBlue, "Elim");

    lv_obj_t * qualBlueDropDown = lv_dropdown_create(qualTabBlue);
    lv_dropdown_set_options(qualBlueDropDown, "None\n" "Left\n" "Right\n" "Solo");
    lv_obj_align(qualBlueDropDown, LV_ALIGN_TOP_LEFT, 5, 0);
    lv_dropdown_set_dir(qualBlueDropDown, LV_DIR_RIGHT);
    lv_dropdown_set_symbol(qualBlueDropDown, LV_SYMBOL_RIGHT);
    lv_obj_set_style_bg_color(qualBlueDropDown, lv_color_black(), 0);

    lv_obj_t * elimBlueDropDown = lv_dropdown_create(elimTabBlue);
    lv_dropdown_set_options(elimBlueDropDown, "None\n" "Left\n" "Right");
    lv_obj_align(elimBlueDropDown, LV_ALIGN_TOP_RIGHT, -5, 0);
    lv_dropdown_set_dir(elimBlueDropDown, LV_DIR_LEFT);
    lv_dropdown_set_symbol(elimBlueDropDown, LV_SYMBOL_LEFT);
    lv_obj_set_style_bg_color(elimBlueDropDown, lv_color_black(), 0);

    //Skills view/////////////////////////////////////////
    lv_obj_t * skillsBtn = lv_btn_create(skillsTab);
    lv_obj_t * skillsLabel = lv_label_create(skillsBtn);

    lv_obj_set_size(skillsBtn, 205, 205);
    lv_obj_center(skillsBtn);
    lv_obj_set_style_bg_color(skillsBtn, lv_color_black(), 0);
    lv_obj_set_style_radius(skillsBtn, LV_RADIUS_CIRCLE, 0);
    lv_label_set_text(skillsLabel, "EZPZ");
    lv_obj_set_style_text_font(skillsLabel, LV_THEME_DEFAULT_FONT_TITLE, 0);
    lv_obj_align(skillsBtn, LV_ALIGN_CENTER, 0, -10);
    lv_obj_center(skillsLabel);

    lv_obj_add_event_cb(qualRedDropDown, autonSelect, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(elimRedDropDown, autonSelect, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(qualBlueDropDown, autonSelect, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(elimBlueDropDown, autonSelect, LV_EVENT_ALL, NULL);

    //adds the coordinates and heading
    lv_obj_t * coordinates = lv_label_create(lv_scr_act());
    lv_label_set_text_fmt(coordinates, "Coords: (%g, %g)", chassis.getPose().x, chassis.getPose().y);
    lv_obj_align(coordinates, LV_ALIGN_BOTTOM_MID, 50, -10);
    lv_obj_t * heading = lv_label_create(lv_scr_act());
    lv_label_set_text_fmt(heading, "Heading: %g", chassis.getPose().theta);
    lv_obj_align(heading, LV_ALIGN_BOTTOM_RIGHT, -20 , -10);
}