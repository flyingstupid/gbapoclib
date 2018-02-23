/** Restore **/

#define NAME "@@query_name:$this_player()$@@"  /* gives greater flexibilty */

status restore(string targ, mixed alt_type, string class) {
  int i;
  string file;

  if(!alt_type) alt_type = "necromancy_sphere";
  if(!class) class = "cleric";
  file = file_name(this_object());
  sscanf(file,"%s#%d",file,i);

  if(!targ) targ = (string)this_player()->query_name();
  this_player()->load_spell(({
  "target",            targ,
  "name",              "Restore",
  "sphere",            alt_type, 
  "cost",              21,
  "level",             21,
  "class", class,
  "cast time",         3,
  "casting msg", ({
    "You call upon the gods to restore life to "+ capitalize(targ) +".\n",
    "You feel life essences restoring "+ capitalize(targ) +".\n",
  }),
  "casting room", ({
    NAME +" calls upon the gods to restore life to "+ capitalize(targ) +".\n",
    "You feel the life essences restoring "+ capitalize(targ) +".\n",
  }),
  "passive",
  "spell object", file,
  }));
  return 1;
}


status cast_spell(object caster,object target,object prev,int dmg) {
  if(!target->query_level_drained()) {
    if(target != caster) {
      write(target->query_name() +" is not level drained.\n");
    }
    else {
      write("You have not been level drained.\n");
    }
  }
  else {
    tell_object(target,"You have been restored a level.\n");
    if(caster != target) {
      write("You restore "+ target->query_name() +" a level.\n");
    }
    say(caster->query_name() +" has restored a level to "+
        target->query_name() +".\n");
    caster->add_exp((int)target->query_level() * 150);
    target->restore_level();
  }
  destruct(this_object());
  return 1;
}

status id(string str) {
  return str == "spell"
      || str == "raise";
}

