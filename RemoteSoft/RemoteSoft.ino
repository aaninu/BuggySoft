/* Imports */
#include "libDebug.h"
#include "libLCD.h"
#include "libRadio.h"
#include "libButtons.h"
#include "libTimedAction.h"

/* Setup */
void setup() {
  /* Setup Debug */
  setup_debug();

  /* Setup LCD */
  setup_lcd();

  /* LCD Init Effect */
  lcd_init_effect();

  /* Setup Radio */
  setup_radio();

  /* Setup Key */
  setup_buttons();
  
  dMsg("[Init]: ready ...");
}

/* TimedAction */
TimedAction Timed_press_button_1 = TimedAction(1, press_button_1);
TimedAction Timed_press_button_2 = TimedAction(1, press_button_2);
TimedAction Timed_press_button_3 = TimedAction(1, press_button_3);
TimedAction Timed_press_joyButton = TimedAction(1, press_joyButton);
TimedAction Timed_press_joyMove = TimedAction(1, press_joyMove);
TimedAction Timed_press_button_effect = TimedAction(1, press_button_clear_effect);
TimedAction Timed_lcd_Menu = TimedAction(1, lcd_Menu);

/* Loop */
void loop() {
  Timed_press_button_1.check();
  Timed_press_button_2.check();
  Timed_press_button_3.check();
  Timed_press_joyButton.check();
  Timed_press_joyMove.check();
  Timed_press_button_effect.check();
  Timed_lcd_Menu.check();
}
