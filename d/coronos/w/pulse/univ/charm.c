/******************************************************************************
 * charm.c
 * Charm Lab
 * Mage University
 * 
 * Pulse,
 * October 1996
 * <john@bitsmart.com>
 */
 
#include <mudlib.h>
inherit "/d/coronos/w/solstice/univ/class/mage_gld";
 
object rag;
 
void reset(int arg) {
  if (arg) {
    return;
  }
 
  ::reset(arg);
  if (!present("amani")) {
    guild_master=clone_object("/d/coronos/w/solstice/univ/monst/amani");   
    move_object(guild_master, this_object());
    set_guild_master_name(guild_master->query_name());
    guild_master->set_heart_ob(this_object());
  }
   
  /* We will balance out the lack of weapons on Amani */
  if (!find_living("rag") || !rag) {
    rag=clone_object("/d/coronos/w/solstice/univ/monst/rag");
    move_object(rag, this_object());
  }
  
  set_long(
    "Excruciating detail has been paid towards amenities here: the windows\n"+
    "have been thrown open and are garnished with curtains of impeccable\n"+
    "taste; the floor is covered by a carpet that is soft and almost fluffy\n"+
    "to the toes.  Not that this room is lavish; it is merely one of the\n"+
    "most charming rooms Ille Coronos has to offer - decorated by a mage,\n"+
    "no less!\n"
  );
  
  set_items((  {
    "carpet#ground",
    "The carpet is like music to your feet - soft and snuggly.\n",
    
    "window#windows",
    "Sunlight streams in through the open windows.\n",
    
    "curtains",
    "The curtains seem to match the room in every detail, even the outside\n"+
    "environment.\n"
  } ));
  
  set_weather(2,3,0);
  
  set_listen("You can hear birds chirping through the open windows.\n");
  
  set_smell("Fresh, clean air fills this room.\n");
  
  set_classes(( {
    "mage", ({ "charm", })
  } ));
  
  set_exits(( {
    "/d/coronos/w/solstice/univ/hall_rt", "west",
  } ));
  
}
 
 
void monster_heart_beat()  {
  if(find_living("amani")->query_attack() && present("rag"))  {
    rag -> add_secondary_attacker(find_living("amani")->query_attack());
    
    tell_room(environment(find_living("amani")),
	      "\nAmani says: My pet doesn't like this.\n");
  }
}
 
