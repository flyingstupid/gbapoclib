#define NAME	(string)this_player()->query_name()

status eat(string str) {
  object corpse, guild_object;
  int level;


  guild_object = present("werebear", this_player());

  if(!str) return 0;
  if(str != "corpse") return 0;

  if((status)guild_object->query_wereform() && 
    (corpse = present("corpse", environment(this_player())))) {


    if(!(level = (int)find_living((string)corpse->query_name(1)))) 
      level = 10;

    if(!this_player()->eat_food(level)) {
      notify_fail("You can't possibly eat this right now.\n");
      return 0;
    }

    this_player()->heal_self(level); /* not much, but it might count */

    write("You hungrilly devour the "+(string)corpse->query_race()+" corpse.\n");
    say(NAME +" hungrilly devours the "+(string)corpse->query_race()+" corpse.\n");
    destruct(corpse);
    return 1;
  }

  notify_fail("Eeewww! How disgusting!\n");
  return 0;
}


    
    
    

