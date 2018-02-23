#include <mudlib.h>
inherit MONSTER;

void reset(status arg) {
::reset(arg);
if(arg) return;
set_name("pup");
set_alias("dingo pup");
set_short("A dingo pup");
set_long(
"A dog like animal with a soft coat. This little guy is \n"+
"only a pup and looks back at you with seemingly gentle \n"+
"and dark brown eyes. He is light brown in color and has \n"+
"a white streak on his muzzle.\n");
set_gender(1);
set_level(4);
set_race("dog");
set_wc(5);
set_ac(8);
set_hp(80);
load_chat(5, ({"Pup bats at a passing fly.\n",
"Pup's tail wags back and forth and looks at you \n"+
"with a slight tilt of his head.\n",
"Pup sits back on his haunches and looks at you.\n",
"With a short yip the pup pounces on your foot \n"+
"and playfully nips at you.\n",
}));
set_domain("garden");
load_a_chat(4,({"Pup looks up with scared little eyes. \n",
"Pup lets out a little YIP of pain.\n",
"Pup bites down on your arm arm!\n",
"Pup growls at you.\n",
}));
set_dead_ob(this_object());
}
void monster_died() {
object obj;
tell_room(environment(), "Pup yips one last time before laying down one last time.\n");
}
