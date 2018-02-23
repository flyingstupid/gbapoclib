#include <mudlib.h>
inherit FOOD;

void reset(status arg) {
  if (arg) {
  return;
}

::reset(arg);
set_name("drow forest cake");
set_alias("cake");
set_short("a small drow forest cake");
set_plural("small drow forest cakes");
set_long(
"This is a small drow forest cake.  It consists of two rich layers of\n"+
"dark chocolate cake.  Between those two layers, is a layer of whipped\n"+
"cream and cherries.  Decorating the top is more cream and cherries.\n");

set_smell("The cherries, cream, and chocolate smell delicious!\n");
set_consumer_msg("You bite into the cake, getting whipped cream on your nose and chin.\n");

set_strength(15);
set_value(75);
set_weight(1);
}

