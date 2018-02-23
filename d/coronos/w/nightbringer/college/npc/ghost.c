/* GHOST
   AUTHOR:NIGHBRINGER
   04-28-97 */


#include <mudlib.h>
inherit UNDEAD;
void reset(status arg) {

    ::reset(arg);
    if(arg) return;

set_name("Ghost");
set_gender(0);
set_race("undead");
set_al(-2000);
set_short("A Ghost");
set_long(
"A ghost is the undead spirit of whatevever is was in mortal\n"+
"life. It was either a creature who was so evil in life or \n"+
"whose death was so unusually emotional that they have been\n"+
"been cursed with the gift of undead status. Thus, they roam\n"+
"about at night or in places of darkness. These spirits hate\n"+
"goodness and life, hungering to draw the living essences from\n"+
"the living.\n");

set_level(40);
set_ac(17);
set_wc(30);
add_class("cleric");
add_class("mage");
add_class("fighter");
set_drain_chance(10);
set_disease_chance(10);
load_spells(20,({"scare", "cure medium wounds", }));
set_aggressive(1);
add_spell_immunity("non enchanted weapons", "death");

}
