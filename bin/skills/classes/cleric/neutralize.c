/* Neutralize Poison. */  

status neutralize(string targ, mixed alt_type, string class) {
  int i;
  string file;

  if(!targ || !(targ == "poison" || sscanf(targ,"poison %s",targ))) {
    notify_fail("neutralize poison?\n");
    return 0;
  }
  if(targ == "poison") targ = 0;

  if(!alt_type) alt_type = "necromancy_sphere";
  if(!class) class = "cleric";

  file = file_name(this_object());
  sscanf(file,"%s#%d",file,i);

  this_player()->load_spell(({
       "target",            targ,
       "name",              "Neutralize Poison",
       "sphere",            alt_type, 
       "cost",              8,
       "level",             8,
  "class", class,
       "spell object",      file,
       "cast time",         1,
       "passive",
  }));
  return 1;
}

/***********************************************************************/
/* when cloned */

status cast_spell(object caster,object target,object prev,int dmg) {
  object poison;

  poison = present("Poison", target);
  if(poison) {
    tell_object(target,"You feel the poison leave your body.\n");
    if(target == caster) {
      say(caster->query_name() +" neutralizes the poison in "+
          caster->query_objective() +"self.\n");  
    }
    else {
      write("You neutralize the poison in "+ target->query_name() 
           +"'s system.\n"); 
      say(caster->query_name() +" neutralizes the poison in "+
          target->query_name()+".\n",target);
    }  
    destruct(poison);
    target->set_constitution((int)target->query_constitution());
  }
  else {
    if(target != caster)  
      write((string)target->query_name() +" is not poisoned.\n");  
    else  
      write("You are not poisoned.\n");  
  }
  destruct(this_object());
  return 1;
}

