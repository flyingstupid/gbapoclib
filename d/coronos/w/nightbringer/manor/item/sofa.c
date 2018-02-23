/* AUTHOR:DARKBRINGER
   04-23-97 */

#include <mudlib.h>
inherit "inherit/chair";

     reset(arg) {
   ::reset(arg);
   if(arg) return;

   set_name("sofa");
   set_short("a sofa");
   set_long("It is a rose colored sofa. It is made from cloth and \n"+
                "looks it would be very comfortable.\n");
   set_max_sitters(3);
   set_weight(10000);
   set_value(10000);
}
