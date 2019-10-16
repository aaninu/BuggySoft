/* libbuttons */

/* List of extern functions */
void dMsg(String text);
void lcd_button_effect(bool state);
void lcd_OptionChange();
void lcd_OptionMenu();
void lcd_OptionHome();
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

/* List of local functions */
void setup_buttons();
void press_button_1();
void press_button_2();
void press_button_3();
void press_joyButton();
void press_joyMove();
void press_button_clear_effect();
int get_JoyLine1();
int get_JoyLine2();
bool compare_Joy(int iOld, int iNew);

/* List of variables */
int button_1 = 12;
int button_2 = 10;
int button_3 = 11;
int valButton_1;
int valButton_2;
int valButton_3;
bool bressedButton_1 = false;
bool bressedButton_2 = false;
bool bressedButton_3 = false;

int joyButton = 8;
int joyLine1 = 0;
int joyLine2 = 1;
int valJoyButton;
int valJoyLine1;
int valJoyLine2;
int valOldJoyLine1 = 0;
int valOldJoyLine2 = 0;
bool bressedJoyButton = false;

/* Setup */
void setup_buttons(){
  pinMode(button_1, INPUT_PULLUP);
  pinMode(button_2, INPUT_PULLUP);
  pinMode(button_3, INPUT_PULLUP);
  pinMode(joyButton, INPUT);
  digitalWrite(joyButton, HIGH);
  dMsg("[Init]: Buttons are ready ...");
}

/* Press Button 1 */
void press_button_1(){
  valButton_1 = digitalRead(button_1);
  if (valButton_1 == 0){
    if (bressedButton_1 == false){
      lcd_button_effect(true);
      lcd_OptionHome();
      Serial.print("111: ");
      Serial.println(valButton_1);    
    }
    bressedButton_1 = true;
  }else{
    bressedButton_1 = false;
  }
}

/* Press Button 2 */
void press_button_2(){
  valButton_2 = digitalRead(button_2);
  if (valButton_2 == 0){
    if (bressedButton_2 == false){
      lcd_button_effect(true);
      lcd_OptionMenu();
      Serial.print("222222: ");
      Serial.println(valButton_2);
    }
    bressedButton_2 = true;
  }else{
    bressedButton_2 = false;
  }
}

/* Press Button 3 */
void press_button_3(){
  valButton_3 = digitalRead(button_3);
  if (valButton_3 == 0){
    if (bressedButton_3 == false){
      lcd_button_effect(true);
      lcd_OptionChange();
      Serial.print("333333333: ");
      Serial.println(valButton_3);
    }
    bressedButton_3 = true;
  }else{
    bressedButton_3 = false;
  }
}

/* Press JoyButton */
void press_joyButton(){
  valJoyButton = digitalRead(joyButton);
  if (valJoyButton == 0){
    if (bressedJoyButton == false){
      lcd_button_effect(true);
      Serial.print("444444444444: ");
      Serial.println(valJoyButton);
    }
    bressedJoyButton = true;
  }else{
    bressedJoyButton = false;
  }
}

/* Move Joy Move */
void press_joyMove(){
  valJoyLine1 = analogRead(joyLine1);
  if (compare_Joy(valOldJoyLine1, valJoyLine1)){
    valOldJoyLine1 = valJoyLine1;

    Serial.print("xxxxxxxx: ");
    Serial.println(valJoyLine1);

    if (valJoyLine1 < 475){
      send_CMD__Motor_Led_Left();
    }else if (valJoyLine1 > 525){
      send_CMD__Motor_Led_Right();
    }else{
      send_CMD__Motor_Led_Stop();
    }
    
   /*
    if (valJoyLine1 < 100){
      send_CMD__Motor_Led_Left();
    }else if (valJoyLine1 < 500 ){
      send_CMD_ledLR_Left();
      //send_CMD_Motor_Stop();
    }else if (valJoyLine1 > 900){
      send_CMD__Motor_Led_Right();
    }else if (valJoyLine1 > 525){
      send_CMD_ledLR_Right();
      //send_CMD_Motor_Stop();
    }else{
      send_CMD__Motor_Led_Stop();
    }
*/

  }
  valJoyLine2 = analogRead(joyLine2);
  if (compare_Joy(valOldJoyLine2, valJoyLine2)){
    valOldJoyLine2 = valJoyLine2;
    Serial.print("yyyyyyyy: ");
    Serial.println(valJoyLine2);

    if (valJoyLine2 < 475){
      send_CMD_Motor_Bottom();
    }else if (valJoyLine2 > 500){
      send_CMD_Motor_Top();
    }else{
      send_CMD_Motor_Stop();
    }
    
  }
 
}

/* Clear Press Button Effect */
void press_button_clear_effect(){
  if (valButton_1 == 1 && valButton_2 == 1 && valButton_3 == 1 && valJoyButton == 1){
     lcd_button_effect(false);
  }
}

int get_JoyLine1(){
  return valJoyLine1;
}
int get_JoyLine2(){
  return valJoyLine2;
}


/* Compare Joy Values */
bool compare_Joy(int iOld, int iNew){
  if (iNew == 0 && iOld == 0)
    return false;
  return ((iNew <= iOld - 2 || iNew >= iOld + 2) || iOld == 0)?true:false;
}
