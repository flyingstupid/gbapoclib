#include <mudlib.h>
#include "paths.h"

inherit ROOM;

object giant;

void reset(status arg) {
  if(!giant || !living(giant)) {
    giant = clone_object(MONSTER);
    giant->set_name("giant");
    giant->set_level(15);
    giant->set_hp(350);
    giant->add_money(250);
    giant->set_short("a hill giant");
    giant->set_long(
    "He stands over 10 feet tall and looks very angry. He appears\n"+
    "to be guarding something.\n");
    giant->set_gender(1);
    giant->set_race("giant");
    giant->set_aggressive(1);
    move_object(giant, this_object());
  }

  if(arg) return;

  set_short("a grassy plain");

  set_long(
  "A large open grassy plain extends to the east, while this area\n"+
  "is rocky and barren. There are several sets of gigantic-sized \n"+
  "footprints here, moving toward the west.\n");


  set_weather(1,0,0);

  set_exits(({
	PATH+"giant_path", "east",
	PATH+"giant_conf", "west",
  }));

  set_items(({
	"footprints",
	"You summise that there are roughly three sets of \n"+
	"gigantic-sized footprints",


	"grass#grassy plain#plain",
	"Dry grass as tall as a halfling extends across a wide open plain",
	
	"cloud#clouds", 
	"They are fluffy clouds. One looks like a tankard of ale\n",
 }));


  set_smell("You can smell giants to the east\n");
  set_listen("You hear a loud noises from the west\n");
} 


