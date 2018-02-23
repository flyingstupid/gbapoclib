#define TP this_player()

status emote(string str) { 
  string verb; 

  verb = query_verb(); 
  if(!str) str = "";
  if(verb[0] == ":"[0]) str = extract(verb, 1) + " " + str; 
  if(str == "" || str == " ") { 
    write("Usage: emote <msg>\n"); 
    return 1; 
  } 
  str = TP->filter_ansi(str); /* always filtered */
  write("You emote: " + TP->query_name() +" "+ str +"\n"); 
  if(TP->query_security_level()) 
      say(TP->query_name() +" "+ str +"\n");
  else 
      say("::"+TP->query_name() +" "+ str +"\n");
  return 1; 
} 
