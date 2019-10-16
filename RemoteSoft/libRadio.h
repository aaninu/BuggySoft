/* libRadio */

/* Imports */
#include "libVirtualWire.h"  

/* List of extern functions */
void dMsg(String text);

/* List of local functions */
void setup_radio();
void send_CMD(char *Value);
void send_CMD(String Value);
bool send_Check(String value);
void send_CMD_ledLR_Left();
void send_CMD_ledLR_Right();
void send_CMD_ledLR_Stop();
void send_CMD_Motor_Left();
void send_CMD_Motor_Right();
void send_CMD_Motor_Top();
void send_CMD_Motor_Bottom();
void send_CMD_Motor_Stop();
void send_CMD__Motor_Led_Left();
void send_CMD__Motor_Led_Right();
void send_CMD__Motor_Led_Stop();


/* List of variables */
int pin_radio = 9;
int Radio_Send_count = 0;
String Radio_Send_old = "";
String Radio_Send_new = "";

/* Setup */
void setup_radio(){
  vw_set_ptt_inverted(true);
  vw_set_tx_pin(pin_radio);
  vw_setup(2000);  
  vw_rx_start();
  dMsg("[Init]: Radio is ready ...");
}

/* Send Radio Command */
void send_CMD(char *Value){
  //if (send_Check(Value) == true){
    vw_send((uint8_t *)Value, strlen(Value));
    delay(50);
    vw_send((uint8_t *)Value, strlen(Value));
    vw_wait_tx();
    Serial.print("send_CMD: ");
    Serial.println(Value);
 // }
}

/* Send Radio Command */
void send_CMD(String Value){
 // if (send_Check(Value) == true){
    int iValue = Value.length() + 1;
    char cValue[iValue];
    Value.toCharArray(cValue, iValue);
    send_CMD(cValue);
 // }
}

bool send_Check(String value){
  bool rStatus = true;
  Radio_Send_new = value;

  if (Radio_Send_old == Radio_Send_new && Radio_Send_count == 5){
    return false;
  }else if (Radio_Send_count >= 5){
    Radio_Send_old = Radio_Send_new;
    Radio_Send_count = 0;
  }else{
    Radio_Send_count += 1;
  }
  return rStatus;
}

void send_CMD_ledLR_Left(){
  String cmd = "APP_LED_LEF";
  send_CMD(cmd);  
}

void send_CMD_ledLR_Right(){
  String cmd = "APP_LED_RIG";
  send_CMD(cmd);  
}

void send_CMD_ledLR_Stop(){
  String cmd = "APP_LED_STO";
  send_CMD(cmd);  
}

void send_CMD_Motor_Left(){
  String cmd = "APP_MOTOR_L";
  send_CMD(cmd);  
}

void send_CMD_Motor_Right(){
  String cmd = "APP_MOTOR_R";
  send_CMD(cmd);  
}

void send_CMD_Motor_Top(){
  String cmd = "APP_MOTOR_T";
  send_CMD(cmd);  
}

void send_CMD_Motor_Bottom(){
  String cmd = "APP_MOTOR_B";
  send_CMD(cmd);  
}

void send_CMD_Motor_Stop(){
  String cmd = "APP_MOTOR_O";
  send_CMD(cmd);  
}

void send_CMD__Motor_Led_Left(){
  String cmd = "APP_LED_M_L";
  send_CMD(cmd);  
}

void send_CMD__Motor_Led_Right(){
  String cmd = "APP_LED_M_R";
  send_CMD(cmd);  
}

void send_CMD__Motor_Led_Stop(){
  String cmd = "APP_LED_M_S";
  send_CMD(cmd);  
}
