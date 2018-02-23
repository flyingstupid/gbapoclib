#include <mudlib.h>
inherit UNDEAD;
void reset(status arg) {

    ::reset(arg);
    if(arg) return;

    set_name("Spectre");
    set_alias("spirit");
    set_gender(0);
    set_race("undead");
    set_al(-2000);
    set_short("A spectral spirit");
    set_long(
      "A spectre is an almost transparent undead monster\n"+
      "that is sometimes mistaken for a ghost or smiliar \n"+
      "undead.  Spectre's typically inhabit desolate and \n"+
      "forgotten places.  Life and the living causes the\n"+
      "spectre to lament its unlife.  They can be a very\n"+
      "foe to defeat.\n");
    set_level(18);
    set_hp(800);
    set_ac(15); /* its ethereal damn it */
    set_drain_chance(5);
}
