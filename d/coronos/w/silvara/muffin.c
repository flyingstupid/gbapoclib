#include <mudlib.h>
inherit FOOD;

void reset (status arg) {
  if (arg) {
  return;
}

::reset(arg);
set_name("muffin");
set_short("a muffin");
set_plural("muffins");
set_long(
"This is a warm poppy-seed muffin, fresh from the oven.\n");

set_smell("The fresh scent of this warm muffin makes one drool.\n");

set_consumer_msg("You sink your teeth into the moist muffin.\n");
set_strength(10);
set_value(25);
set_weight(1);
}
