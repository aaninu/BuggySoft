/* libLCD */

/* Imports */
#include "LiquidCrystal.h"
#include "libOptions.h"

/* List of extern functions */
void dMsg(String text);
int get_JoyLine1();
int get_JoyLine2();

/* List of local functions */
void setup_lcd();
void lcd_Print(String l_0, String l_1, String l_2, String l_3);
void lcd_Print(int iStart, String l_0, String l_1, String l_2, String l_3);
void lcd_Empty();
void lcd_init_effect();
void lcd_button_effect(bool state);
void lcd_Menu();
void lcd_OptionChange();
void lcd_OptionMenu();
void lcd_OptionHome();
void lcd_ShowOptions(char *options[], int pos);

/* List of variables */
LiquidCrystal lcd(2,3,4,5,6,7);
String lineEmpty = "                    ";

/* Setup */
void setup_lcd(){
  lcd.begin(20,4);
  dMsg("[Init]: LCD is ready ...");
}

/* LCD Print */
void lcd_Print(String l_0, String l_1, String l_2, String l_3){
  lcd.setCursor(0,0);
  lcd.print(l_0);
  lcd.setCursor(0,1);
  lcd.print(l_1);
  lcd.setCursor(0,2);
  lcd.print(l_2);
  lcd.setCursor(0,3);
  lcd.print(l_3);
}
void lcd_Print(int iStart, String l_0, String l_1, String l_2, String l_3){
  lcd.setCursor(iStart,0);
  lcd.print(l_0);
  lcd.setCursor(iStart,1);
  lcd.print(l_1);
  lcd.setCursor(iStart,2);
  lcd.print(l_2);
  lcd.setCursor(iStart,3);
  lcd.print(l_3);
}

/* Clear LCD */
void lcd_Empty(){
  lcd_Print(lineEmpty, lineEmpty, lineEmpty, lineEmpty);
} 

/* LCD Init Effect */
void lcd_init_effect(){
  lcd_Print(lineEmpty, " Welcome!", lineEmpty, lineEmpty);
  lcd.setCursor(1,3);
  lcd.print("Cars Remote ");
  lcd.print((char)126);
  lcd.print(" Dev");
  lcd.setCursor(1,2);
  for (int i = 1; i < 19; i++){
    lcd.print((char)255);
    delay(150);
  }
  lcd_Empty();
}

/* LCD Button Press Effect */
void lcd_button_effect(bool state){
  lcd.setCursor(19, 0);
  if (state == true){
    lcd.print((char)255);
  }else{
    lcd.print(" ");
  }
}

int j1 = 0;
int j2 = 0;
int jo1 = 0;
int jo2 = 0;

/* LCD Menu */
void lcd_Menu(){
  if (optionHome){
    lcd_Print(" Home Page ...  ", "", "",  lineEmpty);
    j1 = get_JoyLine1();
    if (j1 != jo1){
      jo1 = j1;
      lcd.setCursor(0, 1);
      lcd.print(" x: ");
      lcd.print(get_JoyLine1());
      lcd.print("          ");
    }
    j2 = get_JoyLine2();
    if (j2 != jo2){
      jo2 = j2;
      lcd.setCursor(0, 2);
      lcd.print(" y: ");
      lcd.print(get_JoyLine2());
      lcd.print("          ");
    }
  }else{
    if (optionMenu == 0){
      lcd_ShowOptions(ledOptions, optionPos);
    }else{
      lcd_ShowOptions(carOptions, optionPos);
    }
  }
}

void lcd_OptionChange(){
  optionPos++;
  if (optionPos > get_MaxOptions()){
    optionPos = 1;
  }
}
void lcd_OptionMenu(){
  optionPos = 1;
  optionMenu++;
  if (optionMenu >= maxMenu){
    optionMenu = 0;
  }
}
void lcd_OptionHome(){
  optionHome = !optionHome;
}


void lcd_ShowOptions(char *options[], int pos){
  /* Show options */
  int effectPos = 0;
  if ( pos <= 3){
    effectPos = pos;
    if (get_MaxOptions() == 1){
      lcd_Print(1, options[0], options[1], lineEmpty,  lineEmpty);
    }else if (get_MaxOptions() == 2){
      lcd_Print(1, options[0], options[1], options[2],  lineEmpty);
    }else{
      lcd_Print(1, options[0], options[1], options[2],  options[3]);
    }
  }else{
    effectPos = 3;
    lcd_Print(1, options[0], options[pos - 2], options[pos - 1],  options[pos]);
  }
  /* Clear old effect */
  if (effectPos == 1){
    lcd.setCursor(0, 2);
    lcd.print(" ");
    lcd.setCursor(0, 3);
    lcd.print(" ");
  }else if (effectPos == 2){
    lcd.setCursor(0, 1);
    lcd.print(" ");
    lcd.setCursor(0, 3);
    lcd.print(" ");
  }else if (effectPos == 3){
    lcd.setCursor(0, 1);
    lcd.print(" ");
    lcd.setCursor(0, 2);
    lcd.print(" ");
  }
  /* Create new effect */
  if (lcd_effect_time == 0){
    lcd.setCursor(0, effectPos);
    lcd.print((char)126);
  }else if (lcd_effect_time == 15){
    lcd.setCursor(0, effectPos);
    lcd.print(" ");
  }else if (lcd_effect_time >= 30){
    lcd_effect_time = -1;
  }
  lcd_effect_time++;  
}




