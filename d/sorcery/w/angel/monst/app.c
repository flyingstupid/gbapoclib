#include <mudlib.h>
inherit MONSTER;

void reset(status arg) {
  object ob;
  ::reset(arg);

  if(arg) return;

  if(!random(3)) {
    set_alignment(-100);
    ob = clone_object("d/coronos/w/angel/city/obj/brobe");
    move_object(ob, this_object());
    init_command("wear robe");
  }
  else if(!random(3)) {
    set_alignment(100);
    ob = clone_object("d/coronos/w/angel/city/obj/wrobe");
    move_object(ob, this_object());
    init_command("wear robe");
  }
  else {
    set_alignment(10);
    ob = clone_object("d/coronos/w/angel/city/obj/grobe");
    move_object(ob, this_object());
    init_command("wear robe");
  }

  set_name("apprentice");
  set_gender(1);
  set_short("A young apprentice");
  set_race("human");
  set_long(
	"This is a young apprentice, searching for a master to teach \n"+
	"him some magic. He looks very inexperienced, and very naove.\n");
  set_level(6);
  load_chat(3, ({
	"Apprentice asks: Where can I find the Masters?\n",
	"Apprentice asks: Are you a Master?\n",
	"Apprentice looks around, quite lost.\n",
	"Apprentice smiles worriedly.\n",
	"Apprentice looks very nervous.\n",
  }));
  load_a_chat(4, ({
	"Apprentice exclaims: Dont hurt me!\n",
	"Apprentice cries out in pain.\n",
	"Apprentice bursts into tears.\n",
  }));
}
	
