/** Friends - uses charisma shadow **/

status friends(string targ, mixed alt_type, string class) {
  int time, i;
  string file;

  if(!alt_type) alt_type = "alteration";
  if(!class) class = "mage";
  time = (objectp(alt_type))
      ? (int)alt_type->query_cast_level()  /* wands */
      : (int)call_other(this_player(),"query_"+alt_type);

  file = file_name(this_object());
  sscanf(file,"%s#%d", file, i);

  this_player()->load_spell(({
  "target",            this_player(),
  "name",              "Friends",
  "sphere",            alt_type, 
  "cost",              12,
  "damage",            time,
  "level",             12,
  "class", class,
  "cast time",         1,
  "spell object",      file,
  "passive",

/* other spell options...
  "area",
  "casting msg",       0,
  "casting msg room",  0,
  "passive",
  "component",        0,
 */
  }));
  return 1;
}

status cast_spell(object caster,object target,object prev,int dam) {
  object charisma;

  if(target->query_charisma_object()) {
    tell_object(caster,"They are already charismatic.\n");
  }
  else {
    charisma = clone_object("obj/shadows/charisma");
    charisma->shadow_charisma(target,(int)target->query_charisma()+5);
    charisma->adj_time(dam * 60);
    tell_object(target,"You feel charismatic!!\n");
    if(caster != target) {
      tell_object(caster,target->query_name() +" looks charismatic!!\n");
    }
  }
  destruct(this_object());
  return 1;
}

