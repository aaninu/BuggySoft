/* libMotors */

/* Imports */
#include "libPCF8574.h"

/* List of extern functions */
void dMsg(String text);
void leds_bottom_down(bool state);

/* List of local functions */
void setup_motors();
void motors_full_off();
void motors_go_up();
void motors_go_down();
void motors_go_left();
void motors_go_right();

/* List of PINS */

// 0,1 >> Left - Top
//  0 > Down
int motor_left_top_down = 0;
//  1 > Up 
int motor_left_top_up = 1;

// 2,3 >> Left - Bottom
//  2 > Down
int motor_left_bottom_down = 2;
//  3 > Up
int motor_left_bottom_up = 3;

// 4,5 >> Right - Bottom
//  4 > Down
int motor_right_bottom_down = 4;
//  5 > Up
int motor_right_bottom_up = 5;

// 6,7 >> Right - Top
//  6 > Down
int motor_right_top_down = 6;
//  7 > Up 
int motor_right_top_up = 7;


/* Init - the variable for controlling motors */
PCF8574 Motor(0x20);

/* Setup */
void setup_motors(){
  Motor.pinMode(motor_left_top_down, OUTPUT);
  Motor.pinMode(motor_left_top_up, OUTPUT);
  Motor.pinMode(motor_left_bottom_down, OUTPUT);
  Motor.pinMode(motor_left_bottom_up, OUTPUT);
  Motor.pinMode(motor_right_bottom_down, OUTPUT);
  Motor.pinMode(motor_right_bottom_up, OUTPUT);
  Motor.pinMode(motor_right_top_down, OUTPUT);
  Motor.pinMode(motor_right_top_up, OUTPUT);
  Motor.begin();
  dMsg("[Init]: Motors are ready ...");
}

/* Motors - Full OFF */
void motors_full_off(){
  Motor.digitalWrite(motor_left_top_down, LOW);
  Motor.digitalWrite(motor_left_top_up, LOW);
  Motor.digitalWrite(motor_left_bottom_down, LOW);
  Motor.digitalWrite(motor_left_bottom_up, LOW);
  Motor.digitalWrite(motor_right_bottom_down, LOW);
  Motor.digitalWrite(motor_right_bottom_up, LOW);
  Motor.digitalWrite(motor_right_top_down, LOW);
  Motor.digitalWrite(motor_right_top_up, LOW);
  dMsg("[Debug]: Motors -> Turn off all.");
  leds_bottom_down(LOW);
}

/* Motors - Go UP */
void motors_go_up(){
  motors_full_off();
  Motor.digitalWrite(motor_left_top_up, HIGH);
  Motor.digitalWrite(motor_left_bottom_up, HIGH);
  Motor.digitalWrite(motor_right_bottom_up, HIGH);
  Motor.digitalWrite(motor_right_top_up, HIGH);
  dMsg("[Debug]: Motors -> Go UP.");
}

/* Motors - Go DOWN */
void motors_go_down(){
  motors_full_off();
  Motor.digitalWrite(motor_left_top_down, HIGH);
  Motor.digitalWrite(motor_left_bottom_down, HIGH);
  Motor.digitalWrite(motor_right_bottom_down, HIGH);
  Motor.digitalWrite(motor_right_top_down, HIGH);
  dMsg("[Debug]: Motors -> Go DOWN");
  leds_bottom_down(HIGH);
}

/* Motors - Go LEFT */
void motors_go_left(){
  motors_full_off();
  Motor.digitalWrite(motor_left_top_down, HIGH);
  Motor.digitalWrite(motor_left_bottom_down, HIGH);
  Motor.digitalWrite(motor_right_bottom_up, HIGH);
  Motor.digitalWrite(motor_right_top_up, HIGH);
  dMsg("[Debug]: Motors -> Go LEFT.");
}

/* Motors - Go RIGHT */
void motors_go_right(){
  motors_full_off();
  Motor.digitalWrite(motor_left_top_up, HIGH);
  Motor.digitalWrite(motor_left_bottom_up, HIGH);
  Motor.digitalWrite(motor_right_bottom_down, HIGH);
  Motor.digitalWrite(motor_right_top_down, HIGH);
  dMsg("[Debug]: Motors -> Go RIGHT.");
}

