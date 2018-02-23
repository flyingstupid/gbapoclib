/* DISINTEGRATE */

#define NON_LIVING_SAVE 15

#define NAME "@@query_name:$this_player()$@@"  /* gives greater flexibilty */
#define TARG "@@query_name:$this_object()$@@"


status disintegrate(mixed targ, mixed alt_type, string class) {
  int cl, i;
  string file;

  if(!alt_type) alt_type = "alteration";
  if(!class) class = "mage";
  cl = (objectp(alt_type))
     ? (int)alt_type->query_cast_level()
     : (int)this_player()->query(alt_type);

  file = file_name(this_object());
  sscanf(file, "%s#%d", file, i);

  this_player()->load_spell(({
  "target",            targ,
  "name",              "Disintegrate",
  "sphere",            alt_type, 
  "cost",              26,
  "damage",            cl, /* used as a save flag */
  "level",             26, /* 30 instant kill - 4 casting time */
  "class", class,
  "cast time",         3,
  "spell object",      file,
  "casting msg",       "A dull grey aura starts forming around your hands.\n",
  "casting msg room",  "A dull grey aura starts forming around "+NAME+
                       "'s hands.\n",
  }));
  return 1;
}


/* call when this object is cloned to target */

status cast_spell(object caster,object target,object prev,int dmg) {
  write("A dark grey beam springs from your hands.\n");
  say("A dark grey beam springs from "+(string)caster->query_name()+
      "'s Hands.\n");
  if(!living(target)) {
    if(random(15) < random(dmg)) {
      call_out("disintergrate_ob",1,target);
    }
    else {
      tell_object(caster,"Nothing Happens...\n");
      say("Nothing Happens...\n", caster);
    }
    return 1;
  }           
  if(!(target->query_npc() || caster->query_npc())) {
    tell_room(environment(target), "Nothing happens...\n");
    return 1;
  }
  if(!target->query_made_my_save()) {
    call_out("disintergrate_ob", 1, target);
  }
  else if(!dmg) {
    write("You see the beam hit "+(string)target->query_name()+".\n"+
          capitalize((string)target->query_pronoun())+
          " resist the beam.\n");
    tell_object(target,"You resist the disintergration beam.\n");
    say("The beam has no effect on "+(string)target->query_name()+".\n");
    destruct(this_object());
  }
  else {
    write("You see "+(string)target->query_name()+" dodge the beam!\n");
    tell_object(target,"You dodge the beam!!\n");
    say((string)target->query_name()+" dodges the beam.\n");
    destruct(this_object()); /* get rid of cloned object */
  }
  return 1; /* don't do damage */
}


static void disintergrate_ob(object target) {
  string name;
  object env;

  env = environment();
  name = (string)target->query_name();
  target->death();
  if(env)
    tell_object(env,"You see the beam strike "+name+" turn to dust.\n");
  say("The dark grey beam turns "+name+" to dust.\n");
  if(target) {
    destruct(target);
  }
  else {
    target = environment();
    if(target->id("corpse")) destruct(target); /* death() has moved us */
  }
  env = environment();
  move_object(clone_object("obj/skills/dust"), env);
  destruct(this_object());
}

status id(string str) { return (str == "spell"); }

