#include <mudlib.h>
inherit "objects/torch";

void reset(status arg) {

  string *arr, COLOR, AROMA;
  arr = ({"ebony", "ivory", "dark blue", "silver", "deep violet",
          "dark green", "amber", "gold", "blood red",  "off white",
         });
  COLOR = arr[random(sizeof(arr))];

  arr = ({"vanilla", "black cherry", "pine", "raspberry", "cranberry",
          "blueberry", "cederwood", "citrus", "musk", "peach", "sage",
          "rosewood", "sandlewood", "mulberry", "patchouli", "jasmine",
        });
  AROMA = arr[random(sizeof(arr))];

  if(arg) return;

  set_name("unicorn candle");
  set_short("a unicorn candle");
  set_alias("candle");
  set_plural("unicorn candles");
  set_long(
    "This is a large, "+COLOR+" candle that has been formed into     \n"+
    "the shape of a unicorn.  Delicate and intricate details have    \n"+
    "been painstakingly carved into the wax to capture this great    \n"+
    "and magical beast in a playfull pose.  He sits lightly on his   \n"+
    "hind hocks, front legs pawing at the air.  His head is tossed,  \n"+
    "his mane flying and his tail is curved up against his back.     \n");

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
/* Newstar/Darkness */

