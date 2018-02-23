/* wish */

status wish(string str, mixed alt_type, string class) {
  string arg;
  mixed *loaded_spell;
  int level, i;

  if(!str) {
    write("wish <spell>?\n");
    return 1;
  }
  if(!alt_type) alt_type = "conjuration";
  if(!class) class = "mage";
  level = (objectp(alt_type))
        ? (int)alt_type->query_cast_level()
        : (int)call_other(this_player(),"query_"+ alt_type);

  if(level < 25) {
    write("You are not knowledgable enough to cast limited wish.\n");
    return 1;
  }
  sscanf(str,"%s %s", str, arg);
  loaded_spell = (mixed *)clone_object("obj/shadows/get_spell")
                 ->get_spell(str,arg,alt_type);
  if(!sizeof(loaded_spell)) {
    write("Wish cannot do such a spell.\n");
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
    if(level > 20) {
      write(capitalize(loaded_spell[i+1]) 
            +" is too powerful for a wish.\n");
      return 1;
    }
    loaded_spell[i+1] = "Wish "+ loaded_spell[i+1];
  } 
  else {
    if(level > 20) {
      write(capitalize(str) +" is too powerful for wish.\n");
      return 1;
    }
    loaded_spell += ({ "name", "Wish "+ str, });
  }

  
  /* change cost */

  if((i = member_array("cost", loaded_spell)) == -1) {
    loaded_spell += ({ "cost", 10, });
  }
  else {
    loaded_spell[i+1] += 10;
  }
  loaded_spell += ({ "class", class, });
  this_player()->load_spell(loaded_spell);
  return 1;
}

