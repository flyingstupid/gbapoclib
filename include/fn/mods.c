/* Economy Daemon */

#include <economy.h>		/* fn's kept here on object type and zone mods */

int query_modifier(string type, string zone) {
  mapping map;
  int modifier;

  if(!zone) zone = "ille coronos";
  if(!type) type = "Treasure";
 
  map = get_modifiers(zone);

  if(!modifier = map[type]) modifier = 1;
  return modifier;
}


