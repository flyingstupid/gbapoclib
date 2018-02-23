/* Scry */

status scry(string str, mixed alt_type, string class) {
  int level;

  if(!alt_type) alt_type = "divination";
  if(!class) class = "mage";
  level = (objectp(alt_type))
        ? (int)alt_type->query_cast_level() 
        : (int)call_other(this_player(),"query_"+alt_type);

  this_player()->load_spell(({
  "target",            environment(this_player()),
  "name",              "Scry",
  "sphere",            alt_type, 
  "cost",              12,
  "damage",            level,
  "immune",            "divination",
  "level",             12,
  "class", class,
  "cast time",         1,
  "spell object",      "obj/skills/scryer",
  "argument",          str,
   "component",        "gem#gemstone",
  "passive",
  }));
  return 1;
}

