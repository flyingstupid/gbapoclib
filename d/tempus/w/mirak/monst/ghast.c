#include <mudlib.h>
inherit UNDEAD;
void reset(status arg) {

    ::reset(arg);
    if(arg) return;

set_name("Ghast");
set_gender(0);
set_race("undead");
set_al(-2000);
set_short("A Ghast");
set_long(
"A ghast is in all appearences a ghoul, with minor\n"+
"exceptions.  The ghast is even quicker and deadlier \n"+
"than the normal ghoul, but they do have the same tendecies\n"+
"towards the living.\n");
set_level(4);
set_multi_attack(4);
}
