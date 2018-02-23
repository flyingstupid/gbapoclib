#include <mudlib.h>
inherit "objects/torch";

void reset(status arg) {

  string *arr, COLOR, AROMA;
  arr = ({"black", "white",  "brown", "brindle", "silver", "grey",
          "auburn", "beige", "pale", "golden", "tan", "sable",
          "ivory", "rust red", "ash", "tawny", "ebony", "dark grey",
          "smoke grey", "light brown", "smoke grey", "mist black",
          "ghost grey", "charcoal grey", "pearl grey",
        });
  COLOR = arr[random(sizeof(arr))];

  arr = ({"vanilla", "cinnamon", "mint", "raspberry", "cranberry",
          "blueberry", "patchouli", "citrus", "jasmine", "peach",
          "black cherry", "pine", "cedarwood", "rosewood", "musk",
          "sandlewood", "lavender", "sage", "apple", "melon",
        });
  AROMA = arr[random(sizeof(arr))];

  if(arg) return;

  set_name("wolf candle");
  set_short("a wolf candle");
  set_alias("candle");
  set_plural("wolf candles");
  set_long(
    "This is a large, "+COLOR+" candle that has been formed into           \n"+
    "the shape of a wolf.  Great detail has been put into this sculpture   \n"+
    "made of wax.   The wolf sits serenely on its hind legs, with its     \n"+
    "tail curled around its paws.  With its ears perked forward and pink   \n"+
    "tongue lolling, it seems to be watching the world with its laughing,  \n"+
    "yellow eyes.  Hard to believe that this sculpture is merley a candle, \n"+
    "the likeness to the feral beast is so real.  \n");

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

