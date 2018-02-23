/* ebl - everburning log */

#define NAME "@@query_name:$this_player()$@@"  /* gives greater flexibilty */

status ebl(string targ, mixed alt_type, string class) {
  string file;
  int i;
  if(!alt_type) alt_type = "nature_sphere";
  if(!class) class = "cleric";

  file = file_name(this_object());
  sscanf(file, "%s#%d", file, i);

  this_player()->load_spell(({
  "target",            this_player(),
  "name",              "Ever Burning Log",
  "sphere",            alt_type, 
  "cost",              1,
  "level",             1, /* 16 - 4*4 cast time */
  "class",             class,
  "cast time",         5,
  "spell object",      file,
  "component",         "stick#branch#torch",
  "passive",
  "casting msg",       "You focus upon the timber.\n",
  "casting msg room",  NAME +" chants slowly.\n",
  }));
  return 1;
}

status cast_spell(object caster,object target,object prev,int level) {
  object ob;
  int i;

  ob = clone_object("obj/skills/sp_torch");
  move_object(ob, target);
  command("light stick "+i, target);
  destruct(this_object());
  return 1;
}

