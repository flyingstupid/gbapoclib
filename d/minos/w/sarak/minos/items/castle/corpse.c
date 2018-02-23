#include <mudlib.h>
#include "/d/minos/w/sarak/include/minos.h"
inherit "/inherit/treasure";



void reset(status arg){
clone_object(TREASURE);
set_name("corpse");
set_short("Corpse of murdered Minotaur");
set_long("This is the corpse of a minotaur. It looks like someone has\n"+
         "sucked the blood right out of it!! You cringe at the thought\n"+
         "of VAMPIRES!!!!\n");
set_value(0);
set_weight(2);
} 

