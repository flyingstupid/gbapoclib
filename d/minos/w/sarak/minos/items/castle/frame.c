#include <mudlib.h>
#include "/d/minos/w/sarak/include/minos.h"
inherit "/inherit/treasure";


void reset(status arg){
clone_object(TREASURE);
set_name("frame");
set_alias("gold frame");
set_short("A piece of Gold frame");
set_long("This partcular piece of gold frame was taken from the minotaur castle.\n"); 
set_value(500);
set_weight(2);
} 

