#include <mudlib.h>
#include <ansi.h>

#define TP this_player()

status whisper(string str){  
    object ob;  
    string who, msg;  

    if(TP->query_ghost()) {  
      write("Your ethereal voice fails you..\n");  
      return 1;  
    }  
    if(!str || !sscanf(str, "%s %s", who, msg)) {  
      write("Usage: whisper <who> <msg>\n");  
      return 1;  
    }  
    ob = find_living(lower_case(who));  
    if(!ob || !present(ob, environment(TP))) {  
      write("There is no "+who+" here.\n");  
      return 1;  
    }  
    if(!ob->ansi_on())
      msg = TP->filter_ansi(msg);
    else
      msg += OFF; /* turn ansi off */
    tell_object(ob, TP->query_name() +" whispers to you: "+ msg +" \n");  
    write("You whisper: "+msg+"\n");  
    say(TP->query_name() +" whispers something to "+ capitalize(who) +".\n", ob); 
    return 1;  
}  

