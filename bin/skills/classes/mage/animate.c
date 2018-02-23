/** animate skeleton, animate zombie **/
#define NAME "@@query_name:$this_player()$@@"  /* gives greater flexibilty */
#define TARG "@@query_name:$this_object()$@@"
status animate(string targ, mixed alt_type, string class) {
  int type, level, spell_level;
  string spell_name, component;
  string file;

  switch(targ) {
    case "skeleton":
      spell_name = "Animate Skeleton";
      component = "skeleton";
      spell_level = 11;
      file = "obj/skills/skeleton";
    break;

    case "zombie":
      spell_name = "Animate Zombie";
      component = "corpse";
      spell_level = 14;
      file = "obj/skills/zombie";
    break;
  
    default:
      notify_fail("animate skeleton, animate zombie?\n");
      return 0;
    break;
  }

  if(!alt_type) alt_type = "necromancy";
  if(!class) class = "mage";
  level = (objectp(alt_type)) ? 
	(int)alt_type->query_cast_level()  /* wands */
      : (int)call_other(this_player(),"query_"+alt_type);

  this_player()->load_spell(({
	"target",	environment(this_player()),
	"name",         spell_name,
	"sphere",       alt_type, 
	"cost",		spell_level,
	"damage",       level,
	"level",        spell_level,
        "class",        class,
	"cast time",    2,
	"casting msg", "You pour unlife into the "+ component +".\n",
	"casting msg room",  "You feel a chill as "+ NAME +" pours unlife into "+
			     "the "+ component +".\n",
	"spell object",	file,
	"component",	component,
	"passive",
  }));
  return 1;
}

