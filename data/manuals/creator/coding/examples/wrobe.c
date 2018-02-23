#include <mudlib.h>
inherit CLOTHING;

void reset(status arg) {
  if(arg) return;
  set_short("a white wizards robe");
  set_name("robe");
  set_long(
	"This is a simple white robe designed in the fashion befitting \n"+
	"a wizard. It is fairly long, but has splits up the sides, and \n"+
	"is obviously meant to be worn over the top of standard clothing.\n"+
	"There are a few silvery runes in cotton along the hem and sleaves\n"+
	"for decoration and effect.\n");
  set_weight(1);
  set_value(100);
}
