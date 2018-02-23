#include <mudlib.h>
#include <linewrap.h>

inherit MONSTER;

object bell;

void reset(status arg) {
  if(!present("bell")) {
    bell = clone_object("objects/bell");
    move_object(bell, this_object());
  }

  if(arg) return;

  set_name("leopold");
  set_short("Leopold, the town crier");
  set_long(
	"Leopold is tireless in his efforts to watch the city. Day in and  \n"+
	"day out he carefully rings his bell, announcing warning, the time,\n"+
	"and special occasions. \n");
  set_level(7);
  set_magic_resist(100);
  load_chat(5, ({ "Leopold says: Hello there.\n",
	"Leopold asks: How are you feeling?\n",
	"Leopold polishes his bell.\n",
	"Leopold says: Welcome to this far city.\n",
  }));

  load_a_chat(5, ({ "Leopold says: Mr. Bain will hear of this.\n",
	"Leopold bursts into tears.\n",
	"Leopold calls out for his mummy.\n",
  }));

  set_race("human");
  set_gender(1);
  add_money(100);
  set_heart_ob(this_object());
  set_wander(50, 360);
  set_domain("city");
  set_wimpy(50);
  add_class("fighter");
  add_class("cleric");
  load_spells(10, ({ "cure light wounds", "bless", "curse", }));
}

void monster_heart_beat() {
  string tmp;
  if(!environment()) return;
  if(!random(15)) {
    if(!environment()) return;
    tmp = (string)environment()->query_time();
    if(!tmp) return;
    tell_room(environment(), "Leopold exclaims:  "+tmp+" ...and all is well!\n");
  }
}

