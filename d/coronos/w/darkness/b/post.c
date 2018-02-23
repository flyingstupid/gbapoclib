/* Post Office -- Bureaucracy */
/* Darkness + the base Post Office code from Tempus */

#include <mudlib.h>
inherit ROOM;
 
 
void reset(status arg) {

  reset_doors(arg);
  load_door(({
    "destination",      "d/coronos/w/darkness/b/hall/hall6",
    "direction",        "south door",
    "long",             "The heavy door is made of sturdy oak.  Iron bracers also\n"+
                        "reinforce the door\n",
    "door id",          "south door",
    "key id",           "city key",
  }));

    if(arg) return;

    set_weather(2, 1, 0);
    set_short("the Ille Coronos post office");
    set_long("\t==Ille Coronos Post Office==\n"+
      "This large room is the central post office of Ille Coronos.  The\n"+
      "walls are covered with pigeon holes, each assigned to a different\n"+
      "person.  There is a sign on the counter at the far end of the room.\n"+
      "A velvet rug covers the floor from wall to wall and matching drapes\n"+
      "hang over the large, rectangular windows.\n");
 
    set_items(({
      "holes#hole#pigeon",
        "These small holes easily hold smalle letters for their assigned\n"+
        "owner.  Each person has a hole assigned to them where they can\n"+
        "easily recieve any mail.\n",
      "sign",
        "Post Office Commands: \n"+
        "read  Read your mail from your pigeon hole\n"+
        "mail  <name>Mail to another player\n"+
        "from  List all the mail you have stored away\n"
      "counter",
        "The counter has a wooden base and a marble counter top.\n",
      "customer area#area",
        "You're in the customer area.  Passage behind the counter is not allowed.\n",
      "vault",
        "The thick metal vault is very safe and secure.\n",
      "wall#walls"
        "The walls are made from think granite blocks.\n",
      "stores",
        "The money kept in the vault is not visible from here.\n",
      "rug",
        "The rug is thin but very soft.  It matches the drapes in the room.\n",
      "curtain#curtains#drapes#drape",
        "The drapes are made of red velvet.  They match the rug in the room.\n",
      "window",
        "The medium sized windows are barred on the inside.\n",
      "frame#wood-frames#wood-frame",
        "The wood frame is simply made from sturdy oak.\n",
      "bar#bars",
        "The storing metal bars are there for protection.\n",
      }));
    set_no_fight(1);
    set_no_summon(1);
}
 
 
void init() {
    ::init();
    if(this_player() && living(this_player()) && !present("mailer", this_player())) {
        move_object(clone_object(MAILER), this_player());
    }
    add_action("say", "say");
    add_action("say", "'", 1);
    add_action("read1", "read");
}
 
 
status ready_to_move(string str) {
    if(present("mailer", this_player())) {
        destruct(present("mailer", this_player()));
    }
    return ::ready_to_move(str);
}
 
status door_to_move(string str) {
    if(present("mailer", this_player())) {
        destruct(present("mailer", this_player()));
    }
    return ::door_to_move(str);
}
 
status say(string arg) {
    write("Post master says: Shhh! People are trying to mail here.\n");
    return 1;
}
 
status query_no_teleport() {  return 1; }

status read1(string str) {
   string tmp1, tmp2;

  if(sscanf(str, "%ssign%s", tmp1, tmp2)) {
    write(
      "|Post Office Commands:                         | \n"+
      "|read Read your mail from your pigeon hole     | \n"+
      "|mail <name> Mail to another player            | \n"+
      "|from  List all the mail you have stored away  | \n");
    return 1;
  }

  else { return 0;
  } 
} 
