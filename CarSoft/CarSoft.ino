/* Imports */
#include "libMotors.h"
#include "libLeds.h"
#include "libDebug.h"
#include "libRadio.h"
#include "libTimedAction.h"

/* Setup */
void setup(){
  /* Setup Debug */
  setup_debug();

  /* Setup Motors */
  setup_motors();

  /* Setup Leds */
  setup_leds();

  /* Setup Radio */
  setup_radio();

  dMsg("[Init]: ready ...");
}

/* TimedAction */
TimedAction Timed_read_serial = TimedAction(1, read_serial);
TimedAction Timed_leds_left = TimedAction(1, leds_left);
TimedAction Timed_leds_right = TimedAction(1, leds_right);
TimedAction Timed_leds_lr = TimedAction(1, leds_lr);
TimedAction Timed_radio_receiver = TimedAction(1, radio_receiver);

/* Loop */
void loop(){
  Timed_read_serial.check();
  Timed_leds_left.check();
  Timed_leds_right.check();
  Timed_leds_lr.check();
  Timed_radio_receiver.check();
}

