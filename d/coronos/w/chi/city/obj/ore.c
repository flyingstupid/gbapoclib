#include <mudlib.h>
inherit TREASURE;

void reset(status arg) {
   ::reset(arg);

   if(arg) return;
   set_name("ore");
   set_short("iron ore");
   set_long("A dark and heavy piece of iron ore.\n");
   set_weight(5);
   set_value(80);
}
