/* stoneskin */

#define NAME  "@@query_name:$this_player()$@@"

status stoneskin(string targ, mixed alt_type, string class) {
  int level, i;
  string file;

  if(!alt_type) alt_type = "abjuration";
  if(!class) class = "mage";
  level = (objectp(alt_type))
        ? (int)alt_type->query_cast_level()
        : (int)call_other(this_player(), "query_"+ alt_type);

  file = file_name(this_object());
  sscanf(file, "%s#%d", file, i);

  this_player()->load_spell(({
  "target",            this_player(),
  "name",              "Stoneskin",
  "sphere",            alt_type, 
  "cost",              14,
  "level",             14,
  "class", class,
  "damage",            level,
  "cast time",         2,
  "spell object",      file,
  "casting msg",       "You feel your skin turning brittle.\n",
  "casting msg room",  NAME +"'s skin turns to a stony colour.\n",
  "passive",
  }));
  return 1;
}


/*******************************************************************/
/* called when this is cloned to target */


status cast_spell(object caster,object target,object prev,int dmg) {
  object ob;

  if((ob = (object)target->query_stoneskin_object())) {
    destruct(ob);
  }
  write("Your skin takes on a stony quality.\n");
  clone_object("obj/shadows/stoneskin")->stoneskin(target,2+(dmg/3));
  destruct(this_object());
  return 1;
}


status id(string str) { return str == "spell"; }
