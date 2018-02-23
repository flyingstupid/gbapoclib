/* KEY.c
 * This key serves as a special key to open the doors at the inn
 * at Skandles Downfall. Each key is auto loading, but will not
 * be available to the players if there is a mud reboot.
 * v2.01, (c) Angel, Feb 1995.
 */

#include <mudlib.h>
inherit TREASURE;

int number;
string name;

void reset(status arg) {
  if(arg) return;
  set_name("key");
  set_alt_name("skandles downfall");
  set_weight(1);
  set_short("A small key");
  set_long(
     "This is a small tarnished bronze key, with the \n"+
     "name 'Skandle's Downfall' across its middle.\n");
}

void long(status wiz) {
  ::long(wiz);
  write("It has the number "+number+" in the centre.\n");
}


string query_auto_load() {
  return "room/city/pub/key:"+ query_alias(1) +", "+number;
}

void init_arg(string str) {
  sscanf(str, "%s, %d", name, number);
  this_object()->set_alias(name);  /* who owns the key */
  this_object()->set_alt_name(number);
}

int set_number(int i)    { 
  this_object()->set_alt_name(i);
  return number = i;
}
status drop(status wiz) {  return 1;           }
