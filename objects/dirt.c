#include <mudlib.h>
inherit TREASURE;

void reset(status arg) {
  if(arg) return;
  set_name("dirt");
  set_alias("mound");
  set_short("");
  set_long(
	"It looks as though something has been freshly burried here.\n");
}

status get() { return 0; } /* can't get it! */
status drop(status wiz){ return 1; } /* cant drop it! */

void extra_long(status wiz) {
  write("There is a small mound of dirt in "+environment()->short()+".\n");
}

