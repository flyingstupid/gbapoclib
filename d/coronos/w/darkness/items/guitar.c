#include <mudlib.h>
inherit WEAPON;
 
void reset(status arg) {
  ::reset(arg);
 
  if(arg) return;
  set_name("club");
  set_short("a guitar");
  set_alias("guitar");
  set_long(
    "A fairly old guitar.  It's strings look like they're going to\n"+ 
    "snap soon.  It is a little scratched, but still playable.\n");
  set_info(
    "The guitar may be wielded as if it were a club.\n");
  set_weight(5);
  set_value(110);
  set_length(36);
  set_type("crush");
  set_wc(1); /* I would like to make it so that the guitar breaks after a couple
                hits, but haven't gotten around to it, so WC is set to 1 instead. */
  set_sell_destruct(1);
}

void init() {
  add_action("player", "play");
  ::init(); 
}

status player(string str) {
  string tmp1, tmp2;

  if(!str) {
  write("Do you wish to play the guitar?\n");
  return 1;
  }

  else if(sscanf(str, "%sguitar%s", tmp1, tmp2)) { 
  write(
    "You play your guitar.  If that was supposed to be a song,\n"+
    "you either need more practice or a better guitar!\n");
  say(this_player()->query_name()+
    " plays a very bad tune on "+this_player()->query_possessive()+
    " guitar.\n", this_player());
  return 1;
  }
return 0;
}
