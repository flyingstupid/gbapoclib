#include <mudlib.h>
inherit UNDEAD;
void reset(status arg) {
 
    ::reset(arg);
    if(arg) return;
 
set_name("skeleton");
set_gender(0);
set_race("undead");
set_al(-2000);
set_aggressive(1);
set_short("A Skeleton");
set_long("Once dead and left to rot away, has become \n"+
         "animated through black arts and evil.\n"+
         "Fear is death's companion, and these monstrous\n"+
         "creations on necrotic sorcery are horrid.\n"+
         "This monstrousity is without flesh, yet moves\n"+
         "with a speed that is deceptive.\n");
set_level(2);
set_multi_attack(2);
}
