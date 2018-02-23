/* WIGHT
   AUTHOR: NIGHTBRINGER
   06-01-97 */


#include <mudlib.h>
inherit UNDEAD;
void reset(status arg) {

    ::reset(arg);
    if(arg) return;

    set_name("Wight");
    set_race("undead");
    set_gender(0);
    set_short("A Wight");
    set_long(
      "From a distance, this creature is easily mistaken\n"+
      "for any number of humaniod races. Once you get closer\n"+
      "to it, its true nature is revealed. It is a nightmarish\n"+
      "reflection of its former self, with cruel, burning eyes\n"+
      "set in mummified flesh over a twisted skeleton with hands\n"+
      "that end in sharp claws.\n");
set_level(21);
    set_wc(30);
    set_ac(17);
    set_al(-2000);
    set_chill_chance(50);
    set_chill_dam(10 + random(10));
    set_drain_chance(5);
    load_a_chat(20, ({"The wight moans."}));
    set_aggressive(1);
    add_spell_immunity("non enchanted weapons", "death");

}
