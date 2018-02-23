/** improved phantasm **/

status improved(string str, mixed alt_type, string class) {
  string who;
  object ob;
  int level, sp_points;

  if(!str || sscanf(str,"phantasm %s", str) != 1) {
    write("improved phantasm <string>\n");
    return 1;
  }

  if(!alt_type) alt_type = "illusion";
  if(!class) class = "mage";
  level = (objectp(alt_type)) 
        ? (int)alt_type->query_cast_level()
        : (int)call_other(this_player(), "query_"+ alt_type);

  sp_points = (objectp(alt_type))
            ? (int)alt_type->query_charges()
            : (int)call_other(this_player(), "query_"+ alt_type +"_points");

  if(level < 10) {
    write("You are not knowledgable enough.\n");
    return 1;
  }
  if(sp_points < 3) {
    write("You feel too weak.\n");
    return 1;
  }
  if(objectp(alt_type)) 
    alt_type->adj_charges(-3);
  else
    call_other(this_player(), "adj_"+ alt_type +"_points", -3);

  say(str +"\n");
  write("You improved phantasm: "+ str +"\n");
  log_file("Illusion", (string)this_player()->query_name(1) +
                       " improved phantasmed "+ str +"\n");
  if(objectp(alt_type)) alt_type->end_spell();
  return 1;
}

