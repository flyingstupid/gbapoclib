/* Remote Viewing for Tech men




*/

status remoteview(string str, mixed alt_type, string class) {
  int level;

  if(!alt_type) alt_type = "sensing";
  if(!class) class = "techman";
  level = (objectp(alt_type))
        ? (int)alt_type->query_cast_level() 
        : (int)call_other(this_player(),"query_"+alt_type);

  this_player()->load_spell(({
  "target",            environment(this_player()),
  "name",              "Remote View",
  "sphere",            alt_type, 
  "cost",              0,
  "damage",            level,
  "immune",            "divination",
  "level",             12,
  "class", class,
  "cast time",         1,
  "spell object",      "obj/skills/remoteviewer",
  "argument",          str,
  // "component",        "gem#gemstone",
  "passive",
  }));
  return 1;
}

