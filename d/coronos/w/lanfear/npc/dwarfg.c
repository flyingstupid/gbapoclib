#include <mudlib.h>
#include "/players/terral/inherit/path.h"
inherit MONSTER;

reset(arg){
  object axe;

  ::reset(arg);
  if(arg)return;
  if(!present("axe")) {
  axe=clone_object(DWARF"/weapons/baxe");
  move_object(axe, this_object());
  command("wield axe");
  }
  set_name("dwarf");
  set_gender(1);
  set_alias("guard");
  set_short("a dwarf guard");
  set_long(
  "Watching you warily this middle aged dwarven guard\n"+
  "stands ready. His armor and axe are worn but polished\n"+
  "showing long use in the hands of one experienced.\n");
  set_race("dwarf");
  set_level(15);
  }
