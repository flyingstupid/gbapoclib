#include <mudlib.h>
inherit UNDEAD;
void reset(status arg) {

    ::reset(arg);
    if(arg) return;

    set_name("Zombie");
    set_gender(0);
    set_race("undead");
    set_al(-2000);
    set_short("A Zombie");
    set_long(
      "This is a creature of evil and sorcery.\n"+
      "Magic has caused this rotted corpse to \n"+
      "come back among the living.  Its flesh \n"+
      "has become sickly and has corroded away\n"+
      "from its body leaving pockets of skeletal\n"+
      "matter showing through rotted flesh.\n");
    set_level(2);
}
