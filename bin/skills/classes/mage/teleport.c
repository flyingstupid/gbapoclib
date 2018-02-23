/* teleport, teleport other */


status teleport(string str, mixed alt_type, string class) {
  int level, i;
  string file, *destinations, dom1, dom2, tmp, who;
  string spell_name;
  int spell_level;
  status party;
  object tel;

  if(!alt_type) alt_type = "alteration";
  if(!class) class = "mage";
  level = (objectp(alt_type))
        ? (int)alt_type->query_cast_level()
        : (int)call_other(this_player(),"query_"+ alt_type);
  file = file_name(this_object());
  sscanf(file,"%s#%d",i);

  if(!(tel = present("teleport", this_player()))) {
    tel = clone_object("obj/skills/teleport");
    move_object(tel, this_player());
    notify_fail("You should memorise a 'destination' first.\n");
    return 0;    
  }

  if(!str) {
    notify_fail("teleport <location>, teleport other <who> <location>, "+
                "teleport party <location>\n");
    return 0;
  }
  if(sscanf(str,"other %s %s", who, str)) {
    spell_name  = "Teleport Other";
    spell_level = 12;
  }
  else if(sscanf(str,"party %s", str)) {
    spell_name  = "Teleport Party";

    spell_level = 19;
    party = 1;
  }
  else {
    spell_name  = "Teleport";
    spell_level = 8;
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
    write("You cannot cross domains with a teleport spell.\n");
    return 1;
  }

  if(environment(this_player())->query_no_teleport()
  || (who && find_player(who) && present("magic_anchor", find_player(who)))
  || environment(this_player())->query_no_summon()) {
    write("Something in the area prevents you from teleporting.\n");
    return 1;
  }
  this_player()->load_spell(({
  "target",            who,
  "name",              spell_name,
  "sphere",            alt_type, 
  "cost",              spell_level,

  "level",             spell_level,
  "class", class,
  "spell object",      file,
  "cast time",         1,
  "argument",          destinations[i+1],
  "component",         "gem 1+gem 2",
  "passive",
   ((party) ? "area" : "dummy"),
  }));
  return 1;
}


status cast_spell(object caster,object target,object prev,int level) {
  string party_name, *party_members;
  object party;
  string file;

  file = (string)caster->query_spell_argument();

  if(prev) { /* area effect (party teleport) */
    if((string)caster->query_party() != (string)target->query_party()) {

      destruct(this_object()); /* not party teleport */
      return 1;
    }
  }
    
  if(this_player()->query_security_level()) {
  }
  
  if(living(target)) {
    if(target->query_npc()) {
      if(target->query_made_my_save()) {
        write(target->query_name() +" gets upset with you.\n");
        target->add_secondary_attacker(caster);
        target->set_primary_attack(caster);
        destruct(this_object());
        return 1;
      }
    }

    /* catch is so this won't stop heart beat on failed move */
    if(catch(call_other("/"+ file, "???"))) {
      write("A disturbance in the astral-weave prevents you from teleporting.\n");
      destruct(this_object());
      return 1;
    }

    if(call_other("/"+ file, "query_no_teleport")) {
      write("Some disturbance at your destination prevents you from leaving.\n");
      destruct(this_object());
      return 1;
    }

    if(catch(target->move_player("X#"+ file))) {
      write("Your destination currently does not exist!\n");
      destruct(this_object());
      return 1;
    }
  }
  else if(target->get() && !target->drop()) {
    if(catch(move_object(target,(string)caster->query_spell_argument()))) {
      write("Your destination currently does not exist!\n");
    }
    else {
      write("The "+ target->query_name() +" disappears in a puff of smoke.\n");
      say(caster->query_name() +" makes the "+ target->query_name() 
         +" disappear in a puff of smoke.\n");
      tell_room(find_object((string)caster->query_spell_argument()),
        "A "+ target->query_name() +" appears in a puff of smoke.\n");
    }
  }
  else {

    write("Something prevents the "+ target->query_name() +" from leaving.\n");
  }
  destruct(this_object());
  return 1;
}


