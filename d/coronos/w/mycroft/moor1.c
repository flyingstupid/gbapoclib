#include <mudlib.h>
#define MONST  "//players/mycroft/open/monsters/"
#define NAME  "(string)this_player()->query_name()
inherit ROOM;


void reset(status arg) {
if(!present("mandrake")){
move_object(clone_object(MONST+"mandrake"),this_object());
}
  if (arg) return;
set_short("Mispec Moor");
set_long("You are standingin the middle of Mispec Moor,\n"+
"a soggy, alkali bog.  This appears to be the stinking den\n"+
"of hideous mandrakes.  The ground is littered with the remains\n"+
"recent feastings. The area to the south seems a bit more treacherous.\n");
set_weather(-2,2,1);
set_exits (({"d/coronos/w/mycroft/moorbog1.c","south",
"players/mycroft/open/moor2.c","east"}));
set_extra_objects(({"mandrake","//players/mycroft/open/monsters/mandrake.c"}));

}

