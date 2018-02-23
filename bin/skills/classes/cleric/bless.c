/* Bless */

inherit "obj/skills/sp_weap";
inherit "obj/skills/sp_arm";
  
status bless(string targ, mixed alt_type, string class) {
  string file;
  int i, cl;

  if(!alt_type) alt_type = "combat_sphere";
  if(!class) class = "cleric";
  cl = (objectp(alt_type))
     ? (int)alt_type->query_cast_level()
     : (int)this_player()->query(alt_type);

  file = file_name(this_object());
  sscanf(file,"%s#%d",file,i);
  
  this_player()->load_spell(({
  "target",            targ,
  "name",              "Bless",
  "sphere",            alt_type, 
  "cost",              1,
  "level",             1,
  "class",             class,
  "cast time",         1,
  "spell object",      file,
  "damage",            cl,  /* as time */
  "passive",
  }));
  return 1;
}


/*********************************************************************/
/* when cloned to player */


status cast_spell(object caster,object target,object prev,int dmg) {
  object bless;

  bless = present("bless", target);
  if(bless) {
      if(target != caster) {
        tell_object(caster,"You extend the time of the Blessing upon "+
                    (string)target->query_name()+".\n");
      }
      else {
        write("You extend the time of your Bless spell.\n");
      }
      bless->adj_time(dmg*60);
      destruct(this_object());
      return 1;
  }
  if(caster == target) {
    write("You are blessed by the gods.\n");
    say(caster->query_name() + " blesses "+
      caster->query_objective() +"self.\n", caster);
  }
  else {
    write("You reach out your hands and lay them on "+ target->query_name() +  
             ",\nblessing "+ target->query_objective() +" in the name of "+  
             "the Gods.\n");
  
    say(caster->query_name() +" reaches out and lays hands upon "+ 
        target->query_name() +",\nblessing "+ target->query_objective() +" "+  
               " in the name of the Gods.\n", target);
  
    tell_object(target, caster->query_name() 
            +" reaches out and lays hands upon you,\n"
            +"blessing you in the name of the Gods.\n");  
  }
  set_name("bless");
  set_alt_extra_long("You are blessed!\n");
  set_extra_long("@@query_name:$environment()$@@ is blessed!.\n");
  set_wc_bonus(1);
  set_ac_bonus(1);
  adj_time(dmg * 60);
  target->recalc_ac();
  target->recalc_wc();
  return 1; /* don't do damage */
}

