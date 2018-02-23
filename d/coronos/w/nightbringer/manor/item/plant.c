#include <mudlib.h>
inherit TREASURE;

void reset(status arg) {
   ::reset(arg);

   if(arg) return;
   set_name("potted plant");
   set_alias("plant");
   set_short("a potted plant");
   set_long("It is a small potted plant that is setting on top of a table.\n");
   set_weight(2);
   set_value(4);
}
