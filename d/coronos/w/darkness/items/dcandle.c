/* dark candle     darkness 1997
   The dark candle is a simple code.  It is a candle that absorbs light as it burns
   instead of emitting light,,, light -2.  It also doesn't last an incredibly long 
   amount of time and the time varies due to instable magics.  It mainly is a 'toy'
   for the players, but an ingenious player will use the candle to hide equipment, 
   rooms, exits, so on and so forth.  
*/

#include <mudlib.h>
inherit "objects/torch";

void reset(status arg) {
  int LAST;

  if(arg) return;

  LAST=2000+random(1000);
  set_name("dark candle");
  set_short("a dark candle");
  set_alias("candle");
  set_plural("dark candles");
  set_long(
    "This black candle is short, but it has a wide diameter.  Through the\n"+
    "deep color of the wax, you can see solid objects that have been mixed\n"+
    "in, like spices, leaves, roots, and many other undistinguishable\n"+
    "objects.  The wick is a dark brown, almost black, woven fiber.  It's\n"+
    "hard to tell what kind of fiber it is made from.  This candle is most\n"+
    "likely magical in nature.\n");

  set_extra_info("Looking at the candle, you think it "+
                 "will last for another @@query_approx_time:"+
                 file_name(this_object()) +"@@.\n");

  set_smell("This candle smells like it has spices and herbs in it.\n");

  set_sell_destruct(1);
  set_weight(2);     
  set_max_fuel(LAST);
  fuel = (LAST);
  light_intensity = -2;
}

int query_value() { return 1000; }  
