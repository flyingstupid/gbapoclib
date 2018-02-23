#include "/players/relgar/private/mydefs.h"
inherit "/d/tempus/w/relgar/main.c";

reset(arg){
    reset_doors(arg);
    load_door(({
	"destination","d/tempus/w/relgar/tapod",
	"direction","south door",
	"closed","locked",
	"long",
	"The door is made of almost perfectly smooth stone that is set into the\n"+
	"wall to the south. Only the lock and handle potrude.\n",
	"lock id",
	"bronze lock",
	"key id",
	"bronze key",
	"door number",1,
	"lock difficulty",12,
      }));
    set_short("The private chambers of the cathedral");
    set_light(2);
    set_long(
      "        You have made your way into the private worship chambers of the\n"+
      "priests of the Tanar'ri. The strangest thing is happening in this room.\n"+
      "there is blood covering the floor however, you notice that it constantly\n"+
      "drips up towards the ceiling. It seems to be slowly running up the walls\n"+
      "on all sides of you. To the west you notice a pair of double doors with\n"+
      "huge statues flanking it on both sides.\n"
    );
    set_items(({
	"blood#floor#ceiling",
	"You notice that the blood on the floor constantly drips up towards the \n"+
	"ceiling in the strangest fashion. It is somewhat unnerving.\n",
	"walls#eastern wall#northern wall#southern wall",
	"The blood from the floor seems to be slowly running up the walls.\n",
	"doors#double doors#statues#huge statues#statue",
	"They can be better seen to the west of you.\n",
      }));
    set_exits(({
	"d/tempus/w/relgar/temp2","west",
      }));
} /* end of reset */
