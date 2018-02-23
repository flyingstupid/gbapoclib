/** shadow door **/

#define NAME "@@query_name:$this_player()$@@"


status shadow(mixed str, mixed alt_type, string class) {
  int jumps, i;
  string file;

  if(!str || !(str == "door" || str == "monster")) {
    write("Usage: shadow door\n"+
          "       shadow monster\n");
    return 1;
  }
  if(!alt_type) alt_type = "illusion";
  if(!class) class = "mage";
  jumps = (objectp(alt_type))
        ? (int)alt_type->query_cast_level() 
        : (int)call_other(this_player(),"query_"+alt_type);
  if(str == "door") {
    if(jumps > 30) jumps = 30;

    file = file_name(this_object());
    sscanf(file, "%s#%d", file, i);

    this_player()->load_spell(({
      "target",            this_player(),
      "name",              "Shadow Door",
      "sphere",            alt_type, 
      "cost",              11,
      "damage",            jumps,
      "level",             11, /* 10 + 5 no component - 4 cast time */
  "class", class,
      "cast time",         2, 
      "spell object",      file,
      "casting msg",      "A door starts to appear in front of you.\n",
      "casting msg room", "A doors starts to form in front of "+NAME+".\n",
      "passive",
    }));
  }
  else if(str == "monster") {
    file = "obj/skills/sh_monst";
    this_player()->load_spell(({
      "target",            environment(this_player()),
      "name",              "Shadow Monster",
      "sphere",            alt_type, 
      "cost",              15,
      "damage",            jumps,
      "level",             15, /* 10 + 5 no component - 4 cast time */
      "cast time",         2, 
      "spell object",      file,
      "casting msg",      "An awesome monster starts to form in front of "+
                          "you.\n",
      "casting msg room", "An awesome monster starts to form in front of "+
                          NAME +".\n",
      "passive",
    }));
  }
  return 1;
}


status cast_spell(object caster,object target,object prev,int jumps) {
  int i;
  string file, *exits;

  file = (string)caster->query_current_room();
  while(++i < jumps) {
    exits = (string *)call_other(file, "query_all_exits");
    if(!exits) exits = (string *)call_other(file, "query_dest_dir");
    if(!exits) break;
    file = exits[(random(sizeof(exits))/2)*2];
  }
  tell_object(caster,"You step through a shadow door.\n");
  caster->move_player("through a dark door#"+ file);
  destruct(this_object());
  return 1;
}

status id(string str) { return (str == "spell"); }

