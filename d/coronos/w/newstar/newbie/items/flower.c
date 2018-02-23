#include <mudlib.h>
inherit TREASURE;

void reset(status arg) {

  string *arr, COLOR;

  arr = ({"red", "yellow", "white", "pink", "orange", "blue", "purple",
          "crimson", "violet", "light blue", "magenta", "off white",
          "fuchsia", "turquiose", "peach", "lavender", "dark red",
        });  
  COLOR = arr[random(sizeof(arr))];
  
  if(arg) return;

  set_name("wild flower");
  set_short("a wild flower");
  set_alias("flower");
  set_plural("wild flowers");
  set_long(
    "A little piece of nature's bounty.  A pretty, "+COLOR+" wild flower\n"+
    "is an example of ideal beauty and perfection, emboding simplicity  \n"+
    "and symmetry in its highest forms.  With a long, dark green stem   \n"+
    "sprouting small leaves and soft, rounded petals it looks delicate\n"+
    "and fragile, but in truth it can survive almost anywhere and thrive\n"+
    "in abundance in almost any climate.                                \n");

  set_smell("The little wild flower gives off a pleasingly sweet and\n"+
            "pungent armoa that lingers in your memories.           \n");

  set_weight(1);
  set_value(0);
  set_sell_destruct(1);
}

/* Newstar */
