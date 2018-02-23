/* death curse */
  
status death(string spell_type, string class, mixed alt_type) {
  string file;
  int i, cl;
   object targ;
 targ == this_player();

   if(spell_type != "curse") {
    notify_fail("death curse?\n");
    return 0;
  }

  if(!alt_type) alt_type = "necromancy_sphere";
  if(!class) class = "cleric";
  cl = (objectp(alt_type))
     ? (int)alt_type->query_cast_level()
     : (int)this_player()->query(alt_type);
  
  this_player()->load_spell(({
  "target",    targ,
  "name",              "Death Curse",
  "sphere",            alt_type, 
  "cost",              30,
  "level",             30,
  "class",             class,
  "cast time",         1,
  "spell object",      "obj/skills/d_curse",
  "damage",            cl,  /* as time */
  "component",         "corpse#skeleton",
  "passive",
  }));
  return 1;
}

