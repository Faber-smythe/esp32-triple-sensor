/* Individual LEDs following layout of DVIC CLIMATE SENSOR CIRCUIT */
const int thermo_1 = 26;
const int thermo_2 = 25;
const int thermo_3 = 33;
const int light_1 = 27;
const int light_2 = 14;
const int light_3 = 12;
const int humid_1 = 13;
const int humid_2 = 15;
const int humid_3 = 4;
/* All LEDs */
const int leds[] = {thermo_1, thermo_2, thermo_3, light_1, light_2, light_3, humid_1, humid_2, humid_3};
/* LEDs as columns */
const int thermo[] = {thermo_1, thermo_2, thermo_3};
const int light[] = {light_1, light_2, light_3};
const int humid[] = {humid_1, humid_2, humid_3};
/* LEDs as  rows */
const int first[] = {thermo_1, light_1, humid_1};
const int second[] = {thermo_2, light_2, humid_2};
const int third[] = {thermo_3, light_3, humid_3};

/* ============================================ */
     
/* Set all LEDs to LOW */
void allOff(){
  for (int i=0; i<sizeof leds; i++) {digitalWrite(leds[i], LOW);}
}
/* Set all LEDs to HIGH */
void allOn(){
  for (int i=0; i<sizeof leds; i++) {digitalWrite(leds[i], HIGH);}
}
/* Set a specific LED off */
void oneOff(int myPin){
  allOn();
  digitalWrite(myPin, LOW);
}
/* Set a specific LED on */
void oneOn(int myPin){
  allOff();
  digitalWrite(myPin, HIGH);
}

/*
 * Currently stuck, can't use the Pins array below, they seem to be larger than expected, and overlaping eachother 
 * Setting Pins individually instead
 */
void LEDThermoLevel(int level){
  /* All off first */
  digitalWrite(thermo_1, LOW);
  digitalWrite(thermo_2, LOW);
  digitalWrite(thermo_3, LOW);
  /* Switch on the right level */
  digitalWrite(thermo[level-1], HIGH);
}
void LEDLightLevel(int level){
  /* All off first */
  digitalWrite(light_1, LOW);
  digitalWrite(light_2, LOW);
  digitalWrite(light_3, LOW);
  if(level == 4){
    digitalWrite(light_1, HIGH);
    digitalWrite(light_2, HIGH);
    digitalWrite(light_3, HIGH);
  }else{
    /* Switch on the right level */
    digitalWrite(light[level-1], HIGH);
  }
}
void LEDHumidLevel(int level){
  /* All off first */
  digitalWrite(humid_1, LOW);
  digitalWrite(humid_2, LOW);
  digitalWrite(humid_3, LOW);
  /* Switch on the right level */
  digitalWrite(humid[level-1], HIGH);
}

/* Short global flashing when Wifi connection has been established */
void ledLoaded(){
    delay(500);
    allOn(); delay(50);
    allOff(); delay(50);
    allOn(); delay(50);
    allOff(); delay(50);
    allOn(); delay(50);
    allOff(); delay(50);
    allOn(); delay(50);
    allOff(); delay(50);
}
