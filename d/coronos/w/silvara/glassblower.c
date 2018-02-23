#include <mudlib.h>
inherit MONSTER;

void reset(status arg) {
   if (arg) {
  return;
}

::reset(arg);
set_name("Stalor");
set_alt_name("glass blower");
set_short("Stalor, the glass blower");
set_long(
"Stalor, the glass blower, stands with stooped strong shoulders.\n"+
"His shaved head shines with sweat, and his fingernails are short and\n"+
"ragged.  His grey tunic sleeves are rolled up to his elbows, exposing\n"+
"his massive forearms.  \n");
load_chat(10, ({
   "Stalor shyly says: I do not like people to watch me blow my glass.\n"+
   "Stalor asks quietly: What if someone laughs at me?\n",
   "Stalor says: My self-esteem is as fragile as the stems of my "+
   "wine goblets.\n",
}));

load_a_chat(6, ({
  "Stalor begs: Please do not break anything, least of all me!\n",
    "Stalor crawls into a corner to hide.\n",
   "Stalor pleads: Do not laugh at me, I cannot bear it!\n",
   "Stalor screams: I shall make ye a nice pair of wine goblets if \n"+
   "ye leave me be!\n",
}));

set_attack_msg(({
  "pummels", "with his strong fists",
  "butts", "with his bald head",
  "kicks", "with his hard booted feet",
}));

set_al(0);
set_level(16);
set_gender(1);
set_race("human");
}
