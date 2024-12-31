#pragma once
#include "auton_selector.hpp"
#include "lemlib/pose.hpp"
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
#include "liblvgl/widgets/lv_roller.h"
#include "subsystemsHeaders/basket.hpp"
#include "subsystemsHeaders/drive.hpp"
#include "subsystemsHeaders/intake.hpp"
#include "test.hpp"
#include <cstdio>

extern int autonSelection;
extern int testSelection;
inline bool testing = false;

void selector();