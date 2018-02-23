#include <mudlib.h>
inherit CLOTHING;

void reset(status arg) {
  if(arg) return;

  set_name("hat");
  set_short("a fine leather hat");
  set_long(
	"This hat is made from fine black leather   \n"+
	"on the outside, and has soft grey felt on   \n"+
	"the inside. The brim is very wide and would \n"+
	"certainly keep out the rain.\n");
  set_value(250);
  set_weight(1);
}
