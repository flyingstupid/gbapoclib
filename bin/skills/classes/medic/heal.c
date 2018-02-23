/* Heal */  


int heal;
object kit;
status heal(string spell_type, mixed alt_type, string class) {
  string file, spell_name;
  string targ, castmsg;
  int skill = this_player()->query_mhealing();
  int i, spell_level; 


  if(!spell_type) {
    notify_fail("heal wounds, heal blindness,\n"+
      "heal deafness, heal disease.\n");
    return 0;
  }
  
  kit = present("medic_kit",this_player());
  if(!kit) {
  write("You need your medic's kit!\n");
  return 1;
  }
  
  
    sscanf(spell_type,"%s wounds", spell_type);
  sscanf(spell_type,"%s %s", spell_type, targ);

  switch(spell_type) {
    case "wounds":
      spell_name = "heal Wounds";
      heal =  (skill/2) * (random(4)+skill);
      castmsg ="You load your hypogun with a little glass vial..\n";
      spell_level = 1;
    break;

    case "deafness":
      spell_name = "heal Deafness";
      spell_level = 5;
    break;

    case "blindness":
      spell_name = "heal Blindness";
      spell_level = 10;
    break;

    case "disease":
      spell_name = "heal Disease";
      spell_level = 15;
    break;

    default:
      notify_fail("heal wounds, heal blindness,\n"+
        "heal deafness, heal disease.\n");
      return 0;
    break;
  }
  if(!alt_type) alt_type = "mhealing";
  if(!class) class = "medic";
  file = file_name(this_object());
  sscanf(file,"%s#%d",file,i);
  
  this_player()->load_spell(({
  "target",            targ,
  "name",              spell_name,
  "sphere",            alt_type, 
  "cost",              0,
  "level",             spell_level,
  "cast time",         2,
  "spell object",      file,
  "class",             class,
  "casting msg",       castmsg,
  "damage",            heal,
  "passive",
  }));
  return 1;
}


/*********************************************************************/
/* when cloned to player */


status cast_spell(object caster,object target,object prev,int heal)
 {
  object ob;
 
  
  
  switch((string)caster->query_spell_name()) {
    case "heal Deafness":
      if(ob = present("Deafness", target)) {
        tell_object(target,"You can hear!\n");
        if(target != caster) {
          write("You heal "+ target->query_name() +" of Deafness.\n");
        }
        say(target->query_name() +" starts rejoicing.\n", target);
        destruct(ob);
      }
      else {
        if(target == caster) {
          write("You are not deaf.\n");
        }
        else {
          write(target->query_name() +" is not deaf.\n");
        }
      }
      
    break;

    case "heal Blindness":
      if(ob = present("Blindness", target)) {
        tell_object(target,"You can see!\n");
        if(target != caster) {
          write("You heal "+ target->query_name() +" of Blindness.\n");
        }
        say(target->query_name() +" starts rejoicing.\n", target);
        destruct(ob);
      }
      else {
        if(target == caster) {
          write("You are not Blind.\n");
        }
        else {
          write(target->query_name() +" is not Blind.\n");
        }
      }
    break;

    case "heal Disease":
      if(ob = present("Disease", target)) {
      
        if(kit->query_antibotics() > 0)
        {
            kit->set_antibotics(kit->query_antibotics()-1);
            tell_object(target,"You feel better!\n");
            if(target != caster) 
                {
                    write("You inject antibotics into "+ target->query_name() +", curing their disease.\n");
                }
            say(target->query_name() +" looks much healthier.\n", target);
            destruct(ob);
        }
        else
        {
            write("You need antibotics to treat diseases!\n");
        }
      }
      else {
        if(target == caster) {
          write("You are not sick.\n");
        }
        else {
          write(target->query_name() +" is not sick.\n");
        }
      }
    break;

    default:
    
       kit->set_healingserum(kit->query_healingserum()-1);
       target->adj_hp(heal);  
      if(target != caster) {
        write("You inject "+ target->query_name() +" with healing serum!\n");
        say(caster->query_name() +" injects "+ caster->query_possessive() 
           +" hypogun into "+ target->query_name() +"!\n"+  
            target->query_name() +" is healed.\n");  
        tell_object(target, caster->query_name() +" injects you with their hypogun.\n"+  
             "You are healed!\n");  
      }  
      else  {  
        write("You heal your wounds.\n");
        say(caster->query_name() +"'s wounds are healed.\n");
            }

    break;
  }  
  destruct(this_object());
  return 1;
}

