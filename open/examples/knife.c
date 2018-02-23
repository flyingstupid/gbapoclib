#include <mudlib.h>
inherit WEAPON;

void reset(status arg) {
  if(arg) return;
  set_name("knife");
  set_length(12);
  set_short("A small knife");
  set_info(
	"From the blood stains on the knife, it seems to have \n"+
	"been used to kill something... ..possibly a jumbuck.\n");
  set_long(
	"Although small, this knife has a keen edge on it.\n"+
	"There is some blood on the blade.\n");
  set_type("slash");
  set_wc(6);
  set_weight(4);
  set_value(90);
}
