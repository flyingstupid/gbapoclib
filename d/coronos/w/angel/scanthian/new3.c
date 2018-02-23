#include <mudlib.h>
#include "paths.h"
inherit ROOM;

#define ENT 3

object *ents;
object ent;
object ob, quiver;

void reset(status arg) {
  int i;
  
  if(!arg) {
     set_short("the elfin forest");
     set_long(
"The forest if full of life here.  All kinds of little animals rummage\n"+
"through the forest here. You hear the sound of whistling coming from\n"+
"the distance. If You are lucky, you can find lots of little elves\n"+
"to stomp.\n");
     set_exits(({
	PATH+"new2", "southwest",
	PATH+"new6", "east",
	PATH+"new5", "north",
     }));
     set_weather(1,4,3);
  }

  if(!ob) {
    ob = clone_object(MONSTER);
    ob -> set_name("gilian");
    ob -> set_gender(2);
    ob -> set_alignment(50);
    ob -> set_short("Gilian, the ranger");
    ob -> set_plural("gilians");
    ob -> set_race("half elf");
    ob -> set_long(
	"Gilian is a beautiful half-elven ranger, taught long ago by the \n"+
	"ranger master Jack Mirrin. She is highly skilled and would prove\n"+
	"to be a formidable opponent to any neofite. Her weapon skills,  \n"+
	"however, are quite lacking.\n");
    move_object(ob, this_object());
    quiver = clone_object("objects/quiver");
    move_object(clone_object("objects/bow"), ob);
    move_object(quiver, ob);
    for(i=0; i<10; i++) {
      move_object(clone_object("objects/arrow"), quiver);
    }
    move_object(clone_object("d/coronos/w/angel/city/obj/knife"), ob);
    ob -> init_command("wield knife");
    ob -> set_level(7);
  }

  if(!ents) ents = allocate(ENT);
  for(i = 0; i < ENT; i++) {
    if(!ents[i]) {
       ent = clone_object(MONSTER);
       ent->set_name("treant");
       ent->set_short("a small treant");
       ent->set_plural("small treants");
       ent->set_long(
               "A small walking talking oak tree.\n"
               "It must be the child of a much larger ent.\n");
       ent->set_level(2);
       ent->set_ac(3);
       ent->set_wc(7);
       ent->set_race("oak tree");
       ent->add_money(60);
       move_object(ent, this_object());
       ents[i] = ent;
    } 
  }
}
