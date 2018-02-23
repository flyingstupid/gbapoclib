#define NAME "@@query_name:$this_player()$@@"

status flame(string targ, mixed alt_type, string class) {

  int level, i;
  string file;

  if(!targ || sscanf(targ,"blade %s",targ) != 1) {

    notify_fail("flame blade <weapon>?\n");
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
  "name",              "Flame Blade",
  "sphere",            alt_type,
  "cost",              24,
  "damage",            level,
  "level",             24,
  "cast time",         4,
  "spell object",      file,
  "component",         "torch", 
  "class",             class,
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
  if(target->query_type() == "crush") {                                       
    write(target->query_name() +" does not have a blade!\n"+                  
          "You drop "+ target->query_name() +" just as the flames touch "+    
          "your hand!\n");                                                    
    say(caster->query_name() +" drops "+ target->query_name() +" as flames "+ 
    "swarm up towards "+ caster->query_possessive() +" hands!\n");            
    caster->hit_player(random(10));
    say(target->query_name() +" is utterly consumed by the magical flames!\n");
    write(target->query_name() +" is utterly consumed by the magical flames!\n");
    destruct(target);
    return 1;                                                                 
  }                                                                           
  if(target->query_enchanted()) {
    write(target->query_name() +" is already enchanted!\n"+
                "Magic flares from your hands and burns you!\n");
    say("Magic flames from "+ target->query_name() +" flare up and burn "+
        caster->query_name() +"!\n");
    caster->hit_player(10 + random(20));
    destruct(this_object());
    return 1;
  }
  write("You hold "+ target->query_name() +" firmly in your hands "+
        "and enchant it.\n"+
        "Flames rises from the "+target->query_name()+" as you finish "+
        "the spell.\n");
  say(caster->query_name()+" grasps "+ target->query_name() +" in "+ 
      caster->query_possessive() +" hands and enchants it.\n"+
      "Flames rise from the "+ target->query_name() +" as "+ 
      caster->query_name()+" finishes the enchantment.\n");
  target->set_enchanted(1);
  target->set_modified(1);
  target->set_light(1);
  sh = (string)target->short();
  if(sscanf(sh,"%s %s", prep, sh)) {
    prep = lower_case(prep);
    sh = (prep == "a" || prep == "the" || prep == "an")
          ? sh
          : capitalize(prep) +" "+ sh;
  }
  level = random((level/3)+1)+1;
  if(level > 6) level = 6;
  target->set_wc((int)target->query_wc()+level);
  target->set_short("Flames surround the blade of "+ prep +" "+ sh);
  target->set_long((string)target->query_long() +"Flames dance and sway along the weapon's length.\n");
  target->recalc_light();
  caster->recalc_wc();
  destruct(this_object());
  return 1;
}


