/* atone someone */

#define NAME "@@query_name:$this_player()$@@"

status atone(string targ, mixed alt_type, string class) { 
  int i;
  string file;
 
  if(!alt_type) alt_type = "divination_sphere"; 
  if(!class)    class    = "cleric";
  file = file_name(this_object());
  sscanf(file,"%s#%d",file,i); 

  this_player()->load_spell(({
  "target",       targ,
  "name",         "Atone",
  "sphere",       alt_type,
  "cost",         15,
  "level",        15,
  "class",             class,
  "cast time",    2,
  "spell object", file,
  "casting msg",  "You begin to pray for atonement.\n",
  "casting msg room", NAME +" begins to pray a silent prayer.\n",
  "passive",
  }));
  return 1;
}

status cast_spell(object caster,object target,object prev,int dmg) {
  if(!living(target)) { 
    write("You cannot atone something that is not living!\n"); 
  } 
  else if(target->query_npc()) { 
    write("You cannot atone "+ target->query_name() +"!\n");
  } 
  else if((int)target->query_level() >= (int)caster->query_level()) { 
     write("You can only atone those of lower level than yourself.\n"); 
  } 

  else {
    target->set_al_title((string)caster->query_al_title()); 
    target->set_alignment((int)caster->query_alignment()); 
    write("You place your hands upon "+ target->query_name() +"\n"+
          "You atone "+ target->query_name() +", turning "+
           target->query_objective() +" to the true way.\n");
    say(caster->query_name() +" places "+ caster->query_possessive() 
      +" hands upon "+ target->query_name() +"\n", target);
    tell_object(target, caster->query_name() +" places "+
      caster->query_possessive() +" hands upon you and atones you\n");
  }
  destruct(this_object());
  return 1; 
} 


