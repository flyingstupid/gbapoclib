#include <mudlib.h>
inherit UNDEAD;
void reset(status arg) {

    ::reset(arg);
    if(arg) return;

    set_name("Mummy");
    set_gender(0);
    set_race("undead");
    set_al(-2000);
    set_short("A Mummy");
    set_long(
      "This is a corpse of a once long dead hero\n"+
      "or ruler that has been swathed in bandages\n"+
      "and special ointments.  However due to a \n"+
      "longing to hold on to life, the mummy has \n"+
      "retained some semblance of life.  Due to it's\n"+
      "entombed state it has developed an extreme \n"+
      "hatred and envey for the living.\n");
    set_level(7);
    set_ac(15); /* mummies should be hit by magical weapons<and they do half> */
    set_disease_chance(10); /* mummies cause disease */
    set_aggressive(1);
}
