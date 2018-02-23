/** phantasm **/
 
status phantasm(string str, mixed alt_type, string class) {
  string who;
  object ob;
  int level, sp_points;
 
  if(!str || sscanf(str,"%s %s", who, str) != 2) {
    write("phantasm <who> <emote>\n");
    return 1;
  }
  if(!(ob = present(who, environment(this_player())))) {
    write("There is no "+ who +" here.\n");
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
 
  if(level < 5) {
    write("You are not knowledgable enough.\n");
    return 1;
  }
  if(sp_points < 2) {
    write("You feel too weak.\n");
    return 1;
  }
 
  if(objectp(alt_type)) 
    alt_type->adj_charges(-2);
  else
    call_other(this_player(), "adj_"+ alt_type +"_points", -2);
 
  say(capitalize(who) +" "+ str +"\n", ob);
  write("From "+ capitalize(who) +" you see: "+ str +"\n");
  tell_object(ob,capitalize(who)+" "+ str + "\n"+
	         "But it wasn't you who did it!!\n");
  log_file("Illusion", (string)this_player()->query_name(1) +
                       " phantasmed"+ (string)ob->query_name(1) +
                       " "+ str +"\n");
  if(objectp(alt_type)) alt_type->end_spell();
  return 1;
}
 
