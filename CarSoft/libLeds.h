/* libLeds */

/* List of extern functions */
void dMsg(String text);
void dMsg(String text, int value);
void dMsg(String text, bool value);

/* List of local functions */
void setup_leds();
void leds_top_short(bool state);
void leds_top_long(bool state);
void leds_left();
void leds_left_state(bool state);
void leds_right();
void leds_right_state(bool state);
void leds_lr();
void leds_lr_state(bool state);
void leds_bottom_down(bool state);
void leds_bottom_short(bool state);
void leds_bottom_stop(bool state);

/* List of variables */
int led_tb_left = 2;
int led_tb_right = 3;
int led_top_short = 4;
int led_top_long = 5;
int led_bottom_down = 6;
int led_bottom_short = 7;
int led_bottom_stop = 8;
int led_timer = 0;
bool led_left_old_state = false;
bool led_left_state = false;
bool led_right_old_state = false;
bool led_right_state = false;
bool led_lr_old_state = false;
bool led_lr_state = false;

/* Setup */
void setup_leds(){
  pinMode(led_tb_left, OUTPUT);
  pinMode(led_tb_right, OUTPUT);
  pinMode(led_top_short, OUTPUT);
  pinMode(led_top_long, OUTPUT);
  pinMode(led_bottom_down, OUTPUT);
  pinMode(led_bottom_short, OUTPUT);
  pinMode(led_bottom_stop, OUTPUT);
  dMsg("[Init]: Leds are ready ...");
}

/* Led Top Short */
void leds_top_short(bool state){
  digitalWrite(led_top_short, state);
  dMsg("[Debug]: Leds -> Top SHORT -> ", state);
}

/* Led Top Long */
void leds_top_long(bool state){
  digitalWrite(led_top_long, state);
  dMsg("[Debug]: Leds -> Top LONG -> ", state);
}

/* Led Left */
void leds_left(){
  if (led_left_state){
    if (led_timer == 0){
      digitalWrite(led_tb_left, HIGH);
    }else if (led_timer == 350){
      digitalWrite(led_tb_left, LOW);
    }else if (led_timer >= 700){
      led_timer = -1;
    }
    led_timer += 1;
   led_left_old_state = led_left_state;
  }else if (led_left_old_state != led_left_state){
    digitalWrite(led_tb_left, LOW);
    led_timer = 0;
    led_left_old_state = led_left_state;
  }
}
void leds_left_state(bool state){
  led_left_state = state;
  if (led_right_state)
    led_right_state = false;
  dMsg("[Debug]: Leds -> Left -> ", state);
}

/* Led Right */
void leds_right(){
  if (led_right_state){
    if (led_timer == 0){
      digitalWrite(led_tb_right, HIGH);
    }else if (led_timer == 350){
      digitalWrite(led_tb_right, LOW);
    }else if (led_timer >= 700){
      led_timer = -1;
    }
    led_timer += 1;
   led_right_old_state = led_right_state;
  }else if (led_right_old_state != led_right_state){
    digitalWrite(led_tb_right, LOW);
    led_timer = 0;
    led_right_old_state = led_right_state;
  }
}
void leds_right_state(bool state){
  led_right_state = state;
  if (led_left_state)
    led_left_state = false;
  dMsg("[Debug]: Leds -> Right -> ", state);
}

/* Led Left-Right */
void leds_lr(){
  if (led_lr_state){
    if (led_timer == 0){
      digitalWrite(led_tb_left, HIGH);
      digitalWrite(led_tb_right, HIGH);
    }else if (led_timer == 250){
      digitalWrite(led_tb_left, LOW);
      digitalWrite(led_tb_right, LOW);
    }else if (led_timer >= 500){
      led_timer = -1;
    }
    led_timer += 1;
   led_lr_old_state = led_lr_state;
  }else if (led_lr_old_state != led_lr_state){
    digitalWrite(led_tb_left, LOW);
    digitalWrite(led_tb_right, LOW);
    led_timer = 0;
    led_lr_old_state = led_lr_state;
  }
}
void leds_lr_state(bool state){
  led_lr_state = state;
  if (led_left_state)
    led_left_state = false;
  if (led_right_state)
    led_right_state = false;
  dMsg("[Debug]: Leds -> LR -> ", state);
}

/* Led Bottom DOWN */
void leds_bottom_down(bool state){
  digitalWrite(led_bottom_down, state);
  dMsg("[Debug]: Leds -> Bottom DOWN -> ", state);
}

/* Led Bottom SHORT */
void leds_bottom_short(bool state){
  digitalWrite(led_bottom_short, state);
  dMsg("[Debug]: Leds -> Bottom SHORT -> ", state);
}

/* Led Bottom STOP */
void leds_bottom_stop(bool state){
  digitalWrite(led_bottom_stop, state);
  dMsg("[Debug]: Leds -> Bottom STOP -> ", state);
}

