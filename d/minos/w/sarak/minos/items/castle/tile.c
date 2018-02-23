#include <mudlib.h>
#include "/d/minos/w/sarak/include/minos.h"
inherit "/inherit/treasure";

void reset(status arg){
  clone_object(TREASURE);
  set_name("tile");
  set_alias("opal");
  set_short("Opal Tile");
  set_long("This was taken from the Minotaur Castle.\n"); 
  set_value(500);
  set_weight(1);
} 

