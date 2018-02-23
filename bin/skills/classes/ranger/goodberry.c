/* GOODBERRY SPELL */  

status goodberry(string targ, mixed alt_type) {
  int level;

  if(!alt_type) alt_type = "nature_sphere";

  this_player()->load_spell(({
  "target",            this_player(),
  "name",              "Goodberry",
  "sphere",            alt_type, 
  "cost",              6,
  "level",             6,
  "cast time",         1,
  "passive",
  "component",         "berry",
  "spell object",	"obj/skills/berry",
  }));
  return 1;
}

