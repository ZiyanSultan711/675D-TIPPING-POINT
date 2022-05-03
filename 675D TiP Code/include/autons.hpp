#pragma once

#include "EZ-Template/drive/drive.hpp"

extern Drive chassis;

extern const int DRIVE_SPEED;
extern const int TURN_SPEED;
extern const int SWING_SPEED;

void wall_exit_condition();

void drive_example();
void turn_example();
void drive_and_turn();
void wait_until_change_speed();
void swing_example();
void combining_movements();
void interfered_example();

void default_constants();
void one_mogo_constants();
void two_mogo_constants();

void prog_skills();
