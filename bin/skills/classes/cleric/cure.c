/* cure */  

status cure(string spell_type, mixed alt_type, string class) {
  string file, spell_name;
  string targ;
  int i, spell_level, heal;

  if(!spell_type) {
    notify_fail("cure wounds, cure light wounds, cure minor wounds,\n"+
      "cure medium wounds, cure serious wounds, cure critical wounds,\n"+
      "cure major wounds, cure heavy wounds, cure blindness,\n"+
      "cure deafness, cure disease.\n");
    return 0;
  }
  sscanf(spell_type,"%s wounds %s", spell_type, targ);
  sscanf(spell_type,"%s wounds", spell_type);
  sscanf(spell_type,"%s %s", spell_type, targ);

  switch(spell_type) {
    case "wounds":
      spell_name = "Cure Wounds";
      heal = 1 * (random(4)+1);
      spell_level = 1;
    break;

    case "light":
      spell_name = "Cure Light Wounds";
      heal = 5 * (random(4)+1);
      spell_level = 4;
    break;

    case "minor":
      spell_name = "Cure Minor Wounds";
      heal = 10 * (random(4)+1);
      spell_level = 7;
    break;

    case "medium":
      spell_name = "Cure Medium Wounds";
      heal = 15 * (random(4)+1);
      spell_level = 10;
    break;

    case "serious":
      spell_name = "Cure Serious Wounds";
      heal = 20 * (random(4)+1);
      spell_level = 13;
    break;

    case "critical":
      spell_name = "Cure Critical Wounds";
      heal = 25 * (random(4)+1);
      spell_level = 16;
    break;

    case "major":
      spell_name = "Cure Major Wounds";
      heal = 30 * (random(4)+1);
      spell_level = 19;
    break;

    case "heavy":
      spell_name = "Cure Heavy Wounds";
      heal = 35 * (random(4)+1);
      spell_level = 23;
    break;

    case "deafness":
      spell_name = "Cure Deafness";
      spell_level = 3;
    break;

    case "blindness":
      spell_name = "Cure Blindness";
      spell_level = 5;
    break;

    case "disease":
      spell_name = "Cure Disease";
      spell_level = 7;
    break;

    default:
      notify_fail("cure wounds, cure light wounds, cure minor wounds,\n"+
        "cure medium wounds, cure serious wounds, cure critical wounds,\n"+
        "cure major wounds, cure heavy wounds, cure blindness,\n"+
        "cure deafness, cure disease.\n");
      return 0;
    break;
  }
  if(!alt_type) alt_type = "healing_sphere";
  if(!class) class = "cleric";
  file = file_name(this_object());
  sscanf(file,"%s#%d",file,i);
  
  this_player()->load_spell(({
  "target",            targ,
  "name",              spell_name,
  "sphere",            alt_type, 
  "cost",              spell_level,
  "level",             spell_level,
  "cast time",         2,
  "spell object",      file,
  "class",             class,
  "casting msg",       "You feel powerful healing energies swirling "+
                       "around you.\n",
  "damage",            heal,
  "passive",
  }));
  return 1;
}


/*********************************************************************/
/* when cloned to player */


status cast_spell(object caster,object target,object prev,int heal) {
  object ob;
  switch((string)caster->query_spell_name()) {
    case "Cure Deafness":
      if(ob = present("Deafness", target)) {
        tell_object(target,"You can hear!\n");
        if(target != caster) {
          write("You cure "+ target->query_name() +" of Deafness.\n");
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

    case "Cure Blindness":
      if(ob = present("Blindness", target)) {
        tell_object(target,"You can see!\n");
        if(target != caster) {
          write("You cure "+ target->query_name() +" of Blindness.\n");
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

    case "Cure Disease":
      if(ob = present("Disease", target)) {
        tell_object(target,"You feel better!\n");
        if(target != caster) {
          write("You cure the diseases of "+ target->query_name() +".\n");
        }
        say(target->query_name() +" starts rejoicing.\n", target);
        destruct(ob);
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
      target->adj_hp(heal);  
      if(target != caster) {
        write("You lay your hands upon "+ target->query_name() +".\n");
        say(caster->query_name() +" lays "+ caster->query_possessive() 
           +" hands upon "+ target->query_name() +".\n"+  
            target->query_name() +" is healed.\n");  
        tell_object(target, caster->query_name() +" lays "+  
             caster->query_possessive() +" hands upon you.\n"+  
             "You are healed!\n");  
      }  
      else {  
        write("You heal your wounds.\n");
        say(caster->query_name() +"'s wounds are healed.\n");
      }
    break;
  }  
  destruct(this_object());
  return 1;
}

