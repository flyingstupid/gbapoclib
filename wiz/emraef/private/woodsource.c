#include <mudlib.h>
#include "/wiz/emraef/open/scav/scavpaths.h" 

inherit GATHER_SOURCE;



void reset(status arg) {
  if(arg) return;
  set_name("wood_source");
  set_short("A source of wood.");

  set_long(
"This fallen tree is a sorce of wood. Perhaps you \n"+
"should <gather> it.\n");

  set_alias("wood source");

  set_gather_object( "/wiz/emraef/open/scav/wood.c" );
}


