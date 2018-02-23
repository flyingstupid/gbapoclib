#include <mudlib.h>

inherit TREASURE;

void reset(status arg) {
  if(arg) return;
  set_name("fleece");
  set_short("some fleece");
  set_long(
	"Some lovely golden fleece.\n");
  set_weight(1);
  set_value(100);
  set_smell("The fleece smells very woolly.\n");
}
