/* dimensional fold */

status dimensional(string str, mixed alt_type, string class) {
  int level, i;
  string file, *destinations, dom1, dom2, tmp, who;
  string spell_name;
  int spell_level;
  status party;
  object tel;

  if(!alt_type) alt_type = "stellar_sphere";
  if(!class) class = "cleric";
  level = (objectp(alt_type))
        ? (int)alt_type->query_cast_level()
        : (int)call_other(this_player(),"query_"+ alt_type);
  file = file_name(this_object());
  sscanf(file,"%s#%d",i);

  if(!(tel = present("teleport", this_player()))) {
    tel = clone_object("obj/skills/teleport");
    move_object(tel, this_player());
  }

  if(!str || sscanf(str,"fold %s",str) != 1) {
    notify_fail("dimensional fold <location>,\n"+
                "dimensional fold other <who> <location>, "+
                "dimensional fold party <location>\n");
    return 0;
  }
  if(sscanf(str,"other %s %s", who, str)) {
    spell_name  = "Dimensional Fold Other";
    spell_level = 16;
  }
  else if(sscanf(str,"party %s", str)) {
    spell_name  = "Dimensional Fold Party";
    spell_level = 23;
    party = 1;
  }
  else {
    spell_name  = "Dimensional Fold";
    spell_level = 12;
  }
  if(level < spell_level) {
    write("You are not knowledgable enough to cast "+ spell_name +".\n");
    return 1;
  }    

  destinations = (string *)tel->query_destinations();
  if((i = member_array(str, destinations)) == -1) {
    write("You have not memorised \""+ str +"\" as a destination.\n"+
          "type 'destination <location>' to memorise this area as a "+
          "destination.\n");
    return 1;
  }
  sscanf((string)this_player()->query_current_room(),"d/%s/%s",dom1,tmp);
  sscanf(destinations[i+1],"d/%s/%s",dom2,tmp);
  if(dom1 != dom2) {
    write("You cannot cross domains with a dimensional fold pray.\n");
    return 1;
  }
  if(environment(this_player())->query_no_teleport()
  || environment(this_player())->query_no_summon()) {
    write("Something in the area prevents you from dimensional folding.\n");
    return 1;
  }
  this_player()->load_spell(({
  "target",            who,
  "name",              spell_name,
  "sphere",            alt_type, 
  "cost",              spell_level,
  "level",             spell_level,
  "spell object",      file,
  "cast time",         1,
  "argument",          destinations[i+1],
  "component",         "gem",
  "class",             class,
  "passive",
   ((party) ? "area" : "dummy"),
  }));
  return 1;
}


status cast_spell(object caster,object target,object prev,int level) {

  if(prev) { /* area effect (party teleport) */
    if((string)caster->query_party() != (string)target->query_party()) {
      destruct(this_object()); /* not party teleport */
      return 1;
    }
  }
    
  if(living(target)) {
    if(target->query_npc()) {
      if((int)caster->query_spell_dmg() != level) {
        write(target->query_name() +" gets upset with you.\n");
        target->add_secondary_attacker(caster);
        target->set_primary_attack(caster);
        destruct(this_object());
        return 1;
      }
    }
    /* catch is so this won't stop heart beat on failed move */
    if(catch(target->move_player("X#"+(string)target->query_spell_argument()))){
      write("Your destination currently does not exist!\n");
    }
  }
  else if(target->get() && !target->drop()) {
    if(catch(move_object(target,(string)target->query_spell_argument()))) {
      write("Your destination currently does not exist!\n");
    }
    else {
      write("The "+ target->query_name() +" disappears in a puff of smoke.\n");
      say(caster->query_name() +" makes the "+ target->query_name() 
         +" disappear in a puff of smoke.\n");
      tell_room(find_object((string)target->query_spell_argument()),
        "A "+ target->query_name() +" appears in a puff of smoke.\n");
    }
  }
  else {
    write("Something prevents the "+ target->query_name() +" from leaving.\n");
  }
  destruct(this_object());
  return 1;
}

