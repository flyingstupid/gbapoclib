#include <mudlib.h>
#include "paths.h"
inherit ROOM;

#define SPRITE 3

object *sprites;


void reset(status arg) {
  int i;
  object spr;
  
  if(!present("tree")) {
    spr = clone_object("obj/skills/tree");
    move_object(spr, this_object());
    spr -> grow();
  }

  if(!arg) {
    set_short("the elfin forest");
    set_long(
"The small animal trail that leads through the forest of Scianthian divides  \n"+
"here, and leads in many directions.  The trees stand magnificently all around\n"+
"you, and the birds tweet happily.\n");

    set_exits(({
	PATH+"new1", "south",
	"d/coronos/w/angel/farms/plains/ranger", "north",
	PATH+"new3", "northeast",
	PATH+"new13", "northwest",
	PATH+"new8", "west",
    }));
    set_listen("You can hear birds twittering. . . \n");
    set_items(({
        "trees",  "large healthy oak trees",
    }));
    set_weather(2,4,3);
  }
  if(!sprites) sprites = allocate(SPRITE);
  for(i = 0; i < SPRITE; i++) {
    if(!sprites[i]) {
      spr = clone_object(MONSTER);
      spr->set_name("sprite");
      spr->set_short("a tree sprite");
      spr->set_plural("tree sprites");
      spr->set_long(
"A small little tree sprite.  It looks almost like an elf, but smaller.\n");
      spr->set_level(1);
      spr->set_ac(3);
      spr->set_wc(5);
      spr->set_gender(2);
      spr->add_mone(30);
      spr->set_al(100);
      spr->set_race("sprite");
      spr->load_chat(10,({ "Sprite bounces around.\n",
          "Sprite dances around.\n",
      }));
      spr->load_a_chat(10,({ "Sprite bursts out in tears.\n",
          "Sprite cries out for help!\n",
      }));
      move_object(spr, this_object());
      sprites[i] = spr;
    }
  }
}
