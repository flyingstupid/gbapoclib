/* scare spell */

status scare(mixed target, mixed alt_type, string class) {
  int level, i;
  string file;

  if(!alt_type) alt_type = "charm";
  if(!class) class = "mage";
  level = (objectp(alt_type))
       ? (int)alt_type->query_cast_level()
       : (int)this_player()->query(alt_type);

  file = file_name(this_object());
  sscanf(file,"%s#%d",file,i);

  this_player()->load_spell(({
  "target",            target,
  "name",              "Scare",
  "sphere",            alt_type, 
  "cost",              14,
  "damage",            level,
  "immune",            "fear",
  "level",             14,
  "class", class,
  "cast time",         2,
  "spell object",      file,
  "casting msg",       "You start to feel scared!\n",
  "casting msg room",  "You start to feel scared!\n",

/* other spell options...
  "area",
  "msg target",        0,
  "msg room",          0,
  "msg caster",        0,
  "passive",
  "component",         0,
 */
  }));
  return 1;
}

/***********************************************************************/
/* when cloned to target */


status cast_spell(object caster,object target,object prev,int dmg) {
  if(!target->query_made_my_save()) {
    target->random_move();
  }
  else {
    tell_room(environment(target),"Nothing Happens....\n");
  }
  destruct(this_object());
  return 1;
}

status id(string str) {
  return str == "spell";
}

