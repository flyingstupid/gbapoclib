#include <mudlib.h>
inherit TREASURE;

void reset(status arg) {
   ::reset(arg);

   if(arg) return;
   set_name("fat");
   set_short("animal fat");
   set_long("A light colored blob of gelatinized lard.\n");
   set_weight(3);
   set_value(40);
}
