/* RAT.C
   AUTHOR:NIGHTBRINGER
   04-23-97 */

#include <mudlib.h>
#include <ansi.h>
inherit MONSTER;

void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  set_short("a small rat");
  set_name("rat");
  set_race("rat");
  set_long(
"  The rat is about eight inches long and has a tail that equals his \n"+
"  body in length. It has a lean body, pointed nose, and long ears. It's\n"+
"  fur is a chocolate brown, with grey patches and a white belly. It has\n"+
"  sharp looking teeth.\n");

  set_gender(random(2) + 1);

  set_level(1);
  set_wc(5);
  set_ac(3);

  set_attack_msg(({
               "nudges softly",    "with its nose",
               "bruises softly",   "with its nose",
               "grazes lightly",   "with its tail",
               "whips lamely",     "with its tail",
               "nips softly",      "with its teeth",
               "bites severly",    "with its teeth",
               "crushes",          "with its jaws",
          }));

}
