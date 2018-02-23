/** Poison **/

status poison(string targ, mixed alt_type, string class) {
  int level;

  if(!alt_type) alt_type = "necromancy_sphere";
  if(!class) class = "cleric";
  level = (objectp(alt_type))
        ? (int)alt_type->query_cast_level()  /* wands */
        : (int)call_other(this_player(),"query_"+alt_type);

  this_player()->load_spell(({
  "target",            targ,
  "name",              "Poison",
  "sphere",            alt_type, 
  "cost",              14,
  "damage",            level,
  "immune",            "poison",
  "spell object",      "objects/poison",
  "level",             14,
  "class", class,
  "cast time",         1,
  }));
  return 1;
}


