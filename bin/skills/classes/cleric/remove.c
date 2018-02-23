/* Remove Curse.    Serepion Nov 1993 */  
#define NAME (string)caster->query_name()


status remove(string targ, mixed alt_type, string class) {
  int dam, i;
  string file;

  if(!targ || !(targ == "curse" || sscanf(targ,"curse %s",targ))) {
    notify_fail("remove curse?\n");
    return 0;
  }
  if(targ == "curse") targ = 0;
  if(!alt_type) alt_type = "combat_sphere";
  if(!class) class = "cleric";
  dam = (objectp(alt_type))
      ? (int)alt_type->query_cast_level() /* wands */
      : (int)call_other(this_player(),"query_"+alt_type);

  file = file_name(this_object());
  sscanf(file,"%s#%d", file, i);

  this_player()->load_spell(({
       "target",            targ,
       "name",              "Remove Curse",
       "sphere",            alt_type, 
       "cost",              2,
       "level",             2,
       "spell object",      file,
       "cast time",         1,
        "class",            class,
       "passive",
  }));
  return 1;
}

/***********************************************************************/
/* when cloned */

status cast_spell(object caster,object target,object prev,int dmg) {
  object curse;

  curse = present("Curse", target);
  if(curse) {
    if(target == caster) {
      write("You remove the curse on you.\n");  
      say(NAME +" removes the curse on "+caster->query_objective()+
        "self.\n");  
    }
    else {
      write("You remove the curse in "+target->query_name()+".\n"); 

      say(NAME +" removes the curses on "+ target->query_name()+".\n");
    }  
    curse->dispel_magic();  
  }
  else {
    if(target != caster)  
      write((string)target->query_name() +" is not cursed.\n");  
    else  
      write("You are not cursed.\n");  
  }
  destruct(this_object());
  return 1;
}

