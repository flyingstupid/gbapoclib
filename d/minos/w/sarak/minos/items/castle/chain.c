#include <mudlib.h>
#include "/d/minos/w/sarak/include/minos.h"
inherit "/inherit/treasure";


void reset(status arg){
clone_object(TREASURE);
set_name("chain");
set_alias("Gold Chain");
set_short("A gold chandelier chain");
set_long("This chain was taken from a broken chandelier in the Minotaur Castle\n");
set_value(750);
set_weight(1);
set_plural("gold chains");
} 

