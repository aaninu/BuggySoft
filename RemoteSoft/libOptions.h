/* libOptions */

/* List of extern functions */

/* List of local functions */
template< typename T, size_t N > size_t ArraySize (T (&) [N]){ return N; }


/* List of variables */
int lcd_effect_time = 0;
int optionPos = 1;
int optionMenu = 0;
int maxMenu = 2;
bool optionHome = true;

char *ledOptions[] = {
    " Lights options ",
    "1. Pozitii         ", 
    "2. Faza lunga      ", 
    "3. Avarii          ", 
    "4. Girofar         ", 
};
char *carOptions[] = {
    " Choose a car   ",
    "1. Car 14,4v       ", 
    "2. Truck           ", 
};

int get_MaxOptions(){
  int num;
  if (optionMenu == 0){
    num = ArraySize(ledOptions);
  }else{
    num = ArraySize(carOptions);
  }
  return num - 1;
}
