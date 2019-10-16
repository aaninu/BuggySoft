/* libDebug */

/* List of extern functions */
void motors_full_off();
void motors_go_up();
void motors_go_down();
void motors_go_left();
void motors_go_right();
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

/* List of local functions */
void setup_debug();
void dMsg(String text);
void dMsg(String text, int value);
void dMsg(String text, bool value);
void dMsg(String text, String text2);
void dMsg(String text, String text2, bool value);
void read_serial();
void debug_motors(int id);
void debug_leds(int id);


/* List of variables */
int debug_port = 9600;
bool debug_status = true;
int debug_temp = 0;

/* Setup */
void setup_debug(){
  if (debug_status){
    Serial.begin(debug_port);
    dMsg("[Init]: Debug is ready ...");
  }
}

/* Debug Message */
void dMsg(String text){
  if (debug_status)
    Serial.println(text);
}
void dMsg(String text, int value){
  if (debug_status){
    Serial.print(text);
    Serial.println(value);
  }
}
void dMsg(String text, bool value){
  if (debug_status){
    Serial.print(text);
    Serial.println(value);
  }
}
void dMsg(String text, String text2){
  if (debug_status){
    Serial.print(text);
    Serial.println(text2);
  }
}
void dMsg(String text, String text2, bool value){
  if (debug_status){
    Serial.print(text);
    Serial.print(text2);
    Serial.print(" ");
    Serial.println(value);
  }
}

/* Serial Read */
void read_serial(){
  if (debug_status)
    if (Serial.available() > 0){
      debug_temp = Serial.read();
      dMsg("[Debug]: Serial.read(): ", debug_temp);
      debug_motors(debug_temp);
      debug_leds(debug_temp);
    }
}

/* Motor Debug */
void debug_motors(int id){
  if (id == 49){  // Key {1}
    motors_full_off();
  }else if (id == 50){ // Key {2}
    motors_go_up();
  }else if (id == 51){ // Key {3}
    motors_go_down();
  }else if (id == 52){ // Key {4}
    motors_go_left();
  }else if (id == 53){ // Key {5}
    motors_go_right();
  }
}

/* Leds Debug */
void debug_leds(int id){
  if (id == 65){  // Key {A}
    leds_top_short(HIGH);
  }else if (id == 97){ // Key {a}
    leds_top_short(LOW);
  }else if (id == 66){ // Key {B}
    leds_top_long(HIGH);
  }else if (id == 98){ // Key {b}
    leds_top_long(LOW);
  }else if (id == 67){ // Key {C}
    leds_left_state(true);
  }else if (id == 99){ // Key {c}
    leds_left_state(false);
  }else if (id == 68){ // Key {D}
    leds_right_state(true);
  }else if (id == 100){ // Key {d}
    leds_right_state(false);
  }else if (id == 69){ // Key {E}
    leds_lr_state(true);
  }else if (id == 101){ // Key {e}
    leds_lr_state(false);
  }else if (id == 70){ // Key {F}
    leds_bottom_down(HIGH);
  }else if (id == 102){ // Key {f}
    leds_bottom_down(LOW);
  }else if (id == 71){ // Key {G}
    leds_bottom_short(HIGH);
  }else if (id == 103){ // Key {g}
    leds_bottom_short(LOW);
  }else if (id == 72){ // Key {H}
    leds_bottom_stop(HIGH);
  }else if (id == 104){ // Key {h}
    leds_bottom_stop(LOW);
  }
}

