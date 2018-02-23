/* dispel magic, illusion, conjuration */

#define SPELLNAME (string)caster->query_spell_name()

status dispel(string spell_type, mixed alt_type, string class) {
  int i;
  string file;
  string targ;
  string spell_name;
  int spell_level;

  if(!spell_type) {
    notify_fail("dispel illusion, dispel magic, dispel conjuration?\n");
    return 0;
  }

  if(!alt_type) alt_type = "abjuration";
  if(!class) class = "mage";

  file = file_name(this_object());
  sscanf(file, "%s#%d", file, i);

  sscanf(spell_type,"%s %s", spell_type, targ);
  spell_type = lower_case(spell_type);
  switch(spell_type) {
    case "illusion":
      spell_name = "Dispel Illusion";
      spell_level = 5;
    break;

    case "magic":
      spell_name = "Dispel Magic";
      spell_level = 10;
    break;

    case "conjuration":
      spell_name = "Dispel Conjuration";
      spell_level = 7;
    break;

    default:
      notify_fail("dispel illusion, dispel magic, dispel conjuration?\n");
      return 0;
    break;
  }

  this_player()->load_spell(({
  "target",            targ,
  "name",              spell_name,
  "sphere",            alt_type, 
  "cost",              spell_level,
  "level",             spell_level,
  "class",             class,
  "cast time",         1,
  "spell object",      file,
  "passive",
  }));
  return 1;
}


/*******************************************************************/
/* called when this is cloned to target */


status cast_spell(object caster,object target,object prev,int dmg) {
  object ob, *inv;
  status flag;
  int i;

  if(SPELLNAME == "Dispel Illusion") {
    if((ob = (object)target->query_illusion_object())) {
      flag = 1;
      if(function_exists("dispel_magic", ob)) ob->dispel_magic();
      else ob->time_out();
    }
    inv = all_inventory(target);
    for(i = sizeof(inv); i--; ) {
      if((ob = (object)inv[i]->query_illusion_object())) {
        flag = 1;
        if(function_exists("dispel_magic", ob)) ob->dispel_magic();
        else ob->time_out();
      }
    }
    if(!flag) {
      write("There is no illusion on "+ target->short() +".\n");
    }
    else {
      tell_room(environment(caster),"You feel some magic drain away...\n");
    }
  }
  else if(SPELLNAME == "Dispel Conjuration") {
    if(!living(target)) {
      if(target == environment(caster)) {
        write("Don't be silly.\n");
      }
      else
        write(target->query_name() +" is not a conjured monster.\n");
    }
    else {
      if(function_exists("time_out", target)) { /* assume uses inherit/timer*/
        if(function_exists("dispel_magic", target)) target->dispel_magic();
        else target->time_out();
        tell_room(environment(caster),"You feel some magic drain away...\n");
      }
      else {
        write(target->query_name() +" is not conjured.\n");
      }
    }
  }
  else if(SPELLNAME == "Dispel Magic") {
    inv = all_inventory(target);
    for(i = sizeof(inv); i--; ) {
      if(function_exists("dispel_magic", inv[i])) inv[i]->dispel_magic();
      else inv[i]->time_out();
    }
    if(function_exists("dispel_magic", target)) target->dispel_magic();
    else target->time_out();
    tell_room(environment(caster),"You feel some magic drain away...\n");
  }     
  if(this_object()) {
    destruct(this_object());
  }
  return 1;
}  

status id(string str) { return str == "spell"; }

