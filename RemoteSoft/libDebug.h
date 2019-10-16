/* libDebug */

/* List of extern functions */


/* List of local functions */
void setup_debug();
void dMsg(String text);
void dMsg(String text, int value);
void dMsg(String text, bool value);
void dMsg(String text, String text2);
void dMsg(String text, String text2, bool value);
void read_serial();


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
    
    }
}

