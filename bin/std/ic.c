#include <mudlib.h>

#define TP this_player()

status ic() {
  string tmp1, tmp2, enter_room;

  if(query_verb() != "-ic") return 0;

  if(environment(TP)->query_ooc_room()) {
    write("Warning: All behaviour @IC should be in character.\n");
    write("You put on your VR goggles and go into character.\n");
    say(TP->query_name()+" puts on "+TP->query_possessive()+" VR goggles and "+
    "goes into character.\n");

    enter_room = TP->query_ooc_enter_room();
    write("Enter Rooom :- "+enter_room+"\n");
    if(!enter_room) {
      TP->set_ooc_enter_room(IC_ENTER);
      enter_room = IC_ENTER;
    }
    if(catch(call_other(enter_room, "query_ooc_room"))) {
      write("Entry room failure.\n");
      TP->set_ooc_enter_room("room/void");
      enter_room = "room/void";
      TP->set_ooc_enter_room(enter_room);
      TP->move_player("X#"+enter_room);
      return 1;
    }
    if(sscanf(enter_room, "%sooc%s", tmp1, tmp2)) TP->set_ooc_enter_room(IC_ENTER);
    TP->move_player("into the virtual world of "+MUD_NAME+"#"+
    enter_room);
    return 1;
  }
  write("You are already in character!\n");
  return 1;
}
