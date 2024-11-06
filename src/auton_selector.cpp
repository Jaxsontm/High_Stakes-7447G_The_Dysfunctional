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
#include "liblvgl/widgets/lv_btn.h"
#include "liblvgl/widgets/lv_label.h"
#include "subsystemsHeaders/drive.hpp"
#include "auton_selector.hpp"
#include "auton.h"

int autonSelection = 0;

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

    lv_obj_t * redright = lv_btn_create(qualTabRed);
    lv_obj_t * redrightLabel = lv_label_create(redright);
    lv_label_set_text(redrightLabel, "RED QUAL RIGHT");
    lv_obj_center(redrightLabel);
    lv_obj_set_style_text_letter_space(redright, 2, 0);
    lv_obj_set_style_bg_color(redright, lv_color_black(), 0);
    lv_obj_align(redright, LV_ALIGN_TOP_MID, 0, 0);

    lv_obj_t * redleft = lv_btn_create(qualTabRed);
    lv_obj_t * redleftLabel = lv_label_create(redleft);
    lv_label_set_text(redleftLabel, "RED QUAL LEFT");
    lv_obj_center(redleftLabel);
    lv_obj_set_style_text_letter_space(redleft, 2, 0);
    lv_obj_set_style_bg_color(redleft, lv_color_black(), 0);
    lv_obj_align(redleft, LV_ALIGN_CENTER, 0, 0);

    lv_obj_t * redsolo = lv_btn_create(qualTabRed);
    lv_obj_t * redsoloLabel = lv_label_create(redsolo);
    lv_label_set_text(redsoloLabel, "RED QUAL SOLO");
    lv_obj_center(redsoloLabel);
    lv_obj_set_style_text_letter_space(redsolo, 2, 0);
    lv_obj_set_style_bg_color(redsolo, lv_color_black(), 0);
    lv_obj_align(redsolo, LV_ALIGN_BOTTOM_MID, 0, 0);

    lv_obj_t * redrightElim = lv_btn_create(elimTabRed);
    lv_obj_t * redrightElimLabel = lv_label_create(redrightElim);
    lv_label_set_text(redrightElimLabel, "RED ELIM RIGHT");
    lv_obj_center(redrightElimLabel);
    lv_obj_set_style_text_letter_space(redrightElim, 2, 0);
    lv_obj_set_style_bg_color(redrightElim, lv_color_black(), 0);
    lv_obj_align(redrightElim, LV_ALIGN_TOP_MID, 0, 0);

    lv_obj_t * redleftElim = lv_btn_create(elimTabRed);
    lv_obj_t * redleftElimLabel = lv_label_create(redleftElim);
    lv_label_set_text(redleftElimLabel, "RED ELIM LEFT");
    lv_obj_center(redleftElimLabel);
    lv_obj_set_style_text_letter_space(redleftElim, 2, 0);
    lv_obj_set_style_bg_color(redleftElim, lv_color_black(), 0);
    lv_obj_align(redleftElim, LV_ALIGN_CENTER, 0, 0);

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

    lv_obj_t * blueright = lv_btn_create(qualTabBlue);
    lv_obj_t * bluerightLabel = lv_label_create(blueright);
    lv_label_set_text(bluerightLabel, "BLUE QUAL RIGHT");
    lv_obj_center(bluerightLabel);
    lv_obj_set_style_text_letter_space(blueright, 2, 0);
    lv_obj_set_style_bg_color(blueright, lv_color_black(), 0);
    lv_obj_align(blueright, LV_ALIGN_TOP_MID, 0, 0);

    lv_obj_t * blueleft = lv_btn_create(qualTabBlue);
    lv_obj_t * blueleftLabel = lv_label_create(blueleft);
    lv_label_set_text(blueleftLabel, "BLUE QUAL LEFT");
    lv_obj_center(blueleftLabel);
    lv_obj_set_style_text_letter_space(blueleft, 2, 0);
    lv_obj_set_style_bg_color(blueleft, lv_color_black(), 0);
    lv_obj_align(blueleft, LV_ALIGN_CENTER, 0, 0);

    lv_obj_t * bluesolo = lv_btn_create(qualTabBlue);
    lv_obj_t * bluesoloLabel = lv_label_create(bluesolo);
    lv_label_set_text(bluesoloLabel, "BLUE QUAL SOLO");
    lv_obj_center(bluesoloLabel);
    lv_obj_set_style_text_letter_space(bluesolo, 2, 0);
    lv_obj_set_style_bg_color(bluesolo, lv_color_black(), 0);
    lv_obj_align(bluesolo, LV_ALIGN_BOTTOM_MID, 0, 0);

    lv_obj_t * bluerightElim = lv_btn_create(elimTabBlue);
    lv_obj_t * bluerightElimLabel = lv_label_create(bluerightElim);
    lv_label_set_text(bluerightElimLabel, "BLUE ELIM RIGHT");
    lv_obj_center(bluerightElimLabel);
    lv_obj_set_style_text_letter_space(bluerightElim, 2, 0);
    lv_obj_set_style_bg_color(bluerightElim, lv_color_black(), 0);
    lv_obj_align(bluerightElim, LV_ALIGN_TOP_MID, 0, 0);

    lv_obj_t * blueleftElim = lv_btn_create(elimTabBlue);
    lv_obj_t * blueleftElimLabel = lv_label_create(blueleftElim);
    lv_label_set_text(blueleftElimLabel, "BLUE ELIM LEFT");
    lv_obj_center(blueleftElimLabel);
    lv_obj_set_style_text_letter_space(blueleftElim, 2, 0);
    lv_obj_set_style_bg_color(blueleftElim, lv_color_black(), 0);
    lv_obj_align(blueleftElim, LV_ALIGN_CENTER, 0, 0);

    //Skills view/////////////////////////////////////////
    lv_obj_t * skills = lv_btn_create(skillsTab);
    lv_obj_t * skillsLabel = lv_label_create(skills);

    lv_obj_set_size(skills, 205, 205);
    lv_obj_center(skills);
    lv_obj_set_style_bg_color(skills, lv_color_black(), 0);
    lv_obj_set_style_radius(skills, LV_RADIUS_CIRCLE, 0);
    lv_label_set_text(skillsLabel, "EZPZ");
    lv_obj_set_style_text_font(skillsLabel, LV_THEME_DEFAULT_FONT_TITLE, 0);
    lv_obj_align(skills, LV_ALIGN_CENTER, 0, -10);
    lv_obj_center(skillsLabel);

    //adds the coordinates and heading
    lv_obj_t * coordinates = lv_label_create(lv_scr_act());
    lv_label_set_text_fmt(coordinates, "Coords: (%g, %g)", chassis.getPose().x, chassis.getPose().y);
    lv_obj_align(coordinates, LV_ALIGN_BOTTOM_MID, 50, -10);
    lv_obj_t * heading = lv_label_create(lv_scr_act());
    lv_label_set_text_fmt(heading, "Heading: %g", chassis.getPose().theta);
    lv_obj_align(heading, LV_ALIGN_BOTTOM_RIGHT, -20 , -10);    
}

autons selected_auton;

static void selection(lv_event_t * e) {
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);
    if (code == LV_EVENT_CLICKED) {
        if (redright) {
            selected_auton = redright;
        }
    }
}

autons current_auton = None;

void request_auton(autons selected_auton) {
    autons current_auton = None;
    if (selected_auton != current_auton) {
            lv_obj_t * auton = lv_label_create(lv_scr_act());

            char file[32];
            lv_label_set_text_fmt(auton, "Auton: %u", selected_auton);
    }
}

void run_auton() {
    while (true) {
        switch (current_auton) {
            case redright:
                if (selected_auton == redright) {
                    redRight();
                } else {
                    current_auton = redleft;
                }
                break;
            case redleft:
                if (selected_auton == redleft) {
                    redLeft();
                } else {
                    current_auton = redsolo;
                }
                break;
            case redsolo:
                if (selected_auton == redsolo) {
                    redSolo();
                } else {
                    current_auton = redrightElim;
                }
                break;
            case redrightElim:
                if (selected_auton == redrightElim) {
                    redRightElim();
                } else {
                    current_auton = redleftElim;
                }
                break;
            case redleftElim:
                if (selected_auton == redleftElim) {
                    redLeftElim();
                } else {
                    current_auton = blueright;
                }
                break;
            case blueright:
                if (selected_auton == blueright) {
                    blueRight();
                } else {
                    current_auton = blueleft;
                }
                break;
            case blueleft:
                if (selected_auton == blueleft) {
                    blueLeft();
                } else {
                    current_auton = bluesolo;
                }
                break;
            case bluesolo:
                if (selected_auton == bluesolo) {
                    blueSolo();
                } else {
                    current_auton = bluerightElim;
                }
                break;
            case bluerightElim:
                if (selected_auton == bluerightElim) {
                    blueRightElim();
                } else {
                    current_auton = blueleftElim;
                }
                break;
            case blueleftElim:
                if (selected_auton == blueleftElim) {
                    blueLeftElim();
                } else {
                    current_auton = skills;
                }
                break;
            case skills:
                if (selected_auton == skills) {
                    Skills();
                } else {
                    current_auton = None;
                }
                break;
            case None:
                if (selected_auton == None) {
                    none();
                } else {
                    break;
                }
                break;
        }
    }
}