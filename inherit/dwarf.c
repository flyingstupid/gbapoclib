 /* Obviously, things you can't normally give out cannot
   be dested. He stops useless items cluttering up the
   mud. I may change him so you can ask him to take special
   items you can't give away to him. eg. quest items!!
                      Sarak - August 1995.                  */

#include <mudlib.h>
inherit MONSTER;

void reset(status arg) {
  ::reset(arg);
  if (arg) return;
  set_name("dwarf");
  set_short("A gully dwarf");
  set_long(
    "This old dwarf is here collecting rubbish. He doesn't care what it\n"+
    "is. He just wants it! If you have any unwanted items you have no use\n"+
    "for, perhaps you should give it to the dwarf.\n");
  set_al(1000);
  set_race("gully dwarf");
  set_gender(1);  /* Probably best to put him in a no-fight room */
  set_level(30);  /* Either that or make him some extremely stupid level. */
  set_hp(2500);
  set_wc(1);
  set_ac(1000);
  set_heart_ob(this_object());
}

void monster_heart_beat() {

  /* Simple but effective. Check the dwarf's inventory each heart beat.
     If he's got anything, dest it, and write a message to the room. */

  int i;
  object *ob;
  ob = all_inventory(this_object());
  for (i = 0; i < sizeof(ob); i++) {
    say("Gully dwarf hides some of his equipment in his stash.\n"+
        "Gully dwarf smiles and says: You'll never see that again.\n");

    if(ob[i]->query_object_type() == "Food") 
      say("Gully dwarf licks his lips and gobbles down "+ob[i]->short()+".\n");
    else if(ob[i]->query_object_type() == "Drink")
      say("Gully dwarf licks his lips and guzzles down "+ob[i]->short()+".\n");

    if(!random(10)) {
      say("Gully dwarf says: Here's a present!\n"+
        "Gully dwarf drops something on the ground.\n");
      move_object(clone_object("objects/components/gem"), environment());
    }
    destruct(ob[i]);
  }
}


