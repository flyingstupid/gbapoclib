/** sticks to snakes **/

status sts(string targ, mixed alt_type, string class) {
  int time;

  if(!alt_type) alt_type = "nature_sphere";
  if(!class) class = "cleric";
  time = (objectp(alt_type))
       ? (int)alt_type->query_cast_level()  /* wands */
       : (int)call_other(this_player(),"query_"+alt_type);

  this_player()->load_spell(({
  "target",            environment(this_player()),
  "name",              "Sticks to Snakes",
  "sphere",            alt_type, 
  "cost",              11,
  "damage",            time,
  "level",             11,
  "class", class,
  "cast time",         1,
  "spell object",      "obj/skills/snakes",
  "passive",
  "component",         "stick#timber#branch#torch",
  }));
  return 1;
}

