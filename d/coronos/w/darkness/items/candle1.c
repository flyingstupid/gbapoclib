#include <mudlib.h>
inherit "objects/torch";

int query_value() { return 4; }  

void reset(status arg) {

  string *arr, COLOR, AROMA;
  arr = ({"dark blue", "blue", "red", "crimson", "silver", "black",
          "yellow", "white", "peach", "green", "violet", "orange",
          "grey", "lavender", "maroon",
         });
  COLOR = arr[random(sizeof(arr))];

  arr = ({"vanilla", "cinnamon", "mint", "raspberry", "cranberry",
          "blueberry", "potpouri", "lemon", "musk",
          "sweet", "pine", "cedar", "rosewood",
        });
  AROMA = arr[random(sizeof(arr))];

  if(arg) return;

  set_name("small candle");
  set_short("a small candle");
  set_alias("candle");
  set_plural("small candles");
  set_long(
    "This is a small, "+COLOR+" candle.  It is well made and looks like\n"+
    "it will burn quit nicely.  These types of candles are also scented.\n");

  set_extra_info("Looking at the candle, you think it "+
                 "will last for another @@query_approx_time:"+
                 file_name(this_object()) +"@@.\n");

  set_smell("The candle gives off a "+AROMA+" scent.  The aroma is\n"+
            "very strong and distinct.\n");

  set_weight(1);
  set_max_fuel(1000);
  fuel = 1000;
  light_intensity = 1;
}
