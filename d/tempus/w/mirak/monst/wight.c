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
      "This is an undead being of pure hatred\n"+
      "and evil.  Its existence is only to feed\n"+
      "on the pulse of life.  It vaguely resembles\n"+
      "anything that might once have been alive.\n"+
      "The creature's tortured existance between\n"+
      "multiple plans of existence have washed away\n"+
      "any mind it once had, it is now just instinct for \n"+
      "for it to kill anthing that is alive.\n");
set_level(8);
    set_al(-2000);
    set_drain_chance(5);
    load_a_chat(20, ({"The wight moans for some flesh to eat!"}));
    set_aggressive(1);
}
