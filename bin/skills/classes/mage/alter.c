/* alter reality */

status alter(string str, mixed alt_type, string class) {
  string arg;
  mixed *loaded_spell;
  int level, i;

  if(!str || sscanf(str,"reality %s", str) != 1) {
    write("alter reality <spell>?\n");
    return 1;
  }
  if(!alt_type) alt_type = "illusion";
  if(!class) class = "mage";
  level = (objectp(alt_type))
        ? (int)alt_type->query_cast_level()
        : (int)call_other(this_player(),"query_"+ alt_type);

  if(level < 18) {
    write("You are not knowledgable enough to cast alter reality.\n");
    return 1;
  }
  sscanf(str,"%s %s", str, arg);
  loaded_spell = (mixed *)clone_object("obj/shadows/get_spell")
                 ->get_spell(str,arg,alt_type);
  if(!sizeof(loaded_spell)) {
    write("Alter Reality cannot do such a spell.\n");
    return 1;
  }

  /* check spell level */

  if((i = member_array("level", loaded_spell)) != -1 
  || (i = member_array("spell level", loaded_spell)) != -1) {
    level = loaded_spell[i+1];
  } 


  /* change the name */

  if((i = member_array("name", loaded_spell)) != -1 
  || (i = member_array("spellname", loaded_spell)) != -1) {
    if(level > 15) {
      write(capitalize(loaded_spell[i+1]) 
            +" is too powerful for alter reality.\n");
      return 1;
    }
    loaded_spell[i+1] = "Alter Reality "+ loaded_spell[i+1];
  } 
  else {
    if(level > 15) {
      write(capitalize(str) +" is too powerful for alter reality.\n");
      return 1;
    }
    loaded_spell += ({ "name", "Alter Reality "+ str, });
  }

  
  /* change cost */

  if((i = member_array("cost", loaded_spell)) == -1) {
    loaded_spell += ({ "cost", 5, });
  }
  else {
    loaded_spell[i+1] += 5;
  }
  this_player()->load_spell(loaded_spell);
  return 1;
}

