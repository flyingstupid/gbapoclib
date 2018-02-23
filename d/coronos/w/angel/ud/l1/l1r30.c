#include <mudlib.h>
#define PATH	"d/coronos/w/angel/ud/l1"
#define MONST	"d/coronos/w/angel/ud/monst"
#define MONST	"d/coronos/w/angel/ud/monst"
#define OBJ	"d/coronos/w/angel/ud/obj"
#define TREAS	"d/coronos/w/angel/city/obj"

inherit ROOM;

 void reset(status arg) {
  int i;
  object ob;
  object chest;



    load_door(({
        "file", "d/coronos/w/angel/city/sewer/sewer8",
        "direction", "secret door",
        "long", "A small part of the wall seems to move a little, \n"+
                "leading to somewhere else within the caven system.\n",
        "secret door", 17,
        "secret door finders", ({ }),
      }));

  if(!present("faeryl")) {
    move_object(clone_object(MONST+"/drow3"), this_object());
  }
  if(!present("chest")) {
    chest = clone_object(OBJ+"/chest");
    chest -> set_weight(100000000);
    move_object(chest, this_object());
  }
  if(chest) {
    if(!present("boots", chest))
      move_object(clone_object(TREAS+"/sboots"), chest);
    if(!present("wand", chest))
      move_object(clone_object(TREAS+"/fwand"), chest);
    if(!present("sword"))
      move_object(clone_object(TREAS+"/defender"), chest);
    if(!present("bracers"))
      move_object(clone_object(TREAS+"/bracers"), chest);
  }




	
	
	if(arg) return;
	set_short("a cave");
	set_long(
"This cave looks more like an office of sorts, with a collection \n"+
"of small chairs made from wood standing around a large table.\n");
  set_smell("It smells like orcs and elves may have been here,\n"+
		"but not recently.\n");
	set_items(({
	"chairs", "The chairs look rather shabbily put together",
	"table", "It looks more like a collection of wood tied together \n"+
		 "on the top, with legs of stumps of wood",
	"stumps", "They make up the legs of the table",
	"rock#rocks", "All the rocks have a familiar shape to them. They look \n"+
									"they might have been used to fill over the cave enterance."
	}));
	set_exits(({
	PATH+"/l1r29", "east",
	}));
	set_weather(0, 1, 0);
}



