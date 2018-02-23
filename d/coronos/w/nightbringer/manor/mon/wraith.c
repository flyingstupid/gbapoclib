/* WRAITH
   TAKEN FROM
   D/TEMPUS/W/MIRAK/MONSTER/
   ALTERED 04-28-97 */



#include <mudlib.h>
inherit UNDEAD;
void reset(status arg) {

    ::reset(arg);
    if(arg) return;

    set_name("Wraith");
    set_race("undead");
    set_gender(0);
    set_short("A Wraith");
    set_long(
      "This is an undead being of pure hatred\n"+
      "and evil.  Its existence is only to feed\n"+
      "on the pulse of life.  It vaguely resembles\n"+
      "anything that might once have been alive.\n"+
      "The creature's tortured existance between\n"+
      "multiple plans of existence have washed away\n"+
      "any mind it once had, it is now just instinct\n"+
      "for it to kill anthing that is alive.\n");
set_level(20);
    set_wc(30);
    set_ac(17);
    set_al(-2000);
    set_chill_chance(50);
add_class("fighter");
    set_chill_dam(8 + random(8));
    set_drain_chance(5);
    set_disease_chance(5);
    load_a_chat(20, ({"The wraith moans for some flesh to eat!"}));
    set_aggressive(1);
}
