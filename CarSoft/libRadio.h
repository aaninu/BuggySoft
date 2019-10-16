/* libRadio */

/* Imports */
#include "libVirtualWire.h"

/* List of extern functions */
void dMsg(String text);
void dMsg(String text, int value);
void dMsg(String text, bool value);
void dMsg(String text, String text2);
void dMsg(String text, String text2, bool value);
void motors_full_off();
void motors_go_up();
void motors_go_down();
void motors_go_left();
void motors_go_right();
void leds_left_state(bool state);
void leds_right_state(bool state);

/* List of local functions */
void setup_radio();
void radio_receiver();
void radio_parsing(char Value[], int Len);
void radio_decodeString(String Variabila);
void radio_decodeInt(String Variabila, int Value);

/* List of variables */
int radio_pin = 9;
int radio_speed = 2000;
byte buf[VW_MAX_MESSAGE_LEN];
byte buflen = VW_MAX_MESSAGE_LEN;
String radio_old_Recv = "";

/* Controls */
String COD_Motor_Top = "APP_MOTOR_T";         // Deplasarea inainte
String COD_Motor_Bottom = "APP_MOTOR_B";      // Deplasarea in spate
String COD_Motor_Left = "APP_MOTOR_L";        // Rotirea la stanga
String COD_Motor_Right = "APP_MOTOR_R";       // Rotirea la dreapta
String COD_Motor_Stop = "APP_MOTOR_O";        // Opreste motoarele

String COD_ledLr_Left = "APP_LED_LEF";
String COD_ledLr_Right = "APP_LED_RIG";
String COD_ledLr_Stop = "APP_LED_STO";

String COD__Motor_Led_Left = "APP_LED_M_L";
String COD__Motor_Led_Right = "APP_LED_M_R";
String COD__Motor_Led_Stop = "APP_LED_M_S";

/* Setup */
void setup_radio(){
  //vw_set_ptt_inverted(true);
  vw_set_rx_pin(radio_pin); 
  vw_setup(radio_speed);
  vw_rx_start();
  dMsg("[Init]: Radio module is ready ...");
}

/* Radio Receiver */
void radio_receiver(){
  if (vw_get_message(buf, &buflen)){
    char Radio_Receive[buflen];
    for (int i = 0; i < buflen; i++){
      Radio_Receive[i] = char(buf[i]);  
    }
    radio_parsing(Radio_Receive, buflen);
  }
}

/* Radio parsing */
void radio_parsing(char Value[], int Len){
  char vType[11];
  for (int i = 0; i < 11; i++){
    vType[i] = Value[i];
  }
  String Variabila = (String)vType;
  Variabila = Variabila.substring(0,11);

  radio_decodeString(Variabila);
  


  

}



/* Radio decode variables */
void radio_decodeString(String Variabila){
  if (Variabila.equals(radio_old_Recv))
    return;
  radio_old_Recv = Variabila;
  if (Variabila.equals(COD_Motor_Top)){
    motors_go_up();
  }else if (Variabila.equals(COD_Motor_Bottom)){
    motors_go_down();
  }else if (Variabila.equals(COD_Motor_Stop)){
    motors_full_off();
  }else if (Variabila.equals(COD_Motor_Left)){
    motors_go_left();
  }else if (Variabila.equals(COD_Motor_Right)){
    motors_go_right();
  }else if (Variabila.equals(COD_ledLr_Left)){
    leds_left_state(true);
  }else if (Variabila.equals(COD_ledLr_Right)){
    leds_right_state(true);
  }else if (Variabila.equals(COD_ledLr_Stop)){
    leds_left_state(false);
    leds_right_state(false);
  }else if (Variabila.equals(COD__Motor_Led_Left)){
    leds_left_state(true);
    motors_go_left();
  }else if (Variabila.equals(COD__Motor_Led_Right)){
    leds_right_state(true);
    motors_go_right();
  }else if (Variabila.equals(COD__Motor_Led_Stop)){
    leds_left_state(false);
    leds_right_state(false);
    motors_full_off();
  }else{
    dMsg("Radio_Decode_Variable(...):", Variabila);
    
  }
}
