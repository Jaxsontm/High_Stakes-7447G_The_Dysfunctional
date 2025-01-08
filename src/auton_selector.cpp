#include "auton_selector.hpp"
#include "liblvgl/misc/lv_area.h"
#include "liblvgl/widgets/lv_label.h"

bool coord = true;
int autonSelection = 6;
int testSelection = -1;
char testName[10];

lv_obj_t *tabview = lv_tabview_create(lv_scr_act(), LV_DIR_LEFT, 100);
lv_obj_t *tab_btns = lv_tabview_get_tab_btns(tabview);
lv_obj_t *redTab = lv_tabview_add_tab(tabview, "Red");
lv_obj_t *blueTab = lv_tabview_add_tab(tabview, "Blue");
lv_obj_t *AWPTab = lv_tabview_add_tab(tabview, "AWP");
lv_obj_t *skillsTab = lv_tabview_add_tab(tabview, "Skills");
lv_obj_t *testTab = lv_tabview_add_tab(tabview, "Tests");
lv_obj_t *statsTab = lv_tabview_add_tab(tabview, "Stats");
lv_obj_t *labelRed;
lv_obj_t *labelBlue;
lv_obj_t *labelAWP;
lv_obj_t *labelSkills;
lv_obj_t *labelTest;
lv_obj_t *placement_label = lv_label_create(lv_scr_act());
lv_obj_t *stats_label = lv_label_create(statsTab);
lv_obj_t *testRoller = lv_roller_create(testTab);
lv_obj_t *testStart = lv_btn_create(testTab);
lv_obj_t *startLabel = lv_label_create(testStart);

lv_obj_t *auton = lv_label_create(lv_scr_act());

lv_obj_t *tabviewRed = lv_tabview_create(redTab, LV_DIR_TOP, 50);
lv_obj_t *qualTabRed = lv_tabview_add_tab(tabviewRed, "Qual");
lv_obj_t *elimTabRed = lv_tabview_add_tab(tabviewRed, "Elim");
lv_obj_t *rqgoal = lv_btn_create(qualTabRed);
lv_obj_t *rqring = lv_btn_create(qualTabRed);
lv_obj_t *rsolo = lv_btn_create(qualTabRed);
lv_obj_t *regoal = lv_btn_create(elimTabRed);
lv_obj_t *rering = lv_btn_create(elimTabRed);

lv_obj_t *tabviewBlue = lv_tabview_create(blueTab, LV_DIR_TOP, 50);
lv_obj_t *qualTabBlue = lv_tabview_add_tab(tabviewBlue, "Qual");
lv_obj_t *elimTabBlue = lv_tabview_add_tab(tabviewBlue, "Elim");
lv_obj_t *bqgoal = lv_btn_create(qualTabBlue);
lv_obj_t *bqring = lv_btn_create(qualTabBlue);
lv_obj_t *bsolo = lv_btn_create(qualTabBlue);
lv_obj_t *begoal = lv_btn_create(elimTabBlue);
lv_obj_t *bering = lv_btn_create(elimTabBlue);

lv_obj_t *tabviewAWP = lv_tabview_create(AWPTab, LV_DIR_TOP, 50);
lv_obj_t *qualTabAWP = lv_tabview_add_tab(tabviewAWP, "AWP");
lv_obj_t *rgoalAWP = lv_btn_create(qualTabAWP);
lv_obj_t *rringAWP = lv_btn_create(qualTabAWP);
lv_obj_t *bgoalAWP = lv_btn_create(qualTabAWP);
lv_obj_t *bringAWP = lv_btn_create(qualTabAWP);

static void coords(lv_event_t *e) {
  lv_event_code_t code = lv_event_get_code(e);
  lemlib::Pose trackerPos = chassis.getPose();

  if (code == LV_EVENT_CLICKED) {
    if (coord) {
      lv_label_set_text_fmt(placement_label, "(x: %.2f, y: %.2f, theta: %.2f)",
                            trackerPos.x, trackerPos.y, trackerPos.theta);
      coord = !coord;
    } else {
      lv_label_set_text(placement_label, "");
      coord = !coord;
    }
  }
}

static void selection(lv_event_t *e) {
  lv_obj_t *btn = lv_event_get_target(e);

  if (btn == rqgoal) {
    autonSelection = 0;
    lv_label_set_text(auton, "Red Qual Goal");
  } else if (btn == rqring) {
    autonSelection = 1;
    lv_label_set_text(auton, "Red Qual Ring");
  } else if (btn == rsolo) {
    autonSelection = 2;
    lv_label_set_text(auton, "Red Qual Solo");
  } else if (btn == regoal) {
    autonSelection = 3;
    lv_label_set_text(auton, "Red Elim Goal");
  } else if (btn == rering) {
    autonSelection = 4;
    lv_label_set_text(auton, "Red Elim Ring");
  } else if (btn == bqgoal) {
    autonSelection = 5;
    lv_label_set_text(auton, "Blue Qual Goal");
  } else if (btn == bqring) {
    autonSelection = 6;
    lv_label_set_text(auton, "Blue Qual Ring");
  } else if (btn == bsolo) {
    autonSelection = 7;
    lv_label_set_text(auton, "Blue Qual Solo");
  } else if (btn == begoal) {
    autonSelection = 8;
    lv_label_set_text(auton, "Blue Elim Goal");
  } else if (btn == bering) {
    autonSelection = 9;
    lv_label_set_text(auton, "Blue Elim Ring");
  } else if (btn == rgoalAWP) {
    autonSelection = 10;
    lv_label_set_text(auton, "EZ RGOAL AWP");
  } else if (btn == rringAWP) {
    autonSelection = 11;
    lv_label_set_text(auton, "EZ RRING AWP");
  } else if (btn == bringAWP) {
    autonSelection = 12;
    lv_label_set_text(auton, "EZ BRING AWP");
  } else if (btn == bgoalAWP) {
    autonSelection = 13;
    lv_label_set_text(auton, "EZ BGOAL AWP");
  } else {
    autonSelection = -1;
    lv_label_set_text(auton, "50 PLEASE");
  }
}

static void testSelect(lv_event_t *e) {
  int testSelected = lv_roller_get_selected(testRoller);
  switch (testSelected) {
  case 0:
    testSelection = 0;
    lv_label_set_text_fmt(startLabel, "%i", testSelection);
    break;
  case 1:
    testSelection = 1;
    lv_label_set_text_fmt(startLabel, "%i", testSelection);
    break;
  case 2:
    testSelection = 2;
    lv_label_set_text_fmt(startLabel, "%i", testSelection);
    break;
  case 3:
    testSelection = 3;
    lv_label_set_text_fmt(startLabel, "%i", testSelection);
    break;
  case 4:
    testSelection = 4;
    lv_label_set_text_fmt(startLabel, "%i", testSelection);
  case 5:
    testSelection = 5;
    lv_label_set_text_fmt(startLabel, "%i", testSelection);
    break;
  }
}

static void testStarter(lv_event_t *e) {
  void (*test)() = (void (*)())lv_event_get_user_data(e);
  // Call the external testtion
  if (test) {
    test();
  }
}

void selector() {
  lv_obj_align(auton, LV_ALIGN_BOTTOM_LEFT, 110, -10);
  lv_label_set_text(auton, "");

  lv_obj_align(placement_label, LV_ALIGN_BOTTOM_RIGHT, -20, -10);
  lv_label_set_text(placement_label, "");
  // creates tabview and colors the background orange
  lv_obj_set_style_bg_color(tabview,
                            lv_palette_darken(LV_PALETTE_DEEP_ORANGE, 2), 0);

  // creates the theme for the tabview

  lv_obj_set_style_bg_color(tab_btns, lv_color_black(), 0);
  lv_obj_set_style_text_color(tab_btns, lv_color_white(), 0);
  lv_obj_set_style_text_letter_space(tab_btns, 2, 0);

  // red view///////////////////////////////////
  lv_obj_set_style_bg_color(tabviewRed,
                            lv_palette_darken(LV_PALETTE_DEEP_ORANGE, 2), 0);

  lv_obj_t *red_tab_btns = lv_tabview_get_tab_btns(tabviewRed);
  lv_obj_set_style_text_letter_space(red_tab_btns, 2, 0);
  lv_obj_set_style_bg_color(red_tab_btns, lv_color_black(), 0);

  labelRed = lv_label_create(rqgoal);       // creates the button's label
  lv_label_set_text(labelRed, "SAFE RUSH"); // sets the button's text
  lv_obj_center(labelRed);                  // centers the button's text
  lv_obj_set_style_text_letter_space(rqgoal, 2, 0);
  lv_obj_set_style_bg_color(rqgoal, lv_color_black(), 0); // sets bg color
  lv_obj_align(rqgoal, LV_ALIGN_TOP_MID, 0,
               0);            // aligns the button in the screen
  lv_obj_add_event_cb(rqgoal, // sets the callback for the button
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
  lv_label_set_text(labelBlue, "SAFE RUSH");
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
  lv_obj_add_event_cb(bering, selection, LV_EVENT_CLICKED, nullptr);

  labelBlue = lv_label_create(begoal);
  lv_label_set_text(labelBlue, "SPEEED GOALRUSHIE");
  lv_obj_center(labelBlue);
  lv_obj_set_style_text_letter_space(begoal, 2, 0);
  lv_obj_set_style_bg_color(begoal, lv_color_black(), 0);
  lv_obj_align(begoal, LV_ALIGN_CENTER, 0, 0);
  lv_obj_add_event_cb(begoal, selection, LV_EVENT_CLICKED, nullptr);

  // AWP view/////////////////////////////////////
  lv_obj_set_style_bg_color(tabviewAWP,
                            lv_palette_darken(LV_PALETTE_DEEP_ORANGE, 2), 0);

  lv_obj_t *AWP_tab_btns = lv_tabview_get_tab_btns(tabviewAWP);
  lv_obj_set_style_text_letter_space(AWP_tab_btns, 2, 0);
  lv_obj_set_style_bg_color(AWP_tab_btns, lv_color_black(), 0);

  labelAWP = lv_label_create(rgoalAWP);
  lv_label_set_text(labelAWP, "Red Goal AWP");
  lv_obj_center(labelAWP);
  lv_obj_set_style_bg_color(rgoalAWP, lv_color_black(), 0);
  lv_obj_align(rgoalAWP, LV_ALIGN_TOP_LEFT, 0, 0);
  lv_obj_add_event_cb(rgoalAWP, selection, LV_EVENT_CLICKED, nullptr);

  labelAWP = lv_label_create(rringAWP);
  lv_label_set_text(labelAWP, "Red Ring AWP");
  lv_obj_center(labelAWP);
  lv_obj_set_style_bg_color(rringAWP, lv_color_black(), 0);
  lv_obj_align(rringAWP, LV_ALIGN_LEFT_MID, 0, 0);
  lv_obj_add_event_cb(rringAWP, selection, LV_EVENT_CLICKED, nullptr);

  labelAWP = lv_label_create(bgoalAWP);
  lv_label_set_text(labelAWP, "Blue Goal AWP");
  lv_obj_center(labelAWP);
  lv_obj_set_style_bg_color(bgoalAWP, lv_color_black(), 0);
  lv_obj_align(bgoalAWP, LV_ALIGN_TOP_RIGHT,0, 0);
  lv_obj_add_event_cb(bgoalAWP, selection, LV_EVENT_CLICKED, nullptr);

  labelAWP = lv_label_create(bringAWP);
  lv_label_set_text(labelAWP, "Blue Ring AWP");
  lv_obj_center(labelAWP);
  lv_obj_set_style_bg_color(bringAWP, lv_color_black(), 0);
  lv_obj_align(bringAWP, LV_ALIGN_RIGHT_MID, 0, 0);
  lv_obj_add_event_cb(bringAWP, selection, LV_EVENT_CLICKED, nullptr);

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

  // Test view/////////////////////////////////////////
  lv_roller_set_options(
      testRoller, "Mogo Grab\nIntake One\nIntake Two\nBasket Score\nBasket Top\nLift Load",
      LV_ROLLER_MODE_INFINITE);
  lv_obj_set_style_bg_color(testRoller, lv_color_black(), 0);
  lv_obj_set_style_text_color(testRoller, lv_color_white(), 0);
  lv_obj_set_style_border_color(testRoller, lv_color_black(), 0);
  lv_obj_set_style_bg_color(testRoller, lv_color_black(), LV_PART_SELECTED);
  lv_obj_set_style_text_color(testRoller, lv_color_make(200, 110, 71),
                              LV_PART_SELECTED);
  lv_obj_center(testRoller);
  lv_obj_add_event_cb(testRoller, testSelect, LV_EVENT_CLICKED, nullptr);

  lv_label_set_text(startLabel, "Start");
  lv_obj_set_style_bg_color(testStart, lv_color_black(), 0);
  lv_obj_set_style_text_color(testStart, lv_color_white(), 0);
  lv_obj_center(startLabel);
  lv_obj_align(testStart, LV_ALIGN_LEFT_MID, 0, 0);
  lv_obj_add_event_cb(testStart, testStarter, LV_EVENT_CLICKED, (void *)test);

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

  lv_obj_set_style_bg_color(stats_label,
                            lv_palette_darken(LV_PALETTE_DEEP_ORANGE, 2), 0);
  lv_obj_align(stats_label, LV_ALIGN_CENTER, 0, -20);
  static lv_style_t stats_style;
  lv_style_init(&stats_style);
  lv_style_set_text_align(&stats_style, LV_TEXT_ALIGN_CENTER);
  lv_obj_add_style(stats_label, &stats_style, 0);

  char statText[150];

  while (true) {
    lv_label_set_text(stats_label, "");

    // stats tab
    lv_label_set_text_fmt(stats_label,
                          "Basket: %i | Lift: %i | Lift Pos: %.2f\nDT "
                          "Left Temp: %.0f | DT Right Temp: %.0f\nIntake Temp: "
                          "%.0f | Lift Temp: %.0f | Basket Temp: %.0f",
                          basketLimit.get_value(), liftLimit.get_value(),
                          lift.get_position(), DTLeft.get_temperature(),
                          DTRight.get_temperature(), Intake.get_temperature(),
                          lift.get_temperature(), basket.get_temperature());

    pros::delay(500);
  } // while loop
} // void selector