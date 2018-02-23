#include <mudlib.h>
inherit TREASURE;

void reset(status arg) {
  if(arg) return;
  set_name("key");
  set_alias("silver key");
  set_short("A silver key");
  set_long(
	"It looks like a simple key, plated in silver.\n");
  set_weight(1);
  set_value(100);
  set_sell_destruct(1);
}

status drop(status quit) {
  if(quit) {
    tell_object(environment(), "The key crumbles into pieces.\n");
    destruct(this_object());
    return 1;
  }
  return 0;
}

