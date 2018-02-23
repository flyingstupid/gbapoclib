/* KEY.c, taken from 'scandles downfall' */

#include <ansi.h>
#include <mudlib.h>
inherit TREASURE;

int number;
string name;

void reset(status arg) {
  if(arg) return;
  set_name("key");
  set_alt_name("skyes tavern and inn");
  set_weight(1);
  set_short("A small key");
  set_long(
"A small silver key with the name Skye written on it.\n");
}

void long(status wiz) {
  ::long(wiz);
  write("It has the number "+number+" in the center.\n");
}


string query_auto_load() {
  return "players/russkie/tavern/obj/key:"+ query_alias(1) +", "+number;
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
