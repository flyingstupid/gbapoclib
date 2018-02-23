/* TABLE
   AUTHOR:NIGHTBRINGER
   04-23-97 */

#include <mudlib.h>
inherit TREASURE;

void reset(status arg) {
   ::reset(arg);


   if(arg) return;
   set_name("table");
   set_short("a small table");
   set_long("It is a small oak table. It is finely crafted and looks valuable. A plant sits on top.\n");
   set_weight(25);
   set_value(880);
}
