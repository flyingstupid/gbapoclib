#include <mudlib.h>
inherit FOOD;

reset (status arg) {
  if (arg) {
  return;
}

::reset(arg);
set_name("cookie");
set_short("an Angel cookie");
set_plural("Angel cookies");
set_alias("cookie");
set_long(
"This is a shortbread cookie, shaped after the creator himself, Angel.\n");

set_smell("The scent of warm shortbread makes the mouth water.\n");
set_consumer_msg("You bite into the cookie, tearing off Angel's foot.\n");

set_strength(5);
set_value(10);
set_weight(1);
}
