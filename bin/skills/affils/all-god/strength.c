status strength(string targ, mixed alt_type) {
  int level, i;
  string file, *destinations, dom1, dom2, tmp, who;
  string spell_name;
  int spell_level;
  status party;
  object tel;

  if(!this_player()->query_class("cleric")) {
    notify_fail("Only a priest may pray for spells.\n");
    return 0;
  }

  if(!targ) {
    notify_fail("strength of one?\n");
    return 0;
  }

  targ = 0; /* me! */

  if(!alt_type) alt_type = "combat_sphere";
  level = (objectp(alt_type))
        ? (int)alt_type->query_cast_level()
        : (int)call_other(this_player(),"query_"+ alt_type);
  file = file_name(this_object());
  sscanf(file,"%s#%d",i);

  this_player()->load_spell(({
    "target",            targ,
    "name",              "Strength of One",
    "damage",		level,
    "sphere",            alt_type,
    "class",  "cleric",
    "cost",              spell_level,
    "level",             spell_level,
    "spell object",      file,
    "cast time",         1,
    "passive",	         1,
  }));
  return 1;
}


status cast_spell(object caster,object target,object prev,int dam) {
  object banner, ob;
  object *obj;
  object *people;
  string *members;
  int max_combat;
  int i;

  if(!banner = present("party_object", caster)) {
    write("You are not in a party!\n");
    destruct(this_object());
    return 1;
  }

  members = (string *)banner->query_all_members();
  people  = ({ });

  for(i=0; i<sizeof(members); i++) {
    if((ob=present(members[i], environment(caster))) && find_player(members[i]))
      people += ({ ob, });
  }  

  if(sizeof(people) == 1) {
    write("A party of one isn't big enough for the prayer!\n");
    destruct(this_object());
    return 1;
  }


  people = sort_array(people, "by_combat", this_object());  
  max_combat = (int)people[0]->query_combat() + random(dam); 
  /* dam at this stage is equal to level! */

  for(i=0; i<sizeof(people); i++) {
    if(ob = people[i]->query_combat_object()) {
      tell_object(caster, people[i]->query_name()+" is further empowered!\n");
      ob -> adj_time(60 * dam);
    }
    else {
      ob = clone_object("obj/shadows/combat");
      ob -> shadow_combat(people[i], max_combat);
      ob -> adj_time(dam * 60);
      tell_object(people[i],"You feel the Strength of One empower you\n");
      say(people[i]->query_name() +" looks strong!!\n",people[i]);
    }
  }
  destruct(this_object());
  return 1;
}


status by_combat(object a, object b) {
  if((int)a->query_combat() == (int)b->query_combat()
    && (int)a->query_combat() < (int)b->query_combat()) return 1;
  return 0;
}

status id(string str) { return (str == "spell"); }
