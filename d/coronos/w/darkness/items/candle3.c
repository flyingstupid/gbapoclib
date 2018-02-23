#include <mudlib.h>
inherit "objects/torch";

void reset(status arg) {

  string *arr, COLOR, AROMA;
  arr = ({"black", "dark blue", "dark red", "deep violet",
          "dark green", "white", 
         });
  COLOR = arr[random(sizeof(arr))];

  arr = ({"vanilla", "cinnamon", "mint", "raspberry", "cranberry",
          "blueberry", "potpouri", "lemon", "musk",
          "sweet", "pine", "cedar", "rosewood",
        });
  AROMA = arr[random(sizeof(arr))];

  if(arg) return;

  set_name("dragon candle");
  set_short("a dragon candle");
  set_alias("candle");
  set_plural("dragon candles");
  set_long(
    "This is a large, "+COLOR+" candle that has been formed into the\n"+
    "shape of a dragon.  The delicate work that has been put into \n"+
    "this wax sculpture captures the essence of the great beast.  Her\n"+
    "wings are outstretched, and her jaws are open wide as if she were\n"+
    "breathing fire.  Her clawed feet are firmly planted on the ground\n"+
    "where she stands.  This is truly a work of art.\n");

  set_extra_info("Looking at the candle, you think it "+
                 "will last for another @@query_approx_time:"+
                 file_name(this_object()) +"@@.\n");

  set_smell("The candle gives off a "+AROMA+" scent.  The aroma is\n"+
            "very strong and distinct.\n");

  set_weight(4);
  set_max_fuel(1000);
  fuel = 1000;
  light_intensity = 1;
}

int query_value() { return 500; }  
