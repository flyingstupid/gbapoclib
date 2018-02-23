#include <mudlib.h>
#include "/d/minos/w/sarak/include/minos.h"
inherit "/inherit/treasure";


void reset(status arg){
clone_object(TREASURE);
set_name("key");
set_alias("minotaur key");
set_short("Royal Guard's Key");
set_long("This key has been made from a strange type of glowing, green\n"+
         "metal. It is very heavy!\n");
set_value(100);
set_weight(2);
} 

