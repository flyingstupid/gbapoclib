#include <mudlib.h>
inherit MONSTER;


reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("beggar");
  set_short("A small beggar man");
  set_long(
	"A filthy beggar. He looks disease ridden and dirty.\n");
  set_level(1);
  set_gender(1);
  set_hp(40);
  set_ac(3);
  set_wc(5);
  load_chat(10, ({ "Beggar asks: Could you spare some money?\n",
	"Beggar says: Please, could I have some money.\n",
	"Beggar asks: Please, I am really thirsty?\n",
	"Beggar asks: Please, could you spare some money for an old man?\n"
  }));
  load_a_chat(10, ({ "Beggar exclaims: Ouch!\n",
	"Beggar exclaims: Don't do that!\n",
	"Beggar bursts into tears.\n",
	"Beggar exclaims: You're hurting me!\n",
  }));
  set_race("human");
  move_object(clone_object("room/city/monst/knife"),this_object());
  init_command("wield knife");
}

init() {
 ::init();
}

catch_tell(string str) {
 string tmp1, tmp2;
 int i;
 

  if(sscanf(str, "%s gives you %d gold coins\n", tmp1, i)) {
    if(i > 20) {
      tell_room(environment(), "Beggar exclaims: Thankyou!\n");
      dothis();
    }
    else {
      tell_room(environment(), "Beggar says: Cheap skate.\n");
    }
  }
}

dothis() {
  command("east", this_object());
  command("buy beer");
  command("drink beer");
}
