#include <mudlib.h>
inherit FOOD;

void reset(status arg) {
  if (arg) {
  return;
}

::reset(arg);
set_name("gnomeclaire");
set_alias("chocolate");
set_plural("gnomeclaires");
set_short("a chocolate gnomeclaire");
set_long(
"This is a famous gnomeclaire made of chocolate.  It's a light,\n"+
"crumbly cake-like dessert, rolled up with chocolate syrup oozing\n"+
"out of its center.\n");

set_smell("The rich smell of chocolate makes the stomach rumble.\n");
set_consumer_msg("You bite into the gnomeclaire and taste its delicious chocolate center.\n");
set_strength(20);
set_value(100);
set_weight(1);
}
