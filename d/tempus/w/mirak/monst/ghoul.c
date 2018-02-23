#include <mudlib.h>
inherit UNDEAD;
void reset(status arg) {

    ::reset(arg);
    if(arg) return;

set_name("Ghoul");
set_gender(0);
set_race("undead");
set_al(-2000);
set_short("A Ghoul");
set_long(
"The ghoul is a zombie-like creature that is\n"+
"much quicker and ferocious in its hatred for\n"+
"the living.  Thier favorite food is a corpse of\n"+
"someone recently deceased, however they do not\n"+
"hesitate to attack the living.\n");
set_level(2);
set_multi_attack(2);
}
