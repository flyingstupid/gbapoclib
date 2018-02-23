#include <mudlib.h>
#include "/d/minos/w/sarak/include/minos.h"
inherit "/inherit/treasure";

void reset(status arg){
  clone_object(TREASURE);
  set_name("skeleton");
  set_short("A charred Skeleton");
  set_long("This is the skeleton of some unfortunate minotaur.\n");
  set_value(0);
  set_weight(2);
} 

