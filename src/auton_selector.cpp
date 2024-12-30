#include "auton_selector.hpp"


int autonSelection = 0;

lv_obj_t *obj;
lv_obj_t *tabview;
lv_obj_t *cover;
lv_obj_t *tab_btns;
lv_obj_t *statsTab;
lv_obj_t *labelRed;
lv_obj_t *labelBlue;
lv_obj_t *labelSkills;
lv_obj_t *labelChange;


lv_obj_t *auton = lv_label_create(lv_scr_act());

lv_obj_t *tabviewRed;
lv_obj_t *qualTabRed = lv_tabview_add_tab(tabviewRed, "Qual");
lv_obj_t *elimTabRed = lv_tabview_add_tab(tabviewRed, "Elim");
lv_obj_t *rqgoal = lv_btn_create(qualTabRed);
lv_obj_t *rqring = lv_btn_create(qualTabRed);
lv_obj_t *rsolo = lv_btn_create(qualTabRed);
lv_obj_t *regoal = lv_btn_create(elimTabRed);
lv_obj_t *rering = lv_btn_create(elimTabRed);

lv_obj_t *tabviewBlue;
lv_obj_t *qualTabBlue = lv_tabview_add_tab(tabviewBlue, "Qual");
lv_obj_t *elimTabBlue = lv_tabview_add_tab(tabviewBlue, "Elim");
lv_obj_t *bqgoal = lv_btn_create(qualTabBlue);
lv_obj_t *bqring = lv_btn_create(qualTabBlue);
lv_obj_t *bsolo = lv_btn_create(qualTabBlue);
lv_obj_t *begoal = lv_btn_create(elimTabBlue);
lv_obj_t *bering = lv_btn_create(elimTabBlue);

static void selection(lv_event_t * e) {
  lv_obj_t *btn = lv_event_get_target(e);

  if (btn == rqgoal) lv_label_set_text(auton, "Red Qual Goal");
  else if (btn == rqring) lv_label_set_text(auton, "Red Qual Ring");
  else if (btn == rsolo) lv_label_set_text(auton, "Red Qual Solo");
  else if (btn == regoal) lv_label_set_text(auton, "Red Elim Goal");
  else if (btn == rering) lv_label_set_text(auton, "Red Elim Ring");
  else if (btn == bqgoal) lv_label_set_text(auton, "Blue Qual Goal");
  else if (btn == bqring) lv_label_set_text(auton, "Blue Qual Ring");
  else if (btn == bsolo) lv_label_set_text(auton, "Blue Qual Solo");
  else if (btn == begoal) lv_label_set_text(auton, "Blue Elim Goal");
  else if (btn == bering) lv_label_set_text(auton, "Blue Elim Ring");
  else lv_label_set_text(auton, "50 PLEASE");
}

lv_event_cb_t Selection = selection;

static void hide_change_button(lv_event_t *e) {
	lv_event_code_t code = lv_event_get_code(e);
	if (code == LV_EVENT_VALUE_CHANGED) {
		int selectedTab = lv_tabview_get_tab_act(tabview);

		if (selectedTab == 3) {
			lv_obj_clear_flag(cover, LV_OBJ_FLAG_HIDDEN);
		} else {
			lv_obj_add_flag(cover, LV_OBJ_FLAG_HIDDEN);
		}
	}
}
static void coords(lv_event_t *e) {
	lv_event_code_t code = lv_event_get_code(e);
	obj = lv_event_get_target(e);
	lv_obj_t *placement_label = lv_label_create(lv_scr_act());
	lv_obj_align(placement_label, LV_ALIGN_BOTTOM_RIGHT, -20, -10);
	char posText[150];

  if (code == LV_EVENT_CLICKED) {
    lemlib::Pose trackerPos = chassis.getPose();
		sprintf(posText, "(x: %.2f, y: %.2f, theta: %.2f)", trackerPos.x, trackerPos.y, trackerPos.theta);
		lv_label_set_text(placement_label, posText);
  }
}

void selector() {
  lv_obj_align(auton, LV_ALIGN_BOTTOM_LEFT, 110, -10);
	// creates tabview and colors the background orange
	tabview = lv_tabview_create(lv_scr_act(), LV_DIR_LEFT, 100);
	lv_obj_set_style_bg_color(tabview,
														lv_palette_darken(LV_PALETTE_DEEP_ORANGE, 2), 0);

	// creates the theme for the tabview
	tab_btns = lv_tabview_get_tab_btns(tabview);
	lv_obj_set_style_bg_color(tab_btns, lv_color_black(), 0);
	lv_obj_set_style_text_color(tab_btns, lv_color_white(), 0);
	lv_obj_set_style_text_letter_space(tab_btns, 2, 0);

	// creates the main tabs
	lv_obj_t *redTab = lv_tabview_add_tab(tabview, "Red");
	lv_obj_t *blueTab = lv_tabview_add_tab(tabview, "Blue");
	lv_obj_t *skillsTab = lv_tabview_add_tab(tabview, "Skills");
	statsTab = lv_tabview_add_tab(tabview, "Stats");
	lv_obj_add_event_cb(tabview, hide_change_button, LV_EVENT_VALUE_CHANGED, nullptr);

	// red view///////////////////////////////////
	labelRed = lv_label_create(redTab);
	
	tabviewRed = lv_tabview_create(redTab, LV_DIR_TOP, 50);

	lv_obj_set_style_bg_color(tabviewRed,
														lv_palette_darken(LV_PALETTE_DEEP_ORANGE, 2), 0);

	lv_obj_t *red_tab_btns = lv_tabview_get_tab_btns(tabviewRed);
	lv_obj_set_style_text_letter_space(red_tab_btns, 2, 0);
	lv_obj_set_style_bg_color(red_tab_btns, lv_color_black(), 0);

	labelRed = lv_label_create(rqgoal); //creates the button's label
	lv_label_set_text(labelRed, "GOAL"); //sets the button's text
	lv_obj_center(labelRed); //centers the button's text
	lv_obj_set_style_text_letter_space(rqgoal, 2, 0);
	lv_obj_set_style_bg_color(rqgoal, lv_color_black(), 0); //sets bg color
	lv_obj_align(rqgoal, LV_ALIGN_TOP_MID, 0, 0); //aligns the button in the screen
	lv_obj_add_event_cb(rqgoal,  //sets the callback for the button
									selection, LV_EVENT_CLICKED, nullptr);

	labelRed = lv_label_create(rqring);
	lv_label_set_text(labelRed, "4 RING");
	lv_obj_center(labelRed);
	lv_obj_set_style_text_letter_space(rqring, 2, 0);
	lv_obj_set_style_bg_color(rqring, lv_color_black(), 0);
	lv_obj_align(rqring, LV_ALIGN_CENTER, 0, 0);
	lv_obj_add_event_cb(rqring, selection, LV_EVENT_CLICKED, nullptr);

	labelRed = lv_label_create(rsolo);
	lv_label_set_text(labelRed, "SOLO :SOB:");
	lv_obj_center(labelRed);
	lv_obj_set_style_text_letter_space(rsolo, 2, 0);
	lv_obj_set_style_bg_color(rsolo, lv_color_black(), 0);
	lv_obj_align(rsolo, LV_ALIGN_BOTTOM_MID, 0, 0);
	lv_obj_add_event_cb(rsolo, selection, LV_EVENT_CLICKED, nullptr);

	labelRed = lv_label_create(regoal);
	lv_label_set_text(labelRed, "SPEEED GOALRUSHIE");
	lv_obj_center(labelRed);
	lv_obj_set_style_text_letter_space(regoal, 2, 0);
	lv_obj_set_style_bg_color(regoal, lv_color_black(), 0);
	lv_obj_align(regoal, LV_ALIGN_TOP_MID, 0, 0);
	lv_obj_add_event_cb(regoal, selection, LV_EVENT_CLICKED, nullptr);

	labelRed = lv_label_create(rering);
	lv_label_set_text(labelRed, "6 RING");
	lv_obj_center(labelRed);
	lv_obj_set_style_text_letter_space(rering, 2, 0);
	lv_obj_set_style_bg_color(rering, lv_color_black(), 0);
	lv_obj_align(rering, LV_ALIGN_CENTER, 0, 0);
	lv_obj_add_event_cb(rering, selection, LV_EVENT_CLICKED, nullptr);

	// blue view/////////////////////////////////////
	labelBlue = lv_label_create(blueTab);
	tabviewBlue = lv_tabview_create(blueTab, LV_DIR_TOP, 50);

	lv_obj_set_style_bg_color(tabviewBlue,
														lv_palette_darken(LV_PALETTE_DEEP_ORANGE, 2), 0);

	lv_obj_t *Blue_tab_btns = lv_tabview_get_tab_btns(tabviewBlue);
	lv_obj_set_style_text_letter_space(Blue_tab_btns, 2, 0);
	lv_obj_set_style_bg_color(Blue_tab_btns, lv_color_black(), 0);

	labelBlue = lv_label_create(bqring);
	lv_label_set_text(labelBlue, "4 RING");
	lv_obj_center(labelBlue);
	lv_obj_set_style_text_letter_space(bqring, 2, 0);
	lv_obj_set_style_bg_color(bqring, lv_color_black(), 0);
	lv_obj_align(bqring, LV_ALIGN_TOP_MID, 0, 0);
	lv_obj_add_event_cb(bqring, selection, LV_EVENT_CLICKED, nullptr);

	labelBlue = lv_label_create(bqgoal);
	lv_label_set_text(labelBlue, "GOAL");
	lv_obj_center(labelBlue);
	lv_obj_set_style_text_letter_space(bqgoal, 2, 0);
	lv_obj_set_style_bg_color(bqgoal, lv_color_black(), 0);
	lv_obj_align(bqgoal, LV_ALIGN_CENTER, 0, 0);
	lv_obj_add_event_cb(bqgoal, selection, LV_EVENT_CLICKED, nullptr);

	labelBlue = lv_label_create(bsolo);
	lv_label_set_text(labelBlue, "SOLO :SOB:");
	lv_obj_center(labelBlue);
	lv_obj_set_style_text_letter_space(bsolo, 2, 0);
	lv_obj_set_style_bg_color(bsolo, lv_color_black(), 0);
	lv_obj_align(bsolo, LV_ALIGN_BOTTOM_MID, 0, 0);
	lv_obj_add_event_cb(bsolo, selection, LV_EVENT_CLICKED, nullptr);

	labelBlue = lv_label_create(bering);
	lv_label_set_text(labelBlue, "6 RING");
	lv_obj_center(labelBlue);
	lv_obj_set_style_text_letter_space(bering, 2, 0);
	lv_obj_set_style_bg_color(bering, lv_color_black(), 0);
	lv_obj_align(bering, LV_ALIGN_TOP_MID, 0, 0);
	lv_obj_add_event_cb(bering, selection, LV_EVENT_CLICKED,
											nullptr);

	labelBlue = lv_label_create(begoal);
	lv_label_set_text(labelBlue, "SPEEED GOALRUSHIE");
	lv_obj_center(labelBlue);
	lv_obj_set_style_text_letter_space(begoal, 2, 0);
	lv_obj_set_style_bg_color(begoal, lv_color_black(), 0);
	lv_obj_align(begoal, LV_ALIGN_CENTER, 0, 0);
	lv_obj_add_event_cb(begoal, selection, LV_EVENT_CLICKED, nullptr);

	// Skills view/////////////////////////////////////////
	lv_obj_t *skills = lv_btn_create(skillsTab);
	labelSkills = lv_label_create(skills);

	lv_obj_set_size(skills, 205, 205);
	lv_obj_center(skills);
	lv_obj_set_style_bg_color(skills, lv_color_black(), 0);
	lv_obj_set_style_radius(skills, LV_RADIUS_CIRCLE, 0);
	lv_label_set_text(labelSkills, "EZPZ");
	lv_obj_set_style_text_font(labelSkills, LV_THEME_DEFAULT_FONT_TITLE, 0);
	lv_obj_align(skills, LV_ALIGN_CENTER, 0, -10);
	lv_obj_add_event_cb(skills, selection, LV_EVENT_CLICKED, nullptr);
  lv_obj_center(labelSkills);

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	lv_obj_t *Coords = lv_btn_create(lv_scr_act());
	lv_obj_t *coordLabel = lv_label_create(Coords);
	lv_label_set_text(coordLabel, "COORDS");
	lv_obj_center(coordLabel);
	lv_obj_set_style_text_letter_space(Coords, 2, 0);
	lv_obj_set_style_text_font(coordLabel, LV_THEME_DEFAULT_FONT_SMALL, 0);
	lv_obj_set_style_bg_color(Coords, lv_color_black(), 0);
	lv_obj_align(Coords, LV_ALIGN_BOTTOM_RIGHT, -10, -35);
	lv_obj_add_event_cb(Coords, coords, LV_EVENT_CLICKED, nullptr);

	lv_obj_t *stats_label = lv_label_create(statsTab);
	lv_obj_set_style_bg_color(stats_label,
														lv_palette_darken(LV_PALETTE_DEEP_ORANGE, 2), 0);
	lv_obj_align(stats_label, LV_ALIGN_CENTER, 0, -20);

	cover = lv_obj_create(lv_scr_act());
	lv_obj_set_size(cover, 110, 40);
	lv_obj_align(cover, LV_ALIGN_LEFT_MID, 100, 30);
	lv_obj_set_style_bg_color(cover, lv_palette_darken(LV_PALETTE_DEEP_ORANGE, 2), 0);
	lv_obj_set_style_border_color(cover, lv_palette_darken(LV_PALETTE_DEEP_ORANGE, 2), 0);
	lv_obj_add_flag(cover, LV_OBJ_FLAG_HIDDEN);


	char statText[150];

	while (true) {
		lv_label_set_text(stats_label, " ");
		// stats tab
		sprintf(statText,
						"Switch: %i | Basket Pos: %.2f | Basket Temp: %.0f\n        DT "
						"Left Temp: %.0f | DT Right Temp: %.0f\n                           "
						"Intake Temp: %.0f",
						basketLimit.get_value(), basket.get_position(),
						basket.get_temperature(), DTLeft.get_temperature(),
						DTRight.get_temperature(), Intake.get_temperature());

		lv_label_set_text(stats_label, statText);

		pros::delay(500);
	} //while loop
} //void selector