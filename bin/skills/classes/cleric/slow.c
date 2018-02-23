/* Slow Poison. */  

status slow(string targ, mixed alt_type, string class) {
  int i;
  string file;

  if(!targ || !(targ == "poison" || sscanf(targ,"poison %s",targ))) {
    notify_fail("slow poison?\n");
    return 0;
  }
  if(targ == "poison") targ = 0;

  if(!alt_type) alt_type = "necromancy_sphere";
  if(!class) class = "cleric";

  file = file_name(this_object());
  sscanf(file,"%s#%d",file,i);

  this_player()->load_spell(({
       "target",            targ,
       "name",              "Slow Poison",
       "sphere",            alt_type, 
       "cost",              3,
       "level",             3,
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
    tell_object(target,"You feel the poison slow in your body.\n");
    if(target == caster) {
      say(caster->query_name() +" slows the poison in "+
          caster->query_objective() +"self.\n");  
    }
    else {
      write("You slow the poison in "+ target->query_name() +"'s system.\n"); 
      say(caster +" slows the poison in "+
target->query_name()+".\n",target);
    }  
    poison->set_poison_rate((int)poison->query_poison_rate()/2);
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

