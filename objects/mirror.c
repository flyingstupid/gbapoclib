/*******************************************************
* A mirror, showing you what others would see as a
* result of your action.
* 
* Created by Hippo on 8-18-95
*******************************************************/

inherit "inherit/treasure";

int start;
void reset(status arg) {
  if (arg) return;
  set_name("mirror");
	  set_short("A mirror");
  set_long("The mirror shows many reflections.\n"+
  "A small sign at the bottom of the mirror says:\n"+
  "  ------------------------------\n"+
  "  -* Type 'mirror' to use me, *-\n"+
  "  -* or 'mirror' to loose me. *-\n"+
  "  ------------------------------\n"+
  "");
  set_smell("It smells like a mirror.\n");
  set_weight(4);
  start=0;
}

void init() {
  add_action("st","mirror");
}

int st() {
 if(!start) {
  move_object(this_object(),environment(this_player()));
  start=1;
  write("Your mirror starts reflecting.\n");
  say(capitalize(this_player()->query_name())+" created a mirror.\n");
  enable_commands();
 }
 else {
  say("A mirror has been destructed by "+capitalize(this_player()->query_name())+".\n");
 destruct(this_object());
 }
 return 1;
}

void catch_tell(string str){
  if(!start) return;
  if(environment()==this_player())  {
    start=0; return; 
  }
  tell_object(this_player(),"<Mirror>: "+str);
}
