#include <mudlib.h>
inherit MONSTER;

void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  set_short("a small bat");
  set_name("bat");
  set_race("bat");
  set_long(
"This small bat is hairy and ugly and smells terrible. It might \n"+
"look harmless by itself, but when it attacks in a bunch, it can\n"+
"be deadly.\n");

  set_gender(random(2) + 1);

  set_aggressive(random(2)); /* 1 or 0 */
  set_level(1);

  set_attack_msg(({
	"missed", "as it swoops around",
	"annoys", "",
	"scrapes", "with its claws",
	"flaps at", "with its wings",
	"beat", "with its wings",
	"bites", "with its sharp teeth",
	"attacks", "ferociously",
 }));
  set_msgin("flaps in");
  set_msgout("swoops");
}
