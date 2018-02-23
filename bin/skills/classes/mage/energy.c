/* energy dran .. drakken */
 
#define NAME "@@query_name:$this_player()$@@"  /* gives greater flexibilty */
#define TARG "@@query_name:$this_object()$@@"
 
status energy(string target, mixed alt_type, string class) {
  int dam, i;
  string file;
 
  if(!target || !(target == "drain" || sscanf(target,"drain %s",target))) {
    notify_fail("energy drain?\n");
    return 0;
  }
  if(target == "drain") target = 0;
  if(!alt_type) alt_type = "necromancy";
  if(!class) class = "mage";
  dam = (objectp(alt_type))
      ? (int)alt_type->query_cast_level() 
      : (int)call_other(this_player(),"query_"+alt_type);
  dam *= (random(6) + 1);
  if(dam > 130) dam = 130;  
 
  file = file_name(this_object());
  sscanf(file,"%s#%d",file,i);
 
  this_player()->load_spell(({
  "target",            target,
  "name",              "Energy Drain",
  "sphere",            alt_type, 
  "cost",     25,
  "damage",            dam,
  "immune",            "negative",
  "level",             25,
  "class", class,
  "cast time",         3,
  "spell object",      file,
  "casting msg",       ({ 
                         "A sudden surge of energy flows throughout your "+
                          "body.\n",
                          "Your hand starts to glow with a faint red aura.\n",
                       }),
  "casting msg room",  ({ 
                          NAME +"'s hand starts to glow with a faint red "+
                          "aura.\n",
                       }),
  "msg caster",        TARG +" starts to glow with a faint red aura as you "+
                       "release\na stunning charge of arcane power into his"+
                       " body.\n",
  "msg target",        "You feel a surge of arcane power through your body.\n",    
  "msg room",          TARG +" starts to glow with a faint red aura.\n", }));
  return 1;
}
 
 
/******************************************************************/
/* when cloned to target */
 
status cast_spell(object caster,object target,object prev,int dmg){
  if(!target->query_made_my_save()) { /* did not save */
    if(target != caster) {
      tell_object(caster,(string)target->query_name()+
                  " starts to glow with a faint red aura as you release \n"+
                  "a stunning charge of arcane power into his body.\n");
    }
    tell_object(target, "You feel a surge of arcane power flow through \n"+
                        "your body as your life force is drained.\n");
    say((string)target->query_name()+
         " glows with a faint red aura, then turns pale white.\n", target);
    target->heal_mage(-dmg);
    target->heal_cleric(-dmg);
    target->drain_level();
    destruct(this_object());
    return 1;  /* do not do damage */
  }
  destruct(this_object());
  return 0;  /* do damage */
}

