#pragma once
#include "lemlib/pose.hpp" // IWYU pragma: keep
#include "liblvgl/core/lv_disp.h" // IWYU pragma: keep
#include "liblvgl/core/lv_event.h" // IWYU pragma: keep
#include "liblvgl/core/lv_obj.h" // IWYU pragma: keep
#include "liblvgl/core/lv_obj_pos.h" // IWYU pragma: keep
#include "liblvgl/core/lv_obj_style.h" // IWYU pragma: keep
#include "liblvgl/draw/lv_draw_rect.h" // IWYU pragma: keep
#include "liblvgl/extra/widgets/tabview/lv_tabview.h" // IWYU pragma: keep
#include "liblvgl/lv_conf_internal.h" // IWYU pragma: keep
#include "liblvgl/misc/lv_area.h" // IWYU pragma: keep
#include "liblvgl/misc/lv_color.h" // IWYU pragma: keep
#include "liblvgl/widgets/lv_btn.h" // IWYU pragma: keep
#include "liblvgl/widgets/lv_label.h" // IWYU pragma: keep
#include "liblvgl/widgets/lv_roller.h" // IWYU pragma: keep
#include "subsystemsHeaders/basket.hpp" // IWYU pragma: keep
#include "subsystemsHeaders/drive.hpp" // IWYU pragma: keep
#include "subsystemsHeaders/intake.hpp" // IWYU pragma: keep
#include "test.hpp" // IWYU pragma: keep
#include <cstdio>

extern int autonSelection;
extern int testSelection;
inline bool testing = false;

void selector();