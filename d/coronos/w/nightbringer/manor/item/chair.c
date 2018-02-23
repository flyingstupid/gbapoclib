/* ROSE CAHIR
   AUTHOR:DARKBRINGER
   04-23-97 */

#include <mudlib.h>
inherit "inherit/chair";

     reset(arg) {
   ::reset(arg);
   if(arg) return;

   set_name("chair");
   set_short("a chair");
   set_long("It is a rose colored chair. It is made from cloth and\n"+
"looks  like it would be very comfortable.\n");
   set_max_sitters(1);
   set_weight(50);
   set_value(5000);
}
