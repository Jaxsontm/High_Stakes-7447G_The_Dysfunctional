#pragma once
void selector();

extern int autonSelection;

enum autons {
    redright = 0,
    redleft = 1,
    redsolo = 2,
    redrightElim = 3,
    redleftElim = 4,
    blueright = 5,
    blueleft = 6,
    bluesolo = 7,
    bluerightElim = 8,
    blueleftElim = 9,
    skills = 10,
    None = 11,
};