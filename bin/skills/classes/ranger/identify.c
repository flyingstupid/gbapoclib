#define MAX_LEVEL_FOR_ANIMALS 5

status identify(string str, mixed alt_type) {
  string *races;
  object ob;

  races = ({
    "orc", "gnoll", "giant", "half giant", 
    "elf", "high elf", "wood elf", "dark elf", "drow", "wild elf",
    "grey elf", "gray elf", "nixie", "pixie", "sprite", "faerie",
    "centaur", "dryad", "treant", "ent", 
    "unicorn",
    "ogre", "dune stalker", "flind", "norker", "tasloi", 
    "cyclops", "gibberling", "grimlock", "meazel", "ogre mage",
    "ogrillon", "quaggoth",
    "bear", "bird", "boar", "pig", 
    "goblin", "hobgoblin", "troll", "ettin", 
  });

  if(!str) {
    notify_fail("Identify who?\n");
    return 0;
  }
  if(!ob = present(str, environment(this_player()))) {
    notify_fail("There is no such creature here.\n");
    return 0;
  }

  if(!living(ob)) {
    notify_fail("But "+ob->short()+" is not living!\n");
    return 0;
  }

  if((int)ob->query_level() > MAX_LEVEL_FOR_ANIMALS) {
    if(member_array(ob->query_race(), races) == -1) {
      notify_fail("What would a ranger know about such a creature!\n");
      return 0;
    }
  }

  alt_type = "divination_sphere";

  /* this is so they can cast the spell whenever they like! */
  /* ..not that they actually have or use this sphere!      */
  this_player()->set_divination_sphere(5);
  this_player()->adj_divination_sphere_points(10);

  return (status)"/bin/skills/classes/cleric/identify"->identify(str,alt_type);
}
