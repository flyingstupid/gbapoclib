/* phantasmal force */

status phantasmal(string str, mixed alt_type, string class) {
  string arg;
  mixed *loaded_spell;
  int level, i;

  if(!str || sscanf(str,"force %s", str) != 1) {
    write("phantasmal force <spell>?\n");
    return 1;
  }
  if(!alt_type) alt_type = "illusion";
  if(!class) class = "mage";
  level = (objectp(alt_type))
        ? (int)alt_type->query_cast_level()
        : (int)call_other(this_player(),"query_"+ alt_type);

  if(level < 12) {
    write("You are not knowledgable enough to cast phantasmal force.\n");
    return 1;
  }
  sscanf(str,"%s %s", str, arg);
  loaded_spell = (mixed *)clone_object("obj/shadows/get_spell")
                 ->get_spell(str,arg,0);
  if(!sizeof(loaded_spell)) {
    write("Phantasmal Force cannot do such a spell.\n");
    return 1;
  }
  if(member_array("evocation", loaded_spell) == -1) {
    write("You can only phantasmal force evocation spells.\n");
    return 1;
  }
  loaded_spell = (mixed *)clone_object("obj/shadows/get_spell")
                 ->get_spell(str,arg,alt_type);

  /* change the name */

  if((i = member_array("name", loaded_spell)) != -1 
  || (i = member_array("spellname", loaded_spell)) != -1) {
    loaded_spell[i+1] = "Phantasmal Force "+ loaded_spell[i+1];
  } 
  else {
    loaded_spell += ({ "name", "Phantasmal Force "+ str, });
  }

  /* change cost */

  if((i = member_array("cost", loaded_spell)) == -1) {
    loaded_spell += ({ "cost", 5, });
  }
  else {
    loaded_spell[i+1] += 5;
  }
  loaded_spell += ({ "class", class, });
  this_player()->load_spell(loaded_spell);
  return 1;
}

