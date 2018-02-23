/*Newstar 1997*/
#include <mudlib.h>
inherit MONSTER;
object ob1;
 
void reset(status arg) {
  if (arg) {
  return;
  }
 
  ::reset(arg);
  set_name("Candy");
  set_short("Candy from Silin");
  set_long(
     "This young half elf is Candy, the ruler of the city Silin. She is of \n"+
     "medium height and a slight build, thin and graceful.  Her long, honey \n"+
     "brown hair hangs down her back in a thick and intricate braid.  Her   \n"+
     "large, dark brown eyes glimmer with intelligence and wisdom.  She is  \n"+
     "clothed simple enough in sturdy, leather breeches, a heavy, silken    \n"+
     "tunic and strong half boots, but all are made of the finest materials.\n"+
     "Her manner is silent but strong.  She knows her way around a horse. \n");
  set_extra_info(
     "This is Candy, the young half elf that is now the ruler of the city of\n"+
     "Silin, the city that is known best for its marvelous breeds of horses.\n"+
     "Candy has become its ruler in absence of her gentle sister, Antonia.\n"+
     "She is well suited for the position, with a quiet yet confident manner\n"+
     "and feet planted firmly on the ground.\n");
  load_chat(3, ( {
    "Candy meets your eyes with a level gaze.\n",
    "Candy walks slowly around the room with her hands clasp behind her back.\n",
    "Candy smiles and nods to you.\n",
    "Candy looks around the room, taking in her surroundings.\n",
    "Candy carefully adjusts her tunic.\n",
    "Candy says 'Greetings Neighbour.'\n",
    "Candy tugs at her braid, deep in thought.\n",
    }));

  load_a_chat(40, ( {
    "Candy nimbly dodges attacks.\n",
    "Candy has no trouble landing solid kicks to the gut.\n",
    "Candy clenches her teeth and glares with digust.\n",
    "Candy yells 'You will pay for this, simpleton!'\n",
    "Candy is stronger then she looks.\n",
    }));
  load_l_chat(2,"elf", ( {
    "Horses are wonderful animals.\n",
    "Well met, Neighbour.\n",
    }));
 
 
  if(!present("gloves")) {
    move_object(clone_object(
    "/d/coronos/w/newstar/items/gloves"),this_object());
    command("wear gloves");
  }
 
  if(!present("whip")) {
    move_object(clone_object(
    "/d/coronos/w/newstar/items/whip"),this_object());
    command("wield whip");
  }
 
  add_class("fighter");
  set_al(215);
  set_level(15);
  set_gender(2);
  set_race("half elf");
  set_max_hp(350);
  set_hp(350);
  set_wc(20);
  set_ac(12);
  set_money(1450 + random(200));
  set_wander(60, 369);
  set_domain("muse");
  add_spell_immunity("charm");
}
