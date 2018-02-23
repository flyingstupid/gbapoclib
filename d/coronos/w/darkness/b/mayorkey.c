/* mayorkey.c == Darkness */

#include <mudlib.h>
inherit TREASURE;
 
void reset (status arg){
  if(arg) return;
  
  set_weight(1);
  set_value(50+random(100));
  set_sell_destruct(1);
  set_name("mayor's key");
  set_alias("key");
  set_short("a shiny iron key");
  set_long("This is a small key made of iron.  The shield of the\n"+
           "city of Ille Coronos is engraved upon it.\n");
}
