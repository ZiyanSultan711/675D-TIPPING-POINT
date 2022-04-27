#include "main.h"

bool is_time_up = false;

void claw_open(){
  piston_clamp.set_value(false);
  piston_clamp_1.set_value(false);
  clamp_current_state = true;
}

void claw_close(){
  piston_clamp.set_value(true);
  piston_clamp_1.set_value(true);
  clamp_current_state = false;
}

int co_task(){
  claw_open();

  return 1;
}

int cc_task(){
  claw_close();

  return 1;
}

void start_claw_open(){
  pros::Task co(co_task);
}

void start_claw_close(){
  pros::Task cc(cc_task);
}

int td_task(){
  tilter.set_value(true);
  mogo_is_down = true;

  wait(500);
  tilter_clamp.set_value(false);
  mogo_clamp_closed = false;

  return 1;
}

int tu_task(){
  tilter_clamp.set_value(true);
  mogo_clamp_closed = true;


  tilter.set_value(false);
  mogo_is_down = false;

  return 1;
}

void tilter_down(){
  pros::Task td(td_task);
}

void tilter_up(){
  pros::Task tu(tu_task);
}

int cd_task(){
  canstealer.set_value(true);
  return 1;
}

int cu_task(){
  canstealer.set_value(false);
  return 1;
}

void canstealer_down(){
  pros::Task cd(cd_task);
}
void canstealer_up(){
  pros::Task cu(cu_task);
}

void start_lift_to(int pos, int speed){
  lift.move_absolute(-pos, speed);
}
void lift_to(int pos, int speed){
  lift.move_absolute(-pos, speed);

  while(fabs(lift.get_position() - lift.get_target_position()) > 5){
    wait(5);
  }
}

void start_intake(int speed){
  conveyor.move_velocity(speed);
}
void stop_intake(){
  conveyor.move_velocity(0);
}
void start_intake_for(int deg, int speed){
  conveyor.move_relative(deg, speed);
}

void intake_for(int deg, int speed){
  conveyor.tare_position();
  conveyor.move_absolute(deg, speed);

  while(fabs(conveyor.get_position() - conveyor.get_target_position()) > 2){
    wait(5);
  }
}

void wait(int time){
  pros::delay(time);
}

void start_flipout(){
  claw_open();
  tilter_down();
}

int check_for_time(){
  is_time_up = false;
  wait(13400);
  is_time_up = true;
  master.rumble("---");
  return 1;
}
