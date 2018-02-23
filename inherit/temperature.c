/***************************************************************************/
/* PERSONAL TEMPERATURE 
 *
 * v1.0 Angel 2002
 *
 * This object, inherited by others, works inconjunction with the weather
 * system. Objects lend a certain amount of cold protection to the wearer
 * and hence increase body temperature. In cold environments, this is a
 * potential life saver. In hot areas, this can kill.
 *
 * The creator manual indicates how much a worn object should add to 
 * personal temperature. 
 *
 * Temperature is in the Kelvin range, so ensure the amounts added or 
 * set are in accordance to that international scale. 
 */


#include <mudlib.h>

/***************************************************************************/
/* std fns */

int temperature;

int add_temperature(int kelvin)   { return temperature += kelvin; }
int set_temperature(int kelvin)   { return temperature  = kelvin; }

int query_temperature()           { return temperature;           }


/***************************************************************************/
/* handy conversion fns for those note used to the kelvin scale */

int fahrenheit_to_centigrade(float i) {
  return to_int(0.555 * (i - 32));
}

int centigrade_to_fahrenheit(float i) {
  return to_int((1.8 * i) + 32);
}

int centigrade_to_kelvin(float i) {
  return to_int(i + 273);
}

int kelvin_to_centigrade(float i) {
  return to_int(i - 273);
}


