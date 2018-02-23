#include <mudlib.h>
inherit MONSTER;

void reset(status arg) {
    ::reset(arg);
    if(arg) {
	return;
    }
    set_name("rat");
    set_short("large black rat");
    set_long(
      "This is a large black rat not uncommon to dungeons."+
      " For some reason the\n"+"anti-rat wards do not work in this"+
      " wing of the  dungeon.\n\n"
    );
    set_al(-50);
    set_race("rat");
    set_wander(25, 120);
    set_gender(1);
    load_chat(10, ({ 
	"Rat squeaks!\n",
	"Rat nibbles on somthing.\n",
	"A rat crawls over your foot.\n",
      }));
    set_level(2);

    set_magic_resist(25 + random(50));
    set_heart_ob(this_object());

}
