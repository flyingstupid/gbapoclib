#include <mudlib.h>
inherit TREASURE;

void reset(status arg) {
   ::reset(arg);

   if(arg) return;
   set_name("picture");
   set_alias("portrait");
   set_short("a portrait");
   set_long("It is a large oil painting of a human woman wearing a fine.\n"+
            "evening gown\n");
   set_weight(10);
   set_value(100);
}
