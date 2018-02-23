#include <mudlib.h>
inherit CLOTHING;

void reset(status arg) {
  if(arg) return;
  set_short("a black wizards robe");
  set_name("robe");
  set_long(
	"A dark black robe of the design worn by the wizards of the council\n"+
	"of high sorcery. While obviously not one of the Prismatic Robes   \n"+
	"its deisgn is highly fashionable among today's mages.\n");
  set_weight(1);
  set_value(100);
}
