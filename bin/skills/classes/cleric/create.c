/* create food, create water */

#define NAME "@@query_name:$this_player()$@@"  /* gives greater flexibilty */

status create(string spell_type, string class, mixed alt_type) {
  int heal;

  if(!alt_type) alt_type = "nature_sphere";
  if(!class) class = "cleric";
  heal = (objectp(alt_type))
       ? (int)alt_type->query_cast_level()
       : (int)this_player()->query(alt_type);

  switch(spell_type) {
    case "food":
      this_player()->load_spell(({
       "target",            this_player(),
       "name",              "Create Food",
       "sphere",            alt_type, 
       "damage",            heal,
       "cost",              8,
       "level",             8, /* 16 + 4 (no component) - 12 cast time */
       "class",             class,
       "cast time",         4,
	"spell object",		"obj/skills/sp_food",
       "casting msg", ({
         "You feel magical energies flow around you.\n",
         "You sense them gathering before you.\n",
         "The magic begins to coalesce before your eyes.\n",
       }),
       "casting msg room", ({ 
         "You feel magical energies flow around "+NAME+".\n",
         "You sense them gathering before "+NAME+".\n",
         "The magic coalesces before "+NAME+".\n",
       }),
       "passive",
      }));
    break;

    case "water":
      this_player()->load_spell(({
       "target",            this_player(),
       "name",              "Create Water",
       "sphere",            alt_type, 
       "damage",            heal,
       "class",             class,
       "cost",              8,
       "level",             8, /* 16 - 12 cast time + 4 since get compon. */
       "cast time",         4,
       "spell object",      "obj/skills/sp_water",
       "component",         "empty bottle#empty tankard#empty barrel#"+
                            "empty bowl#bottle#tankard#barrel#bowl",
       "passive",
       "casting msg", ({
         "You feel magical energies flow around you.\n",
         "You sense them draining the water from the air around you.\n",
         "The magic begins to coalesce before your eyes.\n",
       }),
       "casting msg room", ({ 
         "You feel magical energies flow around "+NAME+".\n",
         "You sense them draining the water from the air around "+NAME+".\n",
         "The magic coalesces before "+NAME+".\n",
       }),
      }));
    break;

    default:
      notify_fail("create water, create food?\n");
      return 0;
    break;
  }
  return 1;
}

