/* Enchanted Weapon */

#define NAME "@@query_name:$this_player()$@@"

status enchanted(string targ, mixed alt_type, string class) {
  int level, i;
  string file;

  if(!targ || sscanf(targ,"weapon %s",targ) != 1) {
    notify_fail("enchanted weapon <weapon>?\n");
    return 0;
  }

  if(!alt_type) alt_type = "alteration"; 
  if(!class) class = "mage";
  level = (objectp(alt_type))
        ? (int)alt_type->query_cast_level()
        : (int)call_other(this_player(),"query_"+ alt_type);

  file = file_name(this_object());
  sscanf(file,"%s#%d", file, i);

  this_player()->load_spell(({
  "target",            targ,
  "name",              "Enchanted Weapon",
  "sphere",            alt_type, 
  "cost",              12,
  "damage",            level,
  "level",             12,
  "class", class,
  "cast time",         2,
  "spell object",      file,
  "casting msg",       "You chant very slowly...\n",
  "casting msg room",  NAME +" chants slowly...\n", 
  "passive",
  }));
  return 1;
}


status cast_spell(object caster,object target,object prev,int level) {
  string sh, prep;
  
  if(living(target)) {
    write(target->query_name() +" is not dead!\n");
    destruct(this_object());
    return 1;
  }
  if(!target->query_wc()) {
    write(target->query_name() +" is not a weapon!\n");
    destruct(this_object());
    return 1;
  }
  if(target->query_enchanted()) {
    write(target->query_name() +" is already enchanted!\n");
    destruct(this_object());
    return 1;
  }
  write("You hold "+ target->query_name() +" firmly in your hands "+
        "and enchant it.\n");
  say(caster->query_name()+" grasps "+ target->query_name() +" in "+ 
      caster->query_possessive() +" hands and enchants it.\n");

  target->set_enchanted(1);
  target->set_modified(1);

  /* set new short */

/*
  sh = (string)target->short();
  changed into query_short to make sure "wielded in .. hand" was excluded from the new short by Hippo
*/
  sh = (string)call_other(target,"query_short");
  if(sscanf(sh,"%s %s", prep, sh)) {
    prep = lower_case(prep);
    sh = (prep == "a" || prep == "the" || prep == "an")
          ? sh
          : capitalize(prep) +" "+ sh;
  }
  target->set_short("Enchanted "+ sh);

  /* set weapon class */

  level = random((level/3)+1)+1;
  if(level > 4) level = 4;
  target->set_wc((int)target->query_wc()+level);

  caster->recalc_wc();
  destruct(this_object());
  return 1;
}

